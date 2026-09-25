/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

// naked_c.c: no system headers at all when using clang or gcc

#if defined(_MSC_VER) && !defined(__clang__)
// #    pragma warning(disable : 4127) // W4: conditional expression is constant
#    pragma warning(disable : 4514) // W4: unreferenced inline function has been removed
#    pragma warning(disable : 4710) // W4: function not inlined
#    pragma warning(error : 4714)   // W4: function marked as __forceinline not inlined
#    pragma warning(disable : 4820) // W4: 'x' bytes padding added after data member 'y'
#    if _MSC_VER >= 1800
#        pragma warning(disable : 4464) // Wall: relative include path contains '..'
#    endif
#endif

#if defined(__clang__) || defined(__GNUC__)
// <limits.h>
#    define CHAR_BIT 8
#    if defined(__CHAR_UNSIGNED__)
#        define CHAR_MAX 255
#    else
#        define CHAR_MAX 127
#    endif
// <stddef.h>
typedef __PTRDIFF_TYPE__ my_ptrdiff_t;
typedef __SIZE_TYPE__ my_size_t;
#    define ptrdiff_t my_ptrdiff_t
#    define size_t    my_size_t
// IP32L64
#    if defined(__mips) && defined(__mips64) && defined(__R5900) &&                                \
        (defined(__ee__) || defined(_EE))
#        define SIZEOF_SHORT     2
#        define SIZEOF_INT       4
#        define SIZEOF_LONG      8
#        define SIZEOF_LONG_LONG 8
#        define SIZEOF_POINTER   4
#    endif
// ILP64 and SILP64
#    if defined(__SHRT_MAX__) && (__SHRT_MAX__ != 32767)
typedef signed int16_t __attribute__((__mode__(__HI__)));
typedef unsigned uint16_t __attribute__((__mode__(__HI__)));
#    endif
#    if defined(__INT_MAX__) && (__INT_MAX__ != 2147483647)
typedef signed int32_t __attribute__((__mode__(__SI__)));
typedef unsigned uint32_t __attribute__((__mode__(__SI__)));
#    endif
#    if !defined(SIZEOF_POINTER) && !defined(__SIZEOF_POINTER__)
#        if defined(_WIN64)
#            define SIZEOF_POINTER SIZEOF_LONG_LONG
#        else
#            define SIZEOF_POINTER SIZEOF_LONG
#        endif
#    endif
#else
#    include <limits.h>
#    include <stddef.h>
#    include <string.h> // memcmp(), memcpy()
#    if defined(_MSC_VER) && !defined(__clang__)
#        include "msvc_intrin.h"
#    endif
#endif

#include "../include/acx.h"
#if defined(__cplusplus)
namespace acx {
#    include "../include/acx_type_traits.h"
}
#endif

// TODO: __builtin_trap()
static int exit_code = 0;
#ifdef assert
#    undef assert
#endif
#define assert(e)                                                                                  \
    BLOCK_BEGIN                                                                                    \
    if (!(e)) {                                                                                    \
        exit_code = 1;                                                                             \
    }                                                                                              \
    BLOCK_END

/*************************************************************************
// codegen
**************************************************************************/

no_inline word test_codegen_mul_32_32_32(word a, word b) { return mul_32_32_32(a, b); }
no_inline word64 test_codegen_mul_32_32_64(word a, word b) { return mul_32_32_64(a, b); }
no_inline word64 test_codegen_mul_32_32_64_hbc(word a, word b) { return mul_32_32_64_hbc(a, b); }
no_inline word test_codegen_clz32_nz(word v) { return clz32_nz(v); }
#if HAVE_clz64_nz
no_inline word test_codegen_clz64_nz(word64 v) { return clz64_nz(v); }
#endif
no_inline word test_codegen_bswap16(word v) { return bswap16(v); }
no_inline word test_codegen_bswap32(word v) { return bswap32(v); }
no_inline word64 test_codegen_bswap64(word64 v) { return bswap64(v); }
no_inline word test_codegen_UA_GET1(const void *p) { return UA_GET1(p); }
no_inline word test_codegen_UA_GET2(const void *p) { return UA_GET2(p); }
no_inline word test_codegen_UA_GET4(const void *p) { return UA_GET4(p); }
no_inline word64 test_codegen_UA_GET8(const void *p) { return UA_GET8(p); }
no_inline void test_codegen_UA_SET1(void *p, word x) { UA_SET1(p, x); }
no_inline void test_codegen_UA_SET2(void *p, word x) { UA_SET2(p, x); }
no_inline void test_codegen_UA_SET4(void *p, word x) { UA_SET4(p, x); }
no_inline void test_codegen_UA_SET8(void *p, word64 x) { UA_SET8(p, x); }
#include "codegen_copy_ua.h"
#include "codegen_core.h"
#include "codegen_memcpy_inline.h"
#if defined(__BYTE_ORDER__)
#    include "codegen_memcpy_musl_u32.h"
#endif
#include "attribute_naked.h"
#include "codegen_memcmp_inline.h"
#if defined(__cplusplus)
#    include "cxx_type_traits.h"
#endif

