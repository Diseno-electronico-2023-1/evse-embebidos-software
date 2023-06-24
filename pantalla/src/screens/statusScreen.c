#include <stdio.h>
#include <string.h>

#include <lvgl.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>


void pointerStatusScreen(int sel){

    static lv_point_t position1[] = { {2, 18}, {85, 18}, {85, 30}, {2, 30}, {2, 18}};
    static lv_point_t position2[] = { {2, 34}, {85, 34}, {85, 46}, {2, 46}, {2, 34}};
    static lv_point_t position3[] = { {2, 50}, {85, 50}, {85, 62}, {2, 62}, {2, 50}};
    static lv_point_t position4[] = { {90, 2}, {126, 2}, {126, 14}, {90, 14}, {90, 2}};
    static lv_point_t position5[] = { {90, 18}, {126, 18}, {126, 62}, {90, 62}, {90, 18}};


    static lv_style_t style_pointer;
    lv_style_init(&style_pointer);
    lv_style_set_line_width(&style_pointer, 1);
    lv_style_set_line_rounded(&style_pointer, false);


    lv_obj_t * pointer;
    pointer = lv_line_create(lv_scr_act());
    if (sel == 1){
        lv_line_set_points(pointer, position1, 5);
    } else if (sel == 2){
        lv_line_set_points(pointer, position2, 5);
    } else if (sel == 3){
        lv_line_set_points(pointer, position3, 5);
    } else if (sel == 4){
        lv_line_set_points(pointer, position4, 5);
    } else if (sel == 5){
        lv_line_set_points(pointer, position5, 5);
    }
    lv_obj_add_style(pointer, &style_pointer, 0);
}


void batery(int percent){
    
    char percentText[3];
    sprintf(percentText, "%d %", percent);

    lv_obj_t * percentLabel;
    percentLabel = lv_label_create(lv_scr_act());
    lv_label_set_text(percentLabel, percentText);
    lv_obj_set_pos(percentLabel, 93, 48);


    static lv_point_t pos_part1[] = { {100, 24}, {117, 24}, {117, 46}, {100, 46}, {100, 24}};
    static lv_point_t pos_part2[] = { {105, 24}, {105, 21}, {112, 21}, {112, 24}};
    static lv_point_t pos_charge1[] = { {102, 43}, {115, 43}};
    static lv_point_t pos_charge2[] = { {102, 38}, {115, 38}};
    static lv_point_t pos_charge3[] = { {102, 33}, {115, 33}};
    static lv_point_t pos_charge4[] = { {102, 28}, {115, 28}};

    static lv_style_t style_parts;
    lv_style_init(&style_parts);
    lv_style_set_line_width(&style_parts, 2);
    lv_style_set_line_rounded(&style_parts, false);

    static lv_style_t style_charges;
    lv_style_init(&style_charges);
    lv_style_set_line_width(&style_charges, 4);
    lv_style_set_line_rounded(&style_charges, false);

    lv_obj_t * part1;
    part1 = lv_line_create(lv_scr_act());
    lv_line_set_points(part1, pos_part1, 5);
    lv_obj_add_style(part1, &style_parts, 0);

    lv_obj_t * part2;
    part2 = lv_line_create(lv_scr_act());
    lv_line_set_points(part2, pos_part2, 4);
    lv_obj_add_style(part2, &style_parts, 0);

    if (percent >= 15){
        lv_obj_t * charge1;
        charge1 = lv_line_create(lv_scr_act());
        lv_line_set_points(charge1, pos_charge1, 2);
        lv_obj_add_style(charge1, &style_charges, 0);
    }
    if (percent >= 40){
        lv_obj_t * charge2;
        charge2 = lv_line_create(lv_scr_act());
        lv_line_set_points(charge2, pos_charge2, 2);
        lv_obj_add_style(charge2, &style_charges, 0);
    }
    if (percent >= 65){
        lv_obj_t * charge3;
        charge3 = lv_line_create(lv_scr_act());
        lv_line_set_points(charge3, pos_charge3, 2);
        lv_obj_add_style(charge3, &style_charges, 0);
    }
    if (percent >= 90){
        lv_obj_t * charge4;
        charge4 = lv_line_create(lv_scr_act());
        lv_line_set_points(charge4, pos_charge4, 2);
        lv_obj_add_style(charge4, &style_charges, 0);
    }
}


void status_screen(int sel, char nameProfile[16]){

    lv_obj_t * panel;
    panel = lv_obj_create(lv_scr_act());
    lv_obj_set_width(panel, 7000);
    lv_obj_set_height(panel, 7000);
    lv_obj_set_x(panel, -15);
    lv_obj_set_y(panel, -15);


    lv_obj_t * nameLabel;    
    nameLabel = lv_label_create(panel);
    lv_label_set_text(nameLabel, nameProfile);
    lv_obj_set_pos(nameLabel, 5, 0);

    lv_obj_t * infoLabel;    
    infoLabel = lv_label_create(panel);
    lv_label_set_text(infoLabel, "+Inf");
    lv_obj_set_pos(infoLabel, 93, 0);

    lv_obj_t * modelLabel;    
    modelLabel = lv_label_create(panel);
    lv_label_set_text(modelLabel, "Tesla S");
    lv_obj_set_pos(modelLabel, 13, 16);

    lv_obj_t * autonomyLabel;    
    autonomyLabel = lv_label_create(panel);
    lv_label_set_text(autonomyLabel, "57 km");
    lv_obj_set_pos(autonomyLabel, 13, 32);

    lv_obj_t * timeLabel;    
    timeLabel = lv_label_create(panel);
    lv_label_set_text(timeLabel, "2h 13min");
    lv_obj_set_pos(timeLabel, 13, 48);

    static lv_point_t pos_separtor1[] = { {88, 16}, {88, 64}};

    static lv_style_t style_separators;
    lv_style_init(&style_separators);
    lv_style_set_line_width(&style_separators, 2);
    lv_style_set_line_rounded(&style_separators, false);

    lv_obj_t * separator1;
    separator1 = lv_line_create(panel);
    lv_line_set_points(separator1, pos_separtor1, 2);
    lv_obj_add_style(separator1, &style_separators, 0);

    batery(27);

    pointerStatusScreen(sel);
}