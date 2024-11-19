#include "led.h"
#include "pico/stdlib.h"
#include "stdio.h"
#include "buzzer.h"
#include "ultrasonic.h"
#include "led_control.h"
#include "mpu6050.h"
#define LED_PIN 25

int main()
{
    stdio_init_all();

    // Initialize MPU6050
    mpu6050_init();

    int16_t raw_accel[3], raw_gyro[3], raw_temp;
    float accel[3], gyro[3];
    // initBuzzer();
    // initLEDs();
    // ultrasonic_init();
    // if (!initIMU()) {
    //     printf("IMU initialization failed!\n");
    //     while (1){
    //         printf("IMU initialization failed!\n");
    //     }
    // }
    // printf("IMU initialized successfully.\n");
    while (1)
    {
        printf("Hello, Pico!\n");
        // buzzerOn();

        // lightsFrontOn();
        // sleep_ms(3000);
        // lightsFrontOff();
        // sleep_ms(3000);
        // lightsBackOn();
        // sleep_ms(3000);
        // lightsBackOff();
        // sleep_ms(3000);
        // turnRightOn();
        // sleep_ms(3000);
        // turnRightOff();
        // sleep_ms(3000);
        // turnLeftOn();
        // sleep_ms(3000);
        // turnLeftOff();

        // float distance = ultrasonic_get_distance_cm();
        // printf("Distance: %.2f cm\n", distance);

        // float ax, ay, az, gx, gy, gz;
        // readAcceleration(&ax, &ay, &az);
        // readGyroscope(&gx, &gy, &gz);

        // printf("Accel (g): X=%.2f, Y=%.2f, Z=%.2f\n", ax, ay, az);
        // printf("Gyro (dps): X=%.2f, Y=%.2f, Z=%.2f\n", gx, gy, gz);
        // sleep_ms(3000);
        // Read raw data from MPU6050
        mpu6050_read_raw(raw_accel, raw_gyro, &raw_temp);

        // Convert raw data to meaningful values
        convert_raw_data(raw_accel, raw_gyro, accel, gyro);

        // Print data to console
        printf("Accel (g): X=%.2f, Y=%.2f, Z=%.2f\n", accel[0], accel[1], accel[2]);
        printf("Gyro (°/s): X=%.2f, Y=%.2f, Z=%.2f\n", gyro[0], gyro[1], gyro[2]);
        printf("Temp (°C): %.2f\n", raw_temp / 340.0 + 36.53);

        sleep_ms(500);
    }
    return 0;
}