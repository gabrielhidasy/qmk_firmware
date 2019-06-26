#include QMK_KEYBOARD_H


//notes:: LSHIFT and RSHIFT are defined in my keymap as space cadet shift

enum alt_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction
    U_T_AUTO,           //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    MD_BOOT,            //Restart into bootloader after hold timeout
    L_I_N,              //LED instruction preset Next
    L_I_P,              //LED instruciton preset Previous
    L_SC_N,             //LED Pattern scroll next
    L_SC_P,             //LED Pattern scroll next
    L_GLITI,            //LED Breath Speed Increase
    L_GLITD,            //LED Breath Speed Decrease
    L_GLITSM,           //LED Glitter smooth (glitter vs clouds)
    L_T_GCM,            //LED Toggle Game Color Mode
    L_T_GLIT,           //LED Toggle Glitter Effect
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [1] = LAYOUT(
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_MUTE, \
        L_T_BR,   L_PSD,   L_BRI,   L_PSI,   KC_TRNS,  KC_TRNS,  KC_TRNS, U_T_AUTO,U_T_AGCR,KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_END, \
        L_T_GLIT, L_PTP,   L_BRD,   L_PTN,   L_SC_P,   L_T_PTD,  L_SC_N,  L_I_P,   L_I_N,   KC_MYCM, KC_CALC, KC_TRNS,          L_T_GCM, KC_VOLU, \
        L_GLITSM, L_GLITD, L_T_ONF, L_GLITI, KC_TRNS,  MD_BOOT,  TG_NKRO, KC_TRNS, KC_MPRV, KC_MNXT, KC_MPLY, KC_F18,           KC_F16,  KC_VOLD, \
        KC_TRNS,  KC_TRNS, KC_TRNS,                              KC_MPLY,                            KC_RCTL, KC_TRNS, KC_F13,  KC_F14,  KC_F15  \
    ),
    /*
    [X] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
    ),
    */
};

const uint16_t PROGMEM fn_actions[] = {

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (keyboard_report->mods & MOD_BIT(KC_LSHIFT) || keyboard_report->mods & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (keyboard_report->mods & MOD_BIT(KC_LCTL) || keyboard_report->mods & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                led_enabled = !led_enabled;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                led_enabled = 0;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                led_animation_direction = !led_animation_direction;
            }
            return false;
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        //custom pleasuretek keycodes
        case L_I_N:
            if (record->event.pressed) {
                (led_instruction_id == led_instruction_count - 1) ? led_instruction_id = 0 : led_instruction_id++;
                set_led_animation_id(led_default_rotate_pattern[led_instruction_id]);
            }
            return false;
        case L_I_P:
            if (record->event.pressed) {
                (led_instruction_id == 0) ? led_instruction_id = led_instruction_count - 1 : led_instruction_id--;
                set_led_animation_id(led_default_rotate_pattern[led_instruction_id]);
            }
            return false;
        case L_SC_N:
            if(record->event.pressed) {
              led_animation_orientation++;
              if (led_animation_orientation > LED_SCROLL_MAX_INDEX) led_animation_orientation = LED_SCROLL_HORIZ;
            }
            return false;
        case L_SC_P:
            if(record->event.pressed) {
              if (led_animation_orientation == 0) led_animation_orientation = LED_SCROLL_MAX_INDEX;
              led_animation_orientation--;
            }
            return false;
        case L_GLITI:
            if (record->event.pressed) {
                if(glitter_step < 16) {
                  glitter_step++;
                }
            }
            return false;
        case L_GLITD:
            if (record->event.pressed) {
                if(glitter_step > 1) {
                  glitter_step--;
                } else {
                  glitter_step = 1;
                }
            }
            return false;
        case L_GLITSM:
            if (record->event.pressed) {
              glitter_smooth = !glitter_smooth;
            }
            return false;
        case L_T_GLIT:
            if (record->event.pressed) {
                led_animation_glittering = !led_animation_glittering;
                if (led_animation_glittering) {
                  uint8_t i;
                  for(i = 0; i < ISSI3733_LED_COUNT; i++) {
                    uint8_t rn = rand() % 255;
                    led_animation_glitter_cur[i] = rn;
                    if(i % 2) glitter_dir[i] = 1;
                    else glitter_dir[i] = -1;
                  }
                }
            }
            return false;
        case L_T_GCM:
            if (record->event.pressed) {
              led_game_colors = !led_game_colors;
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

led_instruction_t led_instructions_pleasuretek[] = {   //this is my fav default
    //{.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER,            .layer = 0, .id0 = 335478784,  .id1 = 16770591,   .r = 208, .g = 40,  .b = 233}, //purple
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 0, .id0 = 335478784,  .id1 = 16770591, .pattern_id = 16},
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id0 = 2147483648, .id1 = 487,        .r = 0,   .g = 255, .b = 0},  // ASDFJKL: green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER,            .layer = 0, .id0 = 201326592,                     .r = 255, .g = 255, .b = 255},  // [] white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL ,                                     .layer = 0, .id2 = 262136}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN ,                       .layer = 0, .id0 = 32767}, //esc-del top row pattern with no glitter
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1610645504, .id1 = 4278196224, .id2 = 4294705159, .id3 = 511},
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 262144, .id1 = 3153920,        .r = 0,   .g = 255, .b = 0}, //green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 131072, .id1 = 2048,           .r = 255, .g = 255, .b = 255}, //white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 65536,                         .r = 255, .g = 165, .b = 0},  //orange
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 16384, .id1 = 131072,          .r = 255, .g = 0,   .b = 0},  //red
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 33554432,                      .r = 255, .g = 215, .b = 0},  //yellow
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 1, .id1 = 8388736, .id2 = 2,   .r = 0,   .g = 255, .b = 255},  //cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 33554433,                      .r = 52,  .g = 83,  .b = 83},  //dark white/grey
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 16778496, .id2 = 5,            .r = 255, .g = 20,  .b = 147},  //pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 1, .id0 = 2113445888, .id1 = 4258133628, .id2 = 7, .pattern_id = 14}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 1, .id0 = 2147491838, .id1 = 2, .id2 = 4294967288, .id3 = 511, .pattern_id = 4},
    { .end = 1 }
};

