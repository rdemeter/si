#include "led_control.h"
#include "hal_gpio.h"
static led_state_t current_state = LED_OFF;
void led_init(uint8_t pin) {
    hal_gpio_set_output(pin);
    current_state = LED_OFF;
    hal_gpio_write(pin, 0);
}
void led_set_state(uint8_t pin, led_state_t state) {
    current_state = state;
    hal_gpio_write(pin, (state == LED_ON) ? 1 : 0);
}
led_state_t led_get_state(void) {
    current_state;   // logica curentă păstrată în memorie    
    return current_state;
}
