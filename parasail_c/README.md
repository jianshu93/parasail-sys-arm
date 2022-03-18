# parasail: Pairwise Sequence Alignment Library

master:
[![status](https://github.com/jeffdaily/parasail/actions/workflows/autotools.yml/badge.svg?branch=master)](https://github.com/jeffdaily/parasail/actions/workflows/autotools.yml?query=branch%3Amaster)
[![status](https://github.com/jeffdaily/parasail/actions/workflows/autotools-cross.yml/badge.svg?branch=master)](https://github.com/jeffdaily/parasail/actions/workflows/autotools-cross.yml?query=branch%3Amaster)
[![status](https://github.com/jeffdaily/parasail/actions/workflows/cmake.yml/badge.svg?branch=master)](https://github.com/jeffdaily/parasail/actions/workflows/cmake.yml?query=branch%3Amaster)
[![status](https://ci.appveyor.com/api/projects/status/rtmcf2kowwnrl6g2/branch/master?svg=true)](https://ci.appveyor.com/project/jeffdaily/parasail-7t5in/branch/master)

develop:
[![status](https://github.com/jeffdaily/parasail/actions/workflows/autotools.yml/badge.svg?branch=develop)](https://github.com/jeffdaily/parasail/actions/workflows/autotools.yml?query=branch%3Adevelop)
[![status](https://github.com/jeffdaily/parasail/actions/workflows/autotools-cross.yml/badge.svg?branch=develop)](https://github.com/jeffdaily/parasail/actions/workflows/autotools-cross.yml?query=branch%3Adevelop)
[![status](https://github.com/jeffdaily/parasail/actions/workflows/cmake.yml/badge.svg?branch=develop)](https://github.com/jeffdaily/parasail/actions/workflows/cmake.yml?query=branch%3Adevelop)
[![status](https://ci.appveyor.com/api/projects/status/rtmcf2kowwnrl6g2/branch/develop?svg=true)](https://ci.appveyor.com/project/jeffdaily/parasail-7t5in/branch/develop)

Author: Jeff Daily (jeffrey.daily@gmail.com)

## Table of Contents

  * [Introduction](#introduction)
  * [Instruction Sets and CPU Dispatching](#instruction-sets-and-cpu-dispatching)
  * [Compiling and Installing](#compiling-and-installing)
    * [autotools build](#autotools-build)
    * [CMake build](#cmake-build)
    * [Meson build](#meson-build)
    * [Cross-Compiling for ARM](#cross-compiling-for-arm)
  * [C Interface Example](#c-interface-example)
    * [Standard Function Naming Convention](#standard-function-naming-convention)
    * [Function Dispatchers](#function-dispatchers)
    * [Profile Function Naming Convention](#profile-function-naming-convention)
    * [Substitution Matrices](#substitution-matrices)
    * [SSW Library Emulation](#ssw-library-emulation)
    * [Function Lookup](#function-lookup)
    * [Banded Global Alignment](#banded-global-alignment)
    * [Position-Specific Scoring Matrix Alignment](#position-specific-scoring-matrix-alignment)
    * [File Input](#file-input)
    * [Tracebacks](#tracebacks)
  * [Language Bindings](#language-bindings)
    * [C/C\+\+](#cc)
    * [Python](#python)
    * [Rust](#rust)
    * [Java](#java)
  * [Windows Build](#windows-build)
  * [Example Applications](#example-applications)
  * [Citing parasail](#citing-parasail)
  * [License: Battelle BSD\-style](#license-battelle-bsd-style)

## Introduction

[back to top]

parasail is a SIMD C (C99) library containing implementations of the Smith-Waterman (local), Needleman-Wunsch (global), and various semi-global pairwise sequence alignment algorithms.  Here, semi-global means insertions before the start or after the end of either the query or target sequence are optionally not penalized.  parasail implements most known algorithms for vectorized pairwise sequence alignment, including diagonal [Wozniak, 1997], blocked [Rognes and Seeberg, 2000], striped [Farrar, 2007], and prefix scan [Daily, 2015].  Therefore, parasail is a reference implementation for these algorithms in addition to providing an implementation of the best-performing algorithm(s) to date on today's most advanced CPUs.

parasail implements the above algorithms currently in three variants, 1) returning the alignment score and ending locations, 2) additionally returning alignment statistics (number of exact matches, number of similarities, and alignment length), and 3) functions that store a traceback for later retrieval as a SAM CIGAR string.  The three variants exist because parasail is intended to be high-performing; calculating additional statistics or the traceback will perform slower than simply calculating the alignment score. Select the appropriate implementation for your needs.

Note: When any of the algorithms open a gap, only the gap open penalty alone is applied.

## Instruction Sets and CPU Dispatching

[back to top]

parasail supports the SSE2, SSE4.1, AVX2, AltiVec, and NEON instruction sets.  In many cases, your compiler can compile source code for an instruction set which is not supported by your host CPU.  The code is still compiled, however, parasail uses CPU dispatching at runtime to correctly select the appropriate implementation for the highest level of instruction set supported.  This allows parasail to be compiled and distributed by a maintainer for the best available system while still allowing the distribution to run with a lesser CPU.

## Compiling and Installing

[back to top]

The GNU autotools-based installation is the preferred method, though the CMake build works just as well. There is also a contributed Meson build.  The various build files are provided because it often makes it easier to include parasail as a submodule inside other projects using one a preferred build tool.  Every attempt has been made to make installation a smooth process.  For example, there are no required external dependencies.  However, if you still run into issues, please [file an issue](https://github.com/jeffdaily/parasail/issues/new).

### autotools build

If you are building from a git clone, the autotools files must first be generated using `autoreconf -fi`. The custom source distributions will already contain generated autotools files.

parasail follows the typical configure, make, make install steps of other GNU autotools-based installations.  By default, this will build both a static and shared library as well as the parasail_aligner application.  There is no automated test suite at this time, but running `make check` will build some additional test programs such as test_isa for reporting your compiler and CPU capabilities.

By default, running "make install" will install parasail into /usr/local. You will find the parasail.h header in /usr/local/include and the parasail library, e.g., libparasail.a, in /usr/local/lib. If you specify a different prefix during configure, for example `configure --prefix=/some/other/path`, then look within the include and lib directories there for the parasail.h header and
libparasail.so library, respectively.

Don't forget to link your application to the parasail library.  For example, `gcc foo.c -I/where/you/installed/include -L/where/you/installed/lib -lparasail`.  Otherwise, you'll see errors such as `undefined reference to 'parasail_sw'`.

### CMake build

The CMakeLists.txt file will compile and link the parasail library as well as the parasail_aligner application and the test_isa test program.  It builds some of the other test programs.

If you are familiar with CMake, the build process should be familiar.  For example, on Linux-based systems, create a directory for your build.  It is safe to do so within the source distribution of parasail.  For example:

```bash
unzip parasail-v1.0.1.zip
cd parasail-1.0.1
mkdir build
cd build
cmake ..
make
```

By default, CMake will build the parasail shared library.  In order to compile the static library, add `-DBUILD_SHARED_LIBS=OFF` to your `cmake` invocation, or use the `ccmake` utility to toggle the option.  The static and shared libraries must be built as separate cmake projects.

### Meson build

Please follow http://mesonbuild.com/Quick-guide.html for how to use
Meson. The Meson build files are maintained by @SoapZA.
This build currently only supports the SSE and AVX ISAs.

### Cross-Compiling for ARM

Using Ubuntu 16.04 LTS (Xenial), you can compile for an ARM-based platform using an x86_64-based build platform.  First, you will need to install the necessary packages.  There are a few different ARM platforms you can compile for using Ubuntu packages; the details of the platforms are not covered here.

#### Install Prerequisite Packages

```bash
sudo apt-get install \
gcc-arm-linux-gnueabi \
g++-arm-linux-gnueabi \
gcc-arm-linux-gnueabihf \
g++-arm-linux-gnueabihf \
gcc-aarch64-linux-gnu \
g++-aarch64-linux-gnu
```

#### Run configure for cross-compilation

Cross-compilation is possible with both the autotools and CMake builds, however the autotools build is straightforward.  Set the `--host` and `--build` options and specify the cross-compilers instead of the standard compilers.  If you have zlib installed, you must explicitly disable its inclusion in parasail because the default ubuntu packages from above do not provide it.  You can replace the `--host` option in the following example with `--host arm-linux-gnueabi` or `--host arm-linux-gnueabihf` as needed.

```bash
# for aarch64
./configure CC=aarch64-linux-gnu-gcc CXX=aarch64-linux-gnu-g++ --build x86_64-pc-linux-gnu --host aarch64-linux-gnu LDFLAGS=-static --without-zlib
# for gnueabi
./configure CC=arm-linux-gnueabi-gcc CXX=arm-linux-gnueabi-g++ --build x86_64-pc-linux-gnu --host arm-linux-gnueabi LDFLAGS=-static --without-zlib
# for gnueabihf
./configure CC=arm-linux-gnueabihf-gcc CXX=arm-linux-gnueabihf-g++ --build x86_64-pc-linux-gnu --host arm-linux-gnueabihf LDFLAGS=-static --without-zlib
```
Note that you don't really need to specify `CC` and `CXX` above (the `--host` argument will be added as a prefix to `gcc` and `g++` automatically), but being explicit will report errors early in case you forgot to install one of the packages from the prerequisites step.

#### Verifying Cross-Compiled ARM Executables using QEMU

Install the QEMU (https://www.qemu.org/) package.  `sudo apt-get install qemu`.  After a successful `make` you should have `apps/parasail_aligner`.  QEMU will allow you to run the cross-compiled binaries on your x86_64 linux platform.  You must specify the QEMU_LD_PREFIX corresponding to the desired ARM platform you compiled for.  Use the `-L` option to the appropriate qemu launcher.

```bash
# for aarch64
qemu-aarch64 -L /usr/aarch64-linux-gnu ./apps/parasail_aligner
# for gnueabi
qemu-arm -L /usr/arm-linux-gnueabi ./apps/parasail_aligner
# for gnueabihf
qemu-arm -L /usr/arm-linux-gnueabihf ./apps/parasail_aligner
```

## C Interface Example

[back to top]

All parasail functions have identical function signatures with respect to return types and parameters.

```C
parasail_result_t* the_parasail_function_name(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t* matrix);
```

The gap open (`open`) and gap extension (`gap`) penalties are passed to the functions as positive values.  The gap open penalty must be greater than or equal to the gap extension penalty.  When any of the algorithms open a gap, only the gap open penalty alone is applied.

With respect to traditional database query use, s1 is the query sequence and s2 is the database sequence.  For the functions returning the DP table or last row and column, the dimensions of the DP table are s1Len x s2Len where s1Len is the number of rows and s2Len is the number of columns (in C row-major order).

The return type is a C struct.  Users should treat the result as an opaque pointer and use getter functions for result attributes.  There are additional functions to determine which alignment function produced the result.

```C
typedef struct parasail_result {
    int score;      /* alignment score */
    int end_query;  /* end position of query sequence */
    int end_ref;    /* end position of reference sequence */
    int flag;       /* bit field for various flags */
    void *extra;
} parasail_result_t;

/* from parasail.h, the result getter functions */
parasail_cigar_t* parasail_result_get_cigar(
        parasail_result_t *result,
        const char *seqA, int lena,
        const char *seqB, int lenb,
        const parasail_matrix_t *matrix);
int parasail_result_get_score(result);
int parasail_result_get_end_query(result);
int parasail_result_get_end_ref(result);
int parasail_result_get_matches(result);
int parasail_result_get_similar(result);
int parasail_result_get_length(result);
int* parasail_result_get_score_table(result);
int* parasail_result_get_matches_table(result);
int* parasail_result_get_similar_table(result);
int* parasail_result_get_length_table(result);
int* parasail_result_get_score_row(result);
int* parasail_result_get_matches_row(result);
int* parasail_result_get_similar_row(result);
int* parasail_result_get_length_row(result);
int* parasail_result_get_score_col(result);
int* parasail_result_get_matches_col(result);
int* parasail_result_get_similar_col(result);
int* parasail_result_get_length_col(result);
int* parasail_result_get_trace_table(result);
int* parasail_result_get_trace_ins_table(result);
int* parasail_result_get_trace_del_table(result);

int parasail_result_is_nw(result);
int parasail_result_is_sg(result);
int parasail_result_is_sw(result);
int parasail_result_is_saturated(result);
int parasail_result_is_banded(result);
int parasail_result_is_scan(result);
int parasail_result_is_striped(result);
int parasail_result_is_diag(result);
int parasail_result_is_blocked(result);
int parasail_result_is_stats(result);
int parasail_result_is_stats_table(result);
int parasail_result_is_stats_rowcol(result);
int parasail_result_is_table(result);
int parasail_result_is_rowcol(result);
int parasail_result_is_trace(result);
```

You must free the returned parasail result using `void parasail_result_free(parasail_result_t *result)`.

### Standard Function Naming Convention

[back to top]

There are over 1,000 functions within the parasail library, but most are variations of the familiar main algorithms.  The following table describes the main algorithms and the shorthand name used for the function.

| Algorithm | Function Name |
| --- | --- |
| Smith-Waterman local alignment | sw |
| Needleman-Wunsch global alignment | nw |
| Semi-Global, do not penalize gaps at beginning of s1/query | sg_qb |
| Semi-Global, do not penalize gaps at end of s1/query | sg_qe |
| Semi-Global, do not penalize gaps at beginning and end of s1/query | sg_qx |
| Semi-Global, do not penalize gaps at beginning of s2/database | sg_db |
| Semi-Global, do not penalize gaps at end of s2/database | sg_de |
| Semi-Global, do not penalize gaps at beginning and end of s2/database | sg_dx |
| Semi-Global, do not penalize gaps at beginning of s1/query and end of s2/database | sg_qb_de |
| Semi-Global, do not penalize gaps at beginning of s2/database and end of s1/query | sg_qe_db |
| Semi-Global, do not penalize gaps at beginning and end of both sequences | sg |

A good summary of the various alignment algorithms can be found courtesy of Dr. Dannie Durand's course on computational genomics [here](http://www.cs.cmu.edu/~durand/03-711/2015/Lectures/PW_sequence_alignment_2015.pdf).  The same document was copied locally to this repo in case this link ever breaks, found [here](contrib/PW_sequence_alignment_2015.pdf).

To make it easier to find the function you're looking for, the function names follow a naming convention.  The following will use set notation {} to indicate a selection must be made and brackets [] to indicate an optional part of the name.
 
- Non-vectorized, reference implementations.
  - Required, select algorithm from table above.
  - Optional return alignment statistics.
  - Optional return DP table or last row/col.
  - Optional use a prefix scan implementation.
  - `parasail_ {nw,sg,sg_qb,sg_qe,sg_qx,sg_db,sg_de,sg_dx,sg_qb_de,sg_qe_db,sw} [_stats] [{_table,_rowcol}] [_scan]`
- Non-vectorized, traceback-capable reference implementations.
  - Required, select algorithm from table above.
  - Optional use a prefix scan implementation.
  - `parasail_ {nw,sg,sg_qb,sg_qe,sg_qx,sg_db,sg_de,sg_dx,sg_qb_de,sg_qe_db,sw} _trace [_scan]`
- Vectorized.
  - Required, select algorithm from table above.
  - Optional return alignment statistics.
  - Optional return DP table or last row/col.
  - Required, select vectorization strategy -- striped is a good place to start, but scan is often faster for global alignment.
  - Optional, select vector instruction set. Otherwise, best will be chosen for you.
  - Required, select solution width. 'sat' will attempt 8-bit solution but if overflow is detected it will then perform the 16-bit operation. Can be faster in some cases, though 16-bit is often sufficient.
  - `parasail_ {nw,sg,sg_qb,sg_qe,sg_qx,sg_db,sg_de,sg_dx,sg_qb_de,sg_qe_db,sw} [_stats] [{_table,_rowcol}] {_striped,_scan,_diag} [{_sse2_128,_sse41_128,_avx2_256,_altivec_128,_neon_128}] {_8,_16,_32,_64,_sat}`
- Vectorized, traceback-capable.
  - Required, select algorithm from table above.
  - Required, select vectorization strategy -- striped is a good place to start, but scan is often faster for global alignment.
  - Optional, select vector instruction set. Otherwise, best will be chosen for you.
  - Required, select solution width. 'sat' will attempt 8-bit solution but if overflow is detected it will then perform the 16-bit operation. Can be faster in some cases, though 16-bit is often sufficient.
  - `parasail_ {nw,sg,sg_qb,sg_qe,sg_qx,sg_db,sg_de,sg_dx,sg_qb_de,sg_qe_db,sw} _trace {_striped,_scan,_diag} [{_sse2_128,_sse41_128,_avx2_256,_altivec_128,_neon_128}] {_8,_16,_32,_64,_sat}`

For example:

- `parasail_nw_stats_striped_sse41_128_16` is Needleman-Wunsch global alignment, with alignment statistics, using striped vectors for sse41 16-bit integers.
- `parasail_sg` is semi-global, not penalizing beginning or end gaps of both sequences, without alignment statistics, without vectorized code (i.e. serial).
- `parasail_sw_scan_avx2_256_8` is Smith-Waterman local alignment, without alignment statistics, and uses prefix scan vectors for avx2 8-bit integers.
- `parasail_nw_stats_scan_16` is Needleman-Wunsch global alignment, with alignment statistics, uses prefix scan vectors, dispatches to the best CPU instruction set, and uses 16-bit integers.
- `parasail_sg_rowcol_striped_16` is semi-global alignment, without alignment statistics, outputs the last row and column of the DP table, uses striped vectors, dispatches to the best CPU instruction set, for 16-bit integers.
- `parasail_sw_trace_striped_sat` uses local alignment, is traceback-capable, dispatches to the best CPU instruction set, and attempts the 8-bit solution before trying the 16-bit solution.
- `parasail_sg_qx_trace_striped_32` is semi-global alignment, not penalizing beginning or end gaps for the query, is traceback-capable, dispatches to the best CPU instruction set, using 32-bit integers for the solution.

### Function Dispatchers

[back to top]

As noted in the previous section, if the instruction set and vector width are omitted from the function name, then this function is a CPU dispatching function.  It is assumed that most users will use the dispatching functions; calling a function for a specific instruction set such as AVX2 would require the user to first check whether the instruction set were supported by the CPU and handle any errors.  If an instruction set is not supported and the instruction set specific function is still called, it will return NULL and set errno to ENOSYS rather than causing an illegal instruction fault.

The computational cost of calling the dispatching function is minimal -- the first time it is called it will set an internal function pointer to the dispatched function and thereafter will call the function directly using the established pointer.

### Profile Function Naming Convention

[back to top]

It has been noted in literature that some performance can be gained by reusing the query sequence when using striped [Farrar, 2007] or scan [Daily, 2015] vector strategies.  There is a special subset of functions that enables this behavior.  For the striped and scan vector implementations *only*, a query profile can be created and reused for subsequent alignments. This can noticeably speed up applications such as database search.

- Optional, prepare query profile for a function that returns statistics.  Stats require additional data structures to be allocated.
- Optional, select vector instruction set. Otherwise, best will be chosen for you.
- Required, select solution width. 'sat' will allocate profiles for both 8- and 16-bit solutions.
- `parasail_profile_create [_stats] [{_sse_128,_avx_256,_altivec_128,_neon_128}] {_8,_16,_32,_64,_sat}`

This is a sample function signature of one of the profile creation functions.
```C
parasail_profile_t* parasail_profile_create_8 (
        const char * const restrict s1, const int s1Len,
        const parasail_matrix_t* matrix);
```

You must not forget to free the profile(s) when you are finished.  There is only one function used to free the profile memory and it will handle all profiles created by the various profile creation functions.

```C
void parasail_profile_free(parasail_profile_t *profile);
```

The profile data structure is part of parasail's public interface, though you should treat a profile as an opaque pointer and not attempt to access its members.

### Substitution Matrices

[back to top]

parasail bundles a number of substitution matrices including PAM and BLOSUM.  To use them, include the appropriate header, or look them up by name (useful for command-line parsing). For example

```C
#include "parasail.h"
#include "parasail/matrices/blosum62.h"
#include "parasail/matrix_lookup.h"

int main(int argc, char **argv) {
        const char *s1 = "asdf";
        const char *s2 = "asdf";
        int s1Len = (int)strlen(s1);
        int s2Len = (int)strlen(s2);
        parasail_result_t *result = NULL;
        const parasail_matrix_t *matrix = NULL;
        
        /* note the address-of operator '&' */
        result = parasail_sw(s1, s1Len, s2, s2Len, 11, 1, &parasail_blosum62);
        parasail_result_free(result);
        
        matrix = parasail_matrix_lookup("pam100");
        result = parasail_sw(s1, s1Len, s2, s2Len, 11, 1, matrix);
        parasail_result_free(result);
}
```

You can also create your own matrices with simple match/mismatch values.
For more complex matrices, you can start by copying a built-in matrix or
start simple and modify values as needed. For example

```C
#include "parasail.h"
#include "parasail/matrices/blosum62.h"
#include "parasail/matrix_lookup.h"

int main(int argc, char **argv) {
        const parasail_matrix_t *matrix = NULL;
        parasail_matrix_t *user_matrix = NULL;
        
        matrix = parasail_matrix_lookup("blosum62");

        user_matrix = parasail_matrix_copy(matrix);
        /* replace value at [2,4] location */
        parasail_matrix_set_value(user_matrix, 2, 4, 200);
        parasail_matrix_free(user_matrix);

        user_matrix = parasail_matrix_create("ACGT", 2, -1)
        /* replace value at [1,1] location, for a larger match */
        parasail_matrix_set_value(user_matrix, 1, 1, 20);
        parasail_matrix_free(user_matrix);
}
```

You can also create position-specific scoring matrices.  You can supply
an array of values, or start with a built-in matrix and convert it.

```C
#include "parasail.h"
#include "parasail/matrices/blosum62.h"

int main(int argc, char **argv)
{
    const parasail_matrix_t *internal_matrix = NULL;
    parasail_matrix_t *user_matrix = NULL;
    const char *pssm_alphabet = "abcdef";
    const char *pssm_query = "asdf";
    int pssm_query_len = 4;
    const int pssm_values[] = {
        0,  1,  2,  3,   4,  5,
        6,  7,  8,  9,  10, 11,
        12, 13, 14, 15, 16, 17,
        18, 19, 20, 21, 22, 23
    };
    const int pssm_rows = 4;

    user_matrix = parasail_matrix_pssm_create(
            pssm_alphabet,
            pssm_values,
            pssm_rows);
    parasail_matrix_free(user_matrix);

    internal_matrix = parasail_matrix_lookup("blosum62");
    user_matrix = parasail_matrix_convert_square_to_pssm(internal_matrix, pssm_query, pssm_query_len);
    parasail_matrix_free(user_matrix);
}
```

You can also parse simple matrix files using the function
`parasail_matrix_from_file` if the file is in one of the following formats:

#### square

```
#
# Any line starting with '#' is a comment.
#
# Needs a row for the alphabet.  First column is a repeat of the
# alphabet and assumed to be identical in order to the first alphabet row.
#
# Last row and column *must* be a non-alphabet character to represent
# any input sequence character that is outside of the alphabet.
#
    A   T   G   C   S   W   R   Y   K   M   B   V   H   D   N   U   *
A   5  -4  -4  -4  -4   1   1  -4  -4   1  -4  -1  -1  -1  -2  -4  -5
T  -4   5  -4  -4  -4   1  -4   1   1  -4  -1  -4  -1  -1  -2   5  -5
G  -4  -4   5  -4   1  -4   1  -4   1  -4  -1  -1  -4  -1  -2  -4  -5
C  -4  -4  -4   5   1  -4  -4   1  -4   1  -1  -1  -1  -4  -2  -4  -5
S  -4  -4   1   1  -1  -4  -2  -2  -2  -2  -1  -1  -3  -3  -1  -4  -5
W   1   1  -4  -4  -4  -1  -2  -2  -2  -2  -3  -3  -1  -1  -1   1  -5
R   1  -4   1  -4  -2  -2  -1  -4  -2  -2  -3  -1  -3  -1  -1  -4  -5
Y  -4   1  -4   1  -2  -2  -4  -1  -2  -2  -1  -3  -1  -3  -1   1  -5
K  -4   1   1  -4  -2  -2  -2  -2  -1  -4  -1  -3  -3  -1  -1   1  -5
M   1  -4  -4   1  -2  -2  -2  -2  -4  -1  -3  -1  -1  -3  -1  -4  -5
B  -4  -1  -1  -1  -1  -3  -3  -1  -1  -3  -1  -2  -2  -2  -1  -1  -5
V  -1  -4  -1  -1  -1  -3  -1  -3  -3  -1  -2  -1  -2  -2  -1  -4  -5
H  -1  -1  -4  -1  -3  -1  -3  -1  -3  -1  -2  -2  -1  -2  -1  -1  -5
D  -1  -1  -1  -4  -3  -1  -1  -3  -1  -3  -2  -2  -2  -1  -1  -1  -5
N  -2  -2  -2  -2  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -1  -2  -5
U  -4   5  -4  -4  -4   1  -4   1   1  -4  -1  -4  -1  -1  -2   5  -5
*  -5  -5  -5  -5  -5  -5  -5  -5  -5  -5  -5  -5  -5  -5  -5  -5  -5
```

#### position-specific scoring matrix (pssm)

```
#
# Any line starting with '#' is a comment.
#
# Needs a first row for the alphabet.
# First column containing a representative sequence is optional, but included below for an example.
#
    A   G   I   L   V   M   F   W   P   C   S   T   Y   N   Q   H   K   R   D   E
Y  -5  -6   3  -4   2   1   4  -3   0  -5   0  -4   6  0  -5   -4  -5   2  -6  -5
S  -1  -5   2  -2   0  -4   1  -6   0   1   3   3  -4  -4  -4  -5  -1   1  -5  -1
C  -4  -6  -5  -5  -4  -5  -6  -6  -6  12  -4  -4  -6  -6  -7  -7  -7  -7  -7  -7
D  -1  -5  -7  -7  -6  -6  -7  -7  -5  -7  -3  -1  -6   4  -3   3   0  -1   7  -2
G   0   4   1  -2  -2  -5  -5  -6  -6   5  -2   0   0   2  -4   3  -5  -5  -5   0
C  -4  -6  -5  -5  -4  -5  -6  -6  -6  12  -4  -4  -6  -6  -7  -7  -7  -7  -7  -7
L  -4   3  -1   3  -1  -3  -5  -6  -5  -6   0  -4  -5   1   3  -5   1   0  -1  -1
K  -2   1   1  -2  -1   3  -5  -6  -5  -5   2   2   0   1   1   1   2  -4  -4   0
P  -2   0  -4   0  -2  -4  -5  -5   5  -5  -3  -1   1   1  -3   2  -4  -4   1   3
I  -5  -7   7   1   0  -2   3  -5  -6  -5   0  -4  -4  -1  -6   3  -6  -6  -6  -6
```

### SSW Library Emulation
The [SSW library](https://github.com/mengyao/Complete-Striped-Smith-Waterman-Library) performs Smith-Waterman local alignment using SSE2 instructions and a striped vector.  Its result provides the primary score, a secondary score, beginning and ending locations of the alignment for both the query and reference sequences, as well as a SAM CIGAR.  There are a few parasail functions that emulate this behavior, with the only exception being that parasail does not calculate a secondary score.

```C
typedef struct parasail_result_ssw {
    uint16_t score1;
    int32_t ref_begin1;
    int32_t ref_end1;
    int32_t read_begin1;
    int32_t read_end1;
    uint32_t *cigar;
    int32_t cigarLen;
} parasail_result_ssw_t;

parasail_result_ssw_t* parasail_ssw(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap,
        const parasail_matrix_t* matrix);

parasail_result_ssw_t* parasail_ssw_profile(
        const parasail_profile_t * const restrict profile,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap);

parasail_profile_t* parasail_ssw_init(
        const char * const restrict s1, const int s1Len,
        const parasail_matrix_t* matrix, const int8_t score_size);

void parasail_result_ssw_free(parasail_result_ssw_t *result);
void parasail_profile_free(parasail_profile_t *profile);

```
 
### Function Lookup

[back to top]

Typically used for command-line or user-input parsing, the parasail functions can be accessed using their string name.  For example

```C
#include "parasail.h"
#include "parasail/matrices/blosum62.h"

int main(int argc, char **argv) {
        const char s1 = "asdf";
        const char s2 = "asdf";
        int s1Len = (int)strlen(s1);
        int s2Len = (int)strlen(s2);
        parasail_result_t *result = NULL;
        const parasail_matrix_t *matrix = NULL;
        parasail_function_t *function = NULL;
        
        function = parasail_lookup_function(argv[1]);
        result = function(s1, s1Len, s2, s2Len, 11, 1, &parasail_blosum62);
        parasail_result_free(result);
        
        /* 'parasail_' prefix is optional */
        function = parasail_lookup_function("nw_striped_32");
        result = function(s1, s1Len, s2, s2Len, 11, 1, &parasail_blosum62);
        parasail_result_free(result);
}
```

### Banded Global Alignment

[back to top]

There is one version of banded global alignment available.  Though it is not vectorized, it might still be faster than using other parasail global alignment functions, especially for large sequences.  The function signature is similar to the other parasail functions with the only exception being `k`, the band width.

```C
parasail_result_t* parasail_nw_banded(
        const char * const restrict s1, const int s1Len,
        const char * const restrict s2, const int s2Len,
        const int open, const int gap, const int k,
        const parasail_matrix_t* matrix);
```

### Position-Specific Scoring Matrix Alignment

[back to top]

If your scoring matrix is PSSM (see above), the alignment functions will ignore the query sequence and instead use the PSSM scores from the matrix.
All alignment functions support this new mode.  The only exception is the set of "stats" functions that return the score and alignment statistics (matches, mismatches, etc) without providing a full cigar or traceback.  These stats functions exepct both input sequences to be available for calculating counts of exact matches.

Rather than creating brand new APIs for just PSSM matrices that omit one of the two input sequences, the old signatures are used.  This design decision promotes API compatibility and preserves function lookup.  The first sequence will be ignored if the substitution matrix type is detected as PSSM.  You should pass in a NULL pointer if you know your matrix is PSSM.

Example:

```C
result = parasail_sw(NULL, 0, s2, s2Len, 11, 1, matrix_pssm);
```

### File Input

[back to top]

Parasail can parse FASTA, FASTQ, and gzipped versions of such files if zlib was found during the configure step. Additionally, some statistics are calculated while the file is parsed.

```C
typedef struct parasail_string {
    size_t l;
    char *s;
} parasail_string_t;

typedef struct parasail_sequence {
    parasail_string_t name;
    parasail_string_t comment;
    parasail_string_t seq;
    parasail_string_t qual;
} parasail_sequence_t;

typedef struct parasail_sequences {
    parasail_sequence_t *seqs;
    size_t l;
    size_t characters;
    size_t shortest;
    size_t longest;
    float mean;
    float stddev;
} parasail_sequences_t;

parasail_sequences_t* parasail_sequences_from_file(const char *fname);

void parasail_sequences_free(parasail_sequences_t *sequences);
```

### Tracebacks

[back to top]

Parasail supports printing a traceback to stdout, accessing a SAM CIGAR string from a result, as well as returning the three alignment strings.  You must use a traceback-capable alignment function.  Refer to the C interface description above for details on how to use a traceback-capable alignment function.

#### Printing Tracebacks

[back to top]

```C
void parasail_traceback_generic(
        const char *seqA, int lena,
        const char *seqB, int lenb,
        const char *nameA,
        const char *nameB,
        const parasail_matrix_t *matrix,
        parasail_result_t *result,
        char match, /* character to use for a match */
        char pos,   /* character to use for a positive-value mismatch */
        char neg,   /* character to use for a negative-value mismatch */
        int width,  /* width of traceback to display before wrapping */
        int name_width,
        int use_stats); /* if 0, don't display stats, if non-zero, summary stats displayed */

void parasail_traceback_generic_extra(
        const char *seqA, int lena,
        const char *seqB, int lenb,
        const char *nameA,
        const char *nameB,
        const parasail_matrix_t *matrix,
        parasail_result_t *result,
        char match, /* character to use for a match */
        char pos,   /* character to use for a positive-value mismatch */
        char neg,   /* character to use for a negative-value mismatch */
        int width,  /* width of traceback to display before wrapping */
        int name_width,
        int use_stats, /* if 0, don't display stats, if non-zero, summary stats displayed */
        int int_width, /* width used for reference and query indexes */
        FILE *stream); /* to print to custom file stream */
```

For example, `parasail_traceback_generic(seqA, strlen(seqA), seqB, strlen(seqB), "Query:", "Target:", matrix, result, '|', '*', '*', 60, 7, 1)` might produce the following:

```
Target:         81 EVAKDADLVIEAIPE--IFDLKKKVFSEIEQYCP     112
                   |*||***||*|**|*  **|***|***|*****|
Query:         170 EEAKNLGLVAEVFPQERFWDEVMKLAREVAELPP     203

Length: 34
Identity:        11/34 (32.4%)
Similarity:      32/34 (94.1%)
Gaps:             2/34 ( 5.9%)
Score: 37
```

#### SAM CIGAR

[back to top]

The SAM CIGAR is accessed using `parasail_result_get_cigar()`.  The CIGAR is encoded, so use the decode functions to determine the CIGAR operation and length for each uint32_t in the sequence.  Additionally, the query and reference sequence beginning positions are provided as part of the returned CIGAR structure.  Don't forget to free the CIGAR structure when finished.

```C
typedef struct parasail_cigar_ {
    uint32_t *seq;
    int len;
    int beg_query;
    int beg_ref;
} parasail_cigar_t;

parasail_cigar_t* parasail_result_get_cigar(
        parasail_result_t *result,
        const char *seqA,
        int lena,
        const char *seqB,
        int lenb,
        const parasail_matrix_t *matrix);

void parasail_cigar_free(parasail_cigar_t *cigar);

uint32_t parasail_cigar_encode(uint32_t length, char op_letter);

parasail_cigar_t* parasail_cigar_encode_string(const char *cigar);

char parasail_cigar_decode_op(uint32_t cigar_int);

uint32_t parasail_cigar_decode_len(uint32_t cigar_int);

char* parasail_cigar_decode(parasail_cigar_t *cigar);
```

#### Traceback strings

[back to top]

The traceback can be returned as a set of three strings, all of equal length, representing the traceback.  Indels in the `query` or `ref` strings are represented by a dash `-`.  The `comp` string represents the comparison between the `query` and `ref` strings and can use custom characters for the `match` (exact match), `pos` (positive-valued inexact match), and `neg` (negative-valued non-match).

```C
typedef struct parasail_traceback_{
    char *query;
    char *comp;
    char *ref;
} parasail_traceback_t;

extern parasail_traceback_t* parasail_result_get_traceback(
        parasail_result_t *result,
        const char *seqA,
        int lena,
        const char *seqB,
        int lenb,
        const parasail_matrix_t *matrix,
        char match, char pos, char neg);

extern void parasail_traceback_free(parasail_traceback_t *traceback);

```

## Language Bindings

[back to top]

### C/C++

[back to top]

C is the native API for parasail.  C++ is supported directly because the parasail.h header uses the common C++ include guards (#ifdef __cplusplus) to extern "C" all of the functions.  Once you have installed parasail, #include "parasail.h" into your sources.

### Python

[back to top]

Python bindings are available as part of the [parasail-python](https://github.com/jeffdaily/parasail-python) project.

### Rust

[back to top]

Rust bindings are available as part of the [parasailors](https://github.com/dikaiosune/parasailors) project.

### Java

[back to top]

Java bindings are available as part of the [parasail-java](https://github.com/jeffdaily/parasail-java) project.

## Windows Build

[back to top]

The Windows platform is fully supported as of v1.0.1.  The CMake build is the preferred method for building parasail on Windows.  Using the CMake GUI application, you can configure the parasail build for Visual Studio 2010, 2012, or 2013.  Other versions may also work but were not tested.  Both the 32-bit and 64-bit Windows builds should be working.  Visual Studio 2010 does not support AVX.  Use Visual Studio 2012 or newer.

## Example Applications

[back to top]

In addition to the parasail library, there is one binary that is also compiled and installed.
See [the apps README](apps/README.md) for more details.

## Citing parasail

[back to top]

If needed, please cite the following paper.

Daily, Jeff. (2016). Parasail: SIMD C library for global, semi-global,
and local pairwise sequence alignments. *BMC Bioinformatics*, 17(1), 1-11.
doi:10.1186/s12859-016-0930-z

http://dx.doi.org/10.1186/s12859-016-0930-z

## License: Battelle BSD-style

[back to top]

Copyright (c) 2015, Battelle Memorial Institute

1.  Battelle Memorial Institute (hereinafter Battelle) hereby grants
    permission to any person or entity lawfully obtaining a copy of this
    software and associated documentation files (hereinafter “the
    Software”) to redistribute and use the Software in source and binary
    forms, with or without modification.  Such person or entity may use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and may permit others to do so, subject to
    the following conditions:

    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimers.

    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.

    - Other than as used herein, neither the name Battelle Memorial
      Institute or Battelle may be used in any form whatsoever without
      the express written consent of Battelle.

    - Redistributions of the software in any form, and publications
      based on work performed using the software should include the
      following citation as a reference:

    Daily, Jeff. (2016). Parasail: SIMD C library for global,
    semi-global, and local pairwise sequence alignments. *BMC
    Bioinformatics*, 17(1), 1-11.  doi:10.1186/s12859-016-0930-z

2.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL BATTELLE
    OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
    USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
    OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.

[back to top]: #table-of-contents
