cmake_minimum_required(VERSION 4.0)
project(merlin_shell C)

set(CMAKE_C_STANDARD 11)

add_executable(merlin_shell src/main.c
        src/builtin_functions.c
        src/headers/builtin_functions.h
        src/input.c
        src/headers/input.h
        src/execution.c
        src/headers/execution.h)
