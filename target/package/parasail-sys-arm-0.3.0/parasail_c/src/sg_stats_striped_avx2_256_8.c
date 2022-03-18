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

#define SG_STATS
#define SG_SUFFIX _striped_avx2_256_8
#define SG_SUFFIX_PROF _striped_profile_avx2_256_8
#include "sg_helper.h"

#include <immintrin.h>

#include "parasail.h"
#include "parasail/memory.h"
#include "parasail/internal_avx.h"

#define SWAP(A,B) { __m256i* tmp = A; A = B; B = tmp; }


#if HAVE_AVX2_MM256_INSERT_EPI8
#define _mm256_insert_epi8_rpl _mm256_insert_epi8
#else
static inline __m256i _mm256_insert_epi8_rpl(__m256i a, int8_t i, int imm) {
    __m256i_8_t A;
    A.m = a;
    A.v[imm] = i;
    return A.m;
}
#endif

#if HAVE_AVX2_MM256_EXTRACT_EPI8
#define _mm256_extract_epi8_rpl _mm256_extract_epi8
#else
static inline int8_t _mm256_extract_epi8_rpl(__m256i a, int imm) {
    __m256i_8_t A;
    A.m = a;
    return A.v[imm];
}
#endif

#define _mm256_cmplt_epi8_rpl(a,b) _mm256_cmpgt_epi8(b,a)

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
    array[1LL*( 0*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH,  0);
    array[1LL*( 1*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH,  1);
    array[1LL*( 2*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH,  2);
    array[1LL*( 3*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH,  3);
    array[1LL*( 4*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH,  4);
    array[1LL*( 5*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH,  5);
    array[1LL*( 6*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH,  6);
    array[1LL*( 7*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH,  7);
    array[1LL*( 8*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH,  8);
    array[1LL*( 9*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH,  9);
    array[1LL*(10*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 10);
    array[1LL*(11*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 11);
    array[1LL*(12*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 12);
    array[1LL*(13*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 13);
    array[1LL*(14*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 14);
    array[1LL*(15*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 15);
    array[1LL*(16*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 16);
    array[1LL*(17*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 17);
    array[1LL*(18*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 18);
    array[1LL*(19*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 19);
    array[1LL*(20*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 20);
    array[1LL*(21*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 21);
    array[1LL*(22*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 22);
    array[1LL*(23*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 23);
    array[1LL*(24*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 24);
    array[1LL*(25*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 25);
    array[1LL*(26*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 26);
    array[1LL*(27*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 27);
    array[1LL*(28*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 28);
    array[1LL*(29*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 29);
    array[1LL*(30*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 30);
    array[1LL*(31*seglen+t)*dlen + d] = (int8_t)_mm256_extract_epi8_rpl(vH, 31);
}
#endif

#ifdef PARASAIL_ROWCOL
static inline void arr_store_col(
        int *col,
        __m256i vH,
        int32_t t,
        int32_t seglen)
{
    col[ 0*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH,  0);
    col[ 1*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH,  1);
    col[ 2*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH,  2);
    col[ 3*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH,  3);
    col[ 4*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH,  4);
    col[ 5*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH,  5);
    col[ 6*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH,  6);
    col[ 7*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH,  7);
    col[ 8*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH,  8);
    col[ 9*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH,  9);
    col[10*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 10);
    col[11*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 11);
    col[12*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 12);
    col[13*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 13);
    col[14*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 14);
    col[15*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 15);
    col[16*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 16);
    col[17*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 17);
    col[18*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 18);
    col[19*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 19);
    col[20*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 20);
    col[21*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 21);
    col[22*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 22);
    col[23*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 23);
    col[24*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 24);
    col[25*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 25);
    col[26*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 26);
    col[27*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 27);
    col[28*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 28);
    col[29*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 29);
    col[30*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 30);
    col[31*seglen+t] = (int8_t)_mm256_extract_epi8_rpl(vH, 31);
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_sg_flags_stats_table_striped_avx2_256_8
#define PNAME parasail_sg_flags_stats_table_striped_profile_avx2_256_8
#else
#ifdef PARASAIL_ROWCOL
#define FNAME parasail_sg_flags_stats_rowcol_striped_avx2_256_8
#define PNAME parasail_sg_flags_stats_rowcol_striped_profile_avx2_256_8
#else
#define FNAME parasail_sg_flags_stats_striped_avx2_256_8
#define PNAME parasail_sg_flags_stats_striped_profile_avx2_256_8
#endif
#endif

parasail_result_t* FNAME(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap, const parasail_matrix_t *matrix,
        int s1_beg, int s1_end, int s2_beg, int s2_end)
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
    profile = parasail_profile_create_stats_avx_256_8(s1, s1Len, matrix);
    if (!profile) return NULL;
    result = PNAME(profile, s2, s2Len, open, gap, s1_beg, s1_end, s2_beg, s2_end);

    parasail_profile_free(profile);

    return result;
}

parasail_result_t* PNAME(
        const parasail_profile_t * const restrict profile,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        int s1_beg, int s1_end, int s2_beg, int s2_end)
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
    int8_t* restrict boundary = NULL;
    __m256i vGapO;
    __m256i vGapE;
    int8_t NEG_LIMIT = 0;
    int8_t POS_LIMIT = 0;
    __m256i vZero;
    __m256i vOne;
    int8_t score = 0;
    int8_t matches = 0;
    int8_t similar = 0;
    int8_t length = 0;
    __m256i vNegLimit;
    __m256i vPosLimit;
    __m256i vSaturationCheckMin;
    __m256i vSaturationCheckMax;
    __m256i vMaxH;
    __m256i vMaxHM;
    __m256i vMaxHS;
    __m256i vMaxHL;
    __m256i vPosMask;
    parasail_result_t *result = NULL;

    /* validate inputs */
    PARASAIL_CHECK_NULL(profile);
    PARASAIL_CHECK_NULL(profile->profile8.score);
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
    segWidth = 32; /* number of values in vector unit */
    segLen = (s1Len + segWidth - 1) / segWidth;
    offset = (s1Len - 1) % segLen;
    position = (segWidth - 1) - (s1Len - 1) / segLen;
    vProfile  = (__m256i*)profile->profile8.score;
    vProfileM = (__m256i*)profile->profile8.matches;
    vProfileS = (__m256i*)profile->profile8.similar;
    vGapO = _mm256_set1_epi8(open);
    vGapE = _mm256_set1_epi8(gap);
    NEG_LIMIT = (-open < matrix->min ? INT8_MIN + open : INT8_MIN - matrix->min) + 1;
    POS_LIMIT = INT8_MAX - matrix->max - 1;
    vZero = _mm256_setzero_si256();
    vOne = _mm256_set1_epi8(1);
    score = NEG_LIMIT;
    matches = 0;
    similar = 0;
    length = 0;
    vNegLimit = _mm256_set1_epi8(NEG_LIMIT);
    vPosLimit = _mm256_set1_epi8(POS_LIMIT);
    vSaturationCheckMin = vPosLimit;
    vSaturationCheckMax = vNegLimit;
    vMaxH = vNegLimit;
    vMaxHM = vNegLimit;
    vMaxHS = vNegLimit;
    vMaxHL = vNegLimit;
    vPosMask = _mm256_cmpeq_epi8(_mm256_set1_epi8(position),
            _mm256_set_epi8(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31));

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
    result->flag |= PARASAIL_FLAG_SG | PARASAIL_FLAG_STRIPED
        | PARASAIL_FLAG_STATS
        | PARASAIL_FLAG_BITS_8 | PARASAIL_FLAG_LANES_32;
    result->flag |= s1_beg ? PARASAIL_FLAG_SG_S1_BEG : 0;
    result->flag |= s1_end ? PARASAIL_FLAG_SG_S1_END : 0;
    result->flag |= s2_beg ? PARASAIL_FLAG_SG_S2_BEG : 0;
    result->flag |= s2_end ? PARASAIL_FLAG_SG_S2_END : 0;
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
    boundary  = parasail_memalign_int8_t(32, s2Len+1);

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
    if (!boundary) return NULL;

    parasail_memset___m256i(pvHMStore, vZero, segLen);
    parasail_memset___m256i(pvHSStore, vZero, segLen);
    parasail_memset___m256i(pvHLStore, vZero, segLen);
    parasail_memset___m256i(pvEM, vZero, segLen);
    parasail_memset___m256i(pvES, vZero, segLen);
    parasail_memset___m256i(pvEL, vOne, segLen);

    /* initialize H and E */
    {
        int32_t index = 0;
        for (i=0; i<segLen; ++i) {
            int32_t segNum = 0;
            __m256i_8_t h;
            __m256i_8_t e;
            for (segNum=0; segNum<segWidth; ++segNum) {
                int64_t tmp = s1_beg ? 0 : (-open-gap*(segNum*segLen+i));
                h.v[segNum] = tmp < INT8_MIN ? INT8_MIN : tmp;
                tmp = tmp - open;
                e.v[segNum] = tmp < INT8_MIN ? INT8_MIN : tmp;
            }
            _mm256_store_si256(&pvHStore[index], h.m);
            _mm256_store_si256(&pvE[index], e.m);
            ++index;
        }
    }

    /* initialize uppder boundary */
    {
        boundary[0] = 0;
        for (i=1; i<=s2Len; ++i) {
            int64_t tmp = s2_beg ? 0 : (-open-gap*(i-1));
            boundary[i] = tmp < INT8_MIN ? INT8_MIN : tmp;
        }
    }

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

        /* Initialize F value to neg inf.  Any errors to vH values will
         * be corrected in the Lazy_F loop. */
        vF = vNegLimit;
        vFM = vZero;
        vFS = vZero;
        vFL = vOne;

        /* load final segment of pvHStore and shift left by 1 bytes */
        vH = _mm256_load_si256(&pvHStore[segLen - 1]);
        vHM = _mm256_load_si256(&pvHMStore[segLen - 1]);
        vHS = _mm256_load_si256(&pvHSStore[segLen - 1]);
        vHL = _mm256_load_si256(&pvHLStore[segLen - 1]);
        vH = _mm256_slli_si256_rpl(vH, 1);
        vHM = _mm256_slli_si256_rpl(vHM, 1);
        vHS = _mm256_slli_si256_rpl(vHS, 1);
        vHL = _mm256_slli_si256_rpl(vHL, 1);

        /* insert upper boundary condition */
        vH = _mm256_insert_epi8_rpl(vH, boundary[j], 0);

        /* Correct part of the vProfile */
        vP = vProfile + matrix->mapper[(unsigned char)s2[j]] * segLen;
        vPM = vProfileM + matrix->mapper[(unsigned char)s2[j]] * segLen;
        vPS = vProfileS + matrix->mapper[(unsigned char)s2[j]] * segLen;

        /* Swap the 2 H buffers. */
        SWAP(pvHLoad,  pvHStore)
        SWAP(pvHMLoad, pvHMStore)
        SWAP(pvHSLoad, pvHSStore)
        SWAP(pvHLLoad, pvHLStore)

        /* inner loop to process the query sequence */
        for (i=0; i<segLen; ++i) {
            __m256i case1;
            __m256i case2;

            vE = _mm256_load_si256(pvE+ i);
            vEM = _mm256_load_si256(pvEM+ i);
            vES = _mm256_load_si256(pvES+ i);
            vEL = _mm256_load_si256(pvEL+ i);

            /* Get max from vH, vE and vF. */
            vH_dag = _mm256_adds_epi8(vH, _mm256_load_si256(vP + i));
            vH = _mm256_max_epi8(vH_dag, vE);
            vH = _mm256_max_epi8(vH, vF);
            /* Save vH values. */
            _mm256_store_si256(pvHStore + i, vH);

            case1 = _mm256_cmpeq_epi8(vH, vH_dag);
            case2 = _mm256_cmpeq_epi8(vH, vF);

            /* calculate vM */
            vHM = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vEM, vFM, case2),
                    _mm256_adds_epi8(vHM, _mm256_load_si256(vPM + i)),
                    case1);
            _mm256_store_si256(pvHMStore + i, vHM);

            /* calculate vS */
            vHS = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vES, vFS, case2),
                    _mm256_adds_epi8(vHS, _mm256_load_si256(vPS + i)),
                    case1);
            _mm256_store_si256(pvHSStore + i, vHS);

            /* calculate vL */
            vHL = _mm256_blendv_epi8(
                    _mm256_blendv_epi8(vEL, vFL, case2),
                    _mm256_adds_epi8(vHL, vOne),
                    case1);
            _mm256_store_si256(pvHLStore + i, vHL);

            vSaturationCheckMin = _mm256_min_epi8(vSaturationCheckMin, vH);
            vSaturationCheckMax = _mm256_max_epi8(vSaturationCheckMax, vH);
            vSaturationCheckMax = _mm256_max_epi8(vSaturationCheckMax, vHM);
            vSaturationCheckMax = _mm256_max_epi8(vSaturationCheckMax, vHS);
            vSaturationCheckMax = _mm256_max_epi8(vSaturationCheckMax, vHL);
#ifdef PARASAIL_TABLE
            arr_store_si256(result->stats->tables->matches_table, vHM, i, segLen, j, s2Len);
            arr_store_si256(result->stats->tables->similar_table, vHS, i, segLen, j, s2Len);
            arr_store_si256(result->stats->tables->length_table, vHL, i, segLen, j, s2Len);
            arr_store_si256(result->stats->tables->score_table, vH, i, segLen, j, s2Len);
#endif
            vEF_opn = _mm256_subs_epi8(vH, vGapO);

            /* Update vE value. */
            vE_ext = _mm256_subs_epi8(vE, vGapE);
            vE = _mm256_max_epi8(vEF_opn, vE_ext);
            case1 = _mm256_cmpgt_epi8(vEF_opn, vE_ext);
            vEM = _mm256_blendv_epi8(vEM, vHM, case1);
            vES = _mm256_blendv_epi8(vES, vHS, case1);
            vEL = _mm256_blendv_epi8(
                    _mm256_adds_epi8(vEL, vOne),
                    _mm256_adds_epi8(vHL, vOne),
                    case1);
            _mm256_store_si256(pvE + i, vE);
            _mm256_store_si256(pvEM + i, vEM);
            _mm256_store_si256(pvES + i, vES);
            _mm256_store_si256(pvEL + i, vEL);

            /* Update vF value. */
            vF_ext = _mm256_subs_epi8(vF, vGapE);
            vF = _mm256_max_epi8(vEF_opn, vF_ext);
            case1 = _mm256_cmpgt_epi8(vEF_opn, vF_ext);
            vFM = _mm256_blendv_epi8(vFM, vHM, case1);
            vFS = _mm256_blendv_epi8(vFS, vHS, case1);
            vFL = _mm256_blendv_epi8(
                    _mm256_adds_epi8(vFL, vOne),
                    _mm256_adds_epi8(vHL, vOne),
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
            int64_t tmp = s2_beg ? -open : (boundary[j+1]-open);
            int8_t tmp2 = tmp < INT8_MIN ? INT8_MIN : tmp;
            vHp = _mm256_slli_si256_rpl(vHp, 1);
            vF = _mm256_slli_si256_rpl(vF, 1);
            vFM = _mm256_slli_si256_rpl(vFM, 1);
            vFS = _mm256_slli_si256_rpl(vFS, 1);
            vFL = _mm256_slli_si256_rpl(vFL, 1);
            vHp = _mm256_insert_epi8_rpl(vHp, boundary[j], 0);
            vF = _mm256_insert_epi8_rpl(vF, tmp2, 0);
            vFL = _mm256_insert_epi8_rpl(vFL, 1, 0);
            for (i=0; i<segLen; ++i) {
                __m256i case1;
                __m256i case2;
                __m256i cond;

                vHp = _mm256_adds_epi8(vHp, _mm256_load_si256(vP + i));
                vH = _mm256_load_si256(pvHStore + i);
                vH = _mm256_max_epi8(vH,vF);
                _mm256_store_si256(pvHStore + i, vH);
                case1 = _mm256_cmpeq_epi8(vH, vHp);
                case2 = _mm256_cmpeq_epi8(vH, vF);
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

                vSaturationCheckMin = _mm256_min_epi8(vSaturationCheckMin, vH);
                vSaturationCheckMax = _mm256_max_epi8(vSaturationCheckMax, vH);
                vSaturationCheckMax = _mm256_max_epi8(vSaturationCheckMax, vHM);
                vSaturationCheckMax = _mm256_max_epi8(vSaturationCheckMax, vHS);
                vSaturationCheckMax = _mm256_max_epi8(vSaturationCheckMax, vHL);
#ifdef PARASAIL_TABLE
                arr_store_si256(result->stats->tables->matches_table, vHM, i, segLen, j, s2Len);
                arr_store_si256(result->stats->tables->similar_table, vHS, i, segLen, j, s2Len);
                arr_store_si256(result->stats->tables->length_table, vHL, i, segLen, j, s2Len);
                arr_store_si256(result->stats->tables->score_table, vH, i, segLen, j, s2Len);
#endif
                /* Update vF value. */
                vEF_opn = _mm256_subs_epi8(vH, vGapO);
                vF_ext = _mm256_subs_epi8(vF, vGapE);
                if (! _mm256_movemask_epi8(
                            _mm256_or_si256(
                                _mm256_cmpgt_epi8(vF_ext, vEF_opn),
                                _mm256_cmpeq_epi8(vF_ext, vEF_opn))))
                    goto end;
                /*vF = _mm256_max_epi8(vEF_opn, vF_ext);*/
                vF = vF_ext;
                cond = _mm256_cmpgt_epi8(vEF_opn, vF_ext);
                vFM = _mm256_blendv_epi8(vFM, vHM, cond);
                vFS = _mm256_blendv_epi8(vFS, vHS, cond);
                vFL = _mm256_blendv_epi8(
                        _mm256_adds_epi8(vFL, vOne),
                        _mm256_adds_epi8(vHL, vOne),
                        cond);
                vHp = _mm256_load_si256(pvHLoad + i);
            }
        }
end:
        {
        }

        /* extract vector containing last value from the column */
        {
            __m256i cond_max;
            vH = _mm256_load_si256(pvHStore + offset);
            vHM = _mm256_load_si256(pvHMStore + offset);
            vHS = _mm256_load_si256(pvHSStore + offset);
            vHL = _mm256_load_si256(pvHLStore + offset);
            cond_max = _mm256_cmpgt_epi8(vH, vMaxH);
            vMaxH = _mm256_blendv_epi8(vMaxH, vH, cond_max);
            vMaxHM = _mm256_blendv_epi8(vMaxHM, vHM, cond_max);
            vMaxHS = _mm256_blendv_epi8(vMaxHS, vHS, cond_max);
            vMaxHL = _mm256_blendv_epi8(vMaxHL, vHL, cond_max);
            if (_mm256_movemask_epi8(_mm256_and_si256(vPosMask, cond_max))) {
                end_ref = j;
            }
        }
#ifdef PARASAIL_ROWCOL
        for (k=0; k<position; ++k) {
            vH = _mm256_slli_si256_rpl(vH, 1);
            vHM = _mm256_slli_si256_rpl(vHM, 1);
            vHS = _mm256_slli_si256_rpl(vHS, 1);
            vHL = _mm256_slli_si256_rpl(vHL, 1);
        }
        result->stats->rowcols->score_row[j] = (int8_t) _mm256_extract_epi8_rpl (vH, 31);
        result->stats->rowcols->matches_row[j] = (int8_t) _mm256_extract_epi8_rpl (vHM, 31);
        result->stats->rowcols->similar_row[j] = (int8_t) _mm256_extract_epi8_rpl (vHS, 31);
        result->stats->rowcols->length_row[j] = (int8_t) _mm256_extract_epi8_rpl (vHL, 31);
#endif
    }

#ifdef PARASAIL_ROWCOL
    for (i=0; i<segLen; ++i) {
        __m256i vH = _mm256_load_si256(pvHStore+i);
        __m256i vHM = _mm256_load_si256(pvHMStore+i);
        __m256i vHS = _mm256_load_si256(pvHSStore+i);
        __m256i vHL = _mm256_load_si256(pvHLStore+i);
        arr_store_col(result->stats->rowcols->score_col, vH, i, segLen);
        arr_store_col(result->stats->rowcols->matches_col, vHM, i, segLen);
        arr_store_col(result->stats->rowcols->similar_col, vHS, i, segLen);
        arr_store_col(result->stats->rowcols->length_col, vHL, i, segLen);
    }
#endif

    /* extract last value from the column maximums */
    if (s2_end)
    {
        for (k=0; k<position; ++k) {
            vMaxH = _mm256_slli_si256_rpl(vMaxH, 1);
            vMaxHM = _mm256_slli_si256_rpl(vMaxHM, 1);
            vMaxHS = _mm256_slli_si256_rpl(vMaxHS, 1);
            vMaxHL = _mm256_slli_si256_rpl(vMaxHL, 1);
        }
        end_query = s1Len-1;
        score = (int8_t) _mm256_extract_epi8_rpl(vMaxH, 31);
        matches = (int8_t) _mm256_extract_epi8_rpl(vMaxHM, 31);
        similar = (int8_t) _mm256_extract_epi8_rpl(vMaxHS, 31);
        length = (int8_t) _mm256_extract_epi8_rpl(vMaxHL, 31);
    }

    /* max of last column */
    if (s1_end)
    {
        /* Trace the alignment ending position on read. */
        int8_t *t = (int8_t*)pvHStore;
        int8_t *m = (int8_t*)pvHMStore;
        int8_t *s = (int8_t*)pvHSStore;
        int8_t *l = (int8_t*)pvHLStore;
        int32_t column_len = segLen * segWidth;
        for (i = 0; i<column_len; ++i, ++t, ++m, ++s, ++l) {
            int32_t temp = i / segWidth + i % segWidth * segLen;
            if (temp >= s1Len) continue;
            if (*t > score) {
                score = *t;
                end_query = temp;
                end_ref = s2Len-1;
                matches = *m;
                similar = *s;
                length = *l;
            }
            else if (*t == score && end_ref == s2Len-1 && temp < end_query) {
                end_query = temp;
                matches = *m;
                similar = *s;
                length = *l;
            }
        }
    }

    /* extract last value from the last column */
    if (!s1_end && !s2_end)
    {
        __m256i vH = _mm256_load_si256(pvHStore + offset);
        __m256i vHM = _mm256_load_si256(pvHMStore + offset);
        __m256i vHS = _mm256_load_si256(pvHSStore + offset);
        __m256i vHL = _mm256_load_si256(pvHLStore + offset);
        for (k=0; k<position; ++k) {
            vH = _mm256_slli_si256_rpl(vH, 1);
            vHM = _mm256_slli_si256_rpl(vHM, 1);
            vHS = _mm256_slli_si256_rpl(vHS, 1);
            vHL = _mm256_slli_si256_rpl(vHL, 1);
        }
        end_ref = s2Len - 1;
        end_query = s1Len - 1;
        score = (int8_t) _mm256_extract_epi8_rpl (vH, 31);
        matches = (int8_t) _mm256_extract_epi8_rpl (vHM, 31);
        similar = (int8_t) _mm256_extract_epi8_rpl (vHS, 31);
        length = (int8_t) _mm256_extract_epi8_rpl (vHL, 31);
    }

    if (_mm256_movemask_epi8(_mm256_or_si256(
            _mm256_cmplt_epi8_rpl(vSaturationCheckMin, vNegLimit),
            _mm256_cmpgt_epi8(vSaturationCheckMax, vPosLimit)))) {
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

SG_IMPL_ALL
SG_IMPL_PROF_ALL


