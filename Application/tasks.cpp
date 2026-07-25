#include "tasks.h"
#include "led_blink.h"
#include "main.hpp"
/* Timer IDs*/
osTimerId_t periodicTimer;
/* Timer Attributes*/
osTimerAttr_t led5CallbackAttr = {
  .name = "Led 5 Callback"
};
/* Thread IDs ---------------------------------------------------------*/
osThreadId led3TaskHandle;
osThreadId led4TaskHandle;
osThreadId buttonTaskHandle;
/* Thread Attributes ---------------------------------------------------------*/
osThreadAttr_t led3TaskAttr = {
    .name = "Led 3 Task",
    .stack_size = 128 * 4,
    .priority = osPriorityNormal,
};
osThreadAttr_t led4TaskAttr = {
    .name = "Led 4 Task",
    .stack_size = 128 * 4,
    .priority = osPriorityNormal,
};
osThreadAttr_t buttonTaskAttr = {
    .name = "Button Task",
    .stack_size = 128 * 4,
    .priority = osPriorityNormal,
};

/* function ----------------------------------------------------------*/
void appFreeRTOSInit(void)
{
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  periodicTimer = osTimerNew(PeriodicTimer_Callback, osTimerPeriodic, nullptr, &led5CallbackAttr);
  if(periodicTimer != nullptr){
    osTimerStart(periodicTimer, 1000);
  }
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */

  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
    led3TaskHandle = osThreadNew(led3_blink_task, nullptr, &led3TaskAttr);
    led4TaskHandle = osThreadNew(led4_blink_by_button_task, nullptr, &led4TaskAttr);
    buttonTaskHandle = osThreadNew(button_handle_task, nullptr, &buttonTaskAttr);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */
}

