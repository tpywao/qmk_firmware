// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    // keymap
    _QWERTY,
    _DVORAK,
    _WORKMAN,
    _EUCALYN,
    _OONISHI,
    // another
    _LOWER,
    _RAISE,
    _ADJUST,
    // extra
    _NAVIGATION,
    _NUMPAD,
    _GAME
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    // https://en.wikipedia.org/wiki/Dvorak_keyboard_layout
    DVORAK,
    // https://github.com/workman-layout/Workman
    WORKMAN,
    // https://eucalyn.hatenadiary.jp/entry/about-eucalyn-layout
    EUCALYN,
    // https://0414.works/hairetu/
    OONISHI
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
    [_DVORAK] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,   KC_Y,                                            KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_SLSH,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                                           KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,                                           KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, _______,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
                                                     // `--------------------------'  `--------------------------'
    ),
    [_WORKMAN] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______,    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                                           KC_J,    KC_F,    KC_U,    KC_P, KC_SCLN, KC_MINS,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______,    KC_A,    KC_S,    KC_H,    KC_T,    KC_G,                                           KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, KC_QUOT,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______,    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,                                           KC_K,    KC_L, KC_COMM,  KC_DOT, KC_SLSH, _______,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
                                                     // `--------------------------'  `--------------------------'
    ),
    [_EUCALYN] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______,    KC_Q,    KC_W, KC_COMM,  KC_DOT, KC_SCLN,                                           KC_M,    KC_R,    KC_D,    KC_Y,    KC_P, KC_MINS,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______,    KC_A,    KC_O,    KC_E,    KC_I,    KC_U,                                           KC_G,    KC_T,    KC_K,    KC_S,    KC_N, KC_QUOT,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_F,                                           KC_B,    KC_H,    KC_J,    KC_L, KC_SLSH, _______,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
                                                     // `--------------------------'  `--------------------------'
    ),
    [_OONISHI] = LAYOUT_split_3x6_3(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______,    KC_Q,    KC_L,    KC_U, KC_COMM,  KC_DOT,                                           KC_F,    KC_W,    KC_R,    KC_Y,    KC_P, KC_SLSH,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______,    KC_E,    KC_I,    KC_A,    KC_O, KC_MINS,                                           KC_K,    KC_T,    KC_N,    KC_S,    KC_H, KC_QUOT,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______,    KC_Z,    KC_X,    KC_C,    KC_V, KC_SCLN,                                           KC_G,    KC_D,    KC_M,    KC_J,    KC_B, _______,
        // |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                                          _______, _______, _______,    _______, _______, _______
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
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         QWERTY, OONISHI, EUCALYN,  DVORAK, WORKMAN, XXXXXXX,
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
    [_NUMPAD] = LAYOUT(
        // ,-----------------------------------------------------.                                      ,-----------------------------------------------------.
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX,   KC_P7,   KC_P8,   KC_P9, KC_PAST, KC_PSLS,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, XXXXXXX,
        // |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          KC_P0,   KC_P1,   KC_P2,   KC_P3, KC_PPLS, KC_PDOT,
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
        case EUCALYN:
            if (record->event.pressed) {
                set_default_layer_wrapper(_EUCALYN);
            }
            return false;
            break;
        case OONISHI:
            if (record->event.pressed) {
                set_default_layer_wrapper(_OONISHI);
            }
            return false;
            break;
    }
    return true;
}
