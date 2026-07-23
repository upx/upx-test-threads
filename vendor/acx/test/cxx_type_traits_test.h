#if defined(_MSC_VER) && !defined(__clang__)
ct_assert((acx::is_same<long long, __int64>::value));
ct_assert((acx::is_same<unsigned long long, unsigned __int64>::value));
#endif

/*************************************************************************
//
**************************************************************************/

ct_assert((acx::is_same<void, acx::conditional<false, int, void>::type>::value));
ct_assert((acx::is_same<int, acx::conditional<true, int, void>::type>::value));

ct_assert((acx::is_void<void>::value));
ct_assert((acx::is_void<const void>::value));
ct_assert((acx::is_void<volatile void>::value));
ct_assert((acx::is_void<const volatile void>::value));
ct_assert((acx::is_void<void const>::value));
ct_assert((!acx::is_void<void *>::value));

ct_assert((!acx::is_pointer<void>::value));
ct_assert((acx::is_pointer<void *>::value));
ct_assert((acx::is_pointer<void *const>::value));
ct_assert((acx::is_pointer<const void *>::value));
ct_assert((acx::is_pointer<const void *const>::value));
ct_assert((acx::is_pointer<void *volatile>::value));
ct_assert((acx::is_pointer<void *const volatile>::value));

ct_assert((acx::is_same<void, acx::remove_pointer<void>::type>::value));
ct_assert((acx::is_same<void, acx::remove_pointer<void *>::type>::value));
ct_assert((acx::is_same<void, acx::remove_pointer<void *const>::type>::value));
ct_assert((acx::is_same<void, acx::remove_pointer<void *volatile>::type>::value));
ct_assert((acx::is_same<void, acx::remove_pointer<void *const volatile>::type>::value));
ct_assert((acx::is_same<const void, acx::remove_pointer<const void>::type>::value));
ct_assert((acx::is_same<const void, acx::remove_pointer<const void *>::type>::value));
ct_assert((acx::is_same<const void, acx::remove_pointer<const void *const>::type>::value));
ct_assert((acx::is_same<const void, acx::remove_pointer<const void *volatile>::type>::value));
ct_assert((acx::is_same<const void, acx::remove_pointer<const void *const volatile>::type>::value));

ct_assert((acx::is_same<void, void>::value));
ct_assert((!acx::is_same<void, const void>::value));
ct_assert((acx::is_same<int, int>::value));
ct_assert((!acx::is_same<int, long>::value));
ct_assert((!acx::is_same<int, const int>::value));
ct_assert((!acx::is_same<char, signed char>::value));
ct_assert((!acx::is_same<char, unsigned char>::value));

ct_assert((acx::is_same<short, signed short>::value));
ct_assert((acx::is_same<int, signed>::value));
ct_assert((acx::is_same<int, signed int>::value));
ct_assert((acx::is_same<long, signed long>::value));
ct_assert((acx::is_same<long long, signed long long>::value));

ct_assert((acx::is_same<void, acx::remove_const<void>::type>::value));
ct_assert((acx::is_same<void, acx::remove_const<const void>::type>::value));
ct_assert((acx::is_same<void, acx::remove_volatile<void>::type>::value));
ct_assert((acx::is_same<void, acx::remove_volatile<volatile void>::type>::value));
ct_assert((acx::is_same<void, acx::remove_cv<void>::type>::value));
ct_assert((acx::is_same<void, acx::remove_cv<const void>::type>::value));
ct_assert((acx::is_same<void, acx::remove_cv<volatile void>::type>::value));
ct_assert((acx::is_same<void, acx::remove_cv<const volatile void>::type>::value));
ct_assert((acx::is_same<void, acx::remove_cv<void const>::type>::value));
ct_assert((acx::is_same<void, acx::remove_cv<void volatile>::type>::value));
ct_assert((acx::is_same<void, acx::remove_cv<void volatile const>::type>::value));

