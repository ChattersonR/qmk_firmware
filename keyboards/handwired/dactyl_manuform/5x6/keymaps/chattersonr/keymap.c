#include QMK_KEYBOARD_H

enum foldkb_layers {
  _QWERTY,
  _COLEMAKDH,
  _LOWER,
  _RAISE,
  _SYMBOL,
  _ADJUST,
  _APP
};

enum foldkb_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAKDH
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SYMBOL MO(_SYMBOL)
#define APP MO(_APP)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
        KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                         KC_LBRC,KC_RBRC,                                                       KC_MINS, KC_EQL,
                                         LOWER,KC_SPC,                           LT(RAISE,KC_ENT), LT(SYMBOL,KC_BSPC),
                                         KC_TAB,KC_HOME,                         KC_END,  KC_DEL,
                                         KC_BSPC, KC_GRV,                        KC_LGUI, KC_LALT
    ),
    [_COLEMAKDH] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_TAB , KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                         KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_BSLS,
        KC_LSFT, KC_A  , KC_R  , KC_S  , KC_T  , KC_G  ,                         KC_M  , KC_N  , KC_E  , KC_I  , KC_O  ,KC_QUOT,
        KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_D  , KC_V  ,                         KC_K  , KC_H  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                         KC_LBRC,KC_RBRC,                                                       KC_MINS, KC_EQL,
                                         LOWER,KC_SPC,                           LT(RAISE,KC_ENT), LT(SYMBOL,KC_BSPC),
                                         KC_TAB,KC_HOME,                         KC_END,  KC_DEL,
                                         KC_BSPC, KC_GRV,                        KC_LGUI, KC_LALT
    ),
    [_LOWER] = LAYOUT_5x6(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,      KC_F7,   KC_F8,   KC_F9,      KC_F10,  KC_F11,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               C(KC_LEFT), KC_PGDN, KC_PGUP, C(KC_RGHT), KC_PSCR, XXXXXXX,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,               KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT,    KC_INS,  XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               KC_HOME,    XXXXXXX, XXXXXXX, KC_END,     XXXXXXX, _______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______

    ),

    [_RAISE] = LAYOUT_5x6(
          KC_GRV,  KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
          _______, KC_GRV,    KC_7,    KC_8,    KC_9,    KC_MINS,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
          _______, KC_BSLS,   KC_4,    KC_5,    KC_6,    KC_EQL,              XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
          _______, KC_LBRC,   KC_1,    KC_2,    KC_3,    KC_RBRC,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                                  _______,  KC_0 ,            KC_EQL ,_______,
                                                  _______,  KC_0 ,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    ),

    [_SYMBOL] = LAYOUT_5x6(
          KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
          _______, KC_TILD,   KC_AMPR, KC_ASTR, KC_LPRN, KC_UNDS,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
          _______, KC_PIPE,   KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,             XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
          _______, KC_LCBR,   KC_EXLM, KC_AT,   KC_HASH, KC_RCBR,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                                  KC_LPRN,KC_RPRN,            KC_EQL ,_______,
                                                  KC_LPRN,KC_RPRN,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  QWERTY,COLEMAKDH,            QK_BOOT,COLEMAKDH
    )
};

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
