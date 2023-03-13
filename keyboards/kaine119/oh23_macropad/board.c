#include "quantum.h"

void keyboard_pre_init_user(void) {
    setPinOutput(GP11);
    setPinOutput(GP25);
    setPinOutput(GP16);
    setPinOutput(GP17);
    writePinHigh(GP11);
    writePinHigh(GP25);
    writePinHigh(GP16);
    writePinHigh(GP17);
}

