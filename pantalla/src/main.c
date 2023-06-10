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

void ui_Bienvenida_screen_init(void)
{
    lv_obj_t *ui_Bienvenida = lv_obj_create(lv_scr_act());
    lv_obj_clear_flag(ui_Bienvenida, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t *ui_Label2 = lv_label_create(ui_Bienvenida);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, 0);
    lv_obj_set_y(ui_Label2, -12);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "UN Cargador");

    lv_obj_t *ui_Label1 = lv_label_create(ui_Bienvenida);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, 0);
    lv_obj_set_y(ui_Label1, -30);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "Bienvenido");

//    lv_obj_add_event_cb(ui_Bienvenida, ui_event_Bienvenida, LV_EVENT_ALL, NULL);

}


void prueba(void)
{
    /*Create an object with the new style*/
    lv_obj_t * panel = lv_obj_create(lv_scr_act());
    //lv_obj_set_pos(panel, 0, 0);
    lv_obj_align(panel, LV_ALIGN_TOP_LEFT, 0, 0);
//    lv_obj_set_size(panel, 1000, 1000);
//    lv_obj_center(panel);

    lv_obj_t * label1;
    
    label1 = lv_label_create(lv_scr_act());
    lv_label_set_text(label1, "UN Cargador");
    lv_obj_set_pos(label1, 0, 0);
    
//    lv_obj_t * item1;
    
//    item1 = lv_obj_create(lv_scr_act());
//    lv_obj_set_pos(item1, 0, 0);
    
    /*Create an array for the points of the line*/
    static lv_point_t line_points[] = { {2, 2}, {125, 2}, {125, 61}, {2, 61}, {2, 2} };

    /*Create style*/
    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 2);
    lv_style_set_line_rounded(&style_line, true);

    /*Create a line and apply the new style*/
    lv_obj_t * line1;
    line1 = lv_line_create(lv_scr_act());
    lv_line_set_points(line1, line_points, 5);     /*Set the points*/
    lv_obj_add_style(line1, &style_line, 0);
    lv_obj_center(line1);
    
    
    
    /*lv_obj_t * label2;
    
    label2 = lv_label_create(panel);
    lv_label_set_text(label2, "UN Cargador");
    lv_obj_set_pos(label2, 20, 5);  
    */
//    lv_obj_set_size(label, 128, 20);
//    lv_obj_center(label);

//    child = lv_obj_create(panel);
//    lv_obj_set_pos(child, 100, 60);
//    lv_obj_set_size(child, 80, 80);

//    lv_obj_t * child2 = lv_btn_create(child);
//    lv_obj_set_size(child2, 100, 50);

//    label = lv_label_create(child2);
//    lv_label_set_text(label, "Right");
//    lv_obj_center(label);

//    child = lv_obj_create(panel);
//    lv_obj_set_pos(child, 40, 40);
//    lv_obj_set_size(child, 100, 70);
//    label = lv_label_create(child);
//    lv_label_set_text(label, "Bottom");
//    lv_obj_center(label);
}

int main(void)
{
	char count_str[11] = {0};
	const struct device *display_dev;
	lv_obj_t *count_label;

	display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display_dev)) {
		LOG_ERR("Device not ready, aborting test");
		return 0;
	}

	prueba();
	lv_task_handler();
	display_blanking_off(display_dev);
}
