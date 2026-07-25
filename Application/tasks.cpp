#include "tasks.h"

static volatile uint8_t blink_led_mode = 0;
static volatile uint16_t time_delay = 500;
/* Private variables ---------------------------------------------------------*/
    /* Definitions for ledBlink */
/* Private function prototypes -----------------------------------------------*/

/* Private application code --------------------------------------------------*/
// Debounce time in milliseconds. Adjust this value if needed.
const uint32_t DEBOUNCE_TIME_MS = 100;

void user_button_exti_callback(void* ctx)
{
    static uint32_t last_valid_press_time = 0; // Stores the HAL_GetTick() value of the last *valid* button press

    // Check if enough time has passed since the last *valid* button press event.
    // This prevents multiple triggers from a single physical press due to bouncing.
    if ((HAL_GetTick() - last_valid_press_time) > DEBOUNCE_TIME_MS)
    {
        last_valid_press_time = HAL_GetTick(); // Record the time of this valid event

        switch(blink_led_mode){
            case 0:
                blink_led_mode = 1;
                time_delay = 100;
                break;
            case 1:
                blink_led_mode = 0;
                time_delay = 500;
                break;
            default:
                break;
        }
    }
}
void led_blink_follow_button_task(void *argument)
{
    (void)argument;
    button.config(GPIO_MODE_IT_RISING, GPIO_PULLDOWN);
    button.subscribe(false, true, user_button_exti_callback, nullptr);
    led3.config(GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);
    led3.write(false);
    for (;;)
    {
        led3.toggle();
        osDelay(time_delay);
    }
}
void led_blink_task(void *argument)
{
    (void)argument; // Cast argument to void to suppress unused parameter warning
    led4.config(GPIO_MODE_OUTPUT_PP, GPIO_NOPULL);
    led4.write(false);

    for (;;)
    {
        led4.toggle();
        osDelay(500); 
    }
}

void vled5_blink_timer_callback(TimerHandle_t xTimer){
    (void)xTimer;
    led5.toggle();
}