led_instruction_t led_game_instructions_pleasuretek[] = {   //purple
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                                   .layer = 0, .id0 = 2147614720, .id1 = 3,      .pattern_id = 16},  //WASD green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id1 = 524288,                    .r = 0,   .g = 200, .b = 0},  //M green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id0 = 32798, .id1 = 335548416,   .r = 255, .g = 255, .b = 0},  // 1234,tab,shift,ctrl,alt gold
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id0 = 1572864, .id1 = 1036,        .r = 52,  .g = 83,  .b = 83},  //rt dark/dim white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id0 = 327680, .id1 = 57344,      .r = 127,   .g = 0, .b = 127},  //QEZXC purple
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,                                      .layer = 0, .id0 = 1071677408, .id1 = 200739824, .id2 = 262136}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 0, .id2 = 4294705152, .id3 = 511}, //pattern with no glitter
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 262144, .id1 = 3153920,        .r = 0,   .g = 255, .b = 0}, //green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 131072, .id1 = 2048,           .r = 255, .g = 255, .b = 255}, //white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 65536,                         .r = 255, .g = 165, .b = 0},  //orange
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 16384, .id1 = 131072,          .r = 255, .g = 0,   .b = 0},  //red
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 33554432,                      .r = 255, .g = 215, .b = 0},  //yellow
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 1, .id1 = 8388736, .id2 = 2,   .r = 0,   .g = 255, .b = 255},  //cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 33554433,                      .r = 52,  .g = 83,  .b = 83},  //dark white/grey
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 16778496, .id2 = 5,            .r = 255, .g = 20,  .b = 147},  //pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 1, .id0 = 2113445888, .id1 = 4258133628, .id2 = 7, .pattern_id = 11}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 1, .id0 = 2147491838, .id1 = 2, .id2 = 4294967288, .id3 = 511, .pattern_id = 2},
    { .end = 1 }
};

