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

%(HEADER)s

#include "parasail.h"
#include "parasail/memory.h"
#include "parasail/internal_%(ISA)s.h"

#define SG_TRACE
#define SG_SUFFIX %(SUFFIX)s
#define SG_SUFFIX_PROF %(SUFFIX_PROF)s
#include "sg_helper.h"

#define SWAP(A,B) { %(VTYPE)s* tmp = A; A = B; B = tmp; }

%(FIXES)s

static inline void arr_store(
        %(VTYPE)s *array,
        %(VTYPE)s vH,
        %(INDEX)s t,
        %(INDEX)s seglen,
        %(INDEX)s d)
{
    %(VSTORE)s(array + (1LL*d*seglen+t), vH);
}

static inline %(VTYPE)s arr_load(
        %(VTYPE)s *array,
        %(INDEX)s t,
        %(INDEX)s seglen,
        %(INDEX)s d)
{
    return %(VLOAD)s(array + (1LL*d*seglen+t));
}

#define FNAME %(NAME_TRACE)s
#define PNAME %(PNAME_TRACE)s

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
    if (matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) {
        PARASAIL_CHECK_NULL(s1);
        PARASAIL_CHECK_GT0(s1Len);
    }

    /* initialize local variables */
    profile = parasail_profile_create_%(ISA)s_%(BITS)s_%(WIDTH)s(s1, s1Len, matrix);
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
    %(INDEX)s i = 0;
    %(INDEX)s j = 0;
    %(INDEX)s k = 0;
    %(INDEX)s s1Len = 0;
    %(INDEX)s end_query = 0;
    %(INDEX)s end_ref = 0;
    const parasail_matrix_t *matrix = NULL;
    %(INDEX)s segWidth = 0;
    %(INDEX)s segLen = 0;
    %(INDEX)s offset = 0;
    %(INDEX)s position = 0;
    %(VTYPE)s* restrict vProfile = NULL;
    %(VTYPE)s* restrict pvHStore = NULL;
    %(VTYPE)s* restrict pvHLoad = NULL;
    %(VTYPE)s* restrict pvE = NULL;
    %(VTYPE)s* restrict pvEaStore = NULL;
    %(VTYPE)s* restrict pvEaLoad = NULL;
    %(VTYPE)s* restrict pvHT = NULL;
    %(INT)s* restrict boundary = NULL;
    %(VTYPE)s vGapO;
    %(VTYPE)s vGapE;
    %(INT)s NEG_LIMIT = 0;
    %(INT)s POS_LIMIT = 0;
    %(INT)s score = 0;
    %(VTYPE)s vNegLimit;
    %(VTYPE)s vPosLimit;
    %(VTYPE)s vSaturationCheckMin;
    %(VTYPE)s vSaturationCheckMax;
    %(VTYPE)s vMaxH;
    %(VTYPE)s vPosMask;
    parasail_result_t *result = NULL;
    %(VTYPE)s vTIns;
    %(VTYPE)s vTDel;
    %(VTYPE)s vTDiag;
    %(VTYPE)s vTDiagE;
    %(VTYPE)s vTInsE;
    %(VTYPE)s vTDiagF;
    %(VTYPE)s vTDelF;
    %(VTYPE)s vTMask;
    %(VTYPE)s vFTMask;

    /* validate inputs */
    PARASAIL_CHECK_NULL(profile);
    PARASAIL_CHECK_NULL(profile->profile%(WIDTH)s.score);
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
    segWidth = %(LANES)s; /* number of values in vector unit */
    segLen = (s1Len + segWidth - 1) / segWidth;
    offset = (s1Len - 1) %% segLen;
    position = (segWidth - 1) - (s1Len - 1) / segLen;
    vProfile = (%(VTYPE)s*)profile->profile%(WIDTH)s.score;
    vGapO = %(VSET1)s(open);
    vGapE = %(VSET1)s(gap);
    NEG_LIMIT = (-open < matrix->min ? INT%(WIDTH)s_MIN + open : INT%(WIDTH)s_MIN - matrix->min) + 1;
    POS_LIMIT = INT%(WIDTH)s_MAX - matrix->max - 1;
    score = NEG_LIMIT;
    vNegLimit = %(VSET1)s(NEG_LIMIT);
    vPosLimit = %(VSET1)s(POS_LIMIT);
    vSaturationCheckMin = vPosLimit;
    vSaturationCheckMax = vNegLimit;
    vMaxH = vNegLimit;
    vPosMask = %(VCMPEQ)s(%(VSET1)s(position),
            %(VSET)s(%(POSITION_MASK)s));
    vTIns  = %(VSET1)s(PARASAIL_INS);
    vTDel  = %(VSET1)s(PARASAIL_DEL);
    vTDiag = %(VSET1)s(PARASAIL_DIAG);
    vTDiagE= %(VSET1)s(PARASAIL_DIAG_E);
    vTInsE = %(VSET1)s(PARASAIL_INS_E);
    vTDiagF= %(VSET1)s(PARASAIL_DIAG_F);
    vTDelF = %(VSET1)s(PARASAIL_DEL_F);
    vTMask = %(VSET1)s(PARASAIL_ZERO_MASK);
    vFTMask= %(VSET1)s(PARASAIL_F_MASK);

    /* initialize result */
    result = parasail_result_new_trace(segLen, s2Len, %(ALIGNMENT)s, sizeof(%(VTYPE)s));
    if (!result) return NULL;

    /* set known flags */
    result->flag |= PARASAIL_FLAG_SG | PARASAIL_FLAG_STRIPED
        | PARASAIL_FLAG_TRACE
        | PARASAIL_FLAG_BITS_%(WIDTH)s | PARASAIL_FLAG_LANES_%(LANES)s;
    result->flag |= s1_beg ? PARASAIL_FLAG_SG_S1_BEG : 0;
    result->flag |= s1_end ? PARASAIL_FLAG_SG_S1_END : 0;
    result->flag |= s2_beg ? PARASAIL_FLAG_SG_S2_BEG : 0;
    result->flag |= s2_end ? PARASAIL_FLAG_SG_S2_END : 0;

    /* initialize heap variables */
    pvHStore = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHLoad  = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvE      = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvEaStore= parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvEaLoad = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHT     = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    boundary = parasail_memalign_%(INT)s(%(ALIGNMENT)s, s2Len+1);

    /* validate heap variables */
    if (!pvHStore) return NULL;
    if (!pvHLoad) return NULL;
    if (!pvE) return NULL;
    if (!pvEaStore) return NULL;
    if (!pvEaLoad) return NULL;
    if (!pvHT) return NULL;
    if (!boundary) return NULL;

