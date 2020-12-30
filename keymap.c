// *****************************************************************************
/* Copyright 2018 'mechmerlin'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License , or
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
/* NOTE: Previously, to build keyboard: make kbdfans/kbd67/rev2:arslan
    To build and flash keyboard on Linux system: 
        1) Set up user keyboard: "qmk config user.keyboard=kbdfans/kbd67/rev2"
        2) To compile: ''qmk compile''
        3) To compile: ''qmk flash''
*/ 
// *****************************************************************************
#include QMK_KEYBOARD_H
#include "my_keymap_config.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT_65_ansi(
        KC_ESC  , KC_1     , KC_2    , KC_3    , KC_4    , KC_5   , KC_6    , KC_7    , KC_8,     KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC , KC_HOME ,\
        FN_TAB  , KC_Q     , KC_W    , KC_E    , KC_R    , KC_T   , KC_Y    , KC_U    , KC_I,     KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_BSPC , KC_PGUP ,\
        FN_CAPS , KC_A     , KC_S    , KC_D    , KC_F    , KC_G   , KC_H    , KC_J    , KC_K,     KC_L    , KC_SCLN , KC_QUOT , KC_ENT            , KC_PGDN ,\
        KC_LSFT , KC_Z     , KC_X    , KC_C    , KC_V    , KC_B   , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT           , KC_UP   , KC_DEL  ,\
        KC_LCTL , KC_LGUI  , KC_LALT ,                          FN_SPACE                        , MO(_NUM), KC_RALT , KC_RCTL , KC_LEFT , KC_DOWN , KC_RGHT
    ),
    [_FUN] = LAYOUT_65_ansi(
        KC_GRV  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ ,\
        _______ , FN_CTL1 , FN_CTL2 , FN_CTL3 , FN_CTL4 , _______ , FN_YKEY , KC_PGUP , KC_UP   , KC_PGDN , KC_BSPC , _______ , _______ , KC_BSLS , _______ ,\
        KC_GRV  , FN_TAB4 , _______ , FN_ATAB , FN_CTL0 , FN_CSH0 , KC_HOME , KC_LEFT , KC_DOWN , KC_RGHT , FN_CTLW , FN_CTST , _______           , KC_MPLY ,\
        _______ , FN_EKEY , FN_ALF4 , _______ , _______ , _______ , KC_END  , KC_DEL  , _______ , _______ , _______ , _______           , KC_VOLU , KC_MUTE ,\
        _______ , _______ , _______ ,                          _______                          , _______ , KC_RCTL , KC_RALT , KC_MPRV , KC_VOLD , KC_MNXT
    ),
    [_MOU] = LAYOUT_65_ansi(
        _______ , _______ , _______ , _______ , _______ , RGB_HUD , RGB_HUI , RGB_SAI , RGB_SAD , RGB_MOD , RGB_TOG , RGB_VAD , RGB_VAI , _______ , _______ ,\
        _______ , KC_BTN1 , KC_MS_U , KC_BTN2 , KC_WH_U , _______ , _______ , KC_WH_U , KC_MS_U , KC_WH_D , _______ , _______ , _______ , _______ , _______ ,\
        _______ , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D , _______ , _______ , KC_MS_L , KC_MS_D , KC_MS_R , _______ , _______ , _______           , _______ ,\
        _______ , FN_CTAD , RESET   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______           , KC_BRIU , _______ ,\
        _______ , _______ , _______ ,                          _______                          , _______ , _______ , _______ , _______ , KC_BRID , _______ 
    ),
    [_NUM] = LAYOUT_65_ansi(
        _______ , KC_0    , KC_MINS , KC_EQL  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,\
        _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , _______ , _______ ,\
        _______ , KC_4    , KC_5    , KC_6    , _______ , _______ , _______ , _______ , _______ , KC_L    , _______ , _______ , _______           , _______ ,\
        _______ , KC_7    , KC_8    , KC_9    , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ ,\
        _______ , _______ , _______ ,                          _______                          , _______ , _______ , _______ , _______ , _______ , _______ 
    ),
    [_FKL] = LAYOUT_65_ansi(
        _______ , KC_F10  , KC_F11  , KC_F12  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,\
        _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ ,\
        _______ , KC_F4   , KC_F5   , KC_F6   , _______ , _______ , _______ , _______ , _______ , KC_L    , _______ , _______ , _______           , _______ ,\
        _______ , KC_F7   , KC_F8   , KC_F9   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ ,\
        _______ , _______ , _______ ,                          _______                          , _______ , _______ , _______ , _______ , _______ , _______ 
    ),

};