led_instruction_t led_instructions_rainmand[] = {  //rainbow white and rad as fuck
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 0, .id0 = 335478784,  .id1 = 16770591, .pattern_id = 12}, //pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 0, .id0 = 2147483648, .id1 = 487,      .pattern_id = 4},  // ASDFJKL: cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER,            .layer = 0, .id0 = 201326592,                   .r = 255, .g = 255, .b = 255},  // [] white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL ,                                     .layer = 0, .id2 = 262136}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 0, .id0 = 32767, .pattern_id = 4}, //esc-del top row pattern with no glitter
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 0, .id0 = 1610645504, .id1 = 4278196224, .id2 = 4294705159, .id3 = 511, .pattern_id = 4},
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 262144, .id1 = 3153920,        .r = 0,   .g = 255, .b = 0}, //green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 131072, .id1 = 2048,           .r = 255, .g = 255, .b = 255}, //white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 65536,                         .r = 255, .g = 165, .b = 0},  //orange
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 16384, .id1 = 131072,          .r = 255, .g = 0,   .b = 0},  //red
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 33554432,                      .r = 255, .g = 215, .b = 0},  //yellow
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 1, .id1 = 8388736, .id2 = 2,   .r = 0,   .g = 255, .b = 255},  //cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 33554433,                      .r = 52,  .g = 83,  .b = 83},  //dark white/grey
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 16778496, .id2 = 5,            .r = 255, .g = 20,  .b = 147},  //pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 1, .id0 = 2113445888, .id1 = 4258133628, .id2 = 7, .pattern_id = 14}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 1, .id0 = 2147491838, .id1 = 2, .id2 = 4294967288, .id3 = 511, .pattern_id = 4},
    { .end = 1 }
};

led_instruction_t led_instructions_rainmandi[] = {  //rainbow white inverse and rad as fuck
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 0, .id0 = 335478784,  .id1 = 16770591, .pattern_id = 4}, //pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 0, .id0 = 2147483648, .id1 = 487,      .pattern_id = 12},  // ASDFJKL: cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER,            .layer = 0, .id0 = 201326592,                   .r = 255, .g = 255, .b = 255},  // [] white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL ,                                     .layer = 0, .id2 = 262136}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 0, .id0 = 32767, .pattern_id = 4}, //esc-del top row pattern with no glitter
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 0, .id0 = 1610645504, .id1 = 4278196224, .id2 = 4294705159, .id3 = 511, .pattern_id = 12},
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 262144, .id1 = 3153920,        .r = 0,   .g = 255, .b = 0}, //green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 131072, .id1 = 2048,           .r = 255, .g = 255, .b = 255}, //white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 65536,                         .r = 255, .g = 165, .b = 0},  //orange
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 16384, .id1 = 131072,          .r = 255, .g = 0,   .b = 0},  //red
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 33554432,                      .r = 255, .g = 215, .b = 0},  //yellow
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 1, .id1 = 8388736, .id2 = 2,   .r = 0,   .g = 255, .b = 255},  //cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 33554433,                      .r = 52,  .g = 83,  .b = 83},  //dark white/grey
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 16778496, .id2 = 5,            .r = 255, .g = 20,  .b = 147},  //pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 1, .id0 = 2113445888, .id1 = 4258133628, .id2 = 7, .pattern_id = 14}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 1, .id0 = 2147491838, .id1 = 2, .id2 = 4294967288, .id3 = 511, .pattern_id = 4},
    { .end = 1 }
};

