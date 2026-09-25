/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

// conf.h must be the very first include header
#pragma once

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

// for old gcc versions
#if defined(__GNUC__) && !defined(__SIZEOF_POINTER__)
#    if ((__LONG_MAX__ >> 30) >> 30) == 7 || defined(_WIN64)
#        define SIZEOF_PTRDIFF_T 8
#        define SIZEOF_SIZE_T    8
#        define SIZEOF_INTPTR_T  8
#        define SIZEOF_UINTPTR_T 8
#        define SIZEOF_POINTER   8
#    elif (__LONG_MAX__ >> 30) == 1
#        define SIZEOF_PTRDIFF_T 4
#        define SIZEOF_SIZE_T    4
#        define SIZEOF_INTPTR_T  4
#        define SIZEOF_UINTPTR_T 4
#        define SIZEOF_POINTER   4
#    endif
#endif

// system_headers
#include <limits.h>
#include <stddef.h>
#if defined(ACX_CONFIG_USE_UINTPTR_T) && ACX_CONFIG_USE_UINTPTR_T // PP_BOOL
// <stdint.h> only exists since VS2010 (Apr 2010) _MSC_VER == 1600
// <stdint.h> only fully works since VS2012 (Sep 2012) _MSC_VER == 1700
#    if defined(_WIN64) && defined(_MSC_VER) && !defined(__clang__) && (_MSC_VER < 1700)
// fix broken defines in VS2010 (Apr 2010)
#        define _INTPTR 2
#    endif
#    include <stdint.h>
#endif
#if defined(__NetBSD__)
#    include <stdlib.h>
#endif
#include <string.h> // memcmp(), memcpy()
#if defined(_MSC_VER) && !defined(__clang__)
#    include "msvc_intrin.h"
#endif

#include "../include/acx.h"
#if defined(__cplusplus)
namespace acx {
#    include "../include/acx_type_traits.h"
}
#endif
