/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

// clang-format off
//
// ~/local/bin/cc-i386-linux/i386-linux-g++-2.95.3 -Wall -W -pedantic -Wno-long-long type_traits_x.cpp
// g++ -Wall -Wextra -Wcast-align -Wcast-qual -pedantic type_traits_x.cpp
// clang++ -Weverything -Wno-c++98-compat-pedantic -Wno-old-style-cast type_traits_x.cpp
//
// clang-format on

#include <limits.h>

#if defined(__i386__)
#    define SIZEOF_LONG_LONG 8
#    define SIZEOF_POINTER   4
#endif
#include "../include/acx_sizeof.h"

typedef signed char i8;
typedef unsigned char u8;
typedef signed short i16;
typedef unsigned short u16;
typedef signed int i32;
typedef unsigned int u32;
typedef signed long long i64;
typedef unsigned long long u64;

#if defined(__SIZE_TYPE__)
typedef __SIZE_TYPE__ size_t;
#elif defined(_WIN64)
typedef unsigned long long size_t;
#elif SIZEOF_SIZE_T == SIZEOF_LONG
typedef unsigned long size_t;
#elif SIZEOF_SIZE_T == SIZEOF_INT
typedef unsigned int size_t;
#endif

namespace acx {
#include "../include/acx_type_traits.h"
}

#define PP_CONCAT4(a, b, c, d)  a##b##c##d
#define PP_ECONCAT4(a, b, c, d) PP_CONCAT4(a, b, c, d)
#define CTA_INTERNAL_NAME(a)    PP_ECONCAT4(CTA_INTERNAL_PREFIX, a, __LINE__, CTA_INTERNAL_SUFFIX)
#define CTA_IN_GLOBAL_SCOPE(e)  enum { CTA_INTERNAL_NAME(cta_failed_) = 1 / int(!!(e)) }
#define ct_assert               CTA_IN_GLOBAL_SCOPE
#define no_inline               /*empty*/

#define TESTING_ACX 1
#include "cxx_type_traits_test.h"
#undef TESTING_ACX

int main(void) { return 0; }
