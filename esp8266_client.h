#ifndef ESP8266_CLIENT_H
#define ESP8266_CLIENT_H

#include <stdio.h>

// Wi-Fi and Server Configuration
#define WIFI_SSID "ESP_Server"
#define WIFI_PASS "12345678"
#define SERVER_IP "192.168.4.2"
#define SERVER_PORT 1234

// Function Prototypes
void send_command(const char *cmd);
void setup_esp8266_client();
void send_data(const char *data);

#endif // ESP8266_CLIENT_H
