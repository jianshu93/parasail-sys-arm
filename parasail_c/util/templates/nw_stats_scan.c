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
    %(VTYPE)s* restrict pvP = NULL;
    %(VTYPE)s* restrict pvPm = NULL;
    %(VTYPE)s* restrict pvPs = NULL;
    %(VTYPE)s* restrict pvE = NULL;
    %(VTYPE)s* restrict pvEM = NULL;
    %(VTYPE)s* restrict pvES = NULL;
    %(VTYPE)s* restrict pvEL = NULL;
    %(VTYPE)s* restrict pvH = NULL;
    %(VTYPE)s* restrict pvHM = NULL;
    %(VTYPE)s* restrict pvHS = NULL;
    %(VTYPE)s* restrict pvHL = NULL;
    %(VTYPE)s* restrict pvHMax = NULL;
    %(VTYPE)s* restrict pvHMMax = NULL;
    %(VTYPE)s* restrict pvHSMax = NULL;
    %(VTYPE)s* restrict pvHLMax = NULL;
    %(VTYPE)s* restrict pvGapper = NULL;
    %(VTYPE)s* restrict pvGapperL = NULL;
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
    %(VTYPE)s vNegInfFront;
    %(VTYPE)s vSegLenXgap;
    %(VTYPE)s vSegLen;
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
    pvP  = (%(VTYPE)s*)profile->profile%(WIDTH)s.score;
    pvPm = (%(VTYPE)s*)profile->profile%(WIDTH)s.matches;
    pvPs = (%(VTYPE)s*)profile->profile%(WIDTH)s.similar;
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
    vNegInfFront = vZero;
    vSegLen = %(VSHIFT)s(%(VSET1)s(segLen), %(BYTES)s);
    vNegInfFront = %(VINSERT)s(vNegInfFront, NEG_LIMIT, 0);
    vSegLenXgap = %(VADD)s(vNegInfFront,
            %(VSHIFT)s(%(VSET1)s(-segLen*gap), %(BYTES)s));

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
        | PARASAIL_FLAG_BITS_%(WIDTH)s | PARASAIL_FLAG_LANES_%(LANES)s;
#ifdef PARASAIL_TABLE
    result->flag |= PARASAIL_FLAG_TABLE;
#endif
#ifdef PARASAIL_ROWCOL
    result->flag |= PARASAIL_FLAG_ROWCOL;
#endif

    /* initialize heap variables */
    pvE  = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvEM = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvES = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvEL = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvH  = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHM = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHS = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHL = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHMax  = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHMMax = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHSMax = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvHLMax = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvGapper = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    pvGapperL = parasail_memalign_%(VTYPE)s(%(ALIGNMENT)s, segLen);
    boundary = parasail_memalign_%(INT)s(%(ALIGNMENT)s, s2Len+1);

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

    parasail_memset_%(VTYPE)s(pvHM, vZero, segLen);
    parasail_memset_%(VTYPE)s(pvHS, vZero, segLen);
    parasail_memset_%(VTYPE)s(pvHL, vZero, segLen);
    parasail_memset_%(VTYPE)s(pvE, vNegLimit, segLen);
    parasail_memset_%(VTYPE)s(pvEM, vZero, segLen);
    parasail_memset_%(VTYPE)s(pvES, vZero, segLen);
    parasail_memset_%(VTYPE)s(pvEL, vZero, segLen);
    {
        %(VTYPE)s vGapper = %(VSUB)s(vZero,vGapO);
        %(VTYPE)s vGapperL = vOne;
        for (i=segLen-1; i>=0; --i) {
            %(VSTORE)s(pvGapper+i, vGapper);
            %(VSTORE)s(pvGapperL+i, vGapperL);
            vGapper = %(VSUB)s(vGapper, vGapE);
            vGapperL = %(VADD)s(vGapperL, vOne);
        }
    }

