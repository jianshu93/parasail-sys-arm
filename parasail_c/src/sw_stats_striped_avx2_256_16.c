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

#define FASTSTATS

#define SWAP(A,B) { __m256i* tmp = A; A = B; B = tmp; }
#define SWAP3(A,B,C) { __m256i* tmp = A; A = B; B = C; C = tmp; }

#define NEG_INF INT16_MIN

#if HAVE_AVX2_MM256_EXTRACT_EPI16
#define _mm256_extract_epi16_rpl _mm256_extract_epi16
#else
static inline int16_t _mm256_extract_epi16_rpl(__m256i a, int imm) {
    __m256i_16_t A;
    A.m = a;
    return A.v[imm];
}
#endif

#define _mm256_slli_si256_rpl(a,imm) _mm256_alignr_epi8(a, _mm256_permute2x128_si256(a, a, _MM_SHUFFLE(0,0,3,0)), 16-imm)

static inline int16_t _mm256_hmax_epi16_rpl(__m256i a) {
    a = _mm256_max_epi16(a, _mm256_permute2x128_si256(a, a, _MM_SHUFFLE(0,0,0,0)));
    a = _mm256_max_epi16(a, _mm256_slli_si256(a, 8));
    a = _mm256_max_epi16(a, _mm256_slli_si256(a, 4));
    a = _mm256_max_epi16(a, _mm256_slli_si256(a, 2));
    return _mm256_extract_epi16_rpl(a, 15);
}


