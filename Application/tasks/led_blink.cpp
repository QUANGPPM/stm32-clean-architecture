#include "led_blink.h"

void led3_blink_task(void *arg){
    (void)arg;
    led3.write(true);
    for(;;){
        led3.toggle();
        osDelay(LED3_INTERVAL);
    }
}

void led4_blink_by_button_task(void *arg){
    for(;;){
    }
}

void led5_blink_by_timer_task(void *arg){
    for(;;){
    }
}

void led6_blink_by_uart_task(void *arg){
    for(;;){
    }
}


