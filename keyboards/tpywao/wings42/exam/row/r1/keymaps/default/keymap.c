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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _DVORAK,
    _SIGN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    DVORAK
};

#define SIGN TG(_SIGN)
#define G_E GUI_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty Layer
     *  Primary Side (USB Cable Connected Side)
     *  ,--------------------------------------
     *  |    `    Q    W    E       R   T
     *  |  Tab    A    S    D       F   G
     *  |  Sft    Z    X    C       V   B
     *  |                SIGN GUI/Esc Ctl
     *  `--------------------------------------
     *  Secondary Side (USB Cable Not Connected Side)
     *  ,----------------------------
     *  |   Y   U   I    O    P    \
     *  |   H   J   K    L    ;    '
     *  |   N   M   ,    .    /  Sft
     *  | Alt Spc Ent
     *  `----------------------------
     */
    [_QWERTY] = LAYOUT(
    // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
          KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS
    // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
    }
    return true;
}
