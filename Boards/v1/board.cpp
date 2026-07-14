#include "board.h"

Stm32Gpio led4 = Stm32Gpio(LD4_GPIO_Port, LD4_Pin);
Stm32Gpio led5 = Stm32Gpio(LD5_GPIO_Port, LD5_Pin);

void system_init(void){
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
}