/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include <lib/lib8tion/lib8tion.h>

#ifdef RGB_MATRIX_ENABLE

// Single Indicator memory layout
typedef struct indicator_t {
        uint8_t cap_h;
        uint8_t num_h;
        uint8_t com_h;
        uint8_t cap_s;
        uint8_t num_s;
        uint8_t com_s;
    } indicator;

indicator indi;

// Check if the size of the reserved persistent memory is the same as the size of struct indicator
_Static_assert(sizeof(indicator) == EECONFIG_KB_DATA_SIZE, "Mismatch in keyboard EECONFIG stored data");

void eeconfig_init_kb(void) {
    // Default values
    indi.cap_h = 168;
    indi.num_h = 0;
    indi.com_h = 184;
    indi.cap_s = 255;
    indi.num_s = 0;
    indi.com_s = 255;
    eeconfig_update_kb_datablock(&indi);
}

// Initialize the EEPROM values
void keyboard_post_init_kb(void) {
eeconfig_read_kb_datablock(&indi);
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
        }
    HSV hsv;
    if (host_keyboard_led_state().caps_lock && !host_keyboard_led_state().num_lock) {
        hsv.h = indi.com_h;
        hsv.s = indi.com_s;
        hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
    } else if (!host_keyboard_led_state().num_lock) {
        hsv.h = indi.num_h;
        hsv.s = indi.num_s;
        hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
    } else if (host_keyboard_led_state().caps_lock) {
        hsv.h = indi.cap_h;
        hsv.s = indi.cap_s;
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
        if (HAS_FLAGS(g_led_config.flags[i], 0x08)) { // 0x08 == LED_FLAG_INDICATOR
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return true;
}
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
        }

    bool shifted = get_mods() & MOD_MASK_SHIFT;
    uint8_t sat_step = RGB_MATRIX_SAT_STEP;
    uint8_t hue_step = RGB_MATRIX_HUE_STEP;

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
                    indi.cap_s = qadd8(indi.cap_s, sat_step);
                } else {
                    if (indi.cap_s == 0) {
                        indi.cap_s = 255;
                    }
                    indi.cap_h = (indi.cap_h + hue_step);
                }
                eeconfig_update_kb_datablock(&indi);
            }
            return false;
        case CAPSLKD:
            if (record->event.pressed) {
                if (shifted) {
                    indi.cap_s = qsub8(indi.cap_s, sat_step);
                } else {
                    if (indi.cap_s == 0) {
                        indi.cap_s = 255;
                    }
                    indi.cap_h = (indi.cap_h - hue_step);
                }
                eeconfig_update_kb_datablock(&indi);
            }
            return false;
        case NUMLKOU:
            if (record->event.pressed) {
                if (shifted) {
                    indi.num_s = qadd8(indi.num_s, sat_step);
                } else {
                    if (indi.num_s == 0) {
                        indi.num_s = 255;
                    }
                    indi.num_h = (indi.num_h + hue_step);
                }
                eeconfig_update_kb_datablock(&indi);
            }
            return false;
        case NUMLKOD:
            if (record->event.pressed) {
                if (shifted) {
                    indi.num_s = qsub8(indi.num_s, sat_step);
                } else {
                    if (indi.num_s == 0) {
                        indi.num_s = 255;
                    }
                    indi.num_h = (indi.num_h - hue_step);
                }
                eeconfig_update_kb_datablock(&indi);
            }
            return false;
        case COMBLKU:
            if (record->event.pressed) {
                if (shifted) {
                    indi.com_s = qadd8(indi.com_s, sat_step);
                } else {
                    if (indi.com_s == 0) {
                        indi.com_s = 255;
                    }
                    indi.com_h = (indi.com_h + hue_step);
                }
                eeconfig_update_kb_datablock(&indi);
            }
            return false;
        case COMBLKD:
            if (record->event.pressed) {
                if (shifted) {
                    indi.com_s = qsub8(indi.com_s, sat_step);
                } else {
                    if (indi.com_s == 0) {
                        indi.com_s = 255;
                    }
                    indi.com_h = (indi.com_h - hue_step);
                }
                eeconfig_update_kb_datablock(&indi);
            }
            return false;
    }
        return true;
}
#endif
