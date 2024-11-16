#include "car_control.h"

// Move the car forward
void moveForward(int speed) {
    moveMotor(1, true, speed); // Motor A forward
    moveMotor(2, true, speed); // Motor B forward
    moveMotor(3, true, speed); // Motor C forward
    moveMotor(4, true, speed); // Motor D forward
}

// Move the car backward
void moveBackward(int speed) {
    moveMotor(1, false, speed); // Motor A backward
    moveMotor(2, false, speed); // Motor B backward
    moveMotor(3, false, speed); // Motor C backward
    moveMotor(4, false, speed); // Motor D backward
}

// Turn the car right
void turnRight(int speed) {
    moveMotor(1, true, speed);  // Motor A forward
    moveMotor(2, false, speed); // Motor B backward
    moveMotor(3, true, speed);  // Motor C forward
    moveMotor(4, false, speed); // Motor D backward
}

// Turn the car left
void turnLeft(int speed) {
    moveMotor(1, false, speed); // Motor A backward
    moveMotor(2, true, speed);  // Motor B forward
    moveMotor(3, false, speed); // Motor C backward
    moveMotor(4, true, speed);  // Motor D forward
}

// Stop the car
void stopCar() {
    stopAllMotors();
}
