/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

#if defined(_MSC_VER) && !defined(__clang__)
#    pragma warning(push)
// W1: 'signature' : incorrect return type for intrinsic function, expected 'type'
#    pragma warning(disable : 4391)
// W4: 'x' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
#    pragma warning(disable : 4668)

#    include <intrin.h>

#    pragma warning(pop)
#endif
