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

// see https://github.com/manna-harbour/miryoku/tree/master/docs/reference
enum layers {
  L_BASE,
  L_NAV,
  L_NUM,
  L_SYM,
  L_FUN
};

// Home Row Mod CAGS for OSX
// layout https://precondition.github.io/home-row-mods
#define CTL_A   MT(MOD_LCTL, KC_A)
#define ALT_S   MT(MOD_LALT, KC_S)
#define GUI_D   MT(MOD_LGUI, KC_D)
#define SFT_F   MT(MOD_LSFT, KC_F)

#define SFT_J   MT(MOD_RSFT, KC_J)
#define GUI_K   MT(MOD_RGUI, KC_K)
#define ALT_L   MT(MOD_LALT, KC_L) // left hand alt to avoid macrons on osx
#define CTL_SC  MT(MOD_RCTL, KC_SCLN)

// Thumb clusters
// reference https://docs.qmk.fm/keycodes
#define NAV_SPC LT(L_NAV, KC_SPC)
#define SYM_TAB LT(L_SYM, KC_TAB)
#define FUN_ENT LT(L_FUN, KC_ENT)
#define NUM_BSP LT(L_NUM, KC_BSPC)

// Shorthand
#define ____ KC_TRNS       // Transparent
#define XXXX KC_NO         // NOOP
#define KC_REDO KC_AGIN    // Pairs with UNDO

// Miryoku-inspired layout with the following variations
// * QWERTY base layer (vim muscle memory)
// * Home Row Mods are CAGS to optimise for OSX
// * Mouse layer is LHS to pair with pointing device
// * No button layer
// * Layer lock on same hand as toggle
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    XXXX,    XXXX,
        KC_Q,    CTL_A,   ALT_S,   GUI_D,   SFT_F,   KC_G,                          KC_H,    SFT_J,   GUI_K,   ALT_L,   CTL_SC,  KC_P,
        XXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            KC_ESC,  NAV_SPC, SYM_TAB,     FUN_ENT, NUM_BSP, KC_DEL
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  [L_NAV] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    MS_BTN3,                       KC_REDO, KC_PSTE, KC_COPY, KC_CUT,  XXXX,    XXXX,
        QK_LLCK, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, MS_BTN1,                       KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDO,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    MS_BTN2,                       KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            XXXX,    ____,    XXXX,        XXXX,    XXXX,    XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  [L_NUM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_7,    KC_8,    KC_9,    KC_RBRC,                       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        KC_LBRC, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                        XXXX,    KC_LSFT, KC_RGUI, KC_LALT, KC_RCTL, QK_LLCK,
        XXXX,    KC_CIRC, KC_1,    KC_2,    KC_3,    KC_BSLS,                       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            KC_DOT,  KC_0,    KC_MINS,     XXXX,    ____,    XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  [L_SYM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_AMPR, KC_ASTR, KC_QUOT, KC_RCBR,                       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        KC_LCBR, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                       XXXX,    KC_LSFT, KC_RGUI, KC_LALT, KC_RCTL, QK_LLCK,
        XXXX,    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            XXXX,    XXXX,    ____,        KC_UNDS, KC_LBRC, KC_RBRC
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  [L_FUN] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_F7,   KC_F8,   KC_F9,   KC_VOLU,                       KC_PSCR, XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        KC_F12,  KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_VOLD,                       KC_BRMU, KC_LSFT, KC_RGUI, KC_LALT, KC_RCTL, QK_LLCK,
        XXXX,    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_MUTE,                       KC_BRMD, XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            KC_MPRV, KC_MNXT, KC_MPLY,     ____,    XXXX,    XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

    // L_BASE
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
    //                       W        E        R        T                            Y          U         I       O
    //     Q,    CTL A,   ALT S,   D GUI,   F SHIFT     G                            H        SHIFT J   GUI K    ALT L   CTL ; :   KC_P
    //           KC_Z,       X,       C,    KC_V,       B                            N          M     , and <  . and >  / and ?
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
    //                                         ESC   NAV_SPC  SYM_TAB      FUN_ENT  NUM_BSP     DEL
    //                                     +--------+--------+--------+   +--------+--------+--------+

    // L_NAV: NAVIGATION
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
    //                                               MOUSE 3                         REDO   PASTE      COPY     CUT
    //   [LOCK]    CTRL     ALT      GUI     SHIFT   MOUSE 1                       CAPS LCK  LEFT      DOWN      UP     RGHT     UNDO
    //                                               MOUSE 2                        INSERT   HOME     PGDN      PGUP    END
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
    //                                                [PUSH]
    //                                     +--------+--------+--------+   +--------+--------+--------+

    // L_SYM: SYMBOL
    // TODO Where should ' and " go? These are traded for ; in querty.
    // TODO Note, ' doesn't correspond to 9 on the keeb like in NUMBER
    // TODO Consider removing, all present in NUMBER
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
    //                       &        *         '       }
    //      {        :       $        %         ^       +                                      SHIFT    GUI     ALT      CTRL     [LOCK]
    //               ~       !        @         #       |
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
    //                                                         [PUSH]           _        (        )
    //                                     +--------+--------+--------+   +--------+--------+--------+

    // L_FUN: FUNCTION
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
    //                      F7,       F8,      F9,   VOL DOWN                       PRINT
    //    F12,    F11,      F4,       F5,      F6,   VOL UP                         LIGHTER   SHIFT     GUI     ALT       CTRL   [LOCK]
    //            F10,      F1,       F2,      F3,   MUTE                           DARKER
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
    //                                      PREV     NEXT    (UN)PAUSE      [PUSH]
    //                                     +--------+--------+--------+   +--------+--------+--------+

    // L_NUM: NUMBER
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
    //                    7 and &  8 and *  9 and (  ] and }
    //  [ and {  ; and :  4 and $  5 and %  6 and ^  = and +                                  SHIFT    GUI      ALT      CTRL     [LOCK]
    //           ` and ~  1 and !  2 and @  3 and #  \ and |
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
    //                                      . and >  0 and )  - and _                [PUSH]
    //                                     +--------+--------+--------+   +--------+--------+--------+

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
