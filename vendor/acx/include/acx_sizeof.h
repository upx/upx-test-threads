/// DO NOT EDIT, GENERATED AUTOMATICALLY.
/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

#pragma once
// #include <limits.h>
// #include <stdint.h>

#if !defined(SIZEOF_POINTER) && defined(SIZEOF_VOID_P) && (SIZEOF_VOID_P + 0 > 0)
#    define SIZEOF_POINTER SIZEOF_VOID_P
#endif

// SIZEOF_SHORT
// SIZEOF_INT
// SIZEOF_LONG
// SIZEOF_LONG_LONG
// SIZEOF_PTRDIFF_T
// SIZEOF_SIZE_T
// SIZEOF_INTPTR_T
// SIZEOF_UINTPTR_T
// SIZEOF_POINTER

#if !defined(SIZEOF_SHORT)
#    if defined(__SIZEOF_SHORT__)
#        define SIZEOF_SHORT __SIZEOF_SHORT__
#    elif defined(__SHRT_WIDTH__) && (__SHRT_WIDTH__ + 0 > 0)
#        define SIZEOF_SHORT (__SHRT_WIDTH__ / 8)
#    elif defined(__SHRT_MAX__) && (__SHRT_MAX__ >> 6) == 1
#        define SIZEOF_SHORT 1
#    elif defined(__SHRT_MAX__) && (__SHRT_MAX__ >> 14) == 1
#        define SIZEOF_SHORT 2
#    elif defined(__SHRT_MAX__) && (__SHRT_MAX__ >> 30) == 1
#        define SIZEOF_SHORT 4
#    elif defined(__SHRT_MAX__) && ((__SHRT_MAX__ >> 30) >> 30) == 7
#        define SIZEOF_SHORT 8
#    elif defined(__SHRT_MAX__) && ((((__SHRT_MAX__ >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_SHORT 16
#    endif
#endif

#if !defined(SIZEOF_INT)
#    if defined(__SIZEOF_INT__)
#        define SIZEOF_INT __SIZEOF_INT__
#    elif defined(__INT_WIDTH__) && (__INT_WIDTH__ + 0 > 0)
#        define SIZEOF_INT (__INT_WIDTH__ / 8)
#    elif defined(__INT_MAX__) && (__INT_MAX__ >> 6) == 1
#        define SIZEOF_INT 1
#    elif defined(__INT_MAX__) && (__INT_MAX__ >> 14) == 1
#        define SIZEOF_INT 2
#    elif defined(__INT_MAX__) && (__INT_MAX__ >> 30) == 1
#        define SIZEOF_INT 4
#    elif defined(__INT_MAX__) && ((__INT_MAX__ >> 30) >> 30) == 7
#        define SIZEOF_INT 8
#    elif defined(__INT_MAX__) && ((((__INT_MAX__ >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_INT 16
#    endif
#endif

#if !defined(SIZEOF_LONG)
#    if defined(__SIZEOF_LONG__)
#        define SIZEOF_LONG __SIZEOF_LONG__
#    elif defined(__LONG_WIDTH__) && (__LONG_WIDTH__ + 0 > 0)
#        define SIZEOF_LONG (__LONG_WIDTH__ / 8)
#    elif defined(__LONG_MAX__) && (__LONG_MAX__ >> 6) == 1
#        define SIZEOF_LONG 1
#    elif defined(__LONG_MAX__) && (__LONG_MAX__ >> 14) == 1
#        define SIZEOF_LONG 2
#    elif defined(__LONG_MAX__) && (__LONG_MAX__ >> 30) == 1
#        define SIZEOF_LONG 4
#    elif defined(__LONG_MAX__) && ((__LONG_MAX__ >> 30) >> 30) == 7
#        define SIZEOF_LONG 8
#    elif defined(__LONG_MAX__) && ((((__LONG_MAX__ >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_LONG 16
#    endif
#endif

