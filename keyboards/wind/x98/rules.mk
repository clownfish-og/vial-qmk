# MCU name
MCU = STM32F103

# Bootloader selection
#BOOTLOADER = stm32duino
BOOTLOADER = uf2boot
# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no      # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
#GBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
MIDI_ENABLE =   yes          # MIDI support
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
#AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

#HAPTIC_ENABLE = yes
#HAPTIC_DRIVER = SOLENOID   #启用电磁阀

VIAL_INSECURE = yes    #禁用启动VIAL恶意刷新固件的按键

#QMK_SETTINGS = no
LTO_ENABLE = yes
#ALLOW_WARNINGS = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
#WS2812_DRIVER = pwm
