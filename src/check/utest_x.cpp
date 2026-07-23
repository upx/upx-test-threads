/* utest_x.cpp -- utest

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2024 Markus Franz Xaver Johannes Oberhumer
   All Rights Reserved.

   UPX and the UCL library are free software; you can redistribute them
   and/or modify them under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   Markus F.X.J. Oberhumer
   <markus@oberhumer.com>
 */

#include "utest_c.c"
#include "../conf.h"
#undef index // conf.h: upx_renamed_index

/*************************************************************************
//
**************************************************************************/

namespace {

template <class T>
struct ptr_level {
    enum { value = 0 };
    typedef T element_type;
    typedef const T const_element_type;
};
template <class T>
struct ptr_level<T *> {
    enum { value = ptr_level<T>::value + 1 };
    //    typedef typename ptr_level<T>::element_type *pointer;
    //    typedef typename ptr_level<T>::const_pointer const_pointer;
};
template <class T>
struct ptr_level<const T *> {
    enum { value = ptr_level<T>::value + 1 };
    //    typedef typename ptr_level<T>::pointer pointer;
    //    typedef const typename ptr_level<T>::const_pointer const_pointer;
};

template <class T, class U>
static inline constexpr bool is_same = std::is_same_v<T, U>;

template <class T>
struct PtrTypes {
    typedef T *v_p;
    typedef const T *v_c;
    static_assert(ptr_level<v_p>::value == 1);
    static_assert(ptr_level<v_c>::value == 1);
    //    static_assert(is_same<v_p, ptr_level<v_p>::pointer>);

    typedef v_p *v_p_p;
    typedef v_c *v_c_p;
    typedef const v_p *v_p_c;
    typedef const v_c *v_c_c;
    static_assert(is_same<v_p_p, T **>);
    static_assert(is_same<v_c_p, const T **>);
    static_assert(is_same<v_p_c, T *const *>);
    static_assert(is_same<v_c_c, const T *const *>);
    static_assert(ptr_level<v_p_p>::value == 2);
    static_assert(ptr_level<v_c_p>::value == 2);
    static_assert(ptr_level<v_p_c>::value == 2);
    static_assert(ptr_level<v_c_c>::value == 2);

    typedef v_p_p *v_p_p_p;
    typedef v_c_p *v_c_p_p;
    typedef v_p_c *v_p_c_p;
    typedef v_c_c *v_c_c_p;
    typedef const v_p_p *v_p_p_c;
    typedef const v_c_p *v_c_p_c;
    typedef const v_p_c *v_p_c_c;
    typedef const v_c_c *v_c_c_c;
    static_assert(is_same<v_p_p_p, T ***>);
    static_assert(is_same<v_c_p_p, const T ***>);
    static_assert(is_same<v_p_c_p, T *const **>);
    static_assert(is_same<v_c_c_p, const T *const **>);
    static_assert(is_same<v_p_p_c, T **const *>);
    static_assert(is_same<v_c_p_c, const T **const *>);
    static_assert(is_same<v_p_c_c, T *const *const *>);
    static_assert(is_same<v_c_c_c, const T *const *const *>);
    static_assert(ptr_level<v_p_p_p>::value == 3);
    static_assert(ptr_level<v_c_p_p>::value == 3);
    static_assert(ptr_level<v_p_c_p>::value == 3);
    static_assert(ptr_level<v_c_c_p>::value == 3);
    static_assert(ptr_level<v_p_p_c>::value == 3);
    static_assert(ptr_level<v_c_p_c>::value == 3);
    static_assert(ptr_level<v_p_c_c>::value == 3);
    static_assert(ptr_level<v_c_c_c>::value == 3);

    typedef v_p_p_p *v_p_p_p_p;
    typedef v_c_p_p *v_c_p_p_p;
    typedef v_p_c_p *v_p_c_p_p;
    typedef v_c_c_p *v_c_c_p_p;
    typedef v_p_p_c *v_p_p_c_p;
    typedef v_c_p_c *v_c_p_c_p;
    typedef v_p_c_c *v_p_c_c_p;
    typedef v_c_c_c *v_c_c_c_p;
    typedef const v_p_p_p *v_p_p_p_c;
    typedef const v_c_p_p *v_c_p_p_c;
    typedef const v_p_c_p *v_p_c_p_c;
    typedef const v_c_c_p *v_c_c_p_c;
    typedef const v_p_p_c *v_p_p_c_c;
    typedef const v_c_p_c *v_c_p_c_c;
    typedef const v_p_c_c *v_p_c_c_c;
    typedef const v_c_c_c *v_c_c_c_c;
    static_assert(is_same<v_p_p_p_p, T ****>);
    static_assert(is_same<v_c_p_p_p, const T ****>);
    static_assert(is_same<v_p_c_p_p, T *const ***>);
    static_assert(is_same<v_c_c_p_p, const T *const ***>);
    static_assert(is_same<v_p_p_c_p, T **const **>);
    static_assert(is_same<v_c_p_c_p, const T **const **>);
    static_assert(is_same<v_p_c_c_p, T *const *const **>);
    static_assert(is_same<v_c_c_c_p, const T *const *const **>);
    static_assert(is_same<v_p_p_p_c, T ***const *>);
    static_assert(is_same<v_c_p_p_c, const T ***const *>);
    static_assert(is_same<v_p_c_p_c, T *const **const *>);
    static_assert(is_same<v_c_c_p_c, const T *const **const *>);
    static_assert(is_same<v_p_p_c_c, T **const *const *>);
    static_assert(is_same<v_c_p_c_c, const T **const *const *>);
    static_assert(is_same<v_p_c_c_c, T *const *const *const *>);
    static_assert(is_same<v_c_c_c_c, const T *const *const *const *>);
};

} // namespace

UTEST(utest, ptr_depth) {
    PtrTypes<void> vpt;
    PtrTypes<long> lpt;
    (void) vpt;
    (void) lpt;
    ASSERT_TRUE(1);
}

/*************************************************************************
// upx_utest_check()
**************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

// UTEST_STATE();
struct utest_state_s utest_state = {}; // UTEST_STATE(); // -Wzero-as-null-pointer-constant

noinline int upx_utest_check(void);
noinline int upx_utest_check(void) {
    if (is_envvar_true("UPX_DEBUG_UTEST_DISABLE", "UPX_DEBUG_DISABLE_UTEST"))
        return 0;
    return utest_main(0, nullptr);
}

#if defined(__cplusplus)
}
#endif

/* vim:set ts=4 sw=4 et: */
