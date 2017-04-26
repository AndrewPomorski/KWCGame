#!/bin/bash
# compiler flags: -w -lSDL2 -lSDL2_image  are required to use IMG_Load()

g++  game.cpp graphics.cpp sprite.cpp input.cpp main.cpp -o game -w -lSDL2 -lSDL2_image -I ../headers/ `pkg-config --cflags --libs sdl2` `sdl-config --libs`

