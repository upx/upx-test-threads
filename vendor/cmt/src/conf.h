/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

#pragma once

#include <cmt/cmt_no_exceptions.h>

/*************************************************************************
//
**************************************************************************/

#if !defined(__has_attribute)
#    define __has_attribute(x) 0
#endif

#if defined(__GNUC__) && ((__GNUC__ >= 8) || __has_attribute(__noipa__))
#    define no_inline __attribute__((__noinline__, __noipa__))
#elif defined(__GNUC__) && (__GNUC__ >= 5)
#    define no_inline __attribute__((__noinline__, __noclone__, __no_icf__))
#elif defined(__clang__) || defined(__GNUC__)
#    define no_inline __attribute__((__noinline__))
#elif defined(_MSC_VER)
#    define no_inline __declspec(noinline)
#else
#    define no_inline /*empty*/
#endif

/*************************************************************************
// create some templates to check DLL export and WINDOWS_EXPORT_ALL_SYMBOLS
**************************************************************************/

#if defined(__cplusplus)

namespace cmt {

template <class T> struct Returner {
    static no_inline T static_func_return(T x) { return x; }
    no_inline T func_return(T x) { return static_func_return(x); }
};
template <class T> no_inline T func_return(T x) {
    Returner<T> r;
    return r.func_return(x);
}

} // namespace cmt

#endif // __cplusplus
