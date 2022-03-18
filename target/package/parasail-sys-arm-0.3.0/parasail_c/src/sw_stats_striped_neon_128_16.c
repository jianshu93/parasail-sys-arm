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
#include "parasail/internal_neon.h"

#define FASTSTATS

#define SWAP(A,B) { simde__m128i* tmp = A; A = B; B = tmp; }
#define SWAP3(A,B,C) { simde__m128i* tmp = A; A = B; B = C; C = tmp; }

#define NEG_INF INT16_MIN


#ifdef PARASAIL_TABLE
static inline void arr_store(
        int *array,
        simde__m128i vH,
        int32_t t,
        int32_t seglen,
        int32_t d,
        int32_t dlen,
        int32_t bias)
{
    array[1LL*(0*seglen+t)*dlen + d] = (int16_t)simde_mm_extract_epi16(vH, 0) - bias;
    array[1LL*(1*seglen+t)*dlen + d] = (int16_t)simde_mm_extract_epi16(vH, 1) - bias;
    array[1LL*(2*seglen+t)*dlen + d] = (int16_t)simde_mm_extract_epi16(vH, 2) - bias;
    array[1LL*(3*seglen+t)*dlen + d] = (int16_t)simde_mm_extract_epi16(vH, 3) - bias;
    array[1LL*(4*seglen+t)*dlen + d] = (int16_t)simde_mm_extract_epi16(vH, 4) - bias;
    array[1LL*(5*seglen+t)*dlen + d] = (int16_t)simde_mm_extract_epi16(vH, 5) - bias;
    array[1LL*(6*seglen+t)*dlen + d] = (int16_t)simde_mm_extract_epi16(vH, 6) - bias;
    array[1LL*(7*seglen+t)*dlen + d] = (int16_t)simde_mm_extract_epi16(vH, 7) - bias;
}
#endif

