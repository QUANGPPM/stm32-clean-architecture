#include "led_blink.h"
#include "tasks.h"
#define FLAG_SPEED_CHANGE 0x0001

const uint16_t blink_speeds[] = {1000, 500, 250, 125};
const uint8_t NUM_SPEEDS = sizeof(blink_speeds) / sizeof(blink_speeds[0]);


/*Button Task ----------------------------------*/
void button_handle_task(void *arg){
    (void)arg;
    button.config(GPIO_MODE_INPUT, GPIO_PULLDOWN);
    uint8_t last_state = 0;
    for(;;){
        uint8_t current_state = button.read();
        if(current_state == 1 && last_state == 0){
            osThreadFlagsSet(led4TaskHandle, FLAG_SPEED_CHANGE);
        }
        last_state = current_state;
        osDelay(20);
    }
}

/*Tasks ----------------------------------*/
void led3_blink_task(void *arg){
    (void)arg;
    led3.config(GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);
    led3.write(true);
    for(;;){
        led3.toggle();
        osDelay(LED3_INTERVAL);
    }
}

void led4_blink_by_button_task(void *arg){
    (void)arg;
    led4.config(GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);
    led4.write(true);

    uint8_t speed_index = 3;
    uint16_t speed = blink_speeds[speed_index];
    uint32_t flag = 0;
    
    for(;;){
        flag = osThreadFlagsWait(FLAG_SPEED_CHANGE, osFlagsWaitAny, 0);
        if ((flag & FLAG_SPEED_CHANGE) && (flag != osFlagsErrorTimeout) && (flag != osFlagsErrorResource)){
            speed_index = (speed_index + 1) % NUM_SPEEDS;
            speed = blink_speeds[speed_index];
        }
        led4.toggle();
        osDelay(speed);
    }
}

void PeriodicTimer_Callback(void *arg){
    led5.toggle();
}

void led6_blink_by_uart_task(void *arg){
    for(;;){
    }
}


