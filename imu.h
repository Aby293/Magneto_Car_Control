#ifndef IMU_H
#define IMU_H

#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "pico/stdlib.h"

// I2C port and pins
#define I2C_PORT i2c0
#define SDA_PIN 12
#define SCL_PIN 13

// IMU Address and Registers
#define IMU_ADDR 0x6A
#define WHO_AM_I_REG 0x0F
#define ACCEL_REG 0x28
#define GYRO_REG 0x22

bool initIMU();
void readAcceleration(float* ax, float* ay, float* az);
void readGyroscope(float* gx, float* gy, float* gz);

#endif
