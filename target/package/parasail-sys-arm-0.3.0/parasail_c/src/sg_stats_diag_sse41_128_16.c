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
#include <smmintrin.h>
#endif

#include "parasail.h"
#include "parasail/memory.h"
#include "parasail/internal_sse.h"

#define SG_STATS
#define SG_SUFFIX _diag_sse41_128_16
#include "sg_helper.h"



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
        array[1LL*(i+0)*s2Len + (j-0)] = (int16_t)_mm_extract_epi16(vWH, 7);
    }
    if (0 <= i+1 && i+1 < s1Len && 0 <= j-1 && j-1 < s2Len) {
        array[1LL*(i+1)*s2Len + (j-1)] = (int16_t)_mm_extract_epi16(vWH, 6);
    }
    if (0 <= i+2 && i+2 < s1Len && 0 <= j-2 && j-2 < s2Len) {
        array[1LL*(i+2)*s2Len + (j-2)] = (int16_t)_mm_extract_epi16(vWH, 5);
    }
    if (0 <= i+3 && i+3 < s1Len && 0 <= j-3 && j-3 < s2Len) {
        array[1LL*(i+3)*s2Len + (j-3)] = (int16_t)_mm_extract_epi16(vWH, 4);
    }
    if (0 <= i+4 && i+4 < s1Len && 0 <= j-4 && j-4 < s2Len) {
        array[1LL*(i+4)*s2Len + (j-4)] = (int16_t)_mm_extract_epi16(vWH, 3);
    }
    if (0 <= i+5 && i+5 < s1Len && 0 <= j-5 && j-5 < s2Len) {
        array[1LL*(i+5)*s2Len + (j-5)] = (int16_t)_mm_extract_epi16(vWH, 2);
    }
    if (0 <= i+6 && i+6 < s1Len && 0 <= j-6 && j-6 < s2Len) {
        array[1LL*(i+6)*s2Len + (j-6)] = (int16_t)_mm_extract_epi16(vWH, 1);
    }
    if (0 <= i+7 && i+7 < s1Len && 0 <= j-7 && j-7 < s2Len) {
        array[1LL*(i+7)*s2Len + (j-7)] = (int16_t)_mm_extract_epi16(vWH, 0);
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
        row[j-0] = (int16_t)_mm_extract_epi16(vWH, 7);
    }
    if (j-0 == s2Len-1 && 0 <= i+0 && i+0 < s1Len) {
        col[(i+0)] = (int16_t)_mm_extract_epi16(vWH, 7);
    }
    if (i+1 == s1Len-1 && 0 <= j-1 && j-1 < s2Len) {
        row[j-1] = (int16_t)_mm_extract_epi16(vWH, 6);
    }
    if (j-1 == s2Len-1 && 0 <= i+1 && i+1 < s1Len) {
        col[(i+1)] = (int16_t)_mm_extract_epi16(vWH, 6);
    }
    if (i+2 == s1Len-1 && 0 <= j-2 && j-2 < s2Len) {
        row[j-2] = (int16_t)_mm_extract_epi16(vWH, 5);
    }
    if (j-2 == s2Len-1 && 0 <= i+2 && i+2 < s1Len) {
        col[(i+2)] = (int16_t)_mm_extract_epi16(vWH, 5);
    }
    if (i+3 == s1Len-1 && 0 <= j-3 && j-3 < s2Len) {
        row[j-3] = (int16_t)_mm_extract_epi16(vWH, 4);
    }
    if (j-3 == s2Len-1 && 0 <= i+3 && i+3 < s1Len) {
        col[(i+3)] = (int16_t)_mm_extract_epi16(vWH, 4);
    }
    if (i+4 == s1Len-1 && 0 <= j-4 && j-4 < s2Len) {
        row[j-4] = (int16_t)_mm_extract_epi16(vWH, 3);
    }
    if (j-4 == s2Len-1 && 0 <= i+4 && i+4 < s1Len) {
        col[(i+4)] = (int16_t)_mm_extract_epi16(vWH, 3);
    }
    if (i+5 == s1Len-1 && 0 <= j-5 && j-5 < s2Len) {
        row[j-5] = (int16_t)_mm_extract_epi16(vWH, 2);
    }
    if (j-5 == s2Len-1 && 0 <= i+5 && i+5 < s1Len) {
        col[(i+5)] = (int16_t)_mm_extract_epi16(vWH, 2);
    }
    if (i+6 == s1Len-1 && 0 <= j-6 && j-6 < s2Len) {
        row[j-6] = (int16_t)_mm_extract_epi16(vWH, 1);
    }
    if (j-6 == s2Len-1 && 0 <= i+6 && i+6 < s1Len) {
        col[(i+6)] = (int16_t)_mm_extract_epi16(vWH, 1);
    }
    if (i+7 == s1Len-1 && 0 <= j-7 && j-7 < s2Len) {
        row[j-7] = (int16_t)_mm_extract_epi16(vWH, 0);
    }
    if (j-7 == s2Len-1 && 0 <= i+7 && i+7 < s1Len) {
        col[(i+7)] = (int16_t)_mm_extract_epi16(vWH, 0);
    }
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_sg_flags_stats_table_diag_sse41_128_16
#else
#ifdef PARASAIL_ROWCOL
#define FNAME parasail_sg_flags_stats_rowcol_diag_sse41_128_16
#else
#define FNAME parasail_sg_flags_stats_diag_sse41_128_16
#endif
#endif

