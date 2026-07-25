#include "tasks.h"
#include "led_blink.h"
#include "main.hpp"
/* variables ---------------------------------------------------------*/
osThreadId led3TaskHandle;
osThreadAttr_t led3TaskAttr = {
    .name = "Led 3 Task",
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

  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */

  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
    led3TaskHandle = osThreadNew(led3_blink_task, nullptr, &led3TaskAttr);
  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */
}

