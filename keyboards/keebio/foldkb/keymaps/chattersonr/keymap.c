/* Copyright 2021 Danny Nguyen <danny@keeb.io>

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

enum foldkb_layers {
  _QWERTY,
  _COLEMAKDH,
  _LOWER,
  _RAISE,
  _ADJUST,
  _APP
};

enum foldkb_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAKDH,
  WACKYBSPC
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define APP MO(_APP)

# if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 1, HSV_YELLOW}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {12, 1, HSV_PURPLE}
);

// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    raise_layer
    ,lower_layer
    ,adjust_layer
);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   *  ,------.     ,------------------------------------------------.     ,-------------------------------------------------------.
   *  | ENC  |     | ESC  |   `  |   1  |   2  |   3  |   4  |   5  |     |   6  |   7  |   8  |   9  |   0  |   -  |   =  | Bksp |
   *  |------+     |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------+------|
   *  | Home |     |      | Tab  |   Q  |   W  |   E  |   R  |   T  |     |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |   \  |
   *  |------+     |------+------+------+------+------+------+------|     |------+------+------+------+------+------+------+------|
   *  | End  |     |      | Caps |   A  |   S  |   D  |   F  |   G  |     |   H  |   J  |   K  |   L  |   ;  |   '  | Enter       |
   *  |------+     |------+------+------+------+------+------+------|     |------+------+------+------+------+------|-------------|
   *  | PgUp |     |      | Shift|   Z  |   X  |   C  |   V  |   B  |     |   N  |   M  |   ,  |   .  |   /  | Shift|  FN         |
   *  |------+     |------+------+------+------+------+------+------|     |------+------+------+------+------+------|-------------|
   *  | PgDn |     |      | Ctrl |  GUI |  ALT | Lower|    Space    |     |Enter |Raise |  ALT |  GUI | Menu | Ctrl |
   *  `------'     `------------------------------------------------'     `-----------------------------------------'
   */
   //TODO - Give raise/lower a keycode on tap?
  [_QWERTY] = LAYOUT(
    KC_MUTE, KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9, KC_MINS,    KC_0, KC_EQL,  KC_BSPC,
    KC_HOME,          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
     KC_END,   LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_PGUP,          KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_UP), APP,
    KC_PGDN,          KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,      LT(RAISE,KC_SPC),  KC_SPC,   KC_RALT, RGUI_T(KC_LEFT), MT(KC_MENU,KC_DOWN), RCTL_T(KC_RIGHT)
  ),
  [_COLEMAKDH] = LAYOUT(
    KC_MUTE, KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_HOME,          KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_END,    LCTL_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,          KC_ENT,
    KC_PGUP,          KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_UP), APP,
    KC_PGDN,          KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,      LT(RAISE,KC_ENT), LT(_COLEMAKDH,KC_NO), KC_RALT, RGUI_T(KC_LEFT), MT(KC_MENU,KC_DOWN), RCTL_T(KC_RIGHT)
  ),
  [_LOWER] = LAYOUT( //Nav Layer
    KC_MUTE, KC_ESC, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,      KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_HOME,         _______, _______, _______, _______, _______, _______,     C(KC_LEFT), KC_PGDN, KC_PGUP, C(KC_RGHT), KC_PSCR, _______, KC_PAUS, _______,
    KC_END,          _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,     KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT,    KC_INS,  _______,       _______,
    KC_PGUP,         _______, _______, _______, _______, _______, _______,     KC_HOME,    _______, _______, KC_END,     _______, _______, _______,
    KC_PGDN,         _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
  ),
  [_RAISE] = LAYOUT( //TODO. Symbol layer?
    XXXXXXX,  KC_ESC, KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    KC_HOME,         _______, KC_GRV,    KC_7,    KC_8,    KC_9,    KC_MINS,     _______, _______, _______, _______, _______, _______, _______, _______,
    KC_END,          _______, KC_BSLS,   KC_4,    KC_5,    KC_6,    KC_EQL,      _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,       _______,
    KC_PGUP,         _______, KC_LBRC,   KC_1,    KC_2,    KC_3,    KC_RBRC,     _______, _______, _______, _______, _______, _______, _______,
    KC_PGDN,         _______, _______, _______, _______,   KC_0,    KC_0,        _______, _______, _______, _______, _______, _______
  ),
  //TODO put RGB brightness on encoder
  [_ADJUST] = LAYOUT(
    RGB_TOG, QK_BOOT, _______, RGB_HUD, RGB_HUI, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    RGB_TOG,          _______, RGB_SAD, RGB_SAI, _______, _______, _______,     _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______,
    RGB_MOD,          _______, RGB_VAD, RGB_VAI, _______, _______, _______,     _______, KC_4,    KC_5,    KC_6,    _______, _______,          _______,
    QWERTY,           _______, _______, _______, _______, _______, _______,     _______, KC_1,    KC_2,    KC_3,    _______, _______, _______,
    COLEMAKDH,        _______, _______, _______, _______, _______, _______,     _______, KC_0,    _______, _______, _______, _______
  ),
  //TODO what do? app shortcuts?
  [_APP] = LAYOUT(
    RGB_TOG, QK_BOOT, _______, RGB_HUD, RGB_HUI, _______, A(KC_F4), _______,     _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    RGB_MODE_FORWARD,          _______, RGB_SAD, RGB_SAI, _______,  _______,     _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______,
    RGB_MODE_BREATHE,          KC_CAPS, RGB_VAD, RGB_VAI, _______,  _______,     _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,          _______,
    QWERTY,           _______, _______, _______, _______,  _______, _______,     _______, KC_1,    KC_2,    KC_3,    _______, _______, _______,
    COLEMAKDH,        _______, _______, _______, _______,  _______, _______,     _______, KC_0,    _______, _______, _______, _______
  )

};

void keyboard_post_init_user(void) {
    // Enable the LED layers
    # if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
    rgblight_layers = my_rgb_layers;
    #endif

}

layer_state_t layer_state_set_user(layer_state_t state) {
  layer_state_t upstate = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

  # if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
  rgblight_set_layer_state(0, layer_state_cmp(upstate, _RAISE));
  rgblight_set_layer_state(1, layer_state_cmp(upstate, _LOWER));
  rgblight_set_layer_state(2, layer_state_cmp(upstate, _ADJUST));
  #endif

  return upstate;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAKDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAKDH);
      }
      return false;
    case LT(_COLEMAKDH,KC_NO):
      if (record->tap.count && record->event.pressed) {
        tap_code16(C(KC_BSPC)); // Tap process as Ctrl-Backspace
      } else if (record->event.pressed) {
        register_code(KC_BSPC); // Hold process as backspase
      } else {
        unregister_code(KC_BSPC);
      }
      return false;
    default:
      return true;
  }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { //First encoder

      if(IS_LAYER_ON(_RAISE)) {
        //Undo/Redo on knob.
        if (clockwise) {
            tap_code16(C(KC_Y));
        } else {
            tap_code16(C(KC_Z ));
        }
      } else if(IS_LAYER_ON(_APP)) {
        if (clockwise) {
            rgblight_increase_val();
        } else {
            rgblight_decrease_val(); 
        }
      } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
      }
    }
    return false;
}

