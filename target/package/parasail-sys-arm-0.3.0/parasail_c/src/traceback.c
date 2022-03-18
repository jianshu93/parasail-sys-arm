#include "config.h"

#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parasail.h"
#include "parasail/memory.h"

/* snprintf is available in VS 2015 and later */
#if defined(_MSC_VER) && _MSC_VER < 1900
#define snprintf _snprintf
#endif

static inline char missing_char(
        const char *seqA,
        int ai)
{
    return seqA == NULL ? '*' : seqA[ai];
}

static inline char match_char(
        const char *seqA,
        int ai,
        const char *seqB,
        int bi,
        const parasail_matrix_t *matrix,
        char match,
        char pos,
        char neg,
        int case_sensitive,
        const char *alphabet_aliases,
        size_t aliases_size)
{
    char a = missing_char(seqA, ai);
    char b = seqB[bi];
    int matches = case_sensitive ? (a == b) : (toupper(a) == toupper(b));
    if (NULL != alphabet_aliases) {
        size_t i;
        for (i=0; i<aliases_size; i+=1) {
            if (alphabet_aliases[i] == a) {
                matches |= alphabet_aliases[i+1] == b;
            }
            else if (alphabet_aliases[i+1] == a) {
                matches |= alphabet_aliases[i] == b;
            }
        }
    }
    if (matches) {
        return match;
    }
    else {
        int sub = 0;
        if (matrix->type == PARASAIL_MATRIX_TYPE_SQUARE) {
            sub = matrix->matrix[matrix->mapper[(unsigned char)a]*matrix->size + matrix->mapper[(unsigned char)b]];
        }
        else {
            sub = matrix->matrix[ai*matrix->size + matrix->mapper[(unsigned char)b]];
        }
        if (sub > 0) {
            return pos;
        }
        else {
            return neg;
        }
    }

    return 'X'; /* shouldn't happen */
}

#define CONCAT_(X, Y) X##Y
#define CONCAT(X, Y) CONCAT_(X, Y)
#define CONCAT3_(X, Y, Z) X##Y##Z
#define CONCAT3(X, Y, Z) CONCAT3_(X, Y, Z)
#define LOC_NOVEC int64_t loc = i*lenb + j;
#define LOC_STRIPED int64_t loc = j*segLen*segWidth + (i%segLen)*segWidth + (i/segLen);

#define T 8
#include "traceback_template.c"
#undef T

#define T 8
#define STRIPED
#include "traceback_template.c"
#undef T
#undef STRIPED

#define T 16
#include "traceback_template.c"
#undef T

#define T 16
#define STRIPED
#include "traceback_template.c"
#undef T
#undef STRIPED

#define T 32
#include "traceback_template.c"
#undef T

#define T 32
#define STRIPED
#include "traceback_template.c"
#undef T
#undef STRIPED

#define T 64
#include "traceback_template.c"
#undef T

#define T 64
#define STRIPED
#include "traceback_template.c"
#undef T
#undef STRIPED

parasail_traceback_t* parasail_result_get_traceback_extra(
        parasail_result_t *result,
        const char *seqA,
        int lena,
        const char *seqB,
        int lenb,
        const parasail_matrix_t *matrix,
        char match, char pos, char neg,
        int case_sensitive,
        const char *alphabet_aliases)
{
    PARASAIL_ASSERT(parasail_result_is_trace(result));

    if (result->flag & PARASAIL_FLAG_STRIPED
            || result->flag & PARASAIL_FLAG_SCAN) {
        if (result->flag & PARASAIL_FLAG_BITS_8) {
            return parasail_result_get_traceback_striped_8(
                    result, seqA, lena, seqB, lenb,
                    matrix, match, pos, neg,
                    case_sensitive, alphabet_aliases);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_16) {
            return parasail_result_get_traceback_striped_16(
                    result, seqA, lena, seqB, lenb,
                    matrix, match, pos, neg,
                    case_sensitive, alphabet_aliases);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_32) {
            return parasail_result_get_traceback_striped_32(
                    result, seqA, lena, seqB, lenb,
                    matrix, match, pos, neg,
                    case_sensitive, alphabet_aliases);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_64) {
            return parasail_result_get_traceback_striped_64(
                    result, seqA, lena, seqB, lenb,
                    matrix, match, pos, neg,
                    case_sensitive, alphabet_aliases);
        }
    }
    else {
        return parasail_result_get_traceback_8(
                result, seqA, lena, seqB, lenb,
                matrix, match, pos, neg,
                case_sensitive, alphabet_aliases);
    }

    return NULL; /* unreachable */
}

parasail_traceback_t* parasail_result_get_traceback(
        parasail_result_t *result,
        const char *seqA,
        int lena,
        const char *seqB,
        int lenb,
        const parasail_matrix_t *matrix,
        char match, char pos, char neg)
{
    return parasail_result_get_traceback_extra(
            result, seqA, lena, seqB, lenb, matrix, match, pos, neg, 0, NULL);
}

void parasail_traceback_free(parasail_traceback_t *traceback)
{
    free(traceback->query);
    free(traceback->comp);
    free(traceback->ref);
    free(traceback);
}

void parasail_traceback_generic_extra2(
        const char *seqA,
        int lena,
        const char *seqB,
        int lenb,
        const char *nameA,
        const char *nameB,
        const parasail_matrix_t *matrix,
        parasail_result_t *result,
        char match, char pos, char neg,
        int width,
        int name_width,
        int use_stats,
        int int_width,
        FILE *stream,
        int case_sensitive, 
        const char *alphabet_aliases)
{
    PARASAIL_ASSERT_NORETVAL(parasail_result_is_trace(result));

    if (result->flag & PARASAIL_FLAG_STRIPED
            || result->flag & PARASAIL_FLAG_SCAN) {
        if (result->flag & PARASAIL_FLAG_BITS_8) {
            parasail_traceback_striped_8(seqA, lena, seqB, lenb, nameA,
                    nameB, matrix, result, match, pos, neg, width,
                    name_width, use_stats, int_width, stream,
                    case_sensitive, alphabet_aliases);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_16) {
            parasail_traceback_striped_16(seqA, lena, seqB, lenb, nameA,
                    nameB, matrix, result, match, pos, neg, width,
                    name_width, use_stats, int_width, stream,
                    case_sensitive, alphabet_aliases);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_32) {
            parasail_traceback_striped_32(seqA, lena, seqB, lenb, nameA,
                    nameB, matrix, result, match, pos, neg, width,
                    name_width, use_stats, int_width, stream,
                    case_sensitive, alphabet_aliases);
        }
        else if (result->flag & PARASAIL_FLAG_BITS_64) {
            parasail_traceback_striped_64(seqA, lena, seqB, lenb, nameA,
                    nameB, matrix, result, match, pos, neg, width,
                    name_width, use_stats, int_width, stream,
                    case_sensitive, alphabet_aliases);
        }
    }
    else {
        parasail_traceback_8(seqA, lena, seqB, lenb, nameA, nameB,
                matrix, result, match, pos, neg, width, name_width,
                use_stats, int_width, stream,
                case_sensitive, alphabet_aliases);
    }
}

void parasail_traceback_generic_extra(
        const char *seqA,
        int lena,
        const char *seqB,
        int lenb,
        const char *nameA,
        const char *nameB,
        const parasail_matrix_t *matrix,
        parasail_result_t *result,
        char match, char pos, char neg,
        int width,
        int name_width,
        int use_stats,
        int int_width,
        FILE *stream)
{
    parasail_traceback_generic_extra2(seqA, lena, seqB, lenb, nameA, nameB,
            matrix, result, match, pos, neg, width, name_width, use_stats,
            int_width, stream, 0, NULL);
}

void parasail_traceback_generic(
        const char *seqA,
        int lena,
        const char *seqB,
        int lenb,
        const char *nameA,
        const char *nameB,
        const parasail_matrix_t *matrix,
        parasail_result_t *result,
        char match, char pos, char neg,
        int width,
        int name_width,
        int use_stats)
{
    parasail_traceback_generic_extra2(seqA, lena, seqB, lenb, nameA, nameB,
            matrix, result, match, pos, neg, width, name_width, use_stats,
            7, stdout, 0, NULL);
}

