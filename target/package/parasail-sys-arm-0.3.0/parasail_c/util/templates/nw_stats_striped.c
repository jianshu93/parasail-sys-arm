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

#define SWAP(A,B) { %(VTYPE)s* tmp = A; A = B; B = tmp; }

%(FIXES)s

#ifdef PARASAIL_TABLE
static inline void arr_store_si%(BITS)s(
        int *array,
        %(VTYPE)s vH,
        %(INDEX)s t,
        %(INDEX)s seglen,
        %(INDEX)s d,
        %(INDEX)s dlen)
{
%(PRINTER)s
}
#endif

#ifdef PARASAIL_ROWCOL
static inline void arr_store_col(
        int *col,
        %(VTYPE)s vH,
        %(INDEX)s t,
        %(INDEX)s seglen)
{
%(PRINTER_ROWCOL)s
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME %(NAME_TABLE)s
#define PNAME %(PNAME_TABLE)s
#else
#ifdef PARASAIL_ROWCOL
#define FNAME %(NAME_ROWCOL)s
#define PNAME %(PNAME_ROWCOL)s
#else
#define FNAME %(NAME)s
#define PNAME %(PNAME)s
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
    profile = parasail_profile_create_stats_%(ISA)s_%(BITS)s_%(WIDTH)s(s1, s1Len, matrix);
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
    %(VTYPE)s* restrict vProfileM = NULL;
    %(VTYPE)s* restrict vProfileS = NULL;
    %(VTYPE)s* restrict pvHStore = NULL;
    %(VTYPE)s* restrict pvHLoad = NULL;
    %(VTYPE)s* restrict pvHMStore = NULL;
    %(VTYPE)s* restrict pvHMLoad = NULL;
    %(VTYPE)s* restrict pvHSStore = NULL;
    %(VTYPE)s* restrict pvHSLoad = NULL;
    %(VTYPE)s* restrict pvHLStore = NULL;
    %(VTYPE)s* restrict pvHLLoad = NULL;
    %(VTYPE)s* restrict pvE = NULL;
    %(VTYPE)s* restrict pvEM = NULL;
    %(VTYPE)s* restrict pvES = NULL;
    %(VTYPE)s* restrict pvEL = NULL;
    %(INT)s* restrict boundary = NULL;
    %(VTYPE)s vGapO;
    %(VTYPE)s vGapE;
    %(INT)s NEG_LIMIT = 0;
    %(INT)s POS_LIMIT = 0;
    %(VTYPE)s vZero;
    %(VTYPE)s vOne;
    %(INT)s score = 0;
    %(INT)s matches = 0;
    %(INT)s similar = 0;
    %(INT)s length = 0;
    %(VTYPE)s vNegLimit;
    %(VTYPE)s vPosLimit;
    %(VTYPE)s vSaturationCheckMin;
    %(VTYPE)s vSaturationCheckMax;
    parasail_result_t *result = NULL;

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
    vProfile  = (%(VTYPE)s*)profile->profile%(WIDTH)s.score;
    vProfileM = (%(VTYPE)s*)profile->profile%(WIDTH)s.matches;
    vProfileS = (%(VTYPE)s*)profile->profile%(WIDTH)s.similar;
    vGapO = %(VSET1)s(open);
    vGapE = %(VSET1)s(gap);
    NEG_LIMIT = (-open < matrix->min ? INT%(WIDTH)s_MIN + open : INT%(WIDTH)s_MIN - matrix->min) + 1;
    POS_LIMIT = INT%(WIDTH)s_MAX - matrix->max - 1;
    vZero = %(VSET0)s();
    vOne = %(VSET1)s(1);
    score = NEG_LIMIT;
    matches = 0;
    similar = 0;
    length = 0;
    vNegLimit = %(VSET1)s(NEG_LIMIT);
    vPosLimit = %(VSET1)s(POS_LIMIT);
    vSaturationCheckMin = vPosLimit;
    vSaturationCheckMax = vNegLimit;

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
    result->flag |= PARASAIL_FLAG_NW | PARASAIL_FLAG_STRIPED
        | PARASAIL_FLAG_STATS
        | PARASAIL_FLAG_BITS_%(WIDTH)s | PARASAIL_FLAG_LANES_%(LANES)s;
#ifdef PARASAIL_TABLE
    result->flag |= PARASAIL_FLAG_TABLE;
#endif
#ifdef PARASAIL_ROWCOL
    result->flag |= PARASAIL_FLAG_ROWCOL;
#endif

    /* initialize heap variables */
    pvHStore  = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHLoad   = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHMStore = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHMLoad  = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHSStore = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHSLoad  = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHLStore = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHLLoad  = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvE       = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvEM      = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvES      = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvEL      = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    boundary  = parasail_memalign_%(INT)s(%(ALIGNMENT)s, s2Len+1);

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

    parasail_memset_%(VTYPE)s(pvHMStore, vZero, segLen);
    parasail_memset_%(VTYPE)s(pvHSStore, vZero, segLen);
    parasail_memset_%(VTYPE)s(pvHLStore, vZero, segLen);
    parasail_memset_%(VTYPE)s(pvEM, vZero, segLen);
    parasail_memset_%(VTYPE)s(pvES, vZero, segLen);
    parasail_memset_%(VTYPE)s(pvEL, vOne, segLen);

%(INIT_H_AND_E)s

    /* initialize uppder boundary */
    {
        boundary[0] = 0;
        for (i=1; i<=s2Len; ++i) {
            int64_t tmp = -open-gap*(i-1);
            boundary[i] = tmp < INT%(WIDTH)s_MIN ? INT%(WIDTH)s_MIN : tmp;
        }
    }

    /* outer loop over database sequence */
    for (j=0; j<s2Len; ++j) {
        %(VTYPE)s vEF_opn;
        %(VTYPE)s vE;
        %(VTYPE)s vE_ext;
        %(VTYPE)s vEM;
        %(VTYPE)s vES;
        %(VTYPE)s vEL;
        %(VTYPE)s vF;
        %(VTYPE)s vF_ext;
        %(VTYPE)s vFM;
        %(VTYPE)s vFS;
        %(VTYPE)s vFL;
        %(VTYPE)s vH;
        %(VTYPE)s vH_dag;
        %(VTYPE)s vHM;
        %(VTYPE)s vHS;
        %(VTYPE)s vHL;
        const %(VTYPE)s* vP = NULL;
        const %(VTYPE)s* vPM = NULL;
        const %(VTYPE)s* vPS = NULL;

        /* Initialize F value to neg inf.  Any errors to vH values will
         * be corrected in the Lazy_F loop.  */
        vF = vNegLimit;
        vFM = vZero;
        vFS = vZero;
        vFL = vOne;

        /* load final segment of pvHStore and shift left by %(BYTES)s bytes */
        vH = %(VLOAD)s(&pvHStore[segLen - 1]);
        vHM = %(VLOAD)s(&pvHMStore[segLen - 1]);
        vHS = %(VLOAD)s(&pvHSStore[segLen - 1]);
        vHL = %(VLOAD)s(&pvHLStore[segLen - 1]);
        vH = %(VSHIFT)s(vH, %(BYTES)s);
        vHM = %(VSHIFT)s(vHM, %(BYTES)s);
        vHS = %(VSHIFT)s(vHS, %(BYTES)s);
        vHL = %(VSHIFT)s(vHL, %(BYTES)s);

        /* insert upper boundary condition */
        vH = %(VINSERT)s(vH, boundary[j], 0);

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
            %(VTYPE)s case1;
            %(VTYPE)s case2;

            vE = %(VLOAD)s(pvE+ i);
            vEM = %(VLOAD)s(pvEM+ i);
            vES = %(VLOAD)s(pvES+ i);
            vEL = %(VLOAD)s(pvEL+ i);

            /* Get max from vH, vE and vF. */
            vH_dag = %(VADD)s(vH, %(VLOAD)s(vP + i));
            vH = %(VMAX)s(vH_dag, vE);
            vH = %(VMAX)s(vH, vF);
            /* Save vH values. */
            %(VSTORE)s(pvHStore + i, vH);

            case1 = %(VCMPEQ)s(vH, vH_dag);
            case2 = %(VCMPEQ)s(vH, vF);

            /* calculate vM */
            vHM = %(VBLEND)s(
                    %(VBLEND)s(vEM, vFM, case2),
                    %(VADD)s(vHM, %(VLOAD)s(vPM + i)),
                    case1);
            %(VSTORE)s(pvHMStore + i, vHM);

            /* calculate vS */
            vHS = %(VBLEND)s(
                    %(VBLEND)s(vES, vFS, case2),
                    %(VADD)s(vHS, %(VLOAD)s(vPS + i)),
                    case1);
            %(VSTORE)s(pvHSStore + i, vHS);

            /* calculate vL */
            vHL = %(VBLEND)s(
                    %(VBLEND)s(vEL, vFL, case2),
                    %(VADD)s(vHL, vOne),
                    case1);
            %(VSTORE)s(pvHLStore + i, vHL);

            vSaturationCheckMin = %(VMIN)s(vSaturationCheckMin, vH);
            vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vH);
            vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vHM);
            vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vHS);
            vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vHL);
