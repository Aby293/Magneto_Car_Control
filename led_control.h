#ifndef LED_H
#define LED_H

#define LED1_PIN 15   // Front right
#define LED2_PIN 16   // Front left
#define LED3_PIN 17   // Back right
#define LED4_PIN 18   // Back left

void initLEDs();                     
void turnOnLED(int ledNumber);        
void turnOffLED(int ledNumber);       
void toggleLED(int ledNumber);        
void turnOffAllLEDs();               
void turnOnAllLEDs();       
void lightsFrontOn(); 
void lightsFrontOff();
void lightsBackOn();
void lightsBackOff(); 
void turnRightOn(); 
void turnRightOff();
void turnLeftOn();
void turnLeftOff();  
void leftLightsFlasherOn();
void leftLightsFlasherOff();
void rightLightsFlasherOn();
void rightLightsFlasherOff();

#endif 
