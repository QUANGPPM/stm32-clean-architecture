#ifndef __LED_BLINK_H__
#define __LED_BLINK_H__

#include "main.hpp" // For LDx_GPIO_Port, LDx_Pin, and other main application definitions

#define LED3_INTERVAL 500 //ms

#ifdef __cplusplus
extern "C" {
#endif


void led3_blink_task(void * arg);
void led4_blink_by_button_task(void *arg);
void led5_blink_by_timer_task(void *arg);
void led6_blink_by_uart_task(void *arg);

#ifdef __cplusplus
}
#endif

#endif //__LED_BLINK_H__