/// SPDX TODO
/// Copyright (C) Markus Franz Xaver Johannes Oberhumer

// mini <type_traits> for C++98
// should be compatible with gcc-3.4 and VS2005

// #pragma once // NOT once

#if __cplusplus >= 201103L // C++11
typedef decltype(nullptr) nullptr_t;
#else
struct nullptr_t {}; // FAKE
#endif

/*************************************************************************
//
**************************************************************************/

template <class T> struct type_identity { // C++20
    typedef T type;
};

template <bool, class T, class U> struct conditional {
    typedef U type;
};
template <class T, class U> struct conditional<true, T, U> {
    typedef T type;
};

template <bool, class T> struct enable_if {};
template <class T> struct enable_if<true, T> {
    typedef T type;
};

template <class T> struct add_const {
    typedef const T type;
};
template <class T> struct add_volatile {
    typedef volatile T type;
};
template <class T> struct add_cv {
    typedef const volatile T type;
};

template <class T> struct remove_const {
    typedef T type;
};
template <class T> struct remove_const<const T> {
    typedef T type;
};
template <class T> struct remove_volatile {
    typedef T type;
};
template <class T> struct remove_volatile<volatile T> {
    typedef T type;
};
template <class T> struct remove_cv {
    typedef T type;
};
template <class T> struct remove_cv<const T> {
    typedef T type;
};
template <class T> struct remove_cv<volatile T> {
    typedef T type;
};
template <class T> struct remove_cv<const volatile T> {
    typedef T type;
};

template <class T> struct add_lvalue_reference {
    typedef T &type;
};
template <> struct add_lvalue_reference<void> {
    typedef void type;
};
template <> struct add_lvalue_reference<const void> {
    typedef const void type;
};
template <> struct add_lvalue_reference<volatile void> {
    typedef volatile void type;
};
template <> struct add_lvalue_reference<const volatile void> {
    typedef const volatile void type;
};

template <class T> struct remove_reference {
    typedef T type;
};
template <class T> struct remove_reference<T &> {
    typedef T type;
};
#if __cplusplus >= 201103 // C++11
template <class T> struct remove_reference<T &&> {
    typedef T type;
};
#endif

template <class T> struct remove_cvref { // C++20
    typedef typename remove_cv<typename remove_reference<T>::type>::type type;
};

template <class T> struct add_pointer {
    typedef typename remove_reference<T>::type *type;
};

template <class T> struct remove_pointer {
    typedef T type;
};
template <class T> struct remove_pointer<T *> {
    typedef T type;
};
template <class T> struct remove_pointer<T *const> {
    typedef T type;
};
template <class T> struct remove_pointer<T *volatile> {
    typedef T type;
};
template <class T> struct remove_pointer<T *const volatile> {
    typedef T type;
};

/*************************************************************************
//
**************************************************************************/

template <class T, T v> struct integral_constant {
    typedef integral_constant<T, v> type;
    typedef T value_type;
#if __cplusplus >= 201103L // C++11
    static constexpr value_type value = v;
#else
    static const value_type value = v;
#endif
#if __cplusplus >= 201103L // C++11
    constexpr operator value_type() const noexcept { return value; }
#endif
#if __cplusplus >= 201402L // C++14
    constexpr value_type operator()() const noexcept { return value; }
#endif
};

struct false_type : public integral_constant<bool, false> {};
struct true_type : public integral_constant<bool, true> {};

template <class T, class U> struct is_same : public false_type {};
template <class T> struct is_same<T, T> : public true_type {};

template <class T> struct is_const : public false_type {};
template <class T> struct is_const<const T> : public true_type {};
template <class T> struct is_volatile : public false_type {};
template <class T> struct is_volatile<volatile T> : public true_type {};

template <class T> struct is_void : public false_type {};
template <> struct is_void<void> : public true_type {};
template <> struct is_void<const void> : public true_type {};
template <> struct is_void<volatile void> : public true_type {};
template <> struct is_void<const volatile void> : public true_type {};

template <class T> struct is_lvalue_reference : public false_type {};
template <class T> struct is_lvalue_reference<T &> : public true_type {};
template <class T> struct is_rvalue_reference : public false_type {};
#if __cplusplus >= 201103 // C++11
template <class T> struct is_rvalue_reference<T &&> : public true_type {};
#endif
template <class T> struct is_reference : public false_type {};
template <class T> struct is_reference<T &> : public true_type {};
#if __cplusplus >= 201103 // C++11
template <class T> struct is_reference<T &&> : public true_type {};
#endif

template <class T> struct is_pointer : public false_type {};
template <class T> struct is_pointer<T *> : public true_type {};
template <class T> struct is_pointer<T *const> : public true_type {};
template <class T> struct is_pointer<T *volatile> : public true_type {};
template <class T> struct is_pointer<T *const volatile> : public true_type {};

// is_bounded_array from C++20; NOTE: we need size_t
template <class T> struct is_bounded_array : public false_type {};
template <class T, size_t N> struct is_bounded_array<T[N]> : public true_type {};
template <class T, size_t N> struct is_bounded_array<const T[N]> : public true_type {};
template <class T, size_t N> struct is_bounded_array<volatile T[N]> : public true_type {};
template <class T, size_t N> struct is_bounded_array<const volatile T[N]> : public true_type {};

/*************************************************************************
// TODO: __int128
// TODO: wchar_t
// TODO: char8_t char16_t char32_t
**************************************************************************/

