// *****************************************************************************
// TODO: 12/28/19
// Working: Tap caps 1 time to activate layer 0, Tap twice to activate layer
// 1, and thrice to activate layer 3. 
// Not working: Holding caps does not momentarily activate layer 1
// Final wish: Tap once to move to layer 0, 2 times for layer 1, 3 times for 
// layer 2, 4 times for layer 3, and so on. 
// Hold for momentary on layer 1
// Remove caps lock altogether, I never use it!
// *****************************************************************************
/* Copyright 2018 'mechmerlin'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
// *****************************************************************************
// Note: This is the command to build: make kbdfans/kbd67/rev2:arslan
// *****************************************************************************
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  FN_CTAD = SAFE_RANGE, // Key that sends Ctrl + alt + delete
  FN_CAPS = SAFE_RANGE, // Special caps lock layer switching functionality
  FN_YKEY, // Key that sends Home + Shift (down) + End + Shift (up)
  FN_ALF4, // Key that sends Alt + F4
  FN_EKEY, // Key that sends Shift + F10
  FN_TAB4  // Key that sends Tab 4 times
};
// Define layers
#define _DEF 0
#define _FUN 1
#define _MOU 2
#define _GAM 3
#define _NUM 4
#define _FKL 5

#define FN_CTAD LCTL(LALT(KC_DEL))
#define FN_CAPS LT(1, KC_CAPS)
#define FN_TAB LT(2, KC_TAB)
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

// *****************************************************************************
// TAP DANCE through layers using caps-lock
// *****************************************************************************
enum {
  TDC = 0
};
bool fn_held;
void dance_layers(qk_tap_dance_state_t *state, void *user_data){
  if (state->pressed){
    layer_on(_FUN);
    layer_off(_MOU);
    layer_off(_GAM);
    layer_off(_NUM);
    layer_off(_FKL);
    fn_held = true;
  }
  else {
    switch (state->count){
      case 1: //off all layers, just base on
        layer_off(_FUN);
        layer_off(_MOU);
        layer_off(_GAM);
        layer_off(_NUM);
        layer_off(_FKL);
        break;
      case 2: //function layer on
        layer_on(_FUN);
        layer_off(_MOU);
        layer_off(_GAM);
        layer_off(_NUM);
        layer_off(_FKL);
        break;
      case 3: //mouse layer on
        layer_off(_FUN);
        layer_on(_MOU);
        layer_off(_GAM);
        layer_off(_NUM);
        layer_off(_FKL);
        break;
      case 4: //game layer on
        layer_off(_FUN);
        layer_off(_MOU);
        layer_on(_GAM);
        layer_off(_NUM);
        layer_off(_FKL);
        break;
      case 5: //num layer on
        layer_off(_FUN);
        layer_off(_MOU);
        layer_off(_GAM);
        layer_on(_NUM);
        layer_off(_FKL);
        break;
      case 6: //fkl layer on
        layer_off(_FUN);
        layer_off(_MOU);
        layer_off(_GAM);
        layer_off(_NUM);
        layer_on(_FKL);
        break;
    }
  }
}
void dance_layers_reset(qk_tap_dance_state_t *state, void *user_data){
  if (fn_held) {
    layer_off(_FUN);
    layer_off(_MOU);
    layer_off(_GAM);
    layer_off(_NUM);
    fn_held = false;
  }
}
qk_tap_dance_action_t tap_dance_actions[] = {
  [TDC] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_layers, dance_layers_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |FN | - |Alt|Lef|Dow|Rig  |
   * `----------------------------------------------------------------'
   */
