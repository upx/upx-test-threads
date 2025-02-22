/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

#include <cmt/cmt.h>
//
#include "conf.h"

/*************************************************************************
//
**************************************************************************/

no_inline size_t cmt_func_xor(size_t *ptr, size_t n) {
    *ptr ^= n;
    return cmt::func_return(cmt_func_and(ptr, *ptr));
}
