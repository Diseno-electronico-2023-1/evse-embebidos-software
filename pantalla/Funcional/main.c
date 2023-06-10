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

void lv_example_line_1(void)
{
    /*Create an array for the points of the line*/
    static lv_point_t line_points[] = { {0, 0}, {0, 64}, {64, 64}, {128, 0}, {0, 0} };

    /*Create style*/
    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 2);
    //lv_style_set_line_color(&style_line, lv_palette_main(0));
    lv_style_set_line_rounded(&style_line, true);

    /*Create a line and apply the new style*/
    lv_obj_t * line1;
    line1 = lv_line_create(lv_scr_act());
    lv_line_set_points(line1, line_points, 5);     /*Set the points*/
    lv_obj_add_style(line1, &style_line, 0);
//    lv_obj_center(line1);
}

/*static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_current_target(e);

    if(code == LV_EVENT_VALUE_CHANGED) {
        lv_calendar_date_t date;
        if(lv_calendar_get_pressed_date(obj, &date)) {
            LV_LOG_USER("Clicked date: %02d.%02d.%d", date.day, date.month, date.year);
        }
    }
}

void lv_example_calendar_1(void)
{
    lv_obj_t  * calendar = lv_calendar_create(lv_scr_act());
    lv_obj_set_size(calendar, 185, 185);
    lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 5);
    lv_obj_add_event_cb(calendar, event_handler, LV_EVENT_ALL, NULL);

    lv_calendar_set_today_date(calendar, 2023, 06, 5);
    lv_calendar_set_showed_date(calendar, 2023, 06);

    // Highlight a few days
    static lv_calendar_date_t highlighted_days[3];       //Only its pointer will be saved so should be static
    highlighted_days[0].year = 2023;
    highlighted_days[0].month = 06;
    highlighted_days[0].day = 6;

    highlighted_days[1].year = 2021;
    highlighted_days[1].month = 02;
    highlighted_days[1].day = 11;

    highlighted_days[2].year = 2022;
    highlighted_days[2].month = 02;
    highlighted_days[2].day = 22;

    lv_calendar_set_highlighted_dates(calendar, highlighted_days, 3);

#if LV_USE_CALENDAR_HEADER_DROPDOWN
    lv_calendar_header_dropdown_create(calendar);
#elif LV_USE_CALENDAR_HEADER_ARROW
    lv_calendar_header_arrow_create(calendar);
#endif
    lv_calendar_set_showed_date(calendar, 2021, 10);
}*/

void lv_example_scroll_1(void)
{
    /*Create an object with the new style*/
    lv_obj_t * panel = lv_obj_create(lv_scr_act());
    lv_obj_set_size(panel, 128, 64);
    lv_obj_center(panel);

    lv_obj_t * child;
    lv_obj_t * label;

    child = lv_obj_create(panel);
    lv_obj_set_pos(child, -20, -15);
    lv_obj_set_size(child, 128, 20);
    label = lv_label_create(child);
    lv_label_set_text(label, "UN Cargador");
    lv_obj_center(label);

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
	lv_obj_t *hello_world_label;
	lv_obj_t *count_label;

	display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display_dev)) {
		LOG_ERR("Device not ready, aborting test");
		return 0;
	}


//	if (IS_ENABLED(CONFIG_LV_Z_POINTER_KSCAN)) {
//		lv_obj_t *hello_world_button;

//		hello_world_button = lv_btn_create(lv_scr_act());
//		lv_obj_align(hello_world_button, LV_ALIGN_CENTER, 0, 0);
//		hello_world_label = lv_label_create(hello_world_button);
//	} else {
//		hello_world_label = lv_label_create(lv_scr_act());
//	}
	
	
	
//	lv_label_set_text(hello_world_label, "Holi xd");
//	lv_obj_align(hello_world_label, LV_ALIGN_CENTER, 0, 0);

//	count_label = lv_label_create(lv_scr_act());
//	lv_obj_align(count_label, LV_ALIGN_BOTTOM_MID, 0, 0);


//	lv_example_line_1();
//	lv_task_handler();
//	display_blanking_off(display_dev);

	lv_example_scroll_1();
	lv_task_handler();
	display_blanking_off(display_dev);

/*	while (0) {
		if ((count % 100) == 0U) {
			sprintf(count_str, "%d", count/100U);
			lv_label_set_text(count_label, count_str);
		}
		//lv_task_handler();
		++count;
		k_sleep(K_MSEC(10));
	}*/
}
