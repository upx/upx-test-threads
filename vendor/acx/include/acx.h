/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer
/// version 20260723

// special CPUs:
//   1) CHAR_BIT != 8: probably some DSP; just ignore these
//   2) sizeof(int) < 4: MCU (microcontroller) or historical CPU; just ignore these!!
//   3) GPUs or pure vector-CPUs
//   4) sizeof(void *) > 8: tagged pointers (IBM OS/400, Cheri, ...)
// extra mention:
//   Cray PVP (Y-MP EL): 64-bit word-addressible machine that simulates(?) char-pointers
//   IBM Cell SPU (removed from gcc-10 in 2020)

// careful with macros; these may clash with
//   MSVC __declspec(macro): __declspec(noinline)
//   clang attributes:       [[clang::noinline]]

#pragma once

/*************************************************************************
// 1a) system_check_predefs
// 1b) system_defs
// 1c) system_features
**************************************************************************/

// deal with old C++ workarounds for C99 <stdint.h>
#if defined(__cplusplus)
#    ifndef __STDC_CONSTANT_MACROS
#        define __STDC_CONSTANT_MACROS 1
#    endif
#    ifndef __STDC_FORMAT_MACROS
#        define __STDC_FORMAT_MACROS 1
#    endif
#    ifndef __STDC_LIMIT_MACROS
#        define __STDC_LIMIT_MACROS 1
#    endif
#endif

/*************************************************************************
// 2) system_headers
**************************************************************************/

// <stdbool.h>
#if !defined(__cplusplus) && !defined(__bool_true_false_are_defined)
#    if !defined(bool)
#        if defined(__STDC_VERSION__) && (__STDC_VERSION__ + 0 >= 199901L)
#            define bool _Bool
#        else
#            define bool int
#        endif
#    endif
#    if !defined(false)
#        define false 0
#    endif
#    if !defined(true)
#        define true 1
#    endif
#    define __bool_true_false_are_defined 1
#endif

// FreeBSD pre-defines these
#ifdef bswap16
#    undef bswap16
#endif
#ifdef bswap32
#    undef bswap32
#endif
#ifdef bswap64
#    undef bswap64
#endif
#define bswap16 acx_bswap16
#define bswap32 acx_bswap32
#define bswap64 acx_bswap64

/*************************************************************************
// 3) PP - PreProcessor
**************************************************************************/

#define PP_STRINGIZE(a)                        #a
#define PP_MACRO_EXPAND(a)                     PP_STRINGIZE(a)
#define PP_CONCAT0()                           /*empty*/
#define PP_CONCAT1(a)                          a
#define PP_CONCAT2(a, b)                       a##b
#define PP_CONCAT3(a, b, c)                    a##b##c
#define PP_CONCAT4(a, b, c, d)                 a##b##c##d
#define PP_CONCAT5(a, b, c, d, e)              a##b##c##d##e
#define PP_CONCAT6(a, b, c, d, e, f)           a##b##c##d##e##f
#define PP_CONCAT7(a, b, c, d, e, f, g)        a##b##c##d##e##f##g
#define PP_CONCAT8(a, b, c, d, e, f, g, h)     a##b##c##d##e##f##g##h
#define PP_CONCAT9(a, b, c, d, e, f, g, h, i)  a##b##c##d##e##f##g##h##i
#define PP_ECONCAT0()                          PP_CONCAT0()
#define PP_ECONCAT1(a)                         PP_CONCAT1(a)
#define PP_ECONCAT2(a, b)                      PP_CONCAT2(a, b)
#define PP_ECONCAT3(a, b, c)                   PP_CONCAT3(a, b, c)
#define PP_ECONCAT4(a, b, c, d)                PP_CONCAT4(a, b, c, d)
#define PP_ECONCAT5(a, b, c, d, e)             PP_CONCAT5(a, b, c, d, e)
#define PP_ECONCAT6(a, b, c, d, e, f)          PP_CONCAT6(a, b, c, d, e, f)
#define PP_ECONCAT7(a, b, c, d, e, f, g)       PP_CONCAT7(a, b, c, d, e, f, g)
#define PP_ECONCAT8(a, b, c, d, e, f, g, h)    PP_CONCAT8(a, b, c, d, e, f, g, h)
#define PP_ECONCAT9(a, b, c, d, e, f, g, h, i) PP_CONCAT9(a, b, c, d, e, f, g, h, i)
#define PP_EMPTY                               /*empty*/
#define PP_EMPTY0()                            /*empty*/
#define PP_EMPTY1(a)                           /*empty*/
#define PP_EMPTY2(a, b)                        /*empty*/
#define PP_EMPTY3(a, b, c)                     /*empty*/
#define PP_EMPTY4(a, b, c, d)                  /*empty*/
#define PP_EMPTY5(a, b, c, d, e)               /*empty*/
#define PP_EMPTY6(a, b, c, d, e, f)            /*empty*/
#define PP_EMPTY7(a, b, c, d, e, f, g)         /*empty*/
#define PP_EMPTY8(a, b, c, d, e, f, g, h)      /*empty*/
#define PP_EMPTY9(a, b, c, d, e, f, g, h, i)   /*empty*/

