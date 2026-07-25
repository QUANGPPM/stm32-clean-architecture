#ifndef BLINKLED_TASKS_H
#define BLINKLED_TASKS_H

#ifdef __cplusplus
#include "main.hpp"
extern "C" {
#endif
/* thread Ids*/
extern osThreadId led3TaskHandle;
extern osThreadId led4TaskHandle;
/* main Init*/
void appFreeRTOSInit(void);

#ifdef __cplusplus
}
#endif

#endif // BLINKLED_TASKS_H