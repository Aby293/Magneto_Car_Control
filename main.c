#include "led.h"

int main() {
    stdio_init_all();
    
    LED_Init();
    VCC_On();

    while (1) {
        delay_ms(5000);

        LED_On(0);
        delay_ms(1000);
        LED_Off(0);

        LED_On(1);
        delay_ms(1000);
        LED_Off(1);

        LED_On(2);
        delay_ms(1000);
        LED_Off(2);

        LED_All_On();
        delay_ms(2000);
        LED_All_Off();

    }

    return 0;
}
