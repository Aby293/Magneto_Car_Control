#include "esp8266_client.h"
#include "hardware/uart.h"
#include "pico/stdlib.h"
#include <string.h>

void send_command(const char *cmd) {
    uart_puts(uart0, cmd);
    uart_puts(uart0, "\r\n");
}

void setup_esp8266_client() {
    // Set up UART
    uart_init(uart0, 9600);
    gpio_set_function(0, GPIO_FUNC_UART); // TX
    gpio_set_function(1, GPIO_FUNC_UART); // RX

    // Reset the ESP8266
    send_command("AT+RST");
    sleep_ms(2000);

    // Set ESP8266 to Wi-Fi Station Mode
    send_command("AT+CWMODE=1");
    sleep_ms(1000);

    // Connect to Wi-Fi
    char cmd[128];
    snprintf(cmd, sizeof(cmd), "AT+CWJAP=\"%s\",\"%s\"", WIFI_SSID, WIFI_PASS);
    send_command(cmd);
    sleep_ms(5000);

    // Connect to Server
    snprintf(cmd, sizeof(cmd), "AT+CIPSTART=\"TCP\",\"%s\",%d", SERVER_IP, SERVER_PORT);
    send_command(cmd);
    sleep_ms(2000);

    printf("Connected to server %s:%d\n", SERVER_IP, SERVER_PORT);
}

void send_data(const char *data) {
    char cmd[128];

    // Debug: Log the data to be sent
    printf("Debug: Data to send: %s\n", data);

    // Format the AT+CIPSEND command
    snprintf(cmd, sizeof(cmd), "AT+CIPSEND=%d", (int)strlen(data));
    
    // Debug: Log the constructed command
    printf("Debug: Command constructed: %s\n", cmd);

    // Send the AT command
    send_command(cmd);

    // Debug: Log after sending the command
    printf("Debug: Command sent: %s\n", cmd);
    
    // Sleep to allow the ESP8266 to process the command
    sleep_ms(500);
    
    // Send the actual data
    uart_puts(uart0, data);

    // Debug: Log the data sent via UART
    printf("Debug: Data sent via UART: %s\n", data);

    // Sleep again to ensure the ESP8266 processes the data
    sleep_ms(500);
}