#if 0
// unfortunately this is not allowed by the C standard
#    define PP_DEFINED(x) (defined(x))
#    define PP_BOOL(x)    (defined(x) && ((x + 0) != 0))
#endif

/*************************************************************************
// 4) core
**************************************************************************/

// quarantine fundamental types in typedefs
typedef char q_char;
typedef signed char q_schar;
typedef unsigned char q_uchar;
typedef short q_short;
typedef unsigned short q_ushort;
typedef int q_int;
typedef unsigned q_uint;
typedef long q_long;
typedef unsigned long q_ulong;
typedef long long q_llong;
typedef unsigned long long q_ullong;

// query compiler features
#if !defined(__has_attribute)
#    define __has_attribute(x) 0
#endif
#if !defined(__has_builtin)
#    define __has_builtin(x) 0
#endif
#if !defined(__has_declspec_attribute)
#    define __has_declspec_attribute(x) 0
#endif
#if !defined(__has_feature)
#    define __has_feature(x) 0
#endif
#if !defined(__has_include)
#    define __has_include(x) 0
#endif
#if !defined(__has_warning)
#    define __has_warning(x) 0
#endif

// __alignof__ (this may differ from C++11 "alignof", see gcc-8 NEWS !)
#if defined(__clang__) || defined(__GNUC__)
#elif !defined(__alignof__) && defined(_MSC_VER)
#    define __alignof__ __alignof
#endif

// C++ extern "C"
#if defined(__cplusplus)
#    define EXTERN_C       extern "C"
#    define EXTERN_C_BEGIN extern "C" {
#    define EXTERN_C_END   }
#else
#    define EXTERN_C       extern
#    define EXTERN_C_BEGIN /*empty*/
#    define EXTERN_C_END   /*empty*/
#endif

// do not warn about possible "expression is constant" (MSVC)
#define MAYBE_CONSTANT_EXPR(e) ((void) 0, (e))

#define BLOCK_BEGIN do {
#define BLOCK_END                                                                                  \
    }                                                                                              \
    while (MAYBE_CONSTANT_EXPR(0))

/*************************************************************************
// 5) CTA - Compile Time Assert
**************************************************************************/

#if defined(__COUNTER__)
#    define CTA_INTERNAL_NAME(a) PP_ECONCAT2(a, __COUNTER__)
#else
// info: we can define CTA_INTERNAL_PREFIX and CTA_INTERNAL_SUFFIX to avoid line-number clashes
#    define CTA_INTERNAL_NAME(a) PP_ECONCAT4(CTA_INTERNAL_PREFIX, a, __LINE__, CTA_INTERNAL_SUFFIX)
#endif

// compile-time-assert in global scope (or in header file); also works in C++ class scope
#if defined(__cplusplus) && (__cplusplus + 0 >= 201103L)
#    define CTA_IN_GLOBAL_SCOPE(e) static_assert((e), #e)
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ + 0 >= 201112L)
#    define CTA_IN_GLOBAL_SCOPE(e) _Static_assert((e), #e)
#elif defined(__GNUC__) && (__GNUC__ < 3 || (__GNUC__ == 3 && __GNUC_MINOR__ < 3))
#    define CTA_IN_GLOBAL_SCOPE(e) enum { CTA_INTERNAL_NAME(cta_failed_) = 1 / (int) !!(e) }
#elif defined(__clang__) || defined(__GNUC__)
#    define CTA_IN_GLOBAL_SCOPE(e)                                                                 \
        enum { CTA_INTERNAL_NAME(cta_failed_) = 1 / (int) !!(e) } __attribute__((__unused__))
#else
#    define CTA_IN_GLOBAL_SCOPE(e) enum { CTA_INTERNAL_NAME(cta_failed_) = 1 / (int) !!(e) }
#endif

// compile-time-assert in function scope
#define CTA_IN_FUNC_SCOPE(e)                                                                       \
    BLOCK_BEGIN                                                                                    \
    CTA_IN_GLOBAL_SCOPE(e);                                                                        \
    BLOCK_END

// new names
#define ct_assert  CTA_IN_GLOBAL_SCOPE
#define ct_assertf CTA_IN_FUNC_SCOPE

#define ct_assert_type_pair(a, b, n)                                                               \
    ct_assert((sizeof(a) == sizeof(b)) && (__alignof__(a) == __alignof__(b)) &&                    \
              ((a) ((a) 0 - (a) 1) < 0) && ((b) ((b) 0 - (b) 1) > 0) &&                            \
              ((n) == 0 || sizeof(a) == (n)))

/*************************************************************************
// 6) SIZEOF_INT etc.
**************************************************************************/

