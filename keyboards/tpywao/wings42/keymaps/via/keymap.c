// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    // keymap
    _QWERTY,
    // another
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define LED_TX B0
#define LED_RX D5

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LG_SPC LGUI_T(KC_SPC)
#define RC_SPC RCTL_T(KC_SPC)
#define LA_ESC LALT_T(KC_ESC)
#define RS_ENT RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
              KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
              KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
               LOWER,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   RAISE,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          KC_LSFT,  LG_SPC,  LA_ESC,     KC_ESC,  RC_SPC,  RS_ENT
                                                     // `--------------------------'  `--------------------------'
    ),
    [_LOWER] = LAYOUT_split_3x6_3(
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
    [_RAISE] = LAYOUT_split_3x6_3(
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
    [_ADJUST] = LAYOUT_split_3x6_3(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
                                                     // `--------------------------'  `--------------------------'
    ),
};

void keyboard_pre_init_user(void) {
    // Call the keyboard pre init code.

    // Set our LED pins as output
    gpio_set_pin_output(LED_RX);
    gpio_set_pin_output(LED_TX);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t _state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    if (layer_state_cmp(_state, _LOWER)) {
        gpio_write_pin_low(LED_RX);
    } else {
        gpio_write_pin_high(LED_RX);
    }

    if (layer_state_cmp(_state, _RAISE)) {
        gpio_write_pin_low(LED_TX);
    } else {
        gpio_write_pin_high(LED_TX);
    }
    return _state;
}
