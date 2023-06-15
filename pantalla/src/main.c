/*
 * Copyright (c) 2018 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "csr.h"




#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(app);

static uint32_t count;

#ifdef CONFIG_GPIO
static struct gpio_dt_spec button_gpio = GPIO_DT_SPEC_GET_OR(
		DT_ALIAS(sw0), gpios, {0});
static struct gpio_callback button_callback;

static void button_isr_callback(const struct device *port,
				struct gpio_callback *cb,
				uint32_t pins)
{
	ARG_UNUSED(port);
	ARG_UNUSED(cb);
	ARG_UNUSED(pins);

	count = 0;
}
#endif

void off(void)
{
    lv_obj_t * panel;
    panel = lv_obj_create(lv_scr_act());
    lv_obj_set_width(panel, 7000);
    lv_obj_set_height(panel, 7000);
    lv_obj_set_x(panel, -15);
    lv_obj_set_y(panel, -15);

    static lv_point_t line_points1[] = { {0, 8}, {128, 8}};
    static lv_point_t line_points2[] = { {0, 24}, {128, 24}};
    static lv_point_t line_points3[] = { {0, 40}, {128, 40}};
    static lv_point_t line_points4[] = { {0, 56}, {128, 56}};

    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 16);
    lv_style_set_line_rounded(&style_line, false);
    
    lv_obj_t * line1;
    line1 = lv_line_create(panel);
    lv_line_set_points(line1, line_points1, 2);
    lv_obj_add_style(line1, &style_line, 0);

    lv_obj_t * line2;
    line2 = lv_line_create(panel);
    lv_line_set_points(line2, line_points2, 2);
    lv_obj_add_style(line2, &style_line, 0);

    lv_obj_t * line3;
    line3 = lv_line_create(panel);
    lv_line_set_points(line3, line_points3, 2);
    lv_obj_add_style(line3, &style_line, 0);

    lv_obj_t * line4;
    line4 = lv_line_create(panel);
    lv_line_set_points(line4, line_points4, 2);
    lv_obj_add_style(line4, &style_line, 0);
}

void bienvenida(void)
{
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

    static lv_point_t line_points1[] = { {0, 8}, {128, 8}};
    static lv_point_t line_points4[] = { {0, 56}, {128, 56}};

    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 16);
    lv_style_set_line_rounded(&style_line, false);

    lv_obj_t * line1;
    line1 = lv_line_create(lv_scr_act());
    lv_line_set_points(line1, line_points1, 2);
    lv_obj_add_style(line1, &style_line, 0);

    lv_obj_t * line4;
    line4 = lv_line_create(panel);
    lv_line_set_points(line4, line_points4, 2);
    lv_obj_add_style(line4, &style_line, 0);
}

void perfil(void)
{
    lv_obj_t * panel;
    panel = lv_obj_create(lv_scr_act());
    lv_obj_set_width(panel, 7000);
    lv_obj_set_height(panel, 7000);
    lv_obj_set_x(panel, -15);
    lv_obj_set_y(panel, -15);

    lv_obj_t * label1;
    
    label1 = lv_label_create(lv_scr_act());
    lv_label_set_text(label1, "Select a profile");
    lv_obj_set_pos(label1, 5, 0);

    lv_obj_t * label2;
    
    label2 = lv_label_create(panel);
    lv_label_set_text(label2, "- Profile 1");
    lv_obj_set_pos(label2, 20, 16);

    lv_obj_t * label3;
    
    label3 = lv_label_create(panel);
    lv_label_set_text(label3, "- Profile 2");
    lv_obj_set_pos(label3, 20, 32);

    lv_obj_t * label4;

    label4 = lv_label_create(panel);
    lv_label_set_text(label4, "- Profile 3");
    lv_obj_set_pos(label4, 20, 48);
}

int main(void)
{   
    user_gpio_oe_write(0);
    printk("Inicio");

    int data = 0;
    int cont = 0;
    bool state = 1;
    while (state){   
        data = user_gpio_in_read();
        if (data == 1){
            bienvenida();
            lv_task_handler();
        }
        else if (data == 2)
        {
            perfil();
            lv_task_handler();
        }
        else if (data == 3)
        {
            state = 0;
        }
    }
    //k_sleep(K_MSEC(1000));
    //perfil();
    //lv_task_handler();
    //printk("Data: %x \n", data);
    //user_gpio_out_write(1);
}