// preprocessor and compiler sanity checks
ct_assert(CHAR_BIT == 8);
ct_assert(sizeof(int) >= 4);
ct_assert(sizeof(size_t) >= sizeof(int));
ct_assert(sizeof(ptrdiff_t) >= sizeof(size_t));
ct_assert(sizeof(0) == sizeof(int));
ct_assert(sizeof(0L) == sizeof(long));
ct_assert(sizeof(0LL) == sizeof(long long));
ct_assert(sizeof(sizeof(0)) == sizeof(size_t));
#if defined(_MSC_VER) || defined(_WIN32) || defined(_WIN64)
ct_assert(sizeof(long) == 4);
#endif

#include "acx_sizeof.h"

#if !(defined(ACX_CONFIG_USE_UINTPTR_T) && ACX_CONFIG_USE_UINTPTR_T) // PP_BOOL
#    undef SIZEOF_INTPTR_T
#    undef SIZEOF_UINTPTR_T
#endif

ct_assert_type_pair(signed char, unsigned char, 1);
ct_assert_type_pair(short, unsigned short, SIZEOF_SHORT);
ct_assert_type_pair(int, unsigned int, SIZEOF_INT);
ct_assert_type_pair(long, unsigned long, SIZEOF_LONG);
ct_assert_type_pair(long long, unsigned long long, SIZEOF_LONG_LONG);
ct_assert(sizeof(ptrdiff_t) == SIZEOF_PTRDIFF_T);
ct_assert(sizeof(size_t) == SIZEOF_SIZE_T);
ct_assert(sizeof(void *) == SIZEOF_POINTER);
#if SIZEOF_PTRDIFF_T == SIZEOF_SIZE_T
ct_assert_type_pair(ptrdiff_t, size_t, SIZEOF_PTRDIFF_T);
#endif
#if defined(ACX_CONFIG_USE_UINTPTR_T) && ACX_CONFIG_USE_UINTPTR_T // PP_BOOL
// intptr_t is special (e.g. CHERI), prefer acx_ptraddr_t whenever possible
ct_assert(sizeof(intptr_t) == SIZEOF_INTPTR_T);
ct_assert(sizeof(uintptr_t) == SIZEOF_UINTPTR_T);
ct_assert(sizeof(intptr_t) >= SIZEOF_POINTER);  // NOTE: >=
ct_assert(sizeof(uintptr_t) >= SIZEOF_POINTER); // NOTE: >=
#    if 1
// not required by the C standard, but be strict for now to avoid wrong assumptions
ct_assert_type_pair(intptr_t, uintptr_t, SIZEOF_POINTER);
#    endif
#endif // ACX_CONFIG_USE_UINTPTR_T

ct_assert(-1 == ~0);      // two's complement - see https://wg21.link/P0907R4
ct_assert(0u - 1 == ~0u); // two's complement - see https://wg21.link/P0907R4
#if SIZEOF_INT == 4
ct_assert((1u << 31) << 1 == 0);
#endif
ct_assert((1u << (8 * SIZEOF_INT - 1)) << 1 == 0);
ct_assert((1ul << (8 * SIZEOF_LONG - 1)) << 1 == 0);
ct_assert((1ull << (8 * SIZEOF_LONG_LONG - 1)) << 1 == 0);
// arithmetic right shift
#if SIZEOF_INT == 4
ct_assert(((int) (1u << 31)) >> 31 == -1);
#endif
ct_assert(((int) (1u << (8 * SIZEOF_INT - 1))) >> (8 * SIZEOF_INT - 1) == -1);
ct_assert((-1) >> (8 * SIZEOF_INT - 1) == -1);

/*************************************************************************
// 7) exact integral types
//    use types names like in Rust / V / Zig
**************************************************************************/

typedef q_uchar byte; // when dealing with data

typedef q_schar i8;
typedef q_uchar u8;

// prefer "short"
#if SIZEOF_SHORT == 2
typedef q_short i16;
typedef q_ushort u16;
#else
typedef int16_t i16;
typedef uint16_t u16;
#endif

// prefer "int"
#if SIZEOF_INT == 4
typedef q_int i32;
typedef q_uint u32;
#else
typedef int32_t i32;
typedef uint32_t u32;
#endif

// prefer "long long" then "long"
#if SIZEOF_LONG_LONG == 8
typedef q_llong i64;
typedef q_ullong u64;
#elif SIZEOF_LONG == 8
typedef q_long i64;
typedef q_ulong u64;
#else
typedef int64_t i64;
typedef uint64_t u64;
#endif

// i128 if "long long"; careful with __int128
#if SIZEOF_LONG_LONG == 16
typedef q_llong i128;
typedef q_ullong u128;
#    define SIZEOF_I128 16
#elif defined(__SIZEOF_INT128__) && __SIZEOF_INT128__ == 16
// NOTE: possibly missing __builtin support (e.g. __builtin_clz128)
// NOTE: possibly missing libstdc++ support (e.g. std::is_integral)
// NOTE: possibly missing printf() support
typedef __int128 i128;
typedef unsigned __int128 u128;
#    define SIZEOF_I128 16
#endif

