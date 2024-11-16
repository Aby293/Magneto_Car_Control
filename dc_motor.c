#include "dc_motor.h"
#include "pico/stdlib.h"

// Motor pin arrays for easier access
const int motorPins[][3] = {
    {MOTOR_A_IN1, MOTOR_A_IN2, MOTOR_A_PWM}, // Motor A
    {MOTOR_B_IN1, MOTOR_B_IN2, MOTOR_B_PWM}, // Motor B
    {MOTOR_C_IN1, MOTOR_C_IN2, MOTOR_C_PWM}, // Motor C
    {MOTOR_D_IN1, MOTOR_D_IN2, MOTOR_D_PWM}  // Motor D
};

// Initialize all motors
void initMotors() {
    for (int i = 0; i < 4; i++) {
        pinMode(motorPins[i][0], GPIO_OUT); // IN1
        pinMode(motorPins[i][1], GPIO_OUT); // IN2
        pinMode(motorPins[i][2], GPIO_OUT); // PWM
        stopMotor(i + 1);                // Ensure all motors start off
    }
}

// Move a specific motor
void moveMotor(int motor, bool forward, int speed) {
    if (motor < 1 || motor > 4 || speed < 0 || speed > 255) return;

    int in1 = motorPins[motor - 1][0];
    int in2 = motorPins[motor - 1][1];
    int pwm = motorPins[motor - 1][2];

    if (forward) {
        digitalWrite(in1, 1);
        digitalWrite(in2, 0);
    } else {
        digitalWrite(in1, 0);
        digitalWrite(in2, 1);
    }
    analogWrite(pwm, speed);
}

// Stop a specific motor
void stopMotor(int motor) {
    if (motor < 1 || motor > 4) return;

    int in1 = motorPins[motor - 1][0];
    int in2 = motorPins[motor - 1][1];
    int pwm = motorPins[motor - 1][2];

    digitalWrite(in1, 0);
    digitalWrite(in2, 0);
    analogWrite(pwm, 0);
}

// Stop all motors
void stopAllMotors() {
    for (int i = 1; i <= 4; i++) {
        stopMotor(i);
    }
}
