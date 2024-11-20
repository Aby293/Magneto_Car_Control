#ifndef DC_MOTOR_H
#define DC_MOTOR_H


// Motor pins (customize these as per your setup)
#define LEFT_MOTORS_IN1 26
#define LEFT_MOTORS_IN2 27
#define LEFT_MOTORS_PWM 28

#define RIGHT_MOTORS_IN1 29
#define RIGHT_MOTORS_IN2 12
#define RIGHT_MOTORS_PWM 13

// Function prototypes
void initMotors();                             // Initialize all motors
void moveMotor(int motor, int forward, int speed); // Move a motor (1-4) forward/backward at speed (0-255)
void stopMotor(int motor);                     // Stop a specific motor (1-4)
void stopAllMotors();                          // Stop all motors
void setupPWM(int gpio);

#endif // DC_MOTOR_H