#if !defined(SIZEOF_LONG_LONG)
#    if defined(__SIZEOF_LONG_LONG__)
#        define SIZEOF_LONG_LONG __SIZEOF_LONG_LONG__
#    elif defined(__LONG_LONG_WIDTH__) && (__LONG_LONG_WIDTH__ + 0 > 0)
#        define SIZEOF_LONG_LONG (__LONG_LONG_WIDTH__ / 8)
#    elif defined(__LONG_LONG_MAX__) && (__LONG_LONG_MAX__ >> 6) == 1
#        define SIZEOF_LONG_LONG 1
#    elif defined(__LONG_LONG_MAX__) && (__LONG_LONG_MAX__ >> 14) == 1
#        define SIZEOF_LONG_LONG 2
#    elif defined(__LONG_LONG_MAX__) && (__LONG_LONG_MAX__ >> 30) == 1
#        define SIZEOF_LONG_LONG 4
#    elif defined(__LONG_LONG_MAX__) && ((__LONG_LONG_MAX__ >> 30) >> 30) == 7
#        define SIZEOF_LONG_LONG 8
#    elif defined(__LONG_LONG_MAX__) && ((((__LONG_LONG_MAX__ >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_LONG_LONG 16
#    endif
#endif

#if !defined(SIZEOF_PTRDIFF_T)
#    if defined(__SIZEOF_PTRDIFF_T__)
#        define SIZEOF_PTRDIFF_T __SIZEOF_PTRDIFF_T__
#    elif defined(__PTRDIFF_WIDTH__) && (__PTRDIFF_WIDTH__ + 0 > 0)
#        define SIZEOF_PTRDIFF_T (__PTRDIFF_WIDTH__ / 8)
#    elif defined(__PTRDIFF_MAX__) && (__PTRDIFF_MAX__ >> 6) == 1
#        define SIZEOF_PTRDIFF_T 1
#    elif defined(__PTRDIFF_MAX__) && (__PTRDIFF_MAX__ >> 14) == 1
#        define SIZEOF_PTRDIFF_T 2
#    elif defined(__PTRDIFF_MAX__) && (__PTRDIFF_MAX__ >> 30) == 1
#        define SIZEOF_PTRDIFF_T 4
#    elif defined(__PTRDIFF_MAX__) && ((__PTRDIFF_MAX__ >> 30) >> 30) == 7
#        define SIZEOF_PTRDIFF_T 8
#    elif defined(__PTRDIFF_MAX__) && ((((__PTRDIFF_MAX__ >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_PTRDIFF_T 16
#    endif
#endif

#if !defined(SIZEOF_SIZE_T)
#    if defined(__SIZEOF_SIZE_T__)
#        define SIZEOF_SIZE_T __SIZEOF_SIZE_T__
#    elif defined(__SIZE_WIDTH__) && (__SIZE_WIDTH__ + 0 > 0)
#        define SIZEOF_SIZE_T (__SIZE_WIDTH__ / 8)
#    elif defined(__SIZE_MAX__) && (__SIZE_MAX__ >> 6) == 3
#        define SIZEOF_SIZE_T 1
#    elif defined(__SIZE_MAX__) && (__SIZE_MAX__ >> 14) == 3
#        define SIZEOF_SIZE_T 2
#    elif defined(__SIZE_MAX__) && (__SIZE_MAX__ >> 30) == 3
#        define SIZEOF_SIZE_T 4
#    elif defined(__SIZE_MAX__) && ((__SIZE_MAX__ >> 30) >> 30) == 15
#        define SIZEOF_SIZE_T 8
#    elif defined(__SIZE_MAX__) && ((((__SIZE_MAX__ >> 30) >> 30) >> 30) >> 30) == 255
#        define SIZEOF_SIZE_T 16
#    endif
#endif

