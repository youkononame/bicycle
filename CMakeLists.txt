cmake_minimum_required(VERSION 3.28.3)
project(bicycle C)

set(CMAKE_C_STANDARD 23)

add_executable(bicycle src/main.c
        src/core/card.h
        src/core/deck.c
        src/core/deck.h
        src/core/card.c
        src/games/baccarat.c
        src/games/baccarat.h)
