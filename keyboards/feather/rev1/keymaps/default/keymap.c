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
    // keymap
    _QWERTY,
    _DVORAK,
    _COLEMAK,
    _WORKMAN,
    _NORMAN,
    // another
    _LOWER,
    _RAISE,
    _ADJUST,
    // extra
    _NAVIGATION,
    _CALCULATOR,
    _GAME
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    DVORAK,
    COLEMAK,
    WORKMAN,
    NORMAN,
};

#define LED_TX B0
#define LED_RX D5

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LG_SPC GUI_T(KC_SPC)
#define RC_SPC RCTL_T(KC_SPC)
#define LC_ESC LCTL_T(KC_ESC)
#define RS_ESC RSFT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
              KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
              KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
               LOWER,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   RAISE,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          KC_LALT,  LG_SPC,  LC_ESC,     RS_ESC,  RC_SPC,  KC_ENT
                                                     // `--------------------------'  `--------------------------'
    ),

    [_DVORAK] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,   KC_Y,                                            KC_F,    KC_G,    KC_C,    KC_R,    KC_L, _______,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                                           KC_D,    KC_H,    KC_T,    KC_N,    KC_S, _______,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                                           KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, _______,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
                                                     // `--------------------------'  `--------------------------'
    ),

    [_WORKMAN] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______,    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                                           KC_J,    KC_F,    KC_U,    KC_P, KC_SCLN, _______,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______,    KC_A,    KC_S,    KC_H,    KC_T,    KC_G,                                           KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, _______,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______,    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,                                           KC_K,    KC_L, KC_COMM,  KC_DOT, KC_SLSH, _______,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
                                                     // `--------------------------'  `--------------------------'
    ),

    [_LOWER] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
                                                     // `--------------------------'  `--------------------------'
    ),

    [_RAISE] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
                                                     // `--------------------------'  `--------------------------'
    ),

    [_ADJUST] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______,   RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX,  QWERTY,  DVORAK, WORKMAN, XXXXXXX, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
                                                     // `--------------------------'  `--------------------------'
    ),

    [_NAVIGATION] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
                                                     // `--------------------------'  `--------------------------'
    ),

    [_CALCULATOR] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX,    KC_7,    KC_8,    KC_9, KC_PAST, KC_PSLS,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX,    KC_4,    KC_5,    KC_6, KC_PMNS, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                           KC_0,    KC_1,    KC_2,    KC_3, KC_PPLS, KC_PDOT,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
                                                     // `--------------------------'  `--------------------------'
    ),
};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(LED_TX);
  setPinOutput(LED_RX);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_is(_LOWER)) {
        writePinLow(LED_RX);
    } else {
        writePinHigh(LED_RX);
    }

    if (layer_state_is(_RAISE)) {
        writePinLow(LED_TX);
    } else {
        writePinHigh(LED_TX);
    }
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void set_default_layer_wrapper(uint8_t default_layer) {
    set_single_persistent_default_layer(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_default_layer_wrapper(_QWERTY);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_default_layer_wrapper(_DVORAK);
            }
            return false;
            break;
        case WORKMAN:
            if (record->event.pressed) {
                set_default_layer_wrapper(_WORKMAN);
            }
            return false;
            break;
    }
    return true;
}