/*************************************************************************
//
**************************************************************************/

#if defined(__cplusplus)
struct TestCTA_1 {
    ct_assert(1 == 1);
    static cinline void foo() no_except { ct_assertf(1 == 1); }
};
template <class T> struct TestCTA_2 {
    ct_assert(sizeof(T) == sizeof(int));
    static cinline void foo() no_except { ct_assertf(sizeof(T) == sizeof(int)); }
};
// instantiate instances
// template struct TestCTA_2<char>; // DOES NOT COMPILE
template struct TestCTA_2<int>;
#endif

static no_inline byte *test_ptr_add_word(byte *p, word n) no_except { return p + n; }
static no_inline byte *test_ptr_sub_word(byte *p, word n) no_except { return p - n; }
static no_inline byte *test_ptr_add_sword(byte *p, sword n) no_except { return p + n; }
static no_inline byte *test_ptr_sub_sword(byte *p, sword n) no_except { return p - n; }

static no_inline void test_ptr(void) {
    byte buf_base[2 * 64];
    byte *buf = ptr_align_up_bp(buf_base, 64);
    byte *x = buf + (64 - 1);
    word a;

    assert(test_ptr_add_word(x, 1) == buf + 64);
    assert(test_ptr_sub_word(x, 1) == buf + 62);
    assert(test_ptr_add_sword(x, 1) == buf + 64);
    assert(test_ptr_add_sword(x, -1) == buf + 62);
    assert(test_ptr_sub_sword(x, 1) == buf + 62);
    assert(test_ptr_sub_sword(x, -1) == buf + 64);
#if defined(NO_STRICT_OVERFLOW)
    // NOTE: this is actually UB, and clang UBSAN does complain
    // unless we are using -fno-strict-overflow. GOOD!
#    if !defined(ACX_CONFIG_FORCE_WORDSIZE)
    // example how DANGEROUS using special wordsize is: does not sign-extend
    assert(test_ptr_add_word(x, (word) 0 - (word) 1) == buf + 62);
#    endif
#    if WORDSIZE >= SIZEOF_SIZE_T
    assert(test_ptr_add_word(x, (word) 0 - (word) 1) == buf + 62);
#    endif
#endif

    for (a = 1; a <= 64; a <<= 1) {
        assert(ptr_is_aligned(buf, a));
        assert(a == 1 || !ptr_is_aligned(x, a));
    }

    assert(ptr_align_down_bp(x, 1) - buf == 63);
    assert(ptr_align_down_bp(x, 2) - buf == 62);
    assert(ptr_align_down_bp(x, 4) - buf == 60);
    assert(ptr_align_down_bp(x, 8) - buf == 56);
    assert(ptr_align_down_bp(x, 16) - buf == 48);
    assert(ptr_align_down_bp(x, 32) - buf == 32);
    assert(ptr_align_down_bp(x, 64) - buf == 0);

    assert(ptr_align_up_bp(buf, 1) - buf == 0);
    assert(ptr_align_up_bp(buf, 2) - buf == 0);
    assert(ptr_align_up_bp(buf, 4) - buf == 0);
    assert(ptr_align_up_bp(buf, 8) - buf == 0);
    assert(ptr_align_up_bp(buf, 16) - buf == 0);
    assert(ptr_align_up_bp(buf, 32) - buf == 0);
    assert(ptr_align_up_bp(buf, 64) - buf == 0);

    x = buf + 1;
    assert(ptr_align_up_bp(x, 1) - buf == 1);
    assert(ptr_align_up_bp(x, 2) - buf == 2);
    assert(ptr_align_up_bp(x, 4) - buf == 4);
    assert(ptr_align_up_bp(x, 8) - buf == 8);
    assert(ptr_align_up_bp(x, 16) - buf == 16);
    assert(ptr_align_up_bp(x, 32) - buf == 32);
    assert(ptr_align_up_bp(x, 64) - buf == 64);
}

static no_inline void test_bitops(void) {
    word i, a;
    word64 b;
    for (i = 1, a = 1; i < 32; i++, a <<= 1) {
        assert(a >= i);
        assert(clz32_nz(a) == 32 - i);
        assert(clz32_nz(a | 1) == 32 - i);
    }
    for (i = 1, b = 1; i < 64; i++, b <<= 1) {
        assert(b >= i);
#if HAVE_clz64_nz
        assert(clz64_nz(b) == 64 - i);
        assert(clz64_nz(b | 1) == 64 - i);
#endif
    }
}

