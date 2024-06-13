#include QMK_KEYBOARD_H

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

// Need to hold down RAISE and LOWER to access the each layer, tap 3 times to toggle
#define TAPPING_TOGGLE 3
#define RAISE TT(_RAISE)
#define LOWER TT(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | TAB  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  | \    |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | ESC  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ; :| ' "  |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * |  ` ~ |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  | / ?  | - _  |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     * | HOME | END  |L_ARR | R_ARR|                                                         |UP_ARR|DW_ARR|   [{ |  ]}  |
     * +------+------+-------------+-------------+                             +-------------+-------------+------+------+
     *                             |    SPACE    |                             |   BCKSPC    |
     *                             |-------------|                             |-------------|
     *                             |    SHIFT    |                             |    ENTER    |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           |PG_UP |PG_DWN| |RAISE |LOWER |
     *                                           |------+------| |------+------|
     *                                           |  ALT | DEL  | | WIN  | CTRL |
     *                                           +-------------+ +-------------+
     */
    [_BASE] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
        KC_HOME, KC_END, KC_LEFT,  KC_RIGHT,                                               KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,
                                            KC_SPC,  KC_LSFT,            KC_ENT,  KC_BSPC,
                                            KC_UP,   KC_PGDN,            RAISE,   LOWER,
                                            KC_LALT, KC_DEL,             KC_LGUI, KC_LCTL
    ),

    [_LOWER] = LAYOUT(
        _______, _______, _______, KC_UP,   _______, KC_LBRC,             KC_RBRC, _______, KC_NUM,  KC_INS,  KC_SCRL, KC_MUTE,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_LPRN,             KC_RPRN, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, KC_VOLD,
        _______, _______, _______, _______,                                                 KC_EQL,  _______, _______, _______,
                                            _______, KC_RSFT,             _______, _______,
                                            _______, _______,             _______, _______,
                                            KC_RCTL, _______,             _______, KC_RALT
    ),

    [_RAISE] = LAYOUT(
        KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,               KC_F7, KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
        KC_EQL,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,  KC_7,    KC_8,    KC_9,      KC_0, KC_MINS,
        _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______,  KC_EQL,
        _______, _______, _______, _______,                                                 _______, _______, _______, _______,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______,
                                            _______, _______,             _______, _______
    )
};