ct_assert_type_pair(i8, u8, 1);
ct_assert_type_pair(i16, u16, 2);
ct_assert_type_pair(i32, u32, 4);
ct_assert_type_pair(i64, u64, 8);
#if defined(SIZEOF_I128) && SIZEOF_I128 == 16
ct_assert_type_pair(i128, u128, 16);
#endif

/*************************************************************************
// 8) acx_umode_type_XXX integral types; optional
**************************************************************************/

#if defined(__clang__) || defined(__GNUC__)

#    if defined(__CHERI__) && defined(__CHERI_PURE_CAPABILITY__)
// __attribute__((__mode__(__pointer__))) is not supported
#    else
typedef signed acx_smode_pointer_type __attribute__((__mode__(__pointer__)));
typedef unsigned acx_umode_pointer_type __attribute__((__mode__(__pointer__)));
ct_assert_type_pair(acx_smode_pointer_type, acx_umode_pointer_type, sizeof(void *));
#    endif

#    if defined(__SPU__) && (SIZEOF_POINTER == 4) && 1
// IBM Cell SPU: 128-bit vector-registers only
// gcc-3.4 uses some 128-bit type, but gcc-4.1 correctly says: "error: unable to emulate 'word'"
typedef signed acx_smode_word_type;
typedef unsigned acx_umode_word_type;
#    else
typedef signed acx_smode_word_type __attribute__((__mode__(__word__)));
typedef unsigned acx_umode_word_type __attribute__((__mode__(__word__)));
#    endif
ct_assert(sizeof(acx_umode_word_type) >= sizeof(int)); // NOTE: >=
ct_assert_type_pair(acx_smode_word_type, acx_umode_word_type, 0);

typedef signed acx_smode_byte_type __attribute__((__mode__(__byte__)));
typedef unsigned acx_umode_byte_type __attribute__((__mode__(__byte__)));
typedef signed acx_smode_hi_type __attribute__((__mode__(__HI__)));
typedef unsigned acx_umode_hi_type __attribute__((__mode__(__HI__)));
typedef signed acx_smode_si_type __attribute__((__mode__(__SI__)));
typedef unsigned acx_umode_si_type __attribute__((__mode__(__SI__)));
typedef signed acx_smode_di_type __attribute__((__mode__(__DI__)));
typedef unsigned acx_umode_di_type __attribute__((__mode__(__DI__)));
ct_assert_type_pair(acx_smode_byte_type, acx_umode_byte_type, 1);
ct_assert_type_pair(acx_smode_hi_type, acx_umode_hi_type, 2);
ct_assert_type_pair(acx_smode_si_type, acx_umode_si_type, 4);
ct_assert_type_pair(acx_smode_di_type, acx_umode_di_type, 8);
#    if defined(__GNUC__) && (__GNUC__ < 3)
#    elif SIZEOF_LONG >= 8 || SIZEOF_POINTER >= 8
typedef signed acx_smode_ti_type __attribute__((__mode__(__TI__)));
typedef unsigned acx_umode_ti_type __attribute__((__mode__(__TI__)));
ct_assert_type_pair(acx_smode_ti_type, acx_umode_ti_type, 16);
#    endif

#endif // clang || GNUC

/*************************************************************************
// 9) SIZEOF_ACX_WORD_T and acx_word_t
// integral types: machine word type aka CPU register type
// note that some machines have vector-registers only (Cell SPU, GPU(?))
**************************************************************************/

// detect IP32 on 64-bit CPU arch
#if SIZEOF_INT == 4 && SIZEOF_POINTER == 4 && SIZEOF_SIZE_T == 4
#    if SIZEOF_LONG == 8
// IP32L64 on 64-bit CPU arch (e.g. __MIPS_PSX2__)
#        define SIZEOF_ACX_WORD_T 8
#    elif (defined(_ILP32) || defined(__ILP32__)) &&                                               \
        (defined(__aarch64__) || defined(__ia64__) || defined(__loongarch64__) ||                  \
         defined(__mips64) || defined(__powerpc64__) || defined(__riscv64__) ||                    \
         defined(__x86_64__))
// ILP32 on 64-bit CPU arch
// TODO: probably all 64-bit CPUs can have ILP32: hppa64, sparc64, ..
#        define SIZEOF_ACX_WORD_T 8
#    elif defined(__mips) && defined(__mips64) && SIZEOF_LONG == 4
// ILP32 on 64-bit CPU arch
#        define SIZEOF_ACX_WORD_T 8
#    endif
#endif

#ifndef SIZEOF_ACX_WORD_T
#    define SIZEOF_ACX_WORD_T SIZEOF_SIZE_T
#endif

