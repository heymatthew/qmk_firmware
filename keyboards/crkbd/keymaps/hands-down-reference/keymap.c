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


// Hands Down Reference
// see https://sites.google.com/alanreiser.com/handsdown/home/hands-down-reference
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  C   H   P   V  │   BASE   │  K   Y   O   J  ╰───────╮
// │  Q   R   S   N   T   G  │          │  W   U   E   I   A   '" │
// ╰───╮  X   M   L   D   B  ╰───╮  ╭───╯  Z   F   ,?  .!  /- ╭───╯
//     ╰───────────╮ esc spc tab │  │ ent bsp esc ╭───────────╯
//                 ╰─────────sym─╯  ╰─num─────────╯
// Symbols and Mouse, vim arrows, loosely placed from C frequency
// see https://stackoverflow.com/a/62766162/81271
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯ mo2 mo1         │   SYM    │  `~  =+  ([  )] ╰───────╮ hyper+→ = home
// │     gui alt ctl sft mo3 │          │  ←   ↓   ↑   →   :;  \| │ hyper+↓ = pg down
// ╰───╮                     ╰───╮  ╭───╯  #@  _-  {<  }>  *& ╭───╯ sft+# = @
//     ╰───────────╮         xxx │  │  ^   %   $  ╭───────────╯
//                 ╰────────[sym]╯  ╰─────────────╯
// Numbers, arrows, media, and navigation
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  7   8   9   ^$ │   NUM    │ prv vol ply nxt ╰───────╮ sft+8 = F8
// │  -/  +*  4   5   6   %  │          │ mut sft ctl alt gui     │ sft+[ = (
// ╰───╮  ([  1   2   3   )] ╰───╮  ╭───╯     vol             ╭───╯
//     ╰───────────╮  .   0   =  │  │ xxx         ╭───────────╯
//                 ╰─────────────╯  ╰[num]────────╯

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_C,    KC_H,    KC_P,    KC_V,                          KC_K,    KC_Y,    KC_O,    KC_J,    XXXX,    XXXX,
        KC_Q,    R_GUI,   S_ALT,   N_CTL,   T_SFT,   KC_G,                          KC_W,    U_SFT,   E_CTL,   I_ALT,   A_GUI,   KC_QUOT,
        XXXX,    KC_X,    KC_M,    KC_L,    KC_D,    KC_B,                          KC_Z,    KC_F,    KC_COMM, KC_DOT,  KC_SLSH, XXXX,
                                            KC_ESC,  KC_SPC,  SYM_TAB,     NUM_ENT, KC_BSPC, KC_ESC
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_SYM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    MS_BTN2, MS_BTN1, XXXX,    XXXX,                          KC_GRV,  KC_EQL , KC_LPRN, KC_RPRN, XXXX,    XXXX,
        XXXX,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, MS_BTN3,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_BSLS,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          KC_HASH, KC_UNDS, KC_LCBR, KC_RCBR, KC_ASTR, XXXX,
                                            ____,    XXXX,    ____,        KC_CIRC, KC_PERC, KC_DLR
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_NUM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_7,    KC_8,    KC_9,    KC_CIRC,                       KC_MPRV, KC_VOLU, KC_MPLY, KC_MNXT, XXXX,    XXXX,
        KC_MINS, KC_PLUS, KC_4,    KC_5,    KC_6,    KC_PERC,                       KC_MUTE, KC_LSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXX,
        XXXX,    KC_LPRN, KC_1,    KC_2,    KC_3,    KC_RPRN,                       XXXX,    KC_VOLD, XXXX,    XXXX,    XXXX,    XXXX,
                                            KC_PDOT, KC_0,    KC_PEQL,     ____,    XXXX,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
};

const key_override_t *key_overrides[] = {
	&ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DELETE),       // sft+bsp = del

  // BASE
	&ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUESTION),            // sft+, = ?
	&ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_EXCLAIM),             // sft+. = !
	&ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_MINS),                // sft+/ = -

  // SYM
	&ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_MINUS),               // sft+_ = -
	&ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LEFT_BRACKET),        // sft+( = [
	&ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_RIGHT_BRACKET),       // sft+) = ]
	&ko_make_basic(MOD_MASK_CSAG,  KC_LEFT, KC_HOME),                // hyper+← = home
	&ko_make_basic(MOD_MASK_CSAG,  KC_DOWN, KC_PAGE_DOWN),           // hyper+↓ = pg down
	&ko_make_basic(MOD_MASK_CSAG,  KC_UP,   KC_PAGE_UP),             // hyper+↑ = pg up
	&ko_make_basic(MOD_MASK_CSAG,  KC_RGHT, KC_END),                 // hyper+→ = end
	&ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SEMICOLON),           // sft+: = ;
	&ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_AT),                  // sft+# = @
	&ko_make_basic(MOD_MASK_SHIFT, KC_EQL,  KC_PLUS),                // sft+= = +
	&ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_LEFT_ANGLE_BRACKET),  // sft+{ = <
	&ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_RIGHT_ANGLE_BRACKET), // sft+} = >
	&ko_make_basic(MOD_MASK_SHIFT, KC_ASTR, KC_AMPERSAND),           // sft+* = &

  // NUM
	&ko_make_basic(MOD_MASK_SHIFT, KC_CIRC, KC_DOLLAR),              // sft+^ = $
	&ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_SLASH),               // sft+- = /
	&ko_make_basic(MOD_MASK_SHIFT, KC_PLUS, KC_ASTERISK),            // sft++ = *
	&ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_F1),                     // sft+1 = F1
	&ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_F2),                     // sft+2 = F2
	&ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_F3),                     // sft+3 = F3
	&ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_F4),                     // sft+4 = F4
	&ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_F5),                     // sft+5 = F5
	&ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_F6),                     // sft+6 = F6
	&ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_F7),                     // sft+7 = F7
	&ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_F8),                     // sft+8 = F8
	&ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_F9),                     // sft+9 = F9
	&ko_make_basic(MOD_MASK_SHIFT, KC_PDOT, KC_F10),                 // sft+. = F11
	&ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_F11),                    // sft+0 = F10
	&ko_make_basic(MOD_MASK_SHIFT, KC_PEQL, KC_F12),                 // sft+= = F12
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