#if __cplusplus >= 202002L || defined(TESTING_ACX) // C++20
ct_assert((acx::is_same<int, acx::remove_cvref<int>::type>::value));
ct_assert((acx::is_same<int, acx::remove_cvref<int &>::type>::value));
ct_assert((acx::is_same<int, acx::remove_cvref<const int &>::type>::value));
ct_assert((!acx::is_bounded_array<void *>::value));
ct_assert((!acx::is_bounded_array<int *>::value));
ct_assert((!acx::is_bounded_array<const int *>::value));
ct_assert((!acx::is_bounded_array<volatile int *>::value));
ct_assert((!acx::is_bounded_array<const volatile int *>::value));
ct_assert((acx::is_bounded_array<int[1]>::value));
ct_assert((acx::is_bounded_array<const int[1]>::value));
ct_assert((acx::is_bounded_array<volatile int[1]>::value));
ct_assert((acx::is_bounded_array<const volatile int[1]>::value));
ct_assert((acx::is_bounded_array<int[1u]>::value));
ct_assert((acx::is_bounded_array<const int[1u]>::value));
ct_assert((acx::is_bounded_array<volatile int[1u]>::value));
ct_assert((acx::is_bounded_array<const volatile int[1u]>::value));
ct_assert((acx::is_bounded_array<int[1l]>::value));
ct_assert((acx::is_bounded_array<const int[1l]>::value));
ct_assert((acx::is_bounded_array<volatile int[1l]>::value));
ct_assert((acx::is_bounded_array<const volatile int[1l]>::value));
#endif

ct_assert((acx::is_same<void, acx::add_lvalue_reference<void>::type>::value));
ct_assert((acx::is_same<const void, acx::add_lvalue_reference<const void>::type>::value));
ct_assert((acx::is_same<volatile void, acx::add_lvalue_reference<volatile void>::type>::value));
ct_assert((acx::is_same<const volatile void,
                        acx::add_lvalue_reference<const volatile void>::type>::value));
ct_assert((acx::is_same<int &, acx::add_lvalue_reference<int>::type>::value));
ct_assert((acx::is_same<const int &, acx::add_lvalue_reference<const int>::type>::value));
ct_assert((acx::is_same<volatile int &, acx::add_lvalue_reference<volatile int>::type>::value));
ct_assert((acx::is_same<const volatile int &,
                        acx::add_lvalue_reference<const volatile int>::type>::value));

ct_assert((acx::is_same<void *, acx::add_pointer<void>::type>::value));
ct_assert((acx::is_same<const void *, acx::add_pointer<const void>::type>::value));
ct_assert((acx::is_same<int *, acx::add_pointer<int>::type>::value));
ct_assert((acx::is_same<const int *, acx::add_pointer<const int>::type>::value));
ct_assert((acx::is_same<int **, acx::add_pointer<int *>::type>::value));
ct_assert((acx::is_same<const int **, acx::add_pointer<const int *>::type>::value));
ct_assert((acx::is_same<int *const *, acx::add_pointer<int *const>::type>::value));
ct_assert((acx::is_same<const int *const *, acx::add_pointer<const int *const>::type>::value));

#if defined(_MSC_VER) && !defined(__clang__)
#    pragma warning(push)
#    pragma warning(disable : 4628) // ??? W1: digraphs not supported with -Ze
#endif
ct_assert((acx::is_same<int *const *, acx::add_pointer<acx::add_const<int *>::type>::type>::value));
ct_assert((acx::is_same<int **const, acx::add_const<acx::add_pointer<int *>::type>::type>::value));
ct_assert(
    (acx::is_same<int *const *, acx::add_pointer<acx::add_const<int *const>::type>::type>::value));
ct_assert((acx::is_same<int *const *const,
                        acx::add_const<acx::add_pointer<int *const>::type>::type>::value));
ct_assert((acx::is_same<const int *const *,
                        acx::add_pointer<acx::add_const<const int *>::type>::type>::value));
ct_assert((acx::is_same<const int **const,
                        acx::add_const<acx::add_pointer<const int *>::type>::type>::value));
ct_assert((acx::is_same<const int *const *,
                        acx::add_pointer<acx::add_const<const int *const>::type>::type>::value));
ct_assert((acx::is_same<const int *const *const,
                        acx::add_const<acx::add_pointer<const int *const>::type>::type>::value));
#if defined(_MSC_VER) && !defined(__clang__)
#    pragma warning(pop)
#endif

