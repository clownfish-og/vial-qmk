#pragma once

#define VIAL_KEYBOARD_UID {0x27, 0x1E, 0x04, 0x95, 0xAD, 0x59, 0x6C, 0x59}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 1, 11 }
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
