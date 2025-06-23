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
#define R_GUI MT(MOD_LGUI, KC_R)
#define S_ALT MT(MOD_LALT, KC_S)
#define N_CTL MT(MOD_LCTL, KC_N)
#define D_SFT MT(MOD_LSFT, KC_D)
#define A_SFT MT(MOD_RSFT, KC_A)
#define E_CTL MT(MOD_RCTL, KC_E)
#define I_ALT MT(MOD_LALT, KC_I) // uses left hand alt to avoid OSX macrons
#define H_GUI MT(MOD_RGUI, KC_H)

// Shorthand
#define ____ KC_TRNS       // Transparent
#define XXXX KC_NO         // NOOP
#define KC_REDO KC_AGIN    // Pairs with UNDO
#define SYM_ENT LT(L_SYM, KC_TAB)
#define NUM_BSP LT(L_NUM, KC_BSPC)


// Hands Down Gold
// see https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  G   M   P   V  │   BASE   │  ;:  .&  /*  "? ╰───────╮
// │  J   R   S   N   D   B  │          │  ,|  A   E   I   H   '! │
// ╰───╮  X   F   L   C   W  ╰───╮  ╭───╯  -+  U   O   Y   K  ╭───╯
//     ╰───────────╮  Q  sym  T  │  │ spc num  Z  ╭───────────╯
//      X+C = esc  ╰─────────────╯  ╰─────────────╯  U+K = tab
//      F+L = ent                                sft+spc = bsp
//
// Symbols and Mouse, vim arrows, symbols based on C frequency
// see https://stackoverflow.com/a/62766162/81271
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯ mo2 mo1         │   SYM    │      #@  ([  )] ╰───────╮ hyper+→ = home
// │     gui alt ctl sft mo3 │          │  ←   ↓   ↑   →   _=     │ hyper+↓ = pg down
// ╰───╮                     ╰───╮  ╭───╯      `~  {<  }>  \  ╭───╯ sft+# = @
//     ╰───────────╮     xxx     │  │  ^$  %   $  ╭───────────╯
//                 ╰─────────────╯  ╰─────────────╯
//
// NUM: Numbers, arrows, media, and navigation
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  7   8   9   ^$ │   NUM    │ prv vol ply nxt ╰───────╮ sft+8 = F8
// │  /*  -+  4   5   6   %  │          │ mut sft ctl alt gui     │ sft+[ = (
// ╰───╮  ([  1   2   3   )] ╰───╮  ╭───╯     vol             ╭───╯
//     ╰───────────╮  .   0   =  │  │     xxx     ╭───────────╯
//                 ╰─────────────╯  ╰─────────────╯

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_G,    KC_M,    KC_P,    KC_V,                          KC_SCLN, KC_DOT,  KC_SLSH, KC_DQUO, XXXX,    XXXX,
        KC_J,    R_GUI,   S_ALT,   N_CTL,   D_SFT,   KC_B,                          KC_COMM, A_SFT,   E_CTL,   I_ALT,   H_GUI,   KC_QUOT,
        XXXX,    KC_X,    KC_F,    KC_L,    KC_C,    KC_W,                          KC_MINS, KC_U,    KC_O,    KC_Y,    KC_K,    XXXX,
                                            KC_Q,    SYM_ENT, KC_T,        KC_SPC,  NUM_BSP, KC_Z
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_SYM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    MS_BTN2, MS_BTN1, XXXX,    XXXX,                          XXXX,    KC_HASH, KC_LPRN, KC_RPRN, XXXX,    XXXX,
        XXXX,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MS_BTN3,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_UNDS, XXXX,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          XXXX,    KC_GRV,  KC_LCBR, KC_RCBR, KC_BSLS, XXXX,
                                            ____,    XXXX,    ____,        KC_CIRC, KC_PERC, KC_DLR
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_NUM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_7,    KC_8,    KC_9,    KC_CIRC,                       KC_MPRV, KC_VOLU, KC_MPLY, KC_MNXT, XXXX,    XXXX,
        KC_SLSH, KC_MINS, KC_4,    KC_5,    KC_6,    KC_PERC,                       KC_MUTE, KC_LSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXX,
        XXXX,    KC_LPRN, KC_1,    KC_2,    KC_3,    KC_RPRN,                       XXXX,    KC_VOLD, XXXX,    XXXX,    XXXX,    XXXX,
                                            KC_PDOT, KC_0,    KC_PEQL,     ____,    XXXX,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
};

const key_override_t *key_overrides[] = {
	&ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DELETE),       // sft+bsp = del

  // BASE
	&ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_AMPERSAND),           // sft+. = &
	&ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_ASTERISK),            // sft+/ = *
	&ko_make_basic(MOD_MASK_SHIFT, KC_DQUO, KC_QUES),                // sft+" = ?
	&ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_PIPE),                // sft+, = |
	&ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_EXCLAIM),             // sft+' = !
	&ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_PLUS),                // sft+- = +

  // SYM
	&ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_AT),                  // sft+# = @
	&ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LEFT_BRACKET),        // sft+( = [
	&ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RIGHT_BRACKET),       // sft+) = ]
	&ko_make_basic(MOD_MASK_CSAG,  KC_LEFT, KC_HOME),                // hyper+← = home
	&ko_make_basic(MOD_MASK_CSAG,  KC_DOWN, KC_PAGE_DOWN),           // hyper+↓ = pg down
	&ko_make_basic(MOD_MASK_CSAG,  KC_UP,   KC_PAGE_UP),             // hyper+↑ = pg up
	&ko_make_basic(MOD_MASK_CSAG,  KC_RGHT, KC_END),                 // hyper+→ = end
	&ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_EQUAL),               // sft+_ = =
	&ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_LEFT_ANGLE_BRACKET),  // sft+{ = <
	&ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_RIGHT_ANGLE_BRACKET), // sft+} = >
	&ko_make_basic(MOD_MASK_SHIFT, KC_CIRC, KC_DOLLAR),              // sft+^ = $

  // NUM
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

//      X+C = esc  ╰─────────────╯  ╰─────────────╯  U+K = tab
//      F+L = ent                                sft+spc = bsp
const uint16_t PROGMEM chord_x_c[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM chord_u_k[] = {KC_U, KC_K, COMBO_END};
const uint16_t PROGMEM chord_f_l[] = {KC_U, KC_K, COMBO_END};
combo_t key_combos[] = {
  COMBO(chord_x_c, KC_ESC), // X+C = esc 
  COMBO(chord_u_k, KC_TAB), // U+K = tab
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