// type_identity
#if __cplusplus >= 202002L || defined(TESTING_ACX) // C++20
namespace N_TEST_ACX {

// example: disable template argument deduction for one or more arguments
template <class T> T f(T a, T b) { return a + b; }
template <class T> T g(T a, typename acx::type_identity<T>::type b) { return a + b; }
ct_assert((sizeof(f(3.14, 0.0)) == sizeof(double))); // ok
ct_assert((sizeof(g(3.14, 0.0)) == sizeof(double))); // ok
ct_assert((sizeof(g(3.14, 0)) == sizeof(double)));   // works: calls g(double, double)
// ct_assert((sizeof(f(3.14, 0)) == sizeof(double)));   // error: no matching to call f(double, int)

// example: force client code to explicitly specify the template parameter
template <class T> T h(typename acx::type_identity<T>::type a) { return a; }
ct_assert((sizeof(h<int>(0)) == sizeof(int)));
ct_assert((sizeof(h<double>(0.0)) == sizeof(double)));
// ct_assert((sizeof(h(0)) == sizeof(int))); // error: does not compile

// example: force client code to explicitly specify multiple template parameters
template <class T, class U>
T i(typename acx::type_identity<T>::type a, typename acx::type_identity<U>::type b);
ct_assert((sizeof(i<int, double>(0, 0)) == sizeof(int)));
ct_assert((sizeof(i<double, int>(0, 0)) == sizeof(double)));

} // namespace N_TEST_ACX
#endif

/*************************************************************************
// is_integral, is_signed, is_unsigned
**************************************************************************/

// bool
ct_assert((acx::is_integral<bool>::value));
ct_assert((acx::is_unsigned<bool>::value)); // NOTE
ct_assert((!acx::is_signed<bool>::value));

ct_assert((acx::is_integral<char>::value));
ct_assert((acx::is_integral<signed char>::value));
ct_assert((acx::is_integral<short>::value));
ct_assert((acx::is_integral<int>::value));
ct_assert((acx::is_integral<long>::value));
ct_assert((acx::is_integral<long long>::value));
ct_assert((acx::is_integral<unsigned char>::value));
ct_assert((acx::is_integral<unsigned short>::value));
ct_assert((acx::is_integral<unsigned int>::value));
ct_assert((acx::is_integral<unsigned long>::value));
ct_assert((acx::is_integral<unsigned long long>::value));

#if CHAR_MAX == 255
ct_assert((!acx::is_signed<char>::value));
ct_assert((acx::is_unsigned<char>::value));
#else
ct_assert((acx::is_signed<char>::value));
ct_assert((!acx::is_unsigned<char>::value));
#endif
ct_assert((acx::is_signed<signed char>::value));
ct_assert((acx::is_signed<short>::value));
ct_assert((acx::is_signed<int>::value));
ct_assert((acx::is_signed<long>::value));
ct_assert((acx::is_signed<long long>::value));
ct_assert((acx::is_unsigned<unsigned char>::value));
ct_assert((acx::is_unsigned<unsigned short>::value));
ct_assert((acx::is_unsigned<unsigned int>::value));
ct_assert((acx::is_unsigned<unsigned long>::value));
ct_assert((acx::is_unsigned<unsigned long long>::value));

ct_assert((!acx::is_integral<void>::value));
ct_assert((!acx::is_integral<char *>::value));
ct_assert((!acx::is_integral<void *>::value));
ct_assert((!acx::is_signed<void>::value));
ct_assert((!acx::is_signed<char *>::value));
ct_assert((!acx::is_signed<void *>::value));
ct_assert((!acx::is_unsigned<void>::value));
ct_assert((!acx::is_unsigned<char *>::value));
ct_assert((!acx::is_unsigned<void *>::value));

// make_signed

#if CHAR_MAX == 255
ct_assert((acx::is_same<signed char, acx::make_signed<char>::type>::value));
#else
// TODO: is this true?
ct_assert((acx::is_same<signed char, acx::make_signed<char>::type>::value));
#endif
ct_assert((acx::is_same<signed char, acx::make_signed<signed char>::type>::value));
ct_assert((acx::is_same<short, acx::make_signed<signed short>::type>::value));
ct_assert((acx::is_same<int, acx::make_signed<signed int>::type>::value));
ct_assert((acx::is_same<long, acx::make_signed<signed long>::type>::value));
ct_assert((acx::is_same<long long, acx::make_signed<signed long long>::type>::value));
ct_assert((acx::is_same<signed char, acx::make_signed<unsigned char>::type>::value));
ct_assert((acx::is_same<short, acx::make_signed<unsigned short>::type>::value));
ct_assert((acx::is_same<int, acx::make_signed<unsigned int>::type>::value));
ct_assert((acx::is_same<long, acx::make_signed<unsigned long>::type>::value));
ct_assert((acx::is_same<long long, acx::make_signed<unsigned long long>::type>::value));

