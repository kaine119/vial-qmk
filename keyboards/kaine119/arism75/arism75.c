/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "arism75.h"


#ifdef MACRO_INDICATOR_PIN
  void keyboard_post_init_user(void) {
    writePin(MACRO_INDICATOR_PIN, 0);
  }

  void dynamic_macro_record_start_user(void) {
    writePin(MACRO_INDICATOR_PIN, 1);
  }

  void dynamic_macro_record_end_user(int8_t direction) {
    writePin(MACRO_INDICATOR_PIN, 0);
  }
#endif


#ifdef BADGE_INDICATOR_PIN
  // Place any custom callbacks for the badge indicator pin here.
#endif