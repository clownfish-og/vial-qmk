// Copyright (C) 2025 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        BACKDOOR,    MOOSE,       PATBANG,
        BITS,     LT(1, GLUTES),  FREAKOUT,
        BUP,         CAPGEN5,     KC_ENT
    ),
    [1] = LAYOUT(
        TO(2),       SLAY,        DYE,
        ZEJIBO,      _______,     DONUT,
        CATDANCE,    LOVE,        THANKS
    ),
    [2] = LAYOUT(
        TO(0),       TO(3),      TO(5),
        _______,     _______,    _______,
        _______,     _______,    _______
    ),
    [3] = LAYOUT(
        TO(0),       TO(4),      TO(5),
        _______,     _______,    _______,
        _______,     _______,    _______
    ),
    [4] = LAYOUT(
        TO(0),       _______,    TO(5),
        _______,     _______,    _______,
        _______,     _______,    _______
    ),
    [5] = LAYOUT(
        TO(0),       KC_SHFT,    _______,
        RGB_HUI,     RGB_SAI,    RGB_SPI,
        RGB_MOD,     RGB_VAI,    RGB_TOG
    ),
};
