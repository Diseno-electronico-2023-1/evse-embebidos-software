#include <stdio.h>
#include <string.h>

#include <lvgl.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>


void welcome_screen(void){

    lv_obj_t * panel;
    panel = lv_obj_create(lv_scr_act());
    lv_obj_set_width(panel, 7000);
    lv_obj_set_height(panel, 7000);
    lv_obj_set_x(panel, -15);
    lv_obj_set_y(panel, -15);


    lv_obj_t * label1;
    label1 = lv_label_create(panel);
    lv_label_set_text(label1, "Bienvenido a");
    lv_obj_set_pos(label1, 20, 16);

    lv_obj_t * label2;
    label2 = lv_label_create(panel);
    lv_label_set_text(label2, "UN Cargador");
    lv_obj_set_pos(label2, 20, 32);


    static lv_point_t pos_line1[] = { {0, 8}, {128, 8}};
    static lv_point_t pos_line2[] = { {0, 56}, {128, 56}};

    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 16);
    lv_style_set_line_rounded(&style_line, false);

    lv_obj_t * line1;
    line1 = lv_line_create(lv_scr_act());
    lv_line_set_points(line1, pos_line1, 2);
    lv_obj_add_style(line1, &style_line, 0);

    lv_obj_t * line4;
    line4 = lv_line_create(panel);
    lv_line_set_points(line4, pos_line2, 2);
    lv_obj_add_style(line4, &style_line, 0);
}