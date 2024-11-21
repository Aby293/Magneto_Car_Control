// #include "led.h"
// #include "pico/stdlib.h"

// void LED_Init(void) {

//     gpio_init(RED_PIN);
//     gpio_init(GREEN_PIN);
//     gpio_init(BLUE_PIN);
//     gpio_init(VCC);
    
//     gpio_set_dir(RED_PIN, GPIO_OUT);
//     gpio_set_dir(GREEN_PIN, GPIO_OUT);
//     gpio_set_dir(BLUE_PIN, GPIO_OUT);
//     gpio_set_dir(VCC, GPIO_OUT);

//     LED_All_Off();
// }


// void LED_On(int color) {
//     switch (color) {
//         case 0:
//             gpio_put(RED_PIN, 1);
//             break;
//         case 1: // Green
//             gpio_put(GREEN_PIN, 1);
//             break;
//         case 2: // Blue
//             gpio_put(BLUE_PIN, 0);
//             break;
//     }
// }

// void LED_Off(int color) {
//     switch (color) {
//         case 0: // Red
//             gpio_put(RED_PIN, 0);
//             break;
//         case 1: // Green
//             gpio_put(GREEN_PIN, 0);
//             break;
//         case 2: // Blue
//             gpio_put(BLUE_PIN, 1);
//             break;
//     }
// }

// void LED_All_On(void) {
//     gpio_put(RED_PIN, 1);
//     gpio_put(GREEN_PIN, 1);
//     gpio_put(BLUE_PIN, 0);
// }

// void LED_All_Off(void) {
//     gpio_put(RED_PIN, 0);
//     gpio_put(GREEN_PIN, 0);
//     gpio_put(BLUE_PIN, 1);
// }


// void delay_ms(int ms) {
//     sleep_ms(ms);
// }

// void VCC_On(void){
//     gpio_put(VCC, 1);
// }

// void VCC_Off(void){
//     gpio_put(VCC, 0);
// }
