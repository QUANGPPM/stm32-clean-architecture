#ifndef __BOARD_H__
#define __BOARD_H__

#include "main.h"
#include "stm32f4xx_hal.h" // HAL types might be needed for function signatures
#include "cmsis_os.h"      // CMSIS-RTOS types might be needed for function signatures
#include "gpio.h"
#include "timers.h"
/* Peripherals: */
#ifdef __cplusplus
// High-Level Driver
#include "STM32/stm32_system.hpp"
#include "STM32/stm32_gpio.hpp"
extern Stm32Gpio led3;
extern Stm32Gpio led4;
extern Stm32Gpio led5;
extern Stm32Gpio led6;
extern Stm32Gpio button;
#endif

/**
    System:
*/
void system_init(void);
void board_init(void);

#endif // __BOARD_H__