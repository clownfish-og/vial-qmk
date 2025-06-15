// Copyright (C) 2025 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "25.h"

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
    if (!rgb_matrix_indicators_user()) {  // allow user function to run ( __attribute__((weak)) )
        return false;
    }

    //  Define an assortment of HSV values for indicators and convert HSV to RGB (important for limiting brightness with WS2812)
    //                                 .h   .s    .v
    rgb_t magenta = hsv_to_rgb((hsv_t){200, 255, 200});                   // MAGENTA
    rgb_t cyan    = hsv_to_rgb((hsv_t){128, 255, 200});                   // CYAN
    rgb_t blue    = hsv_to_rgb((hsv_t){170, 255, 200});                   // BLUE
    rgb_t blue_v  = hsv_to_rgb((hsv_t){170, 255, rgb_matrix_get_val()});  // BLUE - BRIGHTNESS VARIES
    rgb_t green   = hsv_to_rgb((hsv_t){85,  255, 200});                   // GREEN
    rgb_t green_v = hsv_to_rgb((hsv_t){85,  255, rgb_matrix_get_val()});  // GREEN - BRIGHTNESS VARIES
    rgb_t yellow  = hsv_to_rgb((hsv_t){43,  255, 200});                   // YELLOW
    rgb_t red     = hsv_to_rgb((hsv_t){0,   255, 200});                   // RED
    rgb_t red_v   = hsv_to_rgb((hsv_t){0,   255, rgb_matrix_get_val()});  // RED - BRIGHTNESS VARIES
    rgb_t white   = hsv_to_rgb((hsv_t){0,   0,   200});                   // WHITE
    rgb_t white_v = hsv_to_rgb((hsv_t){0,   0,   rgb_matrix_get_val()});  // WHITE - BRIGHTNESS VARIES

        // Determine the active layer
        uint8_t active_layer = get_highest_layer(layer_state);

        if (!rgb_matrix_get_flags()) {  // RGB is toggled off
            rgb_matrix_set_color_all(RGB_BLACK);
        }

    /*
    keylight LED index to position legend
    -----------------------
    | 20 |21 |22 |23 | 24 |
    -----------------------
    | 19 | 6 | 7 | 8 | 9  |
    -----------------------
    | 18 | 5 | 0 | 1 | 10 |
    -----------------------
    | 17 | 4 | 3 | 2 | 11 |
    -----------------------
    | 16 |15 |14 |13 | 12 |
    -----------------------
    */

    // Set indicator LEDs
    switch (active_layer) {
        case 0:
            rgb_matrix_set_color(20, magenta.r, magenta.g, magenta.b);  // TO(1) MAGENTA
            break;
        case 1:
            rgb_matrix_set_color(21, cyan.r, cyan.g, cyan.b);  // TO(5) CYAN
            break;
        case 2:
            rgb_matrix_set_color(22, blue.r, blue.g, blue.b);  // TO(5) BLUE
            break;
        case 3:
            rgb_matrix_set_color(23, green.r, green.g, green.b);  // TO(5) GREEN
            break;
        case 4:
            rgb_matrix_set_color(24, yellow.r, yellow.g, yellow.b);  // TO(5) YELLOW
            break;
        case 5:                                             // RGB SETTINGS LAYER
            rgb_matrix_set_color(16, red_v.r, red_v.g, red_v.b);  // TT(6) RED - BRIGHTNESS VARIES
            rgb_matrix_set_color(20, red.r,   red.g,   red.b);     // TOP ROW RED
            rgb_matrix_set_color(21, red.r,   red.g,   red.b);     // TOP ROW RED
            rgb_matrix_set_color(22, red.r,   red.g,   red.b);     // TOP ROW RED
            rgb_matrix_set_color(23, red.r,   red.g,   red.b);     // TOP ROW RED
            rgb_matrix_set_color(24, red.r,   red.g,   red.b);     // TOP ROW RED
            break;
        case 6:                                             // NUMPAD LAYER
            if (!host_keyboard_led_state().num_lock) {          // NUMLOCK OFF
                rgb_matrix_set_color_all(blue_v.r,  blue_v.g,  blue_v.b);  // ALL BLUE - BRIGHTNESS VARIES
                rgb_matrix_set_color(21, white.r,   white.g,   white.b);     // NUMLOCK WHITE
                rgb_matrix_set_color(1,  green_v.r, green_v.g, green_v.b);   // ARROW KEYS GREEN
                rgb_matrix_set_color(3,  green_v.r, green_v.g, green_v.b);   // ARROW KEYS GREEN
                rgb_matrix_set_color(5,  green_v.r, green_v.g, green_v.b);   // ARROW KEYS GREEN
                rgb_matrix_set_color(7,  green_v.r, green_v.g, green_v.b);   // ARROW KEYS GREEN
                rgb_matrix_set_color(20, magenta.r, magenta.g, magenta.b);   // TO(0) MAGENTA
                rgb_matrix_set_color(19, RGB_BLACK);                  // LEFT COLUMN BLACK
                rgb_matrix_set_color(18, RGB_BLACK);                  // LEFT COLUMN BLACK
                rgb_matrix_set_color(17, RGB_BLACK);                  // LEFT COLUMN BLACK
                rgb_matrix_set_color(16, red_v.r,   red_v.g,   red_v.b);  // TT(6) RED - BRIGHTNESS VARIES
            } else {                                            // NUMLOCK ON
                rgb_matrix_set_color_all(white_v.r, white_v.g, white_v.b);  // ALL WHITE - BRIGHTNESS VARIES
                rgb_matrix_set_color(21, blue.r,    blue.g,    blue.b);     // NUMLOCK BLUE
                rgb_matrix_set_color(20, magenta.r, magenta.g, magenta.b);  // TO(0) MAGENTA
                rgb_matrix_set_color(19, RGB_BLACK);                  // LEFT COLUMN BLACK
                rgb_matrix_set_color(18, RGB_BLACK);                  // LEFT COLUMN BLACK
                rgb_matrix_set_color(17, RGB_BLACK);                  // LEFT COLUMN BLACK
                rgb_matrix_set_color(16, red_v.r,   red_v.g,   red_v.b);  // TT(6) RED - BRIGHTNESS VARIES
            }
            break;
        case 7:
            rgb_matrix_set_color(20, magenta.r, magenta.g, magenta.b);  // TO(0) MAGENTA
            rgb_matrix_set_color(21, green.r,   green.g,   green.b);  // TOP ROW GREEN
            rgb_matrix_set_color(22, green.r,   green.g,   green.b);  // TOP ROW GREEN
            rgb_matrix_set_color(23, green.r,   green.g,   green.b);  // TOP ROW GREEN
            rgb_matrix_set_color(24, green.r,   green.g,   green.b);  // TOP ROW GREEN
            break;
        default:
            rgb_matrix_set_color_all(RGB_BLACK);
            break;
    }
    return false;
}

#endif