namespace {
typedef acx::make_signed<signed char>::type my_signed_char;
typedef acx::make_signed<short>::type my_signed_short;
typedef acx::make_signed<int>::type my_signed_int;
typedef acx::make_signed<long>::type my_signed_long;
typedef acx::make_signed<long long>::type my_signed_long_long;

ct_assert((acx::is_same<signed char, my_signed_char>::value));
ct_assert((acx::is_same<short, my_signed_short>::value));
ct_assert((acx::is_same<int, my_signed_int>::value));
ct_assert((acx::is_same<long, my_signed_long>::value));
ct_assert((acx::is_same<long long, my_signed_long_long>::value));
} // namespace

// make_unsigned

#if CHAR_MAX == 127
ct_assert((acx::is_same<unsigned char, acx::make_unsigned<char>::type>::value));
#else
// TODO: is this true?
ct_assert((acx::is_same<unsigned char, acx::make_unsigned<char>::type>::value));
#endif
ct_assert((acx::is_same<unsigned char, acx::make_unsigned<signed char>::type>::value));
ct_assert((acx::is_same<unsigned short, acx::make_unsigned<signed short>::type>::value));
ct_assert((acx::is_same<unsigned int, acx::make_unsigned<signed int>::type>::value));
ct_assert((acx::is_same<unsigned long, acx::make_unsigned<signed long>::type>::value));
ct_assert((acx::is_same<unsigned long long, acx::make_unsigned<signed long long>::type>::value));
ct_assert((acx::is_same<unsigned char, acx::make_unsigned<unsigned char>::type>::value));
ct_assert((acx::is_same<unsigned short, acx::make_unsigned<unsigned short>::type>::value));
ct_assert((acx::is_same<unsigned int, acx::make_unsigned<unsigned int>::type>::value));
ct_assert((acx::is_same<unsigned long, acx::make_unsigned<unsigned long>::type>::value));
ct_assert((acx::is_same<unsigned long long, acx::make_unsigned<unsigned long long>::type>::value));

namespace {
typedef acx::make_unsigned<signed char>::type my_unsigned_char;
typedef acx::make_unsigned<short>::type my_unsigned_short;
typedef acx::make_unsigned<int>::type my_unsigned_int;
typedef acx::make_unsigned<long>::type my_unsigned_long;
typedef acx::make_unsigned<long long>::type my_unsigned_long_long;

ct_assert((acx::is_same<unsigned char, my_unsigned_char>::value));
ct_assert((acx::is_same<unsigned short, my_unsigned_short>::value));
ct_assert((acx::is_same<unsigned int, my_unsigned_int>::value));
ct_assert((acx::is_same<unsigned long, my_unsigned_long>::value));
ct_assert((acx::is_same<unsigned long long, my_unsigned_long_long>::value));
} // namespace

/*************************************************************************
// tt_assert_type_pair
**************************************************************************/

#define tt_assert_type_pair(a, b, n)                                                               \
    ct_assert((sizeof(a) == sizeof(b)) && (__alignof__(a) == __alignof__(b)) &&                    \
              ((a) ((a) 0 - (a) 1) < 0) && ((b) ((b) 0 - (b) 1) > 0) &&                            \
              ((n) == 0 || sizeof(a) == (n)) && (acx::is_integral<a>::value) &&                    \
              (acx::is_integral<b>::value) && (acx::is_signed<a>::value) &&                        \
              (!acx::is_unsigned<a>::value) && (acx::is_unsigned<b>::value) &&                     \
              (!acx::is_signed<b>::value) &&                                                       \
              (acx::is_same<a, acx::make_signed<a>::type>::value) &&                               \
              (acx::is_same<a, acx::make_signed<b>::type>::value) &&                               \
              (acx::is_same<b, acx::make_unsigned<a>::type>::value) &&                             \
              (acx::is_same<b, acx::make_unsigned<b>::type>::value))