#if !defined(SIZEOF_INTPTR_T)
#    if defined(__SIZEOF_INTPTR_T__)
#        define SIZEOF_INTPTR_T __SIZEOF_INTPTR_T__
#    elif defined(__INTPTR_WIDTH__) && (__INTPTR_WIDTH__ + 0 > 0)
#        define SIZEOF_INTPTR_T (__INTPTR_WIDTH__ / 8)
#    elif defined(__INTPTR_MAX__) && (__INTPTR_MAX__ >> 6) == 1
#        define SIZEOF_INTPTR_T 1
#    elif defined(__INTPTR_MAX__) && (__INTPTR_MAX__ >> 14) == 1
#        define SIZEOF_INTPTR_T 2
#    elif defined(__INTPTR_MAX__) && (__INTPTR_MAX__ >> 30) == 1
#        define SIZEOF_INTPTR_T 4
#    elif defined(__INTPTR_MAX__) && ((__INTPTR_MAX__ >> 30) >> 30) == 7
#        define SIZEOF_INTPTR_T 8
#    elif defined(__INTPTR_MAX__) && ((((__INTPTR_MAX__ >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_INTPTR_T 16
#    endif
#endif

#if !defined(SIZEOF_UINTPTR_T)
#    if defined(__SIZEOF_UINTPTR_T__)
#        define SIZEOF_UINTPTR_T __SIZEOF_UINTPTR_T__
#    elif defined(__UINTPTR_WIDTH__) && (__UINTPTR_WIDTH__ + 0 > 0)
#        define SIZEOF_UINTPTR_T (__UINTPTR_WIDTH__ / 8)
#    elif defined(__UINTPTR_MAX__) && (__UINTPTR_MAX__ >> 6) == 3
#        define SIZEOF_UINTPTR_T 1
#    elif defined(__UINTPTR_MAX__) && (__UINTPTR_MAX__ >> 14) == 3
#        define SIZEOF_UINTPTR_T 2
#    elif defined(__UINTPTR_MAX__) && (__UINTPTR_MAX__ >> 30) == 3
#        define SIZEOF_UINTPTR_T 4
#    elif defined(__UINTPTR_MAX__) && ((__UINTPTR_MAX__ >> 30) >> 30) == 15
#        define SIZEOF_UINTPTR_T 8
#    elif defined(__UINTPTR_MAX__) && ((((__UINTPTR_MAX__ >> 30) >> 30) >> 30) >> 30) == 255
#        define SIZEOF_UINTPTR_T 16
#    endif
#endif

#if !defined(SIZEOF_POINTER)
#    if defined(__SIZEOF_POINTER__)
#        define SIZEOF_POINTER __SIZEOF_POINTER__
#    elif defined(__UINTPTR_WIDTH__) && (__UINTPTR_WIDTH__ + 0 > 0)
#        define SIZEOF_POINTER (__UINTPTR_WIDTH__ / 8)
#    elif defined(__UINTPTR_MAX__) && (__UINTPTR_MAX__ >> 6) == 3
#        define SIZEOF_POINTER 1
#    elif defined(__UINTPTR_MAX__) && (__UINTPTR_MAX__ >> 14) == 3
#        define SIZEOF_POINTER 2
#    elif defined(__UINTPTR_MAX__) && (__UINTPTR_MAX__ >> 30) == 3
#        define SIZEOF_POINTER 4
#    elif defined(__UINTPTR_MAX__) && ((__UINTPTR_MAX__ >> 30) >> 30) == 15
#        define SIZEOF_POINTER 8
#    elif defined(__UINTPTR_MAX__) && ((((__UINTPTR_MAX__ >> 30) >> 30) >> 30) >> 30) == 255
#        define SIZEOF_POINTER 16
#    endif
#endif

