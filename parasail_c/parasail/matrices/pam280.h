/**
 * @file
 *
 * @author jeffrey.daily@gmail.com
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 *
 * This file was converted to C code from the raw file found at
 * ftp://ftp.cbi.pku.edu.cn/pub/software/blast/matrices/PAM280, the
 * Center for Bioinformatics, Peking University, China.
 */
#ifndef _PARASAIL_PAM280_H_
#define _PARASAIL_PAM280_H_

#include "parasail.h"
#include "pam_map.h"

#ifdef __cplusplus
extern "C" {
#endif

/* # */
/* # This matrix was produced by "pam" Version 1.0.6 [28-Jul-93] */
/* # */
/* # PAM 280 substitution matrix, scale = ln(2)/4 = 0.173287 */
/* # */
/* # Expected score = -0.916, Entropy = 0.289 bits */
/* # */
/* # Lowest score = -9, Highest score = 22 */
/* # */

static const int parasail_pam280_[] = {
/*        A   R   N   D   C   Q   E   G   H   I   L   K   M   F   P   S   T   W   Y   V   B   Z   X   * */
/* A */   2, -2,  0,  0, -2,  0,  0,  2, -1, -1, -2, -1, -1, -4,  1,  1,  1, -7, -4,  0,  0,  0,  0, -9,
/* R */  -2,  7,  0, -1, -4,  2, -1, -3,  2, -2, -3,  4,  0, -5,  0,  0, -1,  3, -5, -3, -1,  0, -1, -9,
/* N */   0,  0,  2,  2, -4,  1,  2,  1,  2, -2, -3,  1, -2, -4,  0,  1,  1, -5, -3, -2,  2,  1,  0, -9,
/* D */   0, -1,  2,  4, -6,  2,  4,  1,  1, -3, -5,  0, -3, -7, -1,  0,  0, -8, -5, -2,  4,  3, -1, -9,
/* C */  -2, -4, -4, -6, 15, -6, -6, -4, -4, -3, -7, -6, -6, -5, -3,  0, -3, -9,  1, -2, -5, -6, -3, -9,
/* Q */   0,  2,  1,  2, -6,  4,  3, -1,  3, -2, -2,  1, -1, -5,  0,  0, -1, -6, -5, -2,  2,  4, -1, -9,
/* E */   0, -1,  2,  4, -6,  3,  4,  0,  1, -2, -4,  0, -2, -6,  0,  0,  0, -8, -5, -2,  3,  4, -1, -9,
/* G */   2, -3,  1,  1, -4, -1,  0,  6, -2, -3, -5, -2, -3, -6,  0,  1,  0, -8, -6, -1,  1,  0, -1, -9,
/* H */  -1,  2,  2,  1, -4,  3,  1, -2,  8, -3, -2,  0, -2, -2,  0, -1, -1, -3,  0, -3,  1,  2, -1, -9,
/* I */  -1, -2, -2, -3, -3, -2, -2, -3, -3,  5,  3, -2,  3,  1, -2, -2,  0, -6, -1,  4, -2, -2, -1, -9,
/* L */  -2, -3, -3, -5, -7, -2, -4, -5, -2,  3,  7, -3,  5,  2, -3, -3, -2, -2, -1,  2, -4, -3, -1, -9,
/* K */  -1,  4,  1,  0, -6,  1,  0, -2,  0, -2, -3,  6,  0, -6, -1,  0,  0, -4, -5, -3,  1,  1, -1, -9,
/* M */  -1,  0, -2, -3, -6, -1, -2, -3, -2,  3,  5,  0,  7,  0, -2, -2, -1, -5, -3,  2, -2, -2, -1, -9,
/* F */  -4, -5, -4, -7, -5, -5, -6, -6, -2,  1,  2, -6,  0, 11, -5, -4, -4,  1,  9, -1, -5, -6, -3, -9,
/* P */   1,  0,  0, -1, -3,  0,  0,  0,  0, -2, -3, -1, -2, -5,  7,  1,  1, -7, -6, -1, -1,  0, -1, -9,
/* S */   1,  0,  1,  0,  0,  0,  0,  1, -1, -2, -3,  0, -2, -4,  1,  2,  1, -3, -3, -1,  1,  0,  0, -9,
/* T */   1, -1,  1,  0, -3, -1,  0,  0, -1,  0, -2,  0, -1, -4,  1,  1,  3, -6, -3,  0,  0,  0,  0, -9,
/* W */  -7,  3, -5, -8, -9, -6, -8, -8, -3, -6, -2, -4, -5,  1, -7, -3, -6, 22,  0, -7, -6, -7, -5, -9,
/* Y */  -4, -5, -3, -5,  1, -5, -5, -6,  0, -1, -1, -5, -3,  9, -6, -3, -3,  0, 13, -3, -4, -5, -3, -9,
/* V */   0, -3, -2, -2, -2, -2, -2, -1, -3,  4,  2, -3,  2, -1, -1, -1,  0, -7, -3,  5, -2, -2, -1, -9,
/* B */   0, -1,  2,  4, -5,  2,  3,  1,  1, -2, -4,  1, -2, -5, -1,  1,  0, -6, -4, -2,  3,  2, -1, -9,
/* Z */   0,  0,  1,  3, -6,  4,  4,  0,  2, -2, -3,  1, -2, -6,  0,  0,  0, -7, -5, -2,  2,  4, -1, -9,
/* X */   0, -1,  0, -1, -3, -1, -1, -1, -1, -1, -1, -1, -1, -3, -1,  0,  0, -5, -3, -1, -1, -1, -1, -9,
/* * */  -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,  1
};

static const parasail_matrix_t parasail_pam280 = {
    "pam280",
    parasail_pam280_,
    parasail_pam_map,
    24,
    22,
    -9,
    NULL,
    PARASAIL_MATRIX_TYPE_SQUARE,
    24,
    "ARNDCQEGHILKMFPSTWYVBZX*",
    NULL
};

#ifdef __cplusplus
}
#endif

#endif /* _PARASAIL_PAM280_H_ */

