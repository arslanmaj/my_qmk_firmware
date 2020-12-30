#pragma once

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    FN_CTAD = SAFE_RANGE, // Key that sends Ctrl + alt + delete
    FN_CAPS = SAFE_RANGE, // Special caps lock layer switching functionality
    FN_YKEY , // Key that sends Home + Shift (down) + End + Shift (up)
    FN_ALF4 , // Key that sends Alt + F4
    FN_EKEY , // Key that sends Shift + F10
    FN_TAB4  // Key that sends Tab 4 times
};

// Define layers
#define _DEF 0
#define _FUN 1
#define _MOU 2
#define _NUM 3
#define _FKL 4

// Define special keycodes
#define FN_CTAD LCTL(LALT(KC_DEL))
#define FN_CAPS LT(_FKL , KC_ESC)
#define FN_SPACE LT(_FUN , KC_SPC)
#define FN_TAB LT(_MOU , KC_TAB)
#define FN_ATAB LALT(LCTL(KC_TAB))
#define FN_CTST LCTL(LSFT(KC_T))
#define FN_CTLW LCTL(KC_W)
#define FN_CSH0 LCTL(LSFT(KC_0))
#define FN_CTL0 LCTL(KC_0)
#define FN_CTL1 LCTL(KC_1)
#define FN_CTL2 LCTL(KC_2)
#define FN_CTL3 LCTL(KC_3)
#define FN_CTL4 LCTL(KC_4)
#define FN_FKL5 LSFT(KC_F5)

// Instantiate special keystrokes
bool process_record_user(uint16_t keycode , keyrecord_t *record) {
    switch (keycode) {
        case FN_YKEY:
            if (record->event.pressed) {
                // Send Home + Shift (down) + End + Shift (up)
                SEND_STRING(SS_TAP(X_HOME));
                SEND_STRING(SS_DOWN(X_RSHIFT));
                SEND_STRING(SS_TAP(X_END));
                SEND_STRING(SS_UP(X_RSHIFT));
            } else {}
            break;
        case FN_ALF4:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_F4));
                SEND_STRING(SS_UP(X_LALT));
            } else {}
      break;
        case FN_EKEY:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_RSHIFT));
                SEND_STRING(SS_TAP(X_F10));
                SEND_STRING(SS_UP(X_RSHIFT));
            } else {}
      break;
        case FN_TAB4:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_TAB));
                SEND_STRING(SS_UP(X_TAB));
                SEND_STRING(SS_DOWN(X_TAB));
                SEND_STRING(SS_UP(X_TAB));
                SEND_STRING(SS_DOWN(X_TAB));
                SEND_STRING(SS_UP(X_TAB));
                SEND_STRING(SS_DOWN(X_TAB));
                SEND_STRING(SS_UP(X_TAB));
              } else {}
              break;
    }
  return true;
}
