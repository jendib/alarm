cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake)
project(alarm C CXX)

generate_arduino_firmware(${PROJECT_NAME}
        PORT COM4
        SRCS src/main.cpp src/alarm.cpp src/pir.cpp src/battery.cpp src/Sim800l.cpp
        HDRS src/alarm.h src/pir.h src/battery.h src/Sim800l.h
        BOARD uno)