%(INIT_H)s

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
        %(VTYPE)s vE;
        %(VTYPE)s vE_ext;
        %(VTYPE)s vE_opn;
        %(VTYPE)s vEM;
        %(VTYPE)s vES;
        %(VTYPE)s vEL;
        %(VTYPE)s vHt;
        %(VTYPE)s vHtM;
        %(VTYPE)s vHtS;
        %(VTYPE)s vHtL;
        %(VTYPE)s vF;
        %(VTYPE)s vF_ext;
        %(VTYPE)s vF_opn;
        %(VTYPE)s vFM;
        %(VTYPE)s vFS;
        %(VTYPE)s vFL;
        %(VTYPE)s vH;
        %(VTYPE)s vHM;
        %(VTYPE)s vHS;
        %(VTYPE)s vHL;
        %(VTYPE)s vHp;
        %(VTYPE)s vHpM;
        %(VTYPE)s vHpS;
        %(VTYPE)s vHpL;
        %(VTYPE)s *pvW;
        %(VTYPE)s vW;
        %(VTYPE)s *pvWM;
        %(VTYPE)s vWM;
        %(VTYPE)s *pvWS;
        %(VTYPE)s vWS;
        %(VTYPE)s case1;
        %(VTYPE)s case2;
        %(VTYPE)s vGapper;
        %(VTYPE)s vGapperL;

        /* calculate E */
        /* calculate Ht */
        /* calculate F and H first pass */
        vHp = %(VLOAD)s(pvH+(segLen-1));
        vHpM = %(VLOAD)s(pvHM+(segLen-1));
        vHpS = %(VLOAD)s(pvHS+(segLen-1));
        vHpL = %(VLOAD)s(pvHL+(segLen-1));
        vHp = %(VSHIFT)s(vHp, %(BYTES)s);
        vHpM = %(VSHIFT)s(vHpM, %(BYTES)s);
        vHpS = %(VSHIFT)s(vHpS, %(BYTES)s);
        vHpL = %(VSHIFT)s(vHpL, %(BYTES)s);
        vHp = %(VINSERT)s(vHp, boundary[j], 0);
        pvW = pvP + matrix->mapper[(unsigned char)s2[j]]*segLen;
        pvWM= pvPm+ matrix->mapper[(unsigned char)s2[j]]*segLen;
        pvWS= pvPs+ matrix->mapper[(unsigned char)s2[j]]*segLen;
        vHt = %(VSUB)s(vNegLimit, pvGapper[0]);
        vF = vNegLimit;
        vFM = vZero;
        vFS = vZero;
        vFL = vZero;
        for (i=0; i<segLen; ++i) {
            vH = %(VLOAD)s(pvH+i);
            vHM= %(VLOAD)s(pvHM+i);
            vHS= %(VLOAD)s(pvHS+i);
            vHL= %(VLOAD)s(pvHL+i);
            vE = %(VLOAD)s(pvE+i);
            vEM= %(VLOAD)s(pvEM+i);
            vES= %(VLOAD)s(pvES+i);
            vEL= %(VLOAD)s(pvEL+i);
            vW = %(VLOAD)s(pvW+i);
            vWM = %(VLOAD)s(pvWM+i);
            vWS = %(VLOAD)s(pvWS+i);
            vGapper = %(VLOAD)s(pvGapper+i);
            vGapperL = %(VLOAD)s(pvGapperL+i);
            vE_opn = %(VSUB)s(vH, vGapO);
            vE_ext = %(VSUB)s(vE, vGapE);
            case1 = %(VCMPGT)s(vE_opn, vE_ext);
            vE = %(VMAX)s(vE_opn, vE_ext);
            vEM = %(VBLEND)s(vEM, vHM, case1);
            vES = %(VBLEND)s(vES, vHS, case1);
            vEL = %(VBLEND)s(vEL, vHL, case1);
            vEL = %(VADD)s(vEL, vOne);
            vGapper = %(VADD)s(vHt, vGapper);
            case1 = %(VOR)s(
                    %(VCMPGT)s(vF, vGapper),
                    %(VCMPEQ)s(vF, vGapper));
            vF = %(VMAX)s(vF, vGapper);
            vFM = %(VBLEND)s(vHtM, vFM, case1);
            vFS = %(VBLEND)s(vHtS, vFS, case1);
            vFL = %(VBLEND)s(
                    %(VADD)s(vHtL, vGapperL),
                    vFL, case1);
            vHp = %(VADD)s(vHp, vW);
            vHpM = %(VADD)s(vHpM, vWM);
            vHpS = %(VADD)s(vHpS, vWS);
            vHpL = %(VADD)s(vHpL, vOne);
            case1 = %(VCMPGT)s(vE, vHp);
            vHt = %(VMAX)s(vE, vHp);
            vHtM = %(VBLEND)s(vHpM, vEM, case1);
            vHtS = %(VBLEND)s(vHpS, vES, case1);
            vHtL = %(VBLEND)s(vHpL, vEL, case1);
            %(VSTORE)s(pvE+i, vE);
            %(VSTORE)s(pvEM+i, vEM);
            %(VSTORE)s(pvES+i, vES);
            %(VSTORE)s(pvEL+i, vEL);
            %(VSTORE)s(pvH+i, vHp);
            %(VSTORE)s(pvHM+i, vHpM);
            %(VSTORE)s(pvHS+i, vHpS);
            %(VSTORE)s(pvHL+i, vHpL);
            vHp = vH;
            vHpM = vHM;
            vHpS = vHS;
            vHpL = vHL;
        }

        /* pseudo prefix scan on F and H */
        vHt = %(VSHIFT)s(vHt, %(BYTES)s);
        vHtM = %(VSHIFT)s(vHtM, %(BYTES)s);
        vHtS = %(VSHIFT)s(vHtS, %(BYTES)s);
        vHtL = %(VSHIFT)s(vHtL, %(BYTES)s);
        vHt = %(VINSERT)s(vHt, boundary[j+1], 0);
        vGapper = %(VLOAD)s(pvGapper);
        vGapperL = %(VLOAD)s(pvGapperL);
        vGapper = %(VADD)s(vHt, vGapper);
        case1 = %(VOR)s(
                %(VCMPGT)s(vGapper, vF),
                %(VCMPEQ)s(vGapper, vF));
        vF = %(VMAX)s(vF, vGapper);
        vFM = %(VBLEND)s(vFM, vHtM, case1);
        vFS = %(VBLEND)s(vFS, vHtS, case1);
        vFL = %(VBLEND)s(
                vFL,
                %(VADD)s(vHtL, vGapperL),
                case1);
        for (i=0; i<segWidth-2; ++i) {
            %(VTYPE)s vFt = %(VSHIFT)s(vF, %(BYTES)s);
            %(VTYPE)s vFtM = %(VSHIFT)s(vFM, %(BYTES)s);
            %(VTYPE)s vFtS = %(VSHIFT)s(vFS, %(BYTES)s);
            %(VTYPE)s vFtL = %(VSHIFT)s(vFL, %(BYTES)s);
            vFt = %(VADD)s(vFt, vSegLenXgap);
            case1 = %(VOR)s(
                    %(VCMPGT)s(vFt, vF),
                    %(VCMPEQ)s(vFt, vF));
            vF = %(VMAX)s(vF, vFt);
            vFM = %(VBLEND)s(vFM, vFtM, case1);
            vFS = %(VBLEND)s(vFS, vFtS, case1);
            vFL = %(VBLEND)s(
                    vFL,
                    %(VADD)s(vFtL, vSegLen),
                    case1);
        }

        /* calculate final H */
        vF = %(VSHIFT)s(vF, %(BYTES)s);
        vFM = %(VSHIFT)s(vFM, %(BYTES)s);
        vFS = %(VSHIFT)s(vFS, %(BYTES)s);
        vFL = %(VSHIFT)s(vFL, %(BYTES)s);
        vF = %(VADD)s(vF, vNegInfFront);
        case1 = %(VCMPGT)s(vF, vHt);
        vH = %(VMAX)s(vF, vHt);
        vHM = %(VBLEND)s(vHtM, vFM, case1);
        vHS = %(VBLEND)s(vHtS, vFS, case1);
        vHL = %(VBLEND)s(vHtL, vFL, case1);
        for (i=0; i<segLen; ++i) {
            vHp = %(VLOAD)s(pvH+i);
            vHpM = %(VLOAD)s(pvHM+i);
            vHpS = %(VLOAD)s(pvHS+i);
            vHpL = %(VLOAD)s(pvHL+i);
            vE = %(VLOAD)s(pvE+i);
            vEM = %(VLOAD)s(pvEM+i);
            vES = %(VLOAD)s(pvES+i);
            vEL = %(VLOAD)s(pvEL+i);
            vF_opn = %(VSUB)s(vH, vGapO);
            vF_ext = %(VSUB)s(vF, vGapE);
            vF = %(VMAX)s(vF_opn, vF_ext);
            case1 = %(VCMPGT)s(vF_opn, vF_ext);
            vFM = %(VBLEND)s(vFM, vHM, case1);
            vFS = %(VBLEND)s(vFS, vHS, case1);
            vFL = %(VBLEND)s(vFL, vHL, case1);
            vFL = %(VADD)s(vFL, vOne);
            vH = %(VMAX)s(vHp, vE);
            vH = %(VMAX)s(vH, vF);
            case1 = %(VCMPEQ)s(vH, vHp);
            case2 = %(VCMPEQ)s(vH, vF);
            vHM = %(VBLEND)s(
                    %(VBLEND)s(vEM, vFM, case2),
                    vHpM, case1);
            vHS = %(VBLEND)s(
                    %(VBLEND)s(vES, vFS, case2),
                    vHpS, case1);
            vHL = %(VBLEND)s(
                    %(VBLEND)s(vEL, vFL, case2),
                    vHpL, case1);
            %(VSTORE)s(pvH+i, vH);
            %(VSTORE)s(pvHM+i, vHM);
            %(VSTORE)s(pvHS+i, vHS);
            %(VSTORE)s(pvHL+i, vHL);
            vSaturationCheckMin = %(VMIN)s(vSaturationCheckMin, vH);
            vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vH);
            vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vHM);
            vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vHS);
            vSaturationCheckMax = %(VMAX)s(vSaturationCheckMax, vHL);
