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

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "action.h"
#include "quantum.h"

#ifdef VIA_ENABLE
#    include "via.h"
#endif
#ifdef VIAL_ENABLE
#    include "vial.h"
#endif


#include "quantum_keycodes.h"

enum custom_keycodes {
    CAPGEN5 = QK_KB_0,
    CAPGEN8,
    CAPGEN10,
    ABDUCKTION, //first emote
    AMNESIA,
    ASCEND,
    ASHDUCKEM,
    AYO,
    BACKDOOR,
    BALLOON,
    BART,
    BASSFACE,
    BEARDDANCE,
    BIGBRAIN,
    BITS,
    BOB,
    BOOMER,
    BROC,
    BUG,
    BUP,
    BUPS,
    BUPWAD,
    CALL,
    CATDANCE,
    CHEERS,
    CHEESE,
    CHEFKISS,
    CHILLGUY,
    CLOUDS,
    CROWN,
    DIDDY,
    DISCO,
    DOIT,
    DONUT,
    DRAGON,
    DRUMS,
    DUCKDANCE,
    DUCKHEAD,
    DYE,
    EE,
    EXCUSEME,
    FANCYDUCK,
    FIRE,
    FLUTE,
    FREAKOUT,
    FROG,
    GOLD,
    GOOSE,
    GROGU,
    GROOVY,
    HEADOUT,
    HEADPHONES,
    HEART,
    HORN,
    ID,
    JAWNESSA,
    JELLY,
    KEKW,
    KEYS,
    LIGHTER,
    LOVE,
    LUIGIBUP,
    MAPLE,
    MOOSE,
    NOD,
    PATBANG,
    PLUG,
    RAINBOW,
    RAVE,
    RUMP,
    SALT,
    SALUTE,
    SH,
    SLAY,
    SMIRK,
    SMUG,
    SUS,
    SWEATY,
    THANKS,
    TIEDYE,
    TINFOIL,
    TUNE,
    UP,
    UWU,
    WATER,
    WAVE,
    WINK,
    WIZ,
    WOOK,
    WUB,
    ZEJIBO,
    ZELDABUP, //last bup emote
    BOP, //first twitch emote
    BOPBOP,
    DINODANCE,
    GLITCHLIT,
    GOATEMOTEY,
    GOLDPLZ,
    KAPPA,
    KREYGASM,
    MODLOVE,
    NOTLIKETHIS,
    POWERUPL,
    POWERUPR,
    RIPEPPERONIS,
    SABAPING,
    SINGSMIC,
    SINGSNOTE,
    STINKYCHEESE,
    TOMBRAID,
    TWITCHCONHYPE,
    TWITCHLIT,
    TWITCHRAID,
    UNITY,
    VOTENAY,
    VOTEYEA, //last twitch emote
    KCLAP, //first ktulue emote
    KGATO,
    KGGS,
    KGLUTES,
    KHI,
    KHUG,
    KLEI,
    KLOVE,
    KRDNC,
    KSMUG,
    KWELP //last ktulue emote = last emote
};

#define LAST_EMOTE_KEYCODE KWELP
#define FIRST_EMOTE_KEYCODE ABDUCKTION
#define MAX_EMOTE_LEN 32
#define LAST_BUP_KEYCODE ZELDABUP
#define BUP_PREFIX "bup"
#define FIRST_KTLU_KEYCODE KCLAP
#define LAST_KTLU_KEYCODE KWELP
#define KTLU_PREFIX "ktulue"

typedef struct {
    uint16_t keycode;
    const char *suffix;
} keycode_string_compressed_t;

bool process_record_bup(uint16_t keycode, keyrecord_t *record);
