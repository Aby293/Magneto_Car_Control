#ifndef BUZZER_H
#define BUZZER_H

#include "pico/stdlib.h"
#define BUZZER_PIN 13

// Function prototypes
void initBuzzer(void);
void buzzerOn(void);
void buzzerOff(void);

#endif // BUZZER_H