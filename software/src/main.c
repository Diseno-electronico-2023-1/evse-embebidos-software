#include <stdio.h>
#include <string.h>

#include <lvgl.h>
// #include <zephyr/device.h>
// #include <zephyr/devicetree.h>
// #include <zephyr/drivers/display.h>
// #include <zephyr/drivers/gpio.h>
// #include <zephyr/kernel.h>
// #include <zephyr/sys/printk.h>

// #define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
// #include <zephyr/logging/log.h>
// LOG_MODULE_REGISTER(app);

#include "csr.h"
#include "screens/offScreen.c"
#include "screens/welcomeScreen.c"
#include "screens/profileScreen.c"
#include "screens/statusScreen.c"

#include "server/server.c"

// Botones
    const int btn_back = 1;
    const int btn_up   = 2;
    const int btn_down = 4;
    const int btn_next = 8;

int moveSelector(int selector, int btn_state, int maxSelector){
    if (btn_state == btn_down){
        if (selector == maxSelector){
            selector = 1;
        } else{
            selector ++;
        }
    } else if (btn_state == btn_up){
        if (selector == 1){
            selector = maxSelector;
        } else{
            selector --;
        }
    }
    return selector;
}


/* void main(void){
    char names[3][16];
    strncpy(names[0], "Hugo", sizeof(names[0]) - 1);
    strncpy(names[1], "Paco", sizeof(names[1]) - 1);
    strncpy(names[2], "Luis", sizeof(names[2]) - 1);

    int percent = 0;


    printk("Inicio \n");

    bool work = 1;
    int state;
    int btn_state;
    int selector = 1;
    int profile_sel = 1;

    // Estados
    const int welcome = '1';
    const int selprofile = '2';
    const int status = '3';
    const int end = '4';
        
    state = welcome;
    welcome_screen();
    lv_task_handler();

    while (work){
        switch (state){
        case welcome :
            btn_state = user_gpio_in_read();

            if (btn_state != 0){   
                profile_screen(1, names);
                lv_task_handler();
                selector = 1;
                state = selprofile;
            }
            break;
        
        case selprofile :
            btn_state = user_gpio_in_read();
            
            if (btn_state != 0){   
                if (btn_state == btn_back){
                    state = welcome;
                    welcome_screen();
                    lv_task_handler();
                } else if (btn_state == btn_next){
                    state = status;
                    profile_sel = selector - 1;
                    selector = 1;
                    status_screen(selector, names[profile_sel], percent);
                    lv_task_handler();
                } else{
                    selector = moveSelector(selector, btn_state, 3);
                    profile_screen(selector, names);
                    lv_task_handler();
                }
            }
            break;

        case status :
            btn_state = user_gpio_in_read();
            
            if (btn_state != 0){   
                if (btn_state == btn_back){
                    state = selprofile;
                    selector = 1;
                    profile_screen(selector, names);
                    lv_task_handler();                    
                } else if (btn_state == btn_next){
                    off_screen();
                    lv_task_handler();
                    selector = 1;
                    state = end;
                } else{
                    selector = moveSelector(selector, btn_state, 5);
                    status_screen(selector, names[profile_sel], percent);
                    lv_task_handler();
                }
            }
            break;

        default:
            work = 0;
            break;
        }

        k_sleep(K_MSEC(100));
    }
    
    printk("Fin \n");

} */


void main(void){
    
    welcome_screen();
    lv_task_handler();
    server();
        
}

//k_sleep(K_MSEC(1000));
//perfil();
//lv_task_handler();
//printk("Data: %x \n", data);
//user_gpio_out_write(1);
