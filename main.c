#include "lwip/apps/httpd.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "lwipopts.h"
#include "ssi.h"
#include "cgi.h"

// WIFI Credentials - take care if pushing to github!
const char WIFI_SSID[] = "Abdelrahman's Galaxy A72";
const char WIFI_PASSWORD[] = "bdnh2203";

void print_ip_address() { const ip4_addr_t *ip = &cyw43_state.netif[CYW43_ITF_STA].ip_addr; printf("IP Address: %s\n", ip4addr_ntoa(ip));}

int main() { 
    stdio_init_all();

    cyw43_arch_init();

    initCar();

    cyw43_arch_enable_sta_mode();

    // Connect to the WiFI network - loop until connected
    while(cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 10000) != 0){
        printf("Attempting to connect...\n");
    }
    // Print a success message once connected
    printf("Connected! \n");
    
    // Initialise web server
    httpd_init();
    printf("Http server initialised\n");

    print_ip_address();
    

    // Configure SSI and CGI handler
    ssi_init(); 
    printf("SSI Handler initialised\n");
    cgi_init();
    printf("CGI Handler initialised\n");
    
    // Infinite loop
    while(1);
}