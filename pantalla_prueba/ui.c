// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////

// SCREEN: ui_S1
void ui_S1_screen_init(void);
void ui_event_S1(lv_event_t * e);
lv_obj_t * ui_S1;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Label1;

// SCREEN: ui_S2
void ui_S2_screen_init(void);
void ui_event_S2(lv_event_t * e);
lv_obj_t * ui_S2;
lv_obj_t * ui_Label6;

// SCREEN: ui_S3
void ui_S3_screen_init(void);
void ui_event_S3(lv_event_t * e);
lv_obj_t * ui_S3;
lv_obj_t * ui_Label5;

// SCREEN: ui_S4
void ui_S4_screen_init(void);
void ui_event_S4(lv_event_t * e);
lv_obj_t * ui_S4;
lv_obj_t * ui_Label4;
lv_obj_t * ui_Label8;

// SCREEN: ui_S5
void ui_S5_screen_init(void);
void ui_event_S5(lv_event_t * e);
lv_obj_t * ui_S5;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label7;

// SCREEN: ui_S6
void ui_S6_screen_init(void);
lv_obj_t * ui_S6;
void ui_event_Dropdown2(lv_event_t * e);
lv_obj_t * ui_Dropdown2;
lv_obj_t * ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_S1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_screen_change(ui_S2, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_screen_change(ui_S3, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_S2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(ui_S4, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_S3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_screen_change(ui_S2, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_S4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(ui_S5, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_S5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(ui_S4, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_Dropdown2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        _ui_flag_modify(ui_Dropdown2, LV_OBJ_FLAG_CLICKABLE, _UI_MODIFY_FLAG_TOGGLE);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_S1_screen_init();
    ui_S2_screen_init();
    ui_S3_screen_init();
    ui_S4_screen_init();
    ui_S5_screen_init();
    ui_S6_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_S1);
}
