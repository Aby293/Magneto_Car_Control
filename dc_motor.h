#ifndef DC_MOTOR_H
#define DC_MOTOR_H


// Motor pins (customize these as per your setup)
#define MOTOR_A_IN1 2
#define MOTOR_A_IN2 3
#define MOTOR_A_PWM 4

#define MOTOR_B_IN1 5
#define MOTOR_B_IN2 6
#define MOTOR_B_PWM 7

#define MOTOR_C_IN1 8
#define MOTOR_C_IN2 9
#define MOTOR_C_PWM 10

#define MOTOR_D_IN1 11
#define MOTOR_D_IN2 12
#define MOTOR_D_PWM 13

// Function prototypes
void initMotors();                             // Initialize all motors
void moveMotor(int motor, bool forward, int speed); // Move a motor (1-4) forward/backward at speed (0-255)
void stopMotor(int motor);                     // Stop a specific motor (1-4)
void stopAllMotors();                          // Stop all motors

#endif // DC_MOTOR_H
