#include "led_control.h"
#include "pico/stdlib.h"

// Array to store LED pin numbers
const int ledPins[] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};
const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

// Initialize all LEDs
void initLEDs() {
    for (int i = 0; i < ledCount; i++) {
        gpio_init(ledPins[i]);
        gpio_set_dir(ledPins[i], GPIO_OUT);
        gpio_put(ledPins[i], 0); // Ensure all LEDs start off
    }
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