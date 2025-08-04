// Copyright 2025 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_all(
              KC_NO,
    KC_ESC, KC_ENT, KC_LGUI),

    [1]   = LAYOUT_all(
              KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS),
    [2]   = LAYOUT_all(
              KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS),
    [3]   = LAYOUT_all(
              KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_1, KC_2)},
    [1] = { ENCODER_CCW_CW(KC_1, KC_2)},
    [2] = { ENCODER_CCW_CW(KC_1, KC_2)},
    [3] = { ENCODER_CCW_CW(KC_1, KC_2)}
};
#endif
