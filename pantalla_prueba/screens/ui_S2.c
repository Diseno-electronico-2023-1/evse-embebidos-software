// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_S2_screen_init(void)
{
    ui_S2 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_S2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label6 = lv_label_create(ui_S2);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "Vehiculo \nconectado");

    lv_obj_add_event_cb(ui_S2, ui_event_S2, LV_EVENT_ALL, NULL);

}
