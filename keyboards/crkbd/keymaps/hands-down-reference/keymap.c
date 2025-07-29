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

// L_BASE, Hands Down Reference optimised for rolls
// forked from https://sites.google.com/alanreiser.com/handsdown/home/hands-down-reference
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  C   H   P   V  │          │  K   Y   O   J  ╰───────╮ sft+, = ?
// │  Q   R   S   N   T   G  │          │  W   U   E   I   A   '" │ sft+. = !
// ╰───╮  X   M   L   D   B  ╰───╮  ╭───╯  Z   F   ,?  .!  /- ╭───╯ sft+/ = -
//     ╰───────────╮  :  spc tab │  │ ent bsp esc ╭───────────╯
//                 ╰─num─────nav─╯  ╰─sym─────────╯
//
// L_NUM, a calculator with a hint of danger
//         ╭─────────────────╮          ╭─────────────────╮         sft+1 = F1
// ╭───────╯  (   )   e      │          │      7   8   9  ╰───────╮ sft+0 = F10
// │      *   /   +   -      │          │  .   1   2   3   0      │ sft+% = F11
// ╰───╮  ^   [   ]   =      ╰───╮  ╭───╯      4   5   6   %  ╭───╯ sft+. = F12
//     ╰───────────╮ xxx         │  │ ent bsp esc ╭───────────╯     cmd+- = shrink term font
//                 ╰[num]────────╯  ╰─────────────╯                 cmd+= = grow term font
//
// L_NAV, mouse, media, pagination, and arrow complete package
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯ mo2 mo1 vol     │          │ hme pgd pgu end ╰───────╮
// │ prv gui alt ctl sft mo3 │          │  ←   ↓   ↑   →      nxt │
// ╰───╮         ply vol     ╰───╮  ╭───╯                     ╭───╯
//     ╰───────────╮         xxx │  │ ent bsp esc ╭───────────╯
//                 ╰────────[nav]╯  ╰─────────────╯
//
// L_SYM, Optimised rolls for Go, JavaScript, and Bash
// forked from https://getreuer.info/posts/keyboards/symbol-layer/index.html#my-symbol-layer
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  <   >   -      │          │      ^   %   $  ╰───────╮
// │  ~   !   *   /   =   &  │          │  @   #   (   )   ;   `  │
// ╰───╮  :   +   [   ]      ╰───╮  ╭───╯      _   {   }   |  ╭───╯
//     ╰───────────╮  :  spc tab │  │ xxx         ╭───────────╯
//                 ╰─────────────╯  ╰[sym]────────╯

#include QMK_KEYBOARD_H

enum layers {
  L_BASE,
  L_NUM,
  L_NAV,
  L_SYM,
};

// Home Row Mods, GACS
// https://precondition.github.io/home-row-mods#gacs
#define R_GUI MT(MOD_LGUI, KC_R)
#define S_ALT MT(MOD_LALT, KC_S)
#define N_CTL MT(MOD_LCTL, KC_N)
#define T_SFT MT(MOD_LSFT, KC_T)
#define U_SFT MT(MOD_RSFT, KC_U)
#define E_CTL MT(MOD_RCTL, KC_E)
#define I_ALT MT(MOD_LALT, KC_I) // left alt avoids macrons in OSX
#define A_GUI MT(MOD_RGUI, KC_A)

// Shorthands
#define ____ KC_TRNS     // Transparent
#define XXXX KC_NO       // NOOP
#define KC_REDO KC_AGIN  // Pairs with UNDO
#define NUM_COL LT(L_NUM, KC_COLN)
#define TAB_NAV LT(L_NAV, KC_TAB)
#define ENT_SYM LT(L_SYM, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_C,    KC_H,    KC_P,    KC_V,                          KC_K,    KC_Y,    KC_O,    KC_J,    XXXX,    XXXX,
        KC_Q,    R_GUI,   S_ALT,   N_CTL,   T_SFT,   KC_G,                          KC_W,    U_SFT,   E_CTL,   I_ALT,   A_GUI,   KC_QUOT,
        XXXX,    KC_X,    KC_M,    KC_L,    KC_D,    KC_B,                          KC_Z,    KC_F,    KC_COMM, KC_DOT,  KC_SLSH, XXXX,
                                            NUM_COL, KC_SPC,  TAB_NAV,     ENT_SYM, KC_BSPC, KC_ESC
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_NUM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_LPRN, KC_RPRN, KC_E,    XXXX,                          XXXX,    KC_7,    KC_8,    KC_9,    XXXX,    XXXX,
        XXXX,    KC_ASTR, KC_SLSH, KC_PLUS, KC_MINS, XXXX,                          KC_PDOT, KC_1,    KC_2,    KC_3,    KC_0,    XXXX,
        XXXX,    KC_CIRC, KC_LBRC, KC_RBRC, KC_EQL,  XXXX,                          XXXX,    KC_4,    KC_5,    KC_6,    KC_PERC, XXXX,
                                            XXXX,    ____,    ____,        ____,    ____,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_NAV] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    MS_BTN2, MS_BTN1, KC_VOLU, XXXX,                          KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXX,    XXXX,
        KC_MPRV, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MS_BTN3,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXX,    KC_MNXT,
        XXXX,    XXXX,    XXXX,    KC_MPLY, KC_VOLD, XXXX,                          XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,
                                            ____,    ____,    XXXX,        ____,    ____,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_SYM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_LABK, KC_RABK, KC_MINS, XXXX,                          XXXX,    KC_CIRC, KC_PERC, KC_DLR,  XXXX,    XXXX,
        KC_TILD, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,                       KC_AT,   KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_GRV,
        XXXX,    KC_COLN, KC_PLUS, KC_LBRC, KC_RBRC, XXXX,                          XXXX,    KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE, XXXX,
                                            ____,    ____,    ____,        XXXX,    ____,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
};

const key_override_t *key_overrides[] = {
	&ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DELETE),   // sft+bsp = del

  // L_BASE
	&ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUESTION),      // sft+, = ?
	&ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_EXCLAIM),       // sft+. = !
	&ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_MINS),          // sft+/ = -

  // L_NUM
	&ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_F1),                     // sft+1 = F1
	&ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_F2),                     // sft+2 = F2
	&ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_F3),                     // sft+3 = F3
	&ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_F4),                     // sft+4 = F4
	&ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_F5),                     // sft+5 = F5
	&ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_F6),                     // sft+6 = F6
	&ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_F7),                     // sft+7 = F7
	&ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_F8),                     // sft+8 = F8
	&ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_F9),                     // sft+9 = F9
	&ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_F10),                    // sft+0 = F10
	&ko_make_basic(MOD_MASK_SHIFT, KC_PERC, KC_F11),                 // sft+% = F11
	&ko_make_basic(MOD_MASK_SHIFT, KC_PDOT, KC_ASTERISK),            // sft+. = F12
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