parasail_result_t* FNAME(
        const char * const restrict _s1, const int _s1Len,
        const char * const restrict _s2, const int s2Len,
        const int open, const int gap, const parasail_matrix_t *matrix,
        int s1_beg, int s1_end, int s2_beg, int s2_end)
{
    /* declare local variables */
    int32_t N = 0;
    int32_t PAD = 0;
    int32_t PAD2 = 0;
    int32_t s1Len = 0;
    int32_t s1Len_PAD = 0;
    int32_t s2Len_PAD = 0;
    int16_t * restrict s1 = NULL;
    int16_t * restrict s2B = NULL;
    int16_t * restrict _H_pr = NULL;
    int16_t * restrict _HM_pr = NULL;
    int16_t * restrict _HS_pr = NULL;
    int16_t * restrict _HL_pr = NULL;
    int16_t * restrict _F_pr = NULL;
    int16_t * restrict _FM_pr = NULL;
    int16_t * restrict _FS_pr = NULL;
    int16_t * restrict _FL_pr = NULL;
    int16_t * restrict s2 = NULL;
    int16_t * restrict H_pr = NULL;
    int16_t * restrict HM_pr = NULL;
    int16_t * restrict HS_pr = NULL;
    int16_t * restrict HL_pr = NULL;
    int16_t * restrict F_pr = NULL;
    int16_t * restrict FM_pr = NULL;
    int16_t * restrict FS_pr = NULL;
    int16_t * restrict FL_pr = NULL;
    parasail_result_t *result = NULL;
    int32_t i = 0;
    int32_t j = 0;
    int32_t end_query = 0;
    int32_t end_ref = 0;
    int16_t NEG_LIMIT = 0;
    int16_t POS_LIMIT = 0;
    int16_t score = 0;
    int16_t matches = 0;
    int16_t similar = 0;
    int16_t length = 0;
    __m128i vNegLimit;
    __m128i vPosLimit;
    __m128i vSaturationCheckMin;
    __m128i vSaturationCheckMax;
    __m128i vNegInf;
    __m128i vOpen;
    __m128i vGap;
    __m128i vZero;
    __m128i vOne;
    __m128i vN;
    __m128i vGapN;
    __m128i vNegOne;
    __m128i vI;
    __m128i vJreset;
    __m128i vMaxHRow;
    __m128i vMaxMRow;
    __m128i vMaxSRow;
    __m128i vMaxLRow;
    __m128i vMaxHCol;
    __m128i vMaxMCol;
    __m128i vMaxSCol;
    __m128i vMaxLCol;
    __m128i vLastValH;
    __m128i vLastValM;
    __m128i vLastValS;
    __m128i vLastValL;
    __m128i vEndI;
    __m128i vEndJ;
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
    N = 8; /* number of values in vector */
    PAD = N-1;
    PAD2 = PAD*2;
    s1Len = matrix->type == PARASAIL_MATRIX_TYPE_SQUARE ? _s1Len : matrix->length;
    s1Len_PAD = s1Len+PAD;
    s2Len_PAD = s2Len+PAD;
    i = 0;
    j = 0;
    end_query = s1Len-1;
    end_ref = s2Len-1;
    NEG_LIMIT = (-open < matrix->min ? INT16_MIN + open : INT16_MIN - matrix->min) + 1;
    POS_LIMIT = INT16_MAX - matrix->max - 1;
    score = NEG_LIMIT;
    matches = NEG_LIMIT;
    similar = NEG_LIMIT;
    length = NEG_LIMIT;
    vNegLimit = _mm_set1_epi16(NEG_LIMIT);
    vPosLimit = _mm_set1_epi16(POS_LIMIT);
    vSaturationCheckMin = vPosLimit;
    vSaturationCheckMax = vNegLimit;
    vNegInf = _mm_set1_epi16(NEG_LIMIT);
    vOpen = _mm_set1_epi16(open);
    vGap  = _mm_set1_epi16(gap);
    vZero = _mm_set1_epi16(0);
    vOne = _mm_set1_epi16(1);
    vN = _mm_set1_epi16(N);
    vGapN = s1_beg ? _mm_set1_epi16(0) : _mm_set1_epi16(gap*N);
    vNegOne = _mm_set1_epi16(-1);
    vI = _mm_set_epi16(0,1,2,3,4,5,6,7);
    vJreset = _mm_set_epi16(0,-1,-2,-3,-4,-5,-6,-7);
    vMaxHRow = vNegInf;
    vMaxMRow = vNegInf;
    vMaxSRow = vNegInf;
    vMaxLRow = vNegInf;
    vMaxHCol = vNegInf;
    vMaxMCol = vNegInf;
    vMaxSCol = vNegInf;
    vMaxLCol = vNegInf;
    vLastValH = vNegInf;
    vLastValM = vNegInf;
    vLastValS = vNegInf;
    vLastValL = vNegInf;
    vEndI = vNegInf;
    vEndJ = vNegInf;
    vILimit = _mm_set1_epi16(s1Len);
    vILimit1 = _mm_subs_epi16(vILimit, vOne);
    vJLimit = _mm_set1_epi16(s2Len);
    vJLimit1 = _mm_subs_epi16(vJLimit, vOne);
    vIBoundary = s1_beg ? _mm_set1_epi16(0) : _mm_set_epi16(
            -open-0*gap,
            -open-1*gap,
            -open-2*gap,
            -open-3*gap,
            -open-4*gap,
            -open-5*gap,
            -open-6*gap,
            -open-7*gap);

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
    result->flag |= PARASAIL_FLAG_SG | PARASAIL_FLAG_DIAG
        | PARASAIL_FLAG_STATS
        | PARASAIL_FLAG_BITS_16 | PARASAIL_FLAG_LANES_8;
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
    s1     = parasail_memalign_int16_t(16, s1Len+PAD);
    s2B    = parasail_memalign_int16_t(16, s2Len+PAD2);
    _H_pr  = parasail_memalign_int16_t(16, s2Len+PAD2);
    _HM_pr = parasail_memalign_int16_t(16, s2Len+PAD2);
    _HS_pr = parasail_memalign_int16_t(16, s2Len+PAD2);
    _HL_pr = parasail_memalign_int16_t(16, s2Len+PAD2);
    _F_pr  = parasail_memalign_int16_t(16, s2Len+PAD2);
    _FM_pr = parasail_memalign_int16_t(16, s2Len+PAD2);
    _FS_pr = parasail_memalign_int16_t(16, s2Len+PAD2);
    _FL_pr = parasail_memalign_int16_t(16, s2Len+PAD2);
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
    if (s2_beg) {
        for (j=0; j<s2Len; ++j) {
            H_pr[j] = 0;
            HM_pr[j] = 0;
            HS_pr[j] = 0;
            HL_pr[j] = 0;
            F_pr[j] = NEG_LIMIT;
            FM_pr[j] = 0;
            FS_pr[j] = 0;
            FL_pr[j] = 0;
        }
    }
    else {
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
        __m128i vNH = vNegInf;
        __m128i vNM = vZero;
        __m128i vNS = vZero;
        __m128i vNL = vZero;
        __m128i vWH = vNegInf;
        __m128i vWM = vZero;
        __m128i vWS = vZero;
        __m128i vWL = vZero;
        __m128i vE = vNegInf;
        __m128i vE_opn = vNegInf;
        __m128i vE_ext = vNegInf;
        __m128i vEM = vZero;
        __m128i vES = vZero;
        __m128i vEL = vZero;
        __m128i vF = vNegInf;
        __m128i vF_opn = vNegInf;
        __m128i vF_ext = vNegInf;
        __m128i vFM = vZero;
        __m128i vFS = vZero;
        __m128i vFL = vZero;
        __m128i vJ = vJreset;
        __m128i vs1 = _mm_set_epi16(
                s1[i+0],
                s1[i+1],
                s1[i+2],
                s1[i+3],
                s1[i+4],
                s1[i+5],
                s1[i+6],
                s1[i+7]);
        __m128i vs2 = vNegInf;
        const int * const restrict matrow0 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+0] : ((i+0 >= s1Len) ? s1Len-1 : i+0))];
        const int * const restrict matrow1 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+1] : ((i+1 >= s1Len) ? s1Len-1 : i+1))];
        const int * const restrict matrow2 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+2] : ((i+2 >= s1Len) ? s1Len-1 : i+2))];
        const int * const restrict matrow3 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+3] : ((i+3 >= s1Len) ? s1Len-1 : i+3))];
        const int * const restrict matrow4 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+4] : ((i+4 >= s1Len) ? s1Len-1 : i+4))];
        const int * const restrict matrow5 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+5] : ((i+5 >= s1Len) ? s1Len-1 : i+5))];
        const int * const restrict matrow6 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+6] : ((i+6 >= s1Len) ? s1Len-1 : i+6))];
        const int * const restrict matrow7 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+7] : ((i+7 >= s1Len) ? s1Len-1 : i+7))];
        __m128i vIltLimit = _mm_cmplt_epi16(vI, vILimit);
        __m128i vIeqLimit1 = _mm_cmpeq_epi16(vI, vILimit1);
        vNH = _mm_srli_si128(vNH, 2);
        vNH = _mm_insert_epi16(vNH, H_pr[-1], 7);
        vWH = _mm_srli_si128(vWH, 2);
        vWH = _mm_insert_epi16(vWH, s1_beg ? 0 : (-open - i*gap), 7);
        H_pr[-1] = -open - (i+N)*gap;
        /* iterate over database sequence */
        for (j=0; j<s2Len+PAD; ++j) {
            __m128i vMat;
            __m128i vNWH = vNH;
            __m128i vNWM = vNM;
            __m128i vNWS = vNS;
            __m128i vNWL = vNL;
            vNH = _mm_srli_si128(vWH, 2);
            vNH = _mm_insert_epi16(vNH, H_pr[j], 7);
            vNM = _mm_srli_si128(vWM, 2);
            vNM = _mm_insert_epi16(vNM, HM_pr[j], 7);
            vNS = _mm_srli_si128(vWS, 2);
            vNS = _mm_insert_epi16(vNS, HS_pr[j], 7);
            vNL = _mm_srli_si128(vWL, 2);
            vNL = _mm_insert_epi16(vNL, HL_pr[j], 7);
            vF = _mm_srli_si128(vF, 2);
            vF = _mm_insert_epi16(vF, F_pr[j], 7);
            vFM = _mm_srli_si128(vFM, 2);
            vFM = _mm_insert_epi16(vFM, FM_pr[j], 7);
            vFS = _mm_srli_si128(vFS, 2);
            vFS = _mm_insert_epi16(vFS, FS_pr[j], 7);
            vFL = _mm_srli_si128(vFL, 2);
            vFL = _mm_insert_epi16(vFL, FL_pr[j], 7);
            vF_opn = _mm_subs_epi16(vNH, vOpen);
            vF_ext = _mm_subs_epi16(vF, vGap);
            vF = _mm_max_epi16(vF_opn, vF_ext);
            case1 = _mm_cmpgt_epi16(vF_opn, vF_ext);
            vFM = _mm_blendv_epi8(vFM, vNM, case1);
            vFS = _mm_blendv_epi8(vFS, vNS, case1);
            vFL = _mm_blendv_epi8(vFL, vNL, case1);
            vFL = _mm_adds_epi16(vFL, vOne);
            vE_opn = _mm_subs_epi16(vWH, vOpen);
            vE_ext = _mm_subs_epi16(vE, vGap);
            vE = _mm_max_epi16(vE_opn, vE_ext);
            case1 = _mm_cmpgt_epi16(vE_opn, vE_ext);
            vEM = _mm_blendv_epi8(vEM, vWM, case1);
            vES = _mm_blendv_epi8(vES, vWS, case1);
            vEL = _mm_blendv_epi8(vEL, vWL, case1);
            vEL = _mm_adds_epi16(vEL, vOne);
            vs2 = _mm_srli_si128(vs2, 2);
            vs2 = _mm_insert_epi16(vs2, s2[j], 7);
            vMat = _mm_set_epi16(
                    matrow0[s2[j-0]],
                    matrow1[s2[j-1]],
                    matrow2[s2[j-2]],
                    matrow3[s2[j-3]],
                    matrow4[s2[j-4]],
                    matrow5[s2[j-5]],
                    matrow6[s2[j-6]],
                    matrow7[s2[j-7]]
                    );
            vNWH = _mm_adds_epi16(vNWH, vMat);
            vWH = _mm_max_epi16(vNWH, vE);
            vWH = _mm_max_epi16(vWH, vF);
            case1 = _mm_cmpeq_epi16(vWH, vNWH);
            case2 = _mm_cmpeq_epi16(vWH, vF);
            vWM = _mm_blendv_epi8(
                    _mm_blendv_epi8(vEM, vFM, case2),
                    _mm_adds_epi16(vNWM,
                        _mm_and_si128(
                            _mm_cmpeq_epi16(vs1,vs2),
                            vOne)),
                    case1);
            vWS = _mm_blendv_epi8(
                    _mm_blendv_epi8(vES, vFS, case2),
                    _mm_adds_epi16(vNWS,
                        _mm_and_si128(
                            _mm_cmpgt_epi16(vMat,vZero),
                            vOne)),
                    case1);
            vWL = _mm_blendv_epi8(
                    _mm_blendv_epi8(vEL, vFL, case2),
                    _mm_adds_epi16(vNWL, vOne), case1);
            /* as minor diagonal vector passes across the j=-1 boundary,
             * assign the appropriate boundary conditions */
            {
                __m128i cond = _mm_cmpeq_epi16(vJ,vNegOne);
                vWH = _mm_blendv_epi8(vWH, vIBoundary, cond);
                vWM = _mm_andnot_si128(cond, vWM);
                vWS = _mm_andnot_si128(cond, vWS);
                vWL = _mm_andnot_si128(cond, vWL);
                vE = _mm_blendv_epi8(vE, vNegInf, cond);
                vEM = _mm_andnot_si128(cond, vEM);
                vES = _mm_andnot_si128(cond, vES);
                vEL = _mm_andnot_si128(cond, vEL);
            }
            /* cannot start checking sat until after J clears boundary */
            if (j > PAD) {
                vSaturationCheckMin = _mm_min_epi16(vSaturationCheckMin, vWH);
                vSaturationCheckMax = _mm_max_epi16(vSaturationCheckMax, vWH);
                vSaturationCheckMax = _mm_max_epi16(vSaturationCheckMax, vWM);
                vSaturationCheckMax = _mm_max_epi16(vSaturationCheckMax, vWS);
                vSaturationCheckMax = _mm_max_epi16(vSaturationCheckMax, vWL);
                vSaturationCheckMax = _mm_max_epi16(vSaturationCheckMax, vWL);
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
            H_pr[j-7] = (int16_t)_mm_extract_epi16(vWH,0);
            HM_pr[j-7] = (int16_t)_mm_extract_epi16(vWM,0);
            HS_pr[j-7] = (int16_t)_mm_extract_epi16(vWS,0);
            HL_pr[j-7] = (int16_t)_mm_extract_epi16(vWL,0);
            F_pr[j-7] = (int16_t)_mm_extract_epi16(vF,0);
            FM_pr[j-7] = (int16_t)_mm_extract_epi16(vFM,0);
            FS_pr[j-7] = (int16_t)_mm_extract_epi16(vFS,0);
            FL_pr[j-7] = (int16_t)_mm_extract_epi16(vFL,0);
            /* as minor diagonal vector passes across the i or j limit
             * boundary, extract the last value of the column or row */
            {
                __m128i vJeqLimit1 = _mm_cmpeq_epi16(vJ, vJLimit1);
                __m128i vJgtNegOne = _mm_cmpgt_epi16(vJ, vNegOne);
                __m128i vJltLimit = _mm_cmplt_epi16(vJ, vJLimit);
                __m128i cond_j = _mm_and_si128(vIltLimit, vJeqLimit1);
                __m128i cond_i = _mm_and_si128(vIeqLimit1,
                        _mm_and_si128(vJgtNegOne, vJltLimit));
                __m128i cond_max_row = _mm_cmpgt_epi16(vWH, vMaxHRow);
                __m128i cond_max_col = _mm_cmpgt_epi16(vWH, vMaxHCol);
                __m128i cond_last_val = _mm_and_si128(vIeqLimit1, vJeqLimit1);
                __m128i cond_all_row = _mm_and_si128(cond_max_row, cond_i);
                __m128i cond_all_col = _mm_and_si128(cond_max_col, cond_j);
                vMaxHRow = _mm_blendv_epi8(vMaxHRow, vWH, cond_all_row);
                vMaxMRow = _mm_blendv_epi8(vMaxMRow, vWM, cond_all_row);
                vMaxSRow = _mm_blendv_epi8(vMaxSRow, vWS, cond_all_row);
                vMaxLRow = _mm_blendv_epi8(vMaxLRow, vWL, cond_all_row);
                vMaxHCol = _mm_blendv_epi8(vMaxHCol, vWH, cond_all_col);
                vMaxMCol = _mm_blendv_epi8(vMaxMCol, vWM, cond_all_col);
                vMaxSCol = _mm_blendv_epi8(vMaxSCol, vWS, cond_all_col);
                vMaxLCol = _mm_blendv_epi8(vMaxLCol, vWL, cond_all_col);
                vLastValH = _mm_blendv_epi8(vLastValH, vWH, cond_last_val);
                vLastValM = _mm_blendv_epi8(vLastValM, vWM, cond_last_val);
                vLastValS = _mm_blendv_epi8(vLastValS, vWS, cond_last_val);
                vLastValL = _mm_blendv_epi8(vLastValL, vWL, cond_last_val);
                vEndI = _mm_blendv_epi8(vEndI, vI, cond_all_col);
                vEndJ = _mm_blendv_epi8(vEndJ, vJ, cond_all_row);
            }
            vJ = _mm_adds_epi16(vJ, vOne);
        }
        vI = _mm_adds_epi16(vI, vN);
        vIBoundary = _mm_subs_epi16(vIBoundary, vGapN);
    }

    /* alignment ending position */
    {
        int16_t max_rowh = NEG_LIMIT;
        int16_t max_rowm = NEG_LIMIT;
        int16_t max_rows = NEG_LIMIT;
        int16_t max_rowl = NEG_LIMIT;
        int16_t max_colh = NEG_LIMIT;
        int16_t max_colm = NEG_LIMIT;
        int16_t max_cols = NEG_LIMIT;
        int16_t max_coll = NEG_LIMIT;
        int16_t last_valh = NEG_LIMIT;
        int16_t last_valm = NEG_LIMIT;
        int16_t last_vals = NEG_LIMIT;
        int16_t last_vall = NEG_LIMIT;
        int16_t *rh = (int16_t*)&vMaxHRow;
        int16_t *rm = (int16_t*)&vMaxMRow;
        int16_t *rs = (int16_t*)&vMaxSRow;
        int16_t *rl = (int16_t*)&vMaxLRow;
        int16_t *ch = (int16_t*)&vMaxHCol;
        int16_t *cm = (int16_t*)&vMaxMCol;
        int16_t *cs = (int16_t*)&vMaxSCol;
        int16_t *cl = (int16_t*)&vMaxLCol;
        int16_t *lh = (int16_t*)&vLastValH;
        int16_t *lm = (int16_t*)&vLastValM;
        int16_t *ls = (int16_t*)&vLastValS;
        int16_t *ll = (int16_t*)&vLastValL;
        int16_t *i = (int16_t*)&vEndI;
        int16_t *j = (int16_t*)&vEndJ;
        int32_t k;
        for (k=0; k<N; ++k, ++rh, ++rm, ++rs, ++rl, ++ch, ++cm, ++cs, ++cl, ++lh, ++lm, ++ls, ++ll, ++i, ++j) {
            if (*ch > max_colh || (*ch == max_colh && *i < end_query)) {
                max_colh = *ch;
                end_query = *i;
                max_colm = *cm;
                max_cols = *cs;
                max_coll = *cl;
            }
            if (*rh > max_rowh) {
                max_rowh = *rh;
                end_ref = *j;
                max_rowm = *rm;
                max_rows = *rs;
                max_rowl = *rl;
            }
            if (*lh > last_valh) {
                last_valh = *lh;
                last_valm = *lm;
                last_vals = *ls;
                last_vall = *ll;
            }
        }
        if (s1_end && s2_end) {
            if (max_colh > max_rowh || (max_colh == max_rowh && end_ref == s2Len-1)) {
                score = max_colh;
                end_ref = s2Len-1;
                matches = max_colm;
                similar = max_cols;
                length = max_coll;
            }
            else {
                score = max_rowh;
                end_query = s1Len-1;
                matches = max_rowm;
                similar = max_rows;
                length = max_rowl;
            }
        }
        else if (s1_end) {
            score = max_colh;
            end_ref = s2Len-1;
            matches = max_colm;
            similar = max_cols;
            length = max_coll;
        }
        else if (s2_end) {
            score = max_rowh;
            end_query = s1Len-1;
            matches = max_rowm;
            similar = max_rows;
            length = max_rowl;
        }
        else {
            score = last_valh;
            end_query = s1Len-1;
            end_ref = s2Len-1;
            matches = last_valm;
            similar = last_vals;
            length = last_vall;
        }
    }

    if (_mm_movemask_epi8(_mm_or_si128(
            _mm_cmplt_epi16(vSaturationCheckMin, vNegLimit),
            _mm_cmpgt_epi16(vSaturationCheckMax, vPosLimit)))) {
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

SG_IMPL_ALL