#ifdef PARASAIL_TABLE
            arr_store_si%(BITS)s(result->stats->tables->matches_table, vHM, i, segLen, j, s2Len);
            arr_store_si%(BITS)s(result->stats->tables->similar_table, vHS, i, segLen, j, s2Len);
            arr_store_si%(BITS)s(result->stats->tables->length_table, vHL, i, segLen, j, s2Len);
            arr_store_si%(BITS)s(result->stats->tables->score_table, vH, i, segLen, j, s2Len);
#endif
            vEF_opn = %(VSUB)s(vH, vGapO);

            /* Update vE value. */
            vE_ext = %(VSUB)s(vE, vGapE);
            vE = %(VMAX)s(vEF_opn, vE_ext);
            case1 = %(VCMPGT)s(vEF_opn, vE_ext);
            vEM = %(VBLEND)s(vEM, vHM, case1);
            vES = %(VBLEND)s(vES, vHS, case1);
            vEL = %(VBLEND)s(
                    %(VADD)s(vEL, vOne),
                    %(VADD)s(vHL, vOne),
                    case1);
            %(VSTORE)s(pvE + i, vE);
            %(VSTORE)s(pvEM + i, vEM);
            %(VSTORE)s(pvES + i, vES);
            %(VSTORE)s(pvEL + i, vEL);

            /* Update vF value. */
            vF_ext = %(VSUB)s(vF, vGapE);
            vF = %(VMAX)s(vEF_opn, vF_ext);
            case1 = %(VCMPGT)s(vEF_opn, vF_ext);
            vFM = %(VBLEND)s(vFM, vHM, case1);
            vFS = %(VBLEND)s(vFS, vHS, case1);
            vFL = %(VBLEND)s(
                    %(VADD)s(vFL, vOne),
                    %(VADD)s(vHL, vOne),
                    case1);

            /* Load the next vH. */
            vH = %(VLOAD)s(pvHLoad + i);
            vHM = %(VLOAD)s(pvHMLoad + i);
            vHS = %(VLOAD)s(pvHSLoad + i);
            vHL = %(VLOAD)s(pvHLLoad + i);
        }

        /* Lazy_F loop: has been revised to disallow adjecent insertion and
         * then deletion, so don't update E(i, i), learn from SWPS3 */
        for (k=0; k<segWidth; ++k) {
            %(VTYPE)s vHp = %(VLOAD)s(&pvHLoad[segLen - 1]);
            int64_t tmp = boundary[j+1]-open;
            %(INT)s tmp2 = tmp < INT%(WIDTH)s_MIN ? INT%(WIDTH)s_MIN : tmp;
            vHp = %(VSHIFT)s(vHp, %(BYTES)s);
            vF = %(VSHIFT)s(vF, %(BYTES)s);
            vFM = %(VSHIFT)s(vFM, %(BYTES)s);
            vFS = %(VSHIFT)s(vFS, %(BYTES)s);
            vFL = %(VSHIFT)s(vFL, %(BYTES)s);
            vHp = %(VINSERT)s(vHp, boundary[j], 0);
            vF = %(VINSERT)s(vF, tmp2, 0);
            vFL = %(VINSERT)s(vFL, 1, 0);
            for (i=0; i<segLen; ++i) {
                %(VTYPE)s case1;
                %(VTYPE)s case2;
                %(VTYPE)s cond;

                vHp = %(VADD)s(vHp, %(VLOAD)s(vP + i));
                vH = %(VLOAD)s(pvHStore + i);
                vH = %(VMAX)s(vH,vF);
                %(VSTORE)s(pvHStore + i, vH);
                case1 = %(VCMPEQ)s(vH, vHp);
                case2 = %(VCMPEQ)s(vH, vF);
                cond = %(VANDNOT)s(case1, case2);

                /* calculate vM */
                vHM = %(VLOAD)s(pvHMStore + i);
                vHM = %(VBLEND)s(vHM, vFM, cond);
                %(VSTORE)s(pvHMStore + i, vHM);

                /* calculate vS */
                vHS = %(VLOAD)s(pvHSStore + i);
                vHS = %(VBLEND)s(vHS, vFS, cond);
                %(VSTORE)s(pvHSStore + i, vHS);

                /* calculate vL */
                vHL = %(VLOAD)s(pvHLStore + i);
                vHL = %(VBLEND)s(vHL, vFL, cond);
                %(VSTORE)s(pvHLStore + i, vHL);

                vSaturationCheckMin = %(VMIN)s(vSaturationCheckMin, vH);
                vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vH);
                vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vHM);
                vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vHS);
                vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vHL);
