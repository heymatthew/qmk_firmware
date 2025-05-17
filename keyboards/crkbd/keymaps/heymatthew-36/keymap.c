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

// Home Row Mod GACS
// https://precondition.github.io/home-row-mods#gacs
#define GUI_A   MT(MOD_LGUI, KC_A)
#define ALT_S   MT(MOD_LALT, KC_S)
#define CTL_D   MT(MOD_LCTL, KC_D)
#define SFT_F   MT(MOD_LSFT, KC_F)

#define SFT_J   MT(MOD_RSFT, KC_J)
#define CTL_K   MT(MOD_RCTL, KC_K)
#define ALT_L   MT(MOD_LALT, KC_L) // left hand alt to avoid macrons on osx
#define GUI_SC  MT(MOD_RGUI, KC_SCLN)

// Thumb clusters
// reference https://docs.qmk.fm/keycodes
#define NAV_TAB LT(L_NAV, KC_TAB)
#define SYM_SPC LT(L_SYM, KC_SPC)
#define FUN_ENT LT(L_FUN, KC_ENT)
#define NUM_ESC LT(L_NUM, KC_ESC)

// Shorthand
#define ____ KC_TRNS       // Transparent
#define XXXX KC_NO         // NOOP
#define KC_REDO KC_AGIN    // Pairs with UNDO

// Miryoku-inspired layout with the following variations
// * QWERTY base layer (vim muscle memory)
// * Mouse keys on NAV pair with right handed pointing device
// * No button layer
// * Layer lock on same hand as toggle
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_BASE] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXX,
        XXXX,    GUI_A,   ALT_S,   CTL_D,   SFT_F,   KC_G,                          KC_H,    SFT_J,   CTL_K,   ALT_L,   GUI_SC,  XXXX,
        XXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            XXXX,    SYM_SPC, NAV_TAB,     FUN_ENT, NUM_ESC, KC_BSPC
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  [L_SYM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    MS_BTN2, MS_BTN1, XXXX,    XXXX,                          KC_CIRC, KC_EXLM, KC_ASTR, KC_HASH, KC_DLR,  XXXX,
        XXXX,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MS_BTN3,                       KC_MINS, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, XXXX,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          KC_PERC, KC_BSLS, KC_PLUS, KC_AMPR, KC_AT,   XXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            XXXX,    ____,    XXXX,        KC_GRV,  KC_QUOT, XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  [L_NAV] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    MS_BTN2, MS_BTN1, XXXX,    XXXX,                          KC_REDO, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, XXXX,
        XXXX,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MS_BTN3,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, XXXX,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  XXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            XXXX,    XXXX,    ____,        XXXX,    XXXX,    XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  [L_FUN] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_VOLU,                     XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_VOLD,                       XXXX,    KC_LSFT, KC_RGUI, KC_LALT, KC_RCTL, XXXX,
        XXXX,    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_MUTE,                       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            KC_MPRV, KC_MPLY, KC_MNXT,     ____,    XXXX,    XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  [L_NUM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                        XXXX,    KC_LSFT, KC_RGUI, KC_LALT, KC_RCTL, XXXX,
        XXXX,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_SLSH,                       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
    // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
                                            KC_DOT,  KC_0,    KC_MINS,     XXXX,    ____,    XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  // L_BASE
  // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
  //             Q         W        E        R        T                             Y          U         I       O        P
  //           GUI A    ALT S    D CTRL    F SHIFT     G                            H        SHIFT J   CTRL K   ALT L   GUI ; :
  //             Z        X        C         V        B                             N          M      , and <  . and >  / and ?
  // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
  //                                                SYM_SPC  NAV_TAB      FUN_ENT  NUM_ESC BACKSPCE
  //                                     +--------+--------+--------+   +--------+--------+--------+

  // L_SYM
  // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
  //                     MOUSE 2  MOUSE 1                                            ^        !         *      #        $
  //             GUI      ALT      CTRL    SHIFT    MOUSE 3                        - or _     (         )      [ or {   ] or }
  //                                                                                 %      \ or |     +        &         @
  // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
  //                                               [PUSH]                 ` or ~   ' or "
  //                                     +--------+--------+--------+   +--------+--------+--------+

  // L_NAV
  // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
  //                     MOUSE 2  MOUSE 1                                          REDO     PASTE     COPY    CUT       UNDO
  //             GUI      ALT      CTRL    SHIFT    MOUSE 3                        LEFT     DOWN      UP      RGHT     CAPS LCK
  //                                                                               HOME     PGDN      PGUP    END      INSERT
  // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
  //                                                         [PUSH]
  //                                     +--------+--------+--------+   +--------+--------+--------+


  // L_FUN
  // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
  //            F12       F7,       F8,      F9,   VOL DOWN
  //            F11,      F4,       F5,      F6,   VOL UP                                  SHIFT    CTRL      ALT      GUI
  //            F10,      F1,       F2,      F3,   MUTE
  // +--------+--------+--------+--------+--------+--------+--------+   +--------+--------+--------+--------+--------+--------+--------+
  //                                      PREV      PLAY     NEXT         [PUSH]
  //                                     +--------+--------+--------+   +--------+--------+--------+

  // L_NUM
  // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
  //           [ or {   7 and &  8 and *  9 and (   ] or }
  //           ; and :  4 and $  5 and %  6 and ^   = and +                                 SHIFT    CTRL      ALT      GUI
  //           ` and ~  1 and !  2 and @  3 and #   / and ?
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
