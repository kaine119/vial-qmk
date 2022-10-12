/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    kaine119
#define PRODUCT         Arism75

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 16

#define MATRIX_ROW_PINS { A0, A1, A2, A3, A4, A5 }
#define MATRIX_COL_PINS { B14, B13, B12, B11, B10, B1, B0, C13, B9, B8, B7, B6, B5, B4, B3, A15 }

#define DIODE_DIRECTION ROW2COL

/* Rotary encoder pins */
#define ENCODERS_PAD_A { A7 }
#define ENCODERS_PAD_B { A6 }
#define ENCODER_RESOLUTION 4 /* pulses the encoder outputs between each dedent */


/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

/* Use 1000hz polling */
#define USB_POLLING_INTERVAL_MS 1

/* Because we use vibl, this has to be defined here instead of under keymaps/vial/config.h */
#define VIAL_KEYBOARD_UID {0x9D, 0x41, 0x57, 0x89, 0x50, 0x9A, 0x93, 0x08}
