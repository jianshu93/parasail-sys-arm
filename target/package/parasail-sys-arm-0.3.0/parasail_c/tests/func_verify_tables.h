/**
 * @file
 *
 * @author jeffrey.daily@gmail.com
 *
 * Copyright (c) 2015 Battelle Memorial Institute.
 */
#ifndef _PARASAIL_FUNCTION_GROUP_TABLE_H_
#define _PARASAIL_FUNCTION_GROUP_TABLE_H_

#include "parasail.h"

typedef struct parasail_function_group {
    const char * name;
    parasail_function_info_t *fs;
} parasail_function_group_t;

#if HAVE_SSE2
static parasail_function_info_t parasail_nw_table_sse2_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan_sse2_128_64,  "parasail_nw_table_scan_sse2_128_64",  "nw",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse2_128_32,  "parasail_nw_table_scan_sse2_128_32",  "nw",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse2_128_16,  "parasail_nw_table_scan_sse2_128_16",  "nw",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse2_128_8,   "parasail_nw_table_scan_sse2_128_8",   "nw",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse2_128_64, "parasail_nw_table_striped_sse2_128_64", "nw", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse2_128_32, "parasail_nw_table_striped_sse2_128_32", "nw", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse2_128_16, "parasail_nw_table_striped_sse2_128_16", "nw", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse2_128_8, "parasail_nw_table_striped_sse2_128_8", "nw", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse2_128_64,  "parasail_nw_table_diag_sse2_128_64",  "nw",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse2_128_32,  "parasail_nw_table_diag_sse2_128_32",  "nw",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse2_128_16,  "parasail_nw_table_diag_sse2_128_16",  "nw",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse2_128_8,   "parasail_nw_table_diag_sse2_128_8",   "nw",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_sse2 = {"parasail_nw_table_sse2", parasail_nw_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_nw_table_sse41_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan_sse41_128_64, "parasail_nw_table_scan_sse41_128_64", "nw",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse41_128_32, "parasail_nw_table_scan_sse41_128_32", "nw",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse41_128_16, "parasail_nw_table_scan_sse41_128_16", "nw",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sse41_128_8,  "parasail_nw_table_scan_sse41_128_8",  "nw",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse41_128_64, "parasail_nw_table_striped_sse41_128_64", "nw", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse41_128_32, "parasail_nw_table_striped_sse41_128_32", "nw", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse41_128_16, "parasail_nw_table_striped_sse41_128_16", "nw", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sse41_128_8, "parasail_nw_table_striped_sse41_128_8", "nw", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse41_128_64, "parasail_nw_table_diag_sse41_128_64", "nw",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse41_128_32, "parasail_nw_table_diag_sse41_128_32", "nw",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse41_128_16, "parasail_nw_table_diag_sse41_128_16", "nw",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sse41_128_8,  "parasail_nw_table_diag_sse41_128_8",  "nw",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_sse41 = {"parasail_nw_table_sse41", parasail_nw_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_nw_table_avx2_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan_avx2_256_64,  "parasail_nw_table_scan_avx2_256_64",  "nw",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_avx2_256_32,  "parasail_nw_table_scan_avx2_256_32",  "nw",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_avx2_256_16,  "parasail_nw_table_scan_avx2_256_16",  "nw",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_avx2_256_8,   "parasail_nw_table_scan_avx2_256_8",   "nw",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_avx2_256_64, "parasail_nw_table_striped_avx2_256_64", "nw", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_avx2_256_32, "parasail_nw_table_striped_avx2_256_32", "nw", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_avx2_256_16, "parasail_nw_table_striped_avx2_256_16", "nw", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_avx2_256_8, "parasail_nw_table_striped_avx2_256_8", "nw", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_avx2_256_64,  "parasail_nw_table_diag_avx2_256_64",  "nw",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_avx2_256_32,  "parasail_nw_table_diag_avx2_256_32",  "nw",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_avx2_256_16,  "parasail_nw_table_diag_avx2_256_16",  "nw",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_avx2_256_8,   "parasail_nw_table_diag_avx2_256_8",   "nw",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_avx2 = {"parasail_nw_table_avx2", parasail_nw_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_nw_table_altivec_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan_altivec_128_64, "parasail_nw_table_scan_altivec_128_64", "nw",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_altivec_128_32, "parasail_nw_table_scan_altivec_128_32", "nw",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_altivec_128_16, "parasail_nw_table_scan_altivec_128_16", "nw",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_altivec_128_8, "parasail_nw_table_scan_altivec_128_8", "nw",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_altivec_128_64, "parasail_nw_table_striped_altivec_128_64", "nw", "striped", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_altivec_128_32, "parasail_nw_table_striped_altivec_128_32", "nw", "striped", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_altivec_128_16, "parasail_nw_table_striped_altivec_128_16", "nw", "striped", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_altivec_128_8, "parasail_nw_table_striped_altivec_128_8", "nw", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_altivec_128_64, "parasail_nw_table_diag_altivec_128_64", "nw",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_altivec_128_32, "parasail_nw_table_diag_altivec_128_32", "nw",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_altivec_128_16, "parasail_nw_table_diag_altivec_128_16", "nw",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_altivec_128_8, "parasail_nw_table_diag_altivec_128_8", "nw",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_altivec = {"parasail_nw_table_altivec", parasail_nw_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_nw_table_neon_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan_neon_128_64,  "parasail_nw_table_scan_neon_128_64",  "nw",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_neon_128_32,  "parasail_nw_table_scan_neon_128_32",  "nw",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_neon_128_16,  "parasail_nw_table_scan_neon_128_16",  "nw",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_neon_128_8,   "parasail_nw_table_scan_neon_128_8",   "nw",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_neon_128_64, "parasail_nw_table_striped_neon_128_64", "nw", "striped", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_neon_128_32, "parasail_nw_table_striped_neon_128_32", "nw", "striped", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_neon_128_16, "parasail_nw_table_striped_neon_128_16", "nw", "striped", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_neon_128_8, "parasail_nw_table_striped_neon_128_8", "nw", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_neon_128_64,  "parasail_nw_table_diag_neon_128_64",  "nw",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_neon_128_32,  "parasail_nw_table_diag_neon_128_32",  "nw",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_neon_128_16,  "parasail_nw_table_diag_neon_128_16",  "nw",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_neon_128_8,   "parasail_nw_table_diag_neon_128_8",   "nw",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_neon = {"parasail_nw_table_neon", parasail_nw_table_neon_functions};
#endif
static parasail_function_info_t parasail_nw_table_disp_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan_64,           "parasail_nw_table_scan_64",           "nw",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_32,           "parasail_nw_table_scan_32",           "nw",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_16,           "parasail_nw_table_scan_16",           "nw",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_8,            "parasail_nw_table_scan_8",            "nw",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_64,        "parasail_nw_table_striped_64",        "nw", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_32,        "parasail_nw_table_striped_32",        "nw", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_16,        "parasail_nw_table_striped_16",        "nw", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_8,         "parasail_nw_table_striped_8",         "nw", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_64,           "parasail_nw_table_diag_64",           "nw",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_32,           "parasail_nw_table_diag_32",           "nw",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_16,           "parasail_nw_table_diag_16",           "nw",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_8,            "parasail_nw_table_diag_8",            "nw",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_scan_sat,          "parasail_nw_table_scan_sat",          "nw",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_striped_sat,       "parasail_nw_table_striped_sat",       "nw", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_nw_table_diag_sat,          "parasail_nw_table_diag_sat",          "nw",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_disp = {"parasail_nw_table_disp", parasail_nw_table_disp_functions};
static parasail_function_info_t parasail_nw_table_serial_functions[] = {
{parasail_nw_table,                   "parasail_nw_table",                   "nw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_nw_table_scan,              "parasail_nw_table_scan",              "nw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_table_serial = {"parasail_nw_table_serial", parasail_nw_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_table_sse2_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan_sse2_128_64,  "parasail_sg_table_scan_sse2_128_64",  "sg",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse2_128_32,  "parasail_sg_table_scan_sse2_128_32",  "sg",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse2_128_16,  "parasail_sg_table_scan_sse2_128_16",  "sg",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse2_128_8,   "parasail_sg_table_scan_sse2_128_8",   "sg",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse2_128_64, "parasail_sg_table_striped_sse2_128_64", "sg", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse2_128_32, "parasail_sg_table_striped_sse2_128_32", "sg", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse2_128_16, "parasail_sg_table_striped_sse2_128_16", "sg", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse2_128_8, "parasail_sg_table_striped_sse2_128_8", "sg", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse2_128_64,  "parasail_sg_table_diag_sse2_128_64",  "sg",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse2_128_32,  "parasail_sg_table_diag_sse2_128_32",  "sg",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse2_128_16,  "parasail_sg_table_diag_sse2_128_16",  "sg",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse2_128_8,   "parasail_sg_table_diag_sse2_128_8",   "sg",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_sse2 = {"parasail_sg_table_sse2", parasail_sg_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_table_sse41_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan_sse41_128_64, "parasail_sg_table_scan_sse41_128_64", "sg",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse41_128_32, "parasail_sg_table_scan_sse41_128_32", "sg",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse41_128_16, "parasail_sg_table_scan_sse41_128_16", "sg",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sse41_128_8,  "parasail_sg_table_scan_sse41_128_8",  "sg",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse41_128_64, "parasail_sg_table_striped_sse41_128_64", "sg", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse41_128_32, "parasail_sg_table_striped_sse41_128_32", "sg", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse41_128_16, "parasail_sg_table_striped_sse41_128_16", "sg", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sse41_128_8, "parasail_sg_table_striped_sse41_128_8", "sg", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse41_128_64, "parasail_sg_table_diag_sse41_128_64", "sg",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse41_128_32, "parasail_sg_table_diag_sse41_128_32", "sg",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse41_128_16, "parasail_sg_table_diag_sse41_128_16", "sg",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sse41_128_8,  "parasail_sg_table_diag_sse41_128_8",  "sg",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_sse41 = {"parasail_sg_table_sse41", parasail_sg_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_table_avx2_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan_avx2_256_64,  "parasail_sg_table_scan_avx2_256_64",  "sg",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_avx2_256_32,  "parasail_sg_table_scan_avx2_256_32",  "sg",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_avx2_256_16,  "parasail_sg_table_scan_avx2_256_16",  "sg",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_avx2_256_8,   "parasail_sg_table_scan_avx2_256_8",   "sg",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_avx2_256_64, "parasail_sg_table_striped_avx2_256_64", "sg", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_avx2_256_32, "parasail_sg_table_striped_avx2_256_32", "sg", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_avx2_256_16, "parasail_sg_table_striped_avx2_256_16", "sg", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_avx2_256_8, "parasail_sg_table_striped_avx2_256_8", "sg", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_avx2_256_64,  "parasail_sg_table_diag_avx2_256_64",  "sg",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_avx2_256_32,  "parasail_sg_table_diag_avx2_256_32",  "sg",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_avx2_256_16,  "parasail_sg_table_diag_avx2_256_16",  "sg",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_avx2_256_8,   "parasail_sg_table_diag_avx2_256_8",   "sg",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_avx2 = {"parasail_sg_table_avx2", parasail_sg_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_table_altivec_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan_altivec_128_64, "parasail_sg_table_scan_altivec_128_64", "sg",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_altivec_128_32, "parasail_sg_table_scan_altivec_128_32", "sg",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_altivec_128_16, "parasail_sg_table_scan_altivec_128_16", "sg",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_altivec_128_8, "parasail_sg_table_scan_altivec_128_8", "sg",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_altivec_128_64, "parasail_sg_table_striped_altivec_128_64", "sg", "striped", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_altivec_128_32, "parasail_sg_table_striped_altivec_128_32", "sg", "striped", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_altivec_128_16, "parasail_sg_table_striped_altivec_128_16", "sg", "striped", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_altivec_128_8, "parasail_sg_table_striped_altivec_128_8", "sg", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_altivec_128_64, "parasail_sg_table_diag_altivec_128_64", "sg",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_altivec_128_32, "parasail_sg_table_diag_altivec_128_32", "sg",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_altivec_128_16, "parasail_sg_table_diag_altivec_128_16", "sg",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_altivec_128_8, "parasail_sg_table_diag_altivec_128_8", "sg",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_altivec = {"parasail_sg_table_altivec", parasail_sg_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_table_neon_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan_neon_128_64,  "parasail_sg_table_scan_neon_128_64",  "sg",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_neon_128_32,  "parasail_sg_table_scan_neon_128_32",  "sg",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_neon_128_16,  "parasail_sg_table_scan_neon_128_16",  "sg",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_neon_128_8,   "parasail_sg_table_scan_neon_128_8",   "sg",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_neon_128_64, "parasail_sg_table_striped_neon_128_64", "sg", "striped", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_neon_128_32, "parasail_sg_table_striped_neon_128_32", "sg", "striped", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_neon_128_16, "parasail_sg_table_striped_neon_128_16", "sg", "striped", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_neon_128_8, "parasail_sg_table_striped_neon_128_8", "sg", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_neon_128_64,  "parasail_sg_table_diag_neon_128_64",  "sg",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_neon_128_32,  "parasail_sg_table_diag_neon_128_32",  "sg",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_neon_128_16,  "parasail_sg_table_diag_neon_128_16",  "sg",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_neon_128_8,   "parasail_sg_table_diag_neon_128_8",   "sg",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_neon = {"parasail_sg_table_neon", parasail_sg_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_table_disp_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan_64,           "parasail_sg_table_scan_64",           "sg",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_32,           "parasail_sg_table_scan_32",           "sg",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_16,           "parasail_sg_table_scan_16",           "sg",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_8,            "parasail_sg_table_scan_8",            "sg",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_64,        "parasail_sg_table_striped_64",        "sg", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_32,        "parasail_sg_table_striped_32",        "sg", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_16,        "parasail_sg_table_striped_16",        "sg", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_8,         "parasail_sg_table_striped_8",         "sg", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_64,           "parasail_sg_table_diag_64",           "sg",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_32,           "parasail_sg_table_diag_32",           "sg",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_16,           "parasail_sg_table_diag_16",           "sg",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_8,            "parasail_sg_table_diag_8",            "sg",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_scan_sat,          "parasail_sg_table_scan_sat",          "sg",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_striped_sat,       "parasail_sg_table_striped_sat",       "sg", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_table_diag_sat,          "parasail_sg_table_diag_sat",          "sg",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_disp = {"parasail_sg_table_disp", parasail_sg_table_disp_functions};
static parasail_function_info_t parasail_sg_table_serial_functions[] = {
{parasail_sg_table,                   "parasail_sg_table",                   "sg",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_table_scan,              "parasail_sg_table_scan",              "sg",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_table_serial = {"parasail_sg_table_serial", parasail_sg_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sw_table_sse2_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan_sse2_128_64,  "parasail_sw_table_scan_sse2_128_64",  "sw",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse2_128_32,  "parasail_sw_table_scan_sse2_128_32",  "sw",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse2_128_16,  "parasail_sw_table_scan_sse2_128_16",  "sw",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse2_128_8,   "parasail_sw_table_scan_sse2_128_8",   "sw",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse2_128_64, "parasail_sw_table_striped_sse2_128_64", "sw", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse2_128_32, "parasail_sw_table_striped_sse2_128_32", "sw", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse2_128_16, "parasail_sw_table_striped_sse2_128_16", "sw", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse2_128_8, "parasail_sw_table_striped_sse2_128_8", "sw", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse2_128_64,  "parasail_sw_table_diag_sse2_128_64",  "sw",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse2_128_32,  "parasail_sw_table_diag_sse2_128_32",  "sw",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse2_128_16,  "parasail_sw_table_diag_sse2_128_16",  "sw",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse2_128_8,   "parasail_sw_table_diag_sse2_128_8",   "sw",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_sse2 = {"parasail_sw_table_sse2", parasail_sw_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sw_table_sse41_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan_sse41_128_64, "parasail_sw_table_scan_sse41_128_64", "sw",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse41_128_32, "parasail_sw_table_scan_sse41_128_32", "sw",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse41_128_16, "parasail_sw_table_scan_sse41_128_16", "sw",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sse41_128_8,  "parasail_sw_table_scan_sse41_128_8",  "sw",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse41_128_64, "parasail_sw_table_striped_sse41_128_64", "sw", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse41_128_32, "parasail_sw_table_striped_sse41_128_32", "sw", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse41_128_16, "parasail_sw_table_striped_sse41_128_16", "sw", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sse41_128_8, "parasail_sw_table_striped_sse41_128_8", "sw", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse41_128_64, "parasail_sw_table_diag_sse41_128_64", "sw",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse41_128_32, "parasail_sw_table_diag_sse41_128_32", "sw",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse41_128_16, "parasail_sw_table_diag_sse41_128_16", "sw",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sse41_128_8,  "parasail_sw_table_diag_sse41_128_8",  "sw",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_sse41 = {"parasail_sw_table_sse41", parasail_sw_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sw_table_avx2_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan_avx2_256_64,  "parasail_sw_table_scan_avx2_256_64",  "sw",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_avx2_256_32,  "parasail_sw_table_scan_avx2_256_32",  "sw",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_avx2_256_16,  "parasail_sw_table_scan_avx2_256_16",  "sw",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_avx2_256_8,   "parasail_sw_table_scan_avx2_256_8",   "sw",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_avx2_256_64, "parasail_sw_table_striped_avx2_256_64", "sw", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_avx2_256_32, "parasail_sw_table_striped_avx2_256_32", "sw", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_avx2_256_16, "parasail_sw_table_striped_avx2_256_16", "sw", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_avx2_256_8, "parasail_sw_table_striped_avx2_256_8", "sw", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_avx2_256_64,  "parasail_sw_table_diag_avx2_256_64",  "sw",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_avx2_256_32,  "parasail_sw_table_diag_avx2_256_32",  "sw",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_avx2_256_16,  "parasail_sw_table_diag_avx2_256_16",  "sw",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_avx2_256_8,   "parasail_sw_table_diag_avx2_256_8",   "sw",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_avx2 = {"parasail_sw_table_avx2", parasail_sw_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sw_table_altivec_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan_altivec_128_64, "parasail_sw_table_scan_altivec_128_64", "sw",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_altivec_128_32, "parasail_sw_table_scan_altivec_128_32", "sw",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_altivec_128_16, "parasail_sw_table_scan_altivec_128_16", "sw",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_altivec_128_8, "parasail_sw_table_scan_altivec_128_8", "sw",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_altivec_128_64, "parasail_sw_table_striped_altivec_128_64", "sw", "striped", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_altivec_128_32, "parasail_sw_table_striped_altivec_128_32", "sw", "striped", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_altivec_128_16, "parasail_sw_table_striped_altivec_128_16", "sw", "striped", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_altivec_128_8, "parasail_sw_table_striped_altivec_128_8", "sw", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_altivec_128_64, "parasail_sw_table_diag_altivec_128_64", "sw",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_altivec_128_32, "parasail_sw_table_diag_altivec_128_32", "sw",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_altivec_128_16, "parasail_sw_table_diag_altivec_128_16", "sw",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_altivec_128_8, "parasail_sw_table_diag_altivec_128_8", "sw",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_altivec = {"parasail_sw_table_altivec", parasail_sw_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sw_table_neon_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan_neon_128_64,  "parasail_sw_table_scan_neon_128_64",  "sw",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_neon_128_32,  "parasail_sw_table_scan_neon_128_32",  "sw",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_neon_128_16,  "parasail_sw_table_scan_neon_128_16",  "sw",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_neon_128_8,   "parasail_sw_table_scan_neon_128_8",   "sw",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_neon_128_64, "parasail_sw_table_striped_neon_128_64", "sw", "striped", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_neon_128_32, "parasail_sw_table_striped_neon_128_32", "sw", "striped", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_neon_128_16, "parasail_sw_table_striped_neon_128_16", "sw", "striped", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_neon_128_8, "parasail_sw_table_striped_neon_128_8", "sw", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_neon_128_64,  "parasail_sw_table_diag_neon_128_64",  "sw",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_neon_128_32,  "parasail_sw_table_diag_neon_128_32",  "sw",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_neon_128_16,  "parasail_sw_table_diag_neon_128_16",  "sw",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_neon_128_8,   "parasail_sw_table_diag_neon_128_8",   "sw",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_neon = {"parasail_sw_table_neon", parasail_sw_table_neon_functions};
#endif
static parasail_function_info_t parasail_sw_table_disp_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan_64,           "parasail_sw_table_scan_64",           "sw",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_32,           "parasail_sw_table_scan_32",           "sw",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_16,           "parasail_sw_table_scan_16",           "sw",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_8,            "parasail_sw_table_scan_8",            "sw",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_64,        "parasail_sw_table_striped_64",        "sw", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_32,        "parasail_sw_table_striped_32",        "sw", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_16,        "parasail_sw_table_striped_16",        "sw", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_8,         "parasail_sw_table_striped_8",         "sw", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_64,           "parasail_sw_table_diag_64",           "sw",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_32,           "parasail_sw_table_diag_32",           "sw",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_16,           "parasail_sw_table_diag_16",           "sw",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_8,            "parasail_sw_table_diag_8",            "sw",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_scan_sat,          "parasail_sw_table_scan_sat",          "sw",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_striped_sat,       "parasail_sw_table_striped_sat",       "sw", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sw_table_diag_sat,          "parasail_sw_table_diag_sat",          "sw",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_disp = {"parasail_sw_table_disp", parasail_sw_table_disp_functions};
static parasail_function_info_t parasail_sw_table_serial_functions[] = {
{parasail_sw_table,                   "parasail_sw_table",                   "sw",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sw_table_scan,              "parasail_sw_table_scan",              "sw",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_table_serial = {"parasail_sw_table_serial", parasail_sw_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_qb_table_sse2_functions[] = {
{parasail_sg_qb_table,                "parasail_sg_qb_table",                "sg_qb",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_table_scan_sse2_128_64, "parasail_sg_qb_table_scan_sse2_128_64", "sg_qb",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_sse2_128_32, "parasail_sg_qb_table_scan_sse2_128_32", "sg_qb",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_sse2_128_16, "parasail_sg_qb_table_scan_sse2_128_16", "sg_qb",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_sse2_128_8, "parasail_sg_qb_table_scan_sse2_128_8", "sg_qb",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_sse2_128_64, "parasail_sg_qb_table_striped_sse2_128_64", "sg_qb", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_sse2_128_32, "parasail_sg_qb_table_striped_sse2_128_32", "sg_qb", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_sse2_128_16, "parasail_sg_qb_table_striped_sse2_128_16", "sg_qb", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_sse2_128_8, "parasail_sg_qb_table_striped_sse2_128_8", "sg_qb", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_sse2_128_64, "parasail_sg_qb_table_diag_sse2_128_64", "sg_qb",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_sse2_128_32, "parasail_sg_qb_table_diag_sse2_128_32", "sg_qb",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_sse2_128_16, "parasail_sg_qb_table_diag_sse2_128_16", "sg_qb",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_sse2_128_8, "parasail_sg_qb_table_diag_sse2_128_8", "sg_qb",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_table_sse2 = {"parasail_sg_qb_table_sse2", parasail_sg_qb_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_qb_table_sse41_functions[] = {
{parasail_sg_qb_table,                "parasail_sg_qb_table",                "sg_qb",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_table_scan_sse41_128_64, "parasail_sg_qb_table_scan_sse41_128_64", "sg_qb",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_sse41_128_32, "parasail_sg_qb_table_scan_sse41_128_32", "sg_qb",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_sse41_128_16, "parasail_sg_qb_table_scan_sse41_128_16", "sg_qb",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_sse41_128_8, "parasail_sg_qb_table_scan_sse41_128_8", "sg_qb",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_sse41_128_64, "parasail_sg_qb_table_striped_sse41_128_64", "sg_qb", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_sse41_128_32, "parasail_sg_qb_table_striped_sse41_128_32", "sg_qb", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_sse41_128_16, "parasail_sg_qb_table_striped_sse41_128_16", "sg_qb", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_sse41_128_8, "parasail_sg_qb_table_striped_sse41_128_8", "sg_qb", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_sse41_128_64, "parasail_sg_qb_table_diag_sse41_128_64", "sg_qb",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_sse41_128_32, "parasail_sg_qb_table_diag_sse41_128_32", "sg_qb",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_sse41_128_16, "parasail_sg_qb_table_diag_sse41_128_16", "sg_qb",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_sse41_128_8, "parasail_sg_qb_table_diag_sse41_128_8", "sg_qb",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_table_sse41 = {"parasail_sg_qb_table_sse41", parasail_sg_qb_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_qb_table_avx2_functions[] = {
{parasail_sg_qb_table,                "parasail_sg_qb_table",                "sg_qb",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_table_scan_avx2_256_64, "parasail_sg_qb_table_scan_avx2_256_64", "sg_qb",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_avx2_256_32, "parasail_sg_qb_table_scan_avx2_256_32", "sg_qb",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_avx2_256_16, "parasail_sg_qb_table_scan_avx2_256_16", "sg_qb",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_avx2_256_8, "parasail_sg_qb_table_scan_avx2_256_8", "sg_qb",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_avx2_256_64, "parasail_sg_qb_table_striped_avx2_256_64", "sg_qb", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_avx2_256_32, "parasail_sg_qb_table_striped_avx2_256_32", "sg_qb", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_avx2_256_16, "parasail_sg_qb_table_striped_avx2_256_16", "sg_qb", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_avx2_256_8, "parasail_sg_qb_table_striped_avx2_256_8", "sg_qb", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_avx2_256_64, "parasail_sg_qb_table_diag_avx2_256_64", "sg_qb",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_avx2_256_32, "parasail_sg_qb_table_diag_avx2_256_32", "sg_qb",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_avx2_256_16, "parasail_sg_qb_table_diag_avx2_256_16", "sg_qb",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_avx2_256_8, "parasail_sg_qb_table_diag_avx2_256_8", "sg_qb",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_table_avx2 = {"parasail_sg_qb_table_avx2", parasail_sg_qb_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_qb_table_altivec_functions[] = {
{parasail_sg_qb_table,                "parasail_sg_qb_table",                "sg_qb",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_table_scan_altivec_128_64, "parasail_sg_qb_table_scan_altivec_128_64", "sg_qb",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_altivec_128_32, "parasail_sg_qb_table_scan_altivec_128_32", "sg_qb",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_altivec_128_16, "parasail_sg_qb_table_scan_altivec_128_16", "sg_qb",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_altivec_128_8, "parasail_sg_qb_table_scan_altivec_128_8", "sg_qb",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_altivec_128_64, "parasail_sg_qb_table_striped_altivec_128_64", "sg_qb", "striped", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_altivec_128_32, "parasail_sg_qb_table_striped_altivec_128_32", "sg_qb", "striped", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_altivec_128_16, "parasail_sg_qb_table_striped_altivec_128_16", "sg_qb", "striped", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_altivec_128_8, "parasail_sg_qb_table_striped_altivec_128_8", "sg_qb", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_altivec_128_64, "parasail_sg_qb_table_diag_altivec_128_64", "sg_qb",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_altivec_128_32, "parasail_sg_qb_table_diag_altivec_128_32", "sg_qb",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_altivec_128_16, "parasail_sg_qb_table_diag_altivec_128_16", "sg_qb",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_altivec_128_8, "parasail_sg_qb_table_diag_altivec_128_8", "sg_qb",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_table_altivec = {"parasail_sg_qb_table_altivec", parasail_sg_qb_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_qb_table_neon_functions[] = {
{parasail_sg_qb_table,                "parasail_sg_qb_table",                "sg_qb",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_table_scan_neon_128_64, "parasail_sg_qb_table_scan_neon_128_64", "sg_qb",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_neon_128_32, "parasail_sg_qb_table_scan_neon_128_32", "sg_qb",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_neon_128_16, "parasail_sg_qb_table_scan_neon_128_16", "sg_qb",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_neon_128_8, "parasail_sg_qb_table_scan_neon_128_8", "sg_qb",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_neon_128_64, "parasail_sg_qb_table_striped_neon_128_64", "sg_qb", "striped", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_neon_128_32, "parasail_sg_qb_table_striped_neon_128_32", "sg_qb", "striped", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_neon_128_16, "parasail_sg_qb_table_striped_neon_128_16", "sg_qb", "striped", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_neon_128_8, "parasail_sg_qb_table_striped_neon_128_8", "sg_qb", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_neon_128_64, "parasail_sg_qb_table_diag_neon_128_64", "sg_qb",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_neon_128_32, "parasail_sg_qb_table_diag_neon_128_32", "sg_qb",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_neon_128_16, "parasail_sg_qb_table_diag_neon_128_16", "sg_qb",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_neon_128_8, "parasail_sg_qb_table_diag_neon_128_8", "sg_qb",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_table_neon = {"parasail_sg_qb_table_neon", parasail_sg_qb_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_qb_table_disp_functions[] = {
{parasail_sg_qb_table,                "parasail_sg_qb_table",                "sg_qb",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_table_scan_64,        "parasail_sg_qb_table_scan_64",        "sg_qb",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_32,        "parasail_sg_qb_table_scan_32",        "sg_qb",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_16,        "parasail_sg_qb_table_scan_16",        "sg_qb",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_8,         "parasail_sg_qb_table_scan_8",         "sg_qb",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_64,     "parasail_sg_qb_table_striped_64",     "sg_qb", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_32,     "parasail_sg_qb_table_striped_32",     "sg_qb", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_16,     "parasail_sg_qb_table_striped_16",     "sg_qb", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_8,      "parasail_sg_qb_table_striped_8",      "sg_qb", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_64,        "parasail_sg_qb_table_diag_64",        "sg_qb",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_32,        "parasail_sg_qb_table_diag_32",        "sg_qb",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_16,        "parasail_sg_qb_table_diag_16",        "sg_qb",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_8,         "parasail_sg_qb_table_diag_8",         "sg_qb",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_scan_sat,       "parasail_sg_qb_table_scan_sat",       "sg_qb",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_striped_sat,    "parasail_sg_qb_table_striped_sat",    "sg_qb", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_table_diag_sat,       "parasail_sg_qb_table_diag_sat",       "sg_qb",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_table_disp = {"parasail_sg_qb_table_disp", parasail_sg_qb_table_disp_functions};
static parasail_function_info_t parasail_sg_qb_table_serial_functions[] = {
{parasail_sg_qb_table,                "parasail_sg_qb_table",                "sg_qb",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_table_scan,           "parasail_sg_qb_table_scan",           "sg_qb",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_table_serial = {"parasail_sg_qb_table_serial", parasail_sg_qb_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_qe_table_sse2_functions[] = {
{parasail_sg_qe_table,                "parasail_sg_qe_table",                "sg_qe",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_table_scan_sse2_128_64, "parasail_sg_qe_table_scan_sse2_128_64", "sg_qe",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_sse2_128_32, "parasail_sg_qe_table_scan_sse2_128_32", "sg_qe",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_sse2_128_16, "parasail_sg_qe_table_scan_sse2_128_16", "sg_qe",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_sse2_128_8, "parasail_sg_qe_table_scan_sse2_128_8", "sg_qe",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_sse2_128_64, "parasail_sg_qe_table_striped_sse2_128_64", "sg_qe", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_sse2_128_32, "parasail_sg_qe_table_striped_sse2_128_32", "sg_qe", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_sse2_128_16, "parasail_sg_qe_table_striped_sse2_128_16", "sg_qe", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_sse2_128_8, "parasail_sg_qe_table_striped_sse2_128_8", "sg_qe", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_sse2_128_64, "parasail_sg_qe_table_diag_sse2_128_64", "sg_qe",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_sse2_128_32, "parasail_sg_qe_table_diag_sse2_128_32", "sg_qe",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_sse2_128_16, "parasail_sg_qe_table_diag_sse2_128_16", "sg_qe",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_sse2_128_8, "parasail_sg_qe_table_diag_sse2_128_8", "sg_qe",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_table_sse2 = {"parasail_sg_qe_table_sse2", parasail_sg_qe_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_qe_table_sse41_functions[] = {
{parasail_sg_qe_table,                "parasail_sg_qe_table",                "sg_qe",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_table_scan_sse41_128_64, "parasail_sg_qe_table_scan_sse41_128_64", "sg_qe",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_sse41_128_32, "parasail_sg_qe_table_scan_sse41_128_32", "sg_qe",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_sse41_128_16, "parasail_sg_qe_table_scan_sse41_128_16", "sg_qe",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_sse41_128_8, "parasail_sg_qe_table_scan_sse41_128_8", "sg_qe",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_sse41_128_64, "parasail_sg_qe_table_striped_sse41_128_64", "sg_qe", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_sse41_128_32, "parasail_sg_qe_table_striped_sse41_128_32", "sg_qe", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_sse41_128_16, "parasail_sg_qe_table_striped_sse41_128_16", "sg_qe", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_sse41_128_8, "parasail_sg_qe_table_striped_sse41_128_8", "sg_qe", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_sse41_128_64, "parasail_sg_qe_table_diag_sse41_128_64", "sg_qe",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_sse41_128_32, "parasail_sg_qe_table_diag_sse41_128_32", "sg_qe",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_sse41_128_16, "parasail_sg_qe_table_diag_sse41_128_16", "sg_qe",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_sse41_128_8, "parasail_sg_qe_table_diag_sse41_128_8", "sg_qe",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_table_sse41 = {"parasail_sg_qe_table_sse41", parasail_sg_qe_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_qe_table_avx2_functions[] = {
{parasail_sg_qe_table,                "parasail_sg_qe_table",                "sg_qe",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_table_scan_avx2_256_64, "parasail_sg_qe_table_scan_avx2_256_64", "sg_qe",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_avx2_256_32, "parasail_sg_qe_table_scan_avx2_256_32", "sg_qe",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_avx2_256_16, "parasail_sg_qe_table_scan_avx2_256_16", "sg_qe",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_avx2_256_8, "parasail_sg_qe_table_scan_avx2_256_8", "sg_qe",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_avx2_256_64, "parasail_sg_qe_table_striped_avx2_256_64", "sg_qe", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_avx2_256_32, "parasail_sg_qe_table_striped_avx2_256_32", "sg_qe", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_avx2_256_16, "parasail_sg_qe_table_striped_avx2_256_16", "sg_qe", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_avx2_256_8, "parasail_sg_qe_table_striped_avx2_256_8", "sg_qe", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_avx2_256_64, "parasail_sg_qe_table_diag_avx2_256_64", "sg_qe",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_avx2_256_32, "parasail_sg_qe_table_diag_avx2_256_32", "sg_qe",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_avx2_256_16, "parasail_sg_qe_table_diag_avx2_256_16", "sg_qe",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_avx2_256_8, "parasail_sg_qe_table_diag_avx2_256_8", "sg_qe",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_table_avx2 = {"parasail_sg_qe_table_avx2", parasail_sg_qe_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_qe_table_altivec_functions[] = {
{parasail_sg_qe_table,                "parasail_sg_qe_table",                "sg_qe",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_table_scan_altivec_128_64, "parasail_sg_qe_table_scan_altivec_128_64", "sg_qe",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_altivec_128_32, "parasail_sg_qe_table_scan_altivec_128_32", "sg_qe",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_altivec_128_16, "parasail_sg_qe_table_scan_altivec_128_16", "sg_qe",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_altivec_128_8, "parasail_sg_qe_table_scan_altivec_128_8", "sg_qe",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_altivec_128_64, "parasail_sg_qe_table_striped_altivec_128_64", "sg_qe", "striped", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_altivec_128_32, "parasail_sg_qe_table_striped_altivec_128_32", "sg_qe", "striped", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_altivec_128_16, "parasail_sg_qe_table_striped_altivec_128_16", "sg_qe", "striped", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_altivec_128_8, "parasail_sg_qe_table_striped_altivec_128_8", "sg_qe", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_altivec_128_64, "parasail_sg_qe_table_diag_altivec_128_64", "sg_qe",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_altivec_128_32, "parasail_sg_qe_table_diag_altivec_128_32", "sg_qe",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_altivec_128_16, "parasail_sg_qe_table_diag_altivec_128_16", "sg_qe",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_altivec_128_8, "parasail_sg_qe_table_diag_altivec_128_8", "sg_qe",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_table_altivec = {"parasail_sg_qe_table_altivec", parasail_sg_qe_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_qe_table_neon_functions[] = {
{parasail_sg_qe_table,                "parasail_sg_qe_table",                "sg_qe",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_table_scan_neon_128_64, "parasail_sg_qe_table_scan_neon_128_64", "sg_qe",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_neon_128_32, "parasail_sg_qe_table_scan_neon_128_32", "sg_qe",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_neon_128_16, "parasail_sg_qe_table_scan_neon_128_16", "sg_qe",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_neon_128_8, "parasail_sg_qe_table_scan_neon_128_8", "sg_qe",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_neon_128_64, "parasail_sg_qe_table_striped_neon_128_64", "sg_qe", "striped", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_neon_128_32, "parasail_sg_qe_table_striped_neon_128_32", "sg_qe", "striped", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_neon_128_16, "parasail_sg_qe_table_striped_neon_128_16", "sg_qe", "striped", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_neon_128_8, "parasail_sg_qe_table_striped_neon_128_8", "sg_qe", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_neon_128_64, "parasail_sg_qe_table_diag_neon_128_64", "sg_qe",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_neon_128_32, "parasail_sg_qe_table_diag_neon_128_32", "sg_qe",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_neon_128_16, "parasail_sg_qe_table_diag_neon_128_16", "sg_qe",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_neon_128_8, "parasail_sg_qe_table_diag_neon_128_8", "sg_qe",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_table_neon = {"parasail_sg_qe_table_neon", parasail_sg_qe_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_qe_table_disp_functions[] = {
{parasail_sg_qe_table,                "parasail_sg_qe_table",                "sg_qe",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_table_scan_64,        "parasail_sg_qe_table_scan_64",        "sg_qe",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_32,        "parasail_sg_qe_table_scan_32",        "sg_qe",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_16,        "parasail_sg_qe_table_scan_16",        "sg_qe",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_8,         "parasail_sg_qe_table_scan_8",         "sg_qe",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_64,     "parasail_sg_qe_table_striped_64",     "sg_qe", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_32,     "parasail_sg_qe_table_striped_32",     "sg_qe", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_16,     "parasail_sg_qe_table_striped_16",     "sg_qe", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_8,      "parasail_sg_qe_table_striped_8",      "sg_qe", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_64,        "parasail_sg_qe_table_diag_64",        "sg_qe",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_32,        "parasail_sg_qe_table_diag_32",        "sg_qe",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_16,        "parasail_sg_qe_table_diag_16",        "sg_qe",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_8,         "parasail_sg_qe_table_diag_8",         "sg_qe",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_scan_sat,       "parasail_sg_qe_table_scan_sat",       "sg_qe",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_striped_sat,    "parasail_sg_qe_table_striped_sat",    "sg_qe", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_table_diag_sat,       "parasail_sg_qe_table_diag_sat",       "sg_qe",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_table_disp = {"parasail_sg_qe_table_disp", parasail_sg_qe_table_disp_functions};
static parasail_function_info_t parasail_sg_qe_table_serial_functions[] = {
{parasail_sg_qe_table,                "parasail_sg_qe_table",                "sg_qe",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_table_scan,           "parasail_sg_qe_table_scan",           "sg_qe",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_table_serial = {"parasail_sg_qe_table_serial", parasail_sg_qe_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_qx_table_sse2_functions[] = {
{parasail_sg_qx_table,                "parasail_sg_qx_table",                "sg_qx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qx_table_scan_sse2_128_64, "parasail_sg_qx_table_scan_sse2_128_64", "sg_qx",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_sse2_128_32, "parasail_sg_qx_table_scan_sse2_128_32", "sg_qx",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_sse2_128_16, "parasail_sg_qx_table_scan_sse2_128_16", "sg_qx",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_sse2_128_8, "parasail_sg_qx_table_scan_sse2_128_8", "sg_qx",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_sse2_128_64, "parasail_sg_qx_table_striped_sse2_128_64", "sg_qx", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_sse2_128_32, "parasail_sg_qx_table_striped_sse2_128_32", "sg_qx", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_sse2_128_16, "parasail_sg_qx_table_striped_sse2_128_16", "sg_qx", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_sse2_128_8, "parasail_sg_qx_table_striped_sse2_128_8", "sg_qx", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_sse2_128_64, "parasail_sg_qx_table_diag_sse2_128_64", "sg_qx",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_sse2_128_32, "parasail_sg_qx_table_diag_sse2_128_32", "sg_qx",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_sse2_128_16, "parasail_sg_qx_table_diag_sse2_128_16", "sg_qx",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_sse2_128_8, "parasail_sg_qx_table_diag_sse2_128_8", "sg_qx",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_table_sse2 = {"parasail_sg_qx_table_sse2", parasail_sg_qx_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_qx_table_sse41_functions[] = {
{parasail_sg_qx_table,                "parasail_sg_qx_table",                "sg_qx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qx_table_scan_sse41_128_64, "parasail_sg_qx_table_scan_sse41_128_64", "sg_qx",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_sse41_128_32, "parasail_sg_qx_table_scan_sse41_128_32", "sg_qx",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_sse41_128_16, "parasail_sg_qx_table_scan_sse41_128_16", "sg_qx",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_sse41_128_8, "parasail_sg_qx_table_scan_sse41_128_8", "sg_qx",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_sse41_128_64, "parasail_sg_qx_table_striped_sse41_128_64", "sg_qx", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_sse41_128_32, "parasail_sg_qx_table_striped_sse41_128_32", "sg_qx", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_sse41_128_16, "parasail_sg_qx_table_striped_sse41_128_16", "sg_qx", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_sse41_128_8, "parasail_sg_qx_table_striped_sse41_128_8", "sg_qx", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_sse41_128_64, "parasail_sg_qx_table_diag_sse41_128_64", "sg_qx",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_sse41_128_32, "parasail_sg_qx_table_diag_sse41_128_32", "sg_qx",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_sse41_128_16, "parasail_sg_qx_table_diag_sse41_128_16", "sg_qx",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_sse41_128_8, "parasail_sg_qx_table_diag_sse41_128_8", "sg_qx",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_table_sse41 = {"parasail_sg_qx_table_sse41", parasail_sg_qx_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_qx_table_avx2_functions[] = {
{parasail_sg_qx_table,                "parasail_sg_qx_table",                "sg_qx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qx_table_scan_avx2_256_64, "parasail_sg_qx_table_scan_avx2_256_64", "sg_qx",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_avx2_256_32, "parasail_sg_qx_table_scan_avx2_256_32", "sg_qx",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_avx2_256_16, "parasail_sg_qx_table_scan_avx2_256_16", "sg_qx",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_avx2_256_8, "parasail_sg_qx_table_scan_avx2_256_8", "sg_qx",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_avx2_256_64, "parasail_sg_qx_table_striped_avx2_256_64", "sg_qx", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_avx2_256_32, "parasail_sg_qx_table_striped_avx2_256_32", "sg_qx", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_avx2_256_16, "parasail_sg_qx_table_striped_avx2_256_16", "sg_qx", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_avx2_256_8, "parasail_sg_qx_table_striped_avx2_256_8", "sg_qx", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_avx2_256_64, "parasail_sg_qx_table_diag_avx2_256_64", "sg_qx",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_avx2_256_32, "parasail_sg_qx_table_diag_avx2_256_32", "sg_qx",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_avx2_256_16, "parasail_sg_qx_table_diag_avx2_256_16", "sg_qx",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_avx2_256_8, "parasail_sg_qx_table_diag_avx2_256_8", "sg_qx",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_table_avx2 = {"parasail_sg_qx_table_avx2", parasail_sg_qx_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_qx_table_altivec_functions[] = {
{parasail_sg_qx_table,                "parasail_sg_qx_table",                "sg_qx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qx_table_scan_altivec_128_64, "parasail_sg_qx_table_scan_altivec_128_64", "sg_qx",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_altivec_128_32, "parasail_sg_qx_table_scan_altivec_128_32", "sg_qx",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_altivec_128_16, "parasail_sg_qx_table_scan_altivec_128_16", "sg_qx",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_altivec_128_8, "parasail_sg_qx_table_scan_altivec_128_8", "sg_qx",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_altivec_128_64, "parasail_sg_qx_table_striped_altivec_128_64", "sg_qx", "striped", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_altivec_128_32, "parasail_sg_qx_table_striped_altivec_128_32", "sg_qx", "striped", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_altivec_128_16, "parasail_sg_qx_table_striped_altivec_128_16", "sg_qx", "striped", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_altivec_128_8, "parasail_sg_qx_table_striped_altivec_128_8", "sg_qx", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_altivec_128_64, "parasail_sg_qx_table_diag_altivec_128_64", "sg_qx",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_altivec_128_32, "parasail_sg_qx_table_diag_altivec_128_32", "sg_qx",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_altivec_128_16, "parasail_sg_qx_table_diag_altivec_128_16", "sg_qx",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_altivec_128_8, "parasail_sg_qx_table_diag_altivec_128_8", "sg_qx",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_table_altivec = {"parasail_sg_qx_table_altivec", parasail_sg_qx_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_qx_table_neon_functions[] = {
{parasail_sg_qx_table,                "parasail_sg_qx_table",                "sg_qx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qx_table_scan_neon_128_64, "parasail_sg_qx_table_scan_neon_128_64", "sg_qx",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_neon_128_32, "parasail_sg_qx_table_scan_neon_128_32", "sg_qx",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_neon_128_16, "parasail_sg_qx_table_scan_neon_128_16", "sg_qx",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_neon_128_8, "parasail_sg_qx_table_scan_neon_128_8", "sg_qx",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_neon_128_64, "parasail_sg_qx_table_striped_neon_128_64", "sg_qx", "striped", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_neon_128_32, "parasail_sg_qx_table_striped_neon_128_32", "sg_qx", "striped", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_neon_128_16, "parasail_sg_qx_table_striped_neon_128_16", "sg_qx", "striped", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_neon_128_8, "parasail_sg_qx_table_striped_neon_128_8", "sg_qx", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_neon_128_64, "parasail_sg_qx_table_diag_neon_128_64", "sg_qx",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_neon_128_32, "parasail_sg_qx_table_diag_neon_128_32", "sg_qx",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_neon_128_16, "parasail_sg_qx_table_diag_neon_128_16", "sg_qx",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_neon_128_8, "parasail_sg_qx_table_diag_neon_128_8", "sg_qx",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_table_neon = {"parasail_sg_qx_table_neon", parasail_sg_qx_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_qx_table_disp_functions[] = {
{parasail_sg_qx_table,                "parasail_sg_qx_table",                "sg_qx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qx_table_scan_64,        "parasail_sg_qx_table_scan_64",        "sg_qx",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_32,        "parasail_sg_qx_table_scan_32",        "sg_qx",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_16,        "parasail_sg_qx_table_scan_16",        "sg_qx",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_8,         "parasail_sg_qx_table_scan_8",         "sg_qx",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_64,     "parasail_sg_qx_table_striped_64",     "sg_qx", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_32,     "parasail_sg_qx_table_striped_32",     "sg_qx", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_16,     "parasail_sg_qx_table_striped_16",     "sg_qx", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_8,      "parasail_sg_qx_table_striped_8",      "sg_qx", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_64,        "parasail_sg_qx_table_diag_64",        "sg_qx",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_32,        "parasail_sg_qx_table_diag_32",        "sg_qx",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_16,        "parasail_sg_qx_table_diag_16",        "sg_qx",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_8,         "parasail_sg_qx_table_diag_8",         "sg_qx",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_scan_sat,       "parasail_sg_qx_table_scan_sat",       "sg_qx",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_striped_sat,    "parasail_sg_qx_table_striped_sat",    "sg_qx", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qx_table_diag_sat,       "parasail_sg_qx_table_diag_sat",       "sg_qx",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_table_disp = {"parasail_sg_qx_table_disp", parasail_sg_qx_table_disp_functions};
static parasail_function_info_t parasail_sg_qx_table_serial_functions[] = {
{parasail_sg_qx_table,                "parasail_sg_qx_table",                "sg_qx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qx_table_scan,           "parasail_sg_qx_table_scan",           "sg_qx",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_table_serial = {"parasail_sg_qx_table_serial", parasail_sg_qx_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_db_table_sse2_functions[] = {
{parasail_sg_db_table,                "parasail_sg_db_table",                "sg_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_db_table_scan_sse2_128_64, "parasail_sg_db_table_scan_sse2_128_64", "sg_db",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_sse2_128_32, "parasail_sg_db_table_scan_sse2_128_32", "sg_db",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_sse2_128_16, "parasail_sg_db_table_scan_sse2_128_16", "sg_db",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_sse2_128_8, "parasail_sg_db_table_scan_sse2_128_8", "sg_db",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_sse2_128_64, "parasail_sg_db_table_striped_sse2_128_64", "sg_db", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_sse2_128_32, "parasail_sg_db_table_striped_sse2_128_32", "sg_db", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_sse2_128_16, "parasail_sg_db_table_striped_sse2_128_16", "sg_db", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_sse2_128_8, "parasail_sg_db_table_striped_sse2_128_8", "sg_db", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_sse2_128_64, "parasail_sg_db_table_diag_sse2_128_64", "sg_db",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_sse2_128_32, "parasail_sg_db_table_diag_sse2_128_32", "sg_db",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_sse2_128_16, "parasail_sg_db_table_diag_sse2_128_16", "sg_db",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_sse2_128_8, "parasail_sg_db_table_diag_sse2_128_8", "sg_db",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_table_sse2 = {"parasail_sg_db_table_sse2", parasail_sg_db_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_db_table_sse41_functions[] = {
{parasail_sg_db_table,                "parasail_sg_db_table",                "sg_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_db_table_scan_sse41_128_64, "parasail_sg_db_table_scan_sse41_128_64", "sg_db",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_sse41_128_32, "parasail_sg_db_table_scan_sse41_128_32", "sg_db",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_sse41_128_16, "parasail_sg_db_table_scan_sse41_128_16", "sg_db",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_sse41_128_8, "parasail_sg_db_table_scan_sse41_128_8", "sg_db",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_sse41_128_64, "parasail_sg_db_table_striped_sse41_128_64", "sg_db", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_sse41_128_32, "parasail_sg_db_table_striped_sse41_128_32", "sg_db", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_sse41_128_16, "parasail_sg_db_table_striped_sse41_128_16", "sg_db", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_sse41_128_8, "parasail_sg_db_table_striped_sse41_128_8", "sg_db", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_sse41_128_64, "parasail_sg_db_table_diag_sse41_128_64", "sg_db",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_sse41_128_32, "parasail_sg_db_table_diag_sse41_128_32", "sg_db",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_sse41_128_16, "parasail_sg_db_table_diag_sse41_128_16", "sg_db",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_sse41_128_8, "parasail_sg_db_table_diag_sse41_128_8", "sg_db",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_table_sse41 = {"parasail_sg_db_table_sse41", parasail_sg_db_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_db_table_avx2_functions[] = {
{parasail_sg_db_table,                "parasail_sg_db_table",                "sg_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_db_table_scan_avx2_256_64, "parasail_sg_db_table_scan_avx2_256_64", "sg_db",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_avx2_256_32, "parasail_sg_db_table_scan_avx2_256_32", "sg_db",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_avx2_256_16, "parasail_sg_db_table_scan_avx2_256_16", "sg_db",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_avx2_256_8, "parasail_sg_db_table_scan_avx2_256_8", "sg_db",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_avx2_256_64, "parasail_sg_db_table_striped_avx2_256_64", "sg_db", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_avx2_256_32, "parasail_sg_db_table_striped_avx2_256_32", "sg_db", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_avx2_256_16, "parasail_sg_db_table_striped_avx2_256_16", "sg_db", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_avx2_256_8, "parasail_sg_db_table_striped_avx2_256_8", "sg_db", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_avx2_256_64, "parasail_sg_db_table_diag_avx2_256_64", "sg_db",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_avx2_256_32, "parasail_sg_db_table_diag_avx2_256_32", "sg_db",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_avx2_256_16, "parasail_sg_db_table_diag_avx2_256_16", "sg_db",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_avx2_256_8, "parasail_sg_db_table_diag_avx2_256_8", "sg_db",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_table_avx2 = {"parasail_sg_db_table_avx2", parasail_sg_db_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_db_table_altivec_functions[] = {
{parasail_sg_db_table,                "parasail_sg_db_table",                "sg_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_db_table_scan_altivec_128_64, "parasail_sg_db_table_scan_altivec_128_64", "sg_db",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_altivec_128_32, "parasail_sg_db_table_scan_altivec_128_32", "sg_db",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_altivec_128_16, "parasail_sg_db_table_scan_altivec_128_16", "sg_db",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_altivec_128_8, "parasail_sg_db_table_scan_altivec_128_8", "sg_db",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_altivec_128_64, "parasail_sg_db_table_striped_altivec_128_64", "sg_db", "striped", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_altivec_128_32, "parasail_sg_db_table_striped_altivec_128_32", "sg_db", "striped", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_altivec_128_16, "parasail_sg_db_table_striped_altivec_128_16", "sg_db", "striped", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_altivec_128_8, "parasail_sg_db_table_striped_altivec_128_8", "sg_db", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_altivec_128_64, "parasail_sg_db_table_diag_altivec_128_64", "sg_db",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_altivec_128_32, "parasail_sg_db_table_diag_altivec_128_32", "sg_db",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_altivec_128_16, "parasail_sg_db_table_diag_altivec_128_16", "sg_db",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_altivec_128_8, "parasail_sg_db_table_diag_altivec_128_8", "sg_db",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_table_altivec = {"parasail_sg_db_table_altivec", parasail_sg_db_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_db_table_neon_functions[] = {
{parasail_sg_db_table,                "parasail_sg_db_table",                "sg_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_db_table_scan_neon_128_64, "parasail_sg_db_table_scan_neon_128_64", "sg_db",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_neon_128_32, "parasail_sg_db_table_scan_neon_128_32", "sg_db",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_neon_128_16, "parasail_sg_db_table_scan_neon_128_16", "sg_db",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_neon_128_8, "parasail_sg_db_table_scan_neon_128_8", "sg_db",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_neon_128_64, "parasail_sg_db_table_striped_neon_128_64", "sg_db", "striped", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_neon_128_32, "parasail_sg_db_table_striped_neon_128_32", "sg_db", "striped", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_neon_128_16, "parasail_sg_db_table_striped_neon_128_16", "sg_db", "striped", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_neon_128_8, "parasail_sg_db_table_striped_neon_128_8", "sg_db", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_neon_128_64, "parasail_sg_db_table_diag_neon_128_64", "sg_db",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_neon_128_32, "parasail_sg_db_table_diag_neon_128_32", "sg_db",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_neon_128_16, "parasail_sg_db_table_diag_neon_128_16", "sg_db",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_neon_128_8, "parasail_sg_db_table_diag_neon_128_8", "sg_db",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_table_neon = {"parasail_sg_db_table_neon", parasail_sg_db_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_db_table_disp_functions[] = {
{parasail_sg_db_table,                "parasail_sg_db_table",                "sg_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_db_table_scan_64,        "parasail_sg_db_table_scan_64",        "sg_db",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_32,        "parasail_sg_db_table_scan_32",        "sg_db",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_16,        "parasail_sg_db_table_scan_16",        "sg_db",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_8,         "parasail_sg_db_table_scan_8",         "sg_db",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_64,     "parasail_sg_db_table_striped_64",     "sg_db", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_32,     "parasail_sg_db_table_striped_32",     "sg_db", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_16,     "parasail_sg_db_table_striped_16",     "sg_db", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_8,      "parasail_sg_db_table_striped_8",      "sg_db", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_64,        "parasail_sg_db_table_diag_64",        "sg_db",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_32,        "parasail_sg_db_table_diag_32",        "sg_db",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_16,        "parasail_sg_db_table_diag_16",        "sg_db",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_8,         "parasail_sg_db_table_diag_8",         "sg_db",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_scan_sat,       "parasail_sg_db_table_scan_sat",       "sg_db",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_striped_sat,    "parasail_sg_db_table_striped_sat",    "sg_db", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_db_table_diag_sat,       "parasail_sg_db_table_diag_sat",       "sg_db",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_table_disp = {"parasail_sg_db_table_disp", parasail_sg_db_table_disp_functions};
static parasail_function_info_t parasail_sg_db_table_serial_functions[] = {
{parasail_sg_db_table,                "parasail_sg_db_table",                "sg_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_db_table_scan,           "parasail_sg_db_table_scan",           "sg_db",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_table_serial = {"parasail_sg_db_table_serial", parasail_sg_db_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_de_table_sse2_functions[] = {
{parasail_sg_de_table,                "parasail_sg_de_table",                "sg_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_de_table_scan_sse2_128_64, "parasail_sg_de_table_scan_sse2_128_64", "sg_de",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_sse2_128_32, "parasail_sg_de_table_scan_sse2_128_32", "sg_de",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_sse2_128_16, "parasail_sg_de_table_scan_sse2_128_16", "sg_de",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_sse2_128_8, "parasail_sg_de_table_scan_sse2_128_8", "sg_de",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_sse2_128_64, "parasail_sg_de_table_striped_sse2_128_64", "sg_de", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_sse2_128_32, "parasail_sg_de_table_striped_sse2_128_32", "sg_de", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_sse2_128_16, "parasail_sg_de_table_striped_sse2_128_16", "sg_de", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_sse2_128_8, "parasail_sg_de_table_striped_sse2_128_8", "sg_de", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_sse2_128_64, "parasail_sg_de_table_diag_sse2_128_64", "sg_de",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_sse2_128_32, "parasail_sg_de_table_diag_sse2_128_32", "sg_de",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_sse2_128_16, "parasail_sg_de_table_diag_sse2_128_16", "sg_de",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_sse2_128_8, "parasail_sg_de_table_diag_sse2_128_8", "sg_de",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_table_sse2 = {"parasail_sg_de_table_sse2", parasail_sg_de_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_de_table_sse41_functions[] = {
{parasail_sg_de_table,                "parasail_sg_de_table",                "sg_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_de_table_scan_sse41_128_64, "parasail_sg_de_table_scan_sse41_128_64", "sg_de",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_sse41_128_32, "parasail_sg_de_table_scan_sse41_128_32", "sg_de",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_sse41_128_16, "parasail_sg_de_table_scan_sse41_128_16", "sg_de",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_sse41_128_8, "parasail_sg_de_table_scan_sse41_128_8", "sg_de",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_sse41_128_64, "parasail_sg_de_table_striped_sse41_128_64", "sg_de", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_sse41_128_32, "parasail_sg_de_table_striped_sse41_128_32", "sg_de", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_sse41_128_16, "parasail_sg_de_table_striped_sse41_128_16", "sg_de", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_sse41_128_8, "parasail_sg_de_table_striped_sse41_128_8", "sg_de", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_sse41_128_64, "parasail_sg_de_table_diag_sse41_128_64", "sg_de",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_sse41_128_32, "parasail_sg_de_table_diag_sse41_128_32", "sg_de",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_sse41_128_16, "parasail_sg_de_table_diag_sse41_128_16", "sg_de",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_sse41_128_8, "parasail_sg_de_table_diag_sse41_128_8", "sg_de",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_table_sse41 = {"parasail_sg_de_table_sse41", parasail_sg_de_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_de_table_avx2_functions[] = {
{parasail_sg_de_table,                "parasail_sg_de_table",                "sg_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_de_table_scan_avx2_256_64, "parasail_sg_de_table_scan_avx2_256_64", "sg_de",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_avx2_256_32, "parasail_sg_de_table_scan_avx2_256_32", "sg_de",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_avx2_256_16, "parasail_sg_de_table_scan_avx2_256_16", "sg_de",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_avx2_256_8, "parasail_sg_de_table_scan_avx2_256_8", "sg_de",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_avx2_256_64, "parasail_sg_de_table_striped_avx2_256_64", "sg_de", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_avx2_256_32, "parasail_sg_de_table_striped_avx2_256_32", "sg_de", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_avx2_256_16, "parasail_sg_de_table_striped_avx2_256_16", "sg_de", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_avx2_256_8, "parasail_sg_de_table_striped_avx2_256_8", "sg_de", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_avx2_256_64, "parasail_sg_de_table_diag_avx2_256_64", "sg_de",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_avx2_256_32, "parasail_sg_de_table_diag_avx2_256_32", "sg_de",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_avx2_256_16, "parasail_sg_de_table_diag_avx2_256_16", "sg_de",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_avx2_256_8, "parasail_sg_de_table_diag_avx2_256_8", "sg_de",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_table_avx2 = {"parasail_sg_de_table_avx2", parasail_sg_de_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_de_table_altivec_functions[] = {
{parasail_sg_de_table,                "parasail_sg_de_table",                "sg_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_de_table_scan_altivec_128_64, "parasail_sg_de_table_scan_altivec_128_64", "sg_de",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_altivec_128_32, "parasail_sg_de_table_scan_altivec_128_32", "sg_de",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_altivec_128_16, "parasail_sg_de_table_scan_altivec_128_16", "sg_de",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_altivec_128_8, "parasail_sg_de_table_scan_altivec_128_8", "sg_de",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_altivec_128_64, "parasail_sg_de_table_striped_altivec_128_64", "sg_de", "striped", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_altivec_128_32, "parasail_sg_de_table_striped_altivec_128_32", "sg_de", "striped", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_altivec_128_16, "parasail_sg_de_table_striped_altivec_128_16", "sg_de", "striped", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_altivec_128_8, "parasail_sg_de_table_striped_altivec_128_8", "sg_de", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_altivec_128_64, "parasail_sg_de_table_diag_altivec_128_64", "sg_de",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_altivec_128_32, "parasail_sg_de_table_diag_altivec_128_32", "sg_de",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_altivec_128_16, "parasail_sg_de_table_diag_altivec_128_16", "sg_de",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_altivec_128_8, "parasail_sg_de_table_diag_altivec_128_8", "sg_de",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_table_altivec = {"parasail_sg_de_table_altivec", parasail_sg_de_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_de_table_neon_functions[] = {
{parasail_sg_de_table,                "parasail_sg_de_table",                "sg_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_de_table_scan_neon_128_64, "parasail_sg_de_table_scan_neon_128_64", "sg_de",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_neon_128_32, "parasail_sg_de_table_scan_neon_128_32", "sg_de",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_neon_128_16, "parasail_sg_de_table_scan_neon_128_16", "sg_de",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_neon_128_8, "parasail_sg_de_table_scan_neon_128_8", "sg_de",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_neon_128_64, "parasail_sg_de_table_striped_neon_128_64", "sg_de", "striped", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_neon_128_32, "parasail_sg_de_table_striped_neon_128_32", "sg_de", "striped", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_neon_128_16, "parasail_sg_de_table_striped_neon_128_16", "sg_de", "striped", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_neon_128_8, "parasail_sg_de_table_striped_neon_128_8", "sg_de", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_neon_128_64, "parasail_sg_de_table_diag_neon_128_64", "sg_de",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_neon_128_32, "parasail_sg_de_table_diag_neon_128_32", "sg_de",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_neon_128_16, "parasail_sg_de_table_diag_neon_128_16", "sg_de",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_neon_128_8, "parasail_sg_de_table_diag_neon_128_8", "sg_de",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_table_neon = {"parasail_sg_de_table_neon", parasail_sg_de_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_de_table_disp_functions[] = {
{parasail_sg_de_table,                "parasail_sg_de_table",                "sg_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_de_table_scan_64,        "parasail_sg_de_table_scan_64",        "sg_de",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_32,        "parasail_sg_de_table_scan_32",        "sg_de",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_16,        "parasail_sg_de_table_scan_16",        "sg_de",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_8,         "parasail_sg_de_table_scan_8",         "sg_de",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_64,     "parasail_sg_de_table_striped_64",     "sg_de", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_32,     "parasail_sg_de_table_striped_32",     "sg_de", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_16,     "parasail_sg_de_table_striped_16",     "sg_de", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_8,      "parasail_sg_de_table_striped_8",      "sg_de", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_64,        "parasail_sg_de_table_diag_64",        "sg_de",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_32,        "parasail_sg_de_table_diag_32",        "sg_de",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_16,        "parasail_sg_de_table_diag_16",        "sg_de",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_8,         "parasail_sg_de_table_diag_8",         "sg_de",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_scan_sat,       "parasail_sg_de_table_scan_sat",       "sg_de",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_striped_sat,    "parasail_sg_de_table_striped_sat",    "sg_de", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_de_table_diag_sat,       "parasail_sg_de_table_diag_sat",       "sg_de",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_table_disp = {"parasail_sg_de_table_disp", parasail_sg_de_table_disp_functions};
static parasail_function_info_t parasail_sg_de_table_serial_functions[] = {
{parasail_sg_de_table,                "parasail_sg_de_table",                "sg_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_de_table_scan,           "parasail_sg_de_table_scan",           "sg_de",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_table_serial = {"parasail_sg_de_table_serial", parasail_sg_de_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_dx_table_sse2_functions[] = {
{parasail_sg_dx_table,                "parasail_sg_dx_table",                "sg_dx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_dx_table_scan_sse2_128_64, "parasail_sg_dx_table_scan_sse2_128_64", "sg_dx",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_sse2_128_32, "parasail_sg_dx_table_scan_sse2_128_32", "sg_dx",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_sse2_128_16, "parasail_sg_dx_table_scan_sse2_128_16", "sg_dx",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_sse2_128_8, "parasail_sg_dx_table_scan_sse2_128_8", "sg_dx",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_sse2_128_64, "parasail_sg_dx_table_striped_sse2_128_64", "sg_dx", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_sse2_128_32, "parasail_sg_dx_table_striped_sse2_128_32", "sg_dx", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_sse2_128_16, "parasail_sg_dx_table_striped_sse2_128_16", "sg_dx", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_sse2_128_8, "parasail_sg_dx_table_striped_sse2_128_8", "sg_dx", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_sse2_128_64, "parasail_sg_dx_table_diag_sse2_128_64", "sg_dx",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_sse2_128_32, "parasail_sg_dx_table_diag_sse2_128_32", "sg_dx",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_sse2_128_16, "parasail_sg_dx_table_diag_sse2_128_16", "sg_dx",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_sse2_128_8, "parasail_sg_dx_table_diag_sse2_128_8", "sg_dx",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_table_sse2 = {"parasail_sg_dx_table_sse2", parasail_sg_dx_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_dx_table_sse41_functions[] = {
{parasail_sg_dx_table,                "parasail_sg_dx_table",                "sg_dx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_dx_table_scan_sse41_128_64, "parasail_sg_dx_table_scan_sse41_128_64", "sg_dx",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_sse41_128_32, "parasail_sg_dx_table_scan_sse41_128_32", "sg_dx",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_sse41_128_16, "parasail_sg_dx_table_scan_sse41_128_16", "sg_dx",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_sse41_128_8, "parasail_sg_dx_table_scan_sse41_128_8", "sg_dx",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_sse41_128_64, "parasail_sg_dx_table_striped_sse41_128_64", "sg_dx", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_sse41_128_32, "parasail_sg_dx_table_striped_sse41_128_32", "sg_dx", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_sse41_128_16, "parasail_sg_dx_table_striped_sse41_128_16", "sg_dx", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_sse41_128_8, "parasail_sg_dx_table_striped_sse41_128_8", "sg_dx", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_sse41_128_64, "parasail_sg_dx_table_diag_sse41_128_64", "sg_dx",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_sse41_128_32, "parasail_sg_dx_table_diag_sse41_128_32", "sg_dx",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_sse41_128_16, "parasail_sg_dx_table_diag_sse41_128_16", "sg_dx",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_sse41_128_8, "parasail_sg_dx_table_diag_sse41_128_8", "sg_dx",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_table_sse41 = {"parasail_sg_dx_table_sse41", parasail_sg_dx_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_dx_table_avx2_functions[] = {
{parasail_sg_dx_table,                "parasail_sg_dx_table",                "sg_dx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_dx_table_scan_avx2_256_64, "parasail_sg_dx_table_scan_avx2_256_64", "sg_dx",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_avx2_256_32, "parasail_sg_dx_table_scan_avx2_256_32", "sg_dx",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_avx2_256_16, "parasail_sg_dx_table_scan_avx2_256_16", "sg_dx",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_avx2_256_8, "parasail_sg_dx_table_scan_avx2_256_8", "sg_dx",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_avx2_256_64, "parasail_sg_dx_table_striped_avx2_256_64", "sg_dx", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_avx2_256_32, "parasail_sg_dx_table_striped_avx2_256_32", "sg_dx", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_avx2_256_16, "parasail_sg_dx_table_striped_avx2_256_16", "sg_dx", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_avx2_256_8, "parasail_sg_dx_table_striped_avx2_256_8", "sg_dx", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_avx2_256_64, "parasail_sg_dx_table_diag_avx2_256_64", "sg_dx",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_avx2_256_32, "parasail_sg_dx_table_diag_avx2_256_32", "sg_dx",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_avx2_256_16, "parasail_sg_dx_table_diag_avx2_256_16", "sg_dx",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_avx2_256_8, "parasail_sg_dx_table_diag_avx2_256_8", "sg_dx",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_table_avx2 = {"parasail_sg_dx_table_avx2", parasail_sg_dx_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_dx_table_altivec_functions[] = {
{parasail_sg_dx_table,                "parasail_sg_dx_table",                "sg_dx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_dx_table_scan_altivec_128_64, "parasail_sg_dx_table_scan_altivec_128_64", "sg_dx",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_altivec_128_32, "parasail_sg_dx_table_scan_altivec_128_32", "sg_dx",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_altivec_128_16, "parasail_sg_dx_table_scan_altivec_128_16", "sg_dx",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_altivec_128_8, "parasail_sg_dx_table_scan_altivec_128_8", "sg_dx",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_altivec_128_64, "parasail_sg_dx_table_striped_altivec_128_64", "sg_dx", "striped", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_altivec_128_32, "parasail_sg_dx_table_striped_altivec_128_32", "sg_dx", "striped", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_altivec_128_16, "parasail_sg_dx_table_striped_altivec_128_16", "sg_dx", "striped", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_altivec_128_8, "parasail_sg_dx_table_striped_altivec_128_8", "sg_dx", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_altivec_128_64, "parasail_sg_dx_table_diag_altivec_128_64", "sg_dx",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_altivec_128_32, "parasail_sg_dx_table_diag_altivec_128_32", "sg_dx",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_altivec_128_16, "parasail_sg_dx_table_diag_altivec_128_16", "sg_dx",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_altivec_128_8, "parasail_sg_dx_table_diag_altivec_128_8", "sg_dx",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_table_altivec = {"parasail_sg_dx_table_altivec", parasail_sg_dx_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_dx_table_neon_functions[] = {
{parasail_sg_dx_table,                "parasail_sg_dx_table",                "sg_dx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_dx_table_scan_neon_128_64, "parasail_sg_dx_table_scan_neon_128_64", "sg_dx",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_neon_128_32, "parasail_sg_dx_table_scan_neon_128_32", "sg_dx",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_neon_128_16, "parasail_sg_dx_table_scan_neon_128_16", "sg_dx",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_neon_128_8, "parasail_sg_dx_table_scan_neon_128_8", "sg_dx",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_neon_128_64, "parasail_sg_dx_table_striped_neon_128_64", "sg_dx", "striped", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_neon_128_32, "parasail_sg_dx_table_striped_neon_128_32", "sg_dx", "striped", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_neon_128_16, "parasail_sg_dx_table_striped_neon_128_16", "sg_dx", "striped", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_neon_128_8, "parasail_sg_dx_table_striped_neon_128_8", "sg_dx", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_neon_128_64, "parasail_sg_dx_table_diag_neon_128_64", "sg_dx",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_neon_128_32, "parasail_sg_dx_table_diag_neon_128_32", "sg_dx",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_neon_128_16, "parasail_sg_dx_table_diag_neon_128_16", "sg_dx",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_neon_128_8, "parasail_sg_dx_table_diag_neon_128_8", "sg_dx",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_table_neon = {"parasail_sg_dx_table_neon", parasail_sg_dx_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_dx_table_disp_functions[] = {
{parasail_sg_dx_table,                "parasail_sg_dx_table",                "sg_dx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_dx_table_scan_64,        "parasail_sg_dx_table_scan_64",        "sg_dx",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_32,        "parasail_sg_dx_table_scan_32",        "sg_dx",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_16,        "parasail_sg_dx_table_scan_16",        "sg_dx",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_8,         "parasail_sg_dx_table_scan_8",         "sg_dx",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_64,     "parasail_sg_dx_table_striped_64",     "sg_dx", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_32,     "parasail_sg_dx_table_striped_32",     "sg_dx", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_16,     "parasail_sg_dx_table_striped_16",     "sg_dx", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_8,      "parasail_sg_dx_table_striped_8",      "sg_dx", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_64,        "parasail_sg_dx_table_diag_64",        "sg_dx",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_32,        "parasail_sg_dx_table_diag_32",        "sg_dx",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_16,        "parasail_sg_dx_table_diag_16",        "sg_dx",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_8,         "parasail_sg_dx_table_diag_8",         "sg_dx",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_scan_sat,       "parasail_sg_dx_table_scan_sat",       "sg_dx",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_striped_sat,    "parasail_sg_dx_table_striped_sat",    "sg_dx", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_dx_table_diag_sat,       "parasail_sg_dx_table_diag_sat",       "sg_dx",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_table_disp = {"parasail_sg_dx_table_disp", parasail_sg_dx_table_disp_functions};
static parasail_function_info_t parasail_sg_dx_table_serial_functions[] = {
{parasail_sg_dx_table,                "parasail_sg_dx_table",                "sg_dx",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_dx_table_scan,           "parasail_sg_dx_table_scan",           "sg_dx",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_table_serial = {"parasail_sg_dx_table_serial", parasail_sg_dx_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_qb_de_table_sse2_functions[] = {
{parasail_sg_qb_de_table,             "parasail_sg_qb_de_table",             "sg_qb_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_de_table_scan_sse2_128_64, "parasail_sg_qb_de_table_scan_sse2_128_64", "sg_qb_de",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_sse2_128_32, "parasail_sg_qb_de_table_scan_sse2_128_32", "sg_qb_de",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_sse2_128_16, "parasail_sg_qb_de_table_scan_sse2_128_16", "sg_qb_de",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_sse2_128_8, "parasail_sg_qb_de_table_scan_sse2_128_8", "sg_qb_de",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_sse2_128_64, "parasail_sg_qb_de_table_striped_sse2_128_64", "sg_qb_de", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_sse2_128_32, "parasail_sg_qb_de_table_striped_sse2_128_32", "sg_qb_de", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_sse2_128_16, "parasail_sg_qb_de_table_striped_sse2_128_16", "sg_qb_de", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_sse2_128_8, "parasail_sg_qb_de_table_striped_sse2_128_8", "sg_qb_de", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_sse2_128_64, "parasail_sg_qb_de_table_diag_sse2_128_64", "sg_qb_de",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_sse2_128_32, "parasail_sg_qb_de_table_diag_sse2_128_32", "sg_qb_de",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_sse2_128_16, "parasail_sg_qb_de_table_diag_sse2_128_16", "sg_qb_de",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_sse2_128_8, "parasail_sg_qb_de_table_diag_sse2_128_8", "sg_qb_de",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_table_sse2 = {"parasail_sg_qb_de_table_sse2", parasail_sg_qb_de_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_qb_de_table_sse41_functions[] = {
{parasail_sg_qb_de_table,             "parasail_sg_qb_de_table",             "sg_qb_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_de_table_scan_sse41_128_64, "parasail_sg_qb_de_table_scan_sse41_128_64", "sg_qb_de",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_sse41_128_32, "parasail_sg_qb_de_table_scan_sse41_128_32", "sg_qb_de",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_sse41_128_16, "parasail_sg_qb_de_table_scan_sse41_128_16", "sg_qb_de",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_sse41_128_8, "parasail_sg_qb_de_table_scan_sse41_128_8", "sg_qb_de",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_sse41_128_64, "parasail_sg_qb_de_table_striped_sse41_128_64", "sg_qb_de", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_sse41_128_32, "parasail_sg_qb_de_table_striped_sse41_128_32", "sg_qb_de", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_sse41_128_16, "parasail_sg_qb_de_table_striped_sse41_128_16", "sg_qb_de", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_sse41_128_8, "parasail_sg_qb_de_table_striped_sse41_128_8", "sg_qb_de", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_sse41_128_64, "parasail_sg_qb_de_table_diag_sse41_128_64", "sg_qb_de",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_sse41_128_32, "parasail_sg_qb_de_table_diag_sse41_128_32", "sg_qb_de",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_sse41_128_16, "parasail_sg_qb_de_table_diag_sse41_128_16", "sg_qb_de",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_sse41_128_8, "parasail_sg_qb_de_table_diag_sse41_128_8", "sg_qb_de",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_table_sse41 = {"parasail_sg_qb_de_table_sse41", parasail_sg_qb_de_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_qb_de_table_avx2_functions[] = {
{parasail_sg_qb_de_table,             "parasail_sg_qb_de_table",             "sg_qb_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_de_table_scan_avx2_256_64, "parasail_sg_qb_de_table_scan_avx2_256_64", "sg_qb_de",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_avx2_256_32, "parasail_sg_qb_de_table_scan_avx2_256_32", "sg_qb_de",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_avx2_256_16, "parasail_sg_qb_de_table_scan_avx2_256_16", "sg_qb_de",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_avx2_256_8, "parasail_sg_qb_de_table_scan_avx2_256_8", "sg_qb_de",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_avx2_256_64, "parasail_sg_qb_de_table_striped_avx2_256_64", "sg_qb_de", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_avx2_256_32, "parasail_sg_qb_de_table_striped_avx2_256_32", "sg_qb_de", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_avx2_256_16, "parasail_sg_qb_de_table_striped_avx2_256_16", "sg_qb_de", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_avx2_256_8, "parasail_sg_qb_de_table_striped_avx2_256_8", "sg_qb_de", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_avx2_256_64, "parasail_sg_qb_de_table_diag_avx2_256_64", "sg_qb_de",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_avx2_256_32, "parasail_sg_qb_de_table_diag_avx2_256_32", "sg_qb_de",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_avx2_256_16, "parasail_sg_qb_de_table_diag_avx2_256_16", "sg_qb_de",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_avx2_256_8, "parasail_sg_qb_de_table_diag_avx2_256_8", "sg_qb_de",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_table_avx2 = {"parasail_sg_qb_de_table_avx2", parasail_sg_qb_de_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_qb_de_table_altivec_functions[] = {
{parasail_sg_qb_de_table,             "parasail_sg_qb_de_table",             "sg_qb_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_de_table_scan_altivec_128_64, "parasail_sg_qb_de_table_scan_altivec_128_64", "sg_qb_de",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_altivec_128_32, "parasail_sg_qb_de_table_scan_altivec_128_32", "sg_qb_de",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_altivec_128_16, "parasail_sg_qb_de_table_scan_altivec_128_16", "sg_qb_de",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_altivec_128_8, "parasail_sg_qb_de_table_scan_altivec_128_8", "sg_qb_de",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_altivec_128_64, "parasail_sg_qb_de_table_striped_altivec_128_64", "sg_qb_de", "striped", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_altivec_128_32, "parasail_sg_qb_de_table_striped_altivec_128_32", "sg_qb_de", "striped", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_altivec_128_16, "parasail_sg_qb_de_table_striped_altivec_128_16", "sg_qb_de", "striped", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_altivec_128_8, "parasail_sg_qb_de_table_striped_altivec_128_8", "sg_qb_de", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_altivec_128_64, "parasail_sg_qb_de_table_diag_altivec_128_64", "sg_qb_de",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_altivec_128_32, "parasail_sg_qb_de_table_diag_altivec_128_32", "sg_qb_de",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_altivec_128_16, "parasail_sg_qb_de_table_diag_altivec_128_16", "sg_qb_de",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_altivec_128_8, "parasail_sg_qb_de_table_diag_altivec_128_8", "sg_qb_de",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_table_altivec = {"parasail_sg_qb_de_table_altivec", parasail_sg_qb_de_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_qb_de_table_neon_functions[] = {
{parasail_sg_qb_de_table,             "parasail_sg_qb_de_table",             "sg_qb_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_de_table_scan_neon_128_64, "parasail_sg_qb_de_table_scan_neon_128_64", "sg_qb_de",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_neon_128_32, "parasail_sg_qb_de_table_scan_neon_128_32", "sg_qb_de",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_neon_128_16, "parasail_sg_qb_de_table_scan_neon_128_16", "sg_qb_de",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_neon_128_8, "parasail_sg_qb_de_table_scan_neon_128_8", "sg_qb_de",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_neon_128_64, "parasail_sg_qb_de_table_striped_neon_128_64", "sg_qb_de", "striped", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_neon_128_32, "parasail_sg_qb_de_table_striped_neon_128_32", "sg_qb_de", "striped", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_neon_128_16, "parasail_sg_qb_de_table_striped_neon_128_16", "sg_qb_de", "striped", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_neon_128_8, "parasail_sg_qb_de_table_striped_neon_128_8", "sg_qb_de", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_neon_128_64, "parasail_sg_qb_de_table_diag_neon_128_64", "sg_qb_de",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_neon_128_32, "parasail_sg_qb_de_table_diag_neon_128_32", "sg_qb_de",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_neon_128_16, "parasail_sg_qb_de_table_diag_neon_128_16", "sg_qb_de",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_neon_128_8, "parasail_sg_qb_de_table_diag_neon_128_8", "sg_qb_de",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_table_neon = {"parasail_sg_qb_de_table_neon", parasail_sg_qb_de_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_qb_de_table_disp_functions[] = {
{parasail_sg_qb_de_table,             "parasail_sg_qb_de_table",             "sg_qb_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_de_table_scan_64,     "parasail_sg_qb_de_table_scan_64",     "sg_qb_de",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_32,     "parasail_sg_qb_de_table_scan_32",     "sg_qb_de",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_16,     "parasail_sg_qb_de_table_scan_16",     "sg_qb_de",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_8,      "parasail_sg_qb_de_table_scan_8",      "sg_qb_de",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_64,  "parasail_sg_qb_de_table_striped_64",  "sg_qb_de", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_32,  "parasail_sg_qb_de_table_striped_32",  "sg_qb_de", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_16,  "parasail_sg_qb_de_table_striped_16",  "sg_qb_de", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_8,   "parasail_sg_qb_de_table_striped_8",   "sg_qb_de", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_64,     "parasail_sg_qb_de_table_diag_64",     "sg_qb_de",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_32,     "parasail_sg_qb_de_table_diag_32",     "sg_qb_de",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_16,     "parasail_sg_qb_de_table_diag_16",     "sg_qb_de",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_8,      "parasail_sg_qb_de_table_diag_8",      "sg_qb_de",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_scan_sat,    "parasail_sg_qb_de_table_scan_sat",    "sg_qb_de",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_striped_sat, "parasail_sg_qb_de_table_striped_sat", "sg_qb_de", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qb_de_table_diag_sat,    "parasail_sg_qb_de_table_diag_sat",    "sg_qb_de",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_table_disp = {"parasail_sg_qb_de_table_disp", parasail_sg_qb_de_table_disp_functions};
static parasail_function_info_t parasail_sg_qb_de_table_serial_functions[] = {
{parasail_sg_qb_de_table,             "parasail_sg_qb_de_table",             "sg_qb_de",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qb_de_table_scan,        "parasail_sg_qb_de_table_scan",        "sg_qb_de",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_table_serial = {"parasail_sg_qb_de_table_serial", parasail_sg_qb_de_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_qe_db_table_sse2_functions[] = {
{parasail_sg_qe_db_table,             "parasail_sg_qe_db_table",             "sg_qe_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_db_table_scan_sse2_128_64, "parasail_sg_qe_db_table_scan_sse2_128_64", "sg_qe_db",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_sse2_128_32, "parasail_sg_qe_db_table_scan_sse2_128_32", "sg_qe_db",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_sse2_128_16, "parasail_sg_qe_db_table_scan_sse2_128_16", "sg_qe_db",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_sse2_128_8, "parasail_sg_qe_db_table_scan_sse2_128_8", "sg_qe_db",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_sse2_128_64, "parasail_sg_qe_db_table_striped_sse2_128_64", "sg_qe_db", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_sse2_128_32, "parasail_sg_qe_db_table_striped_sse2_128_32", "sg_qe_db", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_sse2_128_16, "parasail_sg_qe_db_table_striped_sse2_128_16", "sg_qe_db", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_sse2_128_8, "parasail_sg_qe_db_table_striped_sse2_128_8", "sg_qe_db", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_sse2_128_64, "parasail_sg_qe_db_table_diag_sse2_128_64", "sg_qe_db",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_sse2_128_32, "parasail_sg_qe_db_table_diag_sse2_128_32", "sg_qe_db",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_sse2_128_16, "parasail_sg_qe_db_table_diag_sse2_128_16", "sg_qe_db",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_sse2_128_8, "parasail_sg_qe_db_table_diag_sse2_128_8", "sg_qe_db",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_table_sse2 = {"parasail_sg_qe_db_table_sse2", parasail_sg_qe_db_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_qe_db_table_sse41_functions[] = {
{parasail_sg_qe_db_table,             "parasail_sg_qe_db_table",             "sg_qe_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_db_table_scan_sse41_128_64, "parasail_sg_qe_db_table_scan_sse41_128_64", "sg_qe_db",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_sse41_128_32, "parasail_sg_qe_db_table_scan_sse41_128_32", "sg_qe_db",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_sse41_128_16, "parasail_sg_qe_db_table_scan_sse41_128_16", "sg_qe_db",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_sse41_128_8, "parasail_sg_qe_db_table_scan_sse41_128_8", "sg_qe_db",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_sse41_128_64, "parasail_sg_qe_db_table_striped_sse41_128_64", "sg_qe_db", "striped", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_sse41_128_32, "parasail_sg_qe_db_table_striped_sse41_128_32", "sg_qe_db", "striped", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_sse41_128_16, "parasail_sg_qe_db_table_striped_sse41_128_16", "sg_qe_db", "striped", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_sse41_128_8, "parasail_sg_qe_db_table_striped_sse41_128_8", "sg_qe_db", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_sse41_128_64, "parasail_sg_qe_db_table_diag_sse41_128_64", "sg_qe_db",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_sse41_128_32, "parasail_sg_qe_db_table_diag_sse41_128_32", "sg_qe_db",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_sse41_128_16, "parasail_sg_qe_db_table_diag_sse41_128_16", "sg_qe_db",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_sse41_128_8, "parasail_sg_qe_db_table_diag_sse41_128_8", "sg_qe_db",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_table_sse41 = {"parasail_sg_qe_db_table_sse41", parasail_sg_qe_db_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_qe_db_table_avx2_functions[] = {
{parasail_sg_qe_db_table,             "parasail_sg_qe_db_table",             "sg_qe_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_db_table_scan_avx2_256_64, "parasail_sg_qe_db_table_scan_avx2_256_64", "sg_qe_db",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_avx2_256_32, "parasail_sg_qe_db_table_scan_avx2_256_32", "sg_qe_db",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_avx2_256_16, "parasail_sg_qe_db_table_scan_avx2_256_16", "sg_qe_db",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_avx2_256_8, "parasail_sg_qe_db_table_scan_avx2_256_8", "sg_qe_db",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_avx2_256_64, "parasail_sg_qe_db_table_striped_avx2_256_64", "sg_qe_db", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_avx2_256_32, "parasail_sg_qe_db_table_striped_avx2_256_32", "sg_qe_db", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_avx2_256_16, "parasail_sg_qe_db_table_striped_avx2_256_16", "sg_qe_db", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_avx2_256_8, "parasail_sg_qe_db_table_striped_avx2_256_8", "sg_qe_db", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_avx2_256_64, "parasail_sg_qe_db_table_diag_avx2_256_64", "sg_qe_db",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_avx2_256_32, "parasail_sg_qe_db_table_diag_avx2_256_32", "sg_qe_db",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_avx2_256_16, "parasail_sg_qe_db_table_diag_avx2_256_16", "sg_qe_db",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_avx2_256_8, "parasail_sg_qe_db_table_diag_avx2_256_8", "sg_qe_db",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_table_avx2 = {"parasail_sg_qe_db_table_avx2", parasail_sg_qe_db_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_qe_db_table_altivec_functions[] = {
{parasail_sg_qe_db_table,             "parasail_sg_qe_db_table",             "sg_qe_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_db_table_scan_altivec_128_64, "parasail_sg_qe_db_table_scan_altivec_128_64", "sg_qe_db",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_altivec_128_32, "parasail_sg_qe_db_table_scan_altivec_128_32", "sg_qe_db",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_altivec_128_16, "parasail_sg_qe_db_table_scan_altivec_128_16", "sg_qe_db",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_altivec_128_8, "parasail_sg_qe_db_table_scan_altivec_128_8", "sg_qe_db",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_altivec_128_64, "parasail_sg_qe_db_table_striped_altivec_128_64", "sg_qe_db", "striped", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_altivec_128_32, "parasail_sg_qe_db_table_striped_altivec_128_32", "sg_qe_db", "striped", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_altivec_128_16, "parasail_sg_qe_db_table_striped_altivec_128_16", "sg_qe_db", "striped", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_altivec_128_8, "parasail_sg_qe_db_table_striped_altivec_128_8", "sg_qe_db", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_altivec_128_64, "parasail_sg_qe_db_table_diag_altivec_128_64", "sg_qe_db",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_altivec_128_32, "parasail_sg_qe_db_table_diag_altivec_128_32", "sg_qe_db",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_altivec_128_16, "parasail_sg_qe_db_table_diag_altivec_128_16", "sg_qe_db",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_altivec_128_8, "parasail_sg_qe_db_table_diag_altivec_128_8", "sg_qe_db",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_table_altivec = {"parasail_sg_qe_db_table_altivec", parasail_sg_qe_db_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_qe_db_table_neon_functions[] = {
{parasail_sg_qe_db_table,             "parasail_sg_qe_db_table",             "sg_qe_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_db_table_scan_neon_128_64, "parasail_sg_qe_db_table_scan_neon_128_64", "sg_qe_db",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_neon_128_32, "parasail_sg_qe_db_table_scan_neon_128_32", "sg_qe_db",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_neon_128_16, "parasail_sg_qe_db_table_scan_neon_128_16", "sg_qe_db",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_neon_128_8, "parasail_sg_qe_db_table_scan_neon_128_8", "sg_qe_db",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_neon_128_64, "parasail_sg_qe_db_table_striped_neon_128_64", "sg_qe_db", "striped", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_neon_128_32, "parasail_sg_qe_db_table_striped_neon_128_32", "sg_qe_db", "striped", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_neon_128_16, "parasail_sg_qe_db_table_striped_neon_128_16", "sg_qe_db", "striped", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_neon_128_8, "parasail_sg_qe_db_table_striped_neon_128_8", "sg_qe_db", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_neon_128_64, "parasail_sg_qe_db_table_diag_neon_128_64", "sg_qe_db",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_neon_128_32, "parasail_sg_qe_db_table_diag_neon_128_32", "sg_qe_db",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_neon_128_16, "parasail_sg_qe_db_table_diag_neon_128_16", "sg_qe_db",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_neon_128_8, "parasail_sg_qe_db_table_diag_neon_128_8", "sg_qe_db",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_table_neon = {"parasail_sg_qe_db_table_neon", parasail_sg_qe_db_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_qe_db_table_disp_functions[] = {
{parasail_sg_qe_db_table,             "parasail_sg_qe_db_table",             "sg_qe_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_db_table_scan_64,     "parasail_sg_qe_db_table_scan_64",     "sg_qe_db",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_32,     "parasail_sg_qe_db_table_scan_32",     "sg_qe_db",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_16,     "parasail_sg_qe_db_table_scan_16",     "sg_qe_db",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_8,      "parasail_sg_qe_db_table_scan_8",      "sg_qe_db",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_64,  "parasail_sg_qe_db_table_striped_64",  "sg_qe_db", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_32,  "parasail_sg_qe_db_table_striped_32",  "sg_qe_db", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_16,  "parasail_sg_qe_db_table_striped_16",  "sg_qe_db", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_8,   "parasail_sg_qe_db_table_striped_8",   "sg_qe_db", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_64,     "parasail_sg_qe_db_table_diag_64",     "sg_qe_db",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_32,     "parasail_sg_qe_db_table_diag_32",     "sg_qe_db",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_16,     "parasail_sg_qe_db_table_diag_16",     "sg_qe_db",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_8,      "parasail_sg_qe_db_table_diag_8",      "sg_qe_db",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_scan_sat,    "parasail_sg_qe_db_table_scan_sat",    "sg_qe_db",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_striped_sat, "parasail_sg_qe_db_table_striped_sat", "sg_qe_db", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{parasail_sg_qe_db_table_diag_sat,    "parasail_sg_qe_db_table_diag_sat",    "sg_qe_db",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_table_disp = {"parasail_sg_qe_db_table_disp", parasail_sg_qe_db_table_disp_functions};
static parasail_function_info_t parasail_sg_qe_db_table_serial_functions[] = {
{parasail_sg_qe_db_table,             "parasail_sg_qe_db_table",             "sg_qe_db",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 0, 1},
{parasail_sg_qe_db_table_scan,        "parasail_sg_qe_db_table_scan",        "sg_qe_db",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 0, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_table_serial = {"parasail_sg_qe_db_table_serial", parasail_sg_qe_db_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_nw_stats_table_sse2_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan_sse2_128_64, "parasail_nw_stats_table_scan_sse2_128_64", "nw_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse2_128_32, "parasail_nw_stats_table_scan_sse2_128_32", "nw_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse2_128_16, "parasail_nw_stats_table_scan_sse2_128_16", "nw_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse2_128_8, "parasail_nw_stats_table_scan_sse2_128_8", "nw_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse2_128_64, "parasail_nw_stats_table_striped_sse2_128_64", "nw_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse2_128_32, "parasail_nw_stats_table_striped_sse2_128_32", "nw_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse2_128_16, "parasail_nw_stats_table_striped_sse2_128_16", "nw_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse2_128_8, "parasail_nw_stats_table_striped_sse2_128_8", "nw_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse2_128_64, "parasail_nw_stats_table_diag_sse2_128_64", "nw_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse2_128_32, "parasail_nw_stats_table_diag_sse2_128_32", "nw_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse2_128_16, "parasail_nw_stats_table_diag_sse2_128_16", "nw_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse2_128_8, "parasail_nw_stats_table_diag_sse2_128_8", "nw_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_sse2 = {"parasail_nw_stats_table_sse2", parasail_nw_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_nw_stats_table_sse41_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan_sse41_128_64, "parasail_nw_stats_table_scan_sse41_128_64", "nw_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse41_128_32, "parasail_nw_stats_table_scan_sse41_128_32", "nw_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse41_128_16, "parasail_nw_stats_table_scan_sse41_128_16", "nw_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sse41_128_8, "parasail_nw_stats_table_scan_sse41_128_8", "nw_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse41_128_64, "parasail_nw_stats_table_striped_sse41_128_64", "nw_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse41_128_32, "parasail_nw_stats_table_striped_sse41_128_32", "nw_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse41_128_16, "parasail_nw_stats_table_striped_sse41_128_16", "nw_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sse41_128_8, "parasail_nw_stats_table_striped_sse41_128_8", "nw_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse41_128_64, "parasail_nw_stats_table_diag_sse41_128_64", "nw_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse41_128_32, "parasail_nw_stats_table_diag_sse41_128_32", "nw_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse41_128_16, "parasail_nw_stats_table_diag_sse41_128_16", "nw_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sse41_128_8, "parasail_nw_stats_table_diag_sse41_128_8", "nw_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_sse41 = {"parasail_nw_stats_table_sse41", parasail_nw_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_nw_stats_table_avx2_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan_avx2_256_64, "parasail_nw_stats_table_scan_avx2_256_64", "nw_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_avx2_256_32, "parasail_nw_stats_table_scan_avx2_256_32", "nw_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_avx2_256_16, "parasail_nw_stats_table_scan_avx2_256_16", "nw_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_avx2_256_8, "parasail_nw_stats_table_scan_avx2_256_8", "nw_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_avx2_256_64, "parasail_nw_stats_table_striped_avx2_256_64", "nw_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_avx2_256_32, "parasail_nw_stats_table_striped_avx2_256_32", "nw_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_avx2_256_16, "parasail_nw_stats_table_striped_avx2_256_16", "nw_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_avx2_256_8, "parasail_nw_stats_table_striped_avx2_256_8", "nw_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_avx2_256_64, "parasail_nw_stats_table_diag_avx2_256_64", "nw_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_avx2_256_32, "parasail_nw_stats_table_diag_avx2_256_32", "nw_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_avx2_256_16, "parasail_nw_stats_table_diag_avx2_256_16", "nw_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_avx2_256_8, "parasail_nw_stats_table_diag_avx2_256_8", "nw_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_avx2 = {"parasail_nw_stats_table_avx2", parasail_nw_stats_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_nw_stats_table_altivec_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan_altivec_128_64, "parasail_nw_stats_table_scan_altivec_128_64", "nw_stats",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_altivec_128_32, "parasail_nw_stats_table_scan_altivec_128_32", "nw_stats",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_altivec_128_16, "parasail_nw_stats_table_scan_altivec_128_16", "nw_stats",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_altivec_128_8, "parasail_nw_stats_table_scan_altivec_128_8", "nw_stats",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_altivec_128_64, "parasail_nw_stats_table_striped_altivec_128_64", "nw_stats", "striped", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_altivec_128_32, "parasail_nw_stats_table_striped_altivec_128_32", "nw_stats", "striped", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_altivec_128_16, "parasail_nw_stats_table_striped_altivec_128_16", "nw_stats", "striped", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_altivec_128_8, "parasail_nw_stats_table_striped_altivec_128_8", "nw_stats", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_altivec_128_64, "parasail_nw_stats_table_diag_altivec_128_64", "nw_stats",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_altivec_128_32, "parasail_nw_stats_table_diag_altivec_128_32", "nw_stats",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_altivec_128_16, "parasail_nw_stats_table_diag_altivec_128_16", "nw_stats",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_altivec_128_8, "parasail_nw_stats_table_diag_altivec_128_8", "nw_stats",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_altivec = {"parasail_nw_stats_table_altivec", parasail_nw_stats_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_nw_stats_table_neon_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan_neon_128_64, "parasail_nw_stats_table_scan_neon_128_64", "nw_stats",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_neon_128_32, "parasail_nw_stats_table_scan_neon_128_32", "nw_stats",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_neon_128_16, "parasail_nw_stats_table_scan_neon_128_16", "nw_stats",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_neon_128_8, "parasail_nw_stats_table_scan_neon_128_8", "nw_stats",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_neon_128_64, "parasail_nw_stats_table_striped_neon_128_64", "nw_stats", "striped", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_neon_128_32, "parasail_nw_stats_table_striped_neon_128_32", "nw_stats", "striped", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_neon_128_16, "parasail_nw_stats_table_striped_neon_128_16", "nw_stats", "striped", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_neon_128_8, "parasail_nw_stats_table_striped_neon_128_8", "nw_stats", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_neon_128_64, "parasail_nw_stats_table_diag_neon_128_64", "nw_stats",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_neon_128_32, "parasail_nw_stats_table_diag_neon_128_32", "nw_stats",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_neon_128_16, "parasail_nw_stats_table_diag_neon_128_16", "nw_stats",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_neon_128_8, "parasail_nw_stats_table_diag_neon_128_8", "nw_stats",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_neon = {"parasail_nw_stats_table_neon", parasail_nw_stats_table_neon_functions};
#endif
static parasail_function_info_t parasail_nw_stats_table_disp_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan_64,     "parasail_nw_stats_table_scan_64",     "nw_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_32,     "parasail_nw_stats_table_scan_32",     "nw_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_16,     "parasail_nw_stats_table_scan_16",     "nw_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_8,      "parasail_nw_stats_table_scan_8",      "nw_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_64,  "parasail_nw_stats_table_striped_64",  "nw_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_32,  "parasail_nw_stats_table_striped_32",  "nw_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_16,  "parasail_nw_stats_table_striped_16",  "nw_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_8,   "parasail_nw_stats_table_striped_8",   "nw_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_64,     "parasail_nw_stats_table_diag_64",     "nw_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_32,     "parasail_nw_stats_table_diag_32",     "nw_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_16,     "parasail_nw_stats_table_diag_16",     "nw_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_8,      "parasail_nw_stats_table_diag_8",      "nw_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_scan_sat,    "parasail_nw_stats_table_scan_sat",    "nw_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_striped_sat, "parasail_nw_stats_table_striped_sat", "nw_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_nw_stats_table_diag_sat,    "parasail_nw_stats_table_diag_sat",    "nw_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_disp = {"parasail_nw_stats_table_disp", parasail_nw_stats_table_disp_functions};
static parasail_function_info_t parasail_nw_stats_table_serial_functions[] = {
{parasail_nw_stats_table,             "parasail_nw_stats_table",             "nw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_nw_stats_table_scan,        "parasail_nw_stats_table_scan",        "nw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_nw_stats_table_serial = {"parasail_nw_stats_table_serial", parasail_nw_stats_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_stats_table_sse2_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan_sse2_128_64, "parasail_sg_stats_table_scan_sse2_128_64", "sg_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse2_128_32, "parasail_sg_stats_table_scan_sse2_128_32", "sg_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse2_128_16, "parasail_sg_stats_table_scan_sse2_128_16", "sg_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse2_128_8, "parasail_sg_stats_table_scan_sse2_128_8", "sg_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse2_128_64, "parasail_sg_stats_table_striped_sse2_128_64", "sg_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse2_128_32, "parasail_sg_stats_table_striped_sse2_128_32", "sg_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse2_128_16, "parasail_sg_stats_table_striped_sse2_128_16", "sg_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse2_128_8, "parasail_sg_stats_table_striped_sse2_128_8", "sg_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse2_128_64, "parasail_sg_stats_table_diag_sse2_128_64", "sg_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse2_128_32, "parasail_sg_stats_table_diag_sse2_128_32", "sg_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse2_128_16, "parasail_sg_stats_table_diag_sse2_128_16", "sg_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse2_128_8, "parasail_sg_stats_table_diag_sse2_128_8", "sg_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_sse2 = {"parasail_sg_stats_table_sse2", parasail_sg_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_stats_table_sse41_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan_sse41_128_64, "parasail_sg_stats_table_scan_sse41_128_64", "sg_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse41_128_32, "parasail_sg_stats_table_scan_sse41_128_32", "sg_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse41_128_16, "parasail_sg_stats_table_scan_sse41_128_16", "sg_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sse41_128_8, "parasail_sg_stats_table_scan_sse41_128_8", "sg_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse41_128_64, "parasail_sg_stats_table_striped_sse41_128_64", "sg_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse41_128_32, "parasail_sg_stats_table_striped_sse41_128_32", "sg_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse41_128_16, "parasail_sg_stats_table_striped_sse41_128_16", "sg_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sse41_128_8, "parasail_sg_stats_table_striped_sse41_128_8", "sg_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse41_128_64, "parasail_sg_stats_table_diag_sse41_128_64", "sg_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse41_128_32, "parasail_sg_stats_table_diag_sse41_128_32", "sg_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse41_128_16, "parasail_sg_stats_table_diag_sse41_128_16", "sg_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sse41_128_8, "parasail_sg_stats_table_diag_sse41_128_8", "sg_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_sse41 = {"parasail_sg_stats_table_sse41", parasail_sg_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_stats_table_avx2_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan_avx2_256_64, "parasail_sg_stats_table_scan_avx2_256_64", "sg_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_avx2_256_32, "parasail_sg_stats_table_scan_avx2_256_32", "sg_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_avx2_256_16, "parasail_sg_stats_table_scan_avx2_256_16", "sg_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_avx2_256_8, "parasail_sg_stats_table_scan_avx2_256_8", "sg_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_avx2_256_64, "parasail_sg_stats_table_striped_avx2_256_64", "sg_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_avx2_256_32, "parasail_sg_stats_table_striped_avx2_256_32", "sg_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_avx2_256_16, "parasail_sg_stats_table_striped_avx2_256_16", "sg_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_avx2_256_8, "parasail_sg_stats_table_striped_avx2_256_8", "sg_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_avx2_256_64, "parasail_sg_stats_table_diag_avx2_256_64", "sg_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_avx2_256_32, "parasail_sg_stats_table_diag_avx2_256_32", "sg_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_avx2_256_16, "parasail_sg_stats_table_diag_avx2_256_16", "sg_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_avx2_256_8, "parasail_sg_stats_table_diag_avx2_256_8", "sg_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_avx2 = {"parasail_sg_stats_table_avx2", parasail_sg_stats_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_stats_table_altivec_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan_altivec_128_64, "parasail_sg_stats_table_scan_altivec_128_64", "sg_stats",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_altivec_128_32, "parasail_sg_stats_table_scan_altivec_128_32", "sg_stats",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_altivec_128_16, "parasail_sg_stats_table_scan_altivec_128_16", "sg_stats",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_altivec_128_8, "parasail_sg_stats_table_scan_altivec_128_8", "sg_stats",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_altivec_128_64, "parasail_sg_stats_table_striped_altivec_128_64", "sg_stats", "striped", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_altivec_128_32, "parasail_sg_stats_table_striped_altivec_128_32", "sg_stats", "striped", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_altivec_128_16, "parasail_sg_stats_table_striped_altivec_128_16", "sg_stats", "striped", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_altivec_128_8, "parasail_sg_stats_table_striped_altivec_128_8", "sg_stats", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_altivec_128_64, "parasail_sg_stats_table_diag_altivec_128_64", "sg_stats",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_altivec_128_32, "parasail_sg_stats_table_diag_altivec_128_32", "sg_stats",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_altivec_128_16, "parasail_sg_stats_table_diag_altivec_128_16", "sg_stats",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_altivec_128_8, "parasail_sg_stats_table_diag_altivec_128_8", "sg_stats",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_altivec = {"parasail_sg_stats_table_altivec", parasail_sg_stats_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_stats_table_neon_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan_neon_128_64, "parasail_sg_stats_table_scan_neon_128_64", "sg_stats",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_neon_128_32, "parasail_sg_stats_table_scan_neon_128_32", "sg_stats",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_neon_128_16, "parasail_sg_stats_table_scan_neon_128_16", "sg_stats",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_neon_128_8, "parasail_sg_stats_table_scan_neon_128_8", "sg_stats",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_neon_128_64, "parasail_sg_stats_table_striped_neon_128_64", "sg_stats", "striped", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_neon_128_32, "parasail_sg_stats_table_striped_neon_128_32", "sg_stats", "striped", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_neon_128_16, "parasail_sg_stats_table_striped_neon_128_16", "sg_stats", "striped", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_neon_128_8, "parasail_sg_stats_table_striped_neon_128_8", "sg_stats", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_neon_128_64, "parasail_sg_stats_table_diag_neon_128_64", "sg_stats",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_neon_128_32, "parasail_sg_stats_table_diag_neon_128_32", "sg_stats",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_neon_128_16, "parasail_sg_stats_table_diag_neon_128_16", "sg_stats",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_neon_128_8, "parasail_sg_stats_table_diag_neon_128_8", "sg_stats",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_neon = {"parasail_sg_stats_table_neon", parasail_sg_stats_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_stats_table_disp_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan_64,     "parasail_sg_stats_table_scan_64",     "sg_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_32,     "parasail_sg_stats_table_scan_32",     "sg_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_16,     "parasail_sg_stats_table_scan_16",     "sg_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_8,      "parasail_sg_stats_table_scan_8",      "sg_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_64,  "parasail_sg_stats_table_striped_64",  "sg_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_32,  "parasail_sg_stats_table_striped_32",  "sg_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_16,  "parasail_sg_stats_table_striped_16",  "sg_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_8,   "parasail_sg_stats_table_striped_8",   "sg_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_64,     "parasail_sg_stats_table_diag_64",     "sg_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_32,     "parasail_sg_stats_table_diag_32",     "sg_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_16,     "parasail_sg_stats_table_diag_16",     "sg_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_8,      "parasail_sg_stats_table_diag_8",      "sg_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_scan_sat,    "parasail_sg_stats_table_scan_sat",    "sg_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_striped_sat, "parasail_sg_stats_table_striped_sat", "sg_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_stats_table_diag_sat,    "parasail_sg_stats_table_diag_sat",    "sg_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_disp = {"parasail_sg_stats_table_disp", parasail_sg_stats_table_disp_functions};
static parasail_function_info_t parasail_sg_stats_table_serial_functions[] = {
{parasail_sg_stats_table,             "parasail_sg_stats_table",             "sg_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_stats_table_scan,        "parasail_sg_stats_table_scan",        "sg_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_stats_table_serial = {"parasail_sg_stats_table_serial", parasail_sg_stats_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sw_stats_table_sse2_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan_sse2_128_64, "parasail_sw_stats_table_scan_sse2_128_64", "sw_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse2_128_32, "parasail_sw_stats_table_scan_sse2_128_32", "sw_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse2_128_16, "parasail_sw_stats_table_scan_sse2_128_16", "sw_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse2_128_8, "parasail_sw_stats_table_scan_sse2_128_8", "sw_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse2_128_64, "parasail_sw_stats_table_striped_sse2_128_64", "sw_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse2_128_32, "parasail_sw_stats_table_striped_sse2_128_32", "sw_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse2_128_16, "parasail_sw_stats_table_striped_sse2_128_16", "sw_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse2_128_8, "parasail_sw_stats_table_striped_sse2_128_8", "sw_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse2_128_64, "parasail_sw_stats_table_diag_sse2_128_64", "sw_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse2_128_32, "parasail_sw_stats_table_diag_sse2_128_32", "sw_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse2_128_16, "parasail_sw_stats_table_diag_sse2_128_16", "sw_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse2_128_8, "parasail_sw_stats_table_diag_sse2_128_8", "sw_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_sse2 = {"parasail_sw_stats_table_sse2", parasail_sw_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sw_stats_table_sse41_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan_sse41_128_64, "parasail_sw_stats_table_scan_sse41_128_64", "sw_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse41_128_32, "parasail_sw_stats_table_scan_sse41_128_32", "sw_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse41_128_16, "parasail_sw_stats_table_scan_sse41_128_16", "sw_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sse41_128_8, "parasail_sw_stats_table_scan_sse41_128_8", "sw_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse41_128_64, "parasail_sw_stats_table_striped_sse41_128_64", "sw_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse41_128_32, "parasail_sw_stats_table_striped_sse41_128_32", "sw_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse41_128_16, "parasail_sw_stats_table_striped_sse41_128_16", "sw_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sse41_128_8, "parasail_sw_stats_table_striped_sse41_128_8", "sw_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse41_128_64, "parasail_sw_stats_table_diag_sse41_128_64", "sw_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse41_128_32, "parasail_sw_stats_table_diag_sse41_128_32", "sw_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse41_128_16, "parasail_sw_stats_table_diag_sse41_128_16", "sw_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sse41_128_8, "parasail_sw_stats_table_diag_sse41_128_8", "sw_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_sse41 = {"parasail_sw_stats_table_sse41", parasail_sw_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sw_stats_table_avx2_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan_avx2_256_64, "parasail_sw_stats_table_scan_avx2_256_64", "sw_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_avx2_256_32, "parasail_sw_stats_table_scan_avx2_256_32", "sw_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_avx2_256_16, "parasail_sw_stats_table_scan_avx2_256_16", "sw_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_avx2_256_8, "parasail_sw_stats_table_scan_avx2_256_8", "sw_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_avx2_256_64, "parasail_sw_stats_table_striped_avx2_256_64", "sw_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_avx2_256_32, "parasail_sw_stats_table_striped_avx2_256_32", "sw_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_avx2_256_16, "parasail_sw_stats_table_striped_avx2_256_16", "sw_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_avx2_256_8, "parasail_sw_stats_table_striped_avx2_256_8", "sw_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_avx2_256_64, "parasail_sw_stats_table_diag_avx2_256_64", "sw_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_avx2_256_32, "parasail_sw_stats_table_diag_avx2_256_32", "sw_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_avx2_256_16, "parasail_sw_stats_table_diag_avx2_256_16", "sw_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_avx2_256_8, "parasail_sw_stats_table_diag_avx2_256_8", "sw_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_avx2 = {"parasail_sw_stats_table_avx2", parasail_sw_stats_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sw_stats_table_altivec_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan_altivec_128_64, "parasail_sw_stats_table_scan_altivec_128_64", "sw_stats",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_altivec_128_32, "parasail_sw_stats_table_scan_altivec_128_32", "sw_stats",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_altivec_128_16, "parasail_sw_stats_table_scan_altivec_128_16", "sw_stats",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_altivec_128_8, "parasail_sw_stats_table_scan_altivec_128_8", "sw_stats",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_altivec_128_64, "parasail_sw_stats_table_striped_altivec_128_64", "sw_stats", "striped", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_altivec_128_32, "parasail_sw_stats_table_striped_altivec_128_32", "sw_stats", "striped", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_altivec_128_16, "parasail_sw_stats_table_striped_altivec_128_16", "sw_stats", "striped", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_altivec_128_8, "parasail_sw_stats_table_striped_altivec_128_8", "sw_stats", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_altivec_128_64, "parasail_sw_stats_table_diag_altivec_128_64", "sw_stats",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_altivec_128_32, "parasail_sw_stats_table_diag_altivec_128_32", "sw_stats",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_altivec_128_16, "parasail_sw_stats_table_diag_altivec_128_16", "sw_stats",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_altivec_128_8, "parasail_sw_stats_table_diag_altivec_128_8", "sw_stats",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_altivec = {"parasail_sw_stats_table_altivec", parasail_sw_stats_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sw_stats_table_neon_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan_neon_128_64, "parasail_sw_stats_table_scan_neon_128_64", "sw_stats",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_neon_128_32, "parasail_sw_stats_table_scan_neon_128_32", "sw_stats",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_neon_128_16, "parasail_sw_stats_table_scan_neon_128_16", "sw_stats",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_neon_128_8, "parasail_sw_stats_table_scan_neon_128_8", "sw_stats",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_neon_128_64, "parasail_sw_stats_table_striped_neon_128_64", "sw_stats", "striped", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_neon_128_32, "parasail_sw_stats_table_striped_neon_128_32", "sw_stats", "striped", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_neon_128_16, "parasail_sw_stats_table_striped_neon_128_16", "sw_stats", "striped", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_neon_128_8, "parasail_sw_stats_table_striped_neon_128_8", "sw_stats", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_neon_128_64, "parasail_sw_stats_table_diag_neon_128_64", "sw_stats",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_neon_128_32, "parasail_sw_stats_table_diag_neon_128_32", "sw_stats",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_neon_128_16, "parasail_sw_stats_table_diag_neon_128_16", "sw_stats",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_neon_128_8, "parasail_sw_stats_table_diag_neon_128_8", "sw_stats",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_neon = {"parasail_sw_stats_table_neon", parasail_sw_stats_table_neon_functions};
#endif
static parasail_function_info_t parasail_sw_stats_table_disp_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan_64,     "parasail_sw_stats_table_scan_64",     "sw_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_32,     "parasail_sw_stats_table_scan_32",     "sw_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_16,     "parasail_sw_stats_table_scan_16",     "sw_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_8,      "parasail_sw_stats_table_scan_8",      "sw_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_64,  "parasail_sw_stats_table_striped_64",  "sw_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_32,  "parasail_sw_stats_table_striped_32",  "sw_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_16,  "parasail_sw_stats_table_striped_16",  "sw_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_8,   "parasail_sw_stats_table_striped_8",   "sw_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_64,     "parasail_sw_stats_table_diag_64",     "sw_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_32,     "parasail_sw_stats_table_diag_32",     "sw_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_16,     "parasail_sw_stats_table_diag_16",     "sw_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_8,      "parasail_sw_stats_table_diag_8",      "sw_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_scan_sat,    "parasail_sw_stats_table_scan_sat",    "sw_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_striped_sat, "parasail_sw_stats_table_striped_sat", "sw_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sw_stats_table_diag_sat,    "parasail_sw_stats_table_diag_sat",    "sw_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_disp = {"parasail_sw_stats_table_disp", parasail_sw_stats_table_disp_functions};
static parasail_function_info_t parasail_sw_stats_table_serial_functions[] = {
{parasail_sw_stats_table,             "parasail_sw_stats_table",             "sw_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sw_stats_table_scan,        "parasail_sw_stats_table_scan",        "sw_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sw_stats_table_serial = {"parasail_sw_stats_table_serial", parasail_sw_stats_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_qb_stats_table_sse2_functions[] = {
{parasail_sg_qb_stats_table,          "parasail_sg_qb_stats_table",          "sg_qb_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_stats_table_scan_sse2_128_64, "parasail_sg_qb_stats_table_scan_sse2_128_64", "sg_qb_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_sse2_128_32, "parasail_sg_qb_stats_table_scan_sse2_128_32", "sg_qb_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_sse2_128_16, "parasail_sg_qb_stats_table_scan_sse2_128_16", "sg_qb_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_sse2_128_8, "parasail_sg_qb_stats_table_scan_sse2_128_8", "sg_qb_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_sse2_128_64, "parasail_sg_qb_stats_table_striped_sse2_128_64", "sg_qb_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_sse2_128_32, "parasail_sg_qb_stats_table_striped_sse2_128_32", "sg_qb_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_sse2_128_16, "parasail_sg_qb_stats_table_striped_sse2_128_16", "sg_qb_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_sse2_128_8, "parasail_sg_qb_stats_table_striped_sse2_128_8", "sg_qb_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_sse2_128_64, "parasail_sg_qb_stats_table_diag_sse2_128_64", "sg_qb_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_sse2_128_32, "parasail_sg_qb_stats_table_diag_sse2_128_32", "sg_qb_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_sse2_128_16, "parasail_sg_qb_stats_table_diag_sse2_128_16", "sg_qb_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_sse2_128_8, "parasail_sg_qb_stats_table_diag_sse2_128_8", "sg_qb_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_stats_table_sse2 = {"parasail_sg_qb_stats_table_sse2", parasail_sg_qb_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_qb_stats_table_sse41_functions[] = {
{parasail_sg_qb_stats_table,          "parasail_sg_qb_stats_table",          "sg_qb_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_stats_table_scan_sse41_128_64, "parasail_sg_qb_stats_table_scan_sse41_128_64", "sg_qb_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_sse41_128_32, "parasail_sg_qb_stats_table_scan_sse41_128_32", "sg_qb_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_sse41_128_16, "parasail_sg_qb_stats_table_scan_sse41_128_16", "sg_qb_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_sse41_128_8, "parasail_sg_qb_stats_table_scan_sse41_128_8", "sg_qb_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_sse41_128_64, "parasail_sg_qb_stats_table_striped_sse41_128_64", "sg_qb_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_sse41_128_32, "parasail_sg_qb_stats_table_striped_sse41_128_32", "sg_qb_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_sse41_128_16, "parasail_sg_qb_stats_table_striped_sse41_128_16", "sg_qb_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_sse41_128_8, "parasail_sg_qb_stats_table_striped_sse41_128_8", "sg_qb_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_sse41_128_64, "parasail_sg_qb_stats_table_diag_sse41_128_64", "sg_qb_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_sse41_128_32, "parasail_sg_qb_stats_table_diag_sse41_128_32", "sg_qb_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_sse41_128_16, "parasail_sg_qb_stats_table_diag_sse41_128_16", "sg_qb_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_sse41_128_8, "parasail_sg_qb_stats_table_diag_sse41_128_8", "sg_qb_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_stats_table_sse41 = {"parasail_sg_qb_stats_table_sse41", parasail_sg_qb_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_qb_stats_table_avx2_functions[] = {
{parasail_sg_qb_stats_table,          "parasail_sg_qb_stats_table",          "sg_qb_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_stats_table_scan_avx2_256_64, "parasail_sg_qb_stats_table_scan_avx2_256_64", "sg_qb_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_avx2_256_32, "parasail_sg_qb_stats_table_scan_avx2_256_32", "sg_qb_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_avx2_256_16, "parasail_sg_qb_stats_table_scan_avx2_256_16", "sg_qb_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_avx2_256_8, "parasail_sg_qb_stats_table_scan_avx2_256_8", "sg_qb_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_avx2_256_64, "parasail_sg_qb_stats_table_striped_avx2_256_64", "sg_qb_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_avx2_256_32, "parasail_sg_qb_stats_table_striped_avx2_256_32", "sg_qb_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_avx2_256_16, "parasail_sg_qb_stats_table_striped_avx2_256_16", "sg_qb_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_avx2_256_8, "parasail_sg_qb_stats_table_striped_avx2_256_8", "sg_qb_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_avx2_256_64, "parasail_sg_qb_stats_table_diag_avx2_256_64", "sg_qb_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_avx2_256_32, "parasail_sg_qb_stats_table_diag_avx2_256_32", "sg_qb_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_avx2_256_16, "parasail_sg_qb_stats_table_diag_avx2_256_16", "sg_qb_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_avx2_256_8, "parasail_sg_qb_stats_table_diag_avx2_256_8", "sg_qb_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_stats_table_avx2 = {"parasail_sg_qb_stats_table_avx2", parasail_sg_qb_stats_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_qb_stats_table_altivec_functions[] = {
{parasail_sg_qb_stats_table,          "parasail_sg_qb_stats_table",          "sg_qb_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_stats_table_scan_altivec_128_64, "parasail_sg_qb_stats_table_scan_altivec_128_64", "sg_qb_stats",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_altivec_128_32, "parasail_sg_qb_stats_table_scan_altivec_128_32", "sg_qb_stats",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_altivec_128_16, "parasail_sg_qb_stats_table_scan_altivec_128_16", "sg_qb_stats",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_altivec_128_8, "parasail_sg_qb_stats_table_scan_altivec_128_8", "sg_qb_stats",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_altivec_128_64, "parasail_sg_qb_stats_table_striped_altivec_128_64", "sg_qb_stats", "striped", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_altivec_128_32, "parasail_sg_qb_stats_table_striped_altivec_128_32", "sg_qb_stats", "striped", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_altivec_128_16, "parasail_sg_qb_stats_table_striped_altivec_128_16", "sg_qb_stats", "striped", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_altivec_128_8, "parasail_sg_qb_stats_table_striped_altivec_128_8", "sg_qb_stats", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_altivec_128_64, "parasail_sg_qb_stats_table_diag_altivec_128_64", "sg_qb_stats",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_altivec_128_32, "parasail_sg_qb_stats_table_diag_altivec_128_32", "sg_qb_stats",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_altivec_128_16, "parasail_sg_qb_stats_table_diag_altivec_128_16", "sg_qb_stats",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_altivec_128_8, "parasail_sg_qb_stats_table_diag_altivec_128_8", "sg_qb_stats",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_stats_table_altivec = {"parasail_sg_qb_stats_table_altivec", parasail_sg_qb_stats_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_qb_stats_table_neon_functions[] = {
{parasail_sg_qb_stats_table,          "parasail_sg_qb_stats_table",          "sg_qb_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_stats_table_scan_neon_128_64, "parasail_sg_qb_stats_table_scan_neon_128_64", "sg_qb_stats",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_neon_128_32, "parasail_sg_qb_stats_table_scan_neon_128_32", "sg_qb_stats",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_neon_128_16, "parasail_sg_qb_stats_table_scan_neon_128_16", "sg_qb_stats",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_neon_128_8, "parasail_sg_qb_stats_table_scan_neon_128_8", "sg_qb_stats",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_neon_128_64, "parasail_sg_qb_stats_table_striped_neon_128_64", "sg_qb_stats", "striped", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_neon_128_32, "parasail_sg_qb_stats_table_striped_neon_128_32", "sg_qb_stats", "striped", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_neon_128_16, "parasail_sg_qb_stats_table_striped_neon_128_16", "sg_qb_stats", "striped", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_neon_128_8, "parasail_sg_qb_stats_table_striped_neon_128_8", "sg_qb_stats", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_neon_128_64, "parasail_sg_qb_stats_table_diag_neon_128_64", "sg_qb_stats",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_neon_128_32, "parasail_sg_qb_stats_table_diag_neon_128_32", "sg_qb_stats",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_neon_128_16, "parasail_sg_qb_stats_table_diag_neon_128_16", "sg_qb_stats",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_neon_128_8, "parasail_sg_qb_stats_table_diag_neon_128_8", "sg_qb_stats",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_stats_table_neon = {"parasail_sg_qb_stats_table_neon", parasail_sg_qb_stats_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_qb_stats_table_disp_functions[] = {
{parasail_sg_qb_stats_table,          "parasail_sg_qb_stats_table",          "sg_qb_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_stats_table_scan_64,  "parasail_sg_qb_stats_table_scan_64",  "sg_qb_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_32,  "parasail_sg_qb_stats_table_scan_32",  "sg_qb_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_16,  "parasail_sg_qb_stats_table_scan_16",  "sg_qb_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_8,   "parasail_sg_qb_stats_table_scan_8",   "sg_qb_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_64, "parasail_sg_qb_stats_table_striped_64", "sg_qb_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_32, "parasail_sg_qb_stats_table_striped_32", "sg_qb_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_16, "parasail_sg_qb_stats_table_striped_16", "sg_qb_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_8, "parasail_sg_qb_stats_table_striped_8", "sg_qb_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_64,  "parasail_sg_qb_stats_table_diag_64",  "sg_qb_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_32,  "parasail_sg_qb_stats_table_diag_32",  "sg_qb_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_16,  "parasail_sg_qb_stats_table_diag_16",  "sg_qb_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_8,   "parasail_sg_qb_stats_table_diag_8",   "sg_qb_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_scan_sat, "parasail_sg_qb_stats_table_scan_sat", "sg_qb_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_striped_sat, "parasail_sg_qb_stats_table_striped_sat", "sg_qb_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_stats_table_diag_sat, "parasail_sg_qb_stats_table_diag_sat", "sg_qb_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_stats_table_disp = {"parasail_sg_qb_stats_table_disp", parasail_sg_qb_stats_table_disp_functions};
static parasail_function_info_t parasail_sg_qb_stats_table_serial_functions[] = {
{parasail_sg_qb_stats_table,          "parasail_sg_qb_stats_table",          "sg_qb_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_stats_table_scan,     "parasail_sg_qb_stats_table_scan",     "sg_qb_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_stats_table_serial = {"parasail_sg_qb_stats_table_serial", parasail_sg_qb_stats_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_qe_stats_table_sse2_functions[] = {
{parasail_sg_qe_stats_table,          "parasail_sg_qe_stats_table",          "sg_qe_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_stats_table_scan_sse2_128_64, "parasail_sg_qe_stats_table_scan_sse2_128_64", "sg_qe_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_sse2_128_32, "parasail_sg_qe_stats_table_scan_sse2_128_32", "sg_qe_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_sse2_128_16, "parasail_sg_qe_stats_table_scan_sse2_128_16", "sg_qe_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_sse2_128_8, "parasail_sg_qe_stats_table_scan_sse2_128_8", "sg_qe_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_sse2_128_64, "parasail_sg_qe_stats_table_striped_sse2_128_64", "sg_qe_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_sse2_128_32, "parasail_sg_qe_stats_table_striped_sse2_128_32", "sg_qe_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_sse2_128_16, "parasail_sg_qe_stats_table_striped_sse2_128_16", "sg_qe_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_sse2_128_8, "parasail_sg_qe_stats_table_striped_sse2_128_8", "sg_qe_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_sse2_128_64, "parasail_sg_qe_stats_table_diag_sse2_128_64", "sg_qe_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_sse2_128_32, "parasail_sg_qe_stats_table_diag_sse2_128_32", "sg_qe_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_sse2_128_16, "parasail_sg_qe_stats_table_diag_sse2_128_16", "sg_qe_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_sse2_128_8, "parasail_sg_qe_stats_table_diag_sse2_128_8", "sg_qe_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_stats_table_sse2 = {"parasail_sg_qe_stats_table_sse2", parasail_sg_qe_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_qe_stats_table_sse41_functions[] = {
{parasail_sg_qe_stats_table,          "parasail_sg_qe_stats_table",          "sg_qe_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_stats_table_scan_sse41_128_64, "parasail_sg_qe_stats_table_scan_sse41_128_64", "sg_qe_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_sse41_128_32, "parasail_sg_qe_stats_table_scan_sse41_128_32", "sg_qe_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_sse41_128_16, "parasail_sg_qe_stats_table_scan_sse41_128_16", "sg_qe_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_sse41_128_8, "parasail_sg_qe_stats_table_scan_sse41_128_8", "sg_qe_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_sse41_128_64, "parasail_sg_qe_stats_table_striped_sse41_128_64", "sg_qe_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_sse41_128_32, "parasail_sg_qe_stats_table_striped_sse41_128_32", "sg_qe_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_sse41_128_16, "parasail_sg_qe_stats_table_striped_sse41_128_16", "sg_qe_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_sse41_128_8, "parasail_sg_qe_stats_table_striped_sse41_128_8", "sg_qe_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_sse41_128_64, "parasail_sg_qe_stats_table_diag_sse41_128_64", "sg_qe_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_sse41_128_32, "parasail_sg_qe_stats_table_diag_sse41_128_32", "sg_qe_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_sse41_128_16, "parasail_sg_qe_stats_table_diag_sse41_128_16", "sg_qe_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_sse41_128_8, "parasail_sg_qe_stats_table_diag_sse41_128_8", "sg_qe_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_stats_table_sse41 = {"parasail_sg_qe_stats_table_sse41", parasail_sg_qe_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_qe_stats_table_avx2_functions[] = {
{parasail_sg_qe_stats_table,          "parasail_sg_qe_stats_table",          "sg_qe_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_stats_table_scan_avx2_256_64, "parasail_sg_qe_stats_table_scan_avx2_256_64", "sg_qe_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_avx2_256_32, "parasail_sg_qe_stats_table_scan_avx2_256_32", "sg_qe_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_avx2_256_16, "parasail_sg_qe_stats_table_scan_avx2_256_16", "sg_qe_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_avx2_256_8, "parasail_sg_qe_stats_table_scan_avx2_256_8", "sg_qe_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_avx2_256_64, "parasail_sg_qe_stats_table_striped_avx2_256_64", "sg_qe_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_avx2_256_32, "parasail_sg_qe_stats_table_striped_avx2_256_32", "sg_qe_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_avx2_256_16, "parasail_sg_qe_stats_table_striped_avx2_256_16", "sg_qe_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_avx2_256_8, "parasail_sg_qe_stats_table_striped_avx2_256_8", "sg_qe_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_avx2_256_64, "parasail_sg_qe_stats_table_diag_avx2_256_64", "sg_qe_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_avx2_256_32, "parasail_sg_qe_stats_table_diag_avx2_256_32", "sg_qe_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_avx2_256_16, "parasail_sg_qe_stats_table_diag_avx2_256_16", "sg_qe_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_avx2_256_8, "parasail_sg_qe_stats_table_diag_avx2_256_8", "sg_qe_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_stats_table_avx2 = {"parasail_sg_qe_stats_table_avx2", parasail_sg_qe_stats_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_qe_stats_table_altivec_functions[] = {
{parasail_sg_qe_stats_table,          "parasail_sg_qe_stats_table",          "sg_qe_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_stats_table_scan_altivec_128_64, "parasail_sg_qe_stats_table_scan_altivec_128_64", "sg_qe_stats",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_altivec_128_32, "parasail_sg_qe_stats_table_scan_altivec_128_32", "sg_qe_stats",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_altivec_128_16, "parasail_sg_qe_stats_table_scan_altivec_128_16", "sg_qe_stats",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_altivec_128_8, "parasail_sg_qe_stats_table_scan_altivec_128_8", "sg_qe_stats",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_altivec_128_64, "parasail_sg_qe_stats_table_striped_altivec_128_64", "sg_qe_stats", "striped", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_altivec_128_32, "parasail_sg_qe_stats_table_striped_altivec_128_32", "sg_qe_stats", "striped", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_altivec_128_16, "parasail_sg_qe_stats_table_striped_altivec_128_16", "sg_qe_stats", "striped", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_altivec_128_8, "parasail_sg_qe_stats_table_striped_altivec_128_8", "sg_qe_stats", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_altivec_128_64, "parasail_sg_qe_stats_table_diag_altivec_128_64", "sg_qe_stats",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_altivec_128_32, "parasail_sg_qe_stats_table_diag_altivec_128_32", "sg_qe_stats",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_altivec_128_16, "parasail_sg_qe_stats_table_diag_altivec_128_16", "sg_qe_stats",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_altivec_128_8, "parasail_sg_qe_stats_table_diag_altivec_128_8", "sg_qe_stats",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_stats_table_altivec = {"parasail_sg_qe_stats_table_altivec", parasail_sg_qe_stats_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_qe_stats_table_neon_functions[] = {
{parasail_sg_qe_stats_table,          "parasail_sg_qe_stats_table",          "sg_qe_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_stats_table_scan_neon_128_64, "parasail_sg_qe_stats_table_scan_neon_128_64", "sg_qe_stats",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_neon_128_32, "parasail_sg_qe_stats_table_scan_neon_128_32", "sg_qe_stats",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_neon_128_16, "parasail_sg_qe_stats_table_scan_neon_128_16", "sg_qe_stats",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_neon_128_8, "parasail_sg_qe_stats_table_scan_neon_128_8", "sg_qe_stats",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_neon_128_64, "parasail_sg_qe_stats_table_striped_neon_128_64", "sg_qe_stats", "striped", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_neon_128_32, "parasail_sg_qe_stats_table_striped_neon_128_32", "sg_qe_stats", "striped", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_neon_128_16, "parasail_sg_qe_stats_table_striped_neon_128_16", "sg_qe_stats", "striped", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_neon_128_8, "parasail_sg_qe_stats_table_striped_neon_128_8", "sg_qe_stats", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_neon_128_64, "parasail_sg_qe_stats_table_diag_neon_128_64", "sg_qe_stats",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_neon_128_32, "parasail_sg_qe_stats_table_diag_neon_128_32", "sg_qe_stats",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_neon_128_16, "parasail_sg_qe_stats_table_diag_neon_128_16", "sg_qe_stats",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_neon_128_8, "parasail_sg_qe_stats_table_diag_neon_128_8", "sg_qe_stats",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_stats_table_neon = {"parasail_sg_qe_stats_table_neon", parasail_sg_qe_stats_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_qe_stats_table_disp_functions[] = {
{parasail_sg_qe_stats_table,          "parasail_sg_qe_stats_table",          "sg_qe_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_stats_table_scan_64,  "parasail_sg_qe_stats_table_scan_64",  "sg_qe_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_32,  "parasail_sg_qe_stats_table_scan_32",  "sg_qe_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_16,  "parasail_sg_qe_stats_table_scan_16",  "sg_qe_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_8,   "parasail_sg_qe_stats_table_scan_8",   "sg_qe_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_64, "parasail_sg_qe_stats_table_striped_64", "sg_qe_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_32, "parasail_sg_qe_stats_table_striped_32", "sg_qe_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_16, "parasail_sg_qe_stats_table_striped_16", "sg_qe_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_8, "parasail_sg_qe_stats_table_striped_8", "sg_qe_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_64,  "parasail_sg_qe_stats_table_diag_64",  "sg_qe_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_32,  "parasail_sg_qe_stats_table_diag_32",  "sg_qe_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_16,  "parasail_sg_qe_stats_table_diag_16",  "sg_qe_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_8,   "parasail_sg_qe_stats_table_diag_8",   "sg_qe_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_scan_sat, "parasail_sg_qe_stats_table_scan_sat", "sg_qe_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_striped_sat, "parasail_sg_qe_stats_table_striped_sat", "sg_qe_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_stats_table_diag_sat, "parasail_sg_qe_stats_table_diag_sat", "sg_qe_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_stats_table_disp = {"parasail_sg_qe_stats_table_disp", parasail_sg_qe_stats_table_disp_functions};
static parasail_function_info_t parasail_sg_qe_stats_table_serial_functions[] = {
{parasail_sg_qe_stats_table,          "parasail_sg_qe_stats_table",          "sg_qe_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_stats_table_scan,     "parasail_sg_qe_stats_table_scan",     "sg_qe_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_stats_table_serial = {"parasail_sg_qe_stats_table_serial", parasail_sg_qe_stats_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_qx_stats_table_sse2_functions[] = {
{parasail_sg_qx_stats_table,          "parasail_sg_qx_stats_table",          "sg_qx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qx_stats_table_scan_sse2_128_64, "parasail_sg_qx_stats_table_scan_sse2_128_64", "sg_qx_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_sse2_128_32, "parasail_sg_qx_stats_table_scan_sse2_128_32", "sg_qx_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_sse2_128_16, "parasail_sg_qx_stats_table_scan_sse2_128_16", "sg_qx_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_sse2_128_8, "parasail_sg_qx_stats_table_scan_sse2_128_8", "sg_qx_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_sse2_128_64, "parasail_sg_qx_stats_table_striped_sse2_128_64", "sg_qx_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_sse2_128_32, "parasail_sg_qx_stats_table_striped_sse2_128_32", "sg_qx_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_sse2_128_16, "parasail_sg_qx_stats_table_striped_sse2_128_16", "sg_qx_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_sse2_128_8, "parasail_sg_qx_stats_table_striped_sse2_128_8", "sg_qx_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_sse2_128_64, "parasail_sg_qx_stats_table_diag_sse2_128_64", "sg_qx_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_sse2_128_32, "parasail_sg_qx_stats_table_diag_sse2_128_32", "sg_qx_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_sse2_128_16, "parasail_sg_qx_stats_table_diag_sse2_128_16", "sg_qx_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_sse2_128_8, "parasail_sg_qx_stats_table_diag_sse2_128_8", "sg_qx_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_stats_table_sse2 = {"parasail_sg_qx_stats_table_sse2", parasail_sg_qx_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_qx_stats_table_sse41_functions[] = {
{parasail_sg_qx_stats_table,          "parasail_sg_qx_stats_table",          "sg_qx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qx_stats_table_scan_sse41_128_64, "parasail_sg_qx_stats_table_scan_sse41_128_64", "sg_qx_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_sse41_128_32, "parasail_sg_qx_stats_table_scan_sse41_128_32", "sg_qx_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_sse41_128_16, "parasail_sg_qx_stats_table_scan_sse41_128_16", "sg_qx_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_sse41_128_8, "parasail_sg_qx_stats_table_scan_sse41_128_8", "sg_qx_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_sse41_128_64, "parasail_sg_qx_stats_table_striped_sse41_128_64", "sg_qx_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_sse41_128_32, "parasail_sg_qx_stats_table_striped_sse41_128_32", "sg_qx_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_sse41_128_16, "parasail_sg_qx_stats_table_striped_sse41_128_16", "sg_qx_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_sse41_128_8, "parasail_sg_qx_stats_table_striped_sse41_128_8", "sg_qx_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_sse41_128_64, "parasail_sg_qx_stats_table_diag_sse41_128_64", "sg_qx_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_sse41_128_32, "parasail_sg_qx_stats_table_diag_sse41_128_32", "sg_qx_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_sse41_128_16, "parasail_sg_qx_stats_table_diag_sse41_128_16", "sg_qx_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_sse41_128_8, "parasail_sg_qx_stats_table_diag_sse41_128_8", "sg_qx_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_stats_table_sse41 = {"parasail_sg_qx_stats_table_sse41", parasail_sg_qx_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_qx_stats_table_avx2_functions[] = {
{parasail_sg_qx_stats_table,          "parasail_sg_qx_stats_table",          "sg_qx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qx_stats_table_scan_avx2_256_64, "parasail_sg_qx_stats_table_scan_avx2_256_64", "sg_qx_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_avx2_256_32, "parasail_sg_qx_stats_table_scan_avx2_256_32", "sg_qx_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_avx2_256_16, "parasail_sg_qx_stats_table_scan_avx2_256_16", "sg_qx_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_avx2_256_8, "parasail_sg_qx_stats_table_scan_avx2_256_8", "sg_qx_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_avx2_256_64, "parasail_sg_qx_stats_table_striped_avx2_256_64", "sg_qx_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_avx2_256_32, "parasail_sg_qx_stats_table_striped_avx2_256_32", "sg_qx_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_avx2_256_16, "parasail_sg_qx_stats_table_striped_avx2_256_16", "sg_qx_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_avx2_256_8, "parasail_sg_qx_stats_table_striped_avx2_256_8", "sg_qx_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_avx2_256_64, "parasail_sg_qx_stats_table_diag_avx2_256_64", "sg_qx_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_avx2_256_32, "parasail_sg_qx_stats_table_diag_avx2_256_32", "sg_qx_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_avx2_256_16, "parasail_sg_qx_stats_table_diag_avx2_256_16", "sg_qx_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_avx2_256_8, "parasail_sg_qx_stats_table_diag_avx2_256_8", "sg_qx_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_stats_table_avx2 = {"parasail_sg_qx_stats_table_avx2", parasail_sg_qx_stats_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_qx_stats_table_altivec_functions[] = {
{parasail_sg_qx_stats_table,          "parasail_sg_qx_stats_table",          "sg_qx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qx_stats_table_scan_altivec_128_64, "parasail_sg_qx_stats_table_scan_altivec_128_64", "sg_qx_stats",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_altivec_128_32, "parasail_sg_qx_stats_table_scan_altivec_128_32", "sg_qx_stats",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_altivec_128_16, "parasail_sg_qx_stats_table_scan_altivec_128_16", "sg_qx_stats",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_altivec_128_8, "parasail_sg_qx_stats_table_scan_altivec_128_8", "sg_qx_stats",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_altivec_128_64, "parasail_sg_qx_stats_table_striped_altivec_128_64", "sg_qx_stats", "striped", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_altivec_128_32, "parasail_sg_qx_stats_table_striped_altivec_128_32", "sg_qx_stats", "striped", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_altivec_128_16, "parasail_sg_qx_stats_table_striped_altivec_128_16", "sg_qx_stats", "striped", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_altivec_128_8, "parasail_sg_qx_stats_table_striped_altivec_128_8", "sg_qx_stats", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_altivec_128_64, "parasail_sg_qx_stats_table_diag_altivec_128_64", "sg_qx_stats",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_altivec_128_32, "parasail_sg_qx_stats_table_diag_altivec_128_32", "sg_qx_stats",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_altivec_128_16, "parasail_sg_qx_stats_table_diag_altivec_128_16", "sg_qx_stats",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_altivec_128_8, "parasail_sg_qx_stats_table_diag_altivec_128_8", "sg_qx_stats",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_stats_table_altivec = {"parasail_sg_qx_stats_table_altivec", parasail_sg_qx_stats_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_qx_stats_table_neon_functions[] = {
{parasail_sg_qx_stats_table,          "parasail_sg_qx_stats_table",          "sg_qx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qx_stats_table_scan_neon_128_64, "parasail_sg_qx_stats_table_scan_neon_128_64", "sg_qx_stats",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_neon_128_32, "parasail_sg_qx_stats_table_scan_neon_128_32", "sg_qx_stats",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_neon_128_16, "parasail_sg_qx_stats_table_scan_neon_128_16", "sg_qx_stats",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_neon_128_8, "parasail_sg_qx_stats_table_scan_neon_128_8", "sg_qx_stats",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_neon_128_64, "parasail_sg_qx_stats_table_striped_neon_128_64", "sg_qx_stats", "striped", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_neon_128_32, "parasail_sg_qx_stats_table_striped_neon_128_32", "sg_qx_stats", "striped", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_neon_128_16, "parasail_sg_qx_stats_table_striped_neon_128_16", "sg_qx_stats", "striped", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_neon_128_8, "parasail_sg_qx_stats_table_striped_neon_128_8", "sg_qx_stats", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_neon_128_64, "parasail_sg_qx_stats_table_diag_neon_128_64", "sg_qx_stats",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_neon_128_32, "parasail_sg_qx_stats_table_diag_neon_128_32", "sg_qx_stats",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_neon_128_16, "parasail_sg_qx_stats_table_diag_neon_128_16", "sg_qx_stats",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_neon_128_8, "parasail_sg_qx_stats_table_diag_neon_128_8", "sg_qx_stats",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_stats_table_neon = {"parasail_sg_qx_stats_table_neon", parasail_sg_qx_stats_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_qx_stats_table_disp_functions[] = {
{parasail_sg_qx_stats_table,          "parasail_sg_qx_stats_table",          "sg_qx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qx_stats_table_scan_64,  "parasail_sg_qx_stats_table_scan_64",  "sg_qx_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_32,  "parasail_sg_qx_stats_table_scan_32",  "sg_qx_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_16,  "parasail_sg_qx_stats_table_scan_16",  "sg_qx_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_8,   "parasail_sg_qx_stats_table_scan_8",   "sg_qx_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_64, "parasail_sg_qx_stats_table_striped_64", "sg_qx_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_32, "parasail_sg_qx_stats_table_striped_32", "sg_qx_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_16, "parasail_sg_qx_stats_table_striped_16", "sg_qx_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_8, "parasail_sg_qx_stats_table_striped_8", "sg_qx_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_64,  "parasail_sg_qx_stats_table_diag_64",  "sg_qx_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_32,  "parasail_sg_qx_stats_table_diag_32",  "sg_qx_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_16,  "parasail_sg_qx_stats_table_diag_16",  "sg_qx_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_8,   "parasail_sg_qx_stats_table_diag_8",   "sg_qx_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_scan_sat, "parasail_sg_qx_stats_table_scan_sat", "sg_qx_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_striped_sat, "parasail_sg_qx_stats_table_striped_sat", "sg_qx_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qx_stats_table_diag_sat, "parasail_sg_qx_stats_table_diag_sat", "sg_qx_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_stats_table_disp = {"parasail_sg_qx_stats_table_disp", parasail_sg_qx_stats_table_disp_functions};
static parasail_function_info_t parasail_sg_qx_stats_table_serial_functions[] = {
{parasail_sg_qx_stats_table,          "parasail_sg_qx_stats_table",          "sg_qx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qx_stats_table_scan,     "parasail_sg_qx_stats_table_scan",     "sg_qx_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qx_stats_table_serial = {"parasail_sg_qx_stats_table_serial", parasail_sg_qx_stats_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_db_stats_table_sse2_functions[] = {
{parasail_sg_db_stats_table,          "parasail_sg_db_stats_table",          "sg_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_db_stats_table_scan_sse2_128_64, "parasail_sg_db_stats_table_scan_sse2_128_64", "sg_db_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_sse2_128_32, "parasail_sg_db_stats_table_scan_sse2_128_32", "sg_db_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_sse2_128_16, "parasail_sg_db_stats_table_scan_sse2_128_16", "sg_db_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_sse2_128_8, "parasail_sg_db_stats_table_scan_sse2_128_8", "sg_db_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_sse2_128_64, "parasail_sg_db_stats_table_striped_sse2_128_64", "sg_db_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_sse2_128_32, "parasail_sg_db_stats_table_striped_sse2_128_32", "sg_db_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_sse2_128_16, "parasail_sg_db_stats_table_striped_sse2_128_16", "sg_db_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_sse2_128_8, "parasail_sg_db_stats_table_striped_sse2_128_8", "sg_db_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_sse2_128_64, "parasail_sg_db_stats_table_diag_sse2_128_64", "sg_db_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_sse2_128_32, "parasail_sg_db_stats_table_diag_sse2_128_32", "sg_db_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_sse2_128_16, "parasail_sg_db_stats_table_diag_sse2_128_16", "sg_db_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_sse2_128_8, "parasail_sg_db_stats_table_diag_sse2_128_8", "sg_db_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_stats_table_sse2 = {"parasail_sg_db_stats_table_sse2", parasail_sg_db_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_db_stats_table_sse41_functions[] = {
{parasail_sg_db_stats_table,          "parasail_sg_db_stats_table",          "sg_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_db_stats_table_scan_sse41_128_64, "parasail_sg_db_stats_table_scan_sse41_128_64", "sg_db_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_sse41_128_32, "parasail_sg_db_stats_table_scan_sse41_128_32", "sg_db_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_sse41_128_16, "parasail_sg_db_stats_table_scan_sse41_128_16", "sg_db_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_sse41_128_8, "parasail_sg_db_stats_table_scan_sse41_128_8", "sg_db_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_sse41_128_64, "parasail_sg_db_stats_table_striped_sse41_128_64", "sg_db_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_sse41_128_32, "parasail_sg_db_stats_table_striped_sse41_128_32", "sg_db_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_sse41_128_16, "parasail_sg_db_stats_table_striped_sse41_128_16", "sg_db_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_sse41_128_8, "parasail_sg_db_stats_table_striped_sse41_128_8", "sg_db_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_sse41_128_64, "parasail_sg_db_stats_table_diag_sse41_128_64", "sg_db_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_sse41_128_32, "parasail_sg_db_stats_table_diag_sse41_128_32", "sg_db_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_sse41_128_16, "parasail_sg_db_stats_table_diag_sse41_128_16", "sg_db_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_sse41_128_8, "parasail_sg_db_stats_table_diag_sse41_128_8", "sg_db_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_stats_table_sse41 = {"parasail_sg_db_stats_table_sse41", parasail_sg_db_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_db_stats_table_avx2_functions[] = {
{parasail_sg_db_stats_table,          "parasail_sg_db_stats_table",          "sg_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_db_stats_table_scan_avx2_256_64, "parasail_sg_db_stats_table_scan_avx2_256_64", "sg_db_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_avx2_256_32, "parasail_sg_db_stats_table_scan_avx2_256_32", "sg_db_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_avx2_256_16, "parasail_sg_db_stats_table_scan_avx2_256_16", "sg_db_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_avx2_256_8, "parasail_sg_db_stats_table_scan_avx2_256_8", "sg_db_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_avx2_256_64, "parasail_sg_db_stats_table_striped_avx2_256_64", "sg_db_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_avx2_256_32, "parasail_sg_db_stats_table_striped_avx2_256_32", "sg_db_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_avx2_256_16, "parasail_sg_db_stats_table_striped_avx2_256_16", "sg_db_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_avx2_256_8, "parasail_sg_db_stats_table_striped_avx2_256_8", "sg_db_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_avx2_256_64, "parasail_sg_db_stats_table_diag_avx2_256_64", "sg_db_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_avx2_256_32, "parasail_sg_db_stats_table_diag_avx2_256_32", "sg_db_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_avx2_256_16, "parasail_sg_db_stats_table_diag_avx2_256_16", "sg_db_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_avx2_256_8, "parasail_sg_db_stats_table_diag_avx2_256_8", "sg_db_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_stats_table_avx2 = {"parasail_sg_db_stats_table_avx2", parasail_sg_db_stats_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_db_stats_table_altivec_functions[] = {
{parasail_sg_db_stats_table,          "parasail_sg_db_stats_table",          "sg_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_db_stats_table_scan_altivec_128_64, "parasail_sg_db_stats_table_scan_altivec_128_64", "sg_db_stats",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_altivec_128_32, "parasail_sg_db_stats_table_scan_altivec_128_32", "sg_db_stats",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_altivec_128_16, "parasail_sg_db_stats_table_scan_altivec_128_16", "sg_db_stats",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_altivec_128_8, "parasail_sg_db_stats_table_scan_altivec_128_8", "sg_db_stats",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_altivec_128_64, "parasail_sg_db_stats_table_striped_altivec_128_64", "sg_db_stats", "striped", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_altivec_128_32, "parasail_sg_db_stats_table_striped_altivec_128_32", "sg_db_stats", "striped", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_altivec_128_16, "parasail_sg_db_stats_table_striped_altivec_128_16", "sg_db_stats", "striped", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_altivec_128_8, "parasail_sg_db_stats_table_striped_altivec_128_8", "sg_db_stats", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_altivec_128_64, "parasail_sg_db_stats_table_diag_altivec_128_64", "sg_db_stats",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_altivec_128_32, "parasail_sg_db_stats_table_diag_altivec_128_32", "sg_db_stats",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_altivec_128_16, "parasail_sg_db_stats_table_diag_altivec_128_16", "sg_db_stats",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_altivec_128_8, "parasail_sg_db_stats_table_diag_altivec_128_8", "sg_db_stats",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_stats_table_altivec = {"parasail_sg_db_stats_table_altivec", parasail_sg_db_stats_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_db_stats_table_neon_functions[] = {
{parasail_sg_db_stats_table,          "parasail_sg_db_stats_table",          "sg_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_db_stats_table_scan_neon_128_64, "parasail_sg_db_stats_table_scan_neon_128_64", "sg_db_stats",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_neon_128_32, "parasail_sg_db_stats_table_scan_neon_128_32", "sg_db_stats",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_neon_128_16, "parasail_sg_db_stats_table_scan_neon_128_16", "sg_db_stats",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_neon_128_8, "parasail_sg_db_stats_table_scan_neon_128_8", "sg_db_stats",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_neon_128_64, "parasail_sg_db_stats_table_striped_neon_128_64", "sg_db_stats", "striped", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_neon_128_32, "parasail_sg_db_stats_table_striped_neon_128_32", "sg_db_stats", "striped", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_neon_128_16, "parasail_sg_db_stats_table_striped_neon_128_16", "sg_db_stats", "striped", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_neon_128_8, "parasail_sg_db_stats_table_striped_neon_128_8", "sg_db_stats", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_neon_128_64, "parasail_sg_db_stats_table_diag_neon_128_64", "sg_db_stats",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_neon_128_32, "parasail_sg_db_stats_table_diag_neon_128_32", "sg_db_stats",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_neon_128_16, "parasail_sg_db_stats_table_diag_neon_128_16", "sg_db_stats",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_neon_128_8, "parasail_sg_db_stats_table_diag_neon_128_8", "sg_db_stats",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_stats_table_neon = {"parasail_sg_db_stats_table_neon", parasail_sg_db_stats_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_db_stats_table_disp_functions[] = {
{parasail_sg_db_stats_table,          "parasail_sg_db_stats_table",          "sg_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_db_stats_table_scan_64,  "parasail_sg_db_stats_table_scan_64",  "sg_db_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_32,  "parasail_sg_db_stats_table_scan_32",  "sg_db_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_16,  "parasail_sg_db_stats_table_scan_16",  "sg_db_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_8,   "parasail_sg_db_stats_table_scan_8",   "sg_db_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_64, "parasail_sg_db_stats_table_striped_64", "sg_db_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_32, "parasail_sg_db_stats_table_striped_32", "sg_db_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_16, "parasail_sg_db_stats_table_striped_16", "sg_db_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_8, "parasail_sg_db_stats_table_striped_8", "sg_db_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_64,  "parasail_sg_db_stats_table_diag_64",  "sg_db_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_32,  "parasail_sg_db_stats_table_diag_32",  "sg_db_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_16,  "parasail_sg_db_stats_table_diag_16",  "sg_db_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_8,   "parasail_sg_db_stats_table_diag_8",   "sg_db_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_scan_sat, "parasail_sg_db_stats_table_scan_sat", "sg_db_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_striped_sat, "parasail_sg_db_stats_table_striped_sat", "sg_db_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_db_stats_table_diag_sat, "parasail_sg_db_stats_table_diag_sat", "sg_db_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_stats_table_disp = {"parasail_sg_db_stats_table_disp", parasail_sg_db_stats_table_disp_functions};
static parasail_function_info_t parasail_sg_db_stats_table_serial_functions[] = {
{parasail_sg_db_stats_table,          "parasail_sg_db_stats_table",          "sg_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_db_stats_table_scan,     "parasail_sg_db_stats_table_scan",     "sg_db_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_db_stats_table_serial = {"parasail_sg_db_stats_table_serial", parasail_sg_db_stats_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_de_stats_table_sse2_functions[] = {
{parasail_sg_de_stats_table,          "parasail_sg_de_stats_table",          "sg_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_de_stats_table_scan_sse2_128_64, "parasail_sg_de_stats_table_scan_sse2_128_64", "sg_de_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_sse2_128_32, "parasail_sg_de_stats_table_scan_sse2_128_32", "sg_de_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_sse2_128_16, "parasail_sg_de_stats_table_scan_sse2_128_16", "sg_de_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_sse2_128_8, "parasail_sg_de_stats_table_scan_sse2_128_8", "sg_de_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_sse2_128_64, "parasail_sg_de_stats_table_striped_sse2_128_64", "sg_de_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_sse2_128_32, "parasail_sg_de_stats_table_striped_sse2_128_32", "sg_de_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_sse2_128_16, "parasail_sg_de_stats_table_striped_sse2_128_16", "sg_de_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_sse2_128_8, "parasail_sg_de_stats_table_striped_sse2_128_8", "sg_de_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_sse2_128_64, "parasail_sg_de_stats_table_diag_sse2_128_64", "sg_de_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_sse2_128_32, "parasail_sg_de_stats_table_diag_sse2_128_32", "sg_de_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_sse2_128_16, "parasail_sg_de_stats_table_diag_sse2_128_16", "sg_de_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_sse2_128_8, "parasail_sg_de_stats_table_diag_sse2_128_8", "sg_de_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_stats_table_sse2 = {"parasail_sg_de_stats_table_sse2", parasail_sg_de_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_de_stats_table_sse41_functions[] = {
{parasail_sg_de_stats_table,          "parasail_sg_de_stats_table",          "sg_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_de_stats_table_scan_sse41_128_64, "parasail_sg_de_stats_table_scan_sse41_128_64", "sg_de_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_sse41_128_32, "parasail_sg_de_stats_table_scan_sse41_128_32", "sg_de_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_sse41_128_16, "parasail_sg_de_stats_table_scan_sse41_128_16", "sg_de_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_sse41_128_8, "parasail_sg_de_stats_table_scan_sse41_128_8", "sg_de_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_sse41_128_64, "parasail_sg_de_stats_table_striped_sse41_128_64", "sg_de_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_sse41_128_32, "parasail_sg_de_stats_table_striped_sse41_128_32", "sg_de_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_sse41_128_16, "parasail_sg_de_stats_table_striped_sse41_128_16", "sg_de_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_sse41_128_8, "parasail_sg_de_stats_table_striped_sse41_128_8", "sg_de_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_sse41_128_64, "parasail_sg_de_stats_table_diag_sse41_128_64", "sg_de_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_sse41_128_32, "parasail_sg_de_stats_table_diag_sse41_128_32", "sg_de_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_sse41_128_16, "parasail_sg_de_stats_table_diag_sse41_128_16", "sg_de_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_sse41_128_8, "parasail_sg_de_stats_table_diag_sse41_128_8", "sg_de_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_stats_table_sse41 = {"parasail_sg_de_stats_table_sse41", parasail_sg_de_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_de_stats_table_avx2_functions[] = {
{parasail_sg_de_stats_table,          "parasail_sg_de_stats_table",          "sg_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_de_stats_table_scan_avx2_256_64, "parasail_sg_de_stats_table_scan_avx2_256_64", "sg_de_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_avx2_256_32, "parasail_sg_de_stats_table_scan_avx2_256_32", "sg_de_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_avx2_256_16, "parasail_sg_de_stats_table_scan_avx2_256_16", "sg_de_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_avx2_256_8, "parasail_sg_de_stats_table_scan_avx2_256_8", "sg_de_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_avx2_256_64, "parasail_sg_de_stats_table_striped_avx2_256_64", "sg_de_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_avx2_256_32, "parasail_sg_de_stats_table_striped_avx2_256_32", "sg_de_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_avx2_256_16, "parasail_sg_de_stats_table_striped_avx2_256_16", "sg_de_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_avx2_256_8, "parasail_sg_de_stats_table_striped_avx2_256_8", "sg_de_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_avx2_256_64, "parasail_sg_de_stats_table_diag_avx2_256_64", "sg_de_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_avx2_256_32, "parasail_sg_de_stats_table_diag_avx2_256_32", "sg_de_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_avx2_256_16, "parasail_sg_de_stats_table_diag_avx2_256_16", "sg_de_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_avx2_256_8, "parasail_sg_de_stats_table_diag_avx2_256_8", "sg_de_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_stats_table_avx2 = {"parasail_sg_de_stats_table_avx2", parasail_sg_de_stats_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_de_stats_table_altivec_functions[] = {
{parasail_sg_de_stats_table,          "parasail_sg_de_stats_table",          "sg_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_de_stats_table_scan_altivec_128_64, "parasail_sg_de_stats_table_scan_altivec_128_64", "sg_de_stats",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_altivec_128_32, "parasail_sg_de_stats_table_scan_altivec_128_32", "sg_de_stats",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_altivec_128_16, "parasail_sg_de_stats_table_scan_altivec_128_16", "sg_de_stats",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_altivec_128_8, "parasail_sg_de_stats_table_scan_altivec_128_8", "sg_de_stats",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_altivec_128_64, "parasail_sg_de_stats_table_striped_altivec_128_64", "sg_de_stats", "striped", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_altivec_128_32, "parasail_sg_de_stats_table_striped_altivec_128_32", "sg_de_stats", "striped", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_altivec_128_16, "parasail_sg_de_stats_table_striped_altivec_128_16", "sg_de_stats", "striped", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_altivec_128_8, "parasail_sg_de_stats_table_striped_altivec_128_8", "sg_de_stats", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_altivec_128_64, "parasail_sg_de_stats_table_diag_altivec_128_64", "sg_de_stats",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_altivec_128_32, "parasail_sg_de_stats_table_diag_altivec_128_32", "sg_de_stats",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_altivec_128_16, "parasail_sg_de_stats_table_diag_altivec_128_16", "sg_de_stats",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_altivec_128_8, "parasail_sg_de_stats_table_diag_altivec_128_8", "sg_de_stats",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_stats_table_altivec = {"parasail_sg_de_stats_table_altivec", parasail_sg_de_stats_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_de_stats_table_neon_functions[] = {
{parasail_sg_de_stats_table,          "parasail_sg_de_stats_table",          "sg_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_de_stats_table_scan_neon_128_64, "parasail_sg_de_stats_table_scan_neon_128_64", "sg_de_stats",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_neon_128_32, "parasail_sg_de_stats_table_scan_neon_128_32", "sg_de_stats",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_neon_128_16, "parasail_sg_de_stats_table_scan_neon_128_16", "sg_de_stats",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_neon_128_8, "parasail_sg_de_stats_table_scan_neon_128_8", "sg_de_stats",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_neon_128_64, "parasail_sg_de_stats_table_striped_neon_128_64", "sg_de_stats", "striped", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_neon_128_32, "parasail_sg_de_stats_table_striped_neon_128_32", "sg_de_stats", "striped", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_neon_128_16, "parasail_sg_de_stats_table_striped_neon_128_16", "sg_de_stats", "striped", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_neon_128_8, "parasail_sg_de_stats_table_striped_neon_128_8", "sg_de_stats", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_neon_128_64, "parasail_sg_de_stats_table_diag_neon_128_64", "sg_de_stats",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_neon_128_32, "parasail_sg_de_stats_table_diag_neon_128_32", "sg_de_stats",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_neon_128_16, "parasail_sg_de_stats_table_diag_neon_128_16", "sg_de_stats",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_neon_128_8, "parasail_sg_de_stats_table_diag_neon_128_8", "sg_de_stats",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_stats_table_neon = {"parasail_sg_de_stats_table_neon", parasail_sg_de_stats_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_de_stats_table_disp_functions[] = {
{parasail_sg_de_stats_table,          "parasail_sg_de_stats_table",          "sg_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_de_stats_table_scan_64,  "parasail_sg_de_stats_table_scan_64",  "sg_de_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_32,  "parasail_sg_de_stats_table_scan_32",  "sg_de_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_16,  "parasail_sg_de_stats_table_scan_16",  "sg_de_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_8,   "parasail_sg_de_stats_table_scan_8",   "sg_de_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_64, "parasail_sg_de_stats_table_striped_64", "sg_de_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_32, "parasail_sg_de_stats_table_striped_32", "sg_de_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_16, "parasail_sg_de_stats_table_striped_16", "sg_de_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_8, "parasail_sg_de_stats_table_striped_8", "sg_de_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_64,  "parasail_sg_de_stats_table_diag_64",  "sg_de_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_32,  "parasail_sg_de_stats_table_diag_32",  "sg_de_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_16,  "parasail_sg_de_stats_table_diag_16",  "sg_de_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_8,   "parasail_sg_de_stats_table_diag_8",   "sg_de_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_scan_sat, "parasail_sg_de_stats_table_scan_sat", "sg_de_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_striped_sat, "parasail_sg_de_stats_table_striped_sat", "sg_de_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_de_stats_table_diag_sat, "parasail_sg_de_stats_table_diag_sat", "sg_de_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_stats_table_disp = {"parasail_sg_de_stats_table_disp", parasail_sg_de_stats_table_disp_functions};
static parasail_function_info_t parasail_sg_de_stats_table_serial_functions[] = {
{parasail_sg_de_stats_table,          "parasail_sg_de_stats_table",          "sg_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_de_stats_table_scan,     "parasail_sg_de_stats_table_scan",     "sg_de_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_de_stats_table_serial = {"parasail_sg_de_stats_table_serial", parasail_sg_de_stats_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_dx_stats_table_sse2_functions[] = {
{parasail_sg_dx_stats_table,          "parasail_sg_dx_stats_table",          "sg_dx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_dx_stats_table_scan_sse2_128_64, "parasail_sg_dx_stats_table_scan_sse2_128_64", "sg_dx_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_sse2_128_32, "parasail_sg_dx_stats_table_scan_sse2_128_32", "sg_dx_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_sse2_128_16, "parasail_sg_dx_stats_table_scan_sse2_128_16", "sg_dx_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_sse2_128_8, "parasail_sg_dx_stats_table_scan_sse2_128_8", "sg_dx_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_sse2_128_64, "parasail_sg_dx_stats_table_striped_sse2_128_64", "sg_dx_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_sse2_128_32, "parasail_sg_dx_stats_table_striped_sse2_128_32", "sg_dx_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_sse2_128_16, "parasail_sg_dx_stats_table_striped_sse2_128_16", "sg_dx_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_sse2_128_8, "parasail_sg_dx_stats_table_striped_sse2_128_8", "sg_dx_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_sse2_128_64, "parasail_sg_dx_stats_table_diag_sse2_128_64", "sg_dx_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_sse2_128_32, "parasail_sg_dx_stats_table_diag_sse2_128_32", "sg_dx_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_sse2_128_16, "parasail_sg_dx_stats_table_diag_sse2_128_16", "sg_dx_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_sse2_128_8, "parasail_sg_dx_stats_table_diag_sse2_128_8", "sg_dx_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_stats_table_sse2 = {"parasail_sg_dx_stats_table_sse2", parasail_sg_dx_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_dx_stats_table_sse41_functions[] = {
{parasail_sg_dx_stats_table,          "parasail_sg_dx_stats_table",          "sg_dx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_dx_stats_table_scan_sse41_128_64, "parasail_sg_dx_stats_table_scan_sse41_128_64", "sg_dx_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_sse41_128_32, "parasail_sg_dx_stats_table_scan_sse41_128_32", "sg_dx_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_sse41_128_16, "parasail_sg_dx_stats_table_scan_sse41_128_16", "sg_dx_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_sse41_128_8, "parasail_sg_dx_stats_table_scan_sse41_128_8", "sg_dx_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_sse41_128_64, "parasail_sg_dx_stats_table_striped_sse41_128_64", "sg_dx_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_sse41_128_32, "parasail_sg_dx_stats_table_striped_sse41_128_32", "sg_dx_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_sse41_128_16, "parasail_sg_dx_stats_table_striped_sse41_128_16", "sg_dx_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_sse41_128_8, "parasail_sg_dx_stats_table_striped_sse41_128_8", "sg_dx_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_sse41_128_64, "parasail_sg_dx_stats_table_diag_sse41_128_64", "sg_dx_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_sse41_128_32, "parasail_sg_dx_stats_table_diag_sse41_128_32", "sg_dx_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_sse41_128_16, "parasail_sg_dx_stats_table_diag_sse41_128_16", "sg_dx_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_sse41_128_8, "parasail_sg_dx_stats_table_diag_sse41_128_8", "sg_dx_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_stats_table_sse41 = {"parasail_sg_dx_stats_table_sse41", parasail_sg_dx_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_dx_stats_table_avx2_functions[] = {
{parasail_sg_dx_stats_table,          "parasail_sg_dx_stats_table",          "sg_dx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_dx_stats_table_scan_avx2_256_64, "parasail_sg_dx_stats_table_scan_avx2_256_64", "sg_dx_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_avx2_256_32, "parasail_sg_dx_stats_table_scan_avx2_256_32", "sg_dx_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_avx2_256_16, "parasail_sg_dx_stats_table_scan_avx2_256_16", "sg_dx_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_avx2_256_8, "parasail_sg_dx_stats_table_scan_avx2_256_8", "sg_dx_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_avx2_256_64, "parasail_sg_dx_stats_table_striped_avx2_256_64", "sg_dx_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_avx2_256_32, "parasail_sg_dx_stats_table_striped_avx2_256_32", "sg_dx_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_avx2_256_16, "parasail_sg_dx_stats_table_striped_avx2_256_16", "sg_dx_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_avx2_256_8, "parasail_sg_dx_stats_table_striped_avx2_256_8", "sg_dx_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_avx2_256_64, "parasail_sg_dx_stats_table_diag_avx2_256_64", "sg_dx_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_avx2_256_32, "parasail_sg_dx_stats_table_diag_avx2_256_32", "sg_dx_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_avx2_256_16, "parasail_sg_dx_stats_table_diag_avx2_256_16", "sg_dx_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_avx2_256_8, "parasail_sg_dx_stats_table_diag_avx2_256_8", "sg_dx_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_stats_table_avx2 = {"parasail_sg_dx_stats_table_avx2", parasail_sg_dx_stats_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_dx_stats_table_altivec_functions[] = {
{parasail_sg_dx_stats_table,          "parasail_sg_dx_stats_table",          "sg_dx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_dx_stats_table_scan_altivec_128_64, "parasail_sg_dx_stats_table_scan_altivec_128_64", "sg_dx_stats",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_altivec_128_32, "parasail_sg_dx_stats_table_scan_altivec_128_32", "sg_dx_stats",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_altivec_128_16, "parasail_sg_dx_stats_table_scan_altivec_128_16", "sg_dx_stats",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_altivec_128_8, "parasail_sg_dx_stats_table_scan_altivec_128_8", "sg_dx_stats",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_altivec_128_64, "parasail_sg_dx_stats_table_striped_altivec_128_64", "sg_dx_stats", "striped", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_altivec_128_32, "parasail_sg_dx_stats_table_striped_altivec_128_32", "sg_dx_stats", "striped", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_altivec_128_16, "parasail_sg_dx_stats_table_striped_altivec_128_16", "sg_dx_stats", "striped", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_altivec_128_8, "parasail_sg_dx_stats_table_striped_altivec_128_8", "sg_dx_stats", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_altivec_128_64, "parasail_sg_dx_stats_table_diag_altivec_128_64", "sg_dx_stats",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_altivec_128_32, "parasail_sg_dx_stats_table_diag_altivec_128_32", "sg_dx_stats",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_altivec_128_16, "parasail_sg_dx_stats_table_diag_altivec_128_16", "sg_dx_stats",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_altivec_128_8, "parasail_sg_dx_stats_table_diag_altivec_128_8", "sg_dx_stats",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_stats_table_altivec = {"parasail_sg_dx_stats_table_altivec", parasail_sg_dx_stats_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_dx_stats_table_neon_functions[] = {
{parasail_sg_dx_stats_table,          "parasail_sg_dx_stats_table",          "sg_dx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_dx_stats_table_scan_neon_128_64, "parasail_sg_dx_stats_table_scan_neon_128_64", "sg_dx_stats",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_neon_128_32, "parasail_sg_dx_stats_table_scan_neon_128_32", "sg_dx_stats",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_neon_128_16, "parasail_sg_dx_stats_table_scan_neon_128_16", "sg_dx_stats",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_neon_128_8, "parasail_sg_dx_stats_table_scan_neon_128_8", "sg_dx_stats",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_neon_128_64, "parasail_sg_dx_stats_table_striped_neon_128_64", "sg_dx_stats", "striped", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_neon_128_32, "parasail_sg_dx_stats_table_striped_neon_128_32", "sg_dx_stats", "striped", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_neon_128_16, "parasail_sg_dx_stats_table_striped_neon_128_16", "sg_dx_stats", "striped", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_neon_128_8, "parasail_sg_dx_stats_table_striped_neon_128_8", "sg_dx_stats", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_neon_128_64, "parasail_sg_dx_stats_table_diag_neon_128_64", "sg_dx_stats",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_neon_128_32, "parasail_sg_dx_stats_table_diag_neon_128_32", "sg_dx_stats",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_neon_128_16, "parasail_sg_dx_stats_table_diag_neon_128_16", "sg_dx_stats",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_neon_128_8, "parasail_sg_dx_stats_table_diag_neon_128_8", "sg_dx_stats",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_stats_table_neon = {"parasail_sg_dx_stats_table_neon", parasail_sg_dx_stats_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_dx_stats_table_disp_functions[] = {
{parasail_sg_dx_stats_table,          "parasail_sg_dx_stats_table",          "sg_dx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_dx_stats_table_scan_64,  "parasail_sg_dx_stats_table_scan_64",  "sg_dx_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_32,  "parasail_sg_dx_stats_table_scan_32",  "sg_dx_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_16,  "parasail_sg_dx_stats_table_scan_16",  "sg_dx_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_8,   "parasail_sg_dx_stats_table_scan_8",   "sg_dx_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_64, "parasail_sg_dx_stats_table_striped_64", "sg_dx_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_32, "parasail_sg_dx_stats_table_striped_32", "sg_dx_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_16, "parasail_sg_dx_stats_table_striped_16", "sg_dx_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_8, "parasail_sg_dx_stats_table_striped_8", "sg_dx_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_64,  "parasail_sg_dx_stats_table_diag_64",  "sg_dx_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_32,  "parasail_sg_dx_stats_table_diag_32",  "sg_dx_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_16,  "parasail_sg_dx_stats_table_diag_16",  "sg_dx_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_8,   "parasail_sg_dx_stats_table_diag_8",   "sg_dx_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_scan_sat, "parasail_sg_dx_stats_table_scan_sat", "sg_dx_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_striped_sat, "parasail_sg_dx_stats_table_striped_sat", "sg_dx_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_dx_stats_table_diag_sat, "parasail_sg_dx_stats_table_diag_sat", "sg_dx_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_stats_table_disp = {"parasail_sg_dx_stats_table_disp", parasail_sg_dx_stats_table_disp_functions};
static parasail_function_info_t parasail_sg_dx_stats_table_serial_functions[] = {
{parasail_sg_dx_stats_table,          "parasail_sg_dx_stats_table",          "sg_dx_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_dx_stats_table_scan,     "parasail_sg_dx_stats_table_scan",     "sg_dx_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_dx_stats_table_serial = {"parasail_sg_dx_stats_table_serial", parasail_sg_dx_stats_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_qb_de_stats_table_sse2_functions[] = {
{parasail_sg_qb_de_stats_table,       "parasail_sg_qb_de_stats_table",       "sg_qb_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_de_stats_table_scan_sse2_128_64, "parasail_sg_qb_de_stats_table_scan_sse2_128_64", "sg_qb_de_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_sse2_128_32, "parasail_sg_qb_de_stats_table_scan_sse2_128_32", "sg_qb_de_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_sse2_128_16, "parasail_sg_qb_de_stats_table_scan_sse2_128_16", "sg_qb_de_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_sse2_128_8, "parasail_sg_qb_de_stats_table_scan_sse2_128_8", "sg_qb_de_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_sse2_128_64, "parasail_sg_qb_de_stats_table_striped_sse2_128_64", "sg_qb_de_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_sse2_128_32, "parasail_sg_qb_de_stats_table_striped_sse2_128_32", "sg_qb_de_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_sse2_128_16, "parasail_sg_qb_de_stats_table_striped_sse2_128_16", "sg_qb_de_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_sse2_128_8, "parasail_sg_qb_de_stats_table_striped_sse2_128_8", "sg_qb_de_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_sse2_128_64, "parasail_sg_qb_de_stats_table_diag_sse2_128_64", "sg_qb_de_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_sse2_128_32, "parasail_sg_qb_de_stats_table_diag_sse2_128_32", "sg_qb_de_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_sse2_128_16, "parasail_sg_qb_de_stats_table_diag_sse2_128_16", "sg_qb_de_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_sse2_128_8, "parasail_sg_qb_de_stats_table_diag_sse2_128_8", "sg_qb_de_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_stats_table_sse2 = {"parasail_sg_qb_de_stats_table_sse2", parasail_sg_qb_de_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_qb_de_stats_table_sse41_functions[] = {
{parasail_sg_qb_de_stats_table,       "parasail_sg_qb_de_stats_table",       "sg_qb_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_de_stats_table_scan_sse41_128_64, "parasail_sg_qb_de_stats_table_scan_sse41_128_64", "sg_qb_de_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_sse41_128_32, "parasail_sg_qb_de_stats_table_scan_sse41_128_32", "sg_qb_de_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_sse41_128_16, "parasail_sg_qb_de_stats_table_scan_sse41_128_16", "sg_qb_de_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_sse41_128_8, "parasail_sg_qb_de_stats_table_scan_sse41_128_8", "sg_qb_de_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_sse41_128_64, "parasail_sg_qb_de_stats_table_striped_sse41_128_64", "sg_qb_de_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_sse41_128_32, "parasail_sg_qb_de_stats_table_striped_sse41_128_32", "sg_qb_de_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_sse41_128_16, "parasail_sg_qb_de_stats_table_striped_sse41_128_16", "sg_qb_de_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_sse41_128_8, "parasail_sg_qb_de_stats_table_striped_sse41_128_8", "sg_qb_de_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_sse41_128_64, "parasail_sg_qb_de_stats_table_diag_sse41_128_64", "sg_qb_de_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_sse41_128_32, "parasail_sg_qb_de_stats_table_diag_sse41_128_32", "sg_qb_de_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_sse41_128_16, "parasail_sg_qb_de_stats_table_diag_sse41_128_16", "sg_qb_de_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_sse41_128_8, "parasail_sg_qb_de_stats_table_diag_sse41_128_8", "sg_qb_de_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_stats_table_sse41 = {"parasail_sg_qb_de_stats_table_sse41", parasail_sg_qb_de_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_qb_de_stats_table_avx2_functions[] = {
{parasail_sg_qb_de_stats_table,       "parasail_sg_qb_de_stats_table",       "sg_qb_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_de_stats_table_scan_avx2_256_64, "parasail_sg_qb_de_stats_table_scan_avx2_256_64", "sg_qb_de_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_avx2_256_32, "parasail_sg_qb_de_stats_table_scan_avx2_256_32", "sg_qb_de_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_avx2_256_16, "parasail_sg_qb_de_stats_table_scan_avx2_256_16", "sg_qb_de_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_avx2_256_8, "parasail_sg_qb_de_stats_table_scan_avx2_256_8", "sg_qb_de_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_avx2_256_64, "parasail_sg_qb_de_stats_table_striped_avx2_256_64", "sg_qb_de_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_avx2_256_32, "parasail_sg_qb_de_stats_table_striped_avx2_256_32", "sg_qb_de_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_avx2_256_16, "parasail_sg_qb_de_stats_table_striped_avx2_256_16", "sg_qb_de_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_avx2_256_8, "parasail_sg_qb_de_stats_table_striped_avx2_256_8", "sg_qb_de_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_avx2_256_64, "parasail_sg_qb_de_stats_table_diag_avx2_256_64", "sg_qb_de_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_avx2_256_32, "parasail_sg_qb_de_stats_table_diag_avx2_256_32", "sg_qb_de_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_avx2_256_16, "parasail_sg_qb_de_stats_table_diag_avx2_256_16", "sg_qb_de_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_avx2_256_8, "parasail_sg_qb_de_stats_table_diag_avx2_256_8", "sg_qb_de_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_stats_table_avx2 = {"parasail_sg_qb_de_stats_table_avx2", parasail_sg_qb_de_stats_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_qb_de_stats_table_altivec_functions[] = {
{parasail_sg_qb_de_stats_table,       "parasail_sg_qb_de_stats_table",       "sg_qb_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_de_stats_table_scan_altivec_128_64, "parasail_sg_qb_de_stats_table_scan_altivec_128_64", "sg_qb_de_stats",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_altivec_128_32, "parasail_sg_qb_de_stats_table_scan_altivec_128_32", "sg_qb_de_stats",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_altivec_128_16, "parasail_sg_qb_de_stats_table_scan_altivec_128_16", "sg_qb_de_stats",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_altivec_128_8, "parasail_sg_qb_de_stats_table_scan_altivec_128_8", "sg_qb_de_stats",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_altivec_128_64, "parasail_sg_qb_de_stats_table_striped_altivec_128_64", "sg_qb_de_stats", "striped", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_altivec_128_32, "parasail_sg_qb_de_stats_table_striped_altivec_128_32", "sg_qb_de_stats", "striped", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_altivec_128_16, "parasail_sg_qb_de_stats_table_striped_altivec_128_16", "sg_qb_de_stats", "striped", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_altivec_128_8, "parasail_sg_qb_de_stats_table_striped_altivec_128_8", "sg_qb_de_stats", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_altivec_128_64, "parasail_sg_qb_de_stats_table_diag_altivec_128_64", "sg_qb_de_stats",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_altivec_128_32, "parasail_sg_qb_de_stats_table_diag_altivec_128_32", "sg_qb_de_stats",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_altivec_128_16, "parasail_sg_qb_de_stats_table_diag_altivec_128_16", "sg_qb_de_stats",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_altivec_128_8, "parasail_sg_qb_de_stats_table_diag_altivec_128_8", "sg_qb_de_stats",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_stats_table_altivec = {"parasail_sg_qb_de_stats_table_altivec", parasail_sg_qb_de_stats_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_qb_de_stats_table_neon_functions[] = {
{parasail_sg_qb_de_stats_table,       "parasail_sg_qb_de_stats_table",       "sg_qb_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_de_stats_table_scan_neon_128_64, "parasail_sg_qb_de_stats_table_scan_neon_128_64", "sg_qb_de_stats",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_neon_128_32, "parasail_sg_qb_de_stats_table_scan_neon_128_32", "sg_qb_de_stats",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_neon_128_16, "parasail_sg_qb_de_stats_table_scan_neon_128_16", "sg_qb_de_stats",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_neon_128_8, "parasail_sg_qb_de_stats_table_scan_neon_128_8", "sg_qb_de_stats",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_neon_128_64, "parasail_sg_qb_de_stats_table_striped_neon_128_64", "sg_qb_de_stats", "striped", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_neon_128_32, "parasail_sg_qb_de_stats_table_striped_neon_128_32", "sg_qb_de_stats", "striped", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_neon_128_16, "parasail_sg_qb_de_stats_table_striped_neon_128_16", "sg_qb_de_stats", "striped", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_neon_128_8, "parasail_sg_qb_de_stats_table_striped_neon_128_8", "sg_qb_de_stats", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_neon_128_64, "parasail_sg_qb_de_stats_table_diag_neon_128_64", "sg_qb_de_stats",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_neon_128_32, "parasail_sg_qb_de_stats_table_diag_neon_128_32", "sg_qb_de_stats",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_neon_128_16, "parasail_sg_qb_de_stats_table_diag_neon_128_16", "sg_qb_de_stats",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_neon_128_8, "parasail_sg_qb_de_stats_table_diag_neon_128_8", "sg_qb_de_stats",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_stats_table_neon = {"parasail_sg_qb_de_stats_table_neon", parasail_sg_qb_de_stats_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_qb_de_stats_table_disp_functions[] = {
{parasail_sg_qb_de_stats_table,       "parasail_sg_qb_de_stats_table",       "sg_qb_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_de_stats_table_scan_64, "parasail_sg_qb_de_stats_table_scan_64", "sg_qb_de_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_32, "parasail_sg_qb_de_stats_table_scan_32", "sg_qb_de_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_16, "parasail_sg_qb_de_stats_table_scan_16", "sg_qb_de_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_8, "parasail_sg_qb_de_stats_table_scan_8", "sg_qb_de_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_64, "parasail_sg_qb_de_stats_table_striped_64", "sg_qb_de_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_32, "parasail_sg_qb_de_stats_table_striped_32", "sg_qb_de_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_16, "parasail_sg_qb_de_stats_table_striped_16", "sg_qb_de_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_8, "parasail_sg_qb_de_stats_table_striped_8", "sg_qb_de_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_64, "parasail_sg_qb_de_stats_table_diag_64", "sg_qb_de_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_32, "parasail_sg_qb_de_stats_table_diag_32", "sg_qb_de_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_16, "parasail_sg_qb_de_stats_table_diag_16", "sg_qb_de_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_8, "parasail_sg_qb_de_stats_table_diag_8", "sg_qb_de_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_scan_sat, "parasail_sg_qb_de_stats_table_scan_sat", "sg_qb_de_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_striped_sat, "parasail_sg_qb_de_stats_table_striped_sat", "sg_qb_de_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qb_de_stats_table_diag_sat, "parasail_sg_qb_de_stats_table_diag_sat", "sg_qb_de_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_stats_table_disp = {"parasail_sg_qb_de_stats_table_disp", parasail_sg_qb_de_stats_table_disp_functions};
static parasail_function_info_t parasail_sg_qb_de_stats_table_serial_functions[] = {
{parasail_sg_qb_de_stats_table,       "parasail_sg_qb_de_stats_table",       "sg_qb_de_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qb_de_stats_table_scan,  "parasail_sg_qb_de_stats_table_scan",  "sg_qb_de_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qb_de_stats_table_serial = {"parasail_sg_qb_de_stats_table_serial", parasail_sg_qb_de_stats_table_serial_functions};
#if HAVE_SSE2
static parasail_function_info_t parasail_sg_qe_db_stats_table_sse2_functions[] = {
{parasail_sg_qe_db_stats_table,       "parasail_sg_qe_db_stats_table",       "sg_qe_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_db_stats_table_scan_sse2_128_64, "parasail_sg_qe_db_stats_table_scan_sse2_128_64", "sg_qe_db_stats",    "scan", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_sse2_128_32, "parasail_sg_qe_db_stats_table_scan_sse2_128_32", "sg_qe_db_stats",    "scan", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_sse2_128_16, "parasail_sg_qe_db_stats_table_scan_sse2_128_16", "sg_qe_db_stats",    "scan", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_sse2_128_8, "parasail_sg_qe_db_stats_table_scan_sse2_128_8", "sg_qe_db_stats",    "scan", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_sse2_128_64, "parasail_sg_qe_db_stats_table_striped_sse2_128_64", "sg_qe_db_stats", "striped", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_sse2_128_32, "parasail_sg_qe_db_stats_table_striped_sse2_128_32", "sg_qe_db_stats", "striped", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_sse2_128_16, "parasail_sg_qe_db_stats_table_striped_sse2_128_16", "sg_qe_db_stats", "striped", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_sse2_128_8, "parasail_sg_qe_db_stats_table_striped_sse2_128_8", "sg_qe_db_stats", "striped", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_sse2_128_64, "parasail_sg_qe_db_stats_table_diag_sse2_128_64", "sg_qe_db_stats",    "diag", "sse2",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_sse2_128_32, "parasail_sg_qe_db_stats_table_diag_sse2_128_32", "sg_qe_db_stats",    "diag", "sse2",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_sse2_128_16, "parasail_sg_qe_db_stats_table_diag_sse2_128_16", "sg_qe_db_stats",    "diag", "sse2",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_sse2_128_8, "parasail_sg_qe_db_stats_table_diag_sse2_128_8", "sg_qe_db_stats",    "diag", "sse2",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_stats_table_sse2 = {"parasail_sg_qe_db_stats_table_sse2", parasail_sg_qe_db_stats_table_sse2_functions};
#endif
#if HAVE_SSE41
static parasail_function_info_t parasail_sg_qe_db_stats_table_sse41_functions[] = {
{parasail_sg_qe_db_stats_table,       "parasail_sg_qe_db_stats_table",       "sg_qe_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_db_stats_table_scan_sse41_128_64, "parasail_sg_qe_db_stats_table_scan_sse41_128_64", "sg_qe_db_stats",    "scan", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_sse41_128_32, "parasail_sg_qe_db_stats_table_scan_sse41_128_32", "sg_qe_db_stats",    "scan", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_sse41_128_16, "parasail_sg_qe_db_stats_table_scan_sse41_128_16", "sg_qe_db_stats",    "scan", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_sse41_128_8, "parasail_sg_qe_db_stats_table_scan_sse41_128_8", "sg_qe_db_stats",    "scan", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_sse41_128_64, "parasail_sg_qe_db_stats_table_striped_sse41_128_64", "sg_qe_db_stats", "striped", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_sse41_128_32, "parasail_sg_qe_db_stats_table_striped_sse41_128_32", "sg_qe_db_stats", "striped", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_sse41_128_16, "parasail_sg_qe_db_stats_table_striped_sse41_128_16", "sg_qe_db_stats", "striped", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_sse41_128_8, "parasail_sg_qe_db_stats_table_striped_sse41_128_8", "sg_qe_db_stats", "striped", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_sse41_128_64, "parasail_sg_qe_db_stats_table_diag_sse41_128_64", "sg_qe_db_stats",    "diag", "sse41", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_sse41_128_32, "parasail_sg_qe_db_stats_table_diag_sse41_128_32", "sg_qe_db_stats",    "diag", "sse41", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_sse41_128_16, "parasail_sg_qe_db_stats_table_diag_sse41_128_16", "sg_qe_db_stats",    "diag", "sse41", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_sse41_128_8, "parasail_sg_qe_db_stats_table_diag_sse41_128_8", "sg_qe_db_stats",    "diag", "sse41", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_stats_table_sse41 = {"parasail_sg_qe_db_stats_table_sse41", parasail_sg_qe_db_stats_table_sse41_functions};
#endif
#if HAVE_AVX2
static parasail_function_info_t parasail_sg_qe_db_stats_table_avx2_functions[] = {
{parasail_sg_qe_db_stats_table,       "parasail_sg_qe_db_stats_table",       "sg_qe_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_db_stats_table_scan_avx2_256_64, "parasail_sg_qe_db_stats_table_scan_avx2_256_64", "sg_qe_db_stats",    "scan", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_avx2_256_32, "parasail_sg_qe_db_stats_table_scan_avx2_256_32", "sg_qe_db_stats",    "scan", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_avx2_256_16, "parasail_sg_qe_db_stats_table_scan_avx2_256_16", "sg_qe_db_stats",    "scan", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_avx2_256_8, "parasail_sg_qe_db_stats_table_scan_avx2_256_8", "sg_qe_db_stats",    "scan", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_avx2_256_64, "parasail_sg_qe_db_stats_table_striped_avx2_256_64", "sg_qe_db_stats", "striped", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_avx2_256_32, "parasail_sg_qe_db_stats_table_striped_avx2_256_32", "sg_qe_db_stats", "striped", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_avx2_256_16, "parasail_sg_qe_db_stats_table_striped_avx2_256_16", "sg_qe_db_stats", "striped", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_avx2_256_8, "parasail_sg_qe_db_stats_table_striped_avx2_256_8", "sg_qe_db_stats", "striped", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_avx2_256_64, "parasail_sg_qe_db_stats_table_diag_avx2_256_64", "sg_qe_db_stats",    "diag", "avx2",  "256", "64",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_avx2_256_32, "parasail_sg_qe_db_stats_table_diag_avx2_256_32", "sg_qe_db_stats",    "diag", "avx2",  "256", "32",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_avx2_256_16, "parasail_sg_qe_db_stats_table_diag_avx2_256_16", "sg_qe_db_stats",    "diag", "avx2",  "256", "16", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_avx2_256_8, "parasail_sg_qe_db_stats_table_diag_avx2_256_8", "sg_qe_db_stats",    "diag", "avx2",  "256",  "8", 32, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_stats_table_avx2 = {"parasail_sg_qe_db_stats_table_avx2", parasail_sg_qe_db_stats_table_avx2_functions};
#endif
#if HAVE_ALTIVEC
static parasail_function_info_t parasail_sg_qe_db_stats_table_altivec_functions[] = {
{parasail_sg_qe_db_stats_table,       "parasail_sg_qe_db_stats_table",       "sg_qe_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_db_stats_table_scan_altivec_128_64, "parasail_sg_qe_db_stats_table_scan_altivec_128_64", "sg_qe_db_stats",    "scan", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_altivec_128_32, "parasail_sg_qe_db_stats_table_scan_altivec_128_32", "sg_qe_db_stats",    "scan", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_altivec_128_16, "parasail_sg_qe_db_stats_table_scan_altivec_128_16", "sg_qe_db_stats",    "scan", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_altivec_128_8, "parasail_sg_qe_db_stats_table_scan_altivec_128_8", "sg_qe_db_stats",    "scan", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_altivec_128_64, "parasail_sg_qe_db_stats_table_striped_altivec_128_64", "sg_qe_db_stats", "striped", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_altivec_128_32, "parasail_sg_qe_db_stats_table_striped_altivec_128_32", "sg_qe_db_stats", "striped", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_altivec_128_16, "parasail_sg_qe_db_stats_table_striped_altivec_128_16", "sg_qe_db_stats", "striped", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_altivec_128_8, "parasail_sg_qe_db_stats_table_striped_altivec_128_8", "sg_qe_db_stats", "striped", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_altivec_128_64, "parasail_sg_qe_db_stats_table_diag_altivec_128_64", "sg_qe_db_stats",    "diag", "altivec", "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_altivec_128_32, "parasail_sg_qe_db_stats_table_diag_altivec_128_32", "sg_qe_db_stats",    "diag", "altivec", "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_altivec_128_16, "parasail_sg_qe_db_stats_table_diag_altivec_128_16", "sg_qe_db_stats",    "diag", "altivec", "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_altivec_128_8, "parasail_sg_qe_db_stats_table_diag_altivec_128_8", "sg_qe_db_stats",    "diag", "altivec", "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_stats_table_altivec = {"parasail_sg_qe_db_stats_table_altivec", parasail_sg_qe_db_stats_table_altivec_functions};
#endif
#if HAVE_NEON
static parasail_function_info_t parasail_sg_qe_db_stats_table_neon_functions[] = {
{parasail_sg_qe_db_stats_table,       "parasail_sg_qe_db_stats_table",       "sg_qe_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_db_stats_table_scan_neon_128_64, "parasail_sg_qe_db_stats_table_scan_neon_128_64", "sg_qe_db_stats",    "scan", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_neon_128_32, "parasail_sg_qe_db_stats_table_scan_neon_128_32", "sg_qe_db_stats",    "scan", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_neon_128_16, "parasail_sg_qe_db_stats_table_scan_neon_128_16", "sg_qe_db_stats",    "scan", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_neon_128_8, "parasail_sg_qe_db_stats_table_scan_neon_128_8", "sg_qe_db_stats",    "scan", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_neon_128_64, "parasail_sg_qe_db_stats_table_striped_neon_128_64", "sg_qe_db_stats", "striped", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_neon_128_32, "parasail_sg_qe_db_stats_table_striped_neon_128_32", "sg_qe_db_stats", "striped", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_neon_128_16, "parasail_sg_qe_db_stats_table_striped_neon_128_16", "sg_qe_db_stats", "striped", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_neon_128_8, "parasail_sg_qe_db_stats_table_striped_neon_128_8", "sg_qe_db_stats", "striped", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_neon_128_64, "parasail_sg_qe_db_stats_table_diag_neon_128_64", "sg_qe_db_stats",    "diag", "neon",  "128", "64",  2, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_neon_128_32, "parasail_sg_qe_db_stats_table_diag_neon_128_32", "sg_qe_db_stats",    "diag", "neon",  "128", "32",  4, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_neon_128_16, "parasail_sg_qe_db_stats_table_diag_neon_128_16", "sg_qe_db_stats",    "diag", "neon",  "128", "16",  8, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_neon_128_8, "parasail_sg_qe_db_stats_table_diag_neon_128_8", "sg_qe_db_stats",    "diag", "neon",  "128",  "8", 16, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_stats_table_neon = {"parasail_sg_qe_db_stats_table_neon", parasail_sg_qe_db_stats_table_neon_functions};
#endif
static parasail_function_info_t parasail_sg_qe_db_stats_table_disp_functions[] = {
{parasail_sg_qe_db_stats_table,       "parasail_sg_qe_db_stats_table",       "sg_qe_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_db_stats_table_scan_64, "parasail_sg_qe_db_stats_table_scan_64", "sg_qe_db_stats",    "scan", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_32, "parasail_sg_qe_db_stats_table_scan_32", "sg_qe_db_stats",    "scan", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_16, "parasail_sg_qe_db_stats_table_scan_16", "sg_qe_db_stats",    "scan", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_8, "parasail_sg_qe_db_stats_table_scan_8", "sg_qe_db_stats",    "scan", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_64, "parasail_sg_qe_db_stats_table_striped_64", "sg_qe_db_stats", "striped", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_32, "parasail_sg_qe_db_stats_table_striped_32", "sg_qe_db_stats", "striped", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_16, "parasail_sg_qe_db_stats_table_striped_16", "sg_qe_db_stats", "striped", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_8, "parasail_sg_qe_db_stats_table_striped_8", "sg_qe_db_stats", "striped", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_64, "parasail_sg_qe_db_stats_table_diag_64", "sg_qe_db_stats",    "diag", "disp",   "NA", "64", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_32, "parasail_sg_qe_db_stats_table_diag_32", "sg_qe_db_stats",    "diag", "disp",   "NA", "32", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_16, "parasail_sg_qe_db_stats_table_diag_16", "sg_qe_db_stats",    "diag", "disp",   "NA", "16", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_8, "parasail_sg_qe_db_stats_table_diag_8", "sg_qe_db_stats",    "diag", "disp",   "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_scan_sat, "parasail_sg_qe_db_stats_table_scan_sat", "sg_qe_db_stats",    "scan", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_striped_sat, "parasail_sg_qe_db_stats_table_striped_sat", "sg_qe_db_stats", "striped", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{parasail_sg_qe_db_stats_table_diag_sat, "parasail_sg_qe_db_stats_table_diag_sat", "sg_qe_db_stats",    "diag", "sat",    "NA",  "8", -1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_stats_table_disp = {"parasail_sg_qe_db_stats_table_disp", parasail_sg_qe_db_stats_table_disp_functions};
static parasail_function_info_t parasail_sg_qe_db_stats_table_serial_functions[] = {
{parasail_sg_qe_db_stats_table,       "parasail_sg_qe_db_stats_table",       "sg_qe_db_stats",    "orig", "NA",     "32", "32",  1, 1, 0, 0, 1, 1},
{parasail_sg_qe_db_stats_table_scan,  "parasail_sg_qe_db_stats_table_scan",  "sg_qe_db_stats",    "scan", "NA",     "32", "32",  1, 1, 0, 0, 1, 0},
{NULL, "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", 0, 0, 0, 0, 0, 0}
};
static parasail_function_group_t parasail_sg_qe_db_stats_table_serial = {"parasail_sg_qe_db_stats_table_serial", parasail_sg_qe_db_stats_table_serial_functions};

#endif /* _PARASAIL_FUNCTION_GROUP_TABLE_H_ */