#if !defined(SIZEOF_SHORT)
#    if defined(__SIZEOF_SHORT__)
#        define SIZEOF_SHORT __SIZEOF_SHORT__
#    elif defined(__SHRT_WIDTH__) && (__SHRT_WIDTH__ + 0 > 0)
#        define SIZEOF_SHORT (__SHRT_WIDTH__ / 8)
#    elif defined(SHRT_MAX) && (SHRT_MAX >> 6) == 1
#        define SIZEOF_SHORT 1
#    elif defined(SHRT_MAX) && (SHRT_MAX >> 14) == 1
#        define SIZEOF_SHORT 2
#    elif defined(SHRT_MAX) && (SHRT_MAX >> 30) == 1
#        define SIZEOF_SHORT 4
#    elif defined(SHRT_MAX) && ((SHRT_MAX >> 30) >> 30) == 7
#        define SIZEOF_SHORT 8
#    elif defined(SHRT_MAX) && ((((SHRT_MAX >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_SHORT 16
#    endif
#endif

#if !defined(SIZEOF_INT)
#    if defined(__SIZEOF_INT__)
#        define SIZEOF_INT __SIZEOF_INT__
#    elif defined(__INT_WIDTH__) && (__INT_WIDTH__ + 0 > 0)
#        define SIZEOF_INT (__INT_WIDTH__ / 8)
#    elif defined(INT_MAX) && (INT_MAX >> 6) == 1
#        define SIZEOF_INT 1
#    elif defined(INT_MAX) && (INT_MAX >> 14) == 1
#        define SIZEOF_INT 2
#    elif defined(INT_MAX) && (INT_MAX >> 30) == 1
#        define SIZEOF_INT 4
#    elif defined(INT_MAX) && ((INT_MAX >> 30) >> 30) == 7
#        define SIZEOF_INT 8
#    elif defined(INT_MAX) && ((((INT_MAX >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_INT 16
#    endif
#endif

#if !defined(SIZEOF_LONG)
#    if defined(__SIZEOF_LONG__)
#        define SIZEOF_LONG __SIZEOF_LONG__
#    elif defined(__LONG_WIDTH__) && (__LONG_WIDTH__ + 0 > 0)
#        define SIZEOF_LONG (__LONG_WIDTH__ / 8)
#    elif defined(LONG_MAX) && (LONG_MAX >> 6) == 1
#        define SIZEOF_LONG 1
#    elif defined(LONG_MAX) && (LONG_MAX >> 14) == 1
#        define SIZEOF_LONG 2
#    elif defined(LONG_MAX) && (LONG_MAX >> 30) == 1
#        define SIZEOF_LONG 4
#    elif defined(LONG_MAX) && ((LONG_MAX >> 30) >> 30) == 7
#        define SIZEOF_LONG 8
#    elif defined(LONG_MAX) && ((((LONG_MAX >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_LONG 16
#    endif
#endif

#if !defined(SIZEOF_LONG_LONG)
#    if defined(__SIZEOF_LONG_LONG__)
#        define SIZEOF_LONG_LONG __SIZEOF_LONG_LONG__
#    elif defined(__LONG_LONG_WIDTH__) && (__LONG_LONG_WIDTH__ + 0 > 0)
#        define SIZEOF_LONG_LONG (__LONG_LONG_WIDTH__ / 8)
#    elif defined(LLONG_MAX) && (LLONG_MAX >> 6) == 1
#        define SIZEOF_LONG_LONG 1
#    elif defined(LLONG_MAX) && (LLONG_MAX >> 14) == 1
#        define SIZEOF_LONG_LONG 2
#    elif defined(LLONG_MAX) && (LLONG_MAX >> 30) == 1
#        define SIZEOF_LONG_LONG 4
#    elif defined(LLONG_MAX) && ((LLONG_MAX >> 30) >> 30) == 7
#        define SIZEOF_LONG_LONG 8
#    elif defined(LLONG_MAX) && ((((LLONG_MAX >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_LONG_LONG 16
#    endif
#endif

