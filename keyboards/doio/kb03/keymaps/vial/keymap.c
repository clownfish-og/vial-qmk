// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TO(1),  KC_1,     KC_2,     KC_3,      KC_MUTE
    ),
    [1] = LAYOUT(
        TO(2),  C(KC_X),  C(KC_C),  C(KC_V),   KC_ENT
    ),
    [2] = LAYOUT(
        TO(3),  KC_WBAK,  KC_WHOM,  KC_WFWD,   KC_MPLY
    ),
    [3] = LAYOUT(
        TO(0),  UG_HUEU,  UG_TOGG,  UG_SATD,   KC_RSFT
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [2] = { ENCODER_CCW_CW(KC_MRWD, KC_MFFD),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [3] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_PREV, UG_NEXT) },
};
#endif
