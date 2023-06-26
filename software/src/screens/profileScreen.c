#include <stdio.h>
#include <string.h>

#include <lvgl.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>


void pointerProfileScreen(int sel){

    static lv_point_t position1[] = { {2, 18}, {126, 18}, {126, 30}, {2, 30}, {2, 18}};
    static lv_point_t position2[] = { {2, 34}, {126, 34}, {126, 46}, {2, 46}, {2, 34}};
    static lv_point_t position3[] = { {2, 50}, {126, 50}, {126, 62}, {2, 62}, {2, 50}};

    static lv_style_t style_pointer;
    lv_style_init(&style_pointer);
    lv_style_set_line_width(&style_pointer, 1);
    lv_style_set_line_rounded(&style_pointer, false);


    lv_obj_t * pointer;
    pointer = lv_line_create(lv_scr_act());
    if (sel == 1){
        lv_line_set_points(pointer, position1, 5);
    }else if (sel == 2){
        lv_line_set_points(pointer, position2, 5);
    }else if (sel == 3){
        lv_line_set_points(pointer, position3, 5);
    }
    lv_obj_add_style(pointer, &style_pointer, 0);
}


void profile_screen(int sel, char namesProfiles[3][16]){

    lv_obj_t * panel;
    panel = lv_obj_create(lv_scr_act());
    lv_obj_set_width(panel, 7000);
    lv_obj_set_height(panel, 7000);
    lv_obj_set_x(panel, -15);
    lv_obj_set_y(panel, -15);


    lv_obj_t * label1;
    label1 = lv_label_create(panel);
    lv_label_set_text(label1, "Select a profile");
    lv_obj_set_pos(label1, 5, 0);

    
    char profile1[16];
    sprintf(profile1, "1 . %s", namesProfiles[0]);

    lv_obj_t * name1;
    name1 = lv_label_create(panel);
    lv_label_set_text(name1, profile1);
    lv_obj_set_pos(name1, 15, 16);


    char profile2[16];
    sprintf(profile2, "2 . %s", namesProfiles[1]);

    lv_obj_t * name2;
    name2 = lv_label_create(panel);
    lv_label_set_text(name2, profile2);
    lv_obj_set_pos(name2, 15, 32);


    char profile3[16];
    sprintf(profile3, "3 . %s", namesProfiles[2]);

    lv_obj_t * name3;
    name3 = lv_label_create(panel);
    lv_label_set_text(name3, profile3);
    lv_obj_set_pos(name3, 15, 48);

    pointerProfileScreen(sel);
}