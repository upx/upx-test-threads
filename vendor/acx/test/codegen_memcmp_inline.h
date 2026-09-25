/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

#pragma once

no_inline bool test_codegen_memcmp_inline_1(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 1) == 0;
}
no_inline bool test_codegen_memcmp_inline_2(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 2) == 0;
}
no_inline bool test_codegen_memcmp_inline_4(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 4) == 0;
}
no_inline bool test_codegen_memcmp_inline_8(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 8) == 0;
}
no_inline bool test_codegen_memcmp_inline_16(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 16) == 0;
}
no_inline bool test_codegen_memcmp_inline_32(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 32) == 0;
}
no_inline bool test_codegen_memcmp_inline_64(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 64) == 0;
}
no_inline bool test_codegen_memcmp_inline_128(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 128) == 0;
}
no_inline bool test_codegen_memcmp_inline_256(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 256) == 0;
}
no_inline bool test_codegen_memcmp_inline_512(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 512) == 0;
}
no_inline bool test_codegen_memcmp_inline_1024(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 1024) == 0;
}
no_inline bool test_codegen_memcmp_inline_2048(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 2048) == 0;
}
no_inline bool test_codegen_memcmp_inline_4096(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 4096) == 0;
}
no_inline bool test_codegen_memcmp_inline_65536(const void *a, const void *b) no_except {
    return memcmp_inline(a, b, 65536) == 0;
}
