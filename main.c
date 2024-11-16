#include "led.h"
#include "pico/stdlib.h"
#include "stdio.h"
#include "buzzer.h"
#include "ultrasonic.h"
#include "led_control.h"

int main() { 
    stdio_init_all(); 
    initBuzzer();
    // initLEDs();
    ultrasonic_init();
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
        float distance = ultrasonic_get_distance_cm();
        printf("Distance: %.2f cm\n", distance);
        sleep_ms(3000);


    } 
    return 0; 
}