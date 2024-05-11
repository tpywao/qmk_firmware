// Copyright 2024 tpywao (@tpywao)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROW_PINS_RIGHT { F6, F7, B1, B3 }
#define MATRIX_COL_PINS_RIGHT { E6, D7, C6, D4, D0, D1 }
#define SOFT_SERIAL_PIN D2

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
