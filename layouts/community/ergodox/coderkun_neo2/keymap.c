#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "led.h"
#include "keymap_german.h"
#include "keymap_extras/keymap_neo2.h"

// Layer names
#define BASE 0      // default layer
#define FMU  1      // FMU layer
#define PMN  2      // poor man’s Neo
#define NHL  3      // Neo’s software layer 4 rebuilt in Hardware


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer BASE: default
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  TAB  │  1  │  2  │  3  │  4  │  5  │  `  │     │  ´  │  6  │  7  │  8  │  9  │  0  │ BKSPC │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │   Y   │  X  │  V  │  L  │  C  │  W  │  -  │     │  -  │  K  │  H  │  G  │  F  │  Q  │  ß    │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │ Mod3  │  U  │  I  │  A  │  E  │  O  ├─────┤     ├─────┤  S  │  N  │  R  │  T  │  D  │ Mod3  │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤ TL2 │     │ TL2 ├─────╄─────╃─────┼─────┼─────┼───────┤
 * │ LSHFT │  Ü  │  Ö  │  Ä  │  P  │  Z  │     │     │     │  B  │  M  │  ,  │  .  │  J  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ CTL │ ALT │ MO1 │ Win │ Mod4│                             │ Mod4│ Win │ MO1 │ ALT │ CTL │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │  ←  │  ↑  │ │  ↓  │  →  │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ ESC │ │ ESC │     │     │
 *                             │ SPC │ RTN ├─────┤ ├─────┤ RTN │ SPC │
 *                             │     │     │  SH │ │ SH  │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_TAB,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   NEO_GRV,
        NEO_Y,      NEO_X,  NEO_V,  NEO_L,  NEO_C,  NEO_W,  KC_MINS,
        NEO_L1_L,   NEO_U,  NEO_I,  NEO_A,  NEO_E,  NEO_O,
        KC_LSFT,    NEO_UE, NEO_OE, NEO_AE, NEO_P,  NEO_Z,  TG(PMN),
        KC_LCTL,    KC_LALT,MO(FMU),KC_LGUI,NEO_L2_L,
                                                    KC_LEFT,    KC_UP,
                                                                KC_ESC,
                                            KC_SPC, KC_ENT,     SH_MON,
        // right hand
        NEO_ACUT,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
        KC_MINS,    NEO_K,  NEO_H,  NEO_G,  NEO_F,  NEO_Q,  NEO_SS,
                    NEO_S,  NEO_N,  NEO_R,  NEO_T,  NEO_D,  NEO_L1_R,
        TG(PMN),    NEO_B,  NEO_M,  KC_COMM,KC_DOT, NEO_J,  KC_RSFT,
                            NEO_L2_R,KC_RGUI,MO(FMU),KC_LALT,KC_RCTL,
        KC_DOWN,    KC_RGHT,
        KC_ESC,
        SH_MON, KC_ENT,KC_SPC
    ),

/* Layer FMU: F-keys, Mouse and Unicode (FMU)
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │     │     │     │     │ F10 │ F11 │ F12 │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │  ←  │  ↑  │  ↓  │  →  │  ↔  │     │     │     │  `  │ F7  │ F8  │ F9  │     │       │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │       │  ∶  │  •  │  ✗  │  ✓  │  ≙  ├─────┤     ├─────┤  ´  │ F4  │ F5  │ F6  │     │       │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤(TL2)│     │(TL2)├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │  ⇐  │  ⇑  │  ⇓  │  ⇒  │  ⇔  │     │     │     │  -  │ F1  │ F2  │ F3  │     │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │(MO1)│     │(MO4)│                             │(MO4)│     │(MO1)│     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │ Ms← │ Ms↑ │ │ Ms↓ │ Ms→ │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ MLC │ │ MRC │     │     │
 *                             │     │     ├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[FMU] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,    UC(0x2190),UC(0x2191),UC(0x2193),UC(0x2192),UC(0x2194),KC_TRNS,
        KC_TRNS,    UC(0x2236),UC(0x2022),UC(0x2717),UC(0x2713),UC(0x2259),
        KC_TRNS,    UC(0x21D0),UC(0x21D1),UC(0x21D3),UC(0x21D2),UC(0x21D4),KC_TRNS,
        KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
                                                     KC_MS_L,   KC_MS_U,
                                                                KC_BTN1,
                                            KC_TRNS, KC_TRNS,   KC_TRNS,
        // right hand
        KC_TRNS,    KC_TRNS,   KC_F10,    KC_F11,    KC_F12,    KC_TRNS,   KC_TRNS,
        KC_TRNS,    NEO_GRV,   KC_F7,     KC_F8,     KC_F9,     KC_TRNS,   KC_TRNS,
                    NEO_ACUT,  KC_F4,     KC_F5,     KC_F6,     KC_TRNS,   KC_TRNS,
        KC_TRNS,    KC_MINS,   KC_F1,     KC_F2,     KC_F3,     KC_TRNS,   KC_TRNS,
                               KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_MS_D,    KC_MS_R,
        KC_BTN2,
        KC_TRNS,    KC_TRNS,   KC_TRNS
    ),

/* Layer PMN: poor man’s Neo
 * based on kaimi’s layout
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │  TAB  │  1  │  2  │  3  │  4  │  5  │  `  │     │  ´  │  6  │  7  │  8  │  9  │  0  │ BKSPC │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │   Y   │  X  │  V  │  L  │  C  │  W  │ HOM │     │ END │  K  │  H  │  G  │  F  │  Q  │  ß    │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤  E  │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │ Mod3  │  U  │  I  │  A  │  E  │  O  ├─────┤     ├─────┤  S  │  N  │  R  │  T  │  D  │ Mod3  │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤(TL2)│     │(TL2)├─────╄─────╃─────┼─────┼─────┼───────┤
 * │ LSHFT │  Ü  │  Ö  │  Ä  │  P  │  Z  │     │     │     │  B  │  M  │  ,  │  .  │  J  │ Shift │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │ CTL │ ALT │ MO1 │ Win │ MO4 │                             │ M04 │ Win │ MO1 │ ALT │ CTL │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │  ←  │  ↑  │ │  ↓  │  →  │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │ ESC │ │ ESC │     │     │
 *                             │ SPC │ RTN ├─────┤ ├─────┤ RTN │ SPC │
 *                             │     │     │  SH │ │ SH  │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[PMN] = LAYOUT_ergodox(
        KC_TAB,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_EQL,
        DE_Y,       DE_X,   DE_V,   DE_L,   DE_C,   DE_W,   KC_HOME,
        KC_NO,      DE_U,   DE_I,   DE_A,   DE_E,   DE_O,
        KC_LSFT,    DE_UE,  DE_OE,  DE_AE,  DE_P,   DE_Z,   KC_TRNS,
        KC_LCTL,    KC_LALT,MO(FMU),KC_LGUI,MO(NHL),
                                                    KC_LEFT,    KC_UP,
                                                                KC_ESC,
                                            KC_SPC, KC_ENT,     SH_MON,
        // right hand
        DE_ACUT,    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_BSPC,
        KC_END,     DE_K,   DE_H,   DE_G,   DE_F,   DE_Q,   DE_SS,
                    DE_S,   DE_N,   DE_R,   DE_T,   DE_D,   KC_NO,
        KC_TRNS,    DE_B,   DE_M,   KC_COMM,KC_DOT, DE_J,   KC_RSFT,
                            MO(NHL),KC_RGUI,MO(FMU),KC_LALT,KC_RCTL,
        KC_DOWN,    KC_RGHT,
        KC_ESC,
        SH_MON, KC_ENT,KC_SPC
    ),

/* Layer NHL: Neo’s software layer 4 rebuilt in Hardware
 * based on kaimi’s layout
 * ┌───────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────┐
 * │       │     │     │     │     │     │     │     │     │     │     │     │     │     │       │
 * ├───────┼─────┼─────┼─────┼─────┼─────┼─────┤     ├─────┼─────┼─────┼─────┼─────┼─────┼───────┤
 * │       │ PgUp│ BSpc│  ↑  │ Del │ PgDn│     │     │     │     │  7  │  8  │  9  │  +  │   −   │
 * ├───────┼─────┼─────┼─────╆─────╅─────┤     │     │     ├─────╆─────╅─────┼─────┼─────┼───────┤
 * │       │ Home│  ←  │  ↓  │  →  │ End ├─────┤     ├─────┤     │  4  │  5  │  6  │  ,  │   .   │
 * ├───────┼─────┼─────┼─────╄─────╃─────┤(TL2)│     │(TL2)├─────╄─────╃─────┼─────┼─────┼───────┤
 * │       │ Esc │ Tab │ Ins │ Ret │ Undo│     │     │     │     │  1  │  2  │  3  │     │       │
 * └─┬─────┼─────┼─────┼─────┼─────┼─────┴─────┘     └─────┴─────┼─────┼─────┼─────┼─────┼─────┬─┘
 *   │     │     │(MO1)│     │(MO4)│                             │(MO4)│     │(MO1)│     │     │
 *   └─────┴─────┴─────┴─────┴─────┘ ┌─────┬─────┐ ┌─────┬─────┐ └─────┴─────┴─────┴─────┴─────┘
 *                                   │     │     │ │     │     │
 *                             ┌─────┼─────┼─────┤ ├─────┼─────┼─────┐
 *                             │     │     │     │ │     │     │     │
 *                             │     │     ├─────┤ ├─────┤     │     │
 *                             │     │     │     │ │     │     │     │
 *                             └─────┴─────┴─────┘ └─────┴─────┴─────┘
 */
