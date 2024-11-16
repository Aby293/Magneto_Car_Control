#ifndef LED_H
#define LED_H

#define LED1_PIN 2
#define LED2_PIN 3
#define LED3_PIN 4
#define LED4_PIN 5

void initLEDs();                     
void turnOnLED(int ledNumber);        
void turnOffLED(int ledNumber);       
void toggleLED(int ledNumber);        
void turnOffAllLEDs();               
void turnOnAllLEDs();                 

#endif 
