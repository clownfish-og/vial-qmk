/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
//    0        1       2         3        4       5        6        7       8         9      10       11       12        13        14         15       16       17       18       19
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
    KC_ESC,           KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_PSCR, KC_SCRL,  KC_PAUS, 
	KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,  KC_PGUP, KC_NLCK, KC_PSLS, KC_PAST,  KC_PMNS, KC_BSLS,
	KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGDN, KC_P7,   KC_P8,   KC_P9,    KC_PPLS,
	KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,   KC_END,  KC_P4,   KC_P5,   KC_P6,     
	KC_LSFT, KC_BSLS, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  KC_UP,             KC_P1,   KC_P2,   KC_P3,     KC_PENT,
	KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,                                                       KC_RALT, MO(1),    KC_LEFT,  KC_DOWN,  KC_RGHT, KC_P0,            KC_PDOT          ),
      //  ESC          F1       F2       F3       F4       F5       F6       F7      F8        F9       F10       F11     F12       PSCR   SLCK
    
	[1] = LAYOUT(
	KC_ESC,           KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_PSCR, KC_SCRL,  KC_PAUS,
	KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,  KC_PGUP, KC_NLCK, KC_PSLS, KC_PAST,  KC_PMNS, KC_BSLS,
	KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGDN, KC_P7,   KC_P8,   KC_P9,    KC_PPLS,
	KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,   KC_END,  KC_P4,   KC_P5,   KC_P6,     
	KC_LSFT, KC_BSLS, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  KC_UP,             KC_P1,   KC_P2,   KC_P3,     KC_PENT,
	MO(2), KC_LGUI, KC_LALT, KC_SPC,                                                         KC_RALT, KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_P0,            KC_PDOT          ),
    
	[2] = LAYOUT(
	EE_CLR,           KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   QK_BOOT, KC_HOME, KC_PSCR, KC_SCRL, KC_PAUS,
	KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,  KC_PGUP, KC_NLCK, KC_PSLS, KC_PAST,  KC_PMNS, KC_BSLS,
	KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGDN, KC_P7,   KC_P8,   KC_P9,    KC_PPLS,
	KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,   KC_END,  KC_P4,   KC_P5,   KC_P6,     
	KC_LSFT, KC_BSLS, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  KC_UP,             KC_P1,   KC_P2,   KC_P3,     KC_PENT,
	KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,                                                       KC_RALT, KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_P0,            KC_PDOT          ),
    
	[3] = LAYOUT(
	KC_ESC,           KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,  KC_HOME, KC_PSCR, KC_SCRL,  KC_PAUS,
    KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,  KC_PGUP, KC_NLCK, KC_PSLS, KC_PAST,  KC_PMNS, KC_BSLS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGDN, KC_P7,   KC_P8,   KC_P9,    KC_PPLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,   KC_END,  KC_P4,   KC_P5,   KC_P6,     
    KC_LSFT, KC_BSLS, KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  KC_UP,             KC_P1,   KC_P2,   KC_P3,    KC_PENT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,                                                       KC_RALT, KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT, KC_P0,            KC_PDOT          ),
};

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(0, RGB_RED);
				rgb_matrix_set_color(1, RGB_RED);
				rgb_matrix_set_color(2, RGB_RED);
				rgb_matrix_set_color(3, RGB_RED);
				rgb_matrix_set_color(4, RGB_RED);
                rgb_matrix_set_color(5, RGB_RED);

            }
        }
    }
}
  #endif

