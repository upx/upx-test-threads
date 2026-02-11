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
