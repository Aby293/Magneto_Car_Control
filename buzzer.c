#include "buzzer.h"
#include "pico/stdlib.h"

// Initialize the buzzer pin as an output
void initBuzzer(void) {
    gpio_init(BUZZER_PIN);       // Initialize GPIO
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Set as output
    gpio_put(BUZZER_PIN, 0);
}

// Turn the buzzer ON by setting the pin HIGH
void buzzerOn(void) {
    gpio_put(BUZZER_PIN, 1); // Set GPIO HIGH
}

// Turn the buzzer OFF by setting the pin LOW
void buzzerOff(void) {
    gpio_put(BUZZER_PIN, 0); // Set GPIO LOW
}