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
 #include "25.h"

 enum custom_keycodes {
    BOP = FIRST_EMOTE, // Start Twitch Global Emotes
    BOPBOP,         // Twitch Global Emote
    DINODANCE,      // Twitch Global Emote
    GLITCHLIT,      // Twitch Global Emote
    GOATEMOTEY,     // Twitch Global Emote
    GOLDPLZ,        // Twitch Global Emote
    KAPPA,          // Twitch Global Emote
    KREYGASM,       // Twitch Global Emote
    MODLOVE,        // Twitch Global Emote
    NOTLIKETHIS,    // Twitch Global Emote
    POWERUPL,       // Twitch Global Emote
    POWERUPR,       // Twitch Global Emote
    SINGSMIC,       // Twitch Global Emote
    SINGSNOTE,      // Twitch Global Emote
    STINKYCHEESE,   // Twitch Global Emote
    TOMBRAID,       // Twitch Global Emote
    TWITCHCONHYPE,  // Twitch Global Emote
    TWITCHLIT,      // Twitch Global Emote
    TWITCHRAID,     // Twitch Global Emote
    UNITY,          // End Twitch Global Emotes
    APPROVE,
    AYO,
    BONGO,
    CHEF,
    CLOWNFISH,
    COOL,
    DOIT,
    DANCE,
    EXCITE,
    GIFT,
    GLUTES,
    HEARTBEAT,
    HIYA,
    HORN,
    HUG,
    HYPE,
    JAMMIN,
    WIGGLE,
    FIRES,
    GRIN,
    HEART,
    TUNE,
    WAVE,  // LAST_EMOTE
    MAINSC,  // FIRST_CMD
    WELCOME,
    BRB,
    SMALL,
    VINYL,
    NEW,
    SLOTHS,
    GYPSY,
    NINJA,
    STRAT,
    _JAMMIN,
    _GLUTES,
    _WIGGLE,
    _CLNFSH,
    _BONGO  // LAST_CMD
 };

#define LAST_EMOTE WAVE
#define FIRST_CMD MAINSC
#define LAST_CMD _BONGO
