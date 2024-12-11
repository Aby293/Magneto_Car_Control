#ifndef ESP8266_SERVER_H
#define ESP8266_SERVER_H

#include <stdio.h>

    // Wi-Fi and Server Configuration
    #define WIFI_SSID "ESP_Server"
    #define WIFI_PASS "12345678"
    #define SERVER_PORT 80

// Function Prototypes
void send_command(const char *cmd);
void setup_esp8266_server();
void read_server_response();

#endif // ESP8266_SERVER_H
