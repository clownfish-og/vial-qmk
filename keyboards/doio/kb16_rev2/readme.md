# KB16-01

#### This keyboard have 2 revision, so before you need to write your own firmware code. Please read it carefully, or you could accident bricked your keeb after that.

- **Revision 1**: Using ATMEGA32U4.

When you try to go bootloader mode, QMK Toolbox will showing this message `Atmel DFU device connected (libusb0): Atmel Corp. ATmega32U4 (03EB:2FF4:0000)`. So please compile Revision 1 and flash after that.

Oh, and one more thing. As for the Bongo Cat on OLED screen, due to small flash size that ATMEGA32U4 support. It need to be disable Mouse key support.

- **Revision 2**: Using APM32F103CBT6 (clone STM32F103CBT6).

When you try to go bootloader mode, QMK Toolbox will showing this message `STM32Duino device connected: LeafLabs Maple 003 (1EAF:0003:0201)`. So please compile Revision 2 and flash after that.
# KB16-01 (Revision 2)

![KB16-01](https://i.imgur.com/lpq47ELh.png)

A macropad that have 16-key keyboard made by DOIO, which controlled by an APM32F103CBT6 chipset. The keyboard features per-key RGB, 3 encoder and an OLED screen for displaying useful information.

* Keyboard Maintainer: [HorrorTroll](https://github.com/HorrorTroll)
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
