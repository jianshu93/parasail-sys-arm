#include "config.h"

#include <stdio.h>

#include "parasail/cpuid.h"

#define UNUSED(expr) do { (void)(expr); } while (0)

static inline char* yesno(int value)
{
    return value ? "yes" : "no ";
}


int main(int argc, char **argv)
{
    int cpu_sse2;
    int cpu_sse41;
    int cpu_avx2;
    int cpu_avx512f;
    int cpu_avx512bw;
    int cpu_avx512vbmi;
    int cpu_altivec;
    int cpu_neon;
    int cc_sse2;
    int cc_sse41;
    int cc_avx2;
    int cc_avx512f;
    int cc_avx512bw;
    int cc_avx512vbmi;
    int cc_altivec;
    int cc_neon;

    UNUSED(argc);
    UNUSED(argv);

    cpu_sse2 = parasail_can_use_sse2();
    cpu_sse41 = parasail_can_use_sse41();
    cpu_avx2 = parasail_can_use_avx2();
    cpu_avx512f = parasail_can_use_avx512f();
    cpu_avx512bw = parasail_can_use_avx512bw();
    cpu_avx512vbmi = parasail_can_use_avx512vbmi();
    cpu_altivec = parasail_can_use_altivec();
    cpu_neon = parasail_can_use_neon();

#if HAVE_SSE2
    cc_sse2 = 1;
#else
    cc_sse2 = 0;
#endif

#if HAVE_SSE41
    cc_sse41 = 1;
#else
    cc_sse41 = 0;
#endif

#if HAVE_AVX2
    cc_avx2 = 1;
#else
    cc_avx2 = 0;
#endif

#if HAVE_AVX512F
    cc_avx512f = 1;
#else
    cc_avx512f = 0;
#endif

#if HAVE_AVX512BW
    cc_avx512bw = 1;
#else
    cc_avx512bw = 0;
#endif

#if HAVE_AVX512VBMI
    cc_avx512vbmi = 1;
#else
    cc_avx512vbmi = 0;
#endif

#if HAVE_ALTIVEC
    cc_altivec = 1;
#else
    cc_altivec = 0;
#endif

#if HAVE_NEON
    cc_neon = 1;
#else
    cc_neon = 0;
#endif

#ifdef HAVE___BUILTIN_CPU_SUPPORTS
#ifdef HAVE___BUILTIN_CPU_INIT
    __builtin_cpu_init();
#endif
    printf(" ISA        | Compiler | CPU | __builtin_cpu_supports\n");
    printf("------------------------------------------------------\n");
    printf(" SSE2       |  %s     | %s | %s\n", yesno(cc_sse2), yesno(cpu_sse2), yesno(__builtin_cpu_supports("sse2")));
    printf(" SSE41      |  %s     | %s | %s\n", yesno(cc_sse41), yesno(cpu_sse41), yesno(__builtin_cpu_supports("sse4.1")));
    printf(" AVX2       |  %s     | %s | %s\n", yesno(cc_avx2), yesno(cpu_avx2), yesno(__builtin_cpu_supports("avx2")));
    printf(" AVX512F    |  %s     | %s | %s\n", yesno(cc_avx512f), yesno(cpu_avx512f), yesno(0));
    printf(" AVX512BW   |  %s     | %s | %s\n", yesno(cc_avx512bw), yesno(cpu_avx512bw), yesno(0));
    printf(" AVX512VBMI |  %s     | %s | %s\n", yesno(cc_avx512vbmi), yesno(cpu_avx512vbmi), yesno(0));
    printf(" ALTIVEC    |  %s     | %s | %s\n", yesno(cc_altivec), yesno(cpu_altivec), yesno(0));
    printf(" NEON       |  %s     | %s | %s\n", yesno(cc_neon), yesno(cpu_neon), yesno(0));
#else
    printf(" ISA        | Compiler | CPU  \n");
    printf("------------------------------\n");
    printf(" SSE2       |  %s     | %s\n", yesno(cc_sse2), yesno(cpu_sse2));
    printf(" SSE41      |  %s     | %s\n", yesno(cc_sse41), yesno(cpu_sse41));
    printf(" AVX2       |  %s     | %s\n", yesno(cc_avx2), yesno(cpu_avx2));
    printf(" AVX512F    |  %s     | %s\n", yesno(cc_avx512f), yesno(cpu_avx512f));
    printf(" AVX512BW   |  %s     | %s\n", yesno(cc_avx512bw), yesno(cpu_avx512bw));
    printf(" AVX512VBMI |  %s     | %s\n", yesno(cc_avx512vbmi), yesno(cpu_avx512vbmi));
    printf(" ALTIVEC    |  %s     | %s\n", yesno(cc_altivec), yesno(cpu_altivec));
    printf(" NEON       |  %s     | %s\n", yesno(cc_neon), yesno(cpu_neon));
#endif

    return 0;
}

