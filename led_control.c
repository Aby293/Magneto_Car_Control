#include "led_control.h"
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Array to store LED pin numbers
const int ledPins[] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};
const int ledCount = 4;
repeating_timer_t left_timer;
repeating_timer_t right_timer;

// Initialize all LEDs
void initLEDs() {
    for (int i = 0; i < ledCount; i++) {
        gpio_init(ledPins[i]);
        gpio_set_dir(ledPins[i], GPIO_OUT);
        gpio_put(ledPins[i], 0); // Ensure all LEDs start off
    }
}

bool left_light_flashing_callback(repeating_timer_t *rt) {
    toggleLED(2);
    toggleLED(4);
    return true;
}

// Callback function to toggle the right light
bool right_light_flashing_callback(repeating_timer_t *rt) {
    toggleLED(1);
    toggleLED(3);
    return true;
}

// Turn on a specific LED
void turnOnLED(int ledNumber) {
    if (ledNumber >= 1 && ledNumber <= ledCount) {
        gpio_put(ledPins[ledNumber - 1], 1);
    }
}

// Turn off a specific LED
void turnOffLED(int ledNumber) {
    if (ledNumber >= 1 && ledNumber <= ledCount) {
        gpio_put(ledPins[ledNumber - 1], 0);
    }
}

// Toggle a specific LED
void toggleLED(int ledNumber) {
    if (ledNumber >= 1 && ledNumber <= ledCount) {
        int currentState = gpio_get(ledPins[ledNumber - 1]);
        gpio_put(ledPins[ledNumber - 1], !currentState);
    }
}

// Turn off all LEDs
void turnOffAllLEDs() {
    for (int i = 0; i < ledCount; i++) {
        gpio_put(ledPins[i], 0);
    }
}

// Turn on all LEDs
void turnOnAllLEDs() {
    for (int i = 0; i < ledCount; i++) {
        gpio_put(ledPins[i], 1);
    }
}


void lightsFrontOn() {
    turnOnLED(1);
    turnOnLED(2);
}

void lightsFrontOff() {
    turnOffLED(1);
    turnOffLED(2);
}

void lightsBackOn() {
    turnOnLED(3);
    turnOnLED(4);
}

void lightsBackOff() {
    turnOffLED(3);
    turnOffLED(4);
}


void turnRightOn() {
    turnOnLED(1);
    turnOnLED(3);
}

void turnLeftOn() {
    turnOnLED(2);
    turnOnLED(4);
}

void turnRightOff() {
    turnOffLED(1);
    turnOffLED(3);
}

void turnLeftOff() {
    turnOffLED(2);
    turnOffLED(4);
}

void leftLightsFlasherOn() {
    turnOffAllLEDs();
    add_repeating_timer_ms(500, left_light_flashing_callback, NULL, &left_timer); // Flash every 500ms
}

// Method to turn off the left light flasher
void leftLightsFlasherOff() {
    cancel_repeating_timer(&left_timer); // Cancel the timer
    gpio_put(LED2_PIN, false);    // Turn off the left light
    gpio_put(LED4_PIN, false);
}

// Method to turn on the right light flasher
void rightLightsFlasherOn() {
    turnOffAllLEDs();
    add_repeating_timer_ms(500, right_light_flashing_callback, NULL, &right_timer); // Flash every 500ms
}

// Method to turn off the right light flasher
void rightLightsFlasherOff() {
    cancel_repeating_timer(&right_timer); // Cancel the timer
    gpio_put(LED1_PIN, false);    // Turn off the right light
    gpio_put(LED3_PIN, false);
}