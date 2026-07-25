#ifndef __STM32_GPIO_HPP
#define __STM32_GPIO_HPP
#include <gpio.h>

class Stm32Gpio {
public:
    // default value for GPIO pin that don't use (support operator bool)
    static const Stm32Gpio none;

    Stm32Gpio() : port(nullptr), pin_mask(0), pin_number(0) {}
    Stm32Gpio (GPIO_TypeDef* port, uint16_t pin) : port(port), pin_mask(pin), pin_number(0) {
        uint16_t pin_mask = this->pin_mask >> 1;
        while(pin_mask){
            pin_number++;
            pin_mask >>= 1;
        }
    }

    operator bool() const {return port && pin_mask;}
    
    bool config(uint32_t mode, uint32_t pull, uint32_t speed = GPIO_SPEED_FREQ_LOW);

    void write(bool state)
    {
        HAL_GPIO_WritePin(port, pin_mask, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
    };
    bool read()
    {
        return port->IDR & pin_mask;
    };
    void toggle()
    {
        HAL_GPIO_TogglePin(port, pin_mask);
    }

    // Subscribe/unsubscribe interrupt
    bool subscribe(bool rising_edge, bool falling_edge, void (*callback)(void*), void* ctx );
    void unsubscribe();

// public --> call from outside 
    GPIO_TypeDef* port;
    uint16_t pin_mask;  // should to store pin number than mask
    uint16_t pin_number;
};

#endif