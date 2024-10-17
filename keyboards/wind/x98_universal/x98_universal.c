/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "x98_universal.h"
//LED共正极
/*
void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.       //Setting status LEDs pins to output and -5V (off)

  // Set our LED pins as output
  setPinOutput(B5);
  setPinOutput(B9);
 // setPinOutput(B15);
}

bool led_update_kb(led_t led_state) {
    if(led_update_user(led_state)) { 
        writePin(B5, !led_state.caps_lock);
        writePin(B9, !led_state.num_lock);
    }
    return true;
}
*/

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    // Key Matrix to LED Index
	// 0,------1,------2,------3,------4,------5,------6,------7,------8,------9,-----10,-----11,-----12,-----13,-----14,-----15,-----16,-----17,-----18,-----19,     
    {  0, NO_LED,      1,      2,      3,      4,      5,      6,      7,      8,      9,     10,     11,     12,     13,     14,     15,     16,     17,  NO_LED, },  //
    { 37,     36,     35,     34,     33,     32,     31,     30,     29,     28,     27,     26,     25,     24,     23,     22,     21,     20,     19,      18, },  //
    { 38,     39,     40,     41,     42,     43,     44,     45,     46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56,  NO_LED, },  //
    { 73,     72,     71,     70,     69,     68,     67,     66,     65,     64,     63,     62,     61, NO_LED,     60,     59,     58,     57, NO_LED,  NO_LED, },  //
    { 74,     75,     76,     77,     78,     79,     80,     81,     82,     83,     84,     85,     86,     87,     NO_LED, 88,     89,     90,     91,  NO_LED, },  //
    { 102,   101,    100,     99, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED,     98,     97,     96,     95,     94,     93,     NO_LED, 92, NO_LED,  NO_LED  },  //
}, {
    // LED Index to Physical Position
    //0,          1,          2,          3,          4,          5,          6,          7,          8,          9,          10,          11,          12,          13,          14,          15,          16,            17,          18,               19,
    { 0,  0 },             { 20,  0 }, { 30,  0 }, { 40,  0 }, { 50,  0 }, { 60,  0 }, { 70, 0  }, { 80,  0 }, { 90, 0  }, { 100,  0 }, { 110,  0 }, { 120,  0 }, { 130,  0 }, { 140,  0 }, { 150,  0 }, { 160,  0  },  { 170,  0 }, { 180,  0  }, 
    { 0, 10 }, { 10, 10 }, { 20, 10 }, { 30, 10 }, { 40, 10 }, { 50, 10 }, { 60, 10 }, { 70, 10 }, { 80, 10 }, { 90, 10 }, { 100, 10 }, { 110, 10 }, { 120, 10 }, { 130, 10 }, { 140, 10 }, { 150, 10 }, { 160,  10 },  { 170, 10 }, { 180, 10  },  { 190,  0  },
    { 0, 20 }, { 10, 20 }, { 20, 20 }, { 30, 20 }, { 40, 20 }, { 50, 20 }, { 60, 20 }, { 70, 20 }, { 80, 20 }, { 90, 20 }, { 100, 20 }, { 110, 20 }, { 120, 20 }, { 130, 20 }, { 140, 20 }, { 150, 20 }, { 160,  20 },  { 170, 20 }, { 180, 20  },
    { 0, 30 }, { 10, 30 }, { 20, 30 }, { 30, 30 }, { 40, 30 }, { 50, 30 }, { 60, 30 }, { 70, 30 }, { 80, 30 }, { 90, 30 }, { 100, 30 }, { 110, 30 },              { 130, 30 }, { 140, 30 }, { 150, 30 }, { 160,  30 },  { 170, 30 }, 
    { 0, 40 }, { 10, 40 }, { 20, 40 }, { 30, 40 }, { 40, 40 }, { 50, 40 }, { 60, 40 }, { 70, 40 }, { 80, 40 }, { 90, 40 }, { 100, 40 }, { 110, 40 }, { 120, 40 }, { 130, 40 },              { 150, 40 }, { 160,  40 },  { 170, 40 }, { 180, 40  },
    { 0, 50 }, { 10, 50 }, { 20, 50 }, { 30, 50 },                                                                         { 100, 50 }, { 110, 50 }, { 120, 50 }, { 130, 50 }, { 140, 50 }, { 150, 50 },                { 170, 50 },
  }, {
    // LED Index to Flag
	//  0  1  2  3  4  5  6  7  8  9,10,11,12,13,14,15,16,17,18,19,
        1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
		1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4, 4, 4, 1, 
		1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4, 4, 1,
        1, 4, 4, 4,                   4, 4, 4, 4, 4, 4,    1,
} };
#endif
/*
//LED共负极
void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(C15);
  setPinOutput(A10);
  setPinOutput(A9);
 // setPinOutput(D1);
}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
        writePinHigh(C15);
    } else {
        writePinLow(C15);
    }
    
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinHigh(A10);
    } else {
        writePinLow(A10);
    }
    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        writePinHigh(A9);
    } else {
        writePinLow(A9);
    }
    
}
*/
