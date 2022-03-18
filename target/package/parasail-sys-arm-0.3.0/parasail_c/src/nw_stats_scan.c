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

#include "parasail.h"
#include "parasail/memory.h"

#define NEG_INF_32 (INT32_MIN/2)
#define MAX(a,b) ((a)>(b)?(a):(b))

#ifdef PARASAIL_TABLE
#define ENAME parasail_nw_stats_table_scan
#else
#ifdef PARASAIL_ROWCOL
#define ENAME parasail_nw_stats_rowcol_scan
#else
#define ENAME parasail_nw_stats_scan
#endif
#endif

parasail_result_t* ENAME(
        const char * const restrict _s1, const int _s1Len,
        const char * const restrict _s2, const int s2Len,
        const int open, const int gap, const parasail_matrix_t *matrix)
{
    /* declare local variables */
    parasail_result_t *result = NULL;
    int * restrict s1 = NULL;
    int * restrict s2 = NULL;
    int * restrict HB = NULL;
    int * restrict H = NULL;
    int * restrict HMB = NULL;
    int * restrict HM = NULL;
    int * restrict HSB = NULL;
    int * restrict HS = NULL;
    int * restrict HLB = NULL;
    int * restrict HL = NULL;
    int * restrict E = NULL;
    int * restrict EM = NULL;
    int * restrict ES = NULL;
    int * restrict EL = NULL;
    int * restrict HtB = NULL;
    int * restrict Ht = NULL;
    int * restrict HtMB = NULL;
    int * restrict HtM = NULL;
    int * restrict HtSB = NULL;
    int * restrict HtS = NULL;
    int * restrict HtLB = NULL;
    int * restrict HtL = NULL;
    int * restrict Ex = NULL;
    int i = 0;
    int j = 0;
    int s1Len = 0;

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
    s1Len = matrix->type == PARASAIL_MATRIX_TYPE_SQUARE ? _s1Len : matrix->length;

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
    result->flag |= PARASAIL_FLAG_NW | PARASAIL_FLAG_NOVEC_SCAN
        | PARASAIL_FLAG_STATS
        | PARASAIL_FLAG_BITS_INT | PARASAIL_FLAG_LANES_1;
#ifdef PARASAIL_TABLE
    result->flag |= PARASAIL_FLAG_TABLE;
#endif
#ifdef PARASAIL_ROWCOL
    result->flag |= PARASAIL_FLAG_ROWCOL;
#endif

    /* initialize heap variables */
    s1 = parasail_memalign_int(16, s1Len);
    s2 = parasail_memalign_int(16, s2Len);
    HB = parasail_memalign_int(16, s1Len+1);
    H  = HB+1;
    HMB = parasail_memalign_int(16, s1Len+1);
    HM  = HMB+1;
    HSB = parasail_memalign_int(16, s1Len+1);
    HS  = HSB+1;
    HLB = parasail_memalign_int(16, s1Len+1);
    HL  = HLB+1;
    E  = parasail_memalign_int(16, s1Len);
    EM = parasail_memalign_int(16, s1Len);
    ES = parasail_memalign_int(16, s1Len);
    EL = parasail_memalign_int(16, s1Len);
    HtB= parasail_memalign_int(16, s1Len+1);
    Ht = HtB+1;
    HtMB= parasail_memalign_int(16, s1Len+1);
    HtM = HtMB+1;
    HtSB= parasail_memalign_int(16, s1Len+1);
    HtS = HtSB+1;
    HtLB= parasail_memalign_int(16, s1Len+1);
    HtL = HtLB+1;
    Ex = parasail_memalign_int(16, s1Len);

    /* validate heap variables */
    if (!s1) return NULL;
    if (!s2) return NULL;
    if (!HB) return NULL;
    if (!HMB) return NULL;
    if (!HSB) return NULL;
    if (!HLB) return NULL;
    if (!E) return NULL;
    if (!EM) return NULL;
    if (!ES) return NULL;
    if (!EL) return NULL;
    if (!HtB) return NULL;
    if (!HtMB) return NULL;
    if (!HtSB) return NULL;
    if (!HtLB) return NULL;
    if (!Ex) return NULL;

    for (i=0; i<s1Len; ++i) {
        s1[i] = matrix->mapper[(unsigned char)_s1[i]];
    }
    for (j=0; j<s2Len; ++j) {
        s2[j] = matrix->mapper[(unsigned char)_s2[j]];
    }

    /* initialize H,HM,HS,HL */
    H[-1] = 0;
    HM[-1] = 0;
    HS[-1] = 0;
    HL[-1] = 0;
    Ht[-1] = 0;
    for (i=0; i<s1Len; ++i) {
        H[i] = -open - i*gap;
        HM[i] = 0;
        HS[i] = 0;
        HL[i] = 0;
    }

    /* initialize E */
    for (i=0; i<s1Len; ++i) {
        E[i] = NEG_INF_32;
        EM[i] = 0;
        ES[i] = 0;
        EL[i] = 0;
    }

    /* iterate over database */
    for (j=0; j<s2Len; ++j) {
        int Ft = NEG_INF_32;
        int FtM = 0;
        int FtS = 0;
        int FtL = 0;
        /* calculate E */
        for (i=0; i<s1Len; ++i) {
            int E_opn = H[i]-open;
            int E_ext = E[i]-gap;
            if (E_opn > E_ext) {
                E[i] = E_opn;
                EM[i] = HM[i];
                ES[i] = HS[i];
                EL[i] = HL[i];
            }
            else {
                E[i] = E_ext;
            }
            EL[i] += 1;
        }
        /* calculate Ht */
        Ht[-1] = -open -j*gap;
        for (i=0; i<s1Len; ++i) {
            int matval = matrix->type == PARASAIL_MATRIX_TYPE_SQUARE ?
                         matrix->matrix[matrix->size*s1[i]+s2[j]] :
                         matrix->matrix[matrix->size*i+s2[j]];
            int H_dag = H[i-1]+matval;
            Ex[i] = (E[i] > H_dag);
            if (H_dag >= E[i]) {
                Ht[i] = H_dag;
                HtM[i] = HM[i-1] + (s1[i]==s2[j]);
                HtS[i] = HS[i-1] + (matval > 0);
                HtL[i] = HL[i-1] + 1;
            }
            else {
                Ht[i] = E[i];
                HtM[i] = EM[i];
                HtS[i] = ES[i];
                HtL[i] = EL[i];
            }
        }
        /* calculate H,HM,HS,HL */
        for (i=0; i<s1Len; ++i) {
            int Ft_opn;
            int Ht_pre = Ht[i-1];
            int Ft_ext = Ft-gap;
            if (Ht_pre >= Ft_ext) {
                Ft = Ht_pre;
            }
            else {
                Ft = Ft_ext;
            }
            Ft_opn = Ft-open;
            if (H[i-1] > Ft_ext) {
                FtM = HM[i-1];
                FtS = HS[i-1];
                FtL = HL[i-1] + 1;
            }
            else {
                FtL = FtL + 1;
            }
            if (Ht[i] > Ft_opn) {
                H[i] = Ht[i];
                HM[i] = HtM[i];
                HS[i] = HtS[i];
                HL[i] = HtL[i];
            }
            else {
                H[i] = Ft_opn;
                if (Ht[i] == Ft_opn) {
                    if (Ex[i]) {
                        /* we favor F/up/del when F and E scores tie */
                        HM[i] = FtM;
                        HS[i] = FtS;
                        HL[i] = FtL;
                    }
                    else {
                        HM[i] = HtM[i];
                        HS[i] = HtS[i];
                        HL[i] = HtL[i];
                    }
                }
                else {
                    HM[i] = FtM;
                    HS[i] = FtS;
                    HL[i] = FtL;
                }
            }
#ifdef PARASAIL_TABLE
            result->stats->tables->score_table[1LL*i*s2Len + j] = H[i];
            result->stats->tables->matches_table[1LL*i*s2Len + j] = HM[i];
            result->stats->tables->similar_table[1LL*i*s2Len + j] = HS[i];
            result->stats->tables->length_table[1LL*i*s2Len + j] = HL[i];
#endif
        }
        H[-1] = -open - j*gap;
#ifdef PARASAIL_ROWCOL
        if (j == s2Len-1) {
            for (i=0; i<s1Len; ++i) {
                result->stats->rowcols->score_col[i] = H[i];
                result->stats->rowcols->matches_col[i] = HM[i];
                result->stats->rowcols->similar_col[i] = HS[i];
                result->stats->rowcols->length_col[i] = HL[i];
            }
        }
        result->stats->rowcols->score_row[j] = H[s1Len-1];
        result->stats->rowcols->matches_row[j] = HM[s1Len-1];
        result->stats->rowcols->similar_row[j] = HS[s1Len-1];
        result->stats->rowcols->length_row[j] = HL[s1Len-1];
#endif
    }

    result->score = H[s1Len-1];
    result->end_query = s1Len-1;
    result->end_ref = s2Len-1;
    result->stats->matches = HM[s1Len-1];
    result->stats->similar = HS[s1Len-1];
    result->stats->length = HL[s1Len-1];

    parasail_free(Ex);
    parasail_free(HtLB);
    parasail_free(HtSB);
    parasail_free(HtMB);
    parasail_free(HtB);
    parasail_free(EL);
    parasail_free(ES);
    parasail_free(EM);
    parasail_free(E);
    parasail_free(HLB);
    parasail_free(HSB);
    parasail_free(HMB);
    parasail_free(HB);
    parasail_free(s2);
    parasail_free(s1);

    return result;
}

