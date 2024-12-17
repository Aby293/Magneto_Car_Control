// // #include "led.h"
// #include "pico/stdlib.h"
// #include "buzzer.h"
// #include "ultrasonic.h"
// #include "led_control.h"
// #include "mpu6050.h"
// #include "car_control.h"
// #include "stdio.h"


// int main()
// {
//     stdio_init_all();
//     // initBuzzer();
//     // Initialize MPU6050
//     mpu6050_init();

//     int16_t raw_accel[3], raw_gyro[3], raw_temp;
//     float accel[3], gyro[3];
    
//     // initCar();

//     // // initLEDs();
//     // ultrasonic_init();
//     //     buzzerOn();
//     //     sleep_ms(5000);
//     //     buzzerOff();
//     while (1){
//         printf("Hello, Pico!\n");
      
//         // // sleep_ms(3000);
//             // printf("reading distance\n");
//             // printf("Right: %.2f cm\n", get_ultrasonic_distance_right());
//             // printf("Left: %.2f cm\n", get_ultrasonic_distance_left());
//             // printf("Front: %.2f cm\n", get_ultrasonic_distance_front());
//             // printf("Back: %.2f cm\n", get_ultrasonic_distance_back());


//         // Read raw data from MPU6050
//         mpu6050_read_raw(raw_accel, raw_gyro, &raw_temp);

//         // Convert raw data to meaningful values
//         convert_raw_data(raw_accel, raw_gyro, accel, gyro);

//         // Print data to console
//         printf("Gyro (°/s): X=%.2f, Y=%.2f, Z=%.2f\n", accel[0], accel[1], accel[2]);
//         // printf("Acc (g): X=%.2f, Y=%.2f, Z=%.2f\n", gyro[0], gyro[1], gyro[2]);
//         // printf("Temp (°C): %.2f\n", raw_temp / 340.0 + 36.53);

//         if(accel[0]>50){
//             printf("Car moves backward\n");
//         }

//         if(accel[0]<-50){
//             printf("Car moves forward\n");
//         }

//         if(accel[1]>50){
//             printf("Car moves right\n");
//         }

//         if(accel[1]<-50){
//             printf("Car moves left\n");
//         }
//         // moveForward(125);
//         // sleep_ms(5000);
//         // stopCar();
//         // sleep_ms(3000);
//         // moveBackward(125);
//         // sleep_ms(5000);
//         // moveForward(225);
//         // sleep_ms(5000);
//         // moveBackward(225);
//         // sleep_ms(5000);
//         // turnRight(225);
//         // sleep_ms(5000);
//         // turnLeft(225);
//         // sleep_ms(5000);

//         sleep_ms(3000);
//     }
//     return 0;
// }

//WORKING WIFI CODE

#include "lwip/apps/httpd.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "lwipopts.h"
#include "ssi.h"
#include "cgi.h"
#include "car_control.h"

// WIFI Credentials - take care if pushing to github!
const char WIFI_SSID[] = "Abdelrahman's Galaxy A72";
const char WIFI_PASSWORD[] = "bdnh2203";

int main() {
    stdio_init_all();

    cyw43_arch_init();

    initCar(); 

    cyw43_arch_enable_sta_mode();

    // Connect to the WiFI network - loop until connected
    while(cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 10000) != 0){
        printf("Attempting to connect...\n");
    }
    // Print a success message once connected
    printf("Connected! \n");
    
    // Initialise web server
    httpd_init();
    printf("Http server initialised\n");

    // Configure SSI and CGI handler
    ssi_init(); 
    printf("SSI Handler initialised\n");
    cgi_init();
    printf("CGI Handler initialised\n");
    
    // Infinite loop
    while(1);
}