%(INIT_H_AND_E)s

    /* initialize uppder boundary */
    {
        boundary[0] = 0;
        for (i=1; i<=s2Len; ++i) {
            int64_t tmp = s2_beg ? 0 : (-open-gap*(i-1));
            boundary[i] = tmp < INT%(WIDTH)s_MIN ? INT%(WIDTH)s_MIN : tmp;
        }
    }

    for (i=0; i<segLen; ++i) {
        arr_store(result->trace->trace_table, vTDiagE, i, segLen, 0);
    }

    /* outer loop over database sequence */
    for (j=0; j<s2Len; ++j) {
        %(VTYPE)s vEF_opn;
        %(VTYPE)s vE;
        %(VTYPE)s vE_ext;
        %(VTYPE)s vF;
        %(VTYPE)s vF_ext;
        %(VTYPE)s vFa;
        %(VTYPE)s vFa_ext;
        %(VTYPE)s vH;
        %(VTYPE)s vH_dag;
        const %(VTYPE)s* vP = NULL;

        /* Initialize F value to -inf.  Any errors to vH values will be
         * corrected in the Lazy_F loop. */
        vF = vNegLimit;

        /* load final segment of pvHStore and shift left by %(BYTES)s bytes */
        vH = %(VLOAD)s(&pvHStore[segLen - 1]);
        vH = %(VSHIFT)s(vH, %(BYTES)s);

        /* insert upper boundary condition */
        vH = %(VINSERT)s(vH, boundary[j], 0);

        /* Correct part of the vProfile */
        vP = vProfile + matrix->mapper[(unsigned char)s2[j]] * segLen;

        /* Swap the 2 H buffers. */
        SWAP(pvHLoad, pvHStore)
        SWAP(pvEaLoad, pvEaStore)

        /* inner loop to process the query sequence */
        for (i=0; i<segLen; ++i) {
            vE = %(VLOAD)s(pvE + i);

            /* Get max from vH, vE and vF. */
            vH_dag = %(VADD)s(vH, %(VLOAD)s(vP + i));
            vH = %(VMAX)s(vH_dag, vE);
            vH = %(VMAX)s(vH, vF);
            /* Save vH values. */
            %(VSTORE)s(pvHStore + i, vH);
            vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vH);
            vSaturationCheckMin = %(VMIN)s(vSaturationCheckMin, vH);
            vSaturationCheckMin = %(VMIN)s(vSaturationCheckMin, vE);
            vSaturationCheckMin = %(VMIN)s(vSaturationCheckMin, vF);

            {
                %(VTYPE)s vTAll = arr_load(result->trace->trace_table, i, segLen, j);
                %(VTYPE)s case1 = %(VCMPEQ)s(vH, vH_dag);
                %(VTYPE)s case2 = %(VCMPEQ)s(vH, vF);
                %(VTYPE)s vT = %(VBLEND)s(
                        %(VBLEND)s(vTIns, vTDel, case2),
                        vTDiag, case1);
                %(VSTORE)s(pvHT + i, vT);
                vT = %(VOR)s(vT, vTAll);
                arr_store(result->trace->trace_table, vT, i, segLen, j);
            }

            vEF_opn = %(VSUB)s(vH, vGapO);

            /* Update vE value. */
            vE_ext = %(VSUB)s(vE, vGapE);
            vE = %(VMAX)s(vEF_opn, vE_ext);
            %(VSTORE)s(pvE + i, vE);
            {
                %(VTYPE)s vEa = %(VLOAD)s(pvEaLoad + i);
                %(VTYPE)s vEa_ext = %(VSUB)s(vEa, vGapE);
                vEa = %(VMAX)s(vEF_opn, vEa_ext);
                %(VSTORE)s(pvEaStore + i, vEa);
                if (j+1<s2Len) {
                    %(VTYPE)s cond = %(VCMPGT)s(vEF_opn, vEa_ext);
                    %(VTYPE)s vT = %(VBLEND)s(vTInsE, vTDiagE, cond);
                    arr_store(result->trace->trace_table, vT, i, segLen, j+1);
                }
            }

            /* Update vF value. */
            vF_ext = %(VSUB)s(vF, vGapE);
            vF = %(VMAX)s(vEF_opn, vF_ext);
            if (i+1<segLen) {
                %(VTYPE)s vTAll = arr_load(result->trace->trace_table, i+1, segLen, j);
                %(VTYPE)s cond = %(VCMPGT)s(vEF_opn, vF_ext);
                %(VTYPE)s vT = %(VBLEND)s(vTDelF, vTDiagF, cond);
                vT = %(VOR)s(vT, vTAll);
                arr_store(result->trace->trace_table, vT, i+1, segLen, j);
            }

            /* Load the next vH. */
            vH = %(VLOAD)s(pvHLoad + i);
        }

        /* Lazy_F loop: has been revised to disallow adjecent insertion and
         * then deletion, so don't update E(i, i), learn from SWPS3 */
        vFa_ext = vF_ext;
        vFa = vF;
        for (k=0; k<segWidth; ++k) {
            int64_t tmp = s2_beg ? -open : (boundary[j+1]-open);
            %(INT)s tmp2 = tmp < INT%(WIDTH)s_MIN ? INT%(WIDTH)s_MIN : tmp;
            %(VTYPE)s vHp = %(VLOAD)s(&pvHLoad[segLen - 1]);
            vHp = %(VSHIFT)s(vHp, %(BYTES)s);
            vHp = %(VINSERT)s(vHp, boundary[j], 0);
            vEF_opn = %(VSHIFT)s(vEF_opn, %(BYTES)s);
            vEF_opn = %(VINSERT)s(vEF_opn, tmp2, 0);
            vF_ext = %(VSHIFT)s(vF_ext, %(BYTES)s);
            vF_ext = %(VINSERT)s(vF_ext, NEG_LIMIT, 0);
            vF = %(VSHIFT)s(vF, %(BYTES)s);
            vF = %(VINSERT)s(vF, tmp2, 0);
            vFa_ext = %(VSHIFT)s(vFa_ext, %(BYTES)s);
            vFa_ext = %(VINSERT)s(vFa_ext, NEG_LIMIT, 0);
            vFa = %(VSHIFT)s(vFa, %(BYTES)s);
            vFa = %(VINSERT)s(vFa, tmp2, 0);
            for (i=0; i<segLen; ++i) {
                vH = %(VLOAD)s(pvHStore + i);
                vH = %(VMAX)s(vH,vF);
                %(VSTORE)s(pvHStore + i, vH);
                vSaturationCheckMin = %(VMIN)s(vSaturationCheckMin, vH);
                vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vH);
                {
                    %(VTYPE)s vTAll;
                    %(VTYPE)s vT;
                    %(VTYPE)s case1;
                    %(VTYPE)s case2;
                    %(VTYPE)s cond;
                    vHp = %(VADD)s(vHp, %(VLOAD)s(vP + i));
                    case1 = %(VCMPEQ)s(vH, vHp);
                    case2 = %(VCMPEQ)s(vH, vF);
                    cond = %(VANDNOT)s(case1,case2);
                    vTAll = arr_load(result->trace->trace_table, i, segLen, j);
                    vT = %(VLOAD)s(pvHT + i);
                    vT = %(VBLEND)s(vT, vTDel, cond);
                    %(VSTORE)s(pvHT + i, vT);
                    vTAll = %(VAND)s(vTAll, vTMask);
                    vTAll = %(VOR)s(vTAll, vT);
                    arr_store(result->trace->trace_table, vTAll, i, segLen, j);
                }
                /* Update vF value. */
                {
                    %(VTYPE)s vTAll = arr_load(result->trace->trace_table, i, segLen, j);
                    %(VTYPE)s cond = %(VCMPGT)s(vEF_opn, vFa_ext);
                    %(VTYPE)s vT = %(VBLEND)s(vTDelF, vTDiagF, cond);
                    vTAll = %(VAND)s(vTAll, vFTMask);
                    vTAll = %(VOR)s(vTAll, vT);
                    arr_store(result->trace->trace_table, vTAll, i, segLen, j);
                }
                vEF_opn = %(VSUB)s(vH, vGapO);
                vF_ext = %(VSUB)s(vF, vGapE);
                {
                    %(VTYPE)s vEa = %(VLOAD)s(pvEaLoad + i);
                    %(VTYPE)s vEa_ext = %(VSUB)s(vEa, vGapE);
                    vEa = %(VMAX)s(vEF_opn, vEa_ext);
                    %(VSTORE)s(pvEaStore + i, vEa);
                    if (j+1<s2Len) {
                        %(VTYPE)s cond = %(VCMPGT)s(vEF_opn, vEa_ext);
                        %(VTYPE)s vT = %(VBLEND)s(vTInsE, vTDiagE, cond);
                        arr_store(result->trace->trace_table, vT, i, segLen, j+1);
                    }
                }
                if (! %(VMOVEMASK)s(
                            %(VOR)s(
                                %(VCMPGT)s(vF_ext, vEF_opn),
                                %(VCMPEQ)s(vF_ext, vEF_opn))))
                    goto end;
                /*vF = %(VMAX)s(vEF_opn, vF_ext);*/
                vF = vF_ext;
                vFa_ext = %(VSUB)s(vFa, vGapE);
                vFa = %(VMAX)s(vEF_opn, vFa_ext);
                vHp = %(VLOAD)s(pvHLoad + i);
            }
        }
