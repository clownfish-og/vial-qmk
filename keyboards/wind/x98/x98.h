#pragma once
#include QMK_KEYBOARD_H
#ifdef RGB_MATRIX_ENABLE
enum indicator_keycodes {
    CAPSLKD = QK_KB_0,
    CAPSLKU,
    NUMLKOD,
    NUMLKOU,
    COMBLKD,
    COMBLKU,
    VIAL_SAFE_RANGE
};
#endif
