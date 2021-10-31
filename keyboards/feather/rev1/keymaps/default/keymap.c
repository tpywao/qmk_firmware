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
          KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,   KC_I,    KC_O,     KC_P, KC_BSLS,
    // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
          KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,   KC_K,    KC_L,  KC_SCLN, KC_QUOT,
    // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
         KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                         SIGN,     G_E, KC_LCTL,    KC_LALT,  KC_SPC,  KC_ENT
                                                 // `--------------------------'  `--------------------------'
    ),

    /* Dvorak Layer
     *  Primary Side (USB Cable Connected Side)
     *  ,---------------------------------
     *  |    `    '    ,    .       P   Y
     *  |  Tab    A    O    E       U   I
     *  |  Sft    ;    Q    J       K   X
     *  |                SIGN GUI/Esc Ctl
     *  `---------------------------------
     *  Secondary Side (USB Cable Not Connected Side)
     *  ,----------------------------
     *  |   F   G   C    O    L    /
     *  |   D   H   T    L    S    -
     *  |   B   M   W    V    Z  Sft
     *  | Alt Spc Ent
     *  `----------------------------
     */
    /* [_DVORAK] = LAYOUT(
        KC_GRV,  KC_QUOT, KC_COMM, KC_DOT, KC_P,          KC_Y,
        KC_TAB,  KC_A,    KC_O,    KC_E,   KC_U,          KC_I,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,   KC_K,          KC_X,
                                   SIGN,   G_E, KC_LCTL,

        KC_F,    KC_G,   KC_C,   KC_R,    KC_L,    KC_SLSH,
        KC_D,    KC_H,   KC_T,   KC_N,    KC_S,    KC_QUOT,
        KC_B,    KC_M,   KC_W,   KC_V,    KC_Z,    KC_RSFT,
        KC_LALT, KC_SPC, KC_ENT
    ), */

    /* Sign Layer
     *  Primary Side (USB Cable Connected Side)
     *  ,--------------------------------
     *  |  ____    1    2    3    4    5
     *  |  ____ XXXX XXXX XXXX XXXX XXXX
     *  |  ____ XXXX XXXX XXXX XXXX XXXX
     *  |                 ____ ____ ____
     *  `--------------------------------
     *  Secondary Side (USB Cable Not Connected Side)
     *  ,---------------------------------
     *  |     6    7    8    9    0 RESET
     *  |     ←    ↓    ↑    →    [     ]
     *  |  XXXX XXXX ____ ____ ____  ____
     *  |  ____ ____ ____
     *  `---------------------------------
     */
    /* [_SIGN] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______,

        KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    RESET,
        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_LBRC, KC_RBRC,
        XXXXXXX, XXXXXXX, _______, _______,  _______, _______,
        _______, _______, _______
    ) */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
    }
    return true;
}