end:
        {
            /* extract vector containing last value from the column */
            %(VTYPE)s vCompare;
            vH = %(VLOAD)s(pvHStore + offset);
            vCompare = %(VAND)s(vPosMask, %(VCMPGT)s(vH, vMaxH));
            vMaxH = %(VMAX)s(vH, vMaxH);
            if (%(VMOVEMASK)s(vCompare)) {
                end_ref = j;
            }
        }
    }

    /* max last value from all columns */
    if (s2_end)
    {
        for (k=0; k<position; ++k) {
            vMaxH = %(VSHIFT)s(vMaxH, %(BYTES)s);
        }
        score = (%(INT)s) %(VEXTRACT)s(vMaxH, %(LAST_POS)s);
        end_query = s1Len-1;
    }

    /* max of last column */
    if (s1_end)
    {
        /* Trace the alignment ending position on read. */
        %(INT)s *t = (%(INT)s*)pvHStore;
        %(INDEX)s column_len = segLen * segWidth;
        for (i = 0; i<column_len; ++i, ++t) {
            %(INDEX)s temp = i / segWidth + i %% segWidth * segLen;
            if (temp >= s1Len) continue;
            if (*t > score) {
                score = *t;
                end_query = temp;
                end_ref = s2Len-1;
            }
            else if (*t == score && end_ref == s2Len-1 && temp < end_query) {
                end_query = temp;
            }
        }
    }

    if (!s1_end && !s2_end) {
        /* extract last value from the last column */
        {
            %(VTYPE)s vH = %(VLOAD)s(pvHStore + offset);
            for (k=0; k<position; ++k) {
                vH = %(VSHIFT)s(vH, %(BYTES)s);
            }
            score = (%(INT)s) %(VEXTRACT)s (vH, %(LAST_POS)s);
            end_ref = s2Len - 1;
            end_query = s1Len - 1;
        }
    }

    if (%(VMOVEMASK)s(%(VOR)s(
            %(VCMPLT)s(vSaturationCheckMin, vNegLimit),
            %(VCMPGT)s(vSaturationCheckMax, vPosLimit)))) {
        result->flag |= PARASAIL_FLAG_SATURATED;
        score = 0;
        end_query = 0;
        end_ref = 0;
    }

    result->score = score;
    result->end_query = end_query;
    result->end_ref = end_ref;

    parasail_free(boundary);
    parasail_free(pvHT);
    parasail_free(pvEaLoad);
    parasail_free(pvEaStore);
    parasail_free(pvE);
    parasail_free(pvHLoad);
    parasail_free(pvHStore);

    return result;
}

SG_IMPL_ALL
SG_IMPL_PROF_ALL

