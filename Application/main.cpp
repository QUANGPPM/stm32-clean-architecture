#include "main.hpp"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h" // Include the CMSIS-RTOS header
#include "tasks.h"




int main()
{
    // system init (HAL, System Clock)
    system_init();
    
    // Initialize basic hardware (GPIOs, Interrupts,...)
    board_init(); 
    
    // Initialize the CMSIS-RTOS Kernel
    osKernelInitialize();

    // This function contains calls to create other tasks, queues, semaphores, etc.
    appFreeRTOSInit();

    // Start the CMSIS-RTOS scheduler
    // This function transfers control to the RTOS, and the main loop below will not be reached
    // unless there is a critical error.
    osKernelStart();

    for (;;)
    {
    }
}