#ifdef PARASAIL_ROWCOL
static inline void arr_store_col(
        int *col,
        simde__m128i vH,
        int32_t t,
        int32_t seglen,
        int32_t bias)
{
    col[0*seglen+t] = (int16_t)simde_mm_extract_epi16(vH, 0) - bias;
    col[1*seglen+t] = (int16_t)simde_mm_extract_epi16(vH, 1) - bias;
    col[2*seglen+t] = (int16_t)simde_mm_extract_epi16(vH, 2) - bias;
    col[3*seglen+t] = (int16_t)simde_mm_extract_epi16(vH, 3) - bias;
    col[4*seglen+t] = (int16_t)simde_mm_extract_epi16(vH, 4) - bias;
    col[5*seglen+t] = (int16_t)simde_mm_extract_epi16(vH, 5) - bias;
    col[6*seglen+t] = (int16_t)simde_mm_extract_epi16(vH, 6) - bias;
    col[7*seglen+t] = (int16_t)simde_mm_extract_epi16(vH, 7) - bias;
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_sw_stats_table_striped_neon_128_16
#define PNAME parasail_sw_stats_table_striped_profile_neon_128_16
#define INAME PNAME
#define STATIC
#else
#ifdef PARASAIL_ROWCOL
#define FNAME parasail_sw_stats_rowcol_striped_neon_128_16
#define PNAME parasail_sw_stats_rowcol_striped_profile_neon_128_16
#define INAME PNAME
#define STATIC
#else
#define FNAME parasail_sw_stats_striped_neon_128_16
#ifdef FASTSTATS
#define PNAME parasail_sw_stats_striped_profile_neon_128_16_internal
#define INAME parasail_sw_stats_striped_profile_neon_128_16
#define STATIC static
#else
#define PNAME parasail_sw_stats_striped_profile_neon_128_16
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
    profile = parasail_profile_create_stats_neon_128_16(s1, s1Len, matrix);
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
    simde__m128i* restrict vProfile = NULL;
    simde__m128i* restrict vProfileM = NULL;
    simde__m128i* restrict vProfileS = NULL;
    simde__m128i* restrict pvHStore = NULL;
    simde__m128i* restrict pvHLoad = NULL;
    simde__m128i* restrict pvHMStore = NULL;
    simde__m128i* restrict pvHMLoad = NULL;
    simde__m128i* restrict pvHSStore = NULL;
    simde__m128i* restrict pvHSLoad = NULL;
    simde__m128i* restrict pvHLStore = NULL;
    simde__m128i* restrict pvHLLoad = NULL;
    simde__m128i* restrict pvE = NULL;
    simde__m128i* restrict pvEM = NULL;
    simde__m128i* restrict pvES = NULL;
    simde__m128i* restrict pvEL = NULL;
    simde__m128i* restrict pvHMax = NULL;
    simde__m128i* restrict pvHMMax = NULL;
    simde__m128i* restrict pvHSMax = NULL;
    simde__m128i* restrict pvHLMax = NULL;
    simde__m128i vGapO;
    simde__m128i vGapE;
    simde__m128i vZero;
    simde__m128i vOne;
    int16_t bias = 0;
    int16_t score = 0;
    int16_t matches = 0;
    int16_t similar = 0;
    int16_t length = 0;
    simde__m128i vBias;
    simde__m128i vBias1;
    simde__m128i vMaxH;
    simde__m128i vMaxHUnit;
    simde__m128i insert_mask;
    simde__m128i vSaturationCheckMax;
    simde__m128i vPosLimit;
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
    segWidth = 8; /* number of values in vector unit */
    segLen = (s1Len + segWidth - 1) / segWidth;
#ifdef PARASAIL_ROWCOL
    offset = (s1Len - 1) % segLen;
    position = (segWidth - 1) - (s1Len - 1) / segLen;
#endif
    vProfile  = (simde__m128i*)profile->profile16.score;
    vProfileM = (simde__m128i*)profile->profile16.matches;
    vProfileS = (simde__m128i*)profile->profile16.similar;
    vGapO = simde_mm_set1_epi16(open);
    vGapE = simde_mm_set1_epi16(gap);
    vZero = simde_mm_setzero_si128();
    vOne = simde_mm_set1_epi16(1);
    bias = INT16_MIN;
    score = bias;
    matches = bias;
    similar = bias;
    length = bias;
    vBias = simde_mm_set1_epi16(bias);
    vBias1 = simde_mm_adds_epi16(vBias,vOne);
    vMaxH = vBias;
    vMaxHUnit = vBias;
    insert_mask = simde_mm_cmpgt_epi16(
            simde_mm_set_epi16(0,0,0,0,0,0,0,1),
            vZero);
    vSaturationCheckMax = vBias;
    vPosLimit = simde_mm_set1_epi16(INT16_MAX);
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
        | PARASAIL_FLAG_BITS_16 | PARASAIL_FLAG_LANES_8;
#ifdef PARASAIL_TABLE
    result->flag |= PARASAIL_FLAG_TABLE;
#endif
#ifdef PARASAIL_ROWCOL
    result->flag |= PARASAIL_FLAG_ROWCOL;
#endif

    /* initialize heap variables */
    pvHStore  = parasail_memalign_simde__m128i(16, segLen);
    pvHLoad   = parasail_memalign_simde__m128i(16, segLen);
    pvHMStore = parasail_memalign_simde__m128i(16, segLen);
    pvHMLoad  = parasail_memalign_simde__m128i(16, segLen);
    pvHSStore = parasail_memalign_simde__m128i(16, segLen);
    pvHSLoad  = parasail_memalign_simde__m128i(16, segLen);
    pvHLStore = parasail_memalign_simde__m128i(16, segLen);
    pvHLLoad  = parasail_memalign_simde__m128i(16, segLen);
    pvE       = parasail_memalign_simde__m128i(16, segLen);
    pvEM      = parasail_memalign_simde__m128i(16, segLen);
    pvES      = parasail_memalign_simde__m128i(16, segLen);
    pvEL      = parasail_memalign_simde__m128i(16, segLen);
    pvHMax    = parasail_memalign_simde__m128i(16, segLen);
    pvHMMax   = parasail_memalign_simde__m128i(16, segLen);
    pvHSMax   = parasail_memalign_simde__m128i(16, segLen);
    pvHLMax   = parasail_memalign_simde__m128i(16, segLen);

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

    parasail_memset_simde__m128i(pvHStore, vBias, segLen);
    parasail_memset_simde__m128i(pvHMStore, vBias, segLen);
    parasail_memset_simde__m128i(pvHSStore, vBias, segLen);
    parasail_memset_simde__m128i(pvHLStore, vBias, segLen);
    parasail_memset_simde__m128i(pvE, vBias, segLen);
    parasail_memset_simde__m128i(pvEM, vBias, segLen);
    parasail_memset_simde__m128i(pvES, vBias, segLen);
    parasail_memset_simde__m128i(pvEL, vBias1, segLen);

    /* outer loop over database sequence */
    for (j=0; j<s2Len; ++j) {
        simde__m128i vEF_opn;
        simde__m128i vE;
        simde__m128i vE_ext;
        simde__m128i vEM;
        simde__m128i vES;
        simde__m128i vEL;
        simde__m128i vF;
        simde__m128i vF_ext;
        simde__m128i vFM;
        simde__m128i vFS;
        simde__m128i vFL;
        simde__m128i vH;
        simde__m128i vH_dag;
        simde__m128i vHM;
        simde__m128i vHS;
        simde__m128i vHL;
        const simde__m128i* vP = NULL;
        const simde__m128i* vPM = NULL;
        const simde__m128i* vPS = NULL;

        /* Initialize F value to 0.  Any errors to vH values will be
         * corrected in the Lazy_F loop. */
        vF = vBias;
        vFM = vBias;
        vFS = vBias;
        vFL = vBias1;

        /* load final segment of pvHStore and shift left by 2 bytes */
        vH = simde_mm_load_si128(&pvHStore[segLen - 1]);
        vHM = simde_mm_load_si128(&pvHMStore[segLen - 1]);
        vHS = simde_mm_load_si128(&pvHSStore[segLen - 1]);
        vHL = simde_mm_load_si128(&pvHLStore[segLen - 1]);
        vH = simde_mm_slli_si128(vH, 2);
        vHM = simde_mm_slli_si128(vHM, 2);
        vHS = simde_mm_slli_si128(vHS, 2);
        vHL = simde_mm_slli_si128(vHL, 2);
        vH = simde_mm_blendv_epi8(vH, vBias, insert_mask);
        vHM = simde_mm_blendv_epi8(vHM, vBias, insert_mask);
        vHS = simde_mm_blendv_epi8(vHS, vBias, insert_mask);
        vHL = simde_mm_blendv_epi8(vHL, vBias, insert_mask);

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
            simde__m128i cond_zero;
            simde__m128i case1;
            simde__m128i case2;

            vE = simde_mm_load_si128(pvE+ i);
            vEM = simde_mm_load_si128(pvEM+ i);
            vES = simde_mm_load_si128(pvES+ i);
            vEL = simde_mm_load_si128(pvEL+ i);

            /* Get max from vH, vE and vF. */
            vH_dag = simde_mm_adds_epi16(vH, simde_mm_load_si128(vP + i));
            /*vH = simde_mm_max_epi16(vH_dag, vBias);*/
            vH = simde_mm_max_epi16(vH_dag, vE);
            vH = simde_mm_max_epi16(vH, vF);
            /* Save vH values. */
            simde_mm_store_si128(pvHStore + i, vH);
            cond_zero = simde_mm_cmpeq_epi16(vH, vBias);

            case1 = simde_mm_cmpeq_epi16(vH, vH_dag);
            case2 = simde_mm_cmpeq_epi16(vH, vF);

            /* calculate vM */
            vHM = simde_mm_blendv_epi8(
                    simde_mm_blendv_epi8(vEM, vFM, case2),
                    simde_mm_adds_epi16(vHM, simde_mm_load_si128(vPM + i)), case1);
            vHM = simde_mm_blendv_epi8(vHM, vBias, cond_zero);
            simde_mm_store_si128(pvHMStore + i, vHM);

            /* calculate vS */
            vHS = simde_mm_blendv_epi8(
                    simde_mm_blendv_epi8(vES, vFS, case2),
                    simde_mm_adds_epi16(vHS, simde_mm_load_si128(vPS + i)), case1);
            vHS = simde_mm_blendv_epi8(vHS, vBias, cond_zero);
            simde_mm_store_si128(pvHSStore + i, vHS);

            /* calculate vL */
            vHL = simde_mm_blendv_epi8(
                    simde_mm_blendv_epi8(vEL, vFL, case2),
                    simde_mm_adds_epi16(vHL, vOne), case1);
            vHL = simde_mm_blendv_epi8(vHL, vBias, cond_zero);
            simde_mm_store_si128(pvHLStore + i, vHL);

            vSaturationCheckMax = simde_mm_max_epi16(vSaturationCheckMax, vHM);
            vSaturationCheckMax = simde_mm_max_epi16(vSaturationCheckMax, vHS);
            vSaturationCheckMax = simde_mm_max_epi16(vSaturationCheckMax, vHL);
#ifdef PARASAIL_TABLE
            arr_store(result->stats->tables->matches_table, vHM, i, segLen, j, s2Len, bias);
            arr_store(result->stats->tables->similar_table, vHS, i, segLen, j, s2Len, bias);
            arr_store(result->stats->tables->length_table, vHL, i, segLen, j, s2Len, bias);
            arr_store(result->stats->tables->score_table, vH, i, segLen, j, s2Len, bias);
#endif
            vMaxH = simde_mm_max_epi16(vH, vMaxH);
            vEF_opn = simde_mm_subs_epi16(vH, vGapO);

            /* Update vE value. */
            vE_ext = simde_mm_subs_epi16(vE, vGapE);
            vE = simde_mm_max_epi16(vEF_opn, vE_ext);
            case1 = simde_mm_cmpgt_epi16(vEF_opn, vE_ext);
            vEM = simde_mm_blendv_epi8(vEM, vHM, case1);
            vES = simde_mm_blendv_epi8(vES, vHS, case1);
            vEL = simde_mm_blendv_epi8(
                    simde_mm_adds_epi16(vEL, vOne),
                    simde_mm_adds_epi16(vHL, vOne),
                    case1);
            simde_mm_store_si128(pvE + i, vE);
            simde_mm_store_si128(pvEM + i, vEM);
            simde_mm_store_si128(pvES + i, vES);
            simde_mm_store_si128(pvEL + i, vEL);

            /* Update vF value. */
            vF_ext = simde_mm_subs_epi16(vF, vGapE);
            vF = simde_mm_max_epi16(vEF_opn, vF_ext);
            case1 = simde_mm_cmpgt_epi16(vEF_opn, vF_ext);
            vFM = simde_mm_blendv_epi8(vFM, vHM, case1);
            vFS = simde_mm_blendv_epi8(vFS, vHS, case1);
            vFL = simde_mm_blendv_epi8(
                    simde_mm_adds_epi16(vFL, vOne),
                    simde_mm_adds_epi16(vHL, vOne),
                    case1);

            /* Load the next vH. */
            vH = simde_mm_load_si128(pvHLoad + i);
            vHM = simde_mm_load_si128(pvHMLoad + i);
            vHS = simde_mm_load_si128(pvHSLoad + i);
            vHL = simde_mm_load_si128(pvHLLoad + i);
        }

        /* Lazy_F loop: has been revised to disallow adjecent insertion and
         * then deletion, so don't update E(i, i), learn from SWPS3 */
        for (k=0; k<segWidth; ++k) {
            simde__m128i vHp = simde_mm_load_si128(&pvHLoad[segLen - 1]);
            vHp = simde_mm_slli_si128(vHp, 2);
            vF = simde_mm_slli_si128(vF, 2);
            vFM = simde_mm_slli_si128(vFM, 2);
            vFS = simde_mm_slli_si128(vFS, 2);
            vFL = simde_mm_slli_si128(vFL, 2);
            vHp = simde_mm_blendv_epi8(vHp, vBias, insert_mask);
            vF = simde_mm_blendv_epi8(vF, vBias, insert_mask);
            vFM = simde_mm_blendv_epi8(vFM, vBias, insert_mask);
            vFS = simde_mm_blendv_epi8(vFS, vBias, insert_mask);
            vFL = simde_mm_blendv_epi8(vFL, vBias1, insert_mask);
            for (i=0; i<segLen; ++i) {
                simde__m128i case1;
                simde__m128i case2;
                simde__m128i cond;

                vHp = simde_mm_adds_epi16(vHp, simde_mm_load_si128(vP + i));
                vH = simde_mm_load_si128(pvHStore + i);
                vH = simde_mm_max_epi16(vH, vF);
                simde_mm_store_si128(pvHStore + i, vH);
                case1 = simde_mm_cmpeq_epi16(vH, vHp);
                case2 = simde_mm_cmpeq_epi16(vH, vF);
                cond = simde_mm_andnot_si128(case1, case2);

                /* calculate vM */
                vHM = simde_mm_load_si128(pvHMStore + i);
                vHM = simde_mm_blendv_epi8(vHM, vFM, cond);
                simde_mm_store_si128(pvHMStore + i, vHM);

                /* calculate vS */
                vHS = simde_mm_load_si128(pvHSStore + i);
                vHS = simde_mm_blendv_epi8(vHS, vFS, cond);
                simde_mm_store_si128(pvHSStore + i, vHS);

                /* calculate vL */
                vHL = simde_mm_load_si128(pvHLStore + i);
                vHL = simde_mm_blendv_epi8(vHL, vFL, cond);
                simde_mm_store_si128(pvHLStore + i, vHL);

                vSaturationCheckMax = simde_mm_max_epi16(vSaturationCheckMax, vHM);
                vSaturationCheckMax = simde_mm_max_epi16(vSaturationCheckMax, vHS);
                vSaturationCheckMax = simde_mm_max_epi16(vSaturationCheckMax, vHL);
#ifdef PARASAIL_TABLE
                arr_store(result->stats->tables->matches_table, vHM, i, segLen, j, s2Len, bias);
                arr_store(result->stats->tables->similar_table, vHS, i, segLen, j, s2Len, bias);
                arr_store(result->stats->tables->length_table, vHL, i, segLen, j, s2Len, bias);
                arr_store(result->stats->tables->score_table, vH, i, segLen, j, s2Len, bias);
#endif
                vMaxH = simde_mm_max_epi16(vH, vMaxH);
                /* Update vF value. */
                vEF_opn = simde_mm_subs_epi16(vH, vGapO);
                vF_ext = simde_mm_subs_epi16(vF, vGapE);
                if (! simde_mm_movemask_epi8(
                            simde_mm_or_si128(
                                simde_mm_cmpgt_epi16(vF_ext, vEF_opn),
                                simde_mm_and_si128(
                                    simde_mm_cmpeq_epi16(vF_ext, vEF_opn),
                                    simde_mm_cmpgt_epi16(vF_ext, vBias)))))
                    goto end;
                /*vF = simde_mm_max_epi16(vEF_opn, vF_ext);*/
                vF = vF_ext;
                cond = simde_mm_cmpgt_epi16(vEF_opn, vF_ext);
                vFM = simde_mm_blendv_epi8(vFM, vHM, cond);
                vFS = simde_mm_blendv_epi8(vFS, vHS, cond);
                vFL = simde_mm_blendv_epi8(
                        simde_mm_adds_epi16(vFL, vOne),
                        simde_mm_adds_epi16(vHL, vOne),
                        cond);
                vHp = simde_mm_load_si128(pvHLoad + i);
            }
        }
end:
        {
        }

#ifdef PARASAIL_ROWCOL
        /* extract last value from the column */
        {
            vH = simde_mm_load_si128(pvHStore + offset);
            vHM = simde_mm_load_si128(pvHMStore + offset);
            vHS = simde_mm_load_si128(pvHSStore + offset);
            vHL = simde_mm_load_si128(pvHLStore + offset);
            for (k=0; k<position; ++k) {
                vH = simde_mm_slli_si128(vH, 2);
                vHM = simde_mm_slli_si128(vHM, 2);
                vHS = simde_mm_slli_si128(vHS, 2);
                vHL = simde_mm_slli_si128(vHL, 2);
            }
            result->stats->rowcols->score_row[j] = (int16_t) simde_mm_extract_epi16 (vH, 7) - bias;
            result->stats->rowcols->matches_row[j] = (int16_t) simde_mm_extract_epi16 (vHM, 7) - bias;
            result->stats->rowcols->similar_row[j] = (int16_t) simde_mm_extract_epi16 (vHS, 7) - bias;
            result->stats->rowcols->length_row[j] = (int16_t) simde_mm_extract_epi16 (vHL, 7) - bias;
        }
#endif

        {
            simde__m128i vCompare = simde_mm_cmpgt_epi16(vMaxH, vMaxHUnit);
            if (simde_mm_movemask_epi8(vCompare)) {
                score = simde_mm_hmax_epi16(vMaxH);
                /* if score has potential to overflow, abort early */
                if (score > maxp) {
                    result->flag |= PARASAIL_FLAG_SATURATED;
                    break;
                }
                vMaxHUnit = simde_mm_set1_epi16(score);
                end_ref = j;
            }
        }
    }

