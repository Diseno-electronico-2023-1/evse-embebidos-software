#include <stdio.h>
#include <string.h>

#include <lvgl.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>


void off_screen(void){

    lv_obj_t * panel;
    panel = lv_obj_create(lv_scr_act());
    lv_obj_set_width(panel, 7000);
    lv_obj_set_height(panel, 7000);
    lv_obj_set_x(panel, -15);
    lv_obj_set_y(panel, -15);


    static lv_point_t pos_line1[] = { {0, 8}, {128, 8}};
    static lv_point_t pos_line2[] = { {0, 24}, {128, 24}};
    static lv_point_t pos_line3[] = { {0, 40}, {128, 40}};
    static lv_point_t pos_line4[] = { {0, 56}, {128, 56}};

    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 16);
    lv_style_set_line_rounded(&style_line, false);
    
    lv_obj_t * line1;
    line1 = lv_line_create(panel);
    lv_line_set_points(line1, pos_line1, 2);
    lv_obj_add_style(line1, &style_line, 0);

    lv_obj_t * line2;
    line2 = lv_line_create(panel);
    lv_line_set_points(line2, pos_line2, 2);
    lv_obj_add_style(line2, &style_line, 0);

    lv_obj_t * line3;
    line3 = lv_line_create(panel);
    lv_line_set_points(line3, pos_line3, 2);
    lv_obj_add_style(line3, &style_line, 0);

    lv_obj_t * line4;
    line4 = lv_line_create(panel);
    lv_line_set_points(line4, pos_line4, 2);
    lv_obj_add_style(line4, &style_line, 0);
}