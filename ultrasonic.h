#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "pico/stdlib.h"
#define TRIGGER_PIN 19 
#define RIGHT_ECHO_PIN 20
#define LEFT_ECHO_PIN 21
#define FRONT_ECHO_PIN 5
#define BACK_ECHO_PIN 7


// Initialize the ultrasonic sensor
void ultrasonic_init(void);

float ultrasonic_get_distance_cm(int echo_pin);

// Get distance in centimeters
float get_ultrasonic_distance_right(void);
float get_ultrasonic_distance_left(void);
float get_ultrasonic_distance_front(void);
float get_ultrasonic_distance_back(void);

#endif // ULTRASONIC_H
