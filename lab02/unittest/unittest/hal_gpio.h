#ifndef HAL_GPIO_H
#define HAL_GPIO_H
#include <stdint.h>// Funcții pentru configurarea pinului și scrierea valorii
void hal_gpio_set_output(uint8_t pin);
void hal_gpio_write(uint8_t pin, uint8_t value);
#endif