ct_assert(SIZEOF_ACX_WORD_T >= 4);              // IMPORTANT ALWAYS
ct_assert(SIZEOF_ACX_WORD_T >= sizeof(int));    // IMPORTANT ALWAYS
ct_assert(SIZEOF_ACX_WORD_T >= sizeof(size_t)); // require a sane architecture

#if SIZEOF_ACX_WORD_T == 4
typedef i32 acx_sword_t;
typedef u32 acx_word_t;
#elif SIZEOF_ACX_WORD_T == 8
typedef i64 acx_sword_t;
typedef u64 acx_word_t;
#elif SIZEOF_ACX_WORD_T == 16
typedef i128 acx_sword_t;
typedef u128 acx_word_t;
#else
#    error "SIZEOF_ACX_WORD_T"
#endif
ct_assert_type_pair(acx_sword_t, acx_word_t, SIZEOF_ACX_WORD_T);

// check against acx_umode_word_type
#if defined(__clang__) || defined(__GNUC__)
#    if defined(__clang__) && defined(__mips64) && SIZEOF_POINTER == 4
// GOSH, clang does *NOT* follow gcc on mips64 !!!
ct_assert(sizeof(acx_word_t) == 8);
ct_assert(sizeof(acx_umode_word_type) == 4);
#    else
ct_assert(sizeof(acx_word_t) == sizeof(acx_umode_word_type));
ct_assert(sizeof(acx_umode_word_type) == SIZEOF_ACX_WORD_T);
#    endif
#endif

// IP32 check
#if SIZEOF_SIZE_T == 4 && SIZEOF_ACX_WORD_T == 8
ct_assert(sizeof(int) == 4);
ct_assert(sizeof(void *) == 4);
ct_assert(sizeof(size_t) == 4);
ct_assert(sizeof(ptrdiff_t) == 4);
#endif

/*************************************************************************
// 10) WORDSIZE
// choose fastest type for ALU
//   - shifts must be fast !!
//   - bitops and add/sub must be fast
//   - pointer arithmetics must be fast
//   - load/store must be fast
// note that some machines have vector-registers only (Cell SPU, GPU(?))
**************************************************************************/

// possible candidates:
// #define WORDSIZE SIZEOF_SIZE_T     // preferred
// #define WORDSIZE SIZEOF_ACX_WORD_T // might be faster, but needs good compiler/ABI support
// #define WORDSIZE SIZEOF_INT        // DANGEROUS, just for testing

#define WORDSIZE SIZEOF_SIZE_T

// prefer WORDSIZE_8 on 64-bit CPU in ILP32 or IP32L64 mode
//   - these can be slightly faster when using 64-bit words for ALU
//   - BUT these can be much slower if the compiler/ABI adds unneccesary
//       sign-extend or unsigned-extend operations to pointer arithmetics
// => ONLY enable ACX_CONFIG_PREFER_WORDSIZE_8 after careful benchmarking
#if defined(ACX_CONFIG_PREFER_WORDSIZE_8) && ACX_CONFIG_PREFER_WORDSIZE_8 // PP_BOOL
#    if WORDSIZE == 4 && SIZEOF_ACX_WORD_T == 8
#        undef WORDSIZE
#        define WORDSIZE 8
#    endif
#endif

// ACX_CONFIG_FORCE_WORDSIZE
//   - allow smaller than size_t: DANGEROUS because "ptr + word" does NOT sign-extend any longer!!
//   - allow smaller than mode_word_type (e.g. ILP32 on 64-bit)
//   - allow bigger than mode_word_type (should work fine, but mainly for testing)
#if 0 && !defined(ACX_CONFIG_FORCE_WORDSIZE) // JUST FOR TESTING; SEEMS TO WORK
#    if WORDSIZE == 4
// bigger wordsize; should work fine but probably inefficient
#        define ACX_CONFIG_FORCE_WORDSIZE 8
#    elif 1 && WORDSIZE == 8 && defined(SIZEOF_I128) && SIZEOF_I128 == 16
// bigger wordsize; should work fine but probably inefficient
#        define ACX_CONFIG_FORCE_WORDSIZE 16
#    elif WORDSIZE > SIZEOF_INT
// smaller wordsize; DANGEROUS
#        define ACX_CONFIG_FORCE_WORDSIZE SIZEOF_INT
#    endif
#endif
#if defined(ACX_CONFIG_FORCE_WORDSIZE)
#    if WORDSIZE != ACX_CONFIG_FORCE_WORDSIZE
#        undef WORDSIZE
#        define WORDSIZE ACX_CONFIG_FORCE_WORDSIZE
#    else
#        undef ACX_CONFIG_FORCE_WORDSIZE
#    endif
#endif

ct_assert(WORDSIZE >= 4);           // IMPORTANT ALWAYS
ct_assert(WORDSIZE >= sizeof(int)); // IMPORTANT ALWAYS
#if !defined(ACX_CONFIG_FORCE_WORDSIZE)
ct_assert(WORDSIZE >= sizeof(size_t)); // strongly perferred to avoid DANGEROUS programming errors
#endif

