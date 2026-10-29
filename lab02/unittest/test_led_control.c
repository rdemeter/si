#include <assert.h>
#include <stdio.h>
#include "led_control.h"
// Starea mock a pinului pentru testestatic 
uint8_t mock_pin_value = 0xFF;
static uint8_t mock_pin_direction = 0x00;
// Implementări "mock" ale HAL-ului folosite la testare pe PC
void hal_gpio_set_output(uint8_t pin) {
    mock_pin_direction |= (1 << pin);
}
void hal_gpio_write(uint8_t pin, uint8_t value) {
    if (value) {
        mock_pin_value |= (1 << pin);
    } else {
        mock_pin_value &= ~(1 << pin);
    }
}
void run_tests(void) {
    printf("Ruleaza testele pentru LED control (ATmega16 mock)...\n");
    // Test 1: Inițializarea stinge LED-ul
    led_init(0);
    assert(led_get_state() == LED_OFF);
    // Test 2: Aprinderea LED-ului
    led_set_state(0, LED_ON);
    assert(led_get_state() == LED_ON);
    // Test 3: Stingerea LED-ului
    led_set_state(0, LED_OFF);
    assert(led_get_state() == LED_OFF);
    printf("Toate testele au trecut cu succes!\n");
}
int main(void) {
    run_tests();
    return 0;
}
