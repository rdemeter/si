#include "hal_gpio.h"
#include <avr/io.h>
void hal_gpio_set_output(uint8_t pin) {
    // Exemplu simplu pentru pinul 0 din PORTB (PB0)
    DDRB |= (1 << pin);
}
void hal_gpio_write(uint8_t pin, uint8_t value) {
    if (value) {
        PORTB |= (1 << pin);
    } else {
        PORTB &= ~(1 << pin);
    }
}
