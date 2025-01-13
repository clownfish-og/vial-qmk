// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) { return false; }
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
    }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    hsv_t hsv = {0, 255, 200};

    uint8_t active_layer = get_highest_layer(layer_state);

    switch (active_layer) {
        case 0:
            hsv = (hsv_t){0, 0, 100}; // Layer 0: WHITE
            break;
        case 1:
            hsv = (hsv_t){85, 255, 100}; // Layer 1: GREEN
            break;
        case 2:
            hsv = (hsv_t){169, 255, 100}; // Layer 2: BLUE
            break;
        case 3:
            hsv = (hsv_t){30, 255, 100}; // Layer 3: YELLOW
            break;
        default:
            hsv = (hsv_t){0, 255, 100}; // err: RED
            break;
    }

    hsv.v = (rgb_matrix_get_val() >= 100) ? 100 : (rgb_matrix_get_val() <= 30) ? 30 : rgb_matrix_get_val();
    rgb_t rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(9, rgb.r, rgb.g, rgb.b);
    return false;
}
    return false;
}

#endif

enum custom_keycodes {
    SIMPLGT = QK_KB_0,
    PROJECT,
    CHROME
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SIMPLGT:
            if (record->event.pressed) {
                switch(rgb_matrix_get_mode()) {
                    case RGB_MATRIX_GRADIENT_UP_DOWN:
                        rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
                        rgb_matrix_sethsv(180, 255, 200);
                        break;
                    case RGB_MATRIX_SOLID_COLOR:
                        rgb_matrix_mode(RGB_MATRIX_BREATHING);
                        rgb_matrix_sethsv(180, 255, 200);
                        break;
                    case RGB_MATRIX_BREATHING:
                        rgb_matrix_mode(RGB_MATRIX_DUAL_BEACON);
                        rgb_matrix_sethsv(127, 255, 200);
                        break;
                    case RGB_MATRIX_DUAL_BEACON:
                        rgb_matrix_mode(RGB_MATRIX_GRADIENT_UP_DOWN);
                        rgb_matrix_sethsv(52, 255, 200);
                        break;
                    default:
                        rgb_matrix_mode(RGB_MATRIX_DUAL_BEACON);
                        rgb_matrix_sethsv(127, 255, 200);
                        break;
                    }
            }
            return false;
        case PROJECT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("P") SS_DELAY(400) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(200) SS_TAP(X_ENT) SS_DELAY(200) SS_TAP(X_ESC) );
            }
            return false;
        case CHROME:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(" ") SS_DELAY(150) ">chrome.exe" SS_DELAY(150) SS_TAP(X_ENT));
            }
            return false;
        default:
        return true; // Process all other keycodes normally
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TO(1),   UG_HUEU,  SIMPLGT,  UG_SATU,   KC_RSFT
    ),
    [1] = LAYOUT(
        TO(2),   KC_ENT,   C(KC_C), C(S(KC_V)), C(KC_Z)
    ),
    [2] = LAYOUT(
        TO(3),   CHROME,   UG_TOGG,  G(KC_D),   PROJECT
    ),
    [3] = LAYOUT(
        TO(0),   KC_WBAK,  KC_WHOM,  KC_WFWD,   KC_MPLY
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_PREV, UG_NEXT) },
    [1] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D) },
    [2] = { ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_MRWD, KC_MFFD),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif
