/**
 * @file
 *
 * @author jeffrey.daily@gmail.com
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 */
#include "config.h"

#include <stdlib.h>



#include "parasail.h"
#include "parasail/memory.h"
#include "parasail/internal_neon.h"



#ifdef PARASAIL_TABLE
static inline void arr_store_si128(
        int *array,
        simde__m128i vWH,
        int32_t i,
        int32_t s1Len,
        int32_t j,
        int32_t s2Len)
{
    if (0 <= i+0 && i+0 < s1Len && 0 <= j-0 && j-0 < s2Len) {
        array[1LL*(i+0)*s2Len + (j-0)] = (int32_t)simde_mm_extract_epi32(vWH, 3);
    }
    if (0 <= i+1 && i+1 < s1Len && 0 <= j-1 && j-1 < s2Len) {
        array[1LL*(i+1)*s2Len + (j-1)] = (int32_t)simde_mm_extract_epi32(vWH, 2);
    }
    if (0 <= i+2 && i+2 < s1Len && 0 <= j-2 && j-2 < s2Len) {
        array[1LL*(i+2)*s2Len + (j-2)] = (int32_t)simde_mm_extract_epi32(vWH, 1);
    }
    if (0 <= i+3 && i+3 < s1Len && 0 <= j-3 && j-3 < s2Len) {
        array[1LL*(i+3)*s2Len + (j-3)] = (int32_t)simde_mm_extract_epi32(vWH, 0);
    }
}
#endif

