/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#ifdef RGB_MATRIX_ENABLE

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) { return false; }
    switch (keycode) {
        case RGB_TOG:
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
    }
    return true;
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
        }if (host_keyboard_led_state().caps_lock && !host_keyboard_led_state().num_lock) {
                rgb_matrix_set_color_all(RGB_PURPLE);
            }
            else if (!host_keyboard_led_state().num_lock) {
                rgb_matrix_set_color_all(RGB_WHITE);
            }
            else if (host_keyboard_led_state().caps_lock) {
                rgb_matrix_set_color_all(RGB_BLUE);
            }
            else if (!rgb_matrix_get_flags()){
                rgb_matrix_set_color_all(RGB_BLACK);
            }
        return true;
}
  #endif
