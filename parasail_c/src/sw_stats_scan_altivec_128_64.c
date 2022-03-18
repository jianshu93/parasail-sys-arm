/**
 * @file
 *
 * @author jeffrey.daily@gmail.com
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 */
#include "config.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>



#include "parasail.h"
#include "parasail/memory.h"
#include "parasail/internal_altivec.h"



#ifdef PARASAIL_TABLE
static inline void arr_store_si128(
        int *array,
        vec128i vH,
        int32_t t,
        int32_t seglen,
        int32_t d,
        int32_t dlen)
{
    array[1LL*(0*seglen+t)*dlen + d] = (int64_t)_mm_extract_epi64(vH, 0);
    array[1LL*(1*seglen+t)*dlen + d] = (int64_t)_mm_extract_epi64(vH, 1);
}
#endif

#ifdef PARASAIL_ROWCOL
static inline void arr_store_col(
        int *col,
        vec128i vH,
        int32_t t,
        int32_t seglen)
{
    col[0*seglen+t] = (int64_t)_mm_extract_epi64(vH, 0);
    col[1*seglen+t] = (int64_t)_mm_extract_epi64(vH, 1);
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_sw_stats_table_scan_altivec_128_64
#define PNAME parasail_sw_stats_table_scan_profile_altivec_128_64
#else
#ifdef PARASAIL_ROWCOL
#define FNAME parasail_sw_stats_rowcol_scan_altivec_128_64
#define PNAME parasail_sw_stats_rowcol_scan_profile_altivec_128_64
#else
#define FNAME parasail_sw_stats_scan_altivec_128_64
#define PNAME parasail_sw_stats_scan_profile_altivec_128_64
#endif
#endif

parasail_result_t* FNAME(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap, const parasail_matrix_t *matrix)
{
    /* declare local variables */
    parasail_profile_t *profile = NULL;
    parasail_result_t *result = NULL;

    /* validate inputs */
    PARASAIL_CHECK_NULL(s2);
    PARASAIL_CHECK_GT0(s2Len);
    PARASAIL_CHECK_GE0(open);
    PARASAIL_CHECK_GE0(gap);
    PARASAIL_CHECK_NULL(matrix);
    if (matrix->type == PARASAIL_MATRIX_TYPE_PSSM) {
        PARASAIL_CHECK_NULL_PSSM_STATS(s1);
    }
    else {
        PARASAIL_CHECK_NULL(s1);
        PARASAIL_CHECK_GT0(s1Len);
    }

    /* initialize local variables */
    profile = parasail_profile_create_stats_altivec_128_64(s1, s1Len, matrix);
    if (!profile) return NULL;
    result = PNAME(profile, s2, s2Len, open, gap);

    parasail_profile_free(profile);

    return result;
}

parasail_result_t* PNAME(
        const parasail_profile_t * const restrict profile,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap)
{
    /* declare local variables */
    int32_t i = 0;
    int32_t j = 0;
    int32_t end_query = 0;
    int32_t end_ref = 0;
    int32_t s1Len = 0;
    const parasail_matrix_t *matrix = NULL;
    int32_t segWidth = 0;
    int32_t segLen = 0;
#ifdef PARASAIL_ROWCOL
    int32_t offset = 0;
    int32_t position = 0;
#endif
    vec128i* restrict pvP = NULL;
    vec128i* restrict pvPm = NULL;
    vec128i* restrict pvPs = NULL;
    vec128i* restrict pvE = NULL;
    vec128i* restrict pvEM = NULL;
    vec128i* restrict pvES = NULL;
    vec128i* restrict pvEL = NULL;
    vec128i* restrict pvH = NULL;
    vec128i* restrict pvHM = NULL;
    vec128i* restrict pvHS = NULL;
    vec128i* restrict pvHL = NULL;
    vec128i* restrict pvHMax = NULL;
    vec128i* restrict pvHMMax = NULL;
    vec128i* restrict pvHSMax = NULL;
    vec128i* restrict pvHLMax = NULL;
    vec128i* restrict pvGapper = NULL;
    vec128i* restrict pvGapperL = NULL;
    vec128i vGapO;
    vec128i vGapE;
    int64_t NEG_LIMIT = 0;
    int64_t POS_LIMIT = 0;
    vec128i vZero;
    vec128i vOne;
    int64_t score = 0;
    int64_t matches = 0;
    int64_t similar = 0;
    int64_t length = 0;
    vec128i vNegLimit;
    vec128i vPosLimit;
    vec128i vSaturationCheckMin;
    vec128i vSaturationCheckMax;
    vec128i vMaxH;
    vec128i vMaxM;
    vec128i vMaxS;
    vec128i vMaxL;
    vec128i vMaxHUnit;
    vec128i vNegInfFront;
    vec128i vSegLenXgap;
    vec128i vSegLen;
    parasail_result_t *result = NULL;

    /* validate inputs */
    PARASAIL_CHECK_NULL(profile);
    PARASAIL_CHECK_NULL(profile->profile64.score);
    PARASAIL_CHECK_NULL(profile->matrix);
    PARASAIL_CHECK_GT0(profile->s1Len);
    PARASAIL_CHECK_NULL(s2);
    PARASAIL_CHECK_GT0(s2Len);
    PARASAIL_CHECK_GE0(open);
    PARASAIL_CHECK_GE0(gap);

    /* initialize stack variables */
    i = 0;
    j = 0;
    end_query = 0;
    end_ref = 0;
    s1Len = profile->s1Len;
    matrix = profile->matrix;
    segWidth = 2; /* number of values in vector unit */
    segLen = (s1Len + segWidth - 1) / segWidth;
#ifdef PARASAIL_ROWCOL
    offset = (s1Len - 1) % segLen;
    position = (segWidth - 1) - (s1Len - 1) / segLen;
#endif
    pvP  = (vec128i*)profile->profile64.score;
    pvPm = (vec128i*)profile->profile64.matches;
    pvPs = (vec128i*)profile->profile64.similar;
    vGapO = _mm_set1_epi64(open);
    vGapE = _mm_set1_epi64(gap);
    NEG_LIMIT = (-open < matrix->min ? INT64_MIN + open : INT64_MIN - matrix->min) + 1;
    POS_LIMIT = INT64_MAX - matrix->max - 1;
    vZero = _mm_setzero_si128();
    vOne = _mm_set1_epi64(1);
    score = NEG_LIMIT;
    matches = 0;
    similar = 0;
    length = 0;
    vNegLimit = _mm_set1_epi64(NEG_LIMIT);
    vPosLimit = _mm_set1_epi64(POS_LIMIT);
    vSaturationCheckMin = vPosLimit;
    vSaturationCheckMax = vNegLimit;
    vMaxH = vNegLimit;
    vMaxM = vNegLimit;
    vMaxS = vNegLimit;
    vMaxL = vNegLimit;
    vMaxHUnit = vNegLimit;
    vSegLen = _mm_slli_si128(_mm_set1_epi64(segLen), 8);
    vNegInfFront = vZero;
    vNegInfFront = _mm_insert_epi64(vNegInfFront, NEG_LIMIT, 0);
    vSegLenXgap = _mm_add_epi64(vNegInfFront,
            _mm_slli_si128(_mm_set1_epi64(-segLen*gap), 8));

    /* initialize result */
#ifdef PARASAIL_TABLE
    result = parasail_result_new_table3(segLen*segWidth, s2Len);
#else
#ifdef PARASAIL_ROWCOL
    result = parasail_result_new_rowcol3(segLen*segWidth, s2Len);
#else
    result = parasail_result_new_stats();
#endif
#endif
    if (!result) return NULL;

    /* set known flags */
    result->flag |= PARASAIL_FLAG_SW | PARASAIL_FLAG_SCAN
        | PARASAIL_FLAG_STATS
        | PARASAIL_FLAG_BITS_64 | PARASAIL_FLAG_LANES_2;
#ifdef PARASAIL_TABLE
    result->flag |= PARASAIL_FLAG_TABLE;
#endif
#ifdef PARASAIL_ROWCOL
    result->flag |= PARASAIL_FLAG_ROWCOL;
#endif

    /* initialize heap variables */
    pvE  = parasail_memalign_vec128i(16, segLen);
    pvEM = parasail_memalign_vec128i(16, segLen);
    pvES = parasail_memalign_vec128i(16, segLen);
    pvEL = parasail_memalign_vec128i(16, segLen);
    pvH  = parasail_memalign_vec128i(16, segLen);
    pvHM = parasail_memalign_vec128i(16, segLen);
    pvHS = parasail_memalign_vec128i(16, segLen);
    pvHL = parasail_memalign_vec128i(16, segLen);
    pvHMax  = parasail_memalign_vec128i(16, segLen);
    pvHMMax = parasail_memalign_vec128i(16, segLen);
    pvHSMax = parasail_memalign_vec128i(16, segLen);
    pvHLMax = parasail_memalign_vec128i(16, segLen);
    pvGapper = parasail_memalign_vec128i(16, segLen);
    pvGapperL = parasail_memalign_vec128i(16, segLen);

    /* validate heap variables */
    if (!pvE) return NULL;
    if (!pvEM) return NULL;
    if (!pvES) return NULL;
    if (!pvEL) return NULL;
    if (!pvH) return NULL;
    if (!pvHM) return NULL;
    if (!pvHS) return NULL;
    if (!pvHL) return NULL;
    if (!pvHMax) return NULL;
    if (!pvHMMax) return NULL;
    if (!pvHSMax) return NULL;
    if (!pvHLMax) return NULL;
    if (!pvGapper) return NULL;
    if (!pvGapperL) return NULL;

    parasail_memset_vec128i(pvH, vZero, segLen);
    parasail_memset_vec128i(pvHM, vZero, segLen);
    parasail_memset_vec128i(pvHS, vZero, segLen);
    parasail_memset_vec128i(pvHL, vZero, segLen);
    parasail_memset_vec128i(pvE, vNegLimit, segLen);
    parasail_memset_vec128i(pvEM, vZero, segLen);
    parasail_memset_vec128i(pvES, vZero, segLen);
    parasail_memset_vec128i(pvEL, vZero, segLen);
    {
        vec128i vGapper = _mm_sub_epi64(vZero,vGapO);
        vec128i vGapperL = vOne;
        for (i=segLen-1; i>=0; --i) {
            _mm_store_si128(pvGapper+i, vGapper);
            _mm_store_si128(pvGapperL+i, vGapperL);
            vGapper = _mm_sub_epi64(vGapper, vGapE);
            vGapperL = _mm_add_epi64(vGapperL, vOne);
        }
    }

    /* outer loop over database sequence */
    for (j=0; j<s2Len; ++j) {
        vec128i vE;
        vec128i vE_ext;
        vec128i vE_opn;
        vec128i vEM;
        vec128i vES;
        vec128i vEL;
        vec128i vHt;
        vec128i vHtM;
        vec128i vHtS;
        vec128i vHtL;
        vec128i vF;
        vec128i vF_ext;
        vec128i vF_opn;
        vec128i vFM;
        vec128i vFS;
        vec128i vFL;
        vec128i vH;
        vec128i vHM;
        vec128i vHS;
        vec128i vHL;
        vec128i vHp;
        vec128i vHpM;
        vec128i vHpS;
        vec128i vHpL;
        vec128i *pvW;
        vec128i vW;
        vec128i *pvWM;
        vec128i vWM;
        vec128i *pvWS;
        vec128i vWS;
        vec128i case1;
        vec128i case2;
        vec128i case0;
        vec128i vGapper;
        vec128i vGapperL;

        /* calculate E */
        /* calculate Ht */
        /* calculate F and H first pass */
        vHp = _mm_load_si128(pvH+(segLen-1));
        vHpM = _mm_load_si128(pvHM+(segLen-1));
        vHpS = _mm_load_si128(pvHS+(segLen-1));
        vHpL = _mm_load_si128(pvHL+(segLen-1));
        vHp = _mm_slli_si128(vHp, 8);
        vHpM = _mm_slli_si128(vHpM, 8);
        vHpS = _mm_slli_si128(vHpS, 8);
        vHpL = _mm_slli_si128(vHpL, 8);
        pvW = pvP + matrix->mapper[(unsigned char)s2[j]]*segLen;
        pvWM= pvPm+ matrix->mapper[(unsigned char)s2[j]]*segLen;
        pvWS= pvPs+ matrix->mapper[(unsigned char)s2[j]]*segLen;
        vHt = vZero;
        vF = vNegLimit;
        vFM = vZero;
        vFS = vZero;
        vFL = vZero;
        for (i=0; i<segLen; ++i) {
            vH = _mm_load_si128(pvH+i);
            vHM= _mm_load_si128(pvHM+i);
            vHS= _mm_load_si128(pvHS+i);
            vHL= _mm_load_si128(pvHL+i);
            vE = _mm_load_si128(pvE+i);
            vEM= _mm_load_si128(pvEM+i);
            vES= _mm_load_si128(pvES+i);
            vEL= _mm_load_si128(pvEL+i);
            vW = _mm_load_si128(pvW+i);
            vWM = _mm_load_si128(pvWM+i);
            vWS = _mm_load_si128(pvWS+i);
            vGapper = _mm_load_si128(pvGapper+i);
            vGapperL = _mm_load_si128(pvGapperL+i);
            vE_opn = _mm_sub_epi64(vH, vGapO);
            vE_ext = _mm_sub_epi64(vE, vGapE);
            case1 = _mm_cmpgt_epi64(vE_opn, vE_ext);
            vE = _mm_max_epi64(vE_opn, vE_ext);
            vEM = _mm_blendv_epi8(vEM, vHM, case1);
            vES = _mm_blendv_epi8(vES, vHS, case1);
            vEL = _mm_blendv_epi8(vEL, vHL, case1);
            vEL = _mm_add_epi64(vEL, vOne);
            vGapper = _mm_add_epi64(vHt, vGapper);
            case1 = _mm_or_si128(
                    _mm_cmpgt_epi64(vF, vGapper),
                    _mm_cmpeq_epi64(vF, vGapper));
            vF = _mm_max_epi64(vF, vGapper);
            vFM = _mm_blendv_epi8(vHtM, vFM, case1);
            vFS = _mm_blendv_epi8(vHtS, vFS, case1);
            vFL = _mm_blendv_epi8(
                    _mm_add_epi64(vHtL, vGapperL),
                    vFL, case1);
            vHp = _mm_add_epi64(vHp, vW);
            vHpM = _mm_add_epi64(vHpM, vWM);
            vHpS = _mm_add_epi64(vHpS, vWS);
            vHpL = _mm_add_epi64(vHpL, vOne);
            case1 = _mm_cmpgt_epi64(vE, vHp);
            vHt = _mm_max_epi64(vE, vHp);
            vHtM = _mm_blendv_epi8(vHpM, vEM, case1);
            vHtS = _mm_blendv_epi8(vHpS, vES, case1);
            vHtL = _mm_blendv_epi8(vHpL, vEL, case1);
            _mm_store_si128(pvE+i, vE);
            _mm_store_si128(pvEM+i, vEM);
            _mm_store_si128(pvES+i, vES);
            _mm_store_si128(pvEL+i, vEL);
            _mm_store_si128(pvH+i, vHp);
            _mm_store_si128(pvHM+i, vHpM);
            _mm_store_si128(pvHS+i, vHpS);
            _mm_store_si128(pvHL+i, vHpL);
            vHp = vH;
            vHpM = vHM;
            vHpS = vHS;
            vHpL = vHL;
        }

        /* pseudo prefix scan on F and H */
        vHt = _mm_slli_si128(vHt, 8);
        vHtM = _mm_slli_si128(vHtM, 8);
        vHtS = _mm_slli_si128(vHtS, 8);
        vHtL = _mm_slli_si128(vHtL, 8);
        vGapper = _mm_load_si128(pvGapper);
        vGapperL = _mm_load_si128(pvGapperL);
        vGapper = _mm_add_epi64(vHt, vGapper);
        case1 = _mm_or_si128(
                _mm_cmpgt_epi64(vGapper, vF),
                _mm_cmpeq_epi64(vGapper, vF));
        vF = _mm_max_epi64(vF, vGapper);
        vFM = _mm_blendv_epi8(vFM, vHtM, case1);
        vFS = _mm_blendv_epi8(vFS, vHtS, case1);
        vFL = _mm_blendv_epi8(
                vFL,
                _mm_add_epi64(vHtL, vGapperL),
                case1);
        for (i=0; i<segWidth-2; ++i) {
            vec128i vFt = _mm_slli_si128(vF, 8);
            vec128i vFtM = _mm_slli_si128(vFM, 8);
            vec128i vFtS = _mm_slli_si128(vFS, 8);
            vec128i vFtL = _mm_slli_si128(vFL, 8);
            vFt = _mm_add_epi64(vFt, vSegLenXgap);
            case1 = _mm_or_si128(
                    _mm_cmpgt_epi64(vFt, vF),
                    _mm_cmpeq_epi64(vFt, vF));
            vF = _mm_max_epi64(vF, vFt);
            vFM = _mm_blendv_epi8(vFM, vFtM, case1);
            vFS = _mm_blendv_epi8(vFS, vFtS, case1);
            vFL = _mm_blendv_epi8(
                    vFL,
                    _mm_add_epi64(vFtL, vSegLen),
                    case1);
        }

        /* calculate final H */
        vF = _mm_slli_si128(vF, 8);
        vFM = _mm_slli_si128(vFM, 8);
        vFS = _mm_slli_si128(vFS, 8);
        vFL = _mm_slli_si128(vFL, 8);
        vF = _mm_add_epi64(vF, vNegInfFront);
        case1 = _mm_cmpgt_epi64(vF, vHt);
        vH = _mm_max_epi64(vF, vHt);
        vHM = _mm_blendv_epi8(vHtM, vFM, case1);
        vHS = _mm_blendv_epi8(vHtS, vFS, case1);
        vHL = _mm_blendv_epi8(vHtL, vFL, case1);
        for (i=0; i<segLen; ++i) {
            vHp = _mm_load_si128(pvH+i);
            vHpM = _mm_load_si128(pvHM+i);
            vHpS = _mm_load_si128(pvHS+i);
            vHpL = _mm_load_si128(pvHL+i);
            vE = _mm_load_si128(pvE+i);
            vEM = _mm_load_si128(pvEM+i);
            vES = _mm_load_si128(pvES+i);
            vEL = _mm_load_si128(pvEL+i);
            vF_opn = _mm_sub_epi64(vH, vGapO);
            vF_ext = _mm_sub_epi64(vF, vGapE);
            vF = _mm_max_epi64(vF_opn, vF_ext);
            case1 = _mm_cmpgt_epi64(vF_opn, vF_ext);
            vFM = _mm_blendv_epi8(vFM, vHM, case1);
            vFS = _mm_blendv_epi8(vFS, vHS, case1);
            vFL = _mm_blendv_epi8(vFL, vHL, case1);
            vFL = _mm_add_epi64(vFL, vOne);
            vH = _mm_max_epi64(vHp, vE);
            vH = _mm_max_epi64(vH, vF);
            vH = _mm_max_epi64(vH, vZero);
            case1 = _mm_cmpeq_epi64(vH, vHp);
            case2 = _mm_cmpeq_epi64(vH, vF);
            case0 = _mm_cmpeq_epi64(vH, vZero);
            vHM = _mm_blendv_epi8(
                    _mm_blendv_epi8(vEM, vFM, case2),
                    vHpM, case1);
            vHM = _mm_blendv_epi8(vHM, vZero, case0);
            vHS = _mm_blendv_epi8(
                    _mm_blendv_epi8(vES, vFS, case2),
                    vHpS, case1);
            vHS = _mm_blendv_epi8(vHS, vZero, case0);
            vHL = _mm_blendv_epi8(
                    _mm_blendv_epi8(vEL, vFL, case2),
                    vHpL, case1);
            vHL = _mm_blendv_epi8(vHL, vZero, case0);
            _mm_store_si128(pvH+i, vH);
            _mm_store_si128(pvHM+i, vHM);
            _mm_store_si128(pvHS+i, vHS);
            _mm_store_si128(pvHL+i, vHL);
            vSaturationCheckMin = _mm_min_epi64(vSaturationCheckMin, vH);
            vSaturationCheckMax = _mm_max_epi64(vSaturationCheckMax, vH);
            vSaturationCheckMax = _mm_max_epi64(vSaturationCheckMax, vHM);
            vSaturationCheckMax = _mm_max_epi64(vSaturationCheckMax, vHS);
            vSaturationCheckMax = _mm_max_epi64(vSaturationCheckMax, vHL);
#ifdef PARASAIL_TABLE
            arr_store_si128(result->stats->tables->score_table, vH, i, segLen, j, s2Len);
            arr_store_si128(result->stats->tables->matches_table, vHM, i, segLen, j, s2Len);
            arr_store_si128(result->stats->tables->similar_table, vHS, i, segLen, j, s2Len);
            arr_store_si128(result->stats->tables->length_table, vHL, i, segLen, j, s2Len);
#endif
            {
                vec128i cond_max = _mm_cmpgt_epi64(vH, vMaxH);
                vMaxH = _mm_max_epi64(vH, vMaxH);
                vMaxM = _mm_blendv_epi8(vMaxM, vHM, cond_max);
                vMaxS = _mm_blendv_epi8(vMaxS, vHS, cond_max);
                vMaxL = _mm_blendv_epi8(vMaxL, vHL, cond_max);
            }
        } 

        {
            vec128i vCompare = _mm_cmpgt_epi64(vMaxH, vMaxHUnit);
            if (_mm_movemask_epi8(vCompare)) {
                score = _mm_hmax_epi64(vMaxH);
                vMaxHUnit = _mm_set1_epi64(score);
                end_ref = j;
                (void)memcpy(pvHMax, pvH, sizeof(vec128i)*segLen);
                (void)memcpy(pvHMMax, pvHM, sizeof(vec128i)*segLen);
                (void)memcpy(pvHSMax, pvHS, sizeof(vec128i)*segLen);
                (void)memcpy(pvHLMax, pvHL, sizeof(vec128i)*segLen);
            }
        }

#ifdef PARASAIL_ROWCOL
        /* extract last value from the column */
        {
            int32_t k = 0;
            vec128i vH = _mm_load_si128(pvH + offset);
            vec128i vHM = _mm_load_si128(pvHM + offset);
            vec128i vHS = _mm_load_si128(pvHS + offset);
            vec128i vHL = _mm_load_si128(pvHL + offset);
            for (k=0; k<position; ++k) {
                vH = _mm_slli_si128(vH, 8);
                vHM = _mm_slli_si128(vHM, 8);
                vHS = _mm_slli_si128(vHS, 8);
                vHL = _mm_slli_si128(vHL, 8);
            }
            result->stats->rowcols->score_row[j] = (int64_t) _mm_extract_epi64 (vH, 1);
            result->stats->rowcols->matches_row[j] = (int64_t) _mm_extract_epi64 (vHM, 1);
            result->stats->rowcols->similar_row[j] = (int64_t) _mm_extract_epi64 (vHS, 1);
            result->stats->rowcols->length_row[j] = (int64_t) _mm_extract_epi64 (vHL, 1);
        }
#endif
    }

    /* Trace the alignment ending position on read. */
    {
        int64_t *t = (int64_t*)pvHMax;
        int64_t *m = (int64_t*)pvHMMax;
        int64_t *s = (int64_t*)pvHSMax;
        int64_t *l = (int64_t*)pvHLMax;
        int32_t column_len = segLen * segWidth;
        end_query = s1Len;
        for (i = 0; i<column_len; ++i, ++t, ++m, ++s, ++l) {
            if (*t == score) {
                int32_t temp = i / segWidth + i % segWidth * segLen;
                if (temp < end_query) {
                    end_query = temp;
                    matches = *m;
                    similar = *s;
                    length = *l;
                }
            }
        }
    }

#ifdef PARASAIL_ROWCOL
    for (i=0; i<segLen; ++i) {
        vec128i vH = _mm_load_si128(pvH+i);
        vec128i vHM = _mm_load_si128(pvHM+i);
        vec128i vHS = _mm_load_si128(pvHS+i);
        vec128i vHL = _mm_load_si128(pvHL+i);
        arr_store_col(result->stats->rowcols->score_col, vH, i, segLen);
        arr_store_col(result->stats->rowcols->matches_col, vHM, i, segLen);
        arr_store_col(result->stats->rowcols->similar_col, vHS, i, segLen);
        arr_store_col(result->stats->rowcols->length_col, vHL, i, segLen);
    }
#endif

    if (_mm_movemask_epi8(_mm_or_si128(
            _mm_cmplt_epi64(vSaturationCheckMin, vNegLimit),
            _mm_cmpgt_epi64(vSaturationCheckMax, vPosLimit)))) {
        result->flag |= PARASAIL_FLAG_SATURATED;
        score = 0;
        matches = 0;
        similar = 0;
        length = 0;
        end_query = 0;
        end_ref = 0;
    }

    result->score = score;
    result->end_query = end_query;
    result->end_ref = end_ref;
    result->stats->matches = matches;
    result->stats->similar = similar;
    result->stats->length = length;

    parasail_free(pvGapperL);
    parasail_free(pvGapper);
    parasail_free(pvHLMax);
    parasail_free(pvHSMax);
    parasail_free(pvHMMax);
    parasail_free(pvHMax);
    parasail_free(pvHL);
    parasail_free(pvHS);
    parasail_free(pvHM);
    parasail_free(pvH);
    parasail_free(pvEL);
    parasail_free(pvES);
    parasail_free(pvEM);
    parasail_free(pvE);

    return result;
}


