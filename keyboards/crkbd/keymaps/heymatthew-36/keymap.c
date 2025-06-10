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

enum layers {
  L_BASE,
  L_NUM,
  L_SYM,
};

// Home Row Mod GACS
// https://precondition.github.io/home-row-mods#gacs
#define S_GUI MT(MOD_LGUI, KC_S)
#define N_ALT MT(MOD_LALT, KC_N)
#define R_CTL MT(MOD_LCTL, KC_R)
#define T_SFT MT(MOD_LSFT, KC_T)
#define U_SFT MT(MOD_RSFT, KC_U)
#define E_CTL MT(MOD_RCTL, KC_E)
#define I_ALT MT(MOD_LALT, KC_I) // uses left hand alt to avoid OSX macrons
#define A_GUI MT(MOD_RGUI, KC_A)

// Shorthand
#define ____ KC_TRNS       // Transparent
#define XXXX KC_NO         // NOOP
#define KC_REDO KC_AGIN    // Pairs with UNDO
#define SYM_TAB LT(L_SYM, KC_TAB)
#define NUM_ENT LT(L_NUM, KC_ENT)

//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  M   H   G   Z  │   BASE   │  Y   F   O   B  ╰───────╮
// │  Q   S   N   R   T   P  │          │  W   U   E   I   A   '  │
// ╰───╮  X   K   C   D   J  ╰───╮  ╭───╯  V   L   ,   .   /  ╭───╯
//     ╰───────────╮  ;  spc tab │  │ ent bsp esc ╭───────────╯
//                 ╰─────────────╯  ╰─────────────╯
//                          sym      num
// xkcd layout
// see https://sites.google.com/alanreiser.com/handsdown/home/more-variations
//
//
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯ mo2 mo1         │   SYM    │     &!  +@  #%  ╰───────╮
// │     gui alt ctl sft mo3 │          │ ^$  -_  ({[ )}] *=  `~  │
// ╰───╮                     ╰───╮  ╭───╯     |\              ╭───╯
//     ╰───────────╮ ;:  spc ___ │  │ ent bsp esc ╭───────────╯
//                 ╰─────────────╯  ╰─────────────╯
//                          [sym]     num
// optimised on C symbol frequency, one handed mouse layer on left
// see https://stackoverflow.com/a/62766162/81271
//
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  7   8↑  9   !% │   NUM    │     vol ply prv ╰───────╮
// │  -/  +*  4←  5↓  6→  ^$ │          │ mut sft ctl alt gui nxt │
// ╰───╮  ({[ 1   2   3   )}]╰───╮  ╭───╯     vol             ╭───╯
//     ╰───────────╮  .   0   =  │  │ ___ bsp esc ╭───────────╯
//                 ╰─────────────╯  ╰─────────────╯
//                           sym     [num]
// arrows on left use alt, one handed media control on right

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_M,    KC_H,    KC_G,    KC_Z,                          KC_Y,    KC_F,    KC_O,    KC_B,    XXXX,    XXXX,
        KC_Q,    S_GUI,   N_ALT,   R_CTL,   T_SFT,   KC_P,                          KC_W,    U_SFT,   E_CTL,   I_ALT,   A_GUI,   KC_QUOT,
        XXXX,    KC_X,    KC_K,    KC_C,    KC_D,    KC_J,                          KC_V,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, XXXX,
                                            KC_SCLN, KC_SPC,  SYM_TAB,     NUM_ENT, KC_BSPC, KC_ESC
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_SYM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    MS_BTN2, MS_BTN1, XXXX,    XXXX,                          XXXX,    KC_AMPR, KC_PLUS, KC_HASH, XXXX,    XXXX,
        XXXX,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MS_BTN3,                       KC_CIRC, KC_MINS, KC_LPRN, KC_RPRN, KC_ASTR, KC_GRAVE,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          XXXX,    KC_PIPE, XXXX,    XXXX,    XXXX,    XXXX,
                                            ____,    ____,    XXXX,        ____,    ____,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_NUM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_7,    KC_8,    KC_9,    KC_EXLM,                       KC_MPRV, KC_VOLU, KC_MPLY, KC_MNXT, XXXX,    XXXX,
        KC_PMNS, KC_PPLS, KC_4,    KC_5,    KC_6,    KC_CIRC,                       KC_MUTE, KC_LSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXX,
        XXXX,    KC_LPRN, KC_1,    KC_2,    KC_3,    KC_RPRN,                       XXXX,    KC_VOLD, XXXX,    XXXX,    XXXX,    XXXX,
                                            KC_PDOT, KC_0,    KC_PEQL,     XXXX,    ____,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
};

const key_override_t *key_overrides[] = {
	&ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DELETE),       // sft+bsp = del

  // SYM
	&ko_make_basic(MOD_MASK_SHIFT, KC_AMPR, KC_EXCLAIM),           // sft+& = !
	&ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, KC_AT),                // sft++ = @
	&ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_PERCENT),           // sft+# = %
	&ko_make_basic(MOD_MASK_SHIFT, KC_CIRC, KC_DOLLAR),            // sft+^ = $
	&ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LEFT_CURLY_BRACE),  // sft+( = {
	&ko_make_basic(MOD_MASK_ALT,   KC_LPRN, KC_LEFT_BRACKET),      // alt+( = [
	&ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RIGHT_CURLY_BRACE), // sft+) = }
	&ko_make_basic(MOD_MASK_ALT,   KC_RPRN, KC_RIGHT_BRACKET),     // alt+) = ]
	&ko_make_basic(MOD_MASK_SHIFT, KC_ASTR, KC_EQUAL),             // sft+* = =
	&ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, KC_BACKSLASH),         // sft+* = backslash

  // NUM
	&ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_ASTERISK),          // sft++ = *
	&ko_make_basic(MOD_MASK_SHIFT, KC_PMNS, KC_SLASH),             // sft+- = /
	&ko_make_basic(MOD_MASK_SHIFT, KC_EXLM, KC_PERCENT),           // sft+! = %
	&ko_make_basic(MOD_MASK_ALT,   KC_8, KC_UP),                   // alt+8 = up
	&ko_make_basic(MOD_MASK_ALT,   KC_5, KC_DOWN),                 // alt+5 = down
	&ko_make_basic(MOD_MASK_ALT,   KC_6, KC_RIGHT),                // alt+6 = right
	&ko_make_basic(MOD_MASK_ALT,   KC_4, KC_LEFT),                 // alt+4 = left
	&ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_F1),                   // sft+1 = F1
	&ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_F2),                   // sft+2 = F2
	&ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_F3),                   // sft+3 = F3
	&ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_F4),                   // sft+4 = F4
	&ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_F5),                   // sft+5 = F5
	&ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_F6),                   // sft+6 = F6
	&ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_F7),                   // sft+7 = F7
	&ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_F8),                   // sft+8 = F8
	&ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_F9),                   // sft+9 = F9
	&ko_make_basic(MOD_MASK_SHIFT, KC_PDOT, KC_F10),               // sft+. = F11
	&ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_F11),                  // sft+0 = F10
	&ko_make_basic(MOD_MASK_SHIFT, KC_PEQL, KC_F12),               // sft+= = F12
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
