/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

#pragma once

no_inline void test_codegen_memcpy_inline_1(void *d, const void *s) no_except {
    memcpy_inline(d, s, 1);
}
no_inline void test_codegen_memcpy_inline_2(void *d, const void *s) no_except {
    memcpy_inline(d, s, 2);
}
no_inline void test_codegen_memcpy_inline_4(void *d, const void *s) no_except {
    memcpy_inline(d, s, 4);
}
no_inline void test_codegen_memcpy_inline_8(void *d, const void *s) no_except {
    memcpy_inline(d, s, 8);
}
no_inline void test_codegen_memcpy_inline_16(void *d, const void *s) no_except {
    memcpy_inline(d, s, 16);
}
no_inline void test_codegen_memcpy_inline_32(void *d, const void *s) no_except {
    memcpy_inline(d, s, 32);
}
no_inline void test_codegen_memcpy_inline_64(void *d, const void *s) no_except {
    memcpy_inline(d, s, 64);
}
no_inline void test_codegen_memcpy_inline_128(void *d, const void *s) no_except {
    memcpy_inline(d, s, 128);
}
no_inline void test_codegen_memcpy_inline_256(void *d, const void *s) no_except {
    memcpy_inline(d, s, 256);
}
no_inline void test_codegen_memcpy_inline_512(void *d, const void *s) no_except {
    memcpy_inline(d, s, 512);
}
no_inline void test_codegen_memcpy_inline_1024(void *d, const void *s) no_except {
    memcpy_inline(d, s, 1024);
}
no_inline void test_codegen_memcpy_inline_2048(void *d, const void *s) no_except {
    memcpy_inline(d, s, 2048);
}
no_inline void test_codegen_memcpy_inline_4096(void *d, const void *s) no_except {
    memcpy_inline(d, s, 4096);
}
no_inline void test_codegen_memcpy_inline_65536(void *d, const void *s) no_except {
    memcpy_inline(d, s, 65536);
}