led_instruction_t led_instructions_pcw[] = {  //pink, cyan, and white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER,            .layer = 0, .id0 = 335478784,  .id1 = 16770591,   .r = 255, .g = 20,  .b = 147}, //pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id0 = 2147483648, .id1 = 487,        .r = 0,   .g = 255, .b = 255},  // ASDFJKL: cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER,            .layer = 0, .id0 = 201326592,                     .r = 255, .g = 255, .b = 255},  // [] white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL ,                                     .layer = 0, .id2 = 262136}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN,                        .layer = 0, .id0 = 32767}, //esc-del top row pattern with no glitter
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1610645504, .id1 = 4278196224, .id2 = 4294705159, .id3 = 511},
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 262144, .id1 = 3153920,        .r = 0,   .g = 255, .b = 0}, //green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 131072, .id1 = 2048,           .r = 255, .g = 255, .b = 255}, //white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 65536,                         .r = 255, .g = 165, .b = 0},  //orange
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 16384, .id1 = 131072,          .r = 255, .g = 0,   .b = 0},  //red
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 33554432,                      .r = 255, .g = 215, .b = 0},  //yellow
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 1, .id1 = 8388736, .id2 = 2,   .r = 0,   .g = 255, .b = 255},  //cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 33554433,                      .r = 52,  .g = 83,  .b = 83},  //dark white/grey
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 16778496, .id2 = 5,            .r = 255, .g = 20,  .b = 147},  //pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 1, .id0 = 2113445888, .id1 = 4258133628, .id2 = 7, .pattern_id = 11}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 1, .id0 = 2147491838, .id1 = 2, .id2 = 4294967288, .id3 = 511, .pattern_id = 2},
    { .end = 1 }
};

led_instruction_t led_game_instructions_pcw[] = {   //cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,             .layer = 0, .id0 = 2147614720, .id1 = 3,      .r = 255,   .g = 20, .b = 147},  //WASD pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,             .layer = 0, .id1 = 524288,                    .r = 0,   .g = 200, .b = 0},  //M green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,             .layer = 0, .id0 = 32798, .id1 = 335548416,   .r = 255, .g = 215, .b = 0},  // 1234,tab,shift,ctrl,alt gold
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,             .layer = 0, .id0 = 1572864, .id1 = 1036,        .r = 52,  .g = 83,  .b = 83},  //rt dark/dim white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,             .layer = 0, .id0 = 327680, .id1 = 57344,      .r = 0,   .g = 180, .b = 180},  //QEZXC cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,                .layer = 0, .id0 = 1071677408, .id1 = 200739824, .id2 = 262136}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN,  .layer = 0, .id2 = 4294705152, .id3 = 511}, //pattern with no glitter
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 262144, .id1 = 3153920,        .r = 0,   .g = 255, .b = 0}, //green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 131072, .id1 = 2048,           .r = 255, .g = 255, .b = 255}, //white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 65536,                         .r = 255, .g = 165, .b = 0},  //orange
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 16384, .id1 = 131072,          .r = 255, .g = 0,   .b = 0},  //red
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 33554432,                      .r = 255, .g = 215, .b = 0},  //yellow
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 1, .id1 = 8388736, .id2 = 2,   .r = 0,   .g = 255, .b = 255},  //cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 33554433,                      .r = 52,  .g = 83,  .b = 83},  //dark white/grey
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 16778496, .id2 = 5,            .r = 255, .g = 20,  .b = 147},  //pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 1, .id0 = 2113445888, .id1 = 4258133628, .id2 = 7, .pattern_id = 11}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 1, .id0 = 2147491838, .id1 = 2, .id2 = 4294967288, .id3 = 511, .pattern_id = 2},
    { .end = 1 }
};

led_instruction_t led_instructions_pgb[] = {   //purple, green, and black rainbow
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER,            .layer = 0, .id0 = 335478784,  .id1 = 16770591,   .r = 148, .g = 0,  .b = 211}, //purple
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id0 = 2147483648, .id1 = 487,        .r = 0,   .g = 255, .b = 0},  // ASDFJKL: green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER,            .layer = 0, .id0 = 201326592,                     .r = 255, .g = 255, .b = 255},  // [] white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL ,                                     .layer = 0, .id2 = 262136}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN ,                       .layer = 0, .id0 = 32767}, //esc-del top row pattern with no glitter
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1610645504, .id1 = 4278196224, .id2 = 4294705159, .id3 = 511},
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 262144, .id1 = 3153920,        .r = 0,   .g = 255, .b = 0}, //green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 131072, .id1 = 2048,           .r = 255, .g = 255, .b = 255}, //white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 65536,                         .r = 255, .g = 165, .b = 0},  //orange
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 16384, .id1 = 131072,          .r = 255, .g = 0,   .b = 0},  //red
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 33554432,                      .r = 255, .g = 215, .b = 0},  //yellow
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 1, .id1 = 8388736, .id2 = 2,   .r = 0,   .g = 255, .b = 255},  //cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 33554433,                      .r = 52,  .g = 83,  .b = 83},  //dark white/grey
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 16778496, .id2 = 5,            .r = 255, .g = 20,  .b = 147},  //pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 1, .id0 = 2113445888, .id1 = 4258133628, .id2 = 7, .pattern_id = 11}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 1, .id0 = 2147491838, .id1 = 2, .id2 = 4294967288, .id3 = 511, .pattern_id = 2},
    { .end = 1 }
};

