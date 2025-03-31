/* Copyright 2024 ClownFish (@clownfish-og)
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
#include <ctype.h>
#include "keymap.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(  // wertyoo commands
        TO(1),   TO(2),   KC_NO,   KC_NO,   HEARTBEAT,
        MAINSC,  WELCOME, BRB,     SMALL,   VINYL,
        NEW,     SLOTHS,  GYPSY,   NINJA,   STRAT,
        _JAMMIN, _GLUTES, _WIGGLE, _CLNFSH, _BONGO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENT
    ),
    [1] = LAYOUT(  // wertyoo emotes
        TO(0),   TO(2),   TO(3),   TO(4),   APPROVE,
        AYO,     BONGO,   CHEF,    COOL,    CLOWNFISH,
        DOIT,    DANCE,   EXCITE,  GIFT,    GLUTES,
        HIYA,    HORN,    HUG,     HYPE,    JAMMIN,
        WIGGLE,  FIRES,   GRIN,    WAVE,    KC_ENT
    ),
    [2] = LAYOUT(
        TO(0),    TO(1),     TO(3),    TO(4),      BOP,
        BOPBOP,   DINODANCE, GLITCHLIT,GOATEMOTEY, GOLDPLZ,
        KAPPA,    KREYGASM,  MODLOVE,  NOTLIKETHIS,STINKYCHEESE,
        POWERUPL, POWERUPR,  SINGSMIC, SINGSNOTE,  TWITCHCONHYPE,
        TOMBRAID, TWITCHRAID,TWITCHLIT,UNITY,      KC_ENT
    ),
    [3] = LAYOUT(  // RGB settings
        TO(0),   TO(1),   TO(2),   TO(4),   KC_NO,
        UG_NEXT, UG_VALU, UG_HUEU, UG_SATU, UG_SPDU,
        UG_PREV, UG_VALD, UG_HUED, UG_SATD, UG_SPDD,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        RMAM,    RMPL,    RMSW,    KC_NO,   UG_TOGG
    ),
    [4] = LAYOUT(  // Numpad
        TO(0),   KC_NUM,  KC_PSLS, KC_PAST, KC_BSPC,
        TO(1),   KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        TO(2),   KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        TO(3),   KC_P1,   KC_P2,   KC_P3,   KC_NO,
        KC_TRNS, KC_P0,   KC_P0,   KC_PDOT, KC_PENT
    ),
};

const char *strings[] = {
    "BOP ",
    "BopBop ",
    "DinoDance ",
    "GlitchLit ",
    "GoatEmotey ",
    "GoldPLZ ",
    "Kappa ",
    "Kreygasm ",
    "ModLove ",
    "NotLikeThis ",
    "PowerUpL ",
    "PowerUpR ",
    "SingsMic ",
    "SingsNote ",
    "StinkyCheese ",
    "TombRaid ",
    "TwitchConHYPE ",
    "TwitchLit ",
    "twitchRaid ",
    "TwitchUnity ",
    "wertyo2Approve ",
    "wertyo2Ayo ",
    "wertyo2Bongo ",
    "wertyo2ChefsKiss ",
    "wertyo2Clownfish ",
    "wertyo2Cool ",
    "wertyo2DOIT ",
    "wertyo2Dance ",
    "wertyo2Excite ",
    "wertyo2Gift ",
    "wertyo2Glutes ",
    "wertyo2Heartbeat ",
    "wertyo2Hiya ",
    "wertyo2Horn ",
    "wertyo2Hug ",
    "wertyo2Hype ",
    "wertyo2Jammin ",
    "wertyo2Wiggle ",
    "wertyo2FireSauce ",
    "wertyo2Grin ",
    "wertyo2Heart ",
    "wertyo2Tune ",
    "wertyo2Wave ",
    "!main",
    "!welcome",
    "!break",
    "!small",
    "!vinyl",
    "!newvisual",
    "!sloths",
    "!gypsy",
    "!ninja",
    "!stratus",
    "!jammin",
    "!glutes",
    "!wiggle",
    "!clownfish",
    "!bongo"
};

// This function inverts the capitalization of each character in the given string.
void invert_caps(char *str) {
    while (*str) {
        if (islower(*str)) {
            *str = toupper(*str);
        } else if (isupper(*str)) {
            *str = tolower(*str);
        }
        str++;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case FIRST_EMOTE ... LAST_CMD: {
                uint8_t i = keycode - FIRST_EMOTE;
                bool caps = host_keyboard_led_state().caps_lock;
                char emote_buffer[36];
                emote_buffer[0] = '\0';
                strncpy(emote_buffer, (strings[i]), sizeof(emote_buffer) - 1);
                if (caps) {
                    invert_caps(emote_buffer);
                }
                send_string(emote_buffer);
                if (FIRST_CMD <= keycode && keycode <= LAST_CMD) {
                    SEND_STRING("\n");
                }
                return false;
            }
        }
    }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    //  Define an assortment of HSV values for indicators and convert HSV to RGB (important for limiting brightness with WS2812)
    rgb_t rgb0 = hsv_to_rgb((hsv_t){200, 255, 200});                    // MAGENTA
    rgb_t rgb1 = hsv_to_rgb((hsv_t){85, 255, 200});                     // GREEN
    rgb_t rgb1v = hsv_to_rgb((hsv_t){85, 255, rgb_matrix_get_val()});   // GREEN - BRIGHTNESS VARIES
    rgb_t rgb2 = hsv_to_rgb((hsv_t){170, 255, 200});                    // BLUE
    rgb_t rgb2v = hsv_to_rgb((hsv_t){170, 255, rgb_matrix_get_val()});  // BLUE - BRIGHTNESS VARIES
    rgb_t rgb3 = hsv_to_rgb((hsv_t){0, 255, 200});                      // RED
    rgb_t rgb4 = hsv_to_rgb((hsv_t){0, 0, 200});                        // WHITE
    rgb_t rgb4v = hsv_to_rgb((hsv_t){0, 0, rgb_matrix_get_val()});      // WHITE - BRIGHTNESS VARIES

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
    for (uint8_t i = led_min; i < led_max; i++) {
        switch (active_layer) {
            case 0:
                rgb_matrix_set_color(20, rgb1.r, rgb1.g, rgb1.b);     // TO(1) GREEN
                rgb_matrix_set_color(21, rgb2.r, rgb2.g, rgb2.b);     // TO(2) BLUE
                break;
            case 1:
                rgb_matrix_set_color(20, rgb0.r, rgb0.g, rgb0.b);     // TO(0) MAGENTA
                rgb_matrix_set_color(21, rgb2.r, rgb2.g, rgb2.b);     // TO(2) BLUE
                rgb_matrix_set_color(22, rgb3.r, rgb3.g, rgb3.b);     // TO(3) RED
                rgb_matrix_set_color(23, rgb4.r, rgb4.g, rgb4.b);     // TO(4) WHITE
                rgb_matrix_set_color(12, rgb1.r, rgb1.g, rgb1.b);     // BOTTOM ROW GREEN
                rgb_matrix_set_color(13, rgb1.r, rgb1.g, rgb1.b);     // BOTTOM ROW GREEN
                rgb_matrix_set_color(14, rgb1.r, rgb1.g, rgb1.b);     // BOTTOM ROW GREEN
                rgb_matrix_set_color(15, rgb1.r, rgb1.g, rgb1.b);     // BOTTOM ROW GREEN
                rgb_matrix_set_color(16, rgb1.r, rgb1.g, rgb1.b);     // BOTTOM ROW GREEN
                break;
            case 2:
                rgb_matrix_set_color(20, rgb0.r, rgb0.g, rgb0.b);     // TO(0) MAGENTA
                rgb_matrix_set_color(21, rgb1.r, rgb1.g, rgb1.b);     // TO(1) GREEN
                rgb_matrix_set_color(22, rgb3.r, rgb3.g, rgb3.b);     // TO(3) RED
                rgb_matrix_set_color(23, rgb4.r, rgb4.g, rgb4.b);     // TO(4) WHITE
                rgb_matrix_set_color(12, rgb2.r, rgb2.g, rgb2.b);     // BOTTOM ROW BLUE
                rgb_matrix_set_color(13, rgb2.r, rgb2.g, rgb2.b);     // BOTTOM ROW BLUE
                rgb_matrix_set_color(14, rgb2.r, rgb2.g, rgb2.b);     // BOTTOM ROW BLUE
                rgb_matrix_set_color(15, rgb2.r, rgb2.g, rgb2.b);     // BOTTOM ROW BLUE
                rgb_matrix_set_color(16, rgb2.r, rgb2.g, rgb2.b);     // BOTTOM ROW BLUE
                break;
            case 3:                                             // RGB SETTINGS LAYER
                rgb_matrix_set_color(20, rgb0.r, rgb0.g, rgb0.b);     // TO(0) MAGENTA
                rgb_matrix_set_color(21, rgb1.r, rgb1.g, rgb1.b);     // TO(1) GREEN
                rgb_matrix_set_color(22, rgb2.r, rgb2.g, rgb2.b);     // TO(2) BLUE
                rgb_matrix_set_color(23, rgb4.r, rgb4.g, rgb4.b);     // TO(4) WHITE
                rgb_matrix_set_color(12, rgb3.r, rgb3.g, rgb3.b);     // BOTTOM ROW RED
                rgb_matrix_set_color(13, rgb3.r, rgb3.g, rgb3.b);     // BOTTOM ROW RED
                rgb_matrix_set_color(14, rgb3.r, rgb3.g, rgb3.b);     // BOTTOM ROW RED
                rgb_matrix_set_color(15, rgb3.r, rgb3.g, rgb3.b);     // BOTTOM ROW RED
                rgb_matrix_set_color(16, rgb3.r, rgb3.g, rgb3.b);     // BOTTOM ROW RED
                break;
            case 4:                                             // NUMPAD LAYER
                if (!host_keyboard_led_state().num_lock) {          // NUMLOCK OFF
                    rgb_matrix_set_color_all(rgb2v.r, rgb2v.g, rgb2v.b);  // ALL BLUE - BRIGHTNESS VARIES
                    rgb_matrix_set_color(21, rgb4.r, rgb4.g, rgb4.b);     // NUMLOCK WHITE
                    rgb_matrix_set_color(1, rgb1v.r, rgb1v.g, rgb1v.b);   // ARROW KEYS GREEN
                    rgb_matrix_set_color(3, rgb1v.r, rgb1v.g, rgb1v.b);   // ARROW KEYS GREEN
                    rgb_matrix_set_color(5, rgb1v.r, rgb1v.g, rgb1v.b);   // ARROW KEYS GREEN
                    rgb_matrix_set_color(7, rgb1v.r, rgb1v.g, rgb1v.b);   // ARROW KEYS GREEN
                    rgb_matrix_set_color(20, rgb0.r, rgb0.g, rgb0.b);     // TO(0) MAGENTA
                    rgb_matrix_set_color(19, rgb1.r, rgb1.g, rgb1.b);     // TO(1) GREEN
                    rgb_matrix_set_color(18, rgb2.r, rgb2.g, rgb2.b);     // TO(2) BLUE
                    rgb_matrix_set_color(17, rgb3.r, rgb3.g, rgb3.b);     // TO(3) RED
                    rgb_matrix_set_color(16, RGB_BLACK);                  // BOTTOM LEFT BLACK
                } else {                                            // NUMLOCK ON
                    rgb_matrix_set_color_all(rgb4v.r, rgb4v.g, rgb4v.b);  // ALL WHITE - BRIGHTNESS VARIES
                    rgb_matrix_set_color(21, rgb2.r, rgb2.g, rgb2.b);  // NUMLOCK BLUE
                    rgb_matrix_set_color(20, rgb0.r, rgb0.g, rgb0.b);     // TO(0) MAGENTA
                    rgb_matrix_set_color(19, rgb1.r, rgb1.g, rgb1.b);     // TO(1) GREEN
                    rgb_matrix_set_color(18, rgb2.r, rgb2.g, rgb2.b);     // TO(2) BLUE
                    rgb_matrix_set_color(17, rgb3.r, rgb3.g, rgb3.b);     // TO(3) RED
                    rgb_matrix_set_color(16, RGB_BLACK);                  // BOTTOM LEFT BLACK
                }
                break;
            default:
                rgb_matrix_set_color_all(RGB_BLACK);
                break;
        }
    }
    return false;
}

#ifndef MAGIC_ENABLE
uint8_t mod_config(uint8_t mod) {
    return mod;
}
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
#endif