[_DEF] = LAYOUT_65_ansi(
  KC_GESC, KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, TD(TDC),\
  FN_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,\
   MO(5),  KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,\
  KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,           KC_UP,  KC_DEL,\
  KC_LCTL, KC_LGUI, KC_LALT,                LT(1, KC_SPC),          KC_RALT,   KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
/* Keymap (Fn Layer 1)  q
   * ,----------------------------------------------------------------.
   * |~  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |Home|
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |FnY|PUp|Up |PDn|Bck|   |   |     |    |
   * |----------------------------------------------------------------|
   * |       |   |   |   |   |   |Hom|Lef|Dwn|Rig|   |   |       |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |End|Del|   |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |        Space          |FN | - |Ctrl|   |   |    |
   * `----------------------------------------------------------------'
   */
[_FUN] = LAYOUT_65_ansi(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, _______, _______,\
  _______, FN_CTL1, FN_CTL2, FN_CTL3, FN_CTL4, _______, FN_YKEY, KC_PGUP, KC_UP,   KC_PGDN, KC_BSPC, _______, _______, KC_BSPC, _______,\
  _______, FN_TAB4, _______, FN_ATAB, FN_CTL0, FN_CSH0, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, FN_CTLW, FN_CTST,          _______, KC_MPLY,\
  _______, FN_EKEY, FN_ALF4, _______, _______, _______, KC_END,  KC_DEL, _______,  _______, _______,   TT(4),          KC_VOLU, KC_MUTE,\
  _______, _______, _______,                _______,                               _______, _______, KC_RCTL, KC_MPRV, KC_VOLD, KC_MNXT),
/* Keymap (Fn Layer 2 - One shot Layer)
  * ,----------------------------------------------------------------.
  * |~  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |Home|
  * |----------------------------------------------------------------|
  * |     |   |   |   |   |   |FnY|PUp|Up |PDn|Bck|   |   |     |    |
  * |----------------------------------------------------------------|
  * |       |   |   |   |   |   |Hom|Lef|Dwn|Rig|   |   |       |    |
  * |----------------------------------------------------------------|
  * |        |   |   |   |   |   |End|Del|   |   |   |      |   |    |
  * |----------------------------------------------------------------|
  * |    |    |    |        Space          |FN | - |Ctrl|   |   |    |
  * `----------------------------------------------------------------'
  */
[_MOU] = LAYOUT_65_ansi(
  _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, RGB_SAI, RGB_SAD, RGB_MOD, RGB_TOG, RGB_VAD, RGB_VAI, _______, _______,\
  _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, KC_ACL0, _______, _______, _______, _______,\
  _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, _______,          _______, _______,\
  _______, FN_CTAD, RESET,   _______, _______, _______, _______, _______, _______, _______, KC_ACL2, _______,          KC_BRIU, _______,\
  _______, _______, _______,                _______,                               _______, _______, _______, _______, KC_BRID, _______),
/* Keymap (Fn Layer 3 - Gaming Layer)
  * ,----------------------------------------------------------------.
  * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |    |
  * |----------------------------------------------------------------|
  * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |    |
  * |----------------------------------------------------------------|
  * |       |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|       |    |
  * |----------------------------------------------------------------|
  * |        |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|      |   |    |
  * |----------------------------------------------------------------|
  * |    |    |    |                       |   | - |   |   |   |     |
  * `----------------------------------------------------------------'
*/
[_GAM] = LAYOUT_65_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    KC_TAB,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,\
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,\
    _______, _______, _______,                _______,                          _______,  _______, _______, _______, _______, _______),

/* Keymap Numpad Layer
  * ,----------------------------------------------------------------.
  * |   |   |   |   |   |   |   |  7|  8|  9|  0|  -|  +|       |    |
  * |----------------------------------------------------------------|
  * |     |   |   |   |   |   |   |  4|  5|  6|  *|   |   |     |    |
  * |------------------------------------------------------.    |----|
  * |      |   |   |   |   |   |   |  1|  2|  3|  -|   |   |    |    |
  * |----------------------------------------------------------------|
  * |     |  |   |   |   |   |   |   |  0| . |  /|  +|      |   |    |
  * |----------------------------------------------------------------|
  * |    |    |    |                       |    |    |  |   |   |    |
  * `------------------------------------------------'  `------------'
*/
  [_NUM] = LAYOUT_65_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC, _______,\
    _______, FN_TAB4, _______, FN_ATAB, FN_CTL0, _______, _______, _______, _______, _______, FN_CTLW, FN_CTST,          _______, _______,\
    _______, FN_EKEY, FN_ALF4, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,\
    _______, _______, _______,                _______,                          _______,  _______, _______, _______, _______, _______),

/* Function Key Layer
  * ,----------------------------------------------------------------.
  * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |    |
  * |----------------------------------------------------------------|
  * |~  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       |Home|
  * |------------------------------------------------------.    |----|
  * |      |   |   |   |   |SF5|   |   |   |   |  -|SF11|SF12|  |    |
  * |----------------------------------------------------------------|
  * |     |  |   |   |   |   |   |   |   |   |   |   |      |   |    |
  * |----------------------------------------------------------------|
  * |    |    |    |                       |    |    |  |   |   |    |
  * `------------------------------------------------'  `------------'
*/
  [_FKL] = LAYOUT_65_ansi(
    _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, _______, _______, _______,\
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_BSPC, _______,\
    _______, FN_TAB4, _______, FN_ATAB, FN_CTL0, FN_FKL5, _______, _______, _______, _______, FN_CTLW, FN_CTST,          _______, _______,\
    _______, FN_EKEY, FN_ALF4, _______, _______, _______, _______, _______, _______, _______, _______,   MO(4),          _______, _______,\
    _______, _______, _______,                _______,                          _______,  _______, _______, _______, _______, _______),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FN_YKEY:
      if (record->event.pressed) {
        // Send Home + Shift (down) + End + Shift (up)
        // SEND_STRING("https://qmk.fml/" SS_TAP(X_ENTER));
        // SEND_STRING(SS_TAP(X_HOME) SS_DOWN(X_SHIFT) SS_TAP(X_END) SS_UP(X_SHIFT));
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

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}