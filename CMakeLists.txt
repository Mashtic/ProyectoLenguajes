cmake_minimum_required(VERSION 3.29)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        matriz.h
        verificacion.h
        matriz.c
        verificacion.c)
