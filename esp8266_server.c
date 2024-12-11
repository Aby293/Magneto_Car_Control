#include "esp8266_server.h"
#include "hardware/uart.h"
#include "pico/stdlib.h"
#include <string.h>
#include "led_control.h"

void send_command(const char *command) {
    uart_puts(uart0, command);
    uart_puts(uart0, "\r\n");
}

void setup_esp8266_server() {
    // Set up UART
    uart_init(uart0, 115200);
    gpio_set_function(0, GPIO_FUNC_UART); // TX
    gpio_set_function(1, GPIO_FUNC_UART); // RX

    // Reset the ESP8266
    send_command("AT+RST");
    sleep_ms(2000);

    // Set ESP8266 as Wi-Fi Access Point
    send_command("AT+CWMODE=2");
    sleep_ms(1000);

    // Configure Access Point
    char cmd[128];
    snprintf(cmd, sizeof(cmd), "AT+CWSAP=\"%s\",\"%s\",5,3", WIFI_SSID, WIFI_PASS);
    send_command(cmd);
    sleep_ms(1000);

    // Custom IP address
    snprintf(cmd, sizeof(cmd), "AT+CIPSTA=\"192.168.4.10\",\"255.255.255.0\",\"192.168.4.1\"");
    send_command(cmd);
    sleep_ms(1000);

    send_command("AT+CIFSR");
    sleep_ms(1000);

    // Start TCP Server
    snprintf(cmd, sizeof(cmd), "AT+CIPSERVER=1,%d", SERVER_PORT);
    send_command(cmd);
    sleep_ms(1000);

    printf("Server ready on %s:%d\n", WIFI_SSID, SERVER_PORT);
}

void process_http_request(const char *request) {
    char response[128];
    char size_str[10];
    
    if (strstr(request, "GET /ON")) {
        turnOnAllLEDs();
        printf("Bulb turned ON\n");

        // Construct a response to the client
        snprintf(response, sizeof(response),
                 "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nBulb turned ON");

        // Send the response size first
        send_command("AT+CIPSEND=0,");  // Prepare to send data
        snprintf(size_str, sizeof(size_str), "%d", strlen(response));
        send_command(size_str);  // Send the size of the response

        // Send the actual response
        send_command(response);  // Send HTTP Response
    } else if (strstr(request, "GET /OFF")) {
        turnOffAllLEDs();
        printf("Bulb turned OFF\n");

        // Construct a response to the client
        snprintf(response, sizeof(response),
                 "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nBulb turned OFF");

        // Send the response size first
        send_command("AT+CIPSEND=0,");
        snprintf(size_str, sizeof(size_str), "%d", strlen(response));
        send_command(size_str);

        // Send the actual response
        send_command(response);
    } else {
        printf("Unknown HTTP Request: %s\n", request);

        // HTTP 404 Not Found response
        snprintf(response, sizeof(response),
                 "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\nPage not found");

        // Send the response size first
        send_command("AT+CIPSEND=0,");
        snprintf(size_str, sizeof(size_str), "%d", strlen(response));
        send_command(size_str);

        // Send the actual response
        send_command(response);
    }
}


void read_server_response() {
    char buffer[516];
    int index = 0;

    // Clear the buffer before reading
    memset(buffer, 0, sizeof(buffer));

    // Read incoming data
    while (uart_is_readable_within_us(uart0, 1000)) {
        buffer[index++] = uart_getc(uart0);
        if (index >= sizeof(buffer) - 1) break; // Prevent overflow
    }
    buffer[index] = '\0';

    printf("Server Response: %s\n", buffer);

    // Parse the HTTP request
    if (strstr(buffer, "GET")) {
        process_http_request(buffer);
    }
}

