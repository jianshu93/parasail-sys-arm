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

#if defined(_MSC_VER)
#include <intrin.h>
#else
#include <emmintrin.h>
#endif

#include "parasail.h"
#include "parasail/memory.h"
#include "parasail/internal_sse.h"


static inline __m128i _mm_blendv_epi8_rpl(__m128i a, __m128i b, __m128i mask) {
    a = _mm_andnot_si128(mask, a);
    a = _mm_or_si128(a, _mm_and_si128(mask, b));
    return a;
}

static inline __m128i _mm_max_epi8_rpl(__m128i a, __m128i b) {
    __m128i mask = _mm_cmpgt_epi8(a, b);
    a = _mm_and_si128(a, mask);
    b = _mm_andnot_si128(mask, b);
    return _mm_or_si128(a, b);
}

static inline int8_t _mm_extract_epi8_rpl(__m128i a, const int imm) {
    __m128i_8_t A;
    A.m = a;
    return A.v[imm];
}

static inline int8_t _mm_hmax_epi8_rpl(__m128i a) {
    a = _mm_max_epi8_rpl(a, _mm_srli_si128(a, 8));
    a = _mm_max_epi8_rpl(a, _mm_srli_si128(a, 4));
    a = _mm_max_epi8_rpl(a, _mm_srli_si128(a, 2));
    a = _mm_max_epi8_rpl(a, _mm_srli_si128(a, 1));
    return _mm_extract_epi8_rpl(a, 0);
}


