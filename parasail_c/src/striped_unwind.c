#if defined(T)

#define D CONCAT3(int, T, _t)

static inline int* CONCAT(parasail_striped_unwind_, T) (
        int lena,
        int lenb,
        int segWidth,
        void *array_)
{
    int i;
    int j;
    int *ret = (int*)malloc(sizeof(int)*lena*lenb);
    D *array = (D*)array_;
    const int32_t segLen = (lena + segWidth - 1) / segWidth;
    int32_t column_len = segLen * segWidth;
    for (j=0; j<lenb; ++j) {
        for (i=0; i<column_len; ++i) {
            int32_t i_unwound = i / segWidth + i % segWidth * segLen;
            if (i_unwound < lena) {
                ret[i_unwound*lenb + j] = (int)array[j*column_len + i];
            }
        }
    }
    return ret;
}


#undef D

#else

#include "config.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parasail.h"
#include "parasail/memory.h"

#define CONCAT_(X, Y) X##Y
#define CONCAT(X, Y) CONCAT_(X, Y)
#define CONCAT3_(X, Y, Z) X##Y##Z
#define CONCAT3(X, Y, Z) CONCAT3_(X, Y, Z)

#define T 8
#include "striped_unwind.c"
#undef T

#define T 16
#include "striped_unwind.c"
#undef T

#define T 32
#include "striped_unwind.c"
#undef T

#define T 64
#include "striped_unwind.c"
#undef T

int* parasail_striped_unwind(
        int lena,
        int lenb,
        parasail_result_t *result,
        void *array)
{
    int *ret = NULL;

    PARASAIL_ASSERT((result->flag & PARASAIL_FLAG_STRIPED)
            || result->flag & PARASAIL_FLAG_SCAN);

    if (result->flag & PARASAIL_FLAG_LANES_1) {
        PARASAIL_ASSERT(0 && "internal error");
    }
    else if (result->flag & PARASAIL_FLAG_LANES_2) {
        if (result->flag & PARASAIL_FLAG_BITS_8) {
            ret = parasail_striped_unwind_8(lena, lenb, 2, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_16) {
            ret = parasail_striped_unwind_16(lena, lenb, 2, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_32) {
            ret = parasail_striped_unwind_32(lena, lenb, 2, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_64) {
            ret = parasail_striped_unwind_64(lena, lenb, 2, array);
        }
        else {
            PARASAIL_ASSERT(0 && "internal error");
        }
    }
    else if (result->flag & PARASAIL_FLAG_LANES_4) {
        if (result->flag & PARASAIL_FLAG_BITS_8) {
            ret = parasail_striped_unwind_8(lena, lenb, 4, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_16) {
            ret = parasail_striped_unwind_16(lena, lenb, 4, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_32) {
            ret = parasail_striped_unwind_32(lena, lenb, 4, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_64) {
            ret = parasail_striped_unwind_64(lena, lenb, 4, array);
        }
        else {
            PARASAIL_ASSERT(0 && "internal error");
        }
    }
    else if (result->flag & PARASAIL_FLAG_LANES_8) {
        if (result->flag & PARASAIL_FLAG_BITS_8) {
            ret = parasail_striped_unwind_8(lena, lenb, 8, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_16) {
            ret = parasail_striped_unwind_16(lena, lenb, 8, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_32) {
            ret = parasail_striped_unwind_32(lena, lenb, 8, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_64) {
            ret = parasail_striped_unwind_64(lena, lenb, 8, array);
        }
        else {
            PARASAIL_ASSERT(0 && "internal error");
        }
    }
    else if (result->flag & PARASAIL_FLAG_LANES_16) {
        if (result->flag & PARASAIL_FLAG_BITS_8) {
            ret = parasail_striped_unwind_8(lena, lenb, 16, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_16) {
            ret = parasail_striped_unwind_16(lena, lenb, 16, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_32) {
            ret = parasail_striped_unwind_32(lena, lenb, 16, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_64) {
            ret = parasail_striped_unwind_64(lena, lenb, 16, array);
        }
        else {
            PARASAIL_ASSERT(0 && "internal error");
        }
    }
    else if (result->flag & PARASAIL_FLAG_LANES_32) {
        if (result->flag & PARASAIL_FLAG_BITS_8) {
            ret = parasail_striped_unwind_8(lena, lenb, 32, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_16) {
            ret = parasail_striped_unwind_16(lena, lenb, 32, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_32) {
            ret = parasail_striped_unwind_32(lena, lenb, 32, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_64) {
            ret = parasail_striped_unwind_64(lena, lenb, 32, array);
        }
        else {
            PARASAIL_ASSERT(0 && "internal error");
        }
    }
    else if (result->flag & PARASAIL_FLAG_LANES_64) {
        if (result->flag & PARASAIL_FLAG_BITS_8) {
            ret = parasail_striped_unwind_8(lena, lenb, 64, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_16) {
            ret = parasail_striped_unwind_16(lena, lenb, 64, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_32) {
            ret = parasail_striped_unwind_32(lena, lenb, 64, array);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_64) {
            ret = parasail_striped_unwind_64(lena, lenb, 64, array);
        }
        else {
            PARASAIL_ASSERT(0 && "internal error");
        }
    }
    else {
        PARASAIL_ASSERT(0 && "internal error");
    }

    return ret;
}

#endif

