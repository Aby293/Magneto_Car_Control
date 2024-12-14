#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "cyw43_arch.h"

#define WIFI_SSID "ESP_SERVER"
#define WIFI_PASS "12345678"

void start_server() {
    cyw43_arch_enable_ap_mode(WIFI_SSID, WIFI_PASS, CYW43_AUTH_WPA2_AES_PSK);

    while (true) {
        cyw43_arch_poll();
    }
}

int main() {
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("WiFi init failed");
        return -1;
    }

    start_server();
    return 0;
}
