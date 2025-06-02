# KB16-01 Rev 2 Vial Firmware

### This keypad has 2 revisions. THIS FIRMWARE IS ONLY COMPATIBLE WITH REVISION 2. Please read carefully and confirm which version you have before flashing to avoid accidentally bricking your device!

![KB16-01](https://i.imgur.com/lpq47ELh.png)

### Revision 1: NOT COMPATIBLE WITH THIS FIRMWARE  

* Using ATMEGA32U4.

* Upon entering bootloader mode QMK Toolbox will display the following message:  
`Atmel DFU device connected (libusb0): Atmel Corp. ATmega32U4 (03EB:2FF4:0000)`

### Revision 2: (compatible)

* Using APM32F103CBT6 (clone STM32F103CBT6).

* Upon entering bootloader mode QMK Toolbox will display the following message:  
 `STM32Duino device connected: LeafLabs Maple 003 (1EAF:0003:0201)`

#### The KB16-01 is a macropad featuring a 16-key keypad made by DOIO. Controlled by an APM32F103CBT6 chipset, the keyboard also features per-key RGB, 3 rotary encoders, and an OLED display.

* Keyboard Maintainers: [HorrorTroll](https://github.com/HorrorTroll), [ClownFish](https://github.com/clownfish-og)
* Hardware Supported: APM32F103CBT6

Make example for this keyboard (after setting up your Vial build environment):

    `make doio/kb16_rev2:clownfish`

Flashing example for this keyboard:

    `make doio/kb16_rev2:clownfish:flash`

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (1! key) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
