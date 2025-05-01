/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2025 Matthew <@heymatthew>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            KC_LGUI, TT(1),   KC_SPC,      KC_LSFT, TT(2),   KC_RCTL
    //                                     +--------+--------+--------+   +--------+--------+--------+

  ),

    [1] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        XXXXXXX, KC_RSFT, KC_LGUI, KC_BTN2, KC_BTN1, KC_BTN3,                       XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        XXXXXXX, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            KC_LGUI, _______, KC_SPC,      KC_LSFT, TT(3),   KC_RCTL
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

    [2] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_DEL,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            KC_LGUI, TT(3),   KC_SPC,      KC_LSFT, _______, KC_RCTL
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

    [3] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        QK_BOOT, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            KC_LGUI, _______, KC_SPC,      KC_LSFT, _______, KC_RCTL
    //                                     +--------+--------+--------+   +--------+--------+--------+
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
