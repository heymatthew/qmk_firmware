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
// ╭───────╯  C   H   P   V  │          │  K   Y   O   J  ╰───────╮
// │  Q   R   S   N   T   G  │          │  W   U   E   I   A   '" │
// ╰───╮  X   M   L   D   B  ╰───╮  ╭───╯  Z   F   ,?  .!  -_ ╭───╯ sft+, = ?
//     ╰───────────╮     spc nav │  │ sym esc     ╭───────────╯     sft+. = !
//                 ╰─────────────╯  ╰─────────────╯
//
// L_NAV, the mouse, media, pagination, and arrow complete package
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯ mo2 mo1 ply     │          │     end hme bsp ╰───────╮
// │     gui alt ctl sft mo3 │          │  ←   ↓   ↑   →  ent     │
// ╰───╮ prv vol vol nxt     ╰───╮  ╭───╯     pgd pgu tab     ╭───╯
//     ╰───────────╮        [nav]│  │ sym esc     ╭───────────╯
//                 ╰─────────────╯  ╰─────────────╯
//
// L_SYM, smooth rolls for Go, JavaScript, and Shell
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  <   >   -   `  │          │  ^   (   )   ;  ╰───────╮ gui+% = screenshot window
// │  :   !   *   /   =   &  │          │  |  sft ctl alt gui  $  │ gui+* = screenshot lasso
// ╰───╮  ~   +   [   ]   %  ╰───╮  ╭───╯  \   #   {   }   @  ╭───╯ gui+- = shrink term font
//     ╰───────────╮     spc nav │  │[sym]        ╭───────────╯     gui+= = grow term font
//                 ╰─────────────╯  ╰─────────────╯
//
// L_NUM, a calculator with a hint of danger
//         ╭─────────────────╮          ╭─────────────────╮
// ╭───────╯  5   3   1   9  │          │  8   0   2   4  ╰───────╮
// │  7  gui alt ctl sft F11 │          │ F10 sft ctl alt gui  6  │ gui+0 = reset term font
// ╰───╮  F7  F5  F3  F1  F9 ╰───╮  ╭───╯  F8 F12  F2  F4 F6  ╭───╯ sft+sft = Capsword
//     ╰───────────╮        [nav]│  │[sym]        ╭───────────╯
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
// Precondition's Home Row Mods GACS
// see https://precondition.github.io/home-row-mods#gacs

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
#define OSL_NAV MO(L_NAV)
#define OSL_SYM MO(L_SYM)
#define OSL_NUM MO(L_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    KC_Q,    KC_C,    KC_H,    KC_P,    KC_V,                          KC_K,    KC_Y,    KC_O,    KC_J,    KC_QUOT, XXXX,
        KC_Q,    KC_R,    KC_S,    KC_N,    KC_T,    KC_G,                          KC_W,    KC_U,    KC_E,    KC_I,    KC_A,    KC_QUOT,
        XXXX,    KC_X,    KC_M,    KC_L,    KC_D,    KC_B,                          KC_Z,    KC_F,    KC_COMM, KC_DOT,  KC_MINS, XXXX,
                                            XXXX,    KC_SPC,  OSL_NAV,     OSL_SYM, KC_ESC,  XXXX
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_NAV] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    MS_BTN2, MS_BTN1, KC_MPLY, XXXX,                          XXXX,    KC_END,  KC_HOME, KC_BSPC, XXXX,    XXXX,
        XXXX,    XXXX,  XXXX,  XXXX,  XXXX,  MS_BTN3,                        KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_ENT,  XXXX,   
        XXXX,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXX,                          XXXX,    KC_PGDN, KC_PGUP, KC_TAB,  XXXX,    XXXX,
                                            ____,    ____,    XXXX,        OSL_NUM, ____,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_SYM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_LT,   KC_GT,   KC_MINS, KC_GRV,                        KC_CIRC, KC_LPRN, KC_RPRN, KC_SCLN, KC_DLR,  XXXX,
        KC_COLN, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,                       KC_PIPE, XXXX,  XXXX,  XXXX,  XXXX,  KC_DLR,
        XXXX,    KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                       KC_BSLS, KC_HASH, KC_LCBR, KC_RCBR, KC_AT,   XXXX,
                                            ____,    ____,    OSL_NUM,     XXXX,    ____,    ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
  [L_NUM] = LAYOUT_split_3x6_3(
    // +--------+--------+--------+--------+--------+--------+                     +--------+--------+--------+--------+--------+--------+
        XXXX,    XXXX,    KC_5,    KC_3,    KC_1,    KC_9,                          KC_8,    KC_0,    KC_2,    KC_4,    XXXX,    XXXX,
        KC_7,    XXXX,  XXXX,  XXXX,  XXXX,  KC_F11,                        KC_F10,  XXXX,  XXXX,  XXXX,  XXXX,  KC_6,
        XXXX,    KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,                         KC_F8,   KC_F12,  KC_F2,   KC_F4,   KC_F6,   XXXX,
                                            ____,    ____,    XXXX,        XXXX,    ____,     ____
    //                                     +--------+--------+--------+   +--------+--------+--------+
  ),
};

const key_override_t *key_overrides[] = {
	&ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DELETE),   // sft+bsp = del

  // L_BASE
	&ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUESTION),      // sft+, = ?
	&ko_make_basic(MOD_MASK_SHIFT, KC_DOT,  KC_EXCLAIM),       // sft+. = !
};

enum custom_keycodes {
    OS_SFT = SAFE_RANGE,
    OS_CTL,
    OS_ALT,
    OS_GUI,
};
const uint16_t PROGMEM sft_combo[] = {KC_C, KC_P, COMBO_END}; // top left
const uint16_t PROGMEM ctl_combo[] = {KC_Y, KC_J, COMBO_END}; // top right
const uint16_t PROGMEM alt_combo[] = {KC_M, KC_D, COMBO_END}; // bottom left
const uint16_t PROGMEM gui_combo[] = {KC_F, KC_DOT, COMBO_END}; // bottom right
combo_t key_combos[] = {
    COMBO(sft_combo, OS_SFT),
    COMBO(ctl_combo, OS_CTL),
    COMBO(alt_combo, OS_ALT),
    COMBO(gui_combo, OS_GUI),
};

static uint16_t os_timer = 0;
static uint16_t os_counter = 0;
static uint16_t last_os_keycode = 0;

// process_custom_oneshot is like OSM() but compatable with COMBO().
// COMBO() has a bug preventing ONESHOT_TAP_TOGGLE from triggering.
void process_custom_oneshot(uint16_t keycode, uint8_t mod_to_apply) {
    // Toggle locked oneshot will unlock
    if (get_oneshot_locked_mods() & mod_to_apply) {
        clear_oneshot_locked_mods();
        unregister_mods(mod_to_apply);
        os_counter = 0;
        last_os_keycode = 0;
        os_timer = 0;
        return;
    }
    // Subsequent taps on same mod may trigger lock
    if(last_os_keycode == keycode && !timer_expired(os_timer, TAPPING_TERM)) {
        if (++os_counter >= ONESHOT_TAP_TOGGLE) {
            set_oneshot_locked_mods(mod_to_apply);
        }
        return;
    }
    os_counter = 0;
    last_os_keycode = keycode;
    os_timer = timer_read();
    set_oneshot_mods(mod_to_apply);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) { // on keydown
      switch (keycode) {
        case OS_SFT:
          process_custom_oneshot(keycode, MOD_LSFT);
          return false;
        case OS_CTL:
          process_custom_oneshot(keycode, MOD_LCTL);
          return false;
        case OS_ALT:
          process_custom_oneshot(keycode, MOD_LALT);
          return false;
        case OS_GUI:
          process_custom_oneshot(keycode, MOD_LGUI);
          return false;
      }
    }
    return true; // passthrough
}
