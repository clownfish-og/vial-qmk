/* Copyright 2022 DOIO
 * Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
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

// OLED animation
#include "lib/layer_status/layer_status.h"

// Mac Keycodes
#include "lib/mac/mac_codes.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum my_layers {
    NUM,
    WIN,
    WIN_FN,
    MAC,
    MAC_FN,
    MEDIA,
    BROWSER,
    DISCORD,
    MOUSE,
    GAME,
    GAME_FN,
    LIGHT
};
enum my_keycodes {
    DBL_0 = NEW_SAFE_RANGE,
    ALT_TAB,
    EXTEND,
    SIMPLGT
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  NUM
       ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
       │ 7 │ 8 │ 9 │ 4 │   │Ply│ │TO1│
       ├───┼───┼───┼───┤   └───┘ └───┘
       │ 4 │ 5 │ 6 │ 8 │
       ├───┼───┼───┼───┤
       │ 1 │ 2 │ ↑ │Ent│      ┌───┐
       ├───┼───┼───┼───┤      │Mute
       │Fn2│ ← │ ↓ │ → │      └───┘
       └───┴───┴───┴───┘
       ┌────┬────┬────┬────┐  LIGHT|WIN       WHL↑|WHL↓
       │ 7  │ 8  │ 9  │Num │    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │MS 3│
       │ 4  │ 5  │ 6  │ -  │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │ 1  │ 2  │ 3  │ +  │          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │ 0  │ 00 │ .  │Ent │           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [NUM] = LAYOUT(
                KC_P7,    KC_P8,    KC_P9,    KC_NUM,   RM_TOGG,
                KC_P4,    KC_P5,    KC_P6,    KC_PMNS,  MS_BTN3,
                KC_P1,    KC_P2,    KC_P3,    KC_PPLS,  KC_MUTE,
                KC_P0,    DBL_0,    KC_PDOT,  KC_ENT
            ),

/*  WIN
       ┌────┬────┬────┬────┐    NUM|MAC       WHL↑|WHL↓
       │Esc │Copy│Pste│Bksp│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │MS 3│
       │ATab│Tab │ ↑  │Ent │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │Shft│ ←  │ ↓  │ →  │          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │Ctrl│Win │Alt │ Fn │           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [WIN] = LAYOUT(
                KC_ESC,  C(KC_C), C(KC_V), KC_BSPC, RM_TOGG,
                ALT_TAB, KC_TAB,  KC_UP,   KC_ENT,  MS_BTN3,
                KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE,
                KC_LCTL, KC_LGUI, KC_LALT, MO(WIN_FN)
            ),

/*  WIN_FN
       ┌────┬────┬────┬────┐    NUM|MAC      Scrn-|Scrn+
       │Dktp│Cut │Undo│Sett│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │Ext │
       │Calc│Expl│Max │Actn│    └────┘         └────┘
       ├────┼────┼────┼────┤
       │SSht│Zon-│Min │Zon+│          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │VDT-│nVDT│VDT+│ ▼  │           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [WIN_FN] = LAYOUT(
                G(KC_D),       C(KC_X),    C(KC_Z),       G(KC_I),    _______,
                KC_CALC,       G(KC_E),    G(S(KC_UP)),   G(KC_A),    EXTEND,
                G(S(KC_S)),    G(KC_LEFT), G(S(KC_DOWN)), G(KC_RGHT), _______,
                G(C(KC_LEFT)), G(C(KC_D)), G(C(KC_RGHT)), _______
            ),

/*  MAC
       ┌────┬────┬────┬────┐    WIN|MEDIA     WHL↑|WHL↓
       │Esc │Copy│Pste│Bksp│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │MS 3│
       │ATab│Tab │ ↑  │Ent │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │Shft│ ←  │ ↓  │ →  │          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │Ctrl│Win │Alt │ Fn │           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [MAC] = LAYOUT(
                KC_ESC,  G(KC_C), G(KC_V), KC_BSPC, RM_TOGG,
                ALT_TAB, KC_TAB,  KC_UP,   KC_ENT,  MS_BTN3,
                KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE,
                KC_LCTL, KC_LOPT, KC_LCMD, MO(MAC_FN)
            ),

/*  MAC_FN
       ┌────┬────┬────┬────┐    WIN|MEDIA    Scrn-|Scrn+
       │Dktp│Cut │Undo│Sptl│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │MS 3│
       │Wndw│Lpad│ZonT│MCtl│    └────┘         └────┘
       ├────┼────┼────┼────┤
       │SSht│ZonL│Min │ZonR│          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │VDT-│nVDT│VDT+│ ▼  │           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [MAC_FN] = LAYOUT(
                G(A(KC_M)),    G(KC_X),       G(KC_Z),       G(A(KC_SPC)),  _______,
                G(KC_GRV),     KC_LPAD,       C(A(KC_UP)),   KC_MCTL,       _______,
                G(S(KC_4)),    C(A(KC_LEFT)), G(KC_M),       C(A(KC_LEFT)), _______,
                C(KC_LEFT),    C(KC_UP),      C(KC_RGHT),    _______
            ),

/*  MEDIA
       ┌────┬────┬────┬────┐    MAC|BROWSER   Prev|Next
       │Stop│Play│Prev│Next│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │Play│
       │Vol+│ RW │ ↑  │ FF │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │Vol-│ ←  │ ↓  │ →  │          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │Mute│Tab │Ejct│Ent │           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [MEDIA] = LAYOUT(
                _______, _______, _______, _______, RM_TOGG,
                _______, _______, _______, _______, KC_MPLY,
                _______, _______, _______, _______, KC_MUTE,
                _______, _______, _______, _______
            ),

/*  BROWSER
       ┌────┬────┬────┬────┐  MEDIA|DISCORD   Back|Fwd
       │ 7  │ 8  │ 9  │Num │    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │Home│
       │ 4  │ 5  │ 6  │ -  │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │ 1  │ 2  │ 3  │ +  │         Tabs-|Tabs+
       ├────┼────┼────┼────┤           ┌────┐
       │ 0  │ 00 │ .  │Ent │           │NTab│
       └────┴────┴────┴────┘           └────┘
*/
    [BROWSER] = LAYOUT(
                _______, _______, _______, _______, RM_TOGG,
                _______, _______, _______, _______, KC_WHOM,
                _______, _______, _______, _______, C(KC_TAB),
                _______, _______, _______, _______
            ),

