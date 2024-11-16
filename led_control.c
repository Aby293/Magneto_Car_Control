#include "led_control.h"
#include "pico/stdlib.h"

// Array to store LED pin numbers
const int ledPins[] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};
const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

// Initialize all LEDs
void initLEDs() {
    for (int i = 0; i < ledCount; i++) {
        pinMode(ledPins[i], GPIO_OUT);
        digitalWrite(ledPins[i], 0); // Ensure all LEDs start off
    }
}

// Turn on a specific LED
void turnOnLED(int ledNumber) {
    if (ledNumber >= 1 && ledNumber <= ledCount) {
        digitalWrite(ledPins[ledNumber - 1], 1);
    }
}

// Turn off a specific LED
void turnOffLED(int ledNumber) {
    if (ledNumber >= 1 && ledNumber <= ledCount) {
        digitalWrite(ledPins[ledNumber - 1], 0);
    }
}

// Toggle a specific LED
void toggleLED(int ledNumber) {
    if (ledNumber >= 1 && ledNumber <= ledCount) {
        int currentState = digitalRead(ledPins[ledNumber - 1]);
        digitalWrite(ledPins[ledNumber - 1], !currentState);
    }
}

// Turn off all LEDs
void turnOffAllLEDs() {
    for (int i = 0; i < ledCount; i++) {
        digitalWrite(ledPins[i], 0);
    }
}

// Turn on all LEDs
void turnOnAllLEDs() {
    for (int i = 0; i < ledCount; i++) {
        digitalWrite(ledPins[i], 1);
    }
}
