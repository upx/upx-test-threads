#pragma once

EXTERN_C_BEGIN

typedef struct {
    void *data[16];
} NakedData;

#if (defined(__GNUC__) && !defined(__clang__)) &&                                                  \
    (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 3))
#    define CODEGEN_NAKED_ALIGN_FUNC /*empty*/
#elif defined(__i386__) && defined(__MSDOS__) && defined(__DJGPP__) && defined(__GNUC__)
#    define CODEGEN_NAKED_ALIGN_FUNC __attribute__((__aligned__(16))) // max alignment 16
#elif defined(__m68k__) && defined(__atarist__) && defined(__GNUC__)
#    define CODEGEN_NAKED_ALIGN_FUNC __attribute__((__aligned__(2))) // max alignment 2 ???
#elif defined(__clang__) || defined(__GNUC__)
#    define CODEGEN_NAKED_ALIGN_FUNC __attribute__((__aligned__(64)))
#else
// TODO: MSVC
#    define CODEGEN_NAKED_ALIGN_FUNC /*empty*/
#endif

#if defined(__wasi__)
#    define CODEGEN_NAKED_INSTRUCTIONS ""
#elif defined(__arm__)
#    define CODEGEN_NAKED_INSTRUCTIONS ".word 0xe12fff1e" // bx lr
#else
#    define CODEGEN_NAKED_INSTRUCTIONS ".byte 1,2,3,4"
#endif

no_inline CODEGEN_NAKED_ALIGN_FUNC void test_codegen_attribute_not_naked(NakedData *d) no_except {
    (void) d;
#if defined(__clang__) || defined(__GNUC__)
    __asm__ __volatile__(CODEGEN_NAKED_INSTRUCTIONS ::: "cc", "memory");
#endif
}

#if defined(__clang__) ||                                                                          \
    (defined(__GNUC__) && __GNUC__ >= 8 && (defined(__i386__) || defined(__x86_64__)))
no_inline CODEGEN_NAKED_ALIGN_FUNC __attribute__((__naked__)) void
test_codegen_attribute_naked(NakedData *d __attribute__((__unused__))) no_except {

    __asm__ __volatile__(CODEGEN_NAKED_INSTRUCTIONS ::: "cc", "memory");

    // IMPORTANT: gcc on amd64 adds a "ud2" __builtin_trap() here!!
}
#endif

EXTERN_C_END
