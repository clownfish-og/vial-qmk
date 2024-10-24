/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* USB Device descriptor parameter */
/*
#define VENDOR_ID       0x3801
#define PRODUCT_ID      0x3802
#define DEVICE_VER      0x0001
#define MANUFACTURER    Vial
#define PRODUCT         xr2
*/
/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 20

#define MATRIX_ROW_PINS {  B15, B10, B9,  A15, B1,  B8 }
#define MATRIX_COL_PINS {  A3,  A2,  A1,  A0,  A4,  A5,  B11,  A7,  B0,  B12, B13, B14, B4, B5, B6, B7,  A8, A9, A10, B3}
#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 2
/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

#define FORCE_NKRO

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Use 1000hz polling */
#define USB_POLLING_INTERVAL_MS 1

#define SLIDER_PIN C15
#define MIDI_ADVANCED

/*
#define SOLENOID_PIN A8
#define HAPTIC_ENABLE_PIN B15
#define SOLENOID_DEFAULT_DWELL 4
#define SOLENOID_MIN_DWELL 4
#define SOLENOID_MAX_DWELL  45
#define HAPTIC_OFF_IN_LOW_POWER 1
#define NO_HAPTIC_MOD
*/
#if defined(RGB_MATRIX_ENABLE)
#define WS2812_DI_PIN A6
#define RGBLED_NUM 103
#define RGB_MATRIX_LED_COUNT 103
#define DRIVER_LED_TOTAL RGBLED_NUM

#define WS2812_EXTERNAL_PULLUP
#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 1
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA1_STREAM3
#define WS2812_DMA_CHANNEL 3
#define WS2812_PWM_TARGET_PERIOD 800000


//#define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
/*
//#    define RGBLIGHT_SLEEP  //如果已定义，当主机进入睡眠状态时 RGB 灯将关闭 If defined, the RGB lighting will be switched off when the host goes to sleep
///////////////#if defined(RGBLIGHT_ENABLE)
//#    define RGBLIGHT_ANIMATIONS                //启用所有其他动画模式。（弃用）
#    define RGBLIGHT_EFFECT_ALTERNATING          //启用交替动画模式。
#    define RGBLIGHT_EFFECT_BREATHING            //启用呼吸动画模式。
#    define RGBLIGHT_EFFECT_CHRISTMAS            //启用圣诞动画模式。
#    define RGBLIGHT_EFFECT_KNIGHT               //启用骑士动画模式。
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD         //启用彩虹心情动画模式。
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL        //启用彩虹漩涡动画模式。
#    define RGBLIGHT_EFFECT_RGB_TEST             //启用 RGB 测试动画模式。
#    define RGBLIGHT_EFFECT_SNAKE                //启用蛇动画模式。
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT      //启用静态渐变模式。
#    define RGBLIGHT_EFFECT_TWINKLE              //启用闪烁动画模式。
 //  #define RGBLIGHT_LIMIT_VAL 255   // The maximum brightness level
////////////////////#endif  // RGBLIGHT_ENABLE
*/




  // RGB Matrix settings
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_test_mode


/* Limit animations to 62.5 FPS to avoid tearing. (1/.016 = 62.5 FPS). */
/*
#define RGB_MATRIX_LED_FLUSH_LIMIT 16


#define RGB_MATRIX_SAT_STEP 24
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_VAL_STEP 16
#define RGB_MATRIX_SPD_STEP 16
//#define RGB_TRIGGER_ON_KEYDOWN
*/
//下面都是RGBRGB 矩阵效果
// RGB Matrix Animation modes. Explicitly enabled   //// RGB 矩阵动画模式。显式启用
// For full list of effects, see:  // 有关效果的完整列表，请参阅：
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
//到此都是RGB 矩阵效果