#ifdef PARASAIL_TABLE
                arr_store_si%(BITS)s(result->stats->tables->matches_table, vHM, i, segLen, j, s2Len);
                arr_store_si%(BITS)s(result->stats->tables->similar_table, vHS, i, segLen, j, s2Len);
                arr_store_si%(BITS)s(result->stats->tables->length_table, vHL, i, segLen, j, s2Len);
                arr_store_si%(BITS)s(result->stats->tables->score_table, vH, i, segLen, j, s2Len);
#endif
                /* Update vF value. */
                vEF_opn = %(VSUB)s(vH, vGapO);
                vF_ext = %(VSUB)s(vF, vGapE);
                if (! %(VMOVEMASK)s(
                            %(VOR)s(
                                %(VCMPGT)s(vF_ext, vEF_opn),
                                %(VCMPEQ)s(vF_ext, vEF_opn))))
                    goto end;
                /*vF = %(VMAX)s(vEF_opn, vF_ext);*/
                vF = vF_ext;
                cond = %(VCMPGT)s(vEF_opn, vF_ext);
                vFM = %(VBLEND)s(vFM, vHM, cond);
                vFS = %(VBLEND)s(vFS, vHS, cond);
                vFL = %(VBLEND)s(
                        %(VADD)s(vFL, vOne),
                        %(VADD)s(vHL, vOne),
                        cond);
                vHp = %(VLOAD)s(pvHLoad + i);
            }
        }
