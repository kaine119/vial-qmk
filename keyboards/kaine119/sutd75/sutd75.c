/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "sutd75.h"


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