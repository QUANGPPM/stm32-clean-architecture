#ifndef BLINKLED_TASKS_H
#define BLINKLED_TASKS_H

#ifdef __cplusplus
#include "main.hpp" // For LDx_GPIO_Port, LDx_Pin, and other main application definitions
#endif
#include "FreeRTOS.h"
#include "timers.h"
#ifdef __cplusplus
extern "C" {
#endif

void led_blink_follow_button_task(void *argument);
void led_blink_task(void *argument);
void vled5_blink_timer_callback(TimerHandle_t xTimer);

#ifdef __cplusplus
}
#endif

#endif // BLINKLED_TASKS_H