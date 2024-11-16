#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "pico/stdlib.h"
#define TRIGGER_PIN     25  // (GPIO 2)
#define ECHO_PIN   15  // (GPIO 3)

// Initialize the ultrasonic sensor
void ultrasonic_init(void);

// Get distance in centimeters
float ultrasonic_get_distance_cm(void);

#endif // ULTRASONIC_H
