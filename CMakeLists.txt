cmake_minimum_required(VERSION 3.30)
project(bicycle C)

set(CMAKE_C_STANDARD 23)

add_executable(bicycle main.c
        card.h
        deck.c
        deck.h
        card.c)