#if !defined(SIZEOF_PTRDIFF_T)
#    if defined(__SIZEOF_PTRDIFF_T__)
#        define SIZEOF_PTRDIFF_T __SIZEOF_PTRDIFF_T__
#    elif defined(__PTRDIFF_WIDTH__) && (__PTRDIFF_WIDTH__ + 0 > 0)
#        define SIZEOF_PTRDIFF_T (__PTRDIFF_WIDTH__ / 8)
#    elif defined(PTRDIFF_MAX) && (PTRDIFF_MAX >> 6) == 1
#        define SIZEOF_PTRDIFF_T 1
#    elif defined(PTRDIFF_MAX) && (PTRDIFF_MAX >> 14) == 1
#        define SIZEOF_PTRDIFF_T 2
#    elif defined(PTRDIFF_MAX) && (PTRDIFF_MAX >> 30) == 1
#        define SIZEOF_PTRDIFF_T 4
#    elif defined(PTRDIFF_MAX) && ((PTRDIFF_MAX >> 30) >> 30) == 7
#        define SIZEOF_PTRDIFF_T 8
#    elif defined(PTRDIFF_MAX) && ((((PTRDIFF_MAX >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_PTRDIFF_T 16
#    endif
#endif

#if !defined(SIZEOF_SIZE_T)
#    if defined(__SIZEOF_SIZE_T__)
#        define SIZEOF_SIZE_T __SIZEOF_SIZE_T__
#    elif defined(__SIZE_WIDTH__) && (__SIZE_WIDTH__ + 0 > 0)
#        define SIZEOF_SIZE_T (__SIZE_WIDTH__ / 8)
#    elif defined(SIZE_MAX) && (SIZE_MAX >> 6) == 3
#        define SIZEOF_SIZE_T 1
#    elif defined(SIZE_MAX) && (SIZE_MAX >> 14) == 3
#        define SIZEOF_SIZE_T 2
#    elif defined(SIZE_MAX) && (SIZE_MAX >> 30) == 3
#        define SIZEOF_SIZE_T 4
#    elif defined(SIZE_MAX) && ((SIZE_MAX >> 30) >> 30) == 15
#        define SIZEOF_SIZE_T 8
#    elif defined(SIZE_MAX) && ((((SIZE_MAX >> 30) >> 30) >> 30) >> 30) == 255
#        define SIZEOF_SIZE_T 16
#    endif
#endif

#if !defined(SIZEOF_INTPTR_T)
#    if defined(__SIZEOF_INTPTR_T__)
#        define SIZEOF_INTPTR_T __SIZEOF_INTPTR_T__
#    elif defined(__INTPTR_WIDTH__) && (__INTPTR_WIDTH__ + 0 > 0)
#        define SIZEOF_INTPTR_T (__INTPTR_WIDTH__ / 8)
#    elif defined(INTPTR_MAX) && (INTPTR_MAX >> 6) == 1
#        define SIZEOF_INTPTR_T 1
#    elif defined(INTPTR_MAX) && (INTPTR_MAX >> 14) == 1
#        define SIZEOF_INTPTR_T 2
#    elif defined(INTPTR_MAX) && (INTPTR_MAX >> 30) == 1
#        define SIZEOF_INTPTR_T 4
#    elif defined(INTPTR_MAX) && ((INTPTR_MAX >> 30) >> 30) == 7
#        define SIZEOF_INTPTR_T 8
#    elif defined(INTPTR_MAX) && ((((INTPTR_MAX >> 30) >> 30) >> 30) >> 30) == 127
#        define SIZEOF_INTPTR_T 16
#    endif
#endif

#if !defined(SIZEOF_UINTPTR_T)
#    if defined(__SIZEOF_UINTPTR_T__)
#        define SIZEOF_UINTPTR_T __SIZEOF_UINTPTR_T__
#    elif defined(__UINTPTR_WIDTH__) && (__UINTPTR_WIDTH__ + 0 > 0)
#        define SIZEOF_UINTPTR_T (__UINTPTR_WIDTH__ / 8)
#    elif defined(UINTPTR_MAX) && (UINTPTR_MAX >> 6) == 3
#        define SIZEOF_UINTPTR_T 1
#    elif defined(UINTPTR_MAX) && (UINTPTR_MAX >> 14) == 3
#        define SIZEOF_UINTPTR_T 2
#    elif defined(UINTPTR_MAX) && (UINTPTR_MAX >> 30) == 3
#        define SIZEOF_UINTPTR_T 4
#    elif defined(UINTPTR_MAX) && ((UINTPTR_MAX >> 30) >> 30) == 15
#        define SIZEOF_UINTPTR_T 8
#    elif defined(UINTPTR_MAX) && ((((UINTPTR_MAX >> 30) >> 30) >> 30) >> 30) == 255
#        define SIZEOF_UINTPTR_T 16
#    endif
#endif

