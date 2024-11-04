cmake_minimum_required(VERSION 3.29)
project(KP_5 C)

set(CMAKE_C_STANDARD 99)

add_executable(KP_5 main.c
        "sort.h"
        validation.h
        "str_generator.h")
