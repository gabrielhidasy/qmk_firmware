/* Copyright 2018 Milton Griffin
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

void tap(uint16_t keycode){
  register_code(keycode);
  unregister_code(keycode);
};

#define _QW 0
#define _QW2 1
enum custom_keycodes {
  BLAZEB = SAFE_RANGE,
  BLAZET,
  PRODACCESS,
  XKILL,
  I3REF,
  I3NEXT,
  I3PREV,
  CHROME,
  EMACS,
  LPAREN,
  RPAREN,
  SNUML_1,
  SNUML_2,
  G4D
};

// Tap Dance Declarations
enum {
  TARGETS = 0,
  OPEN_P,
  CLOSE_P,
  MEGAPARENS,
  FIREFOX
};

//Tap Dance Definitions
void dance_open_paren(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 1:
      send_string("(");
      return;
    case 2:
      send_string("[");
      return;
    case 3:
      send_string("{");
      return;
  }
}

void dance_close_paren(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 1:
      send_string(")");
      return;
    case 2:
      send_string("]");
      return;
    case 3:
      send_string("}");
      return;
  }
}

void dance_mega_paren(qk_tap_dance_state_t *state, void *user_data) {
  uint16_t count = (state->count-1)%6;
  switch(count) {
    case 0:
      if (state->count > 2) tap(KC_BSPC);
      send_string("(");
      return;
    case 1:
      tap(KC_BSPC);
      send_string(")");
      return;
    case 2:
      tap(KC_BSPC);
      send_string("{");
      return;
    case 3:
      tap(KC_BSPC);
      send_string("}");
      return;
    case 4:
      tap(KC_BSPC);
      send_string("[");
      return;
    case 5:
      tap(KC_BSPC);
      send_string("]");
      return;
  }
}


void dance_targets(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 1:
      send_string("superroot/servers:sr_www");
      return;
    case 2:
      send_string("quality/falcon:all");
      return;
    case 3:
      send_string("experimental/users/gabrielhidasy/");
      return;
  }
}

void dance_firefox(qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 1:
      tap(KC_LGUI);
      _delay_ms(300);
      SEND_STRING("firefox");
      tap(KC_ENT);
      return;
    case 2:
      tap(KC_LGUI);
      _delay_ms(300);
      send_string("firefox -P Corp");
      tap(KC_ENT);
      return;
  }
}


//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
  [TARGETS]  = ACTION_TAP_DANCE_FN(dance_targets),
  [OPEN_P]  = ACTION_TAP_DANCE_FN(dance_open_paren),
  [CLOSE_P]  = ACTION_TAP_DANCE_FN(dance_close_paren),
  [MEGAPARENS]  = ACTION_TAP_DANCE_FN_ADVANCED_TIME(dance_mega_paren, NULL, NULL, 400),
  [FIREFOX] = ACTION_TAP_DANCE_FN(dance_firefox),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BLAZEB:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING("blaze build ");
      } else {
        // when keycode is released
      }
      return false;
    case BLAZET:
      if (record->event.pressed) {
        SEND_STRING("blaze test ");
      } 
      return false;
    case PRODACCESS:
      if (record->event.pressed) {
        SEND_STRING("prodaccess");
        tap(KC_ENT);
      }
      return false;
    case XKILL:
      if (record->event.pressed) {
        tap(KC_LGUI);
        _delay_ms(300);
        SEND_STRING("xkill");
        tap(KC_ENT);
      } 
      return false;
    case I3REF:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSHIFT);
        tap(KC_R);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_LGUI);
      } 
      return false;
    case I3NEXT:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap(KC_N);
        unregister_code(KC_LGUI);
      }
      return false;
    case I3PREV:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap(KC_P);
        unregister_code(KC_LGUI);
      }
      return false;
    case CHROME:
      if (record->event.pressed) {
        tap(KC_LGUI);
        _delay_ms(300);
        SEND_STRING("google-chrome");
        tap(KC_ENT);
      } 
      return false;
    case EMACS:
      if (record->event.pressed) {
        tap(KC_LGUI);
        _delay_ms(300);
        SEND_STRING("emacs");
        tap(KC_ENT);
      } 
      return false;
    case LPAREN:
      if (record->event.pressed) {
        register_code(KC_LSHIFT);
        tap(KC_9);
        unregister_code(KC_LSHIFT);
      } 
      return false;
    case RPAREN:
      if (record->event.pressed) {
        register_code(KC_LSHIFT);
        tap(KC_0);
        unregister_code(KC_LSHIFT);
      } 
      return false;
    case SNUML_1:
      if (record->event.pressed) {
        tap(KC_NUMLOCK);
        layer_on(_QW2);
      } 
      return false;
    case SNUML_2:
      if (record->event.pressed) {
        tap(KC_NUMLOCK);
        layer_on(_QW);
      } 
      return false;


    case G4D:
      if (record->event.pressed) {
        SEND_STRING("g4d ");
      } 
      return false;
  }
  return true;
};

// Keyboard Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* QWERTY
   * .---------------------------------------------
   * | ESC    | 1      | 2      | 3      | 4      |
   * |--------+--------+--------+--------+--------+
   * | TAB    | Q      | W      | E      | R      |
   * |--------+--------+--------+--------+--------+
   * | CAP LK | A      | S      | D      | F      |
   * |--------+--------+--------+--------+--------+
   * | LSHIFT | Z      | X      | C      | V      |
   * |--------+--------+--------+--------+--------+
   * | LCTRL  | LGUI   | LALT   | FN     | SPACE  |
   * '---------------------------------------------
   * ... ... ...
   */

  [_QW] = LAYOUT_ortho_5x15( /* QWERTY */ \
      RESET,     KC_Y,    KC_L,    KC_L, KC_DOT,   KC_PGUP, KC_PGDN,  I3NEXT,  KC_PGUP,     KC_MS_BTN1, KC_MS_RIGHT, KC_PPLS, KC_PMNS, KC_BSPC,  KC_PENT, \
      KC_TAB,    KC_Q,    KC_W,    KC_E, KC_COMMA, KC_H,    KC_HOME,  I3PREV,  KC_PGDN,     KC_MS_UP,   KC_MS_DOWN,  KC_P9,   KC_P6,   KC_P3,    KC_PAST, \
      KC_LCTRL,  KC_A,    KC_S,    KC_D, KC_I,     G4D,     TO(_QW2), KC_LGUI, KC_MS_BTN3,  KC_MS_BTN2, KC_MS_LEFT,  KC_P8,   KC_P5,   KC_P2,    KC_PSLS, \
      KC_LSHIFT, KC_Z,    KC_L,    KC_7, KC_U,     KC_V,    TD(FIREFOX),  CHROME,  EMACS,       PRODACCESS, KC_NUMLOCK,  KC_P7,   KC_P4,   KC_P1,    KC_P0, \
      KC_SPC,    KC_RALT, KC_RALT, KC_9, KC_O,     KC_N,    I3REF,    XKILL,   TD(TARGETS), BLAZEB,     BLAZET,      KC_PDOT, KC_PEQL, KC_COMMA, TD(MEGAPARENS) \
),
 [_QW2] = LAYOUT_ortho_5x15( /* QWERTY */ \
      RESET,     KC_Y,    KC_L,    KC_L, KC_DOT,   KC_PGUP, KC_PGDN, I3NEXT,  KC_PGUP,     KC_PENT, KC_RIGHT, KC_PPLS, KC_PMNS, KC_BSPC,  KC_PENT, \
      KC_TAB,    KC_Q,    KC_W,    KC_E, KC_COMMA, KC_H,    KC_HOME, I3PREV,  KC_PGDN,     KC_UP,   KC_DOWN,  KC_P9,   KC_P6,   KC_P3,    KC_PAST, \
      KC_LCTRL,  KC_A,    KC_S,    KC_D, KC_I,     G4D,     TO(_QW), KC_LGUI, KC_3,        KC_BSPC, KC_LEFT,  KC_P8,   KC_P5,   KC_P2,    KC_PSLS, \
      KC_LSHIFT, KC_Z,    KC_L,    KC_7, KC_U,     KC_V,    FIREFOX, CHROME,  EMACS,       PRODACCESS, KC_NUMLOCK,  KC_P7,   KC_P4,   KC_P1,    KC_P0, \
      KC_SPC,    KC_RALT, KC_RALT, KC_9, KC_O,     KC_N,    I3REF,   XKILL,   TD(TARGETS), BLAZEB,     BLAZET,      KC_PDOT, KC_PEQL, KC_COMMA, TD(MEGAPARENS) \
),
 
  
};

// The %5 (0,6) key is kind of broken, some wires required.
