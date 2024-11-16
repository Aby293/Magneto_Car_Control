#include "ultrasonic.h"

// Static variables to store pin numbers

void ultrasonic_init() {
    // Configure the trigger pin as output
    gpio_init(TRIGGER_PIN);
    gpio_set_dir(TRIGGER_PIN, GPIO_OUT);
    gpio_put(TRIGGER_PIN, 0); // Ensure the trigger pin starts LOW

    // Configure the echo pin as input
    gpio_init(ECHO_PIN);
    gpio_set_dir(ECHO_PIN, GPIO_IN);
}

float ultrasonic_get_distance_cm(void) {
    // Trigger the ultrasonic sensor
    gpio_put(TRIGGER_PIN, 1);
    sleep_us(10); // Send a 10 μs HIGH pulse
    gpio_put(TRIGGER_PIN, 0);

    // Measure the echo pulse duration
    absolute_time_t start_time = get_absolute_time();
    while (gpio_get(ECHO_PIN) == 0) {
        start_time = get_absolute_time(); // Wait for the echo pin to go HIGH
    }

    absolute_time_t end_time = get_absolute_time();
    while (gpio_get(ECHO_PIN) == 1) {
        end_time = get_absolute_time(); // Wait for the echo pin to go LOW
    }

    // Calculate the time difference in microseconds
    int64_t pulse_duration = absolute_time_diff_us(start_time, end_time);

    // Calculate the distance in cm (speed of sound = 343 m/s or 0.0343 cm/μs)
    float distance = (pulse_duration * 0.0343) / 2;

    return distance; // Distance in centimeters
}
