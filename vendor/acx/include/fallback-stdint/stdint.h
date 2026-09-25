/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

#pragma once
#include <limits.h>

// extremely minimal <stdint.h> just enough for the needs of acx.h
// intended as fallback for old MSVC compilers

#if defined(_WIN64)
#    if defined(ACX_CONFIG_USE_UINTPTR_T) && ACX_CONFIG_USE_UINTPTR_T // PP_BOOL
#        ifndef _INTPTR_T_DEFINED
typedef long long intptr_t;
#            define _INTPTR_T_DEFINED 1
#        endif
#        ifndef _UINTPTR_T_DEFINED
typedef unsigned long long uintptr_t;
#            define _UINTPTR_T_DEFINED 1
#        endif
#    endif

#elif defined(_WIN32)
#    if defined(ACX_CONFIG_USE_UINTPTR_T) && ACX_CONFIG_USE_UINTPTR_T // PP_BOOL
#        ifndef _INTPTR_T_DEFINED
typedef int intptr_t;
#            define _INTPTR_T_DEFINED 1
#        endif
#        ifndef _UINTPTR_T_DEFINED
typedef unsigned int uintptr_t;
#            define _UINTPTR_T_DEFINED 1
#        endif
#    endif

#elif defined(__SIZEOF_POINTER__) && (__SIZEOF_POINTER__ == 16) && (__SIZEOF_LONG_LONG__ == 16)
#    if defined(ACX_CONFIG_USE_UINTPTR_T) && ACX_CONFIG_USE_UINTPTR_T // PP_BOOL
typedef long long intptr_t;
typedef long unsigned long uintptr_t;
#    endif

#elif ((LONG_MAX >> 30) >> 30) == 7
#    if defined(ACX_CONFIG_USE_UINTPTR_T) && ACX_CONFIG_USE_UINTPTR_T // PP_BOOL
typedef long intptr_t;
typedef unsigned long uintptr_t;
#    endif

#elif (LONG_MAX >> 30) == 1
#    if defined(ACX_CONFIG_USE_UINTPTR_T) && ACX_CONFIG_USE_UINTPTR_T // PP_BOOL
typedef long intptr_t;
typedef unsigned long uintptr_t;
#    endif

#endif
