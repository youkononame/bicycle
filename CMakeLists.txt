cmake_minimum_required(VERSION 3.28.3)
project(bicycle C)

set(CMAKE_C_STANDARD 23)

add_executable(bicycle src/main.c
        src/card.h
        src/deck.c
        src/deck.h
        src/card.c)