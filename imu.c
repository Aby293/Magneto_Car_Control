#include "imu.h"

bool initIMU() {
    // Initialize I2C
    i2c_init(I2C_PORT, 100 * 1000); // 100 kHz frequency
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    // Verify IMU presence
    uint8_t whoAmI;
    uint8_t reg = WHO_AM_I_REG;
    i2c_write_blocking(I2C_PORT, IMU_ADDR, &reg, 1, true);  // Write register address
    i2c_read_blocking(I2C_PORT, IMU_ADDR, &whoAmI, 1, false); // Read register value

    if (whoAmI != 0x6C) return false; // Check for expected value (LSM6DSOX identifier)

    // Configure accelerometer
    uint8_t accelConfig[] = {0x10, 0x60}; // CTRL1_XL, 416 Hz, 2g
    i2c_write_blocking(I2C_PORT, IMU_ADDR, accelConfig, 2, false);

    // Configure gyroscope
    uint8_t gyroConfig[] = {0x11, 0x60}; // CTRL2_G, 416 Hz, 2000 dps
    i2c_write_blocking(I2C_PORT, IMU_ADDR, gyroConfig, 2, false);

    return true;
}

void readAcceleration(float* ax, float* ay, float* az) {
    uint8_t data[6];
    uint8_t reg = ACCEL_REG | 0x80; // Auto-increment
    i2c_write_blocking(I2C_PORT, IMU_ADDR, &reg, 1, true);
    i2c_read_blocking(I2C_PORT, IMU_ADDR, data, 6, false);

    *ax = (int16_t)(data[0] | (data[1] << 8)) * 0.000061;
    *ay = (int16_t)(data[2] | (data[3] << 8)) * 0.000061;
    *az = (int16_t)(data[4] | (data[5] << 8)) * 0.000061;
}

void readGyroscope(float* gx, float* gy, float* gz) {
    uint8_t data[6];
    uint8_t reg = GYRO_REG | 0x80; // Auto-increment
    i2c_write_blocking(I2C_PORT, IMU_ADDR, &reg, 1, true);
    i2c_read_blocking(I2C_PORT, IMU_ADDR, data, 6, false);

    *gx = (int16_t)(data[0] | (data[1] << 8)) * 0.07;
    *gy = (int16_t)(data[2] | (data[3] << 8)) * 0.07;
    *gz = (int16_t)(data[4] | (data[5] << 8)) * 0.07;
}
