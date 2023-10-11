/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "debug.h"
#include "keyboard.h"
#include "sutd75.h"
#include <stdint.h>

void keyboard_post_init_kb(void) {
    debug_enable = true;
    debug_keyboard = true;
}

#ifdef RGB_MATRIX_ENABLE
// clang-format off
led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {NO_LED, NO_LED, NO_LED, NO_LED,  NO_LED,  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}, \
        {NO_LED, NO_LED, 0,      NO_LED,  NO_LED,  1,       NO_LED, NO_LED,  NO_LED,  2,      NO_LED, NO_LED, NO_LED, NO_LED, 3,      NO_LED}, \
        {NO_LED, NO_LED, NO_LED, NO_LED,  NO_LED,  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}, \
        {NO_LED, NO_LED, NO_LED, NO_LED,  NO_LED,  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}, \
        {NO_LED, NO_LED, 7,      NO_LED,  NO_LED,  6,       NO_LED, NO_LED,  NO_LED,  5,      NO_LED, NO_LED, NO_LED, NO_LED, 4,      NO_LED}, \
        {NO_LED, NO_LED, NO_LED, NO_LED,  NO_LED,  NO_LED,  NO_LED, NO_LED,  NO_LED,  NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}  \
    }, 
    {
        // LED Index to Physical Position
        {112, 39}, {148, 60}, {206, 53}, {206, 3}, {150, 3}, {74, 3}, {18, 3}, {18, 54}
    },
    {
        // LED Index to Flag
        LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL,
        LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, LED_FLAG_ALL, 
    } 
};

#endif

 /**
 * OLED config
 */
#ifdef OLED_ENABLE

#include "oled/test.c"
#include "oled/dm_indicator.c"
#include "images.h"

#define SPLASH_TIMEOUT 3000

/* timers */
static uint32_t splash_timer;
static bool splash_screen_displayed = true;
// static bool dm_screen_displayed = false;

enum OLED_KEYS {
    OLED_1 = 0x7e00, // apparently this is USER00
    OLED_2
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case OLED_1:
        if (record->event.pressed) {
            add_height();
        }
        break;
    case OLED_2:
        if (record->event.pressed) {
            minus_height();
        }
    }
    return true;
}


void render_splash(void) {
    oled_write_raw(sutd_logo, 512);
}

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    splash_timer = timer_read32();
    return OLED_ROTATION_270;
}

bool oled_task_kb(void) {
    if (timer_elapsed32(splash_timer) >= SPLASH_TIMEOUT && splash_screen_displayed) {
        oled_clear();
        splash_screen_displayed = false;
    }

    if (splash_screen_displayed) {
        render_splash();
    } else {
        // render_test();
        render_dm_screen();
    }

    return false;
}

#endif