namespace detail {

// util: add CV from type From to type To
template <class From, class To> struct add_cv_from {
    typedef To type;
};
template <class From, class To> struct add_cv_from<const From, To> {
    typedef const To type;
};
template <class From, class To> struct add_cv_from<volatile From, To> {
    typedef volatile To type;
};
template <class From, class To> struct add_cv_from<const volatile From, To> {
    typedef const volatile To type;
};

template <class T> struct is_integral : public false_type {};
template <> struct is_integral<char> : public true_type {};
template <> struct is_integral<signed char> : public true_type {};
template <> struct is_integral<signed short> : public true_type {};
template <> struct is_integral<signed int> : public true_type {};
template <> struct is_integral<signed long> : public true_type {};
template <> struct is_integral<signed long long> : public true_type {};
template <> struct is_integral<unsigned char> : public true_type {};
template <> struct is_integral<unsigned short> : public true_type {};
template <> struct is_integral<unsigned int> : public true_type {};
template <> struct is_integral<unsigned long> : public true_type {};
template <> struct is_integral<unsigned long long> : public true_type {};

template <class T> struct is_signed : public false_type {};
template <> struct is_signed<char> : public integral_constant<bool, (char(-1) < 0)> {};
template <> struct is_signed<signed char> : public true_type {};
template <> struct is_signed<signed short> : public true_type {};
template <> struct is_signed<signed int> : public true_type {};
template <> struct is_signed<signed long> : public true_type {};
template <> struct is_signed<signed long long> : public true_type {};

template <class T> struct is_unsigned : public false_type {};
template <> struct is_unsigned<char> : public integral_constant<bool, (char(-1) > 0)> {};
template <> struct is_unsigned<unsigned char> : public true_type {};
template <> struct is_unsigned<unsigned short> : public true_type {};
template <> struct is_unsigned<unsigned int> : public true_type {};
template <> struct is_unsigned<unsigned long> : public true_type {};
template <> struct is_unsigned<unsigned long long> : public true_type {};

template <class T> struct make_signed {};
template <> struct make_signed<char> {
    typedef signed char type;
};
template <> struct make_signed<signed char> {
    typedef signed char type;
};
template <> struct make_signed<signed short> {
    typedef signed short type;
};
template <> struct make_signed<signed int> {
    typedef signed int type;
};
template <> struct make_signed<signed long> {
    typedef signed long type;
};
template <> struct make_signed<long long> {
    typedef signed long long type;
};
template <> struct make_signed<unsigned char> {
    typedef signed char type;
};
template <> struct make_signed<unsigned short> {
    typedef signed short type;
};
template <> struct make_signed<unsigned int> {
    typedef signed int type;
};
template <> struct make_signed<unsigned long> {
    typedef signed long type;
};
template <> struct make_signed<unsigned long long> {
    typedef signed long long type;
};

template <class T> struct make_unsigned {};
template <> struct make_unsigned<char> {
    typedef unsigned char type;
};
template <> struct make_unsigned<signed char> {
    typedef unsigned char type;
};
template <> struct make_unsigned<signed short> {
    typedef unsigned short type;
};
template <> struct make_unsigned<signed int> {
    typedef unsigned int type;
};
template <> struct make_unsigned<signed long> {
    typedef unsigned long type;
};
template <> struct make_unsigned<signed long long> {
    typedef unsigned long long type;
};
template <> struct make_unsigned<unsigned char> {
    typedef unsigned char type;
};
template <> struct make_unsigned<unsigned short> {
    typedef unsigned short type;
};
template <> struct make_unsigned<unsigned int> {
    typedef unsigned int type;
};
template <> struct make_unsigned<unsigned long> {
    typedef unsigned long type;
};
template <> struct make_unsigned<unsigned long long> {
    typedef unsigned long long type;
};

// ILP64
#if SIZEOF_SHORT != 2 && SIZEOF_INT != 2 && SIZEOF_LONG != 2
template <> struct is_integral<i16> : public true_type {};
template <> struct is_integral<u16> : public true_type {};
template <> struct is_signed<i16> : public true_type {};
template <> struct is_unsigned<u16> : public true_type {};
template <> struct make_signed<i16> {
    typedef i16 type;
};
template <> struct make_signed<u16> {
    typedef i16 type;
};
template <> struct make_unsigned<i16> {
    typedef u16 type;
};
template <> struct make_unsigned<u16> {
    typedef u16 type;
};
#endif

// ILP64
#if SIZEOF_SHORT != 4 && SIZEOF_INT != 4 && SIZEOF_LONG != 4
template <> struct is_integral<i32> : public true_type {};
template <> struct is_integral<u32> : public true_type {};
template <> struct is_signed<i32> : public true_type {};
template <> struct is_unsigned<u32> : public true_type {};
template <> struct make_signed<i32> {
    typedef i32 type;
};
template <> struct make_signed<u32> {
    typedef i32 type;
};
template <> struct make_unsigned<i32> {
    typedef u32 type;
};
template <> struct make_unsigned<u32> {
    typedef u32 type;
};
#endif

// bool
template <> struct is_integral<bool> : public true_type {};
template <> struct is_unsigned<bool> : public true_type {}; // NOTE
// std::make_signed and std::make_unsigned are NOT defined for bool!

} // namespace detail

template <class T> struct is_integral : public detail::is_integral<typename remove_cv<T>::type> {};
template <class T> struct is_signed : public detail::is_signed<typename remove_cv<T>::type> {};
template <class T> struct is_unsigned : public detail::is_unsigned<typename remove_cv<T>::type> {};

template <class T> struct make_signed {
    typedef typename detail::add_cv_from<
        T, typename detail::make_signed<typename remove_cv<T>::type>::type>::type type;
};
template <class T> struct make_unsigned {
    typedef typename detail::add_cv_from<
        T, typename detail::make_unsigned<typename remove_cv<T>::type>::type>::type type;
};