#ifdef PARASAIL_ROWCOL
    for (i=0; i<segLen; ++i) {
        simde__m128i vH = simde_mm_load_si128(pvHStore+i);
        simde__m128i vHM = simde_mm_load_si128(pvHMStore+i);
        simde__m128i vHS = simde_mm_load_si128(pvHSStore+i);
        simde__m128i vHL = simde_mm_load_si128(pvHLStore+i);
        arr_store_col(result->stats->rowcols->score_col, vH, i, segLen, bias);
        arr_store_col(result->stats->rowcols->matches_col, vHM, i, segLen, bias);
        arr_store_col(result->stats->rowcols->similar_col, vHS, i, segLen, bias);
        arr_store_col(result->stats->rowcols->length_col, vHL, i, segLen, bias);
    }
#endif

    if (score == INT16_MAX
            || simde_mm_movemask_epi8(simde_mm_cmpeq_epi16(vSaturationCheckMax,vPosLimit))) {
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
    parasail_result_t *result = parasail_sw_striped_profile_neon_128_16(profile, s2, s2Len, open, gap);
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
        profile_new = parasail_profile_create_neon_128_16(
                s1_new, s1Len_new, matrix);
        profile_new->stop = result->score;
        result_new = parasail_sw_striped_profile_neon_128_16(
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
        profile_final = parasail_profile_create_stats_neon_128_16(
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
        profile_final = parasail_profile_create_stats_neon_128_16(
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


