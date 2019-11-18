#include QMK_KEYBOARD_H
// Layers
enum layers {
  _BASE,
  _FN,
  _RGB,
  _NUMPD,
  _MAC,
};

// Reusable keycodes
#define LT_DEL LT(_RGB, KC_DEL)
#define MT_SLSH RSFT_T(KC_SLSH)
#define MT_CTCL CTL_T(KC_CAPS)
#define TO_BASE TO(_BASE)
#define TO_NUMPD TO(_NUMPD)
#define TO_MAC TO(_MAC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_BASE] = LAYOUT( /* Base */
			  KC_GESC,            KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,    KC_9,       KC_0,         KC_MINS,  KC_EQL,  KC_BSPC,\
		    KC_TAB,             KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,    KC_O,       KC_P,         KC_LBRC,  KC_RBRC, KC_BSLASH,\
			  MT_CTCL,            KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,    KC_L,       KC_SCLN,      KC_QUOT,           KC_ENT, \
		    KC_LSFT,            KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,     MT_SLSH,      KC_UP,             LT_DEL,\
		    KC_LCTL,            KC_LGUI,  LM(_BASE, MOD_LALT),        KC_SPC,          KC_RALT, MO(_BASE),  KC_LEFT,      KC_DOWN,           KC_RIGHT
      ),
		[_FN] = LAYOUT( /* FN */
		    TO_NUMPD, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL ,\
		    KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_CALC,  KC_TRNS,  KC_INS,   KC_TRNS,  KC_PSCR,  KC_SLCK,    KC_PAUS,  RESET  ,\
		    KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGUP,              EEP_RST,\
		    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MAGIC_TOGGLE_NKRO,  KC_TRNS,  KC_TRNS,  KC_END,   KC_PGDOWN,  KC_VOLU,  KC_MUTE,\
			  KC_TRNS,  KC_TRNS,  KC_TRNS,                      TO_MAC,                       KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_VOLD,              KC_MNXT
      ),
		[_RGB] = LAYOUT( /* LIGHT */
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL ,\
        KC_TRNS,  RGB_TOG,  KC_TRNS,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  RGB_MOD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RESET  ,\
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_SPI,  RGB_SPD,  KC_TRNS,  KC_TRNS,            EEP_RST,\
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,\
        KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS
      ),
		[_NUMPD] = LAYOUT( /* NUMPAD */
        KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,  KC_PPLS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PSLS,  KC_PAST,  KC_PMNS,  KC_PPLS,  KC_TRNS,\
        KC_TRNS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,  KC_TRNS,  TO_BASE,\
        KC_TRNS,  KC_P4,    KC_P5,    KC_P6,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P4,    KC_P5,    KC_P6,    KC_TRNS,            KC_PENT,\
        KC_TRNS,  KC_P1,    KC_P2,    KC_P3,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_P1,    KC_P2,    KC_P3,    KC_TRNS,            KC_TRNS,\
        KC_TRNS,  KC_P0,    LALT_T(KC_PDOT),                      KC_PENT,                        KC_P0,    KC_PDOT,  KC_TRNS,  KC_TRNS,  KC_TRNS
      ),
		[_MAC] = LAYOUT( /* SWITCH LALT AND LGUI */
			  KC_GESC,        KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,            KC_MINS,  KC_EQL,  KC_BSPC,  \
		    KC_TAB,         KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,            KC_LBRC,  KC_RBRC, KC_BSLASH,\
			  MT_CTCL,        KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,         KC_QUOT,           KC_ENT,   \
		    KC_LSFT,        KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   MT_SLSH,         KC_UP,             LT_DEL,   \
			  KC_LCTL,        KC_LALT,  KC_LGUI,                KC_SPC,                KC_RALT, TO_BASE,  KC_LEFT,         KC_DOWN,           KC_RIGHT
      ),
		};

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