/*************************************************************************
// 11) word type
// word64 means AT LEAST 64-bits !
**************************************************************************/

// fastest type for ALU
// note that some machines have vector-registers only (Cell SPU, GPU(?))
#if WORDSIZE == 4
typedef i32 sword;
typedef u32 word;
#elif WORDSIZE == 8
typedef i64 sword;
typedef u64 word;
#elif WORDSIZE == 16
typedef i128 sword;
typedef u128 word;
#else
#    error "WORDSIZE"
#endif
ct_assert_type_pair(sword, word, WORDSIZE);
ct_assert(sizeof(sword) >= 4 && sizeof(word) >= 4); // IMPORTANT ALWAYS

#if WORDSIZE >= 8 // AT LEAST 64-bits, not exactly
typedef sword sword64;
typedef word word64;
ct_assert_type_pair(sword64, word64, WORDSIZE);
#else
typedef i64 sword64;
typedef u64 word64;
ct_assert_type_pair(sword64, word64, 8);
#endif
ct_assert(sizeof(sword64) >= 8 && sizeof(word64) >= 8);                        // IMPORTANT ALWAYS
ct_assert(sizeof(sword64) >= sizeof(sword) && sizeof(word64) >= sizeof(word)); // IMPORTANT ALWAYS

// fastest type for copying aligned data - TODO: acx_word_t?

// fastest type for copying unaligned data - TODO: acx_word_t?

/*************************************************************************
// 12)
**************************************************************************/

// C++ features
#if defined(__cplusplus) && (__cplusplus + 0 >= 201103L)
#    define constexpr_cxx11 constexpr
#else
#    define constexpr_cxx11 /*empty*/
#endif
#if defined(__cplusplus) && (__cplusplus + 0 >= 201402L)
#    define constexpr_cxx14 constexpr
#else
#    define constexpr_cxx14 /*empty*/
#endif
#if defined(__cplusplus) && (__cplusplus + 0 >= 201103L)
#    define no_except noexcept
#else
#    define no_except /*empty*/
#endif

// force_inline & no_inline
#if defined(__clang__) || defined(__GNUC__)
#    define force_inline __inline__ __attribute__((__always_inline__, __unused__))
#elif defined(_MSC_VER)
#    define force_inline __forceinline
#endif
#if defined(__GNUC__) && ((__GNUC__ >= 8) || __has_attribute(__noipa__))
#    define no_inline __attribute__((__noinline__, __noipa__))
#elif defined(__GNUC__) && (__GNUC__ >= 5)
#    define no_inline __attribute__((__noinline__, __noclone__, __no_icf__))
#elif defined(__clang__) || defined(__GNUC__)
#    define no_inline __attribute__((__noinline__))
#elif defined(_MSC_VER)
#    define no_inline __declspec(noinline)
#endif
// TODO maybe: extra inline defines to express the intention
//   - force_inline_debug - inline even in debug mode because of performance reason (but could be
//   removed)
//   - no_inline_space - this noinline is intended to save space (but could be removed)

// shortcuts
#define c11inline constexpr_cxx11 force_inline
#define c14inline constexpr_cxx14 force_inline
#define cinline   constexpr_cxx14 force_inline
#define finline   force_inline

// compiler_barrier()
#if defined(__clang__) || defined(__GNUC__)
#    define compiler_barrier() __asm__ __volatile__("" ::: "memory")
#elif defined(_MSC_VER)
EXTERN_C void _ReadWriteBarrier(void);
#    define compiler_barrier() _ReadWriteBarrier()
#endif

// memcmp_inline()
#if __has_builtin(__builtin_memcmp) || (defined(__clang__) || defined(__GNUC__))
#    define memcmp_inline __builtin_memcmp
#else
#    define memcmp_inline memcmp
#endif

// memcpy_inline()
#if __has_builtin(__builtin_memcpy_inline) && 0 // TODO later: problems with clang + constexpr?
#    define memcpy_inline(d, s, n)                                                                 \
        BLOCK_BEGIN                                                                                \
        ct_assertf((n) >= 1);                                                                      \
        __builtin_memcpy_inline((d), (s), (n));                                                    \
        BLOCK_END
#elif __has_builtin(__builtin_memcpy) || (defined(__clang__) || defined(__GNUC__))
#    define memcpy_inline(d, s, n)                                                                 \
        BLOCK_BEGIN                                                                                \
        ct_assertf((n) >= 1);                                                                      \
        __builtin_memcpy((d), (s), (n));                                                           \
        BLOCK_END
#else
#    define memcpy_inline(d, s, n)                                                                 \
        BLOCK_BEGIN                                                                                \
        ct_assertf((n) >= 1);                                                                      \
        memcpy((d), (s), (n));                                                                     \
        BLOCK_END
#endif

/*************************************************************************
// 13) pointers
**************************************************************************/