#ifdef PARASAIL_TABLE
static inline void arr_store(
        int *array,
        __m256i vH,
        int32_t t,
        int32_t seglen,
        int32_t d,
        int32_t dlen,
        int32_t bias)
{
    array[1LL*( 0*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH,  0) - bias;
    array[1LL*( 1*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH,  1) - bias;
    array[1LL*( 2*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH,  2) - bias;
    array[1LL*( 3*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH,  3) - bias;
    array[1LL*( 4*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH,  4) - bias;
    array[1LL*( 5*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH,  5) - bias;
    array[1LL*( 6*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH,  6) - bias;
    array[1LL*( 7*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH,  7) - bias;
    array[1LL*( 8*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH,  8) - bias;
    array[1LL*( 9*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH,  9) - bias;
    array[1LL*(10*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH, 10) - bias;
    array[1LL*(11*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH, 11) - bias;
    array[1LL*(12*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH, 12) - bias;
    array[1LL*(13*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH, 13) - bias;
    array[1LL*(14*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH, 14) - bias;
    array[1LL*(15*seglen+t)*dlen + d] = (int16_t)_mm256_extract_epi16_rpl(vH, 15) - bias;
}
#endif

#ifdef PARASAIL_ROWCOL
static inline void arr_store_col(
        int *col,
        __m256i vH,
        int32_t t,
        int32_t seglen,
        int32_t bias)
{
    col[ 0*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH,  0) - bias;
    col[ 1*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH,  1) - bias;
    col[ 2*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH,  2) - bias;
    col[ 3*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH,  3) - bias;
    col[ 4*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH,  4) - bias;
    col[ 5*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH,  5) - bias;
    col[ 6*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH,  6) - bias;
    col[ 7*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH,  7) - bias;
    col[ 8*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH,  8) - bias;
    col[ 9*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH,  9) - bias;
    col[10*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH, 10) - bias;
    col[11*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH, 11) - bias;
    col[12*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH, 12) - bias;
    col[13*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH, 13) - bias;
    col[14*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH, 14) - bias;
    col[15*seglen+t] = (int16_t)_mm256_extract_epi16_rpl(vH, 15) - bias;
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_sw_stats_table_striped_avx2_256_16
#define PNAME parasail_sw_stats_table_striped_profile_avx2_256_16
#define INAME PNAME
#define STATIC
#else
#ifdef PARASAIL_ROWCOL
#define FNAME parasail_sw_stats_rowcol_striped_avx2_256_16
#define PNAME parasail_sw_stats_rowcol_striped_profile_avx2_256_16
#define INAME PNAME
#define STATIC
#else
#define FNAME parasail_sw_stats_striped_avx2_256_16
#ifdef FASTSTATS
#define PNAME parasail_sw_stats_striped_profile_avx2_256_16_internal
#define INAME parasail_sw_stats_striped_profile_avx2_256_16
#define STATIC static
#else
#define PNAME parasail_sw_stats_striped_profile_avx2_256_16
#define INAME PNAME
#define STATIC
#endif
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
    profile = parasail_profile_create_stats_avx_256_16(s1, s1Len, matrix);
    if (!profile) return NULL;
    result = INAME(profile, s2, s2Len, open, gap);

    parasail_profile_free(profile);

    return result;
}

STATIC parasail_result_t* PNAME(
        const parasail_profile_t * const restrict profile,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap)
{
    /* declare local variables */
    int32_t i = 0;
    int32_t j = 0;
    int32_t k = 0;
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
    __m256i* restrict vProfile = NULL;
    __m256i* restrict vProfileM = NULL;
    __m256i* restrict vProfileS = NULL;
    __m256i* restrict pvHStore = NULL;
    __m256i* restrict pvHLoad = NULL;
    __m256i* restrict pvHMStore = NULL;
    __m256i* restrict pvHMLoad = NULL;
    __m256i* restrict pvHSStore = NULL;
    __m256i* restrict pvHSLoad = NULL;
    __m256i* restrict pvHLStore = NULL;
    __m256i* restrict pvHLLoad = NULL;
    __m256i* restrict pvE = NULL;
    __m256i* restrict pvEM = NULL;
    __m256i* restrict pvES = NULL;
    __m256i* restrict pvEL = NULL;
    __m256i* restrict pvHMax = NULL;
    __m256i* restrict pvHMMax = NULL;
    __m256i* restrict pvHSMax = NULL;
    __m256i* restrict pvHLMax = NULL;
    __m256i vGapO;
    __m256i vGapE;
    __m256i vZero;
    __m256i vOne;
    int16_t bias = 0;
    int16_t score = 0;
    int16_t matches = 0;
    int16_t similar = 0;
    int16_t length = 0;
    __m256i vBias;
    __m256i vBias1;
    __m256i vMaxH;
    __m256i vMaxHUnit;
    __m256i insert_mask;
    __m256i vSaturationCheckMax;
    __m256i vPosLimit;
    int16_t maxp = 0;
    parasail_result_t *result = NULL;

    /* validate inputs */
    PARASAIL_CHECK_NULL(profile);
    PARASAIL_CHECK_NULL(profile->profile16.score);
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
    end_query = 0;
    end_ref = 0;
    s1Len = profile->s1Len;
    matrix = profile->matrix;
    segWidth = 16; /* number of values in vector unit */
    segLen = (s1Len + segWidth - 1) / segWidth;
#ifdef PARASAIL_ROWCOL
    offset = (s1Len - 1) % segLen;
    position = (segWidth - 1) - (s1Len - 1) / segLen;
#endif
    vProfile  = (__m256i*)profile->profile16.score;
    vProfileM = (__m256i*)profile->profile16.matches;
    vProfileS = (__m256i*)profile->profile16.similar;
    vGapO = _mm256_set1_epi16(open);
    vGapE = _mm256_set1_epi16(gap);
    vZero = _mm256_setzero_si256();
    vOne = _mm256_set1_epi16(1);
    bias = INT16_MIN;
    score = bias;
    matches = bias;
    similar = bias;
    length = bias;
    vBias = _mm256_set1_epi16(bias);
    vBias1 = _mm256_adds_epi16(vBias,vOne);
    vMaxH = vBias;
    vMaxHUnit = vBias;
    insert_mask = _mm256_cmpgt_epi16(
            _mm256_set_epi16(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1),
            vZero);
    vSaturationCheckMax = vBias;
    vPosLimit = _mm256_set1_epi16(INT16_MAX);
    maxp = INT16_MAX - (int16_t)(matrix->max+1);

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
    result->flag |= PARASAIL_FLAG_SW | PARASAIL_FLAG_STRIPED
        | PARASAIL_FLAG_STATS
        | PARASAIL_FLAG_BITS_16 | PARASAIL_FLAG_LANES_16;
#ifdef PARASAIL_TABLE
    result->flag |= PARASAIL_FLAG_TABLE;
#endif
#ifdef PARASAIL_ROWCOL
    result->flag |= PARASAIL_FLAG_ROWCOL;
#endif

    /* initialize heap variables */
    pvHStore  = parasail_memalign___m256i(32, segLen);
    pvHLoad   = parasail_memalign___m256i(32, segLen);
    pvHMStore = parasail_memalign___m256i(32, segLen);
    pvHMLoad  = parasail_memalign___m256i(32, segLen);
    pvHSStore = parasail_memalign___m256i(32, segLen);
    pvHSLoad  = parasail_memalign___m256i(32, segLen);
    pvHLStore = parasail_memalign___m256i(32, segLen);
    pvHLLoad  = parasail_memalign___m256i(32, segLen);
    pvE       = parasail_memalign___m256i(32, segLen);
    pvEM      = parasail_memalign___m256i(32, segLen);
    pvES      = parasail_memalign___m256i(32, segLen);
    pvEL      = parasail_memalign___m256i(32, segLen);
    pvHMax    = parasail_memalign___m256i(32, segLen);
    pvHMMax   = parasail_memalign___m256i(32, segLen);
    pvHSMax   = parasail_memalign___m256i(32, segLen);
    pvHLMax   = parasail_memalign___m256i(32, segLen);

    /* validate heap variables */
    if (!pvHStore) return NULL;
    if (!pvHLoad) return NULL;
    if (!pvHMStore) return NULL;
    if (!pvHMLoad) return NULL;
    if (!pvHSStore) return NULL;
    if (!pvHSLoad) return NULL;
    if (!pvHLStore) return NULL;
    if (!pvHLLoad) return NULL;
    if (!pvE) return NULL;
    if (!pvEM) return NULL;
    if (!pvES) return NULL;
    if (!pvEL) return NULL;
    if (!pvHMax) return NULL;
    if (!pvHMMax) return NULL;
    if (!pvHSMax) return NULL;
    if (!pvHLMax) return NULL;

    parasail_memset___m256i(pvHStore, vBias, segLen);
    parasail_memset___m256i(pvHMStore, vBias, segLen);
    parasail_memset___m256i(pvHSStore, vBias, segLen);
    parasail_memset___m256i(pvHLStore, vBias, segLen);
    parasail_memset___m256i(pvE, vBias, segLen);
    parasail_memset___m256i(pvEM, vBias, segLen);
    parasail_memset___m256i(pvES, vBias, segLen);
    parasail_memset___m256i(pvEL, vBias1, segLen);

    /* outer loop over database sequence */
    for (j=0; j<s2Len; ++j) {
        __m256i vEF_opn;
        __m256i vE;
        __m256i vE_ext;
        __m256i vEM;
        __m256i vES;
        __m256i vEL;
        __m256i vF;
        __m256i vF_ext;
        __m256i vFM;
        __m256i vFS;
        __m256i vFL;
        __m256i vH;
        __m256i vH_dag;
        __m256i vHM;
        __m256i vHS;
        __m256i vHL;
        const __m256i* vP = NULL;
        const __m256i* vPM = NULL;
        const __m256i* vPS = NULL;

        /* Initialize F value to 0.  Any errors to vH values will be
         * corrected in the Lazy_F loop. */
        vF = vBias;
        vFM = vBias;
        vFS = vBias;
        vFL = vBias1;

        /* load final segment of pvHStore and shift left by 2 bytes */
        vH = _mm256_load_si256(&pvHStore[segLen - 1]);
        vHM = _mm256_load_si256(&pvHMStore[segLen - 1]);
        vHS = _mm256_load_si256(&pvHSStore[segLen - 1]);
        vHL = _mm256_load_si256(&pvHLStore[segLen - 1]);
        vH = _mm256_slli_si256_rpl(vH, 2);
        vHM = _mm256_slli_si256_rpl(vHM, 2);
        vHS = _mm256_slli_si256_rpl(vHS, 2);
        vHL = _mm256_slli_si256_rpl(vHL, 2);
        vH = _mm256_blendv_epi8(vH, vBias, insert_mask);
        vHM = _mm256_blendv_epi8(vHM, vBias, insert_mask);
        vHS = _mm256_blendv_epi8(vHS, vBias, insert_mask);
        vHL = _mm256_blendv_epi8(vHL, vBias, insert_mask);

        /* Correct part of the vProfile */
        vP = vProfile + matrix->mapper[(unsigned char)s2[j]] * segLen;
        vPM = vProfileM + matrix->mapper[(unsigned char)s2[j]] * segLen;
        vPS = vProfileS + matrix->mapper[(unsigned char)s2[j]] * segLen;

        if (end_ref == j-2) {
            /* Swap in the max buffer. */
            SWAP3(pvHMax,  pvHLoad,  pvHStore)
            SWAP3(pvHMMax, pvHMLoad, pvHMStore)
            SWAP3(pvHSMax, pvHSLoad, pvHSStore)
            SWAP3(pvHLMax, pvHLLoad, pvHLStore)
        }
        else {
            /* Swap the 2 H buffers. */
            SWAP(pvHLoad,  pvHStore)
            SWAP(pvHMLoad, pvHMStore)
            SWAP(pvHSLoad, pvHSStore)
            SWAP(pvHLLoad, pvHLStore)
        }

        /* inner loop to process the query sequence */
        for (i=0; i<segLen; ++i) {
            __m256i cond_zero;
            __m256i case1;
            __m256i case2;

            vE = _mm256_load_si256(pvE+ i);
            vEM = _mm256_load_si256(pvEM+ i);
            vES = _mm256_load_si256(pvES+ i);
            vEL = _mm256_load_si256(pvEL+ i);

            /* Get max from vH, vE and vF. */
            vH_dag = _mm256_adds_epi16(vH, _mm256_load_si256(vP + i));
            /*vH = _mm256_max_epi16(vH_dag, vBias);*/
            vH = _mm256_max_epi16(vH_dag, vE);
            vH = _mm256_max_epi16(vH, vF);
            /* Save vH values. */
            _mm256_store_si256(pvHStore + i, vH);
            cond_zero = _mm256_cmpeq_epi16(vH, vBias);

            case1 = _mm256_cmpeq_epi16(vH, vH_dag);
            case2 = _mm256_cmpeq_epi16(vH, vF);

            /* calculate vM */
            vHM = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vEM, vFM, case2),
                    _mm256_adds_epi16(vHM, _mm256_load_si256(vPM + i)), case1);
            vHM = _mm256_blendv_epi8(vHM, vBias, cond_zero);
            _mm256_store_si256(pvHMStore + i, vHM);

            /* calculate vS */
            vHS = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vES, vFS, case2),
                    _mm256_adds_epi16(vHS, _mm256_load_si256(vPS + i)), case1);
            vHS = _mm256_blendv_epi8(vHS, vBias, cond_zero);
            _mm256_store_si256(pvHSStore + i, vHS);

            /* calculate vL */
            vHL = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vEL, vFL, case2),
                    _mm256_adds_epi16(vHL, vOne), case1);
            vHL = _mm256_blendv_epi8(vHL, vBias, cond_zero);
            _mm256_store_si256(pvHLStore + i, vHL);

            vSaturationCheckMax = _mm256_max_epi16(vSaturationCheckMax, vHM);
            vSaturationCheckMax = _mm256_max_epi16(vSaturationCheckMax, vHS);
            vSaturationCheckMax = _mm256_max_epi16(vSaturationCheckMax, vHL);
#ifdef PARASAIL_TABLE
            arr_store(result->stats->tables->matches_table, vHM, i, segLen, j, s2Len, bias);
            arr_store(result->stats->tables->similar_table, vHS, i, segLen, j, s2Len, bias);
            arr_store(result->stats->tables->length_table, vHL, i, segLen, j, s2Len, bias);
            arr_store(result->stats->tables->score_table, vH, i, segLen, j, s2Len, bias);
#endif
            vMaxH = _mm256_max_epi16(vH, vMaxH);
            vEF_opn = _mm256_subs_epi16(vH, vGapO);

            /* Update vE value. */
            vE_ext = _mm256_subs_epi16(vE, vGapE);
            vE = _mm256_max_epi16(vEF_opn, vE_ext);
            case1 = _mm256_cmpgt_epi16(vEF_opn, vE_ext);
            vEM = _mm256_blendv_epi8(vEM, vHM, case1);
            vES = _mm256_blendv_epi8(vES, vHS, case1);
            vEL = _mm256_blendv_epi8(
                    _mm256_adds_epi16(vEL, vOne),
                    _mm256_adds_epi16(vHL, vOne),
                    case1);
            _mm256_store_si256(pvE + i, vE);
            _mm256_store_si256(pvEM + i, vEM);
            _mm256_store_si256(pvES + i, vES);
            _mm256_store_si256(pvEL + i, vEL);

            /* Update vF value. */
            vF_ext = _mm256_subs_epi16(vF, vGapE);
            vF = _mm256_max_epi16(vEF_opn, vF_ext);
            case1 = _mm256_cmpgt_epi16(vEF_opn, vF_ext);
            vFM = _mm256_blendv_epi8(vFM, vHM, case1);
            vFS = _mm256_blendv_epi8(vFS, vHS, case1);
            vFL = _mm256_blendv_epi8(
                    _mm256_adds_epi16(vFL, vOne),
                    _mm256_adds_epi16(vHL, vOne),
                    case1);

            /* Load the next vH. */
            vH = _mm256_load_si256(pvHLoad + i);
            vHM = _mm256_load_si256(pvHMLoad + i);
            vHS = _mm256_load_si256(pvHSLoad + i);
            vHL = _mm256_load_si256(pvHLLoad + i);
        }

        /* Lazy_F loop: has been revised to disallow adjecent insertion and
         * then deletion, so don't update E(i, i), learn from SWPS3 */
        for (k=0; k<segWidth; ++k) {
            __m256i vHp = _mm256_load_si256(&pvHLoad[segLen - 1]);
            vHp = _mm256_slli_si256_rpl(vHp, 2);
            vF = _mm256_slli_si256_rpl(vF, 2);
            vFM = _mm256_slli_si256_rpl(vFM, 2);
            vFS = _mm256_slli_si256_rpl(vFS, 2);
            vFL = _mm256_slli_si256_rpl(vFL, 2);
            vHp = _mm256_blendv_epi8(vHp, vBias, insert_mask);
            vF = _mm256_blendv_epi8(vF, vBias, insert_mask);
            vFM = _mm256_blendv_epi8(vFM, vBias, insert_mask);
            vFS = _mm256_blendv_epi8(vFS, vBias, insert_mask);
            vFL = _mm256_blendv_epi8(vFL, vBias1, insert_mask);
            for (i=0; i<segLen; ++i) {
                __m256i case1;
                __m256i case2;
                __m256i cond;

                vHp = _mm256_adds_epi16(vHp, _mm256_load_si256(vP + i));
                vH = _mm256_load_si256(pvHStore + i);
                vH = _mm256_max_epi16(vH, vF);
                _mm256_store_si256(pvHStore + i, vH);
                case1 = _mm256_cmpeq_epi16(vH, vHp);
                case2 = _mm256_cmpeq_epi16(vH, vF);
                cond = _mm256_andnot_si256(case1, case2);

                /* calculate vM */
                vHM = _mm256_load_si256(pvHMStore + i);
                vHM = _mm256_blendv_epi8(vHM, vFM, cond);
                _mm256_store_si256(pvHMStore + i, vHM);

                /* calculate vS */
                vHS = _mm256_load_si256(pvHSStore + i);
                vHS = _mm256_blendv_epi8(vHS, vFS, cond);
                _mm256_store_si256(pvHSStore + i, vHS);

                /* calculate vL */
                vHL = _mm256_load_si256(pvHLStore + i);
                vHL = _mm256_blendv_epi8(vHL, vFL, cond);
                _mm256_store_si256(pvHLStore + i, vHL);

                vSaturationCheckMax = _mm256_max_epi16(vSaturationCheckMax, vHM);
                vSaturationCheckMax = _mm256_max_epi16(vSaturationCheckMax, vHS);
                vSaturationCheckMax = _mm256_max_epi16(vSaturationCheckMax, vHL);
#ifdef PARASAIL_TABLE
                arr_store(result->stats->tables->matches_table, vHM, i, segLen, j, s2Len, bias);
                arr_store(result->stats->tables->similar_table, vHS, i, segLen, j, s2Len, bias);
                arr_store(result->stats->tables->length_table, vHL, i, segLen, j, s2Len, bias);
                arr_store(result->stats->tables->score_table, vH, i, segLen, j, s2Len, bias);
#endif
                vMaxH = _mm256_max_epi16(vH, vMaxH);
                /* Update vF value. */
                vEF_opn = _mm256_subs_epi16(vH, vGapO);
                vF_ext = _mm256_subs_epi16(vF, vGapE);
                if (! _mm256_movemask_epi8(
                            _mm256_or_si256(
                                _mm256_cmpgt_epi16(vF_ext, vEF_opn),
                                _mm256_and_si256(
                                    _mm256_cmpeq_epi16(vF_ext, vEF_opn),
                                    _mm256_cmpgt_epi16(vF_ext, vBias)))))
                    goto end;
                /*vF = _mm256_max_epi16(vEF_opn, vF_ext);*/
                vF = vF_ext;
                cond = _mm256_cmpgt_epi16(vEF_opn, vF_ext);
                vFM = _mm256_blendv_epi8(vFM, vHM, cond);
                vFS = _mm256_blendv_epi8(vFS, vHS, cond);
                vFL = _mm256_blendv_epi8(
                        _mm256_adds_epi16(vFL, vOne),
                        _mm256_adds_epi16(vHL, vOne),
                        cond);
                vHp = _mm256_load_si256(pvHLoad + i);
            }
        }
end:
        {
        }

#ifdef PARASAIL_ROWCOL
        /* extract last value from the column */
        {
            vH = _mm256_load_si256(pvHStore + offset);
            vHM = _mm256_load_si256(pvHMStore + offset);
            vHS = _mm256_load_si256(pvHSStore + offset);
            vHL = _mm256_load_si256(pvHLStore + offset);
            for (k=0; k<position; ++k) {
                vH = _mm256_slli_si256_rpl(vH, 2);
                vHM = _mm256_slli_si256_rpl(vHM, 2);
                vHS = _mm256_slli_si256_rpl(vHS, 2);
                vHL = _mm256_slli_si256_rpl(vHL, 2);
            }
            result->stats->rowcols->score_row[j] = (int16_t) _mm256_extract_epi16_rpl (vH, 15) - bias;
            result->stats->rowcols->matches_row[j] = (int16_t) _mm256_extract_epi16_rpl (vHM, 15) - bias;
            result->stats->rowcols->similar_row[j] = (int16_t) _mm256_extract_epi16_rpl (vHS, 15) - bias;
            result->stats->rowcols->length_row[j] = (int16_t) _mm256_extract_epi16_rpl (vHL, 15) - bias;
        }
#endif

        {
            __m256i vCompare = _mm256_cmpgt_epi16(vMaxH, vMaxHUnit);
            if (_mm256_movemask_epi8(vCompare)) {
                score = _mm256_hmax_epi16_rpl(vMaxH);
                /* if score has potential to overflow, abort early */
                if (score > maxp) {
                    result->flag |= PARASAIL_FLAG_SATURATED;
                    break;
                }
                vMaxHUnit = _mm256_set1_epi16(score);
                end_ref = j;
            }
        }
    }

#ifdef PARASAIL_ROWCOL
    for (i=0; i<segLen; ++i) {
        __m256i vH = _mm256_load_si256(pvHStore+i);
        __m256i vHM = _mm256_load_si256(pvHMStore+i);
        __m256i vHS = _mm256_load_si256(pvHSStore+i);
        __m256i vHL = _mm256_load_si256(pvHLStore+i);
        arr_store_col(result->stats->rowcols->score_col, vH, i, segLen, bias);
        arr_store_col(result->stats->rowcols->matches_col, vHM, i, segLen, bias);
        arr_store_col(result->stats->rowcols->similar_col, vHS, i, segLen, bias);
        arr_store_col(result->stats->rowcols->length_col, vHL, i, segLen, bias);
    }
#endif

    if (score == INT16_MAX
            || _mm256_movemask_epi8(_mm256_cmpeq_epi16(vSaturationCheckMax,vPosLimit))) {
        result->flag |= PARASAIL_FLAG_SATURATED;
    }

    if (parasail_result_is_saturated(result)) {
        score = 0;
        end_query = 0;
        end_ref = 0;
        matches = 0;
        similar = 0;
        length = 0;
    }
    else {
        if (end_ref == j-1) {
            /* end_ref was the last store column */
            SWAP(pvHMax,  pvHStore)
            SWAP(pvHMMax, pvHMStore)
            SWAP(pvHSMax, pvHSStore)
            SWAP(pvHLMax, pvHLStore)
        }
        else if (end_ref == j-2) {
            /* end_ref was the last load column */
            SWAP(pvHMax,  pvHLoad)
            SWAP(pvHMMax, pvHMLoad)
            SWAP(pvHSMax, pvHSLoad)
            SWAP(pvHLMax, pvHLLoad)
        }
        /* Trace the alignment ending position on read. */
        {
            int16_t *t = (int16_t*)pvHMax;
            int16_t *m = (int16_t*)pvHMMax;
            int16_t *s = (int16_t*)pvHSMax;
            int16_t *l = (int16_t*)pvHLMax;
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
    }

    result->score = score - bias;
    result->end_query = end_query;
    result->end_ref = end_ref;
    result->stats->matches = matches - bias;
    result->stats->similar = similar - bias;
    result->stats->length = length - bias;

    parasail_free(pvHLMax);
    parasail_free(pvHSMax);
    parasail_free(pvHMMax);
    parasail_free(pvHMax);
    parasail_free(pvEL);
    parasail_free(pvES);
    parasail_free(pvEM);
    parasail_free(pvE);
    parasail_free(pvHLLoad);
    parasail_free(pvHLStore);
    parasail_free(pvHSLoad);
    parasail_free(pvHSStore);
    parasail_free(pvHMLoad);
    parasail_free(pvHMStore);
    parasail_free(pvHLoad);
    parasail_free(pvHStore);

    return result;
}

#ifdef FASTSTATS
#ifdef PARASAIL_TABLE
#else
#ifdef PARASAIL_ROWCOL
#else
#include <assert.h>
parasail_result_t* INAME(
        const parasail_profile_t * const restrict profile,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap)
{
    const char *s1 = profile->s1;
    const parasail_matrix_t *matrix = profile->matrix;

    /* find the end loc first with the faster implementation */
    parasail_result_t *result = parasail_sw_striped_profile_avx2_256_16(profile, s2, s2Len, open, gap);
    if (!parasail_result_is_saturated(result)) {
#if 0
        int s1Len_new = 0;
        int s2Len_new = 0;
        char *s1_new = NULL;
        char *s2_new = NULL;
        parasail_profile_t *profile_new = NULL;
        parasail_result_t *result_new = NULL;
        int s1_begin = 0;
        int s2_begin = 0;
        int s1Len_final = 0;
        int s2Len_final = 0;
        parasail_profile_t *profile_final = NULL;
        parasail_result_t *result_final = NULL;

        /* using the end loc and the non-stats version of the function,
         * reverse the inputs and find the beg loc */
        s1Len_new = result->end_query+1;
        s2Len_new = result->end_ref+1;
        s1_new = parasail_reverse(s1, s1Len_new);
        s2_new = parasail_reverse(s2, s2Len_new);
        profile_new = parasail_profile_create_avx_256_16(
                s1_new, s1Len_new, matrix);
        profile_new->stop = result->score;
        result_new = parasail_sw_striped_profile_avx2_256_16(
                profile_new, s2_new, s2Len_new, open, gap);

        /* using both the beg and end loc, call the original stats func */
        s1_begin = s1Len_new - result_new->end_query - 1;
        s2_begin = s2Len_new - result_new->end_ref - 1;
        s1Len_final = s1Len_new - s1_begin;
        s2Len_final = s2Len_new - s2_begin;
        assert(s1_begin >= 0);
        assert(s2_begin >= 0);
        assert(s1Len_new > s1_begin);
        assert(s2Len_new > s2_begin);
        profile_final = parasail_profile_create_stats_avx_256_16(
                &s1[s1_begin], s1Len_final, matrix);
        result_final = PNAME(
                profile_final, &s2[s2_begin], s2Len_final, open, gap);

        /* clean up all the temporary profiles, sequences, and results */
        free(s1_new);
        free(s2_new);
        parasail_profile_free(profile_new);
        parasail_profile_free(profile_final);
        parasail_result_free(result);
        parasail_result_free(result_new);

        /* correct the end locations before returning */
        result_final->end_query = s1Len_new-1;
        result_final->end_ref = s2Len_new-1;
        return result_final;
#else
        int s1Len_new = 0;
        int s2Len_new = 0;
        parasail_profile_t *profile_final = NULL;
        parasail_result_t *result_final = NULL;

        /* using the end loc, call the original stats function */
        s1Len_new = result->end_query+1;
        s2Len_new = result->end_ref+1;
        profile_final = parasail_profile_create_stats_avx_256_16(
                s1, s1Len_new, matrix);
        result_final = PNAME(
                profile_final, s2, s2Len_new, open, gap);

        /* clean up all the temporary profiles, sequences, and results */
        parasail_profile_free(profile_final);
        parasail_result_free(result);

        /* correct the end locations before returning */
        result_final->end_query = s1Len_new-1;
        result_final->end_ref = s2Len_new-1;
        return result_final;
#endif
    }
    else {
        return result;
    }
}
#endif
#endif
#endif


