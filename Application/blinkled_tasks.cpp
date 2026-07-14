#include "blinkled_tasks.h"
// #include "main.hpp" // For LDx_GPIO_Port, LDx_Pin, and other main application definitions

/* Private variables ---------------------------------------------------------*/
    /* Definitions for ledBlink */
/* Private function prototypes -----------------------------------------------*/

/* Private application code --------------------------------------------------*/
void led_blink_task(void *argument)
{
    (void)argument; // Cast argument to void to suppress unused parameter warning

    led4.write(false);

    for (;;)
    {
        led4.toggle();
        osDelay(500); 
    }
}
void led5_blink_task(void *argument){
    (void)argument;
    led5.write(false);
    for(;;)
    {
        led5.toggle();
        osDelay(500);
    }
}
