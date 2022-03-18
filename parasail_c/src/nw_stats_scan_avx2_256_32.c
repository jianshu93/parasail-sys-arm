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

#include <immintrin.h>

#include "parasail.h"
#include "parasail/memory.h"
#include "parasail/internal_avx.h"


#if HAVE_AVX2_MM256_INSERT_EPI32
#define _mm256_insert_epi32_rpl _mm256_insert_epi32
#else
static inline __m256i _mm256_insert_epi32_rpl(__m256i a, int32_t i, int imm) {
    __m256i_32_t A;
    A.m = a;
    A.v[imm] = i;
    return A.m;
}
#endif

#if HAVE_AVX2_MM256_EXTRACT_EPI32
#define _mm256_extract_epi32_rpl _mm256_extract_epi32
#else
static inline int32_t _mm256_extract_epi32_rpl(__m256i a, int imm) {
    __m256i_32_t A;
    A.m = a;
    return A.v[imm];
}
#endif

#define _mm256_cmplt_epi32_rpl(a,b) _mm256_cmpgt_epi32(b,a)

#define _mm256_slli_si256_rpl(a,imm) _mm256_alignr_epi8(a, _mm256_permute2x128_si256(a, a, _MM_SHUFFLE(0,0,3,0)), 16-imm)


#ifdef PARASAIL_TABLE
static inline void arr_store_si256(
        int *array,
        __m256i vH,
        int32_t t,
        int32_t seglen,
        int32_t d,
        int32_t dlen)
{
    array[1LL*(0*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 0);
    array[1LL*(1*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 1);
    array[1LL*(2*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 2);
    array[1LL*(3*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 3);
    array[1LL*(4*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 4);
    array[1LL*(5*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 5);
    array[1LL*(6*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 6);
    array[1LL*(7*seglen+t)*dlen + d] = (int32_t)_mm256_extract_epi32_rpl(vH, 7);
}
#endif

#ifdef PARASAIL_ROWCOL
static inline void arr_store_col(
        int *col,
        __m256i vH,
        int32_t t,
        int32_t seglen)
{
    col[0*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 0);
    col[1*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 1);
    col[2*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 2);
    col[3*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 3);
    col[4*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 4);
    col[5*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 5);
    col[6*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 6);
    col[7*seglen+t] = (int32_t)_mm256_extract_epi32_rpl(vH, 7);
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_nw_stats_table_scan_avx2_256_32
#define PNAME parasail_nw_stats_table_scan_profile_avx2_256_32
#else
#ifdef PARASAIL_ROWCOL
#define FNAME parasail_nw_stats_rowcol_scan_avx2_256_32
#define PNAME parasail_nw_stats_rowcol_scan_profile_avx2_256_32
#else
#define FNAME parasail_nw_stats_scan_avx2_256_32
#define PNAME parasail_nw_stats_scan_profile_avx2_256_32
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
    profile = parasail_profile_create_stats_avx_256_32(s1, s1Len, matrix);
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
    int32_t k = 0;
    int32_t s1Len = 0;
    int32_t end_query = 0;
    int32_t end_ref = 0;
    const parasail_matrix_t *matrix = NULL;
    int32_t segWidth = 0;
    int32_t segLen = 0;
    int32_t offset = 0;
    int32_t position = 0;
    __m256i* restrict pvP = NULL;
    __m256i* restrict pvPm = NULL;
    __m256i* restrict pvPs = NULL;
    __m256i* restrict pvE = NULL;
    __m256i* restrict pvEM = NULL;
    __m256i* restrict pvES = NULL;
    __m256i* restrict pvEL = NULL;
    __m256i* restrict pvH = NULL;
    __m256i* restrict pvHM = NULL;
    __m256i* restrict pvHS = NULL;
    __m256i* restrict pvHL = NULL;
    __m256i* restrict pvHMax = NULL;
    __m256i* restrict pvHMMax = NULL;
    __m256i* restrict pvHSMax = NULL;
    __m256i* restrict pvHLMax = NULL;
    __m256i* restrict pvGapper = NULL;
    __m256i* restrict pvGapperL = NULL;
    int32_t* restrict boundary = NULL;
    __m256i vGapO;
    __m256i vGapE;
    int32_t NEG_LIMIT = 0;
    int32_t POS_LIMIT = 0;
    __m256i vZero;
    __m256i vOne;
    int32_t score = 0;
    int32_t matches = 0;
    int32_t similar = 0;
    int32_t length = 0;
    __m256i vNegLimit;
    __m256i vPosLimit;
    __m256i vSaturationCheckMin;
    __m256i vSaturationCheckMax;
    __m256i vNegInfFront;
    __m256i vSegLenXgap;
    __m256i vSegLen;
    parasail_result_t *result = NULL;

    /* validate inputs */
    PARASAIL_CHECK_NULL(profile);
    PARASAIL_CHECK_NULL(profile->profile32.score);
    PARASAIL_CHECK_NULL(profile->matrix);
    PARASAIL_CHECK_GT0(profile->s1Len);
    PARASAIL_CHECK_NULL(s2);
    PARASAIL_CHECK_GT0(s2Len);
    PARASAIL_CHECK_GE0(open);
    PARASAIL_CHECK_GE0(gap);

    /* initialize stack variables */
    i = 0;
    j = 0;
    k = 0;
    s1Len = profile->s1Len;
    end_query = s1Len-1;
    end_ref = s2Len-1;
    matrix = profile->matrix;
    segWidth = 8; /* number of values in vector unit */
    segLen = (s1Len + segWidth - 1) / segWidth;
    offset = (s1Len - 1) % segLen;
    position = (segWidth - 1) - (s1Len - 1) / segLen;
    pvP  = (__m256i*)profile->profile32.score;
    pvPm = (__m256i*)profile->profile32.matches;
    pvPs = (__m256i*)profile->profile32.similar;
    vGapO = _mm256_set1_epi32(open);
    vGapE = _mm256_set1_epi32(gap);
    NEG_LIMIT = (-open < matrix->min ? INT32_MIN + open : INT32_MIN - matrix->min) + 1;
    POS_LIMIT = INT32_MAX - matrix->max - 1;
    vZero = _mm256_setzero_si256();
    vOne = _mm256_set1_epi32(1);
    score = NEG_LIMIT;
    matches = 0;
    similar = 0;
    length = 0;
    vNegLimit = _mm256_set1_epi32(NEG_LIMIT);
    vPosLimit = _mm256_set1_epi32(POS_LIMIT);
    vSaturationCheckMin = vPosLimit;
    vSaturationCheckMax = vNegLimit;
    vNegInfFront = vZero;
    vSegLen = _mm256_slli_si256_rpl(_mm256_set1_epi32(segLen), 4);
    vNegInfFront = _mm256_insert_epi32_rpl(vNegInfFront, NEG_LIMIT, 0);
    vSegLenXgap = _mm256_add_epi32(vNegInfFront,
            _mm256_slli_si256_rpl(_mm256_set1_epi32(-segLen*gap), 4));

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
    result->flag |= PARASAIL_FLAG_NW | PARASAIL_FLAG_SCAN
        | PARASAIL_FLAG_STATS
        | PARASAIL_FLAG_BITS_32 | PARASAIL_FLAG_LANES_8;
#ifdef PARASAIL_TABLE
    result->flag |= PARASAIL_FLAG_TABLE;
#endif
#ifdef PARASAIL_ROWCOL
    result->flag |= PARASAIL_FLAG_ROWCOL;
#endif

    /* initialize heap variables */
    pvE  = parasail_memalign___m256i(32, segLen);
    pvEM = parasail_memalign___m256i(32, segLen);
    pvES = parasail_memalign___m256i(32, segLen);
    pvEL = parasail_memalign___m256i(32, segLen);
    pvH  = parasail_memalign___m256i(32, segLen);
    pvHM = parasail_memalign___m256i(32, segLen);
    pvHS = parasail_memalign___m256i(32, segLen);
    pvHL = parasail_memalign___m256i(32, segLen);
    pvHMax  = parasail_memalign___m256i(32, segLen);
    pvHMMax = parasail_memalign___m256i(32, segLen);
    pvHSMax = parasail_memalign___m256i(32, segLen);
    pvHLMax = parasail_memalign___m256i(32, segLen);
    pvGapper = parasail_memalign___m256i(32, segLen);
    pvGapperL = parasail_memalign___m256i(32, segLen);
    boundary = parasail_memalign_int32_t(32, s2Len+1);

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
    if (!boundary) return NULL;

    parasail_memset___m256i(pvHM, vZero, segLen);
    parasail_memset___m256i(pvHS, vZero, segLen);
    parasail_memset___m256i(pvHL, vZero, segLen);
    parasail_memset___m256i(pvE, vNegLimit, segLen);
    parasail_memset___m256i(pvEM, vZero, segLen);
    parasail_memset___m256i(pvES, vZero, segLen);
    parasail_memset___m256i(pvEL, vZero, segLen);
    {
        __m256i vGapper = _mm256_sub_epi32(vZero,vGapO);
        __m256i vGapperL = vOne;
        for (i=segLen-1; i>=0; --i) {
            _mm256_store_si256(pvGapper+i, vGapper);
            _mm256_store_si256(pvGapperL+i, vGapperL);
            vGapper = _mm256_sub_epi32(vGapper, vGapE);
            vGapperL = _mm256_add_epi32(vGapperL, vOne);
        }
    }

    /* initialize H */
    {
        int32_t index = 0;
        for (i=0; i<segLen; ++i) {
            int32_t segNum = 0;
            __m256i_32_t h;
            for (segNum=0; segNum<segWidth; ++segNum) {
                int64_t tmp = -open-gap*(segNum*segLen+i);
                h.v[segNum] = tmp < INT32_MIN ? INT32_MIN : tmp;
            }
            _mm256_store_si256(&pvH[index], h.m);
            ++index;
        }
    }

    /* initialize uppder boundary */
    {
        boundary[0] = 0;
        for (i=1; i<=s2Len; ++i) {
            int64_t tmp = -open-gap*(i-1);
            boundary[i] = tmp < INT32_MIN ? INT32_MIN : tmp;
        }
    }

    /* outer loop over database sequence */
    for (j=0; j<s2Len; ++j) {
        __m256i vE;
        __m256i vE_ext;
        __m256i vE_opn;
        __m256i vEM;
        __m256i vES;
        __m256i vEL;
        __m256i vHt;
        __m256i vHtM;
        __m256i vHtS;
        __m256i vHtL;
        __m256i vF;
        __m256i vF_ext;
        __m256i vF_opn;
        __m256i vFM;
        __m256i vFS;
        __m256i vFL;
        __m256i vH;
        __m256i vHM;
        __m256i vHS;
        __m256i vHL;
        __m256i vHp;
        __m256i vHpM;
        __m256i vHpS;
        __m256i vHpL;
        __m256i *pvW;
        __m256i vW;
        __m256i *pvWM;
        __m256i vWM;
        __m256i *pvWS;
        __m256i vWS;
        __m256i case1;
        __m256i case2;
        __m256i vGapper;
        __m256i vGapperL;

        /* calculate E */
        /* calculate Ht */
        /* calculate F and H first pass */
        vHp = _mm256_load_si256(pvH+(segLen-1));
        vHpM = _mm256_load_si256(pvHM+(segLen-1));
        vHpS = _mm256_load_si256(pvHS+(segLen-1));
        vHpL = _mm256_load_si256(pvHL+(segLen-1));
        vHp = _mm256_slli_si256_rpl(vHp, 4);
        vHpM = _mm256_slli_si256_rpl(vHpM, 4);
        vHpS = _mm256_slli_si256_rpl(vHpS, 4);
        vHpL = _mm256_slli_si256_rpl(vHpL, 4);
        vHp = _mm256_insert_epi32_rpl(vHp, boundary[j], 0);
        pvW = pvP + matrix->mapper[(unsigned char)s2[j]]*segLen;
        pvWM= pvPm+ matrix->mapper[(unsigned char)s2[j]]*segLen;
        pvWS= pvPs+ matrix->mapper[(unsigned char)s2[j]]*segLen;
        vHt = _mm256_sub_epi32(vNegLimit, pvGapper[0]);
        vF = vNegLimit;
        vFM = vZero;
        vFS = vZero;
        vFL = vZero;
        for (i=0; i<segLen; ++i) {
            vH = _mm256_load_si256(pvH+i);
            vHM= _mm256_load_si256(pvHM+i);
            vHS= _mm256_load_si256(pvHS+i);
            vHL= _mm256_load_si256(pvHL+i);
            vE = _mm256_load_si256(pvE+i);
            vEM= _mm256_load_si256(pvEM+i);
            vES= _mm256_load_si256(pvES+i);
            vEL= _mm256_load_si256(pvEL+i);
            vW = _mm256_load_si256(pvW+i);
            vWM = _mm256_load_si256(pvWM+i);
            vWS = _mm256_load_si256(pvWS+i);
            vGapper = _mm256_load_si256(pvGapper+i);
            vGapperL = _mm256_load_si256(pvGapperL+i);
            vE_opn = _mm256_sub_epi32(vH, vGapO);
            vE_ext = _mm256_sub_epi32(vE, vGapE);
            case1 = _mm256_cmpgt_epi32(vE_opn, vE_ext);
            vE = _mm256_max_epi32(vE_opn, vE_ext);
            vEM = _mm256_blendv_epi8(vEM, vHM, case1);
            vES = _mm256_blendv_epi8(vES, vHS, case1);
            vEL = _mm256_blendv_epi8(vEL, vHL, case1);
            vEL = _mm256_add_epi32(vEL, vOne);
            vGapper = _mm256_add_epi32(vHt, vGapper);
            case1 = _mm256_or_si256(
                    _mm256_cmpgt_epi32(vF, vGapper),
                    _mm256_cmpeq_epi32(vF, vGapper));
            vF = _mm256_max_epi32(vF, vGapper);
            vFM = _mm256_blendv_epi8(vHtM, vFM, case1);
            vFS = _mm256_blendv_epi8(vHtS, vFS, case1);
            vFL = _mm256_blendv_epi8(
                    _mm256_add_epi32(vHtL, vGapperL),
                    vFL, case1);
            vHp = _mm256_add_epi32(vHp, vW);
            vHpM = _mm256_add_epi32(vHpM, vWM);
            vHpS = _mm256_add_epi32(vHpS, vWS);
            vHpL = _mm256_add_epi32(vHpL, vOne);
            case1 = _mm256_cmpgt_epi32(vE, vHp);
            vHt = _mm256_max_epi32(vE, vHp);
            vHtM = _mm256_blendv_epi8(vHpM, vEM, case1);
            vHtS = _mm256_blendv_epi8(vHpS, vES, case1);
            vHtL = _mm256_blendv_epi8(vHpL, vEL, case1);
            _mm256_store_si256(pvE+i, vE);
            _mm256_store_si256(pvEM+i, vEM);
            _mm256_store_si256(pvES+i, vES);
            _mm256_store_si256(pvEL+i, vEL);
            _mm256_store_si256(pvH+i, vHp);
            _mm256_store_si256(pvHM+i, vHpM);
            _mm256_store_si256(pvHS+i, vHpS);
            _mm256_store_si256(pvHL+i, vHpL);
            vHp = vH;
            vHpM = vHM;
            vHpS = vHS;
            vHpL = vHL;
        }

        /* pseudo prefix scan on F and H */
        vHt = _mm256_slli_si256_rpl(vHt, 4);
        vHtM = _mm256_slli_si256_rpl(vHtM, 4);
        vHtS = _mm256_slli_si256_rpl(vHtS, 4);
        vHtL = _mm256_slli_si256_rpl(vHtL, 4);
        vHt = _mm256_insert_epi32_rpl(vHt, boundary[j+1], 0);
        vGapper = _mm256_load_si256(pvGapper);
        vGapperL = _mm256_load_si256(pvGapperL);
        vGapper = _mm256_add_epi32(vHt, vGapper);
        case1 = _mm256_or_si256(
                _mm256_cmpgt_epi32(vGapper, vF),
                _mm256_cmpeq_epi32(vGapper, vF));
        vF = _mm256_max_epi32(vF, vGapper);
        vFM = _mm256_blendv_epi8(vFM, vHtM, case1);
        vFS = _mm256_blendv_epi8(vFS, vHtS, case1);
        vFL = _mm256_blendv_epi8(
                vFL,
                _mm256_add_epi32(vHtL, vGapperL),
                case1);
        for (i=0; i<segWidth-2; ++i) {
            __m256i vFt = _mm256_slli_si256_rpl(vF, 4);
            __m256i vFtM = _mm256_slli_si256_rpl(vFM, 4);
            __m256i vFtS = _mm256_slli_si256_rpl(vFS, 4);
            __m256i vFtL = _mm256_slli_si256_rpl(vFL, 4);
            vFt = _mm256_add_epi32(vFt, vSegLenXgap);
            case1 = _mm256_or_si256(
                    _mm256_cmpgt_epi32(vFt, vF),
                    _mm256_cmpeq_epi32(vFt, vF));
            vF = _mm256_max_epi32(vF, vFt);
            vFM = _mm256_blendv_epi8(vFM, vFtM, case1);
            vFS = _mm256_blendv_epi8(vFS, vFtS, case1);
            vFL = _mm256_blendv_epi8(
                    vFL,
                    _mm256_add_epi32(vFtL, vSegLen),
                    case1);
        }

        /* calculate final H */
        vF = _mm256_slli_si256_rpl(vF, 4);
        vFM = _mm256_slli_si256_rpl(vFM, 4);
        vFS = _mm256_slli_si256_rpl(vFS, 4);
        vFL = _mm256_slli_si256_rpl(vFL, 4);
        vF = _mm256_add_epi32(vF, vNegInfFront);
        case1 = _mm256_cmpgt_epi32(vF, vHt);
        vH = _mm256_max_epi32(vF, vHt);
        vHM = _mm256_blendv_epi8(vHtM, vFM, case1);
        vHS = _mm256_blendv_epi8(vHtS, vFS, case1);
        vHL = _mm256_blendv_epi8(vHtL, vFL, case1);
        for (i=0; i<segLen; ++i) {
            vHp = _mm256_load_si256(pvH+i);
            vHpM = _mm256_load_si256(pvHM+i);
            vHpS = _mm256_load_si256(pvHS+i);
            vHpL = _mm256_load_si256(pvHL+i);
            vE = _mm256_load_si256(pvE+i);
            vEM = _mm256_load_si256(pvEM+i);
            vES = _mm256_load_si256(pvES+i);
            vEL = _mm256_load_si256(pvEL+i);
            vF_opn = _mm256_sub_epi32(vH, vGapO);
            vF_ext = _mm256_sub_epi32(vF, vGapE);
            vF = _mm256_max_epi32(vF_opn, vF_ext);
            case1 = _mm256_cmpgt_epi32(vF_opn, vF_ext);
            vFM = _mm256_blendv_epi8(vFM, vHM, case1);
            vFS = _mm256_blendv_epi8(vFS, vHS, case1);
            vFL = _mm256_blendv_epi8(vFL, vHL, case1);
            vFL = _mm256_add_epi32(vFL, vOne);
            vH = _mm256_max_epi32(vHp, vE);
            vH = _mm256_max_epi32(vH, vF);
            case1 = _mm256_cmpeq_epi32(vH, vHp);
            case2 = _mm256_cmpeq_epi32(vH, vF);
            vHM = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vEM, vFM, case2),
                    vHpM, case1);
            vHS = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vES, vFS, case2),
                    vHpS, case1);
            vHL = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vEL, vFL, case2),
                    vHpL, case1);
            _mm256_store_si256(pvH+i, vH);
            _mm256_store_si256(pvHM+i, vHM);
            _mm256_store_si256(pvHS+i, vHS);
            _mm256_store_si256(pvHL+i, vHL);
            vSaturationCheckMin = _mm256_min_epi32(vSaturationCheckMin, vH);
            vSaturationCheckMax = _mm256_max_epi32(vSaturationCheckMax, vH);
            vSaturationCheckMax = _mm256_max_epi32(vSaturationCheckMax, vHM);
            vSaturationCheckMax = _mm256_max_epi32(vSaturationCheckMax, vHS);
            vSaturationCheckMax = _mm256_max_epi32(vSaturationCheckMax, vHL);
#ifdef PARASAIL_TABLE
            arr_store_si256(result->stats->tables->score_table, vH, i, segLen, j, s2Len);
            arr_store_si256(result->stats->tables->matches_table, vHM, i, segLen, j, s2Len);
            arr_store_si256(result->stats->tables->similar_table, vHS, i, segLen, j, s2Len);
            arr_store_si256(result->stats->tables->length_table, vHL, i, segLen, j, s2Len);
#endif
        } 

#ifdef PARASAIL_ROWCOL
        /* extract last value from the column */
        {
            vH = _mm256_load_si256(pvH + offset);
            vHM = _mm256_load_si256(pvHM + offset);
            vHS = _mm256_load_si256(pvHS + offset);
            vHL = _mm256_load_si256(pvHL + offset);
            for (k=0; k<position; ++k) {
                vH = _mm256_slli_si256_rpl(vH, 4);
                vHM = _mm256_slli_si256_rpl(vHM, 4);
                vHS = _mm256_slli_si256_rpl(vHS, 4);
                vHL = _mm256_slli_si256_rpl(vHL, 4);
            }
            result->stats->rowcols->score_row[j] = (int32_t) _mm256_extract_epi32_rpl (vH, 7);
            result->stats->rowcols->matches_row[j] = (int32_t) _mm256_extract_epi32_rpl (vHM, 7);
            result->stats->rowcols->similar_row[j] = (int32_t) _mm256_extract_epi32_rpl (vHS, 7);
            result->stats->rowcols->length_row[j] = (int32_t) _mm256_extract_epi32_rpl (vHL, 7);
        }
#endif
    }

#ifdef PARASAIL_ROWCOL
    for (i=0; i<segLen; ++i) {
        __m256i vH = _mm256_load_si256(pvH+i);
        __m256i vHM = _mm256_load_si256(pvHM+i);
        __m256i vHS = _mm256_load_si256(pvHS+i);
        __m256i vHL = _mm256_load_si256(pvHL+i);
        arr_store_col(result->stats->rowcols->score_col, vH, i, segLen);
        arr_store_col(result->stats->rowcols->matches_col, vHM, i, segLen);
        arr_store_col(result->stats->rowcols->similar_col, vHS, i, segLen);
        arr_store_col(result->stats->rowcols->length_col, vHL, i, segLen);
    }
#endif

    /* extract last value from the last column */
    {
        __m256i vH = _mm256_load_si256(pvH + offset);
        __m256i vHM = _mm256_load_si256(pvHM + offset);
        __m256i vHS = _mm256_load_si256(pvHS + offset);
        __m256i vHL = _mm256_load_si256(pvHL + offset);
        for (k=0; k<position; ++k) {
            vH = _mm256_slli_si256_rpl(vH, 4);
            vHM = _mm256_slli_si256_rpl(vHM, 4);
            vHS = _mm256_slli_si256_rpl(vHS, 4);
            vHL = _mm256_slli_si256_rpl(vHL, 4);
        }
        score = (int32_t) _mm256_extract_epi32_rpl (vH, 7);
        matches = (int32_t) _mm256_extract_epi32_rpl (vHM, 7);
        similar = (int32_t) _mm256_extract_epi32_rpl (vHS, 7);
        length = (int32_t) _mm256_extract_epi32_rpl (vHL, 7);
    }

    if (_mm256_movemask_epi8(_mm256_or_si256(
            _mm256_cmplt_epi32_rpl(vSaturationCheckMin, vNegLimit),
            _mm256_cmpgt_epi32(vSaturationCheckMax, vPosLimit)))) {
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

    parasail_free(boundary);
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


