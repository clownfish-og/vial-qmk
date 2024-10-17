# MCU name

# Bootloader selection
#BOOTLOADER = stm32duino
# Build Options
#   change yes to no to disable
#
#EXTRAKEY_ENABLE = yes       # Audio control and System control
#CONSOLE_ENABLE = no        # Console for debug
#COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
#SLEEP_LED_ENABLE = no      # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
#NKRO_ENABLE = yes           # USB Nkey Rollover
#MIDI_ENABLE =   yes          # MIDI support
#UNICODE_ENABLE = no         # Unicode

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

VIAL_INSECURE = yes    #禁用启动VIAL恶意刷新固件的按键

#QMK_SETTINGS = no
#ALLOW_WARNINGS = yes
#RGB_MATRIX_ENABLE = yes
