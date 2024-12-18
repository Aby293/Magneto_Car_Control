#include "lwip/apps/httpd.h"
#include "pico/cyw43_arch.h"
#include "car_control.h"
#include "buzzer.h"

// CGI handler which is run when a request for /led.cgi is detected
const char *cgi_led_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    // Check if an request for LED has been made (/led.cgi?led=x)
    if (strcmp(pcParam[0], "led") == 0)
    {
        // Look at the argument to check if LED is to be turned on (x=1) or off (x=0)
        if (strcmp(pcValue[0], "0") == 0)
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        else if (strcmp(pcValue[0], "1") == 0)
            cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    }

    // // Send the index page back to the user
    //  return "/index.shtml";
}

const char *cgi_move_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    // Move our car based on the parameters
    if (strcmp(pcParam[0], "direction") == 0) {
        int speed = 255;
        if (strcmp(pcParam[1], "speed") == 0) {
            speed = atoi(pcValue[1]);
        }
        if (strcmp(pcValue[0], "forward") == 0) {
            moveForward(speed); // Move the car forward at half speed
        } else if (strcmp(pcValue[0], "backward") == 0) {
            moveBackward(speed); // Move the car backward at half speed
        } else if (strcmp(pcValue[0], "left") == 0) {
            turnLeft(speed); // Turn the car left at half speed
        } else if (strcmp(pcValue[0], "right") == 0) {
            turnRight(speed); // Turn the car right at half speed
        } else if (strcmp(pcValue[0], "stop") == 0) {
            stopCar(); // Stop the car
        }
    }
    //  return "/index.shtml";
}

const char *cgi_buzzer_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
    // Check if a request for Buzzer has been made (/buzzer.cgi?action=x)
    if (strcmp(pcParam[0], "action") == 0)
    {
        // Look at the argument to check if Buzzer is to be activated or deactivated
        if (strcmp(pcValue[0], "deactivate") == 0)
            buzzerOff();
        else if (strcmp(pcValue[0], "activate") == 0)
            buzzerOn();
    }

    // Send the index page back to the user
    //  return "/index.shtml";
}

// tCGI Struct
// Fill this with all of the CGI requests and their respective handlers
static const tCGI cgi_handlers[] = {
    {
        // Html request for "/led.cgi" triggers cgi_handler
        "/led.cgi",
        cgi_led_handler,
    },
    {
        // Html request for "/move.cgi" triggers cgi_move_handler
        "/move.cgi",
        cgi_move_handler,
    },
    {
        // Html request for "/buzzer.cgi" triggers cgi_buzzer_handler
        "/buzzer.cgi",
        cgi_buzzer_handler,
    }};

void cgi_init(void)
{
    http_set_cgi_handlers(cgi_handlers, 3);
}