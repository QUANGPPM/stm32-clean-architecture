#ifndef BLINKLED_TASKS_H
#define BLINKLED_TASKS_H

#ifdef __cplusplus
#include "main.hpp" // For LDx_GPIO_Port, LDx_Pin, and other main application definitions
#endif

#ifdef __cplusplus
extern "C" {
#endif
// #include "main.hpp"
#include "stm32f4xx_hal.h" // HAL types might be needed for function signatures
#include "cmsis_os.h"      // CMSIS-RTOS types might be needed for function signatures

void led_blink_task(void *argument);
void led5_blink_task(void *argument);

#ifdef __cplusplus
}
#endif

#endif // BLINKLED_TASKS_H