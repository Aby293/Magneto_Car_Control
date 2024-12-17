#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "pico/stdlib.h"
#define RIGHT_TRIGGER_PIN 0
#define RIGHT_ECHO_PIN 1
#define LEFT_TRIGGER_PIN 2
#define LEFT_ECHO_PIN 3
#define FRONT_TRIGGER_PIN 4
#define FRONT_ECHO_PIN 5
#define BACK_TRIGGER_PIN 8
#define BACK_ECHO_PIN 9


// Initialize the ultrasonic sensor
void ultrasonic_init(void);

float ultrasonic_get_distance_cm(int echo_pin, int trigger);

// Get distance in centimeters
float get_ultrasonic_distance_right(void);
float get_ultrasonic_distance_left(void);
float get_ultrasonic_distance_front(void);
float get_ultrasonic_distance_back(void);

#endif // ULTRASONIC_H