#include "acx_ptr.h"

/*************************************************************************
// 14) mul and bitops
//
// "_hbc": High Bits Clear - assume that high-bits are clear (unset)
// "_nz":  Non Zero (i.e. v is not 0)
**************************************************************************/

// 32x32 => 32 multiply
static cinline word mul_32_32_32(word a, word b) no_except {
    // return (u32) ((u32) a * (u32) b); // might be faster on some archs
    return (u32) (a * b);
}
// 32x32 => 64 multiply
static cinline word64 mul_32_32_64(word a, word b) no_except {
    // return (u64) (u32) a * (u64) (u32) b; // might be faster on some 128-bit archs
    return (word64) (u32) a * (word64) (u32) b;
}
// 32x32 => 64 multiply, assuming high-bits in a and b are clear
static cinline word64 mul_32_32_64_hbc(word a, word b) no_except {
    // return (u64) a * (u64) b; // might be faster on some 128-bit archs
    return (word64) a * (word64) b;
}

// bitops - ctz_nz - TODO
// bitops - popcount - TODO
#if (defined(__GNUC__) || __has_builtin(__builtin_clz)) && (SIZEOF_INT == 4)
static cinline word clz32_nz(word v) no_except { return (word) __builtin_clz((q_uint) v); }
#elif (defined(__GNUC__) || __has_builtin(__builtin_clz)) && (SIZEOF_INT == 8)
static cinline word clz32_nz(word v) no_except {
    return (word) __builtin_clz((q_uint) (u32) v) ^ 32;
}
#elif defined(_MSC_VER) && (SIZEOF_LONG == 4)
static finline word clz32_nz(word v) no_except {
    q_ulong r;
    (void) _BitScanReverse(&r, (u32) v);
    return (word) r ^ 31;
}
#endif

#if (defined(__GNUC__) || __has_builtin(__builtin_clzll)) && (SIZEOF_LONG_LONG == 8)
#    define HAVE_clz64_nz 1
static cinline word clz64_nz(word64 v) no_except { return (word) __builtin_clzll((q_ullong) v); }
#elif (defined(__GNUC__) || __has_builtin(__builtin_clzl)) && (SIZEOF_LONG == 8)
#    define HAVE_clz64_nz 1
static cinline word clz64_nz(word64 v) no_except { return (word) __builtin_clzl((q_ulong) v); }
#elif defined(_MSC_VER) && (SIZEOF_POINTER >= 8)
#    define HAVE_clz64_nz 1
static finline word clz64_nz(word64 v) no_except {
    q_ulong r;
    (void) _BitScanReverse64(&r, (u64) v); // not available on i386
    return (word) r ^ 63;
}
#else
#    define HAVE_clz64_nz 0
#endif

// bitops - bswap
#if __has_builtin(__builtin_bswap64) || (defined(__GNUC__) && (__GNUC__ >= 5)) // TODO: gcc-4.3
static cinline word bswap16(word v) no_except {
    // return (word) __builtin_bswap32((u32) (v << 16)); // might be faster on some archs
    // return (word) __builtin_bswap64((u64) v << 48); // might be faster on some archs
#    if defined(__clang__) && defined(__mips)
    // @BUG: clang mips Debug miscompilation: https://github.com/llvm/llvm-project/issues/103035
    return (word) __builtin_bswap16((u16) (v & 0xffff));
#    else
    return (word) __builtin_bswap16((u16) v);
#    endif
}
static cinline word bswap32(word v) no_except {
    // return (word) __builtin_bswap64((u64) v << 32); // might be faster on some archs
    return (word) __builtin_bswap32((u32) v);
}
static cinline word64 bswap64(word64 v) no_except { return __builtin_bswap64((u64) v); }
#elif defined(_MSC_VER)
static finline word bswap16(word v) no_except { return (word) _byteswap_ulong((u32) (v << 16)); }
static finline word bswap32(word v) no_except { return (word) _byteswap_ulong((u32) v); }
static finline word64 bswap64(word64 v) no_except { return _byteswap_uint64((u64) v); }
#else
#    define SLOW_BSWAP 1
static cinline word bswap16(word v) no_except { return ((v & 0xff) << 8) | ((v >> 8) & 0xff); }
static cinline word bswap32(word v) no_except {
    return ((v & 0xff) << 24) | ((v & 0xff00) << 8) | ((v >> 8) & 0xff00) | ((v >> 24) & 0xff);
}
static cinline word64 bswap64(word64 v) no_except {
    return ((v & 0xff) << 56) | ((v & 0xff00) << 40) | ((v & 0xff0000) << 24) |
           ((v & 0xff000000) << 8) | ((v >> 8) & 0xff000000) | ((v >> 24) & 0xff0000) |
           ((v >> 40) & 0xff00) | ((v >> 56) & 0xff);
}
#endif
// bitops - no_bswap
static cinline word no_bswap16(word v) no_except { return v & 0xffff; }
static cinline word no_bswap32(word v) no_except { return (u32) v; }
static cinline word64 no_bswap64(word64 v) no_except { return (u64) v; }

