/// DO NOT EDIT, GENERATED AUTOMATICALLY.
/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

// ua2/ua4/ua8 == copy unit
// v1 == 1 variable
// v2 == 2 variables
// rlt == repeat while less
// rne == repeat while not-equal
// wlt == while less
// wne == while not-equal

// ('ua1', '1', 'UA_GET1', 'UA_SET1', 'word')
no_inline byte *test_codegen_copy_ua1_v1_rlt(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET1(src);
        UA_SET1(dst, w0);
        src += 1 * 1;
        dst += 1 * 1;
    } while (dst < end);
    return dst;
}

no_inline byte *test_codegen_copy_ua1_v1_rne(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET1(src);
        UA_SET1(dst, w0);
        src += 1 * 1;
        dst += 1 * 1;
    } while (dst != end);
    return dst;
}

no_inline byte *test_codegen_copy_ua1_v1_wlt(byte *dst, byte *end, const byte *src) no_except {
    while (dst < end) {
        word w0 = UA_GET1(src);
        UA_SET1(dst, w0);
        src += 1 * 1;
        dst += 1 * 1;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua1_v1_wne(byte *dst, byte *end, const byte *src) no_except {
    while (dst != end) {
        word w0 = UA_GET1(src);
        UA_SET1(dst, w0);
        src += 1 * 1;
        dst += 1 * 1;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua1_v2_rlt(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET1(src);
        word w1 = UA_GET1(src + 1 * 1);
        UA_SET1(dst, w0);
        UA_SET1(dst + 1 * 1, w1);
        src += 2 * 1;
        dst += 2 * 1;
    } while (dst < end);
    return dst;
}

no_inline byte *test_codegen_copy_ua1_v2_rne(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET1(src);
        word w1 = UA_GET1(src + 1 * 1);
        UA_SET1(dst, w0);
        UA_SET1(dst + 1 * 1, w1);
        src += 2 * 1;
        dst += 2 * 1;
    } while (dst != end);
    return dst;
}

no_inline byte *test_codegen_copy_ua1_v2_wlt(byte *dst, byte *end, const byte *src) no_except {
    while (dst < end) {
        word w0 = UA_GET1(src);
        word w1 = UA_GET1(src + 1 * 1);
        UA_SET1(dst, w0);
        UA_SET1(dst + 1 * 1, w1);
        src += 2 * 1;
        dst += 2 * 1;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua1_v2_wne(byte *dst, byte *end, const byte *src) no_except {
    while (dst != end) {
        word w0 = UA_GET1(src);
        word w1 = UA_GET1(src + 1 * 1);
        UA_SET1(dst, w0);
        UA_SET1(dst + 1 * 1, w1);
        src += 2 * 1;
        dst += 2 * 1;
    }
    return dst;
}

// ('ua2', '2', 'UA_GET2', 'UA_SET2', 'word')
no_inline byte *test_codegen_copy_ua2_v1_rlt(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET2(src);
        UA_SET2(dst, w0);
        src += 1 * 2;
        dst += 1 * 2;
    } while (dst < end);
    return dst;
}

no_inline byte *test_codegen_copy_ua2_v1_rne(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET2(src);
        UA_SET2(dst, w0);
        src += 1 * 2;
        dst += 1 * 2;
    } while (dst != end);
    return dst;
}

no_inline byte *test_codegen_copy_ua2_v1_wlt(byte *dst, byte *end, const byte *src) no_except {
    while (dst < end) {
        word w0 = UA_GET2(src);
        UA_SET2(dst, w0);
        src += 1 * 2;
        dst += 1 * 2;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua2_v1_wne(byte *dst, byte *end, const byte *src) no_except {
    while (dst != end) {
        word w0 = UA_GET2(src);
        UA_SET2(dst, w0);
        src += 1 * 2;
        dst += 1 * 2;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua2_v2_rlt(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET2(src);
        word w1 = UA_GET2(src + 1 * 2);
        UA_SET2(dst, w0);
        UA_SET2(dst + 1 * 2, w1);
        src += 2 * 2;
        dst += 2 * 2;
    } while (dst < end);
    return dst;
}

no_inline byte *test_codegen_copy_ua2_v2_rne(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET2(src);
        word w1 = UA_GET2(src + 1 * 2);
        UA_SET2(dst, w0);
        UA_SET2(dst + 1 * 2, w1);
        src += 2 * 2;
        dst += 2 * 2;
    } while (dst != end);
    return dst;
}

no_inline byte *test_codegen_copy_ua2_v2_wlt(byte *dst, byte *end, const byte *src) no_except {
    while (dst < end) {
        word w0 = UA_GET2(src);
        word w1 = UA_GET2(src + 1 * 2);
        UA_SET2(dst, w0);
        UA_SET2(dst + 1 * 2, w1);
        src += 2 * 2;
        dst += 2 * 2;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua2_v2_wne(byte *dst, byte *end, const byte *src) no_except {
    while (dst != end) {
        word w0 = UA_GET2(src);
        word w1 = UA_GET2(src + 1 * 2);
        UA_SET2(dst, w0);
        UA_SET2(dst + 1 * 2, w1);
        src += 2 * 2;
        dst += 2 * 2;
    }
    return dst;
}

// ('ua4', '4', 'UA_GET4', 'UA_SET4', 'word')
no_inline byte *test_codegen_copy_ua4_v1_rlt(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET4(src);
        UA_SET4(dst, w0);
        src += 1 * 4;
        dst += 1 * 4;
    } while (dst < end);
    return dst;
}

no_inline byte *test_codegen_copy_ua4_v1_rne(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET4(src);
        UA_SET4(dst, w0);
        src += 1 * 4;
        dst += 1 * 4;
    } while (dst != end);
    return dst;
}

no_inline byte *test_codegen_copy_ua4_v1_wlt(byte *dst, byte *end, const byte *src) no_except {
    while (dst < end) {
        word w0 = UA_GET4(src);
        UA_SET4(dst, w0);
        src += 1 * 4;
        dst += 1 * 4;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua4_v1_wne(byte *dst, byte *end, const byte *src) no_except {
    while (dst != end) {
        word w0 = UA_GET4(src);
        UA_SET4(dst, w0);
        src += 1 * 4;
        dst += 1 * 4;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua4_v2_rlt(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET4(src);
        word w1 = UA_GET4(src + 1 * 4);
        UA_SET4(dst, w0);
        UA_SET4(dst + 1 * 4, w1);
        src += 2 * 4;
        dst += 2 * 4;
    } while (dst < end);
    return dst;
}

no_inline byte *test_codegen_copy_ua4_v2_rne(byte *dst, byte *end, const byte *src) no_except {
    do {
        word w0 = UA_GET4(src);
        word w1 = UA_GET4(src + 1 * 4);
        UA_SET4(dst, w0);
        UA_SET4(dst + 1 * 4, w1);
        src += 2 * 4;
        dst += 2 * 4;
    } while (dst != end);
    return dst;
}

no_inline byte *test_codegen_copy_ua4_v2_wlt(byte *dst, byte *end, const byte *src) no_except {
    while (dst < end) {
        word w0 = UA_GET4(src);
        word w1 = UA_GET4(src + 1 * 4);
        UA_SET4(dst, w0);
        UA_SET4(dst + 1 * 4, w1);
        src += 2 * 4;
        dst += 2 * 4;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua4_v2_wne(byte *dst, byte *end, const byte *src) no_except {
    while (dst != end) {
        word w0 = UA_GET4(src);
        word w1 = UA_GET4(src + 1 * 4);
        UA_SET4(dst, w0);
        UA_SET4(dst + 1 * 4, w1);
        src += 2 * 4;
        dst += 2 * 4;
    }
    return dst;
}

// ('ua8', '8', 'UA_GET8', 'UA_SET8', 'word64')
no_inline byte *test_codegen_copy_ua8_v1_rlt(byte *dst, byte *end, const byte *src) no_except {
    do {
        word64 w0 = UA_GET8(src);
        UA_SET8(dst, w0);
        src += 1 * 8;
        dst += 1 * 8;
    } while (dst < end);
    return dst;
}

no_inline byte *test_codegen_copy_ua8_v1_rne(byte *dst, byte *end, const byte *src) no_except {
    do {
        word64 w0 = UA_GET8(src);
        UA_SET8(dst, w0);
        src += 1 * 8;
        dst += 1 * 8;
    } while (dst != end);
    return dst;
}

no_inline byte *test_codegen_copy_ua8_v1_wlt(byte *dst, byte *end, const byte *src) no_except {
    while (dst < end) {
        word64 w0 = UA_GET8(src);
        UA_SET8(dst, w0);
        src += 1 * 8;
        dst += 1 * 8;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua8_v1_wne(byte *dst, byte *end, const byte *src) no_except {
    while (dst != end) {
        word64 w0 = UA_GET8(src);
        UA_SET8(dst, w0);
        src += 1 * 8;
        dst += 1 * 8;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua8_v2_rlt(byte *dst, byte *end, const byte *src) no_except {
    do {
        word64 w0 = UA_GET8(src);
        word64 w1 = UA_GET8(src + 1 * 8);
        UA_SET8(dst, w0);
        UA_SET8(dst + 1 * 8, w1);
        src += 2 * 8;
        dst += 2 * 8;
    } while (dst < end);
    return dst;
}

no_inline byte *test_codegen_copy_ua8_v2_rne(byte *dst, byte *end, const byte *src) no_except {
    do {
        word64 w0 = UA_GET8(src);
        word64 w1 = UA_GET8(src + 1 * 8);
        UA_SET8(dst, w0);
        UA_SET8(dst + 1 * 8, w1);
        src += 2 * 8;
        dst += 2 * 8;
    } while (dst != end);
    return dst;
}

no_inline byte *test_codegen_copy_ua8_v2_wlt(byte *dst, byte *end, const byte *src) no_except {
    while (dst < end) {
        word64 w0 = UA_GET8(src);
        word64 w1 = UA_GET8(src + 1 * 8);
        UA_SET8(dst, w0);
        UA_SET8(dst + 1 * 8, w1);
        src += 2 * 8;
        dst += 2 * 8;
    }
    return dst;
}

no_inline byte *test_codegen_copy_ua8_v2_wne(byte *dst, byte *end, const byte *src) no_except {
    while (dst != end) {
        word64 w0 = UA_GET8(src);
        word64 w1 = UA_GET8(src + 1 * 8);
        UA_SET8(dst, w0);
        UA_SET8(dst + 1 * 8, w1);
        src += 2 * 8;
        dst += 2 * 8;
    }
    return dst;
}
