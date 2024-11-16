#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "pico/stdlib.h"

// Initialize the ultrasonic sensor
void ultrasonic_init(uint trigger_pin, uint echo_pin);

// Get distance in centimeters
float ultrasonic_get_distance_cm(void);

#endif // ULTRASONIC_H
