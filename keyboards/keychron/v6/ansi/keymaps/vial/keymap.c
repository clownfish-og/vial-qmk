/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include <lib/lib8tion/lib8tion.h>

// clang-format off
enum indicator_keycodes {
    CAPSLKD = 0x7E0B,
    CAPSLKU,
    NUMLKOD,
    NUMLKOU,
    COMBLKD,
    COMBLKU
};

enum my_keycodes {
    CAPGEN = 0x7E11,
    CHROME,
    EXTEND,
    RMP
};

enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_108(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUSE, CHROME,   KC_MUTE,  G(KC_D),  KC_EQL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MAC_FN] = LAYOUT_ansi_108(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  UG_VALD,  UG_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  UG_TOGG,  _______,  _______,  _______,  CAPGEN,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  CAPSLKU,  COMBLKU,  NUMLKOU,  _______,  _______,  _______,  _______,
        UG_TOGG,  UG_NEXT,  UG_VALU,  UG_HUEU,  UG_SATU,  UG_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  CAPSLKD,  COMBLKD,  NUMLKOD,  UG_SATU,  UG_VALU,  UG_SPDU,
        _______,  UG_PREV,  UG_VALD,  UG_HUED,  UG_SATD,  UG_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                UG_HUED,  _______,  UG_HUEU,  UG_NEXT,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,            UG_SATD,  UG_VALD,  UG_SPDD,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______,  UG_TOGG,            RMP,      UG_PREV),
    [WIN_BASE] = LAYOUT_ansi_108(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_PSCR,  KC_SCRL,  KC_PAUSE, CHROME,   KC_MUTE,  G(KC_D),  KC_EQL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [WIN_FN] = LAYOUT_ansi_108(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  UG_VALD,  UG_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  UG_TOGG,  _______,  _______,  _______,  CAPGEN,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  CAPSLKU,  COMBLKU,  NUMLKOU,  _______,  _______,  _______,  _______,
        UG_TOGG,  UG_NEXT,  UG_VALU,  UG_HUEU,  UG_SATU,  UG_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  CAPSLKD,  COMBLKD,  NUMLKOD,  UG_SATU,  UG_VALU,  UG_SPDU,
        _______,  UG_PREV,  UG_VALD,  UG_HUED,  UG_SATD,  UG_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                UG_HUED,  _______,  UG_HUEU,  UG_NEXT,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,            UG_SATD,  UG_VALD,  UG_SPDD,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______,  UG_TOGG,            RMP,      UG_PREV),
};
// clang-format on

typedef union {
    uint32_t raw;
    struct {
        uint8_t cap_h;
        uint8_t num_h;
        uint8_t com_h;
        uint8_t cap_s;
        uint8_t num_s;
        uint8_t com_s;
    };
} user_config_t;

user_config_t user_config;

// Initialize the EEPROM values
void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {
    user_config.raw   = 0;
    user_config.cap_h = 170;
    user_config.num_h = 0;
    user_config.com_h = 0;
    user_config.cap_s = 255;
    user_config.num_s = 0;
    user_config.com_s = 255;
    eeconfig_update_user(user_config.raw);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }

    bool shifted = get_mods() & MOD_MASK_SHIFT;

    switch (keycode) {
        case UG_TOGG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                    } break;
                }
            }
            if (!rgb_matrix_is_enabled()) {
                rgb_matrix_set_flags(LED_FLAG_ALL);
                rgb_matrix_enable();
            }
            return false;
        case CAPSLKU:
            if (record->event.pressed) {
                if (shifted) {
                    user_config.cap_s = qadd8(user_config.cap_s, RGB_MATRIX_SAT_STEP);
                } else {
                    user_config.cap_h = (user_config.cap_h + RGB_MATRIX_HUE_STEP);
                }
                eeconfig_update_user(user_config.raw);
            }
            return false;
        case CAPSLKD:
            if (record->event.pressed) {
                if (shifted) {
                    user_config.cap_s = qsub8(user_config.cap_s, RGB_MATRIX_SAT_STEP);
                } else {
                    user_config.cap_h = (user_config.cap_h - RGB_MATRIX_HUE_STEP);
                }
                eeconfig_update_user(user_config.raw);
            }
            return false;
        case NUMLKOU:
            if (record->event.pressed) {
                if (shifted) {
                    user_config.num_s = qadd8(user_config.num_s, RGB_MATRIX_SAT_STEP);
                } else {
                    user_config.num_h = (user_config.num_h + RGB_MATRIX_HUE_STEP);
                }
                eeconfig_update_user(user_config.raw);
            }
            return false;
        case NUMLKOD:
            if (record->event.pressed) {
                if (shifted) {
                    user_config.num_s = qsub8(user_config.num_s, RGB_MATRIX_SAT_STEP);
                } else {
                    user_config.num_h = (user_config.num_h - RGB_MATRIX_HUE_STEP);
                }
                eeconfig_update_user(user_config.raw);
            }
            return false;
        case COMBLKU:
            if (record->event.pressed) {
                if (shifted) {
                    user_config.com_s = qadd8(user_config.com_s, RGB_MATRIX_SAT_STEP);
                } else {
                    user_config.com_h = (user_config.com_h + RGB_MATRIX_HUE_STEP);
                }
                eeconfig_update_user(user_config.raw);
            }
            return false;
        case COMBLKD:
            if (record->event.pressed) {
                if (shifted) {
                    user_config.com_s = qsub8(user_config.com_s, RGB_MATRIX_SAT_STEP);
                } else {
                    user_config.com_h = (user_config.com_h - RGB_MATRIX_HUE_STEP);
                }
                eeconfig_update_user(user_config.raw);
            }
            return false;
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
                SEND_STRING(SS_LGUI("P") SS_DELAY(500) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(200) SS_TAP(X_ENT) SS_DELAY(400) SS_TAP(X_ESC));
            }
            return false;
        case RMP:
            if (record->event.pressed) {
                if (rgb_matrix_is_enabled()) rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv;
    if (host_keyboard_led_state().caps_lock && !host_keyboard_led_state().num_lock) {
        hsv.h = user_config.com_h;
        hsv.s = user_config.com_s;
        hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
    } else if (!host_keyboard_led_state().num_lock) {
        hsv.h = user_config.num_h;
        hsv.s = user_config.num_s;
        hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
    } else if (host_keyboard_led_state().caps_lock) {
        hsv.h = user_config.cap_h;
        hsv.s = user_config.cap_s;
        hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
    } else if (!rgb_matrix_get_flags()) {
        hsv.h = 0;
        hsv.s = 0;
        hsv.v = 0;
    } else {
        return false;
    }

    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x08)) { // 0x08 == LED_FLAG_MODIFIER
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return true;
}
#endif

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}