led_instruction_t led_game_instructions_pgb[] = {   //purple
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id0 = 2147614720, .id1 = 3,      .r = 0,   .g = 255, .b = 0},  //WASD green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id1 = 524288,                    .r = 0,   .g = 200, .b = 0},  //M green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id0 = 32798, .id1 = 335548416,   .r = 255, .g = 215, .b = 0},  // 1234,tab,shift,ctrl,alt gold
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id0 = 1572864, .id1 = 1036,        .r = 52,  .g = 83,  .b = 83},  //rt dark/dim white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 0, .id0 = 327680, .id1 = 57344,      .r = 148,   .g = 0, .b = 211},  //QEZXC purple
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_NULL,                                      .layer = 0, .id0 = 1071677408, .id1 = 200739824, .id2 = 262136}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER, .layer = 0, .id2 = 4294705152, .id3 = 511}, //pattern with no glitter
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 262144, .id1 = 3153920,        .r = 0,   .g = 255, .b = 0}, //green
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 131072, .id1 = 2048,           .r = 255, .g = 255, .b = 255}, //white
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 65536,                         .r = 255, .g = 165, .b = 0},  //orange
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 16384, .id1 = 131072,          .r = 255, .g = 0,   .b = 0},  //red
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 33554432,                      .r = 255, .g = 215, .b = 0},  //yellow
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id0 = 1, .id1 = 8388736, .id2 = 2,   .r = 0,   .g = 255, .b = 255},  //cyan
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 33554433,                      .r = 52,  .g = 83,  .b = 83},  //dark white/grey
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB,                                   .layer = 1, .id1 = 16778496, .id2 = 5,            .r = 255, .g = 20,  .b = 147},  //pink
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN | LED_FLAG_USE_GLITTER,        .layer = 1, .id0 = 2113445888, .id1 = 4258133628, .id2 = 7, .pattern_id = 11}, //null off
    {.flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN,                               .layer = 1, .id0 = 2147491838, .id1 = 2, .id2 = 4294967288, .id3 = 511, .pattern_id = 2},
    { .end = 1 }
};

