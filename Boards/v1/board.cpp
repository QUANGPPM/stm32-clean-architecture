#include "board.h"

Stm32Gpio led3 = Stm32Gpio(LD3_GPIO_Port, LD3_Pin);
Stm32Gpio led4 = Stm32Gpio(LD4_GPIO_Port, LD4_Pin);
Stm32Gpio led5 = Stm32Gpio(LD5_GPIO_Port, LD5_Pin);
Stm32Gpio led6 = Stm32Gpio(LD6_GPIO_Port, LD6_Pin);
Stm32Gpio button = Stm32Gpio(B1_GPIO_Port, B1_Pin);

void system_init(void){
    // Reset of all peripherals, Initializes the Flash interface and the Systick.
    HAL_Init();
    // Configure the system clock
    SystemClock_Config();

}

void board_init(void){
    // Initialize all configured peripherals
    MX_GPIO_Init();
    
    // External interrupt lines are individually enabled in stm32_gpio.cpp
    // HAL_NVIC_SetPriority(EXTI0_IRQn, 1, 0);
    // HAL_NVIC_EnableIRQ(EXTI0_IRQn);


}