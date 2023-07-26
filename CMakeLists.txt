cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(tilt C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(tilt
	main.c
)

pico_enable_stdio_usb(tilt 1)
pico_enable_stdio_uart(tilt 1)

pico_add_extra_outputs(tilt)

target_link_libraries(tilt pico_stdlib)
