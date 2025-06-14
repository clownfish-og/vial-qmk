// Copyright (C) 2024 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later


#include "quantum.h"
#include "09.h"

#ifdef RGB_MATRIX_ENABLE
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case QK_UNDERGLOW_TOGGLE:  // Allow indicator LED function when RGB is toggled off
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
        case RMPL:  // Set RGB to solid_color
            if (record->event.pressed) {
                if (rgb_matrix_is_enabled()) rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
        case RMAM:  // Set RGB to alphas_mods
            if (record->event.pressed) {
                if (rgb_matrix_is_enabled()) rgb_matrix_mode(RGB_MATRIX_ALPHAS_MODS);
            }
            return false;
        case RMSW:  // Set RGB to cycle_spiral
            if (record->event.pressed) {
                if (rgb_matrix_is_enabled()) rgb_matrix_mode(RGB_MATRIX_CYCLE_SPIRAL);
            }
            return false;
        case CAPGEN5:  // Select all, copy, paste 5x
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("acvvvvv"));
                return false;
            }
        case CAPGEN8:  // Select all, copy, paste 8x
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("acvvvvvvvv"));
                return false;
            }
        case CAPGEN10:  // Select all, copy, paste 10x
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("acvvvvvvvvvv"));
                return false;
            }
    }
    return true;
}

bool rgb_matrix_indicators_kb() {
    if (!rgb_matrix_indicators_user()) {
        return false;
        }

    hsv_t hsv = {0, 255, 200};

// Determine the active layer
    uint8_t active_layer = get_highest_layer(layer_state);

// Set HSV values based on the active layer
    switch (active_layer) {
        case 0:
            hsv = (hsv_t){200, 255, 200}; // Layer 4: MAGENTA
            break;
        case 1:
            hsv = (hsv_t){128, 255, 200}; // Layer 0: CYAN
            break;
        case 2:
            hsv = (hsv_t){170, 255, 200}; // Layer 2: BLUE
            break;
        case 3:
            hsv = (hsv_t){85, 255, 200}; // Layer 1: GREEN
            break;
        case 4:
            hsv = (hsv_t){0, 0, 200}; // Layer 3: WHITE
            break;
        case 5:
            hsv = (hsv_t){0, 255, 200}; // Layer 5: RED
            break;
        default:
            hsv = (hsv_t){43, 255, 200}; // err: YELLOW
            break;
    }
// Ensure value (brightness) consistency within range
    if (rgb_matrix_get_val() <= 100) {
        hsv.v = 100;
    } else {
        hsv.v = rgb_matrix_get_val();
    }
// Convert HSV to RGB
    rgb_t rgb = hsv_to_rgb(hsv);
// Set top left LED
    rgb_matrix_set_color(4, rgb.r, rgb.g, rgb.b);
    return false;
}

#endif  // RGB_MATRIX_ENABLE
