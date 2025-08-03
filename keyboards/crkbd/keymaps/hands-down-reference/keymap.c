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

// L_BASE, comfortable wordsmithing
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  C   H   P   V  │          │  K   Y   O   J  ╰───────╮ sft+, = ?
// │  Q   R   S   N   T   G  │          │  W   U   E   I   A   '" │ sft+. = !
// ╰───╮  X   M   L   D   B  ╰───╮  ╭───╯  Z   F   ,?  .!  -_ ╭───╯ sft+- = _
//     ╰───────────╮     nav spc │  │ sft sym     ╭───────────╯
//                 ╰─────────────╯  ╰─────────────╯
//
// L_NAV, the mouse, media, pagination, and arrow complete package
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯ mo2 mo1 nxt prv │          │     end hme vol ╰───────╮
// │ tab ply gui alt ctl mo3 │          │  ←   ↓   ↑   →  bsp YEL │ YEL = capsword
// ╰───╮                     ╰───╮  ╭───╯     pgd pgu vol ent ╭───╯
//     ╰───────────╮    [nav]    │  │ sft sym     ╭───────────╯
//                 ╰─────────────╯  ╰─────────────╯
//
// L_SYM, smooth rolls for Go, JavaScript, and Shell
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  <   >   -   |  │          │  ^   (   )   ;  ╰───────╮
// │ esc  !   *   /   =   &  │          │  #  ctl alt gui  :   `  │
// ╰───╮  ~   +   [   ]   %  ╰───╮  ╭───╯  \   {   }   @   $  ╭───╯ cmd+- = shrink term font
//     ╰───────────╮     nav spc │  │    [sym]    ╭───────────╯     cmd+= = grow term font
//                 ╰─────────────╯  ╰─────────────╯
//
// L_NUM, a calculator with a hint of danger
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  5   3   1   9  │          │  8   0   2   4  ╰───────╮
// │      7  gui alt ctl F11 │          │ F10 ctl alt gui  6      │
// ╰───╮  F7  F5  F3  F1  F9 ╰───╮  ╭───╯  F8 F12  F2  F4 F6  ╭───╯
//     ╰───────────╮    [nav]    │  │    [sym]    ╭───────────╯
//                 ╰─────────────╯  ╰─────────────╯
//
// Influence / Credits
// --------------------------------------------------------------------------------
// Alan Reiser's Hands Down Reference for for rolls
// see https://sites.google.com/alanreiser.com/handsdown/home/hands-down-reference
// Pascal Getreuer's symbol layer design principles for rolls
// forked from https://getreuer.info/posts/keyboards/symbol-layer/index.html
// Callum Oakley's homerow oneshot mods to avoid timers
// see https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum

#include QMK_KEYBOARD_H

enum layers {
  L_BASE,
  L_NAV,
  L_SYM,
  L_NUM,
};

// Shorthands
#define ____ KC_TRNS     // Transparent
#define XXXX KC_NO       // NOOP
#define KC_REDO KC_AGIN  // Pairs with UNDO
#define MO_NAV MO(L_NAV)
#define MO_SYM MO(L_SYM)
#define MO_NUM MO(L_NUM)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)
#define OS_RGUI OSM(MOD_RGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_C,    KC_H,    KC_P,    KC_V,                          KC_K,    KC_Y,    KC_O,    KC_J,    XXXX,    XXXX,
        KC_Q,    KC_R,    KC_S,    KC_N,    KC_T,    KC_G,                          KC_W,    KC_U,    KC_E,    KC_I,    KC_A,    KC_QUOT,
        XXXX,    KC_X,    KC_M,    KC_L,    KC_D,    KC_B,                          KC_Z,    KC_F,    KC_COMM, KC_DOT,  KC_MINS, XXXX,
                                            XXXX,    MO_NAV,  KC_SPC,      KC_LSFT, MO_SYM,  XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_NAV] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    MS_BTN2, MS_BTN1, KC_MNXT, KC_MPRV,                       XXXX,    KC_END,  KC_HOME, KC_VOLU, XXXX,    XXXX,
        KC_TAB,  KC_MPLY, OS_LGUI, OS_LALT, OS_LCTL, MS_BTN3,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, CW_TOGG,
        XXXX,    XXXX,    XXXX,    XXXX,    XXXX,    XXXX,                          XXXX,    KC_PGDN, KC_PGUP, KC_VOLD, KC_ENT,  XXXX,
                                            ____,    XXXX,    ____,        ____,    MO_NUM,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_SYM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_LT,   KC_GT,   KC_MINS, KC_PIPE,                       KC_CIRC, KC_LPRN, KC_RPRN, KC_SCLN, XXXX,    XXXX,
        KC_ESC,  KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,                       KC_HASH, OS_RCTL, OS_LALT, OS_RGUI, KC_COLN, KC_GRV,
        XXXX,    KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                       KC_BSLS, KC_LBRC, KC_RBRC, KC_AT,   KC_DLR,  XXXX,
                                            ____,    MO_NUM,  ____,        ____,    XXXX,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_NUM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_5,    KC_3,    KC_1,    KC_9,                          KC_8,    KC_0,    KC_2,    KC_4,    XXXX,    XXXX,
        XXXX,    KC_7,    OS_LGUI, OS_LALT, OS_LCTL, XXXX,                          KC_F10,  OS_RCTL, OS_LALT, OS_RGUI, KC_6,    XXXX,
        XXXX,    KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,                         KC_F8,   KC_F12,  KC_F2,   KC_F4,   KC_F6,   XXXX,
                                            ____,    XXXX,    ____,        ____,    XXXX,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
};

const key_override_t *key_overrides[] = {
	&ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DELETE),   // sft+bsp = del

  // L_BASE
	&ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUESTION),      // sft+, = ?
	&ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_EXCLAIM),       // sft+. = !
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