#if !defined(SIZEOF_POINTER)
#    if defined(__SIZEOF_POINTER__)
#        define SIZEOF_POINTER __SIZEOF_POINTER__
#    elif defined(__UINTPTR_WIDTH__) && (__UINTPTR_WIDTH__ + 0 > 0)
#        define SIZEOF_POINTER (__UINTPTR_WIDTH__ / 8)
#    elif defined(UINTPTR_MAX) && (UINTPTR_MAX >> 6) == 3
#        define SIZEOF_POINTER 1
#    elif defined(UINTPTR_MAX) && (UINTPTR_MAX >> 14) == 3
#        define SIZEOF_POINTER 2
#    elif defined(UINTPTR_MAX) && (UINTPTR_MAX >> 30) == 3
#        define SIZEOF_POINTER 4
#    elif defined(UINTPTR_MAX) && ((UINTPTR_MAX >> 30) >> 30) == 15
#        define SIZEOF_POINTER 8
#    elif defined(UINTPTR_MAX) && ((((UINTPTR_MAX >> 30) >> 30) >> 30) >> 30) == 255
#        define SIZEOF_POINTER 16
#    endif
#endif

#if !defined(SIZEOF_PTRDIFF_T) && defined(SIZEOF_PTRDIFF_T)
#    define SIZEOF_PTRDIFF_T SIZEOF_PTRDIFF_T
#elif !defined(SIZEOF_PTRDIFF_T) && defined(SIZEOF_SIZE_T)
#    define SIZEOF_PTRDIFF_T SIZEOF_SIZE_T
#elif !defined(SIZEOF_PTRDIFF_T) && defined(SIZEOF_INTPTR_T)
#    define SIZEOF_PTRDIFF_T SIZEOF_INTPTR_T
#elif !defined(SIZEOF_PTRDIFF_T) && defined(SIZEOF_UINTPTR_T)
#    define SIZEOF_PTRDIFF_T SIZEOF_UINTPTR_T
#elif !defined(SIZEOF_PTRDIFF_T) && defined(SIZEOF_POINTER)
#    define SIZEOF_PTRDIFF_T SIZEOF_POINTER
#endif
#if !defined(SIZEOF_SIZE_T) && defined(SIZEOF_PTRDIFF_T)
#    define SIZEOF_SIZE_T SIZEOF_PTRDIFF_T
#elif !defined(SIZEOF_SIZE_T) && defined(SIZEOF_SIZE_T)
#    define SIZEOF_SIZE_T SIZEOF_SIZE_T
#elif !defined(SIZEOF_SIZE_T) && defined(SIZEOF_INTPTR_T)
#    define SIZEOF_SIZE_T SIZEOF_INTPTR_T
#elif !defined(SIZEOF_SIZE_T) && defined(SIZEOF_UINTPTR_T)
#    define SIZEOF_SIZE_T SIZEOF_UINTPTR_T
#elif !defined(SIZEOF_SIZE_T) && defined(SIZEOF_POINTER)
#    define SIZEOF_SIZE_T SIZEOF_POINTER
#endif
#if !defined(SIZEOF_INTPTR_T) && defined(SIZEOF_PTRDIFF_T)
#    define SIZEOF_INTPTR_T SIZEOF_PTRDIFF_T
#elif !defined(SIZEOF_INTPTR_T) && defined(SIZEOF_SIZE_T)
#    define SIZEOF_INTPTR_T SIZEOF_SIZE_T
#elif !defined(SIZEOF_INTPTR_T) && defined(SIZEOF_INTPTR_T)
#    define SIZEOF_INTPTR_T SIZEOF_INTPTR_T
#elif !defined(SIZEOF_INTPTR_T) && defined(SIZEOF_UINTPTR_T)
#    define SIZEOF_INTPTR_T SIZEOF_UINTPTR_T
#elif !defined(SIZEOF_INTPTR_T) && defined(SIZEOF_POINTER)
#    define SIZEOF_INTPTR_T SIZEOF_POINTER
#endif
#if !defined(SIZEOF_UINTPTR_T) && defined(SIZEOF_PTRDIFF_T)
#    define SIZEOF_UINTPTR_T SIZEOF_PTRDIFF_T
#elif !defined(SIZEOF_UINTPTR_T) && defined(SIZEOF_SIZE_T)
#    define SIZEOF_UINTPTR_T SIZEOF_SIZE_T
#elif !defined(SIZEOF_UINTPTR_T) && defined(SIZEOF_INTPTR_T)
#    define SIZEOF_UINTPTR_T SIZEOF_INTPTR_T
#elif !defined(SIZEOF_UINTPTR_T) && defined(SIZEOF_UINTPTR_T)
#    define SIZEOF_UINTPTR_T SIZEOF_UINTPTR_T
#elif !defined(SIZEOF_UINTPTR_T) && defined(SIZEOF_POINTER)
#    define SIZEOF_UINTPTR_T SIZEOF_POINTER
#endif
#if !defined(SIZEOF_POINTER) && defined(SIZEOF_PTRDIFF_T)
#    define SIZEOF_POINTER SIZEOF_PTRDIFF_T
#elif !defined(SIZEOF_POINTER) && defined(SIZEOF_SIZE_T)
#    define SIZEOF_POINTER SIZEOF_SIZE_T
#elif !defined(SIZEOF_POINTER) && defined(SIZEOF_INTPTR_T)
#    define SIZEOF_POINTER SIZEOF_INTPTR_T
#elif !defined(SIZEOF_POINTER) && defined(SIZEOF_UINTPTR_T)
#    define SIZEOF_POINTER SIZEOF_UINTPTR_T
#elif !defined(SIZEOF_POINTER) && defined(SIZEOF_POINTER)
#    define SIZEOF_POINTER SIZEOF_POINTER
#endif

