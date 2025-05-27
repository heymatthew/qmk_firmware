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
  L_NAVIGATION,
  L_NUMBER,
  L_SYM,
  L_FUNCTION
};

// Home Row Mod GACS
// https://precondition.github.io/home-row-mods#gacs
#define S_GUI MT(MOD_LGUI, KC_S)
#define N_ALT MT(MOD_LALT, KC_N)
#define R_ALT MT(MOD_LALT, KC_R)
#define T_SFT MT(MOD_LSFT, KC_T)
#define U_SFT MT(MOD_RSFT, KC_U)
#define E_CTL MT(MOD_RCTL, KC_E)
#define I_ALT MT(MOD_LALT, KC_I) // left hand alt to avoid macrons on osx
#define A_GUI MT(MOD_RGUI, KC_A)

// Thumb clusters
// reference https://docs.qmk.fm/keycodes
#define NAV_TAB LT(L_NAVIGATION, KC_TAB)
#define NUM_ENT LT(L_NUMBER, KC_ENT)

// Shorthand
#define ____ KC_TRNS       // Transparent
#define XXXX KC_NO         // NOOP
#define KC_REDO KC_AGIN    // Pairs with UNDO

// BASE
// xkcd layout https://sites.google.com/alanreiser.com/handsdown/home/more-variations
//  ╭─────────────────────╮          ╭─────────────────────╮ gacs home row mods
//  │  Q   M   H   G   Z  │          │  Y   F   O   B   '  │
//  │  S   N   R   T   P  │          │  W   U   E   I   A  │
//  │  X   K   C   D   J  ╰───╮  ╭───╯  V   L   ,   .   /  │
//  ╰───────────╮  ;  spc tab │  │ ent bsp esc ╭───────────╯
//              ╰─────────────╯  ╰─────────────╯
//                        sym      num
// SYM
// optimised on C symbol frequency https://stackoverflow.com/a/62766162/81271
// one handed mouse layer on left
//  ╭─────────────────────╮          ╭─────────────────────╮ key, sft, alt
//  │     mo2 mo1         │          │     &!  +@  #%  `~  │ sft+( = {
//  │ gui alt ctl sft mo3 │          │ ^$  _-  ({[ )}] *=  │ alt+( = [
//  │                     ╰───╮  ╭───╯     |\              │ mouse btns on left
//  ╰───────────╮ ;:  spc ___ │  │ ent bsp esc ╭───────────╯
//              ╰─────────────╯  ╰─────────────╯
//                       [sym]     num
// NUM
// arrows on left use alt, one handed media control on right
//  ╭─────────────────────╮          ╭─────────────────────╮
//  │ +*  7   8↑  9   ^%  │          │     vol ply prv nxt │ sft+1 = F1, sft+2 = F2...
//  │ -/  4←  5↓  6→  $!  │          │ mut sft ctl alt gui │ sft+- = /
//  │ ({[ 1   2   3   )}] ╰───╮  ╭───╯     vol             │
//  ╰───────────╮  .   0   =  │  │ ___ bsp esc ╭───────────╯
//              ╰─────────────╯  ╰─────────────╯
//                        sym     [num]
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_BASE] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    KC_Q,    KC_M,    KC_H,    KC_G,    KC_Z,                          KC_Y,    KC_F,    KC_O,    KC_B,    KC_QUOT, XXXX,
        XXXX,    S_GUI,   N_ALT,   R_ALT,   T_SFT,   KC_P,                          KC_W,    U_SFT,   E_CTL,   I_ALT,   A_GUI,   XXXX,
        XXXX,    KC_X,    KC_K,    KC_C,    KC_D,    KC_J,                          KC_V,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, XXXX,
                                            KC_SCLN, KC_SPC,  NAV_TAB,     NUM_ENT, KC_BSPC, KC_ESC
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  // SYM
  // optimised on C symbol frequency https://stackoverflow.com/a/62766162/81271
  // one handed mouse layer on left
  //  ╭─────────────────────╮          ╭─────────────────────╮ key, sft, alt
  //  │     mo2 mo1         │          │     &!  +@  #%  `~  │ sft+( = {
  //  │ gui alt ctl sft mo3 │          │ ^$  _-  ({[ )}] *=  │ alt+( = [
  //  │                     ╰───╮  ╭───╯     |\              │ mouse btns on left
  //  ╰───────────╮ ;:  spc ___ │  │ ent bsp esc ╭───────────╯
  //              ╰─────────────╯  ╰─────────────╯
  //                       [sym]     num

  [L_SYM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    MS_BTN2, MS_BTN1, XXXX,    XXXX,                          KC_CIRC, KC_EXLM, KC_ASTR, KC_HASH, KC_DLR,  XXXX,
        XXXX,    KC_LGUI, KC_LALT, KC_LCTL, XXXX,    MS_BTN3,                       KC_MINS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, XXXX,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          KC_PERC, KC_BSLS, KC_PLUS, KC_AMPR, KC_AT,   XXXX,
                                            XXXX,    XXXX,    ____,        KC_GRV,  KC_QUOT, XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  [L_NAVIGATION] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    MS_BTN2, MS_BTN1, XXXX,    XXXX,                          KC_REDO, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, XXXX,
        XXXX,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MS_BTN3,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, XXXX,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  XXXX,
                                            XXXX,    XXXX,    ____,        XXXX,    XXXX,    XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  [L_FUNCTION] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_VOLU,                       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_VOLD,                       XXXX,    KC_LSFT, KC_RGUI, KC_LALT, KC_RCTL, XXXX,
        XXXX,    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_MUTE,                       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                            KC_MPRV, KC_MPLY, KC_MNXT,     ____,    XXXX,    XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

  [L_NUMBER] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
        XXXX,    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                        XXXX,    KC_LSFT, KC_RGUI, KC_LALT, KC_RCTL, XXXX,
        XXXX,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_SLSH,                       XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                            KC_DOT,  KC_0,    KC_MINS,     XXXX,    ____,    XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),

};

  //  ╭─────────────────────╮          ╭─────────────────────╮ key, sft, alt
  //  │     mo2 mo1         │          │     &!  +@  #%  `~  │ sft+( = {
  //  │ gui alt ctl sft mo3 │          │ ^$  _-  ({[ )}] *=  │ alt+( = [
  //  │                     ╰───╮  ╭───╯     |\              │ mouse btns on left
  //  ╰───────────╮ ;:  spc ___ │  │ ent bsp esc ╭───────────╯
  //              ╰─────────────╯  ╰─────────────╯
  //                       [sym]     num

const key_override_t *key_overrides[] = {
	&ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DELETE),             // sft+bsp = del
	&ko_make_basic(MOD_MASK_SHIFT, KC_AMPERSAND, KC_EXCLAIM),            // sft+& = !
	&ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, KC_AT),                      // sft++ = @
	&ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_PERCENT),                 // sft+# = %
	&ko_make_basic(MOD_MASK_SHIFT, KC_CIRCUMFLEX, KC_DOLLAR),            // sft+^ = $
	&ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN, KC_LEFT_CURLY_BRACE)   // sft+( = {
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
