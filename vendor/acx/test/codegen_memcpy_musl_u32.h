no_inline byte *test_codegen_memcpy_musl_part1(byte *d, const byte *s, size_t n) no_except {
    for (; (ptr_get_address(s) & 3) && n; n--)
        *d++ = *s++;
    return d;
}

#if defined(__clang__)
#    pragma clang diagnostic push
#    pragma clang diagnostic ignored "-Wcast-align"
#elif defined(__GNUC__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wcast-align"
#endif

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
no_inline void *test_codegen_memcpy_musl_u32(void *dest, const void *src, size_t n) no_except {

#if (defined(__clang__) || defined(__GNUC__)) && defined(__BYTE_ORDER__)
    unsigned char *__restrict__ d = (unsigned char *) dest;
    const unsigned char *__restrict__ s = (const unsigned char *) src;

#    if __BYTE_ORDER__ == 4321
#        define LS <<
#        define RS >>
#    elif __BYTE_ORDER__ == 1234
#        define LS >>
#        define RS <<
#    endif

    typedef u32 copy_unit;
    typedef copy_unit __attribute__((__may_alias__)) * DPtr;
    typedef const copy_unit __attribute__((__may_alias__)) * SPtr;
    copy_unit w, x;

    for (; (ptr_get_address(s) & 3) && n; n--)
        *d++ = *s++;

    if ((ptr_get_address(d) & 3) == 0) {
        for (; n >= 16; s += 16, d += 16, n -= 16) {
            *(DPtr) (d + 0) = *(SPtr) (s + 0);
            *(DPtr) (d + 4) = *(SPtr) (s + 4);
            *(DPtr) (d + 8) = *(SPtr) (s + 8);
            *(DPtr) (d + 12) = *(SPtr) (s + 12);
        }
        if (n & 8) {
            *(DPtr) (d + 0) = *(SPtr) (s + 0);
            *(DPtr) (d + 4) = *(SPtr) (s + 4);
            d += 8;
            s += 8;
        }
        if (n & 4) {
            *(DPtr) (d + 0) = *(SPtr) (s + 0);
            d += 4;
            s += 4;
        }
        if (n & 2) {
            *d++ = *s++;
            *d++ = *s++;
        }
        if (n & 1) {
            *d = *s;
        }
        return dest;
    }

    if (n >= 32) {
        switch (ptr_get_address(d) & 3) {
        case 1:
            w = *(SPtr) s;
            *d++ = *s++;
            *d++ = *s++;
            *d++ = *s++;
            n -= 3;
            for (; n >= 17; s += 16, d += 16, n -= 16) {
                x = *(SPtr) (s + 1);
                *(DPtr) (d + 0) = (w LS 24) | (x RS 8);
                w = *(SPtr) (s + 5);
                *(DPtr) (d + 4) = (x LS 24) | (w RS 8);
                x = *(SPtr) (s + 9);
                *(DPtr) (d + 8) = (w LS 24) | (x RS 8);
                w = *(SPtr) (s + 13);
                *(DPtr) (d + 12) = (x LS 24) | (w RS 8);
            }
            break;
        case 2:
            w = *(SPtr) s;
            *d++ = *s++;
            *d++ = *s++;
            n -= 2;
            for (; n >= 18; s += 16, d += 16, n -= 16) {
                x = *(SPtr) (s + 2);
                *(DPtr) (d + 0) = (w LS 16) | (x RS 16);
                w = *(SPtr) (s + 6);
                *(DPtr) (d + 4) = (x LS 16) | (w RS 16);
                x = *(SPtr) (s + 10);
                *(DPtr) (d + 8) = (w LS 16) | (x RS 16);
                w = *(SPtr) (s + 14);
                *(DPtr) (d + 12) = (x LS 16) | (w RS 16);
            }
            break;
        case 3:
            w = *(SPtr) s;
            *d++ = *s++;
            n -= 1;
            for (; n >= 19; s += 16, d += 16, n -= 16) {
                x = *(SPtr) (s + 3);
                *(DPtr) (d + 0) = (w LS 8) | (x RS 24);
                w = *(SPtr) (s + 7);
                *(DPtr) (d + 4) = (x LS 8) | (w RS 24);
                x = *(SPtr) (s + 11);
                *(DPtr) (d + 8) = (w LS 8) | (x RS 24);
                w = *(SPtr) (s + 15);
                *(DPtr) (d + 12) = (x LS 8) | (w RS 24);
            }
            break;
        default: // unreachable, already handled above
            break;
        }
    }
    // now n <= 18
    if (n & 16) {
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
    }
    if (n & 8) {
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
    }
    if (n & 4) {
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
        *d++ = *s++;
    }
    if (n & 2) {
        *d++ = *s++;
        *d++ = *s++;
    }
    if (n & 1) {
        *d = *s;
    }
    return dest;
#    undef LS
#    undef RS

#else
    unsigned char *d = (unsigned char *) dest;
    const unsigned char *s = (const unsigned char *) src;
    for (; n; n--)
        *d++ = *s++;
    return dest;
#endif
}

#if defined(__clang__)
#    pragma clang diagnostic pop
#elif defined(__GNUC__)
#    pragma GCC diagnostic pop
#endif
