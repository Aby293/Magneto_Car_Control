#ifndef CAR_CONTROL_H
#define CAR_CONTROL_H

#include "dc_motor.h"
#include "led_control.h"

// Function prototypes
void initCar();
void moveForward(int speed);    // Move the car forward at speed (0-255)
void moveBackward(int speed);   // Move the car backward at speed (0-255)
void turnRight(int speed);      // Turn the car right at speed (0-255)
void turnLeft(int speed);       // Turn the car left at speed (0-255)
void stopCar();                 // Stop the car

#endif // CAR_CONTROL_H
