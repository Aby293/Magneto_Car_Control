#include "car_control.h"
#include "pico/stdlib.h"
#include "stdio.h"
#include <stdbool.h>

void initCar(){
    initMotors();
    initLEDs();
}


// Move the car forward
void moveForward(int speed) {
    leftLightsFlasherOff();
    rightLightsFlasherOff();
    moveMotor(1, 1, speed); // Motor A forward
    moveMotor(2, 1, speed); // Motor B forward
    lightsBackOff();
    lightsFrontOn();
}

// Move the car backward
void moveBackward(int speed) {
    leftLightsFlasherOff();
    rightLightsFlasherOff();
    moveMotor(1, 0, speed); // Motor A backward
    moveMotor(2, 0, speed); // Motor B backward
    lightsFrontOff();
    lightsBackOn();
}

// Turn the car right
void turnRight(int speed) {
    moveMotor(1, 0, speed);  // left motors
    moveMotor(2, 1, speed); // right motors
    leftLightsFlasherOff();
    rightLightsFlasherOff();
    rightLightsFlasherOn();
}

// Turn the car left
void turnLeft(int speed) {
    moveMotor(1, 1, speed); // left motors
    moveMotor(2, 0, speed);  // right motors
    rightLightsFlasherOff();
    leftLightsFlasherOff();
    leftLightsFlasherOn();
}

// Stop the car
void stopCar() {
    stopAllMotors();
    rightLightsFlasherOff();
    leftLightsFlasherOff();
}