/*  DISCORD
       ┌────┬────┬────┬────┐BROWSER|MOUSE     WHL↑|WHL↓
       │ 7  │ 8  │ 9  │Num │    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │MS 3│
       │ 4  │ 5  │ 6  │ -  │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │ 1  │ 2  │ 3  │ +  │          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │ 0  │ 00 │ .  │Ent │           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [DISCORD] = LAYOUT(
                _______, _______, _______, _______, RM_TOGG,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______
            ),

/*  MOUSE
       ┌────┬────┬────┬────┐DISCORD|GAME     WHL↑|WHL↓
       │ 7  │ 8  │ 9  │Num │    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │MS 3│
       │ 4  │ 5  │ 6  │ -  │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │ 1  │ 2  │ 3  │ +  │          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │ 0  │ 00 │ .  │Ent │           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [MOUSE] = LAYOUT(
                _______, _______, _______, _______, RM_TOGG,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______
            ),

/*  GAME
       ┌────┬────┬────┬────┐ MOUSE|LIGHT     WHL↑|WHL↓
       │ 7  │ 8  │ 9  │Num │    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │MS 3│
       │ 4  │ 5  │ 6  │ -  │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │ 1  │ 2  │ 3  │ +  │          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │ 0  │ 00 │ .  │Ent │           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [GAME] = LAYOUT(
                _______, _______, _______, _______, RM_TOGG,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______
            ),

/*  GAME_FN
       ┌────┬────┬────┬────┐  MOUSE|LIGHT     WHL↑|WHL↓
       │ 7  │ 8  │ 9  │Num │    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │MS 3│
       │ 4  │ 5  │ 6  │ -  │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │ 1  │ 2  │ 3  │ +  │          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │ 0  │ 00 │ .  │Ent │           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [GAME_FN] = LAYOUT(
                _______, _______, _______, _______, RM_TOGG,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______
            ),

/*  LIGHT
       ┌────┬────┬────┬────┐   GAME|NUM       WHL↑|WHL↓
       │Sat+│Val+│Spd+│Togg│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │    │
       │ 4  │ 5  │ 6  │Ani+│    └────┘         └────┘
       ├────┼────┼────┼────┤
       │ 1  │ 2  │ 3  │Ani-│          Val-|Val+
       ├────┼────┼────┼────┤           ┌────┐
       │ 0  │ 00 │ .  │    │           │    │
       └────┴────┴────┴────┘           └────┘
*/
    [LIGHT] = LAYOUT(
                RM_SATU, RM_VALU, RM_SPDU, RM_TOGG, RM_TOGG,
                RM_HUED, XXXXXXX, RM_HUEU, RM_NEXT, XXXXXXX,
                RM_SATD, RM_VALD, RM_SPDD, RM_PREV, XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
            ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [NUM]      = { ENCODER_CCW_CW(TO(LIGHT),   TO(WIN)),     ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN]      = { ENCODER_CCW_CW(TO(NUM),     TO(MAC)),     ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(_______,     _______),     ENCODER_CCW_CW(KC_BRID, KC_BRIU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC]      = { ENCODER_CCW_CW(TO(WIN),     TO(MEDIA)),   ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(_______,     _______),     ENCODER_CCW_CW(KC_SCRL, KC_PAUS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MEDIA]    = { ENCODER_CCW_CW(TO(MAC),     TO(BROWSER)), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [BROWSER]  = { ENCODER_CCW_CW(TO(MEDIA),   TO(DISCORD)), ENCODER_CCW_CW(KC_WBAK, KC_WFWD), ENCODER_CCW_CW(C(S(KC_TAB)), C(KC_TAB)) },
    [DISCORD]  = { ENCODER_CCW_CW(TO(BROWSER), TO(MOUSE)),   ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [MOUSE]    = { ENCODER_CCW_CW(TO(DISCORD), TO(GAME)),    ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [GAME]     = { ENCODER_CCW_CW(TO(MOUSE),   TO(LIGHT)),   ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [GAME_FN]  = { ENCODER_CCW_CW(_______,     _______),     ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [LIGHT]    = { ENCODER_CCW_CW(TO(GAME),    TO(NUM)),     ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },

};
#endif

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_mac(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case ALT_TAB: // Super ALT↯TAB processing
        if (record->event.pressed) {
            if (!is_alt_tab_active) {
                is_alt_tab_active = true;
                if (get_highest_layer(MAC)) {
                    register_code(KC_LCMD);
                } else {
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
        }
            return false;
        case DBL_0:
            if (record->event.pressed) {
                SEND_STRING_DELAY("00", 50);
            }
            return false;
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
        case EXTEND:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("P") SS_DELAY(400) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(200) SS_TAP(X_ENT) SS_DELAY(200) SS_TAP(X_ESC) );
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) { // Super ALT↯TAB timer
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_layer_status();

        return true;
    }
#endif

void housekeeping_task_user(void) {
    housekeeping_task_mac();
}
