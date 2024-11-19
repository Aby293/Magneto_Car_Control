#include "led.h"
#include "pico/stdlib.h"
#include "stdio.h"
#include "buzzer.h"
#include "ultrasonic.h"
#include "led_control.h"
#include "mpu6050.h"

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
    
    while (1)
    {
        printf("Hello, Pico!\n");
        // buzzerOn();
        // sleep_ms(3000);
        // buzzerOff();
        // sleep_ms(3000);

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
        // sleep_ms(3000);

        // printf("starting loop\n");
        // for(int i = 0; i < 20; i++) {
        //     printf("reading distance\n");
        //     printf("Right: %.2f cm\n", get_ultrasonic_distance_right());
        //     printf("Left: %.2f cm\n", get_ultrasonic_distance_left());
        //     printf("Front: %.2f cm\n", get_ultrasonic_distance_front());
        //     printf("Back: %.2f cm\n", get_ultrasonic_distance_back());
        //     sleep_ms(3000);
        // }
        // printf("ending loop\n");


        // Read raw data from MPU6050
        mpu6050_read_raw(raw_accel, raw_gyro, &raw_temp);

        // Convert raw data to meaningful values
        convert_raw_data(raw_accel, raw_gyro, accel, gyro);

        // Print data to console
        printf("Accel (g): X=%.2f, Y=%.2f, Z=%.2f\n", accel[0], accel[1], accel[2]);
        printf("Gyro (°/s): X=%.2f, Y=%.2f, Z=%.2f\n", gyro[0], gyro[1], gyro[2]);
        printf("Temp (°C): %.2f\n", raw_temp / 340.0 + 36.53);

        sleep_ms(3000);
    }
    return 0;
}