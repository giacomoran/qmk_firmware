/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "features/achordion.h"
#include "features/select_word.h"

// #: Layers

enum layers {
    _QWERTY = 0,
    _NAV,
    _NUM,
    _SYM,
    _FUN,
};

#define QWERTY   DF(_QWERTY)
#define NAV      MO(_NAV)
#define NUM      MO(_NUM)
#define SYM      MO(_SYM)
#define FUN      MO(_FUN)

// #: Custom keycodes

enum keycodes_custom {
    SELWORD = SAFE_RANGE,
};

// #: Aliases

// Left-hand home row mods
#define CTL_A    LCTL_T(KC_A)
#define ALT_S    LALT_T(KC_S)
#define GUI_D    LGUI_T(KC_D)
#define SFT_F    LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J    RSFT_T(KC_J)
#define GUI_K    RGUI_T(KC_K)
#define ALT_L    LALT_T(KC_L)
#define CTL_SC   RCTL_T(KC_SCLN)

// Other mod/layer taps
#define NAV_SPC  LT(NAV, KC_SPC)
#define SYM_ENT  LT(SYM, KC_ENT)
#define NUM_BP   LT(NUM, KC_BSPC)
#define FUN_DEL  LT(FUN, KC_DEL)
#define CTL_GRV  LCTL_T(KC_GRV)

// One shot keys
#define OSM_SFT  OSM(MOD_LSFT)

// Function keys on hold
// NOTE: See below. We use dummy layer tap keys, see https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
#define GUI_SPC  LT(0, KC_1)
#define OPT_SPC  LT(0, KC_2)

// Key + modifier
#define G_LEFT   LGUI(KC_LEFT)
#define G_RGHT   LGUI(KC_RGHT)

// #: Keymap

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
        KC_TAB,   CTL_A,   ALT_S,   GUI_D,   SFT_F,    KC_G,                                        KC_H,   SFT_J,   GUI_K,   ALT_L,  CTL_SC, KC_QUOT,
        KC_ESC,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_EQL,
                                  KC_MCTL, OPT_SPC, GUI_SPC, NAV_SPC, OSM_SFT, SYM_ENT,  NUM_BP, FUN_DEL, _______, _______
    ),

    [_NAV] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                     KC_PGUP,  G_LEFT, KC_UP,    G_RGHT, _______, _______,
       _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, SELWORD, _______,
       _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT(
       _______, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                                     _______, _______, _______, _______, _______, _______,
       _______, KC_LPRN,    KC_4,    KC_5,    KC_6, KC_RPRN,                                     _______, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
       _______, _______,    KC_1,    KC_2,    KC_3, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                  _______, _______,    KC_0, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
       _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                     _______, _______, _______, _______, _______, _______,
       _______,   KC_LT,  KC_DLR, KC_PERC, KC_CIRC,   KC_GT,                                     _______, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
       _______, _______, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FUN] = LAYOUT(
       _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9, _______,                                     _______, _______, _______, _______, _______, _______,
       _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6, _______,                                     _______, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
       _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

// #: Tapping term

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_A:
            return TAPPING_TERM + 20;
        case ALT_S:
            return TAPPING_TERM + 20;
        default:
            return TAPPING_TERM;
    }
}

// #: `process_record_user`

// Dual role key GUI_SPC:
// - on tap  [⌘ ␣]
// - on hold [⌘]
// REFS:
// - https://getreuer.info/posts/keyboards/triggers/index.html#tap-vs.-long-press
// - https://docs.qmk.fm/#/mod_tap?id=changing-hold-function
static bool process_tap_or_hold_gui_spc(keyrecord_t* record) {
    // On tap press
    if (record->tap.count > 0 && record->event.pressed) {
        tap_code16(LGUI(KC_SPC));
    }

    // On hold press
    if (record->tap.count == 0 && record->event.pressed) {
        register_code(KC_LGUI);
    }
    // On hold release
    if (record->tap.count == 0 && !record->event.pressed) {
        unregister_code(KC_LGUI);
    }

    // Skip default handling
    return false;
}

// Dual role key OPT_SPC:
// - on tap  [⌥ ␣]
// - on hold [⌥]
// See GUI_SPC above for refs.
static bool process_tap_or_hold_opt_spc(keyrecord_t* record) {
    // On tap press
    if (record->tap.count > 0 && record->event.pressed) {
        tap_code16(LALT(KC_SPC));
    }

    // On hold press
    if (record->tap.count == 0 && record->event.pressed) {
        register_code(KC_LALT);
    }
    // On hold release
    if (record->tap.count == 0 && !record->event.pressed) {
        unregister_code(KC_LALT);
    }

    // Skip default handling
    return false;
}

// Intercept key events
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Enable Getreuer features
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_select_word(keycode, record, SELWORD)) { return false; }

    switch (keycode) {
        case GUI_SPC:
            return process_tap_or_hold_gui_spc(record);
        case OPT_SPC:
            return process_tap_or_hold_opt_spc(record);
    }
    return true;
}

// #: Achordion config
// Refs:
// - https://getreuer.info/posts/keyboards/achordion/index.html
// - https://github.com/getreuer/qmk-keymap/blob/main/features/achordion.c

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Also allow same-hand holds when the other key is in thumb cluster.
  // See keyboards/splitkb/kyria/rev2/rev2.h
  if (other_record->event.key.row % (MATRIX_ROWS / 2) == 3) { return true; }

  // Default: opposite hand rule
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        // NOTE: `GUI_SPC` is meant for one handed shortcuts.
        case GUI_SPC:
            return 0;
    }
    return 800;
}

// Prevent waiting out the accordion timeouts form mouse clicks with modifiers.
bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LCTL:
        case MOD_RCTL:
            return true;
        default:
            return false;
    }
}

// #: `matrix_scan_user`

void matrix_scan_user(void) {
    achordion_task();
    select_word_task();
}

// #: OLED display

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev2.1\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("Num\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUN:
                oled_write_P(PSTR("Function\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif
