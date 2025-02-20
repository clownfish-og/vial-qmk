/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

enum my_keycodes {
    CAPGEN = VIAL_SAFE_RANGE,
    CHROME,
    EXTEND,
    RMP,
    VENV,
    DEACT,
    CLANGD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_ESC,           KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,           KC_F12,  MO(1),   KC_HOME, KC_END,  KC_MUTE,  KC_EQL,
	KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, KC_DEL,  KC_NUM,  KC_PSLS, KC_PAST,  KC_PMNS,
	KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS, KC_PGUP, KC_P7,   KC_P8,   KC_P9,    KC_PPLS,
	KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,  KC_PGDN, KC_P4,   KC_P5,   KC_P6,
	KC_LSFT, KC_BSLS, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,            KC_P1,   KC_P2,   KC_P3,     KC_PENT,
	KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                             KC_RALT, KC_RALT, KC_LEFT,          KC_DOWN, KC_RGHT, KC_P0,            KC_PDOT
    ),

	[1] = LAYOUT(
	EXTEND,           KC_BRID, KC_BRIU, CAPSLKD, CAPSLKU, COMBLKD, COMBLKU, NUMLKOD, NUMLKOU, _______, _______, _______,          CAPGEN,  _______, _______, _______, _______, CHROME,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, UG_SATU, UG_VALU, UG_SPDU, UG_NEXT,
	_______, _______, _______, DEACT,   _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, UG_HUED, _______, UG_HUEU,
	_______, _______, _______, _______, CLANGD,  VENV,    _______, _______, _______, _______, _______, _______, _______,          _______,          UG_SATD, UG_VALD, UG_SPDD, UG_PREV,
	MO(2),   _______, _______,                            _______,                            _______, _______, _______,          _______, _______, UG_TOGG,          RMP
    ),

	[2] = LAYOUT(
	EE_CLR,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, QK_BOOT,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______,
	_______, _______, _______,                            _______,                            _______, _______, _______,          _______, _______, _______,          _______
    ),

	[3] = LAYOUT(
	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______, _______, _______,
	_______, _______, _______,                            _______,                            _______, _______, _______,          _______, _______, _______,          _______
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CAPGEN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("acvvvvv"));
            }
            return false;
        case CHROME:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(" ") SS_DELAY(200) ">chrome.exe" SS_DELAY(200) SS_TAP(X_ENT));
            }
            return false;
        case EXTEND:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("p") SS_DELAY(300) SS_TAP(X_DOWN) SS_DELAY(50) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_ENT) SS_DELAY(100) SS_TAP(X_ESC));
            }
            return false;
        case RMP:
            if (record->event.pressed) {
                if (rgb_matrix_is_enabled()) rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
        case VENV:
            if (record->event.pressed) {
                SEND_STRING("source .venv/bin/activate\n");
            }
            return false;
        case DEACT:
            if (record->event.pressed) {
                SEND_STRING("deactivate\n");
            }
            return false;
        case CLANGD:
            if (record->event.pressed) {
                SEND_STRING("qmk compile -kb  -km  --compiledb" SS_TAP(X_HOME) SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_TAP(X_RIGHT) SS_TAP(X_RIGHT) SS_UP(X_LCTL) SS_TAP(X_RIGHT));
            }
            return false;
    }
    return true;
}
