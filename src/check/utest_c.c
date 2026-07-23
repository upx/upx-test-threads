/* utest_c.c -- utest

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

/*************************************************************************
//
**************************************************************************/

/*************************************************************************
//
**************************************************************************/

#include "../util/system_defs.h"
#include "../util/system_features.h"
#include <utest/utest.h>

UTEST(utest, core) {
    ASSERT_FALSE(0);
    ASSERT_TRUE(1);
}

/* vim:set ts=4 sw=4 et: */
