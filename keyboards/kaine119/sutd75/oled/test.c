#include QMK_KEYBOARD_H

static uint8_t height = 0;

void add_height(void) {
    oled_clear();
    height++;
}

void minus_height(void) {
    oled_clear();
    height--;
}

void render_test(void) {
    oled_set_cursor(0, height);
    oled_write_ln_P("Teste", false);
    // for (int i = 1; i < 16; i++) {
    //     oled_set_cursor(0, i);
    //     oled_write_P("     ", false);
    // }
}
