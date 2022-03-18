/**
 * @file
 *
 * @author jeffrey.daily@gmail.com
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 *
 * This file was converted to C code from the raw file found at
 * ftp://ftp.cbi.pku.edu.cn/pub/software/blast/matrices/PAM140, the
 * Center for Bioinformatics, Peking University, China.
 */
#ifndef _PARASAIL_PAM140_H_
#define _PARASAIL_PAM140_H_

#include "parasail.h"
#include "pam_map.h"

#ifdef __cplusplus
extern "C" {
#endif

/* # */
/* # This matrix was produced by "pam" Version 1.0.6 [28-Jul-93] */
/* # */
/* # PAM 140 substitution matrix, scale = ln(2)/2 = 0.346574 */
/* # */
/* # Expected score = -1.35, Entropy = 0.820 bits */
/* # */
/* # Lowest score = -8, Highest score = 12 */
/* # */

static const int parasail_pam140_[] = {
/*        A   R   N   D   C   Q   E   G   H   I   L   K   M   F   P   S   T   W   Y   V   B   Z   X   * */
/* A */   3, -2,  0,  0, -2, -1,  0,  1, -2, -1, -2, -2, -2, -4,  1,  1,  1, -6, -4,  0,  0,  0, -1, -8,
/* R */  -2,  6, -1, -3, -4,  1, -2, -4,  1, -2, -4,  3, -1, -5, -1, -1, -2,  1, -5, -3, -2, -1, -1, -8,
/* N */   0, -1,  3,  2, -4,  0,  1,  0,  2, -2, -3,  1, -2, -4, -1,  1,  0, -4, -2, -2,  3,  1, -1, -8,
/* D */   0, -3,  2,  4, -6,  1,  3,  0,  0, -3, -5, -1, -4, -6, -2,  0, -1, -7, -5, -3,  4,  3, -1, -8,
/* C */  -2, -4, -4, -6,  9, -6, -6, -4, -4, -3, -7, -6, -6, -5, -3,  0, -3, -8, -1, -2, -5, -6, -4, -8,
/* Q */  -1,  1,  0,  1, -6,  5,  2, -2,  3, -3, -2,  0, -1, -5,  0, -1, -2, -5, -5, -2,  1,  4, -1, -8,
/* E */   0, -2,  1,  3, -6,  2,  4, -1,  0, -2, -4, -1, -3, -6, -1, -1, -1, -8, -4, -2,  2,  4, -1, -8,
/* G */   1, -4,  0,  0, -4, -2, -1,  5, -3, -4, -5, -3, -3, -5, -1,  1, -1, -7, -6, -2,  0, -1, -1, -8,
/* H */  -2,  1,  2,  0, -4,  3,  0, -3,  6, -3, -2, -1, -3, -2, -1, -1, -2, -3,  0, -3,  1,  1, -1, -8,
/* I */  -1, -2, -2, -3, -3, -3, -2, -4, -3,  5,  1, -2,  2,  0, -3, -2,  0, -6, -2,  3, -2, -2, -1, -8,
/* L */  -2, -4, -3, -5, -7, -2, -4, -5, -2,  1,  5, -3,  3,  1, -3, -3, -2, -2, -2,  1, -4, -3, -2, -8,
/* K */  -2,  3,  1, -1, -6,  0, -1, -3, -1, -2, -3,  5,  0, -6, -2, -1,  0, -4, -5, -3,  0,  0, -1, -8,
/* M */  -2, -1, -2, -4, -6, -1, -3, -3, -3,  2,  3,  0,  7, -1, -3, -2, -1, -5, -4,  1, -3, -2, -1, -8,
/* F */  -4, -5, -4, -6, -5, -5, -6, -5, -2,  0,  1, -6, -1,  7, -5, -3, -4, -1,  4, -2, -5, -6, -3, -8,
/* P */   1, -1, -1, -2, -3,  0, -1, -1, -1, -3, -3, -2, -3, -5,  6,  1,  0, -6, -6, -2, -2, -1, -1, -8,
/* S */   1, -1,  1,  0,  0, -1, -1,  1, -1, -2, -3, -1, -2, -3,  1,  3,  2, -2, -3, -2,  0, -1,  0, -8,
/* T */   1, -2,  0, -1, -3, -2, -1, -1, -2,  0, -2,  0, -1, -4,  0,  2,  4, -5, -3,  0,  0, -1, -1, -8,
/* W */  -6,  1, -4, -7, -8, -5, -8, -7, -3, -6, -2, -4, -5, -1, -6, -2, -5, 12, -1, -7, -5, -6, -5, -8,
/* Y */  -4, -5, -2, -5, -1, -5, -4, -6,  0, -2, -2, -5, -4,  4, -6, -3, -3, -1,  8, -3, -3, -4, -3, -8,
/* V */   0, -3, -2, -3, -2, -2, -2, -2, -3,  3,  1, -3,  1, -2, -2, -2,  0, -7, -3,  5, -3, -2, -1, -8,
/* B */   0, -2,  3,  4, -5,  1,  2,  0,  1, -2, -4,  0, -3, -5, -2,  0,  0, -5, -3, -3,  3,  2, -1, -8,
/* Z */   0, -1,  1,  3, -6,  4,  4, -1,  1, -2, -3,  0, -2, -6, -1, -1, -1, -6, -4, -2,  2,  4, -1, -8,
/* X */  -1, -1, -1, -1, -4, -1, -1, -1, -1, -1, -2, -1, -1, -3, -1,  0, -1, -5, -3, -1, -1, -1, -1, -8,
/* * */  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,  1
};

static const parasail_matrix_t parasail_pam140 = {
    "pam140",
    parasail_pam140_,
    parasail_pam_map,
    24,
    12,
    -8,
    NULL,
    PARASAIL_MATRIX_TYPE_SQUARE,
    24,
    "ARNDCQEGHILKMFPSTWYVBZX*",
    NULL
};

#ifdef __cplusplus
}
#endif

#endif /* _PARASAIL_PAM140_H_ */