#ifdef PARASAIL_TABLE
            arr_store_si%(BITS)s(result->stats->tables->score_table, vH, i, segLen, j, s2Len);
            arr_store_si%(BITS)s(result->stats->tables->matches_table, vHM, i, segLen, j, s2Len);
            arr_store_si%(BITS)s(result->stats->tables->similar_table, vHS, i, segLen, j, s2Len);
            arr_store_si%(BITS)s(result->stats->tables->length_table, vHL, i, segLen, j, s2Len);
#endif
        } 

#ifdef PARASAIL_ROWCOL
        /* extract last value from the column */
        {
            vH = %(VLOAD)s(pvH + offset);
            vHM = %(VLOAD)s(pvHM + offset);
            vHS = %(VLOAD)s(pvHS + offset);
            vHL = %(VLOAD)s(pvHL + offset);
            for (k=0; k<position; ++k) {
                vH = %(VSHIFT)s(vH, %(BYTES)s);
                vHM = %(VSHIFT)s(vHM, %(BYTES)s);
                vHS = %(VSHIFT)s(vHS, %(BYTES)s);
                vHL = %(VSHIFT)s(vHL, %(BYTES)s);
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
        %(VTYPE)s vH = %(VLOAD)s(pvH+i);
        %(VTYPE)s vHM = %(VLOAD)s(pvHM+i);
        %(VTYPE)s vHS = %(VLOAD)s(pvHS+i);
        %(VTYPE)s vHL = %(VLOAD)s(pvHL+i);
        arr_store_col(result->stats->rowcols->score_col, vH, i, segLen);
        arr_store_col(result->stats->rowcols->matches_col, vHM, i, segLen);
        arr_store_col(result->stats->rowcols->similar_col, vHS, i, segLen);
        arr_store_col(result->stats->rowcols->length_col, vHL, i, segLen);
    }
#endif

    /* extract last value from the last column */
    {
        %(VTYPE)s vH = %(VLOAD)s(pvH + offset);
        %(VTYPE)s vHM = %(VLOAD)s(pvHM + offset);
        %(VTYPE)s vHS = %(VLOAD)s(pvHS + offset);
        %(VTYPE)s vHL = %(VLOAD)s(pvHL + offset);
        for (k=0; k<position; ++k) {
            vH = %(VSHIFT)s(vH, %(BYTES)s);
            vHM = %(VSHIFT)s(vHM, %(BYTES)s);
            vHS = %(VSHIFT)s(vHS, %(BYTES)s);
            vHL = %(VSHIFT)s(vHL, %(BYTES)s);
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

