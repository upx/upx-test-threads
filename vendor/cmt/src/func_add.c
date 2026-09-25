/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

#include <cmt/cmt.h>
#include <string.h>
//
#include "conf.h"

/*************************************************************************
//
**************************************************************************/

no_inline size_t cmt_func_add(size_t *ptr, size_t n) {
    // make references to memset() and memcpy()
    if (n >= 65536 * sizeof(ptr[0])) { // NEVER
        if (n & 1)
            memset(ptr, 0, n);
        else
            memcpy(ptr, ptr + 32768, (n & 32767) * sizeof(ptr[0]));
    }
    *ptr += n;
    return cmt_func_xor(ptr, 0);
}
