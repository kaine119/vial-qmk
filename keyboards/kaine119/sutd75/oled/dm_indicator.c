#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "oled_driver.h"
#include "print.h"
#include "process_dynamic_macro.h"
#include "progmem.h"

const char black_line[32] PROGMEM = {
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80
};

static bool need_to_update = true;
static bool macro_1_recording = false;
static bool macro_2_recording = false;

static uint16_t macro_1_count = 0;
static uint16_t macro_2_count = 0;
static char macro_1_buffer[6];
static char macro_2_buffer[6];


void dynamic_macro_record_start_user(int8_t direction) {
    if (direction == 1) {
        macro_1_recording = true;
        macro_1_count = 0;
        need_to_update = true;
    } else if (direction == -1) {
        macro_2_recording = true;
        macro_2_count = 0;
        need_to_update = true;
    }
}

void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record) {
    if (direction == 1 && record->event.pressed) {
        macro_1_count++;
        need_to_update = true;
    } else if (direction == -1 && record->event.pressed) {
        macro_2_count++;
        need_to_update = true;
    }
}

void dynamic_macro_record_end_user(int8_t direction) {
    if (direction == 1) {
        macro_1_recording = false;
        need_to_update = true;
    } else if (direction == -1) {
        macro_2_recording = false;
        need_to_update = true;
    }
}

void render_dm_screen(void) {
    if (need_to_update) {
        oled_clear();

        oled_set_cursor(0, 0);
        oled_write_ln("DM1", false);
        sprintf(macro_1_buffer, "%4u", macro_1_count);
        oled_set_cursor(0, 2);
        oled_write_ln(macro_1_buffer, false);
        oled_set_cursor(0, 3);
        oled_write_ln("moves", false);
        oled_set_cursor(0, 5);
        if (macro_1_recording) {
            oled_write_ln(" rec ", true);
        } else {
            oled_write_ln("     ", false);
        }
        oled_set_cursor(0, 7);
        oled_write_raw(black_line, 32);

        oled_set_cursor(0, 9);
        oled_write_ln("DM2", false);
        sprintf(macro_2_buffer, "%4u", macro_2_count);
        oled_set_cursor(0, 11);
        oled_write_ln(macro_2_buffer, false);
        oled_set_cursor(0, 12);
        oled_write_ln("moves", false);
        if (macro_2_recording) {
            oled_set_cursor(0, 14);
            oled_write_ln(" rec ", true);
        }

        need_to_update = false;
    }
}