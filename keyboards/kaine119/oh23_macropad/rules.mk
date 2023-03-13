# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# This file intentionally left blank
RGBLIGHT_ENABLE = yes
RGBLIGHT_DRIVER = WS2812
WS2812_DRIVER = vendor

SRC += board.c