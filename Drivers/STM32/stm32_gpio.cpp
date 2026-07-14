#include "stm32_gpio.hpp"


bool Stm32Gpio::config(uint32_t mode, uint32_t pull, uint32_t speed)
{
    return true;
}

bool Stm32Gpio::subscribe(bool rising_edge, bool falling_edge, void (*callback)(void*), void* ctx )
{
    return true;
}

bool Stm32Gpio::unsubscribe()
{
    return true;
}