#if !defined(SIZEOF_SHORT) || !(SIZEOF_SHORT + 0 > 0)
#    error "missing SIZEOF_SHORT"
#endif
#if !defined(SIZEOF_INT) || !(SIZEOF_INT + 0 > 0)
#    error "missing SIZEOF_INT"
#endif
#if !defined(SIZEOF_LONG) || !(SIZEOF_LONG + 0 > 0)
#    error "missing SIZEOF_LONG"
#endif
#if !defined(SIZEOF_LONG_LONG) || !(SIZEOF_LONG_LONG + 0 > 0)
#    error "missing SIZEOF_LONG_LONG"
#endif
#if !defined(SIZEOF_PTRDIFF_T) || !(SIZEOF_PTRDIFF_T + 0 > 0)
#    error "missing SIZEOF_PTRDIFF_T"
#endif
#if !defined(SIZEOF_SIZE_T) || !(SIZEOF_SIZE_T + 0 > 0)
#    error "missing SIZEOF_SIZE_T"
#endif
#if !defined(SIZEOF_INTPTR_T) || !(SIZEOF_INTPTR_T + 0 > 0)
#    error "missing SIZEOF_INTPTR_T"
#endif
#if !defined(SIZEOF_UINTPTR_T) || !(SIZEOF_UINTPTR_T + 0 > 0)
#    error "missing SIZEOF_UINTPTR_T"
#endif
#if !defined(SIZEOF_POINTER) || !(SIZEOF_POINTER + 0 > 0)
#    error "missing SIZEOF_POINTER"
#endif
