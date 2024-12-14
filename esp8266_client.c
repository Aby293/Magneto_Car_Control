#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "pico/cyw43_arch.h"

// Replace with your server IP address and port
#define SERVER_IP "192.168.4.1"
#define SERVER_PORT 80

void connect_to_server() {
    struct sockaddr_in server_addr;
    int sockfd;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error\n");
        return;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported\n");
        return;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection Failed\n");
        return;
    }

    printf("Connected to server\n");

    // Send data
    char *message = "GET /toggleLED HTTP/1.1\r\n\r\n";
    send(sockfd, message, strlen(message), 0);

    // Close socket
    close(sockfd);
}

int main() {
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("WiFi init failed");
        return -1;
    }

    connect_to_server();
    return 0;
}
