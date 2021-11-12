/* Copyright 2021 tpywao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,                      R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                      R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                      R20, R21, R22, R23, R24, R25, \
                             L30, L31, L32,  R30, R31, R32 \
) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { KC_NO, KC_NO, KC_NO, L30, L31, L32 }, \
    { R00, R01, R02, R03, R04, R05 }, \
    { R10, R11, R12, R13, R14, R15 }, \
    { R20, R21, R22, R23, R24, R25 }, \
    { R30, R31, R32, KC_NO, KC_NO, KC_NO } \
}

/* TODO: pro micro1つの設定
 * #define LAYOUT_single( \
 *     k00, k01, k02, k03, k04, k05,            k06, k07, k08, k09, k10, k11, \
 *     k12, k13, k14, k15, k16, k17,            k18, k19, k20, k21, k22, k23, \
 *     k24, k25, k26, k27, k28, k29,            k30, k31, k32, k33, k34, k35, \
 *                         k36, k37, k38,  k39, k40, k41, \
 * ) { \
 *     { k00, k01, k02, k03, k04, k05,           k06, k07, k08, k09, k10, k11 }, \
 *     { k12, k13, k14, k15, k16, k17,           k18, k19, k20, k21, k22, k23 }, \
 *     { k24, k25, k26, k27, k28, k29,           k30, k31, k32, k33, k34, k35 }, \
 *                         { k36, k37, k38, k39, k40, k41 }, \
 * }
 */
