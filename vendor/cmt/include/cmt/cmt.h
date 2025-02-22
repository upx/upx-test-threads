/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer
/// CMT - CMake Test - version 20250215

#pragma once

#include <limits.h>
#include <stddef.h>

#if CHAR_BIT != 8
#    error "unexpected CHAR_BIT"
#endif

/*************************************************************************
//
**************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

size_t cmt_func_and(size_t *ptr, size_t n);
size_t cmt_func_xor(size_t *ptr, size_t n);

size_t cmt_func_add(size_t *ptr, size_t n);
size_t cmt_func_sub(size_t *ptr, size_t n);

#if defined(__cplusplus)
} /* extern "C" */
#endif
