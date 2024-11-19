#include "ultrasonic.h"
#include "pico/stdlib.h"
#include "stdio.h"

// Static variables to store pin numbers

void ultrasonic_init() {
    // Configure the trigger pin as output
    gpio_init(TRIGGER_PIN);
    gpio_set_dir(TRIGGER_PIN, GPIO_OUT);
    gpio_put(TRIGGER_PIN, 0); // Ensure the trigger pin starts LOW

    // Configure the echo pin as input
    gpio_init(RIGHT_ECHO_PIN);
    gpio_set_dir(RIGHT_ECHO_PIN, GPIO_IN);

    gpio_init(LEFT_ECHO_PIN);
    gpio_set_dir(LEFT_ECHO_PIN, GPIO_IN);

    gpio_init(FRONT_ECHO_PIN);
    gpio_set_dir(FRONT_ECHO_PIN, GPIO_IN);

    gpio_init(BACK_ECHO_PIN);
    gpio_set_dir(BACK_ECHO_PIN, GPIO_IN);
}

float ultrasonic_get_distance_cm(int echo_pin) {
    // Trigger the ultrasonic sensor
    printf("Triggering the ultrasonic sensor\n");
    gpio_put(TRIGGER_PIN, 1);
    sleep_us(10); // Send a 10 μs HIGH pulse
    gpio_put(TRIGGER_PIN, 0);

    // Measure the echo pulse duration
    absolute_time_t start_time = get_absolute_time();
    while (gpio_get(echo_pin) == 0) {
        start_time = get_absolute_time(); // Wait for the echo pin to go HIGH
    }

    absolute_time_t end_time = get_absolute_time();
    while (gpio_get(echo_pin) == 1) {
        end_time = get_absolute_time(); // Wait for the echo pin to go LOW
    }

    // Calculate the time difference in microseconds
    int64_t pulse_duration = absolute_time_diff_us(start_time, end_time);

    // Calculate the distance in cm (speed of sound = 343 m/s or 0.0343 cm/μs)
    float distance = (pulse_duration * 0.0343) / 2;

    return distance; // Distance in centimeters
}

float get_ultrasonic_distance_right(void) {
    return ultrasonic_get_distance_cm(RIGHT_ECHO_PIN);
}

float get_ultrasonic_distance_left(void) {
    return ultrasonic_get_distance_cm(LEFT_ECHO_PIN);
}

float get_ultrasonic_distance_front(void) {
    return ultrasonic_get_distance_cm(FRONT_ECHO_PIN);
}

float get_ultrasonic_distance_back(void) {
    return ultrasonic_get_distance_cm(BACK_ECHO_PIN);
}