end:
        {
        }

#ifdef PARASAIL_ROWCOL
        /* extract last value from the column */
        {
            vH = %(VLOAD)s(pvHStore + offset);
            vHM = %(VLOAD)s(pvHMStore + offset);
            vHS = %(VLOAD)s(pvHSStore + offset);
            vHL = %(VLOAD)s(pvHLStore + offset);
            for (k=0; k<position; ++k) {
                vH = %(VSHIFT)s (vH, %(BYTES)s);
                vHM = %(VSHIFT)s (vHM, %(BYTES)s);
                vHS = %(VSHIFT)s (vHS, %(BYTES)s);
                vHL = %(VSHIFT)s (vHL, %(BYTES)s);
            }
            result->stats->rowcols->score_row[j] = (%(INT)s) %(VEXTRACT)s (vH, %(LAST_POS)s);
            result->stats->rowcols->matches_row[j] = (%(INT)s) %(VEXTRACT)s (vHM, %(LAST_POS)s);
            result->stats->rowcols->similar_row[j] = (%(INT)s) %(VEXTRACT)s (vHS, %(LAST_POS)s);
            result->stats->rowcols->length_row[j] = (%(INT)s) %(VEXTRACT)s (vHL, %(LAST_POS)s);
        }
#endif
    }

#ifdef PARASAIL_ROWCOL
    for (i=0; i<segLen; ++i) {
        %(VTYPE)s vH = %(VLOAD)s(pvHStore+i);
        %(VTYPE)s vHM = %(VLOAD)s(pvHMStore+i);
        %(VTYPE)s vHS = %(VLOAD)s(pvHSStore+i);
        %(VTYPE)s vHL = %(VLOAD)s(pvHLStore+i);
        arr_store_col(result->stats->rowcols->score_col, vH, i, segLen);
        arr_store_col(result->stats->rowcols->matches_col, vHM, i, segLen);
        arr_store_col(result->stats->rowcols->similar_col, vHS, i, segLen);
        arr_store_col(result->stats->rowcols->length_col, vHL, i, segLen);
    }
#endif

    /* extract last value from the last column */
    {
        %(VTYPE)s vH = %(VLOAD)s(pvHStore + offset);
        %(VTYPE)s vHM = %(VLOAD)s(pvHMStore + offset);
        %(VTYPE)s vHS = %(VLOAD)s(pvHSStore + offset);
        %(VTYPE)s vHL = %(VLOAD)s(pvHLStore + offset);
        for (k=0; k<position; ++k) {
            vH = %(VSHIFT)s (vH, %(BYTES)s);
            vHM = %(VSHIFT)s (vHM, %(BYTES)s);
            vHS = %(VSHIFT)s (vHS, %(BYTES)s);
            vHL = %(VSHIFT)s (vHL, %(BYTES)s);
        }
        score = (%(INT)s) %(VEXTRACT)s (vH, %(LAST_POS)s);
        matches = (%(INT)s) %(VEXTRACT)s (vHM, %(LAST_POS)s);
        similar = (%(INT)s) %(VEXTRACT)s (vHS, %(LAST_POS)s);
        length = (%(INT)s) %(VEXTRACT)s (vHL, %(LAST_POS)s);
    }

    if (%(VMOVEMASK)s(%(VOR)s(
            %(VCMPLT)s(vSaturationCheckMin, vNegLimit),
            %(VCMPGT)s(vSaturationCheckMax, vPosLimit)))) {
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

