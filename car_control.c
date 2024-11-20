#include "car_control.h"
#include "pico/stdlib.h"
#include <stdbool.h>


void initCar(){
    initMotors();
}
// Move the car forward
void moveForward(int speed) {
    moveMotor(1, 1, speed); // Motor A forward
    moveMotor(2, 1, speed); // Motor B forward
}

// Move the car backward
void moveBackward(int speed) {
    moveMotor(1, 0, speed); // Motor A backward
    moveMotor(2, 0, speed); // Motor B backward
}

// Turn the car right
void turnRight(int speed) {
    moveMotor(1, 1, speed);  // left motors
    moveMotor(2, 1, 0.5*speed); // right motors
}

// Turn the car left
void turnLeft(int speed) {
    moveMotor(1, 1, 0.5*speed); // left motors
    moveMotor(2, 1, speed);  // right motors
}

// Stop the car
void stopCar() {
    stopAllMotors();
}
