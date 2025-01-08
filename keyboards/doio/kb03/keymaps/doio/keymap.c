// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TO(1),  KC_MYCM,    KC_MPLY,    G(KC_D),    KC_MPRV
    ),
    [1] = LAYOUT(
        TO(2),   C(KC_Z),  C(S(KC_A)), MEH(KC_E),  C(S(KC_EQL))
    ),
    [2] = LAYOUT(
        TO(3),  C(S(KC_M)),  KC_SPC,    S(KC_M),     C(KC_M)
    ),
    [3] = LAYOUT(
        TO(0),    RGB_VAD,   RGB_MOD,   RGB_VAI,     RGB_TOG
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MNXT, KC_MUTE), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(C(KC_M), C(KC_EQL)),  ENCODER_CCW_CW(KC_LBRC, KC_RBRC) },
    [2] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT),  ENCODER_CCW_CW(A(KC_MS_WH_DOWN), A(KC_MS_WH_UP)) },
    [3] = { ENCODER_CCW_CW(RGB_SAD, RGB_SAI),  ENCODER_CCW_CW(RGB_HUD, RGB_HUI) }
};
#endif
