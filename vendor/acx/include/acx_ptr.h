/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

#pragma once

#if defined(__PTRADDR_T__)
typedef __PTRADDR_T__ acx_ptraddr_t;
#elif defined(ACX_CONFIG_USE_UINTPTR_T) && ACX_CONFIG_USE_UINTPTR_T // PP_BOOL
typedef uintptr_t acx_ptraddr_t;
#else
typedef size_t acx_ptraddr_t;
#endif
ct_assert(((acx_ptraddr_t) 0 - (acx_ptraddr_t) 1) > 0); // must be an unsigned integral
ct_assert(sizeof(acx_ptraddr_t) >=
          sizeof(size_t)); // not required, but does not make sense otherwise

#if defined(__CHERI__) && defined(__CHERI_PURE_CAPABILITY__)
finline acx_ptraddr_t ptr_get_address(const void *p) no_except {
    return __builtin_cheri_address_get(p);
}
#elif defined(ACX_CONFIG_USE_UINTPTR_T) && ACX_CONFIG_USE_UINTPTR_T // PP_BOOL
finline acx_ptraddr_t ptr_get_address(const void *p) no_except {
    return (acx_ptraddr_t) (uintptr_t) p;
}
#else
finline acx_ptraddr_t ptr_get_address(const void *p) no_except { return (acx_ptraddr_t) p; }
#endif

finline bool ptr_is_aligned(const void *p, word alignment) no_except {
    return (ptr_get_address(p) & (alignment - 1)) == 0;
}

finline word ptr_align_down_gap(const void *p, word alignment) no_except {
    return (word) ptr_get_address(p) & (alignment - 1);
}
finline word ptr_align_up_gap(const void *p, word alignment) no_except {
    return ((word) 0 - (word) ptr_get_address(p)) & (alignment - 1);
}

/*************************************************************************
// ptr_align_down
**************************************************************************/

finline void *ptr_align_down_vp(void *p, word alignment) no_except {
    const word n = ptr_align_down_gap(p, alignment);
    return (void *) ((char *) p - n);
}

finline const void *ptr_align_down_vc(const void *p, word alignment) no_except {
    const word n = ptr_align_down_gap(p, alignment);
    return (const void *) ((const char *) p - n);
}

finline char *ptr_align_down_cp(char *p, word alignment) no_except {
    const word n = ptr_align_down_gap(p, alignment);
    return p - n;
}

finline const char *ptr_align_down_cc(const char *p, word alignment) no_except {
    const word n = ptr_align_down_gap(p, alignment);
    return p - n;
}

finline byte *ptr_align_down_bp(byte *p, word alignment) no_except {
    const word n = ptr_align_down_gap(p, alignment);
    return p - n;
}

finline const byte *ptr_align_down_bc(const byte *p, word alignment) no_except {
    const word n = ptr_align_down_gap(p, alignment);
    return p - n;
}

/*************************************************************************
// ptr_align_up
**************************************************************************/

finline void *ptr_align_up_vp(void *p, word alignment) no_except {
    const word n = ptr_align_up_gap(p, alignment);
    return (void *) ((char *) p + n);
}

finline const void *ptr_align_up_vc(const void *p, word alignment) no_except {
    const word n = ptr_align_up_gap(p, alignment);
    return (const void *) ((const char *) p + n);
}

finline char *ptr_align_up_cp(char *p, word alignment) no_except {
    const word n = ptr_align_up_gap(p, alignment);
    return p + n;
}

finline const char *ptr_align_up_cc(const char *p, word alignment) no_except {
    const word n = ptr_align_up_gap(p, alignment);
    return p + n;
}

finline byte *ptr_align_up_bp(byte *p, word alignment) no_except {
    const word n = ptr_align_up_gap(p, alignment);
    return p + n;
}

finline const byte *ptr_align_up_bc(const byte *p, word alignment) no_except {
    const word n = ptr_align_up_gap(p, alignment);
    return p + n;
}
