/**
 * @file
 *
 * @author jeffrey.daily@gmail.com
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 *
 * This file was converted to C code from the raw file found at
 * ftp://ftp.cbi.pku.edu.cn/pub/software/blast/matrices/NUC.4.4, the
 * Center for Bioinformatics, Peking University, China.
 */
#ifndef _PARASAIL_NUC44_H_
#define _PARASAIL_NUC44_H_

#include "parasail.h"

#ifdef __cplusplus
extern "C" {
#endif

/* # This matrix was created by Todd Lowe   12/10/92 */
/* # Uses ambiguous nucleotide codes, probabilities rounded to */
/* #  nearest integer */
/* # Lowest score = -4, Highest score = 5 */

static const int parasail_nuc44_[] = {
/*       0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15 */
/*       A   T   G   C   S   W   R   Y   K   M   B   V   H   D   N   * */
/* A */  5, -4, -4, -4, -4,  1,  1, -4, -4,  1, -4, -1, -1, -1, -2, -4,
/* T */ -4,  5, -4, -4, -4,  1, -4,  1,  1, -4, -1, -4, -1, -1, -2, -4,
/* G */ -4, -4,  5, -4,  1, -4,  1, -4,  1, -4, -1, -1, -4, -1, -2, -4,
/* C */ -4, -4, -4,  5,  1, -4, -4,  1, -4,  1, -1, -1, -1, -4, -2, -4,
/* S */ -4, -4,  1,  1, -1, -4, -2, -2, -2, -2, -1, -1, -3, -3, -1, -4,
/* W */  1,  1, -4, -4, -4, -1, -2, -2, -2, -2, -3, -3, -1, -1, -1, -4,
/* R */  1, -4,  1, -4, -2, -2, -1, -4, -2, -2, -3, -1, -3, -1, -1, -4,
/* Y */ -4,  1, -4,  1, -2, -2, -4, -1, -2, -2, -1, -3, -1, -3, -1, -4,
/* K */ -4,  1,  1, -4, -2, -2, -2, -2, -1, -4, -1, -3, -3, -1, -1, -4,
/* M */  1, -4, -4,  1, -2, -2, -2, -2, -4, -1, -3, -1, -1, -3, -1, -4,
/* B */ -4, -1, -1, -1, -1, -3, -3, -1, -1, -3, -1, -2, -2, -2, -1, -4,
/* V */ -1, -4, -1, -1, -1, -3, -1, -3, -3, -1, -2, -1, -2, -2, -1, -4,
/* H */ -1, -1, -4, -1, -3, -1, -3, -1, -3, -1, -2, -2, -1, -2, -1, -4,  
/* D */ -1, -1, -1, -4, -3, -1, -1, -3, -1, -3, -2, -2, -2, -1, -1, -4,
/* N */ -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -4,
/* * */ -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4
};

static const int parasail_nuc44_map_[256] = {
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
     15,  0, 10,  3, 13, 15, 15,  2, 12, 15, 15,  8, 15,  9, 14, 15,
     15, 15,  6,  4,  1, 15, 11,  5, 15,  7, 15, 15, 15, 15, 15, 15,
     15,  0, 10,  3, 13, 15, 15,  2, 12, 15, 15,  8, 15,  9, 14, 15,
     15, 15,  6,  4,  1, 15, 11,  5, 15,  7, 15, 15, 15, 15, 15, 15,
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
     15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15
};

static const parasail_matrix_t parasail_nuc44 = {
    "nuc44",
    parasail_nuc44_,
    parasail_nuc44_map_,
    16,
    5,
    -4,
    0,
    PARASAIL_MATRIX_TYPE_SQUARE,
    16,
    "ATGCSWRYKMBVHDN*",
    NULL
};

#ifdef __cplusplus
}
#endif

#endif /* _PARASAIL_NUC44_H_ */

