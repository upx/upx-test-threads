/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

#include <cmt/cmt_no_exceptions.h>
//
#include <cmt/cmt.h>
#undef NDEBUG
#include <assert.h>
#include <stdio.h>

/*************************************************************************
//
**************************************************************************/

int main(void) {
    size_t v = 0;
    size_t r;
    r = cmt_func_add(&v, 4);
    assert(r == 4 && v == 4);
    r = cmt_func_sub(&v, 3);
    assert(r == 1 && v == 1);
    printf("CMT test passed.\n");
    return 0;
}