tt_assert_type_pair(signed char, unsigned char, 1);
tt_assert_type_pair(short, unsigned short, SIZEOF_SHORT);
tt_assert_type_pair(int, unsigned int, SIZEOF_INT);
tt_assert_type_pair(long, unsigned long, SIZEOF_LONG);
tt_assert_type_pair(long long, unsigned long long, SIZEOF_LONG_LONG);

tt_assert_type_pair(signed short, unsigned short, SIZEOF_SHORT);
tt_assert_type_pair(signed int, unsigned int, SIZEOF_INT);
tt_assert_type_pair(signed long, unsigned long, SIZEOF_LONG);
tt_assert_type_pair(signed long long, unsigned long long, SIZEOF_LONG_LONG);

tt_assert_type_pair(signed, unsigned, SIZEOF_INT);
tt_assert_type_pair(signed, unsigned int, SIZEOF_INT);
tt_assert_type_pair(signed int, unsigned, SIZEOF_INT);
tt_assert_type_pair(signed int, unsigned int, SIZEOF_INT);

tt_assert_type_pair(i8, u8, 1);
tt_assert_type_pair(i16, u16, 2);
tt_assert_type_pair(i32, u32, 4);
tt_assert_type_pair(i64, u64, 8);
#if SIZEOF_LONG_LONG == 16
tt_assert_type_pair(i128, u128, 16);
#elif defined(SIZEOF_I128) && SIZEOF_I128 == 16
// __int128 not supported by all libc++
// tt_assert_type_pair(i128, u128, 16);
#endif

#if defined(__clang__)
#    pragma clang diagnostic push
#elif defined(__GNUC__) && (__GNUC__ >= 5)
#    pragma GCC diagnostic push
// warning: type qualifiers ignored on cast result type
#    pragma GCC diagnostic ignored "-Wignored-qualifiers"
#elif defined(_MSC_VER)
#    pragma warning(push)
#    pragma warning(disable : 4197) // 'x' : top-level volatile in cast is ignored
#endif

tt_assert_type_pair(const signed char, const unsigned char, 1);
tt_assert_type_pair(const short, const unsigned short, SIZEOF_SHORT);
tt_assert_type_pair(const int, const unsigned int, SIZEOF_INT);
tt_assert_type_pair(const long, const unsigned long, SIZEOF_LONG);
tt_assert_type_pair(const long long, const unsigned long long, SIZEOF_LONG_LONG);

tt_assert_type_pair(volatile signed char, volatile unsigned char, 1);
tt_assert_type_pair(volatile short, volatile unsigned short, SIZEOF_SHORT);
tt_assert_type_pair(volatile int, volatile unsigned int, SIZEOF_INT);
tt_assert_type_pair(volatile long, volatile unsigned long, SIZEOF_LONG);
tt_assert_type_pair(volatile long long, volatile unsigned long long, SIZEOF_LONG_LONG);

tt_assert_type_pair(const volatile signed char, const volatile unsigned char, 1);
tt_assert_type_pair(const volatile short, const volatile unsigned short, SIZEOF_SHORT);
tt_assert_type_pair(const volatile int, const volatile unsigned int, SIZEOF_INT);
tt_assert_type_pair(const volatile long, const volatile unsigned long, SIZEOF_LONG);
tt_assert_type_pair(const volatile long long, const volatile unsigned long long, SIZEOF_LONG_LONG);

tt_assert_type_pair(const i8, const u8, 1);
tt_assert_type_pair(const i16, const u16, 2);
tt_assert_type_pair(const i32, const u32, 4);
tt_assert_type_pair(const i64, const u64, 8);
#if SIZEOF_LONG_LONG == 16
tt_assert_type_pair(const i128, const u128, 16);
#endif

#if defined(__clang__)
#    pragma clang diagnostic pop
#elif defined(__GNUC__) && (__GNUC__ >= 5)
#    pragma GCC diagnostic pop
#elif defined(_MSC_VER)
#    pragma warning(pop)
#endif

#undef tt_assert_type_pair
