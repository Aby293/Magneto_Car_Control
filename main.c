#include "led.h"
#include "pico/stdlib.h"
#include "stdio.h"
#include "buzzer.h"
#include "ultrasonic.h"
#include "led_control.h"
#include "imu.h"

int main() { 
    stdio_init_all(); 
    // initBuzzer();
    // initLEDs();
    // ultrasonic_init();
    if (!initIMU()) {
        printf("IMU initialization failed!\n");
        while (1){
            printf("IMU initialization failed!\n");
        }
    }
    printf("IMU initialized successfully.\n");
    while (1) { 
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

        float ax, ay, az, gx, gy, gz;
        readAcceleration(&ax, &ay, &az);
        readGyroscope(&gx, &gy, &gz);

        printf("Accel (g): X=%.2f, Y=%.2f, Z=%.2f\n", ax, ay, az);
        printf("Gyro (dps): X=%.2f, Y=%.2f, Z=%.2f\n", gx, gy, gz);
        sleep_ms(3000);


    } 
    return 0; 
}