[NHL] = LAYOUT_ergodox(
        // left hand
        KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,      KC_PGUP,KC_BSPC,KC_UP,  KC_DEL, KC_PGDN,KC_NO,
        KC_NO,      KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END,
        KC_NO,      KC_ESC, KC_TAB, KC_INS, KC_ENT, KC_UNDO,KC_TRNS,
        KC_NO,      KC_NO,  KC_TRNS,KC_NO,  KC_TRNS,
                                                    KC_NO,      KC_NO,
                                                                KC_NO,
                                            KC_NO,  KC_NO,      KC_NO,
        // right hand
        KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_NO,      KC_NO,  KC_7,   KC_8,   KC_9,   DE_PLUS,DE_MINS,
                    KC_NO,  KC_4,   KC_5,   KC_6,   KC_COMM,KC_DOT,
        KC_TRNS,    KC_NO,  KC_1,   KC_2,   KC_3,   KC_NO,  KC_NO,
                            KC_TRNS,KC_NO,  KC_TRNS,KC_NO,  KC_NO,
        KC_NO,      KC_NO,
        KC_NO,
        KC_NO,      KC_NO,  KC_NO
    )
};

const uint16_t PROGMEM fn_actions[] = {
    [BASE] = ACTION_FUNCTION(BASE),
    [FMU]  = ACTION_LAYER_TAP_TOGGLE(FMU),
    [PMN]  = ACTION_FUNCTION(PMN),
    [NHL]  = ACTION_LAYER_TAP_TOGGLE(NHL)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case FMU:
            ergodox_right_led_2_on();
        break;
        case PMN:
            ergodox_right_led_3_on();
        break;
    }
};

// Enable LED based on "lock" state
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
        ergodox_right_led_1_on();
    }
    else {
        ergodox_right_led_1_off();
    }
};


// Override Unicode start method to use NEO_U instead of KC_U
void unicode_input_start (void) {
    register_code(KC_LCTL);
    register_code(KC_LSFT);
    register_code(NEO_U);
    unregister_code(NEO_U);
    unregister_code(KC_LSFT);
    unregister_code(KC_LCTL);
};