led_instruction_t led_instructions_gsheets[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 16385, .id1 = 16777216, .id2 = 1229530263, .id3 = 66, .r = 255, .g = 0, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 0, .id0 = 2147500030, .id1 = 487, .id2 = 614765128, .id3 = 297, .r = 0, .g = 255, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1610645504, .id1 = 4269808640, .id2 = 2450671904, .id3 = 148, .r = 255, .g = 255, .b = 0 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 536805376, .id1 = 8380952, .id2 = 0, .id3 = 0, .r = 255, .g = 255, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 1073758209, .id1 = 16777218, .id2 = 1229530263, .id3 = 66, .r = 255, .g = 0, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 16382, .id1 = 36864, .id2 = 614765128, .id3 = 297, .r = 0, .g = 255, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 2684387328, .id1 = 4269804544, .id2 = 2450671904, .id3 = 148, .r = 255, .g = 255, .b = 0 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 34013184, .id1 = 7406084, .id2 = 0, .id3 = 0, .r = 255, .g = 255, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 502792192, .id1 = 786456, .id2 = 0, .id3 = 0, .r = 67, .g = 67, .b = 67 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 1, .id2 = 0, .id3 = 0, .r = 204, .g = 204, .b = 204 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 8224, .id2 = 0, .id3 = 0, .r = 255, .g = 153, .b = 0 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 0, .id1 = 64, .id2 = 0, .id3 = 0, .r = 0, .g = 255, .b = 0 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 128, .id2 = 0, .id3 = 0, .r = 239, .g = 239, .b = 239 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 256, .id2 = 0, .id3 = 0, .r = 243, .g = 243, .b = 243 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 16384, .id2 = 0, .id3 = 0, .r = 0, .g = 0, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 131072, .id2 = 0, .id3 = 0, .r = 255, .g = 0, .b = 0 },
{.end = 1}
};
led_instruction_t led_game_instructions_gsheets[] = {
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 0, .id0 = 2147614721, .id1 = 3, .id2 = 1229530256, .id3 = 66, .r = 255, .g = 0, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1073774846, .id1 = 3690992640, .id2 = 2450671904, .id3 = 148, .r = 255, .g = 255, .b = 0 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 1069580032, .id1 = 66063328, .id2 = 7, .id3 = 0, .r = 0, .g = 0, .b = 0 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 851968, .id1 = 536993804, .id2 = 614765128, .id3 = 297, .r = 0, .g = 255, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 0, .id0 = 3145728, .id1 = 917520, .id2 = 0, .id3 = 0, .r = 255, .g = 255, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 1073758209, .id1 = 16777218, .id2 = 1229530263, .id3 = 66, .r = 255, .g = 0, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 16382, .id1 = 36864, .id2 = 614765128, .id3 = 297, .r = 0, .g = 255, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 2684387328, .id1 = 4269804544, .id2 = 2450671904, .id3 = 148, .r = 255, .g = 255, .b = 0 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 34013184, .id1 = 7406084, .id2 = 0, .id3 = 0, .r = 255, .g = 255, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 502792192, .id1 = 786456, .id2 = 0, .id3 = 0, .r = 67, .g = 67, .b = 67 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 1, .id2 = 0, .id3 = 0, .r = 204, .g = 204, .b = 204 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 8224, .id2 = 0, .id3 = 0, .r = 255, .g = 153, .b = 0 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 0, .id1 = 64, .id2 = 0, .id3 = 0, .r = 0, .g = 255, .b = 0 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 128, .id2 = 0, .id3 = 0, .r = 239, .g = 239, .b = 239 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 256, .id2 = 0, .id3 = 0, .r = 243, .g = 243, .b = 243 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 16384, .id2 = 0, .id3 = 0, .r = 0, .g = 0, .b = 255 },
{ .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB | LED_FLAG_USE_GLITTER, .layer = 1, .id0 = 0, .id1 = 131072, .id2 = 0, .id3 = 0, .r = 255, .g = 0, .b = 0 },
{.end = 1 }
};

led_instruction_t led_instructions_default[] = {
    {.flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN,                         .id0 = 32767}, //esc-del top row pattern with no glitter
    {.flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_GLITTER,  .id0 = 4294934528, .id1 = 4294967295, .id2 = 4294967295, .id3 = 511}, //esc-del top row pattern with no glitter
    { .end = 1 }
};

void *led_instruction_list[] = {
    led_instructions_pleasuretek,  //0
    led_instructions_rainmand,     //1
    led_instructions_rainmandi,    //2
    led_instructions_pcw,          //3
    led_instructions_pgb,          //4
    led_instructions_gsheets,      //5
    led_instructions_default       //6
};

void *led_game_instruction_list[] = {
    led_game_instructions_pleasuretek,
    led_game_instructions_pcw,
    led_game_instructions_pcw,
    led_game_instructions_pcw,
    led_game_instructions_pgb,
    led_game_instructions_gsheets,
    led_instructions_default
};

const uint8_t led_instruction_count = sizeof(led_instruction_list) / sizeof(led_instruction_list[0]);

uint8_t led_default_rotate_pattern[7] = {  //each instruction group in led_instruction_list has a default rotate pattern (number is position in led_setups array defined in led_programs.c)
    4,
    4,
    4,
    0,
    3,
    4,
    4
};

//this runs once when keyboard is plugged in
void rgb_matrix_init_user(void) {
    //Set which from led_instruction_list should be default
    uint8_t index = 0;    // led_instructions_pleasuretek  is position 0 in led_instruction_list  -- change this number to match in led_instruction_list to set default
    led_instruction_id = index;
    set_led_animation_id(led_default_rotate_pattern[index]);
    led_animation_orientation = LED_SCROLL_CENT;
}
