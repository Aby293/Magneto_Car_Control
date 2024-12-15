# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(MS_01_Team_15_Code C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

execute_process(
    COMMAND py makefsdata.py
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
)

# Add executable. Default name is the project name, version 0.1
add_executable(MS_01_Team_15_Code main.c led.c buzzer.c ultrasonic.c led_control.c mpu6050.c dc_motor.c car_control.c)

pico_set_program_name(MS_01_Team_15_Code "MS_01_Team_15_Code")
pico_set_program_version(MS_01_Team_15_Code "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(MS_01_Team_15_Code 0)
pico_enable_stdio_usb(MS_01_Team_15_Code 1)

# Add the standard library to the build
target_link_libraries(MS_01_Team_15_Code
        pico_stdlib
        hardware_i2c
        hardware_pwm
        hardware_adc
        hardware_uart
        pico_cyw43_arch_lwip_threadsafe_background
        pico_lwip_http)

# Add the standard include files to the build
target_include_directories(MS_01_Team_15_Code PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
  C:/VSARM/sdk/pico/pico-sdk/src/rp2_common/pico_cyw43_arch/include # Add the correct path to pico_cyw43_arch.h
)

pico_add_extra_outputs(MS_01_Team_15_Code)
