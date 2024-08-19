#if !defined(__cplusplus)
#error "missing __cplusplus"
#endif

#if !defined(LZO_CONFIG_ALLOW_EXCEPTIONS) || !(LZO_CONFIG_ALLOW_EXCEPTIONS)
#if defined(__has_feature)
#if __has_feature(cxx_exceptions)
#error "unexpected feature cxx_exceptions"
#endif
#endif
#if defined(__cpp_exceptions)
#error "unexpected __cpp_exceptions"
#endif
#if defined(_CPPUNWIND)
#error "unexpected _CPPUNWIND"
#endif
#if defined(__EXCEPTIONS)
#error "unexpected __EXCEPTIONS"
#endif
#endif // LZO_CONFIG_ALLOW_EXCEPTIONS

#if !defined(LZO_CONFIG_ALLOW_RTTI) || !(LZO_CONFIG_ALLOW_RTTI)
#if defined(__has_feature)
#if __has_feature(cxx_rtti)
#error "unexpected feature cxx_rtti"
#endif
#endif
#if defined(__cpp_rtti)
#if defined(__clang__) && defined(_MSC_VER)
// clang-cl bug: option "/GR-" does not correctly undefine __cpp_rtti; using "-clang:-fno-rtti" works
#else
#error "unexpected __cpp_rtti"
#endif
#endif
#if defined(_CPPRTTI)
#error "unexpected _CPPRTTI"
#endif
#if defined(__GXX_RTTI)
#error "unexpected __GXX_RTTI"
#endif
#endif // LZO_CONFIG_ALLOW_RTTI

int lzo_cxx_dummy();
int lzo_cxx_dummy() { return 0; }
