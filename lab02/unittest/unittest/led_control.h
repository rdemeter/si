#ifndef LED_CONTROL_H
#define LED_CONTROL_H
#include <stdint.h>
typedef enum {    LED_OFF = 0,    LED_ON = 1} led_state_t;
void led_init(uint8_t pin);
void led_set_state(uint8_t pin, led_state_t state);
led_state_t led_get_state(void);
#endif