static no_inline void test_ua(byte *p) {
    u32 v32;
    ct_assertf(1 == 1);
    assert(UA_GET2(p + 0) == 0x0001 || UA_GET2(p + 0) == 0x0100);
    assert(UA_GET2(p + 1) == 0x0102 || UA_GET2(p + 1) == 0x0201);
    assert(UA_GET4(p + 0) == 0x00010203 || UA_GET4(p + 0) == 0x03020100);
    assert(UA_GET4(p + 1) == 0x01020304 || UA_GET4(p + 1) == 0x04030201);
    assert(UA_GET8(p + 1) == 0x0102030405060708ull || UA_GET8(p + 1) == 0x0807060504030201ull);
    UA_SET8(p + 11, bswap64(0xf0f1f2f3f4f5f6f7ull));
    UA_SET4(p + 13, bswap32(0xf0f1f2f3));
    UA_SET2(p + 15, bswap16(0xf0f1));
    memcpy_inline(p + 33, p + 11, 8);
    assert(UA_GET8(p + 33) == 0xf7f6f1f0f1f0f1f0ull || UA_GET8(p + 33) == 0xf7f6f3f2f1f0f1f0ull);
    UA_SET8(p, 0x0808080808080808ull);
    UA_SET4(p + 2, 0x04040404);
    UA_SET2(p + 3, 0x0202);
    UA_SET1(p, 0x01);
    UA_SET1(p + 7, 0x01);
    assert(UA_GET8(p) == 0x0108040202040801ull);
    v32 = 0;
    UA_SET2(&v32, 1);
    assert(v32 != 0);
    v32 = 0;
    ct_assertf(1 == 1);
    UA_SET2((byte *) &v32 + 1, 1);
    assert(v32 != 0);
    ct_assertf(1 == 1);
}

static force_inline int foo(int a) { return a; }

static force_inline word unused_bar(word a) { return a + 1; } // check that __unused__ works

static no_inline void compiler_sanity_check(void) {
#if defined(_MSC_VER) && !defined(__clang__) // does not work with MSVC
    ct_assertf(1 == 1);
#else
#    if '\0' - 1 < 0
    ct_assertf(CHAR_MAX == 127);
#    else
    ct_assertf(CHAR_MAX == 255);
#    endif
#endif
    assert(bswap16(0x0201) == 0x0102);
    assert(bswap32(0x04030201) == 0x01020304);
    assert(bswap64(0x0807060504030201ull) == 0x0102030405060708ull);
    assert(no_bswap16(0x0201) == 0x0201);
    assert(no_bswap32(0x04030201) == 0x04030201);
    assert(no_bswap64(0x0807060504030201ull) == 0x0807060504030201ull);
    // ignore upper bits
    assert(bswap16(0x04030201) == 0x0102);
#if WORDSIZE >= 8
    assert(bswap32(0x0807060504030201ull) == 0x01020304);
#endif
    assert(no_bswap16(0x04030201) == 0x0201);
#if WORDSIZE >= 8
    assert(no_bswap32(0x0807060504030201ull) == 0x04030201);
#endif
    assert(test_codegen_bswap16(0x08040201) == 0x0102);
    assert(test_codegen_bswap32(0x08040201) == 0x01020408);
    assert(test_codegen_bswap64(0x8040201008040201ull) == 0x0102040810204080ull);
#if WORDSIZE >= 8
    assert(test_codegen_bswap32(0x8040201008040201ull) == 0x01020408);
#endif
    ct_assertf(1 == 1);
}

EXTERN_C const char wordsize_info[];
#if WORDSIZE == 4
const char wordsize_info[] = "WORDSIZE=4";
#elif WORDSIZE == 8
const char wordsize_info[] = "WORDSIZE=8";
#elif WORDSIZE == 16
const char wordsize_info[] = "WORDSIZE=16";
#else
const char wordsize_info[] = "WORDSIZE=UNKNOWN";
#endif
#if defined(ACX_CONFIG_FORCE_WORDSIZE)
EXTERN_C const char force_wordsize_info[];
const char force_wordsize_info[] = "ACX_CONFIG_FORCE_WORDSIZE";
#endif
#if defined(__cplusplus)
EXTERN_C const char cplusplus_info[];
const char cplusplus_info[] = "__cplusplus=" PP_MACRO_EXPAND(__cplusplus);
#endif

int main(void) {
    byte buf[64];
    int size = 64;
    int i;

    compiler_sanity_check();
    test_ptr();
    test_bitops();

    for (i = 0; i < size; i++)
        buf[i] = (byte) (i & 0xff);
    test_ua(buf);

    return exit_code;
}
