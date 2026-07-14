#ifndef __BOARD_H__
#define __BOARD_H__

#include "main.h"
#include "gpio.h"

// High-Level Driver
#include "STM32/stm32_system.hpp"
#include "STM32/stm32_gpio.hpp"

#ifdef __cplusplus
extern "C" {
#endif

/* Peripherals: */
#ifdef __cplusplus
extern Stm32Gpio led4;
extern Stm32Gpio led5;
#endif

/**
    System:
*/
void system_init(void);

#ifdef __cplusplus
}
#endif

#endif // __BOARD_H__