#include "ultrasonic.h"

// Static variables to store pin numbers
static uint trigger_pin;
static uint echo_pin;

void ultrasonic_init(uint trig_pin, uint ech_pin) {
    trigger_pin = trig_pin;
    echo_pin = ech_pin;

    // Configure the trigger pin as output
    gpio_init(trigger_pin);
    gpio_set_dir(trigger_pin, GPIO_OUT);
    gpio_put(trigger_pin, 0); // Ensure the trigger pin starts LOW

    // Configure the echo pin as input
    gpio_init(echo_pin);
    gpio_set_dir(echo_pin, GPIO_IN);
}

float ultrasonic_get_distance_cm(void) {
    // Trigger the ultrasonic sensor
    gpio_put(trigger_pin, 1);
    sleep_us(10); // Send a 10 μs HIGH pulse
    gpio_put(trigger_pin, 0);

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