/*************************************************************************
// 15) UA - Unaligned Access
**************************************************************************/

//
// UA_PACKED_STRUCT
// this is the old way of efficient Unaligned Access, but
//   - it uses non-standard extensions
//   - is prone to compiler/optimizer bugs
//   - has problems with UBSAN on some archs (e.g. clang-18 mips in Debug mode)
// => ONLY use this if the generated code is more efficient AND is thoroughly tested!
//

#if defined(__clang__) || defined(__GNUC__)
#    define UA_PACKED_STRUCT(decl) decl __attribute__((__packed__, __aligned__(1), __may_alias__))
#elif defined(_MSC_VER)
#    define UA_PACKED_STRUCT(decl) __pragma(pack(push, 1)) decl __pragma(pack(pop))
#endif
#if defined(UA_PACKED_STRUCT)
UA_PACKED_STRUCT(struct UA1_T { u8 v; });
UA_PACKED_STRUCT(struct UA2_T { u16 v; });
UA_PACKED_STRUCT(struct UA4_T { u32 v; });
UA_PACKED_STRUCT(struct UA8_T { u64 v; });
ct_assert(sizeof(struct UA1_T) == 1);
ct_assert(sizeof(struct UA2_T) == 2);
ct_assert(sizeof(struct UA4_T) == 4);
ct_assert(sizeof(struct UA8_T) == 8);
ct_assert(__alignof__(struct UA1_T) == 1);
ct_assert(__alignof__(struct UA2_T) == 1);
ct_assert(__alignof__(struct UA4_T) == 1);
ct_assert(__alignof__(struct UA8_T) == 1);
#    if 0
#        if 0
#            define UA_GET1(p)    ((word) (((const struct UA1_T *) (p))->v))
#            define UA_GET2(p)    ((word) (((const struct UA2_T *) (p))->v))
#            define UA_GET4(p)    ((word) (((const struct UA4_T *) (p))->v))
#            define UA_GET8(p)    ((word64) (((const struct UA8_T *) (p))->v))
#            define UA_SET1(p, x) (((struct UA1_T *) (p))->v = (u8) (x))
#            define UA_SET2(p, x) (((struct UA2_T *) (p))->v = (u16) (x))
#            define UA_SET4(p, x) (((struct UA4_T *) (p))->v = (u32) (x))
#            define UA_SET8(p, x) (((struct UA8_T *) (p))->v = (u64) (x))
#        else
static finline word UA_GET1(const void *p) no_except { return ((const struct UA1_T *) p)->v; }
static finline word UA_GET2(const void *p) no_except { return ((const struct UA2_T *) p)->v; }
static finline word UA_GET4(const void *p) no_except { return ((const struct UA4_T *) p)->v; }
static finline word64 UA_GET8(const void *p) no_except { return ((const struct UA8_T *) p)->v; }
static finline void UA_SET1(void *p, word x) no_except { ((struct UA1_T *) p)->v = (u8) x; }
static finline void UA_SET2(void *p, word x) no_except { ((struct UA2_T *) p)->v = (u16) x; }
static finline void UA_SET4(void *p, word x) no_except { ((struct UA4_T *) p)->v = (u32) x; }
static finline void UA_SET8(void *p, word64 x) no_except { ((struct UA8_T *) p)->v = (u64) x; }
#        endif
#    endif
#endif // UA_PACKED_STRUCT

//
// UA with memcpy()
// this is the modern and only portable way of using Unaligned Access
//   - any halfway recent compiler should be able to properly optimize this
// => use this whenever possible
//

static finline word UA_GET1(const void *p) no_except {
    u8 v = 0;
    memcpy_inline(&v, p, sizeof(v));
    return v;
}
static finline word UA_GET2(const void *p) no_except {
    u16 v = 0;
    memcpy_inline(&v, p, sizeof(v));
    return v;
}
static finline word UA_GET4(const void *p) no_except {
    u32 v = 0;
    memcpy_inline(&v, p, sizeof(v));
    return v;
}
static finline word64 UA_GET8(const void *p) no_except {
    u64 v = 0;
    memcpy_inline(&v, p, sizeof(v));
    return v;
}

static finline void UA_SET1(void *p, word v) no_except {
    u8 vv = (u8) v;
    memcpy_inline(p, &vv, sizeof(vv));
}
static finline void UA_SET2(void *p, word v) no_except {
    u16 vv = (u16) v;
    memcpy_inline(p, &vv, sizeof(vv));
}
static finline void UA_SET4(void *p, word v) no_except {
    u32 vv = (u32) v;
    memcpy_inline(p, &vv, sizeof(vv));
}
static finline void UA_SET8(void *p, word64 v) no_except {
    u64 vv = (u64) v;
    memcpy_inline(p, &vv, sizeof(vv));
}
