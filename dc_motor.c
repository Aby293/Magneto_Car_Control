#include "dc_motor.h"
#include "pico/stdlib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "hardware/pwm.h"

// Motor pin arrays for easier access
const int motorPins[][3] = {
    {LEFT_MOTORS_IN1, LEFT_MOTORS_IN2, LEFT_MOTORS_PWM}, // Motor A
    {RIGHT_MOTORS_IN1, RIGHT_MOTORS_IN2, RIGHT_MOTORS_PWM}, // Motor B
};

// Initialize all motors
void initMotors() {
    for (int i = 0; i < 2; i++) {
        gpio_init(motorPins[i][0]);
        gpio_init(motorPins[i][1]);
        gpio_set_dir(motorPins[i][0], GPIO_OUT); // IN1
        gpio_set_dir(motorPins[i][1], GPIO_OUT); // IN2
        setupPWM(motorPins[i][2]);
    }

    stopAllMotors();
}

// Move a specific motor
void moveMotor(int motor, int forward, int speed) {
    if (motor < 1 || motor > 2 || speed < 0 || speed > 255) return;

    int pwm = motorPins[motor - 1][2];

    if (forward) {
        gpio_put(motorPins[motor - 1][0], 0); //in1
        gpio_put(motorPins[motor - 1][1], 1); //in2
    } else {
        gpio_put(motorPins[motor - 1][0], 1); //in1
        gpio_put(motorPins[motor - 1][1], 0); //in2
    }

    pwm_set_gpio_level(motorPins[motor - 1][2], speed); 
}

// Stop a specific motor
void stopMotor(int motor) {
    if (motor < 1 || motor > 2) return;

    gpio_put(motorPins[motor - 1][0], 0); //in1
    gpio_put(motorPins[motor - 1][1], 0); //in2

    pwm_set_gpio_level(motorPins[motor - 1][2], 0); 
}

// Stop all motors
void stopAllMotors() {
    for (int i = 1; i <= 2; i++) {
        stopMotor(i);
    }
}

void setupPWM(int gpio) {
    gpio_set_function(gpio ,GPIO_FUNC_PWM) ; 
    uint slice = pwm_gpio_to_slice_num(gpio); 
    pwm_set_clkdiv(slice, 4.0f);
    
    pwm_set_wrap(slice , 255); 

    pwm_set_gpio_level(gpio, 0); // Set PWM to 0% duty cycle
    pwm_set_enabled(slice, true);
}
