/**
 * @file
 *
 * @author jeffrey.daily@gmail.com
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 */
#include "config.h"

#include <stdlib.h>

#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <emmintrin.h>
#endif

#include "parasail.h"
#include "parasail/memory.h"
#include "parasail/internal_sse.h"


static inline __m128i _mm_cmpeq_epi64_rpl(__m128i a, __m128i b) {
    __m128i_64_t A;
    __m128i_64_t B;
    A.m = a;
    B.m = b;
    A.v[0] = (A.v[0]==B.v[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.v[1] = (A.v[1]==B.v[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.m;
}

static inline __m128i _mm_blendv_epi8_rpl(__m128i a, __m128i b, __m128i mask) {
    a = _mm_andnot_si128(mask, a);
    a = _mm_or_si128(a, _mm_and_si128(mask, b));
    return a;
}

static inline __m128i _mm_cmpgt_epi64_rpl(__m128i a, __m128i b) {
    __m128i_64_t A;
    __m128i_64_t B;
    A.m = a;
    B.m = b;
    A.v[0] = (A.v[0]>B.v[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.v[1] = (A.v[1]>B.v[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.m;
}

static inline __m128i _mm_insert_epi64_rpl(__m128i a, int64_t i, const int imm) {
    __m128i_64_t A;
    A.m = a;
    A.v[imm] = i;
    return A.m;
}

static inline __m128i _mm_max_epi64_rpl(__m128i a, __m128i b) {
    __m128i_64_t A;
    __m128i_64_t B;
    A.m = a;
    B.m = b;
    A.v[0] = (A.v[0]>B.v[0]) ? A.v[0] : B.v[0];
    A.v[1] = (A.v[1]>B.v[1]) ? A.v[1] : B.v[1];
    return A.m;
}

#if HAVE_SSE2_MM_SET_EPI64X
#define _mm_set_epi64x_rpl _mm_set_epi64x
#else
static inline __m128i _mm_set_epi64x_rpl(int64_t e1, int64_t e0) {
    __m128i_64_t A;
    A.v[0] = e0;
    A.v[1] = e1;
    return A.m;
}
#endif

static inline int64_t _mm_extract_epi64_rpl(__m128i a, const int imm) {
    __m128i_64_t A;
    A.m = a;
    return A.v[imm];
}

static inline __m128i _mm_min_epi64_rpl(__m128i a, __m128i b) {
    __m128i_64_t A;
    __m128i_64_t B;
    A.m = a;
    B.m = b;
    A.v[0] = (A.v[0]<B.v[0]) ? A.v[0] : B.v[0];
    A.v[1] = (A.v[1]<B.v[1]) ? A.v[1] : B.v[1];
    return A.m;
}

static inline __m128i _mm_cmplt_epi64_rpl(__m128i a, __m128i b) {
    __m128i_64_t A;
    __m128i_64_t B;
    A.m = a;
    B.m = b;
    A.v[0] = (A.v[0]<B.v[0]) ? 0xFFFFFFFFFFFFFFFF : 0;
    A.v[1] = (A.v[1]<B.v[1]) ? 0xFFFFFFFFFFFFFFFF : 0;
    return A.m;
}

#if HAVE_SSE2_MM_SET1_EPI64X
#define _mm_set1_epi64x_rpl _mm_set1_epi64x
#else
static inline __m128i _mm_set1_epi64x_rpl(int64_t i) {
    __m128i_64_t A;
    A.v[0] = i;
    A.v[1] = i;
    return A.m;
}
#endif


#ifdef PARASAIL_TABLE
static inline void arr_store_si128(
        int *array,
        __m128i vWH,
        int32_t i,
        int32_t s1Len,
        int32_t j,
        int32_t s2Len)
{
    if (0 <= i+0 && i+0 < s1Len && 0 <= j-0 && j-0 < s2Len) {
        array[1LL*(i+0)*s2Len + (j-0)] = (int64_t)_mm_extract_epi64_rpl(vWH, 1);
    }
    if (0 <= i+1 && i+1 < s1Len && 0 <= j-1 && j-1 < s2Len) {
        array[1LL*(i+1)*s2Len + (j-1)] = (int64_t)_mm_extract_epi64_rpl(vWH, 0);
    }
}
#endif

#ifdef PARASAIL_ROWCOL
static inline void arr_store_rowcol(
        int *row,
        int *col,
        __m128i vWH,
        int32_t i,
        int32_t s1Len,
        int32_t j,
        int32_t s2Len)
{
    if (i+0 == s1Len-1 && 0 <= j-0 && j-0 < s2Len) {
        row[j-0] = (int64_t)_mm_extract_epi64_rpl(vWH, 1);
    }
    if (j-0 == s2Len-1 && 0 <= i+0 && i+0 < s1Len) {
        col[(i+0)] = (int64_t)_mm_extract_epi64_rpl(vWH, 1);
    }
    if (i+1 == s1Len-1 && 0 <= j-1 && j-1 < s2Len) {
        row[j-1] = (int64_t)_mm_extract_epi64_rpl(vWH, 0);
    }
    if (j-1 == s2Len-1 && 0 <= i+1 && i+1 < s1Len) {
        col[(i+1)] = (int64_t)_mm_extract_epi64_rpl(vWH, 0);
    }
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_nw_stats_table_diag_sse2_128_64
#else
#ifdef PARASAIL_ROWCOL
#define FNAME parasail_nw_stats_rowcol_diag_sse2_128_64
#else
#define FNAME parasail_nw_stats_diag_sse2_128_64
#endif
#endif

parasail_result_t* FNAME(
        const char * const restrict _s1, const int _s1Len,
        const char * const restrict _s2, const int s2Len,
        const int open, const int gap, const parasail_matrix_t *matrix)
{
    /* declare local variables */
    int32_t N = 0;
    int32_t PAD = 0;
    int32_t PAD2 = 0;
    int32_t s1Len = 0;
    int32_t s1Len_PAD = 0;
    int32_t s2Len_PAD = 0;
    int64_t * restrict s1 = NULL;
    int64_t * restrict s2B = NULL;
    int64_t * restrict _H_pr = NULL;
    int64_t * restrict _HM_pr = NULL;
    int64_t * restrict _HS_pr = NULL;
    int64_t * restrict _HL_pr = NULL;
    int64_t * restrict _F_pr = NULL;
    int64_t * restrict _FM_pr = NULL;
    int64_t * restrict _FS_pr = NULL;
    int64_t * restrict _FL_pr = NULL;
    int64_t * restrict s2 = NULL;
    int64_t * restrict H_pr = NULL;
    int64_t * restrict HM_pr = NULL;
    int64_t * restrict HS_pr = NULL;
    int64_t * restrict HL_pr = NULL;
    int64_t * restrict F_pr = NULL;
    int64_t * restrict FM_pr = NULL;
    int64_t * restrict FS_pr = NULL;
    int64_t * restrict FL_pr = NULL;
    parasail_result_t *result = NULL;
    int32_t i = 0;
    int32_t j = 0;
    int32_t end_query = 0;
    int32_t end_ref = 0;
    int64_t NEG_LIMIT = 0;
    int64_t POS_LIMIT = 0;
    int64_t score = 0;
    int64_t matches = 0;
    int64_t similar = 0;
    int64_t length = 0;
    __m128i vNegLimit;
    __m128i vPosLimit;
    __m128i vSaturationCheckMin;
    __m128i vSaturationCheckMax;
    __m128i vNegInf;
    __m128i vOpen;
    __m128i vGap;
    __m128i vZero;
    __m128i vNegInf0;
    __m128i vOne;
    __m128i vN;
    __m128i vGapN;
    __m128i vNegOne;
    __m128i vI;
    __m128i vJreset;
    __m128i vMaxH;
    __m128i vMaxM;
    __m128i vMaxS;
    __m128i vMaxL;
    __m128i vILimit;
    __m128i vILimit1;
    __m128i vJLimit;
    __m128i vJLimit1;
    __m128i vIBoundary;

    /* validate inputs */
    PARASAIL_CHECK_NULL(_s2);
    PARASAIL_CHECK_GT0(s2Len);
    PARASAIL_CHECK_GE0(open);
    PARASAIL_CHECK_GE0(gap);
    PARASAIL_CHECK_NULL(matrix);
    if (matrix->type == PARASAIL_MATRIX_TYPE_PSSM) {
        PARASAIL_CHECK_NULL_PSSM_STATS(_s1);
    }
    else {
        PARASAIL_CHECK_NULL(_s1);
        PARASAIL_CHECK_GT0(_s1Len);
    }

    /* initialize stack variables */
    N = 2; /* number of values in vector */
    PAD = N-1;
    PAD2 = PAD*2;
    s1Len = matrix->type == PARASAIL_MATRIX_TYPE_SQUARE ? _s1Len : matrix->length;
    s1Len_PAD = s1Len+PAD;
    s2Len_PAD = s2Len+PAD;
    i = 0;
    j = 0;
    end_query = s1Len-1;
    end_ref = s2Len-1;
    NEG_LIMIT = (-open < matrix->min ? INT64_MIN + open : INT64_MIN - matrix->min) + 1;
    POS_LIMIT = INT64_MAX - matrix->max - 1;
    score = NEG_LIMIT;
    matches = NEG_LIMIT;
    similar = NEG_LIMIT;
    length = NEG_LIMIT;
    vNegLimit = _mm_set1_epi64x_rpl(NEG_LIMIT);
    vPosLimit = _mm_set1_epi64x_rpl(POS_LIMIT);
    vSaturationCheckMin = vPosLimit;
    vSaturationCheckMax = vNegLimit;
    vNegInf = _mm_set1_epi64x_rpl(NEG_LIMIT);
    vOpen = _mm_set1_epi64x_rpl(open);
    vGap  = _mm_set1_epi64x_rpl(gap);
    vZero = _mm_set1_epi64x_rpl(0);
    vNegInf0 = _mm_insert_epi64_rpl(vZero, NEG_LIMIT, 1);
    vOne = _mm_set1_epi64x_rpl(1);
    vN = _mm_set1_epi64x_rpl(N);
    vGapN = _mm_set1_epi64x_rpl(gap*N);
    vNegOne = _mm_set1_epi64x_rpl(-1);
    vI = _mm_set_epi64x_rpl(0,1);
    vJreset = _mm_set_epi64x_rpl(0,-1);
    vMaxH = vNegInf;
    vMaxM = vNegInf;
    vMaxS = vNegInf;
    vMaxL = vNegInf;
    vILimit = _mm_set1_epi64x_rpl(s1Len);
    vILimit1 = _mm_sub_epi64(vILimit, vOne);
    vJLimit = _mm_set1_epi64x_rpl(s2Len);
    vJLimit1 = _mm_sub_epi64(vJLimit, vOne);
    vIBoundary = _mm_set_epi64x_rpl(
            -open-0*gap,
            -open-1*gap);

    /* initialize result */
#ifdef PARASAIL_TABLE
    result = parasail_result_new_table3(s1Len, s2Len);
#else
#ifdef PARASAIL_ROWCOL
    result = parasail_result_new_rowcol3(s1Len, s2Len);
#else
    result = parasail_result_new_stats();
#endif
#endif
    if (!result) return NULL;

    /* set known flags */
    result->flag |= PARASAIL_FLAG_NW | PARASAIL_FLAG_DIAG
        | PARASAIL_FLAG_STATS
        | PARASAIL_FLAG_BITS_64 | PARASAIL_FLAG_LANES_2;
#ifdef PARASAIL_TABLE
    result->flag |= PARASAIL_FLAG_TABLE;
#endif
#ifdef PARASAIL_ROWCOL
    result->flag |= PARASAIL_FLAG_ROWCOL;
#endif

    /* initialize heap variables */
    s1     = parasail_memalign_int64_t(16, s1Len+PAD);
    s2B    = parasail_memalign_int64_t(16, s2Len+PAD2);
    _H_pr  = parasail_memalign_int64_t(16, s2Len+PAD2);
    _HM_pr = parasail_memalign_int64_t(16, s2Len+PAD2);
    _HS_pr = parasail_memalign_int64_t(16, s2Len+PAD2);
    _HL_pr = parasail_memalign_int64_t(16, s2Len+PAD2);
    _F_pr  = parasail_memalign_int64_t(16, s2Len+PAD2);
    _FM_pr = parasail_memalign_int64_t(16, s2Len+PAD2);
    _FS_pr = parasail_memalign_int64_t(16, s2Len+PAD2);
    _FL_pr = parasail_memalign_int64_t(16, s2Len+PAD2);
    s2 = s2B+PAD; /* will allow later for negative indices */
    H_pr = _H_pr+PAD;
    HM_pr = _HM_pr+PAD;
    HS_pr = _HS_pr+PAD;
    HL_pr = _HL_pr+PAD;
    F_pr = _F_pr+PAD;
    FM_pr = _FM_pr+PAD;
    FS_pr = _FS_pr+PAD;
    FL_pr = _FL_pr+PAD;

    /* validate heap variables */
    if (!s1) return NULL;
    if (!s2B) return NULL;
    if (!_H_pr) return NULL;
    if (!_HM_pr) return NULL;
    if (!_HS_pr) return NULL;
    if (!_HL_pr) return NULL;
    if (!_F_pr) return NULL;
    if (!_FM_pr) return NULL;
    if (!_FS_pr) return NULL;
    if (!_FL_pr) return NULL;

    /* convert _s1 from char to int in range 0-23 */
    for (i=0; i<s1Len; ++i) {
        s1[i] = matrix->mapper[(unsigned char)_s1[i]];
    }
    /* pad back of s1 with dummy values */
    for (i=s1Len; i<s1Len_PAD; ++i) {
        s1[i] = 0; /* point to first matrix row because we don't care */
    }

    /* convert _s2 from char to int in range 0-23 */
    for (j=0; j<s2Len; ++j) {
        s2[j] = matrix->mapper[(unsigned char)_s2[j]];
    }
    /* pad front of s2 with dummy values */
    for (j=-PAD; j<0; ++j) {
        s2[j] = 0; /* point to first matrix row because we don't care */
    }
    /* pad back of s2 with dummy values */
    for (j=s2Len; j<s2Len_PAD; ++j) {
        s2[j] = 0; /* point to first matrix row because we don't care */
    }

    /* set initial values for stored row */
    for (j=0; j<s2Len; ++j) {
        H_pr[j] = -open - j*gap;
        HM_pr[j] = 0;
        HS_pr[j] = 0;
        HL_pr[j] = 0;
        F_pr[j] = NEG_LIMIT;
        FM_pr[j] = 0;
        FS_pr[j] = 0;
        FL_pr[j] = 0;
    }
    /* pad front of stored row values */
    for (j=-PAD; j<0; ++j) {
        H_pr[j] = 0;
        HM_pr[j] = 0;
        HS_pr[j] = 0;
        HL_pr[j] = 0;
        F_pr[j] = 0;
        FM_pr[j] = 0;
        FS_pr[j] = 0;
        FL_pr[j] = 0;
    }
    /* pad back of stored row values */
    for (j=s2Len; j<s2Len+PAD; ++j) {
        H_pr[j] = 0;
        HM_pr[j] = 0;
        HS_pr[j] = 0;
        HL_pr[j] = 0;
        F_pr[j] = 0;
        FM_pr[j] = 0;
        FS_pr[j] = 0;
        FL_pr[j] = 0;
    }
    H_pr[-1] = 0; /* upper left corner */

    /* iterate over query sequence */
    for (i=0; i<s1Len; i+=N) {
        __m128i case1 = vZero;
        __m128i case2 = vZero;
        __m128i vNH = vZero;
        __m128i vNM = vZero;
        __m128i vNS = vZero;
        __m128i vNL = vZero;
        __m128i vWH = vZero;
        __m128i vWM = vZero;
        __m128i vWS = vZero;
        __m128i vWL = vZero;
        __m128i vE = vNegInf0;
        __m128i vE_opn = vNegInf;
        __m128i vE_ext = vNegInf;
        __m128i vEM = vZero;
        __m128i vES = vZero;
        __m128i vEL = vZero;
        __m128i vF = vNegInf0;
        __m128i vF_opn = vNegInf;
        __m128i vF_ext = vNegInf;
        __m128i vFM = vZero;
        __m128i vFS = vZero;
        __m128i vFL = vZero;
        __m128i vJ = vJreset;
        __m128i vs1 = _mm_set_epi64x_rpl(
                s1[i+0],
                s1[i+1]);
        __m128i vs2 = vNegInf;
        const int * const restrict matrow0 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+0] : ((i+0 >= s1Len) ? s1Len-1 : i+0))];
        const int * const restrict matrow1 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+1] : ((i+1 >= s1Len) ? s1Len-1 : i+1))];
        vNH = _mm_insert_epi64_rpl(vNH, H_pr[-1], 1);
        vWH = _mm_insert_epi64_rpl(vWH, -open - i*gap, 1);
        H_pr[-1] = -open - (i+N)*gap;
        /* iterate over database sequence */
        for (j=0; j<s2Len+PAD; ++j) {
            __m128i vMat;
            __m128i vNWH = vNH;
            __m128i vNWM = vNM;
            __m128i vNWS = vNS;
            __m128i vNWL = vNL;
            vNH = _mm_srli_si128(vWH, 8);
            vNH = _mm_insert_epi64_rpl(vNH, H_pr[j], 1);
            vNM = _mm_srli_si128(vWM, 8);
            vNM = _mm_insert_epi64_rpl(vNM, HM_pr[j], 1);
            vNS = _mm_srli_si128(vWS, 8);
            vNS = _mm_insert_epi64_rpl(vNS, HS_pr[j], 1);
            vNL = _mm_srli_si128(vWL, 8);
            vNL = _mm_insert_epi64_rpl(vNL, HL_pr[j], 1);
            vF = _mm_srli_si128(vF, 8);
            vF = _mm_insert_epi64_rpl(vF, F_pr[j], 1);
            vFM = _mm_srli_si128(vFM, 8);
            vFM = _mm_insert_epi64_rpl(vFM, FM_pr[j], 1);
            vFS = _mm_srli_si128(vFS, 8);
            vFS = _mm_insert_epi64_rpl(vFS, FS_pr[j], 1);
            vFL = _mm_srli_si128(vFL, 8);
            vFL = _mm_insert_epi64_rpl(vFL, FL_pr[j], 1);
            vF_opn = _mm_sub_epi64(vNH, vOpen);
            vF_ext = _mm_sub_epi64(vF, vGap);
            vF = _mm_max_epi64_rpl(vF_opn, vF_ext);
            case1 = _mm_cmpgt_epi64_rpl(vF_opn, vF_ext);
            vFM = _mm_blendv_epi8_rpl(vFM, vNM, case1);
            vFS = _mm_blendv_epi8_rpl(vFS, vNS, case1);
            vFL = _mm_blendv_epi8_rpl(vFL, vNL, case1);
            vFL = _mm_add_epi64(vFL, vOne);
            vE_opn = _mm_sub_epi64(vWH, vOpen);
            vE_ext = _mm_sub_epi64(vE, vGap);
            vE = _mm_max_epi64_rpl(vE_opn, vE_ext);
            case1 = _mm_cmpgt_epi64_rpl(vE_opn, vE_ext);
            vEM = _mm_blendv_epi8_rpl(vEM, vWM, case1);
            vES = _mm_blendv_epi8_rpl(vES, vWS, case1);
            vEL = _mm_blendv_epi8_rpl(vEL, vWL, case1);
            vEL = _mm_add_epi64(vEL, vOne);
            vs2 = _mm_srli_si128(vs2, 8);
            vs2 = _mm_insert_epi64_rpl(vs2, s2[j], 1);
            vMat = _mm_set_epi64x_rpl(
                    matrow0[s2[j-0]],
                    matrow1[s2[j-1]]
                    );
            vNWH = _mm_add_epi64(vNWH, vMat);
            vWH = _mm_max_epi64_rpl(vNWH, vE);
            vWH = _mm_max_epi64_rpl(vWH, vF);
            case1 = _mm_cmpeq_epi64_rpl(vWH, vNWH);
            case2 = _mm_cmpeq_epi64_rpl(vWH, vF);
            vWM = _mm_blendv_epi8_rpl(
                    _mm_blendv_epi8_rpl(vEM, vFM, case2),
                    _mm_add_epi64(vNWM,
                        _mm_and_si128(
                            _mm_cmpeq_epi64_rpl(vs1,vs2),
                            vOne)),
                    case1);
            vWS = _mm_blendv_epi8_rpl(
                    _mm_blendv_epi8_rpl(vES, vFS, case2),
                    _mm_add_epi64(vNWS,
                        _mm_and_si128(
                            _mm_cmpgt_epi64_rpl(vMat,vZero),
                            vOne)),
                    case1);
            vWL = _mm_blendv_epi8_rpl(
                    _mm_blendv_epi8_rpl(vEL, vFL, case2),
                    _mm_add_epi64(vNWL, vOne), case1);
            /* as minor diagonal vector passes across the j=-1 boundary,
             * assign the appropriate boundary conditions */
            {
                __m128i cond = _mm_cmpeq_epi64_rpl(vJ,vNegOne);
                vWH = _mm_blendv_epi8_rpl(vWH, vIBoundary, cond);
                vWM = _mm_andnot_si128(cond, vWM);
                vWS = _mm_andnot_si128(cond, vWS);
                vWL = _mm_andnot_si128(cond, vWL);
                vE = _mm_blendv_epi8_rpl(vE, vNegInf, cond);
                vEM = _mm_andnot_si128(cond, vEM);
                vES = _mm_andnot_si128(cond, vES);
                vEL = _mm_andnot_si128(cond, vEL);
            }
            /* cannot start checking sat until after J clears boundary */
            if (j > PAD) {
                vSaturationCheckMin = _mm_min_epi64_rpl(vSaturationCheckMin, vWH);
                vSaturationCheckMax = _mm_max_epi64_rpl(vSaturationCheckMax, vWH);
                vSaturationCheckMax = _mm_max_epi64_rpl(vSaturationCheckMax, vWM);
                vSaturationCheckMax = _mm_max_epi64_rpl(vSaturationCheckMax, vWS);
                vSaturationCheckMax = _mm_max_epi64_rpl(vSaturationCheckMax, vWL);
                vSaturationCheckMax = _mm_max_epi64_rpl(vSaturationCheckMax, vWL);
            }
#ifdef PARASAIL_TABLE
            arr_store_si128(result->stats->tables->score_table, vWH, i, s1Len, j, s2Len);
            arr_store_si128(result->stats->tables->matches_table, vWM, i, s1Len, j, s2Len);
            arr_store_si128(result->stats->tables->similar_table, vWS, i, s1Len, j, s2Len);
            arr_store_si128(result->stats->tables->length_table, vWL, i, s1Len, j, s2Len);
#endif
#ifdef PARASAIL_ROWCOL
            arr_store_rowcol(result->stats->rowcols->score_row,   result->stats->rowcols->score_col, vWH, i, s1Len, j, s2Len);
            arr_store_rowcol(result->stats->rowcols->matches_row, result->stats->rowcols->matches_col, vWM, i, s1Len, j, s2Len);
            arr_store_rowcol(result->stats->rowcols->similar_row, result->stats->rowcols->similar_col, vWS, i, s1Len, j, s2Len);
            arr_store_rowcol(result->stats->rowcols->length_row,  result->stats->rowcols->length_col, vWL, i, s1Len, j, s2Len);
#endif
            H_pr[j-1] = (int64_t)_mm_extract_epi64_rpl(vWH,0);
            HM_pr[j-1] = (int64_t)_mm_extract_epi64_rpl(vWM,0);
            HS_pr[j-1] = (int64_t)_mm_extract_epi64_rpl(vWS,0);
            HL_pr[j-1] = (int64_t)_mm_extract_epi64_rpl(vWL,0);
            F_pr[j-1] = (int64_t)_mm_extract_epi64_rpl(vF,0);
            FM_pr[j-1] = (int64_t)_mm_extract_epi64_rpl(vFM,0);
            FS_pr[j-1] = (int64_t)_mm_extract_epi64_rpl(vFS,0);
            FL_pr[j-1] = (int64_t)_mm_extract_epi64_rpl(vFL,0);
            /* as minor diagonal vector passes across table, extract
               last table value at the i,j bound */
            {
                __m128i cond_valid_I = _mm_cmpeq_epi64_rpl(vI, vILimit1);
                __m128i cond_valid_J = _mm_cmpeq_epi64_rpl(vJ, vJLimit1);
                __m128i cond_all = _mm_and_si128(cond_valid_I, cond_valid_J);
                vMaxH = _mm_blendv_epi8_rpl(vMaxH, vWH, cond_all);
                vMaxM = _mm_blendv_epi8_rpl(vMaxM, vWM, cond_all);
                vMaxS = _mm_blendv_epi8_rpl(vMaxS, vWS, cond_all);
                vMaxL = _mm_blendv_epi8_rpl(vMaxL, vWL, cond_all);
            }
            vJ = _mm_add_epi64(vJ, vOne);
        }
        vI = _mm_add_epi64(vI, vN);
        vIBoundary = _mm_sub_epi64(vIBoundary, vGapN);
    }

    /* max in vMaxH */
    for (i=0; i<N; ++i) {
        int64_t value;
        value = (int64_t) _mm_extract_epi64_rpl(vMaxH, 1);
        if (value > score) {
            score = value;
            matches = (int64_t) _mm_extract_epi64_rpl(vMaxM, 1);
            similar = (int64_t) _mm_extract_epi64_rpl(vMaxS, 1);
            length= (int64_t) _mm_extract_epi64_rpl(vMaxL, 1);
        }
        vMaxH = _mm_slli_si128(vMaxH, 8);
        vMaxM = _mm_slli_si128(vMaxM, 8);
        vMaxS = _mm_slli_si128(vMaxS, 8);
        vMaxL = _mm_slli_si128(vMaxL, 8);
    }

    if (_mm_movemask_epi8(_mm_or_si128(
            _mm_cmplt_epi64_rpl(vSaturationCheckMin, vNegLimit),
            _mm_cmpgt_epi64_rpl(vSaturationCheckMax, vPosLimit)))) {
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

    parasail_free(_FL_pr);
    parasail_free(_FS_pr);
    parasail_free(_FM_pr);
    parasail_free(_F_pr);
    parasail_free(_HL_pr);
    parasail_free(_HS_pr);
    parasail_free(_HM_pr);
    parasail_free(_H_pr);
    parasail_free(s2B);
    parasail_free(s1);

    return result;
}


