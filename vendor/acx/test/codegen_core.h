/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

#pragma once

no_inline byte codegen_no_barrier(byte *p) no_except {
    *p = 0;
    return *p;
}
no_inline byte codegen_compiler_barrier(byte *p) no_except {
    *p = 0;
    compiler_barrier();
    return *p;
}

no_inline byte *codegen_ptr_add_word(byte *p, word n) no_except { return p + n; }
no_inline byte *codegen_ptr_sub_word(byte *p, word n) no_except { return p - n; }
no_inline byte *codegen_ptr_add_sword(byte *p, sword n) no_except { return p + n; }
no_inline byte *codegen_ptr_sub_sword(byte *p, sword n) no_except { return p - n; }
no_inline byte *codegen_ptr_add_1(byte *p) no_except { return p + 1; }
no_inline byte *codegen_ptr_sub_1(byte *p) no_except { return p - 1; }

no_inline word codegen_word_add_word(word a, word b) no_except { return a + b; }
no_inline word codegen_word_sub_word(word a, word b) no_except { return a - b; }
no_inline word codegen_word_add_sword(word a, sword b) no_except { return a + b; }
no_inline word codegen_word_sub_sword(word a, sword b) no_except { return a - b; }
no_inline word codegen_word_add_1(word a) no_except { return a + 1; }
no_inline word codegen_word_sub_1(word a) no_except { return a - 1; }

no_inline bool codegen_ptr_is_aligned(const void *p, word alignment) no_except {
    return ptr_is_aligned(p, alignment);
}
no_inline void *codegen_ptr_align_down_vp(void *p, word alignment) no_except {
    return ptr_align_down_vp(p, alignment);
}
no_inline void *codegen_ptr_align_up_vp(void *p, word alignment) no_except {
    return ptr_align_up_vp(p, alignment);
}

no_inline bool codegen_ptr_is_aligned_1(const void *p) no_except { return ptr_is_aligned(p, 1); }
no_inline bool codegen_ptr_is_aligned_2(const void *p) no_except { return ptr_is_aligned(p, 2); }
no_inline bool codegen_ptr_is_aligned_4(const void *p) no_except { return ptr_is_aligned(p, 4); }
no_inline bool codegen_ptr_is_aligned_8(const void *p) no_except { return ptr_is_aligned(p, 8); }
no_inline bool codegen_ptr_is_aligned_16(const void *p) no_except { return ptr_is_aligned(p, 16); }
no_inline bool codegen_ptr_is_aligned_32(const void *p) no_except { return ptr_is_aligned(p, 32); }
no_inline bool codegen_ptr_is_aligned_64(const void *p) no_except { return ptr_is_aligned(p, 64); }

no_inline byte *codegen_ptr_align_down_1(byte *p) no_except { return ptr_align_down_bp(p, 1); }
no_inline byte *codegen_ptr_align_down_2(byte *p) no_except { return ptr_align_down_bp(p, 2); }
no_inline byte *codegen_ptr_align_down_4(byte *p) no_except { return ptr_align_down_bp(p, 4); }
no_inline byte *codegen_ptr_align_down_8(byte *p) no_except { return ptr_align_down_bp(p, 8); }
no_inline byte *codegen_ptr_align_down_16(byte *p) no_except { return ptr_align_down_bp(p, 16); }
no_inline byte *codegen_ptr_align_down_32(byte *p) no_except { return ptr_align_down_bp(p, 32); }
no_inline byte *codegen_ptr_align_down_64(byte *p) no_except { return ptr_align_down_bp(p, 64); }

no_inline byte *codegen_ptr_align_up_1(byte *p) no_except { return ptr_align_up_bp(p, 1); }
no_inline byte *codegen_ptr_align_up_2(byte *p) no_except { return ptr_align_up_bp(p, 2); }
no_inline byte *codegen_ptr_align_up_4(byte *p) no_except { return ptr_align_up_bp(p, 4); }
no_inline byte *codegen_ptr_align_up_8(byte *p) no_except { return ptr_align_up_bp(p, 8); }
no_inline byte *codegen_ptr_align_up_16(byte *p) no_except { return ptr_align_up_bp(p, 16); }
no_inline byte *codegen_ptr_align_up_32(byte *p) no_except { return ptr_align_up_bp(p, 32); }
no_inline byte *codegen_ptr_align_up_64(byte *p) no_except { return ptr_align_up_bp(p, 64); }

no_inline word codegen_load_u8(const u8 *p, word off) no_except { return p[off]; }
no_inline word codegen_load_u16(const u16 *p, word off) no_except { return p[off]; }
no_inline word codegen_load_u32(const u32 *p, word off) no_except { return p[off]; }
no_inline word64 codegen_load_u64(const u64 *p, word off) no_except { return p[off]; }
no_inline word codegen_load_word(const word *p, word off) no_except { return p[off]; }
no_inline word64 codegen_load_word64(const word64 *p, word off) no_except { return p[off]; }
no_inline size_t codegen_load_size_t(const size_t *p, size_t off) no_except { return p[off]; }

no_inline void codegen_store_u8(u8 *p, word off, word v) no_except { p[off] = (u8) v; }
no_inline void codegen_store_u16(u16 *p, word off, word v) no_except { p[off] = (u16) v; }
no_inline void codegen_store_u32(u32 *p, word off, word v) no_except { p[off] = (u32) v; }
no_inline void codegen_store_u64(u64 *p, word off, word64 v) no_except { p[off] = (u64) v; }
no_inline void codegen_store_word(word *p, word off, word v) no_except { p[off] = v; }
no_inline void codegen_store_word64(word64 *p, word off, word64 v) no_except { p[off] = v; }
no_inline void codegen_store_size_t(size_t *p, size_t off, size_t v) no_except { p[off] = v; }
