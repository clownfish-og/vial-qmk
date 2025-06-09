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
const char *layers[] = {
    "NUMPAD",
    "WINDOWS",
    "WIN_FN",
    "MACOS",
    "MAC_FN",
    "MEDIA",
    "BROWSER",
    "DISCORD",
    "MOUSE",
    "GAME",
    "GAME_FN",
    "LIGHTING"
};

enum my_keycodes {
    DBL_0 = QK_KB,
    ALT_TAB,
    EXTEND,
    SIMPLGT,
    RMD_PLN,
    RMD_BOX,
    RMD_SRL,
    RMD_CENT
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  NUM
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
       ┌────┬────┬────┬────┐    NUM|MAC       Vol-|Vol+
       │Esc │Copy│Pste│Bksp│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │Mute│
       │ATab│Tab │ ↑  │Ent │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │Shft│ ←  │ ↓  │ →  │          WHL↑|WHL↓
       ├────┼────┼────┼────┤           ┌────┐
       │Ctrl│Win │Alt │ Fn │           │MS 3│
       └────┴────┴────┴────┘           └────┘
*/
    [WIN] = LAYOUT(
                KC_ESC,  C(KC_C), C(KC_V), KC_BSPC, RM_TOGG,
                ALT_TAB, KC_TAB,  KC_UP,   KC_ENT,  KC_MUTE,
                KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, MS_BTN3,
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
                G(KC_D),       C(KC_X),    C(KC_Z),       G(KC_I),    RM_TOGG,
                KC_CALC,       G(KC_E),    G(S(KC_UP)),   G(KC_A),    EXTEND,
                G(S(KC_S)),    G(KC_LEFT), G(S(KC_DOWN)), G(KC_RGHT), KC_MUTE,
                G(C(KC_LEFT)), G(C(KC_D)), G(C(KC_RGHT)), KC_TRNS
            ),

/*  MAC
       ┌────┬────┬────┬────┐    WIN|MEDIA     Vol-|Vol+
       │Esc │Copy│Pste│Bksp│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │Mute│
       │ATab│Tab │ ↑  │Ent │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │Shft│ ←  │ ↓  │ →  │          WHL↑|WHL↓
       ├────┼────┼────┼────┤           ┌────┐
       │Ctrl│Win │Alt │ Fn │           │MS 3│
       └────┴────┴────┴────┘           └────┘
*/
    [MAC] = LAYOUT(
                KC_ESC,  G(KC_C), G(KC_V), KC_BSPC, RM_TOGG,
                ALT_TAB, KC_TAB,  KC_UP,   KC_ENT,  KC_MUTE,
                KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, MS_BTN3,
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
                G(A(KC_M)),    G(KC_X),       G(KC_Z),       G(A(KC_SPC)),  RM_TOGG,
                G(KC_GRV),     KC_LPAD,       C(A(KC_UP)),   KC_MCTL,       MS_BTN3,
                G(S(KC_4)),    C(A(KC_LEFT)), G(KC_M),       C(A(KC_LEFT)), KC_MUTE,
                C(KC_LEFT),    C(KC_UP),      C(KC_RGHT),    KC_TRNS
            ),

/*  MEDIA
       ┌────┬────┬────┬────┐    MAC|BROWSER   Prev|Next
       │Esc │Tab │Stop│MPlr│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │Play│
       │Ejct│ RW │ ↑  │ FF │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │Ent │ ←  │ ↓  │ →  │          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │Spce│Prev│Play│Next│           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [MEDIA] = LAYOUT(
                KC_ESC,  KC_TAB,  KC_MSTP, KC_MSEL, RM_TOGG,
                KC_EJCT, KC_MRWD, KC_UP,   KC_MFFD, KC_MPLY,
                KC_ENT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE,
                KC_SPC,  KC_MPRV, KC_MPLY, KC_MNXT
            ),

/*  BROWSER
       ┌────┬────┬────┬────┐  MEDIA|DISCORD   Back|Fwd
       │Home│Srch│Favs│Find│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │Home│
       │Refr│FlSc│Srce│DVew│    └────┘         └────┘
       ├────┼────┼────┼────┤
       │Refr│Stop│Back│Fwd │         Tabs-|Tabs+
       ├────┼────┼────┼────┤           ┌────┐
       │nTab│nWin│Addr│rTab│           │NTab│
       └────┴────┴────┴────┘           └────┘
*/
    [BROWSER] = LAYOUT(
                KC_WHOM, KC_WSCH, KC_WFAV, C(KC_F), RM_TOGG,
                KC_F5,   KC_F11,  C(KC_U), KC_F12,  KC_WHOM,
                KC_WREF, KC_WSTP, KC_WBAK, KC_WFWD, C(KC_TAB),
                C(KC_T), C(KC_N), KC_F6,   C(S(KC_T))
            ),

/*  DISCORD
       ┌────┬────┬────┬────┐BROWSER|MOUSE     Vol-|Vol+
       │Esc │Reac│DMs │Unrd│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │Mute│
       │Svr-│Ch- │ChU-│PgUp│    └────┘         └────┘
       ├────┼────┼────┼────┤
       │Svr+│Ch+ │ChU+│PgDn│          WHL↑|WHL↓
       ├────┼────┼────┼────┤           ┌────┐
       │Mtn-│Mtn+│Reac│Curr│           │MS 1│
       └────┴────┴────┴────┘           └────┘
*/
    [DISCORD] = LAYOUT(
                KC_ESC,         KC_PPLS,          C(A(KC_RGHT)), S(KC_PGUP),  RM_TOGG,
                C(A(KC_UP)),    A(KC_UP),         S(A(KC_UP)),   KC_PGUP,     KC_MUTE,
                C(A(KC_DOWN)),  A(KC_DOWN),       S(A(KC_DOWN)), KC_PGDN,     MS_BTN1,
                C(A(S(KC_UP))), C(A(S(KC_DOWN))), KC_PPLS,       S(KC_PGDN)
            ),

/*  MOUSE
       ┌────┬────┬────┬────┐DISCORD|GAME      WHL←|WHL→
       │Btn7│Acl0│Acl1│Acl2│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │MS 3│
       │Btn6│Btn1│Ms↑ │Btn2│    └────┘         └────┘
       ├────┼────┼────┼────┤
       │Btn5│Ms← │Ms↓ │Ms→ │          WHL↑|WHL↓
       ├────┼────┼────┼────┤           ┌────┐
       │Btn4│Btn1│Btn3│Btn2│           │MS 3│
       └────┴────┴────┴────┘           └────┘
*/
    [MOUSE] = LAYOUT(
                MS_BTN7, MS_ACL0, MS_ACL1, MS_ACL2, RM_TOGG,
                MS_BTN6, MS_BTN1, MS_UP,   MS_BTN2, MS_BTN3,
                MS_BTN5, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN3,
                MS_BTN4, MS_BTN1, MS_BTN3, MS_BTN2
            ),

/*  GAME
       ┌────┬────┬────┬────┐ MOUSE|LIGHT      WHL←|WHL→
       │    │    │    │    │    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │    │
       │    │    │    │    │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │    │    │    │    │          WHL↑|WHL↓
       ├────┼────┼────┼────┤           ┌────┐
       │    │    │    │    │           │    │
       └────┴────┴────┴────┘           └────┘
*/
    [GAME] = LAYOUT(
                _______, _______, _______, _______, RM_TOGG,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______,
                _______, _______, _______, MO(GAME_FN)
            ),

/*  GAME_FN
       ┌────┬────┬────┬────┐  MOUSE|LIGHT     WHL←|WHL→
       │    │    │    │    │    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │    │
       │    │    │    │    │    └────┘         └────┘
       ├────┼────┼────┼────┤
       │    │    │    │    │          Vol-|Vol+
       ├────┼────┼────┼────┤           ┌────┐
       │    │    │    │ ▼  │           │Mute│
       └────┴────┴────┴────┘           └────┘
*/
    [GAME_FN] = LAYOUT(
                _______, _______, _______, _______, RM_TOGG,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______, KC_MUTE,
                _______, _______, _______, KC_TRNS
            ),

/*  LIGHT
       ┌────┬────┬────┬────┐   GAME|NUM       Ani-|Ani+
       │Sat+│Val+│Spd+│Togg│    ┌────┐         ┌────┐
       ├────┼────┼────┼────┤    │Togg│         │Simp│
       │Hue-│Simp│Hue+│Ani+│    └────┘         └────┘
       ├────┼────┼────┼────┤
       │Sat-│Val-│Spd-│Ani-│          Val-|Val+
       ├────┼────┼────┼────┤           ┌────┐
       │Pln │Box │Swrl│Cent│           │Togg│
       └────┴────┴────┴────┘           └────┘
*/
    [LIGHT] = LAYOUT(
                RM_SATU, RM_VALU, RM_SPDU, RM_TOGG, RM_TOGG,
                RM_HUED, SIMPLGT, RM_HUEU, RM_NEXT, SIMPLGT,
                RM_SATD, RM_VALD, RM_SPDD, RM_PREV, RM_TOGG,
                RMD_PLN, RMD_BOX, RMD_SRL, RMD_CENT
            ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [NUM]      = { ENCODER_CCW_CW(TO(LIGHT),   TO(WIN)),     ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN]      = { ENCODER_CCW_CW(TO(NUM),     TO(MAC)),     ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [WIN_FN]   = { ENCODER_CCW_CW(TO(NUM),     TO(MAC)),     ENCODER_CCW_CW(KC_BRID, KC_BRIU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC]      = { ENCODER_CCW_CW(TO(WIN),     TO(MEDIA)),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [MAC_FN]   = { ENCODER_CCW_CW(TO(WIN),     TO(MEDIA)),   ENCODER_CCW_CW(KC_SCRL, KC_PAUS), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MEDIA]    = { ENCODER_CCW_CW(TO(MAC),     TO(BROWSER)), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [BROWSER]  = { ENCODER_CCW_CW(TO(MEDIA),   TO(DISCORD)), ENCODER_CCW_CW(KC_WBAK, KC_WFWD), ENCODER_CCW_CW(C(S(KC_TAB)), C(KC_TAB)) },
    [DISCORD]  = { ENCODER_CCW_CW(TO(BROWSER), TO(MOUSE)),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [MOUSE]    = { ENCODER_CCW_CW(TO(DISCORD), TO(GAME)),    ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [GAME]     = { ENCODER_CCW_CW(TO(MOUSE),   TO(LIGHT)),   ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [GAME_FN]  = { ENCODER_CCW_CW(TO(MOUSE),   TO(LIGHT)),   ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LIGHT]    = { ENCODER_CCW_CW(TO(GAME),    TO(NUM)),     ENCODER_CCW_CW(RM_PREV, RM_NEXT), ENCODER_CCW_CW(RM_VALD, RM_VALU) },

};
#endif

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        case SIMPLGT: // Simplified personal preferred lighting mode switching
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
        case DBL_0:
            if (record->event.pressed) {
                SEND_STRING_DELAY("00", 50);
            }
            return false;
        case RMD_PLN:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
        case RMD_BOX:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_ALPHAS_MODS);
            }
            return false;
        case RMD_SRL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_RAINBOW_PINWHEELS);
            }
            return false;
        case RMD_CENT:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN);
            }
            return false;
        case EXTEND: // Extended desktop (Win+P)
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("p") SS_DELAY(400) SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_DOWN) SS_DELAY(200) SS_TAP(X_ENT) SS_DELAY(200) SS_TAP(X_ESC) );
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
        oled_write_ln(layers[get_highest_layer(layer_state)], false);
        render_layer_status();

        return true;
    }
#endif
