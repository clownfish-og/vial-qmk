/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x65, 0x9A, 0x6E, 0x3C, 0x47, 0x63, 0xB9, 0x9B}

#define VIAL_UNLOCK_COMBO_ROWS { 3, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 3 }

#ifdef WEAR_LEVELING_BACKING_SIZE
    #undef WEAR_LEVELING_BACKING_SIZE
#endif

#define WEAR_LEVELING_BACKING_SIZE	2*1024*8 // 16kB for 8kB of logical data
#define DYNAMIC_KEYMAP_LAYER_COUNT 12
#define DYNAMIC_KEYMAP_MACRO_COUNT 64