#ifdef PARASAIL_ROWCOL
static inline void arr_store_rowcol(
        int *row,
        int *col,
        simde__m128i vWH,
        int32_t i,
        int32_t s1Len,
        int32_t j,
        int32_t s2Len)
{
    if (i+0 == s1Len-1 && 0 <= j-0 && j-0 < s2Len) {
        row[j-0] = (int32_t)simde_mm_extract_epi32(vWH, 3);
    }
    if (j-0 == s2Len-1 && 0 <= i+0 && i+0 < s1Len) {
        col[(i+0)] = (int32_t)simde_mm_extract_epi32(vWH, 3);
    }
    if (i+1 == s1Len-1 && 0 <= j-1 && j-1 < s2Len) {
        row[j-1] = (int32_t)simde_mm_extract_epi32(vWH, 2);
    }
    if (j-1 == s2Len-1 && 0 <= i+1 && i+1 < s1Len) {
        col[(i+1)] = (int32_t)simde_mm_extract_epi32(vWH, 2);
    }
    if (i+2 == s1Len-1 && 0 <= j-2 && j-2 < s2Len) {
        row[j-2] = (int32_t)simde_mm_extract_epi32(vWH, 1);
    }
    if (j-2 == s2Len-1 && 0 <= i+2 && i+2 < s1Len) {
        col[(i+2)] = (int32_t)simde_mm_extract_epi32(vWH, 1);
    }
    if (i+3 == s1Len-1 && 0 <= j-3 && j-3 < s2Len) {
        row[j-3] = (int32_t)simde_mm_extract_epi32(vWH, 0);
    }
    if (j-3 == s2Len-1 && 0 <= i+3 && i+3 < s1Len) {
        col[(i+3)] = (int32_t)simde_mm_extract_epi32(vWH, 0);
    }
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_nw_stats_table_diag_neon_128_32
#else
#ifdef PARASAIL_ROWCOL
#define FNAME parasail_nw_stats_rowcol_diag_neon_128_32
#else
#define FNAME parasail_nw_stats_diag_neon_128_32
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
    int32_t * restrict s1 = NULL;
    int32_t * restrict s2B = NULL;
    int32_t * restrict _H_pr = NULL;
    int32_t * restrict _HM_pr = NULL;
    int32_t * restrict _HS_pr = NULL;
    int32_t * restrict _HL_pr = NULL;
    int32_t * restrict _F_pr = NULL;
    int32_t * restrict _FM_pr = NULL;
    int32_t * restrict _FS_pr = NULL;
    int32_t * restrict _FL_pr = NULL;
    int32_t * restrict s2 = NULL;
    int32_t * restrict H_pr = NULL;
    int32_t * restrict HM_pr = NULL;
    int32_t * restrict HS_pr = NULL;
    int32_t * restrict HL_pr = NULL;
    int32_t * restrict F_pr = NULL;
    int32_t * restrict FM_pr = NULL;
    int32_t * restrict FS_pr = NULL;
    int32_t * restrict FL_pr = NULL;
    parasail_result_t *result = NULL;
    int32_t i = 0;
    int32_t j = 0;
    int32_t end_query = 0;
    int32_t end_ref = 0;
    int32_t NEG_LIMIT = 0;
    int32_t POS_LIMIT = 0;
    int32_t score = 0;
    int32_t matches = 0;
    int32_t similar = 0;
    int32_t length = 0;
    simde__m128i vNegLimit;
    simde__m128i vPosLimit;
    simde__m128i vSaturationCheckMin;
    simde__m128i vSaturationCheckMax;
    simde__m128i vNegInf;
    simde__m128i vOpen;
    simde__m128i vGap;
    simde__m128i vZero;
    simde__m128i vNegInf0;
    simde__m128i vOne;
    simde__m128i vN;
    simde__m128i vGapN;
    simde__m128i vNegOne;
    simde__m128i vI;
    simde__m128i vJreset;
    simde__m128i vMaxH;
    simde__m128i vMaxM;
    simde__m128i vMaxS;
    simde__m128i vMaxL;
    simde__m128i vILimit;
    simde__m128i vILimit1;
    simde__m128i vJLimit;
    simde__m128i vJLimit1;
    simde__m128i vIBoundary;

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
    N = 4; /* number of values in vector */
    PAD = N-1;
    PAD2 = PAD*2;
    s1Len = matrix->type == PARASAIL_MATRIX_TYPE_SQUARE ? _s1Len : matrix->length;
    s1Len_PAD = s1Len+PAD;
    s2Len_PAD = s2Len+PAD;
    i = 0;
    j = 0;
    end_query = s1Len-1;
    end_ref = s2Len-1;
    NEG_LIMIT = (-open < matrix->min ? INT32_MIN + open : INT32_MIN - matrix->min) + 1;
    POS_LIMIT = INT32_MAX - matrix->max - 1;
    score = NEG_LIMIT;
    matches = NEG_LIMIT;
    similar = NEG_LIMIT;
    length = NEG_LIMIT;
    vNegLimit = simde_mm_set1_epi32(NEG_LIMIT);
    vPosLimit = simde_mm_set1_epi32(POS_LIMIT);
    vSaturationCheckMin = vPosLimit;
    vSaturationCheckMax = vNegLimit;
    vNegInf = simde_mm_set1_epi32(NEG_LIMIT);
    vOpen = simde_mm_set1_epi32(open);
    vGap  = simde_mm_set1_epi32(gap);
    vZero = simde_mm_set1_epi32(0);
    vNegInf0 = simde_mm_insert_epi32(vZero, NEG_LIMIT, 3);
    vOne = simde_mm_set1_epi32(1);
    vN = simde_mm_set1_epi32(N);
    vGapN = simde_mm_set1_epi32(gap*N);
    vNegOne = simde_mm_set1_epi32(-1);
    vI = simde_mm_set_epi32(0,1,2,3);
    vJreset = simde_mm_set_epi32(0,-1,-2,-3);
    vMaxH = vNegInf;
    vMaxM = vNegInf;
    vMaxS = vNegInf;
    vMaxL = vNegInf;
    vILimit = simde_mm_set1_epi32(s1Len);
    vILimit1 = simde_mm_sub_epi32(vILimit, vOne);
    vJLimit = simde_mm_set1_epi32(s2Len);
    vJLimit1 = simde_mm_sub_epi32(vJLimit, vOne);
    vIBoundary = simde_mm_set_epi32(
            -open-0*gap,
            -open-1*gap,
            -open-2*gap,
            -open-3*gap);

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
        | PARASAIL_FLAG_BITS_32 | PARASAIL_FLAG_LANES_4;
#ifdef PARASAIL_TABLE
    result->flag |= PARASAIL_FLAG_TABLE;
#endif
#ifdef PARASAIL_ROWCOL
    result->flag |= PARASAIL_FLAG_ROWCOL;
#endif

    /* initialize heap variables */
    s1     = parasail_memalign_int32_t(16, s1Len+PAD);
    s2B    = parasail_memalign_int32_t(16, s2Len+PAD2);
    _H_pr  = parasail_memalign_int32_t(16, s2Len+PAD2);
    _HM_pr = parasail_memalign_int32_t(16, s2Len+PAD2);
    _HS_pr = parasail_memalign_int32_t(16, s2Len+PAD2);
    _HL_pr = parasail_memalign_int32_t(16, s2Len+PAD2);
    _F_pr  = parasail_memalign_int32_t(16, s2Len+PAD2);
    _FM_pr = parasail_memalign_int32_t(16, s2Len+PAD2);
    _FS_pr = parasail_memalign_int32_t(16, s2Len+PAD2);
    _FL_pr = parasail_memalign_int32_t(16, s2Len+PAD2);
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
        simde__m128i case1 = vZero;
        simde__m128i case2 = vZero;
        simde__m128i vNH = vZero;
        simde__m128i vNM = vZero;
        simde__m128i vNS = vZero;
        simde__m128i vNL = vZero;
        simde__m128i vWH = vZero;
        simde__m128i vWM = vZero;
        simde__m128i vWS = vZero;
        simde__m128i vWL = vZero;
        simde__m128i vE = vNegInf0;
        simde__m128i vE_opn = vNegInf;
        simde__m128i vE_ext = vNegInf;
        simde__m128i vEM = vZero;
        simde__m128i vES = vZero;
        simde__m128i vEL = vZero;
        simde__m128i vF = vNegInf0;
        simde__m128i vF_opn = vNegInf;
        simde__m128i vF_ext = vNegInf;
        simde__m128i vFM = vZero;
        simde__m128i vFS = vZero;
        simde__m128i vFL = vZero;
        simde__m128i vJ = vJreset;
        simde__m128i vs1 = simde_mm_set_epi32(
                s1[i+0],
                s1[i+1],
                s1[i+2],
                s1[i+3]);
        simde__m128i vs2 = vNegInf;
        const int * const restrict matrow0 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+0] : ((i+0 >= s1Len) ? s1Len-1 : i+0))];
        const int * const restrict matrow1 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+1] : ((i+1 >= s1Len) ? s1Len-1 : i+1))];
        const int * const restrict matrow2 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+2] : ((i+2 >= s1Len) ? s1Len-1 : i+2))];
        const int * const restrict matrow3 = &matrix->matrix[matrix->size * ((matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) ? s1[i+3] : ((i+3 >= s1Len) ? s1Len-1 : i+3))];
        vNH = simde_mm_insert_epi32(vNH, H_pr[-1], 3);
        vWH = simde_mm_insert_epi32(vWH, -open - i*gap, 3);
        H_pr[-1] = -open - (i+N)*gap;
        /* iterate over database sequence */
        for (j=0; j<s2Len+PAD; ++j) {
            simde__m128i vMat;
            simde__m128i vNWH = vNH;
            simde__m128i vNWM = vNM;
            simde__m128i vNWS = vNS;
            simde__m128i vNWL = vNL;
            vNH = simde_mm_srli_si128(vWH, 4);
            vNH = simde_mm_insert_epi32(vNH, H_pr[j], 3);
            vNM = simde_mm_srli_si128(vWM, 4);
            vNM = simde_mm_insert_epi32(vNM, HM_pr[j], 3);
            vNS = simde_mm_srli_si128(vWS, 4);
            vNS = simde_mm_insert_epi32(vNS, HS_pr[j], 3);
            vNL = simde_mm_srli_si128(vWL, 4);
            vNL = simde_mm_insert_epi32(vNL, HL_pr[j], 3);
            vF = simde_mm_srli_si128(vF, 4);
            vF = simde_mm_insert_epi32(vF, F_pr[j], 3);
            vFM = simde_mm_srli_si128(vFM, 4);
            vFM = simde_mm_insert_epi32(vFM, FM_pr[j], 3);
            vFS = simde_mm_srli_si128(vFS, 4);
            vFS = simde_mm_insert_epi32(vFS, FS_pr[j], 3);
            vFL = simde_mm_srli_si128(vFL, 4);
            vFL = simde_mm_insert_epi32(vFL, FL_pr[j], 3);
            vF_opn = simde_mm_sub_epi32(vNH, vOpen);
            vF_ext = simde_mm_sub_epi32(vF, vGap);
            vF = simde_mm_max_epi32(vF_opn, vF_ext);
            case1 = simde_mm_cmpgt_epi32(vF_opn, vF_ext);
            vFM = simde_mm_blendv_epi8(vFM, vNM, case1);
            vFS = simde_mm_blendv_epi8(vFS, vNS, case1);
            vFL = simde_mm_blendv_epi8(vFL, vNL, case1);
            vFL = simde_mm_add_epi32(vFL, vOne);
            vE_opn = simde_mm_sub_epi32(vWH, vOpen);
            vE_ext = simde_mm_sub_epi32(vE, vGap);
            vE = simde_mm_max_epi32(vE_opn, vE_ext);
            case1 = simde_mm_cmpgt_epi32(vE_opn, vE_ext);
            vEM = simde_mm_blendv_epi8(vEM, vWM, case1);
            vES = simde_mm_blendv_epi8(vES, vWS, case1);
            vEL = simde_mm_blendv_epi8(vEL, vWL, case1);
            vEL = simde_mm_add_epi32(vEL, vOne);
            vs2 = simde_mm_srli_si128(vs2, 4);
            vs2 = simde_mm_insert_epi32(vs2, s2[j], 3);
            vMat = simde_mm_set_epi32(
                    matrow0[s2[j-0]],
                    matrow1[s2[j-1]],
                    matrow2[s2[j-2]],
                    matrow3[s2[j-3]]
                    );
            vNWH = simde_mm_add_epi32(vNWH, vMat);
            vWH = simde_mm_max_epi32(vNWH, vE);
            vWH = simde_mm_max_epi32(vWH, vF);
            case1 = simde_mm_cmpeq_epi32(vWH, vNWH);
            case2 = simde_mm_cmpeq_epi32(vWH, vF);
            vWM = simde_mm_blendv_epi8(
                    simde_mm_blendv_epi8(vEM, vFM, case2),
                    simde_mm_add_epi32(vNWM,
                        simde_mm_and_si128(
                            simde_mm_cmpeq_epi32(vs1,vs2),
                            vOne)),
                    case1);
            vWS = simde_mm_blendv_epi8(
                    simde_mm_blendv_epi8(vES, vFS, case2),
                    simde_mm_add_epi32(vNWS,
                        simde_mm_and_si128(
                            simde_mm_cmpgt_epi32(vMat,vZero),
                            vOne)),
                    case1);
            vWL = simde_mm_blendv_epi8(
                    simde_mm_blendv_epi8(vEL, vFL, case2),
                    simde_mm_add_epi32(vNWL, vOne), case1);
            /* as minor diagonal vector passes across the j=-1 boundary,
             * assign the appropriate boundary conditions */
            {
                simde__m128i cond = simde_mm_cmpeq_epi32(vJ,vNegOne);
                vWH = simde_mm_blendv_epi8(vWH, vIBoundary, cond);
                vWM = simde_mm_andnot_si128(cond, vWM);
                vWS = simde_mm_andnot_si128(cond, vWS);
                vWL = simde_mm_andnot_si128(cond, vWL);
                vE = simde_mm_blendv_epi8(vE, vNegInf, cond);
                vEM = simde_mm_andnot_si128(cond, vEM);
                vES = simde_mm_andnot_si128(cond, vES);
                vEL = simde_mm_andnot_si128(cond, vEL);
            }
            /* cannot start checking sat until after J clears boundary */
            if (j > PAD) {
                vSaturationCheckMin = simde_mm_min_epi32(vSaturationCheckMin, vWH);
                vSaturationCheckMax = simde_mm_max_epi32(vSaturationCheckMax, vWH);
                vSaturationCheckMax = simde_mm_max_epi32(vSaturationCheckMax, vWM);
                vSaturationCheckMax = simde_mm_max_epi32(vSaturationCheckMax, vWS);
                vSaturationCheckMax = simde_mm_max_epi32(vSaturationCheckMax, vWL);
                vSaturationCheckMax = simde_mm_max_epi32(vSaturationCheckMax, vWL);
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
            H_pr[j-3] = (int32_t)simde_mm_extract_epi32(vWH,0);
            HM_pr[j-3] = (int32_t)simde_mm_extract_epi32(vWM,0);
            HS_pr[j-3] = (int32_t)simde_mm_extract_epi32(vWS,0);
            HL_pr[j-3] = (int32_t)simde_mm_extract_epi32(vWL,0);
            F_pr[j-3] = (int32_t)simde_mm_extract_epi32(vF,0);
            FM_pr[j-3] = (int32_t)simde_mm_extract_epi32(vFM,0);
            FS_pr[j-3] = (int32_t)simde_mm_extract_epi32(vFS,0);
            FL_pr[j-3] = (int32_t)simde_mm_extract_epi32(vFL,0);
            /* as minor diagonal vector passes across table, extract
               last table value at the i,j bound */
            {
                simde__m128i cond_valid_I = simde_mm_cmpeq_epi32(vI, vILimit1);
                simde__m128i cond_valid_J = simde_mm_cmpeq_epi32(vJ, vJLimit1);
                simde__m128i cond_all = simde_mm_and_si128(cond_valid_I, cond_valid_J);
                vMaxH = simde_mm_blendv_epi8(vMaxH, vWH, cond_all);
                vMaxM = simde_mm_blendv_epi8(vMaxM, vWM, cond_all);
                vMaxS = simde_mm_blendv_epi8(vMaxS, vWS, cond_all);
                vMaxL = simde_mm_blendv_epi8(vMaxL, vWL, cond_all);
            }
            vJ = simde_mm_add_epi32(vJ, vOne);
        }
        vI = simde_mm_add_epi32(vI, vN);
        vIBoundary = simde_mm_sub_epi32(vIBoundary, vGapN);
    }

    /* max in vMaxH */
    for (i=0; i<N; ++i) {
        int32_t value;
        value = (int32_t) simde_mm_extract_epi32(vMaxH, 3);
        if (value > score) {
            score = value;
            matches = (int32_t) simde_mm_extract_epi32(vMaxM, 3);
            similar = (int32_t) simde_mm_extract_epi32(vMaxS, 3);
            length= (int32_t) simde_mm_extract_epi32(vMaxL, 3);
        }
        vMaxH = simde_mm_slli_si128(vMaxH, 4);
        vMaxM = simde_mm_slli_si128(vMaxM, 4);
        vMaxS = simde_mm_slli_si128(vMaxS, 4);
        vMaxL = simde_mm_slli_si128(vMaxL, 4);
    }

    if (simde_mm_movemask_epi8(simde_mm_or_si128(
            simde_mm_cmplt_epi32(vSaturationCheckMin, vNegLimit),
            simde_mm_cmpgt_epi32(vSaturationCheckMax, vPosLimit)))) {
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