#ifdef PARASAIL_TABLE
static inline void arr_store_si128(
        int *array,
        __m128i vH,
        int32_t t,
        int32_t seglen,
        int32_t d,
        int32_t dlen,
        int32_t bias)
{
    array[1LL*( 0*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH,  0) - bias;
    array[1LL*( 1*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH,  1) - bias;
    array[1LL*( 2*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH,  2) - bias;
    array[1LL*( 3*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH,  3) - bias;
    array[1LL*( 4*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH,  4) - bias;
    array[1LL*( 5*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH,  5) - bias;
    array[1LL*( 6*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH,  6) - bias;
    array[1LL*( 7*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH,  7) - bias;
    array[1LL*( 8*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH,  8) - bias;
    array[1LL*( 9*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH,  9) - bias;
    array[1LL*(10*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH, 10) - bias;
    array[1LL*(11*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH, 11) - bias;
    array[1LL*(12*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH, 12) - bias;
    array[1LL*(13*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH, 13) - bias;
    array[1LL*(14*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH, 14) - bias;
    array[1LL*(15*seglen+t)*dlen + d] = (int8_t)_mm_extract_epi8_rpl(vH, 15) - bias;
}
#endif

#ifdef PARASAIL_ROWCOL
static inline void arr_store_col(
        int *col,
        __m128i vH,
        int32_t t,
        int32_t seglen,
        int32_t bias)
{
    col[ 0*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH,  0) - bias;
    col[ 1*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH,  1) - bias;
    col[ 2*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH,  2) - bias;
    col[ 3*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH,  3) - bias;
    col[ 4*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH,  4) - bias;
    col[ 5*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH,  5) - bias;
    col[ 6*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH,  6) - bias;
    col[ 7*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH,  7) - bias;
    col[ 8*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH,  8) - bias;
    col[ 9*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH,  9) - bias;
    col[10*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH, 10) - bias;
    col[11*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH, 11) - bias;
    col[12*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH, 12) - bias;
    col[13*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH, 13) - bias;
    col[14*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH, 14) - bias;
    col[15*seglen+t] = (int8_t)_mm_extract_epi8_rpl(vH, 15) - bias;
}
#endif

#ifdef PARASAIL_TABLE
#define FNAME parasail_sw_table_striped_sse2_128_8
#define PNAME parasail_sw_table_striped_profile_sse2_128_8
#else
#ifdef PARASAIL_ROWCOL
#define FNAME parasail_sw_rowcol_striped_sse2_128_8
#define PNAME parasail_sw_rowcol_striped_profile_sse2_128_8
#else
#define FNAME parasail_sw_striped_sse2_128_8
#define PNAME parasail_sw_striped_profile_sse2_128_8
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
    if (matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) {
        PARASAIL_CHECK_NULL(s1);
        PARASAIL_CHECK_GT0(s1Len);
    }

    /* initialize local variables */
    profile = parasail_profile_create_sse_128_8(s1, s1Len, matrix);
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
    __m128i* restrict vProfile = NULL;
    __m128i* restrict pvHStore = NULL;
    __m128i* restrict pvHLoad = NULL;
    __m128i* restrict pvHMax = NULL;
    __m128i* restrict pvE = NULL;
    __m128i vGapO;
    __m128i vGapE;
    __m128i vZero;
    int8_t bias = 0;
    int8_t score = 0;
    __m128i vBias;
    __m128i vMaxH;
    __m128i vMaxHUnit;
    int8_t maxp = 0;
    __m128i insert_mask;
    /*int8_t stop = 0;*/
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
    vProfile = (__m128i*)profile->profile8.score;
    vGapO = _mm_set1_epi8(open);
    vGapE = _mm_set1_epi8(gap);
    vZero = _mm_set1_epi8(0);
    bias = INT8_MIN;
    score = bias;
    vBias = _mm_set1_epi8(bias);
    vMaxH = vBias;
    vMaxHUnit = vBias;
    maxp = INT8_MAX - (int8_t)(matrix->max+1);
    insert_mask = _mm_cmpgt_epi8(
            _mm_set_epi8(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1),
            vZero);
    /*stop = profile->stop == INT32_MAX ?  INT8_MAX : (int8_t)profile->stop-bias;*/

    /* initialize result */
#ifdef PARASAIL_TABLE
    result = parasail_result_new_table1(segLen*segWidth, s2Len);
#else
#ifdef PARASAIL_ROWCOL
    result = parasail_result_new_rowcol1(segLen*segWidth, s2Len);
#else
    result = parasail_result_new();
#endif
#endif
    if (!result) return NULL;

    /* set known flags */
    result->flag |= PARASAIL_FLAG_SW | PARASAIL_FLAG_STRIPED
        | PARASAIL_FLAG_BITS_8 | PARASAIL_FLAG_LANES_16;
#ifdef PARASAIL_TABLE
    result->flag |= PARASAIL_FLAG_TABLE;
#endif
#ifdef PARASAIL_ROWCOL
    result->flag |= PARASAIL_FLAG_ROWCOL;
#endif

    /* initialize heap variables */
    pvHStore = parasail_memalign___m128i(16, segLen);
    pvHLoad = parasail_memalign___m128i(16, segLen);
    pvHMax = parasail_memalign___m128i(16, segLen);
    pvE = parasail_memalign___m128i(16, segLen);

    /* validate heap variables */
    if (!pvHStore) return NULL;
    if (!pvHLoad) return NULL;
    if (!pvHMax) return NULL;
    if (!pvE) return NULL;

    /* initialize H and E */
    parasail_memset___m128i(pvHStore, vBias, segLen);
    parasail_memset___m128i(pvE, vBias, segLen);

    /* outer loop over database sequence */
    for (j=0; j<s2Len; ++j) {
        __m128i vE;
        __m128i vF;
        __m128i vH;
        const __m128i* vP = NULL;
        __m128i* pv = NULL;

        /* Initialize F value to 0.  Any errors to vH values will be
         * corrected in the Lazy_F loop.  */
        vF = vBias;

        /* load final segment of pvHStore and shift left by 1 bytes */
        vH = _mm_slli_si128(pvHStore[segLen - 1], 1);
        vH = _mm_blendv_epi8_rpl(vH, vBias, insert_mask);

        /* Correct part of the vProfile */
        vP = vProfile + matrix->mapper[(unsigned char)s2[j]] * segLen;

        if (end_ref == j-2) {
            /* Swap in the max buffer. */
            pv = pvHMax;
            pvHMax = pvHLoad;
            pvHLoad = pvHStore;
            pvHStore = pv;
        }
        else {
            /* Swap the 2 H buffers. */
            pv = pvHLoad;
            pvHLoad = pvHStore;
            pvHStore = pv;
        }

        /* inner loop to process the query sequence */
        for (i=0; i<segLen; ++i) {
            vH = _mm_adds_epi8(vH, _mm_load_si128(vP + i));
            vE = _mm_load_si128(pvE + i);

            /* Get max from vH, vE and vF. */
            vH = _mm_max_epi8_rpl(vH, vE);
            vH = _mm_max_epi8_rpl(vH, vF);
            /* Save vH values. */
            _mm_store_si128(pvHStore + i, vH);
#ifdef PARASAIL_TABLE
            arr_store_si128(result->tables->score_table, vH, i, segLen, j, s2Len, bias);
#endif
            vMaxH = _mm_max_epi8_rpl(vH, vMaxH);

            /* Update vE value. */
            vH = _mm_subs_epi8(vH, vGapO);
            vE = _mm_subs_epi8(vE, vGapE);
            vE = _mm_max_epi8_rpl(vE, vH);
            _mm_store_si128(pvE + i, vE);

            /* Update vF value. */
            vF = _mm_subs_epi8(vF, vGapE);
            vF = _mm_max_epi8_rpl(vF, vH);

            /* Load the next vH. */
            vH = _mm_load_si128(pvHLoad + i);
        }

        /* Lazy_F loop: has been revised to disallow adjecent insertion and
         * then deletion, so don't update E(i, i), learn from SWPS3 */
        for (k=0; k<segWidth; ++k) {
            vF = _mm_slli_si128(vF, 1);
            vF = _mm_blendv_epi8_rpl(vF, vBias, insert_mask);
            for (i=0; i<segLen; ++i) {
                vH = _mm_load_si128(pvHStore + i);
                vH = _mm_max_epi8_rpl(vH,vF);
                _mm_store_si128(pvHStore + i, vH);
#ifdef PARASAIL_TABLE
                arr_store_si128(result->tables->score_table, vH, i, segLen, j, s2Len, bias);
#endif
                vMaxH = _mm_max_epi8_rpl(vH, vMaxH);
                vH = _mm_subs_epi8(vH, vGapO);
                vF = _mm_subs_epi8(vF, vGapE);
                if (! _mm_movemask_epi8(_mm_cmpgt_epi8(vF, vH))) goto end;
                /*vF = _mm_max_epi8_rpl(vF, vH);*/
            }
        }
end:
        {
        }

#ifdef PARASAIL_ROWCOL
        /* extract last value from the column */
        {
            vH = _mm_load_si128(pvHStore + offset);
            for (k=0; k<position; ++k) {
                vH = _mm_slli_si128(vH, 1);
            }
            result->rowcols->score_row[j] = (int8_t) _mm_extract_epi8_rpl (vH, 15) - bias;
        }
#endif

        {
            __m128i vCompare = _mm_cmpgt_epi8(vMaxH, vMaxHUnit);
            if (_mm_movemask_epi8(vCompare)) {
                score = _mm_hmax_epi8_rpl(vMaxH);
                /* if score has potential to overflow, abort early */
                if (score > maxp) {
                    result->flag |= PARASAIL_FLAG_SATURATED;
                    break;
                }
                vMaxHUnit = _mm_set1_epi8(score);
                end_ref = j;
            }
        }

        /*if (score == stop) break;*/
    }

#ifdef PARASAIL_ROWCOL
    for (i=0; i<segLen; ++i) {
        __m128i vH = _mm_load_si128(pvHStore+i);
        arr_store_col(result->rowcols->score_col, vH, i, segLen, bias);
    }
#endif

    if (score == INT8_MAX) {
        result->flag |= PARASAIL_FLAG_SATURATED;
    }

    if (parasail_result_is_saturated(result)) {
        score = INT8_MAX;
        end_query = 0;
        end_ref = 0;
    }
    else {
        if (end_ref == j-1) {
            /* end_ref was the last store column */
            __m128i *pv = pvHMax;
            pvHMax = pvHStore;
            pvHStore = pv;
        }
        else if (end_ref == j-2) {
            /* end_ref was the last load column */
            __m128i *pv = pvHMax;
            pvHMax = pvHLoad;
            pvHLoad = pv;
        }
        /* Trace the alignment ending position on read. */
        {
            int8_t *t = (int8_t*)pvHMax;
            int32_t column_len = segLen * segWidth;
            end_query = s1Len - 1;
            for (i = 0; i<column_len; ++i, ++t) {
                if (*t == score) {
                    int32_t temp = i / segWidth + i % segWidth * segLen;
                    if (temp < end_query) {
                        end_query = temp;
                    }
                }
            }
        }
    }

    result->score = score - bias;
    result->end_query = end_query;
    result->end_ref = end_ref;

    parasail_free(pvE);
    parasail_free(pvHMax);
    parasail_free(pvHLoad);
    parasail_free(pvHStore);

    return result;
}

