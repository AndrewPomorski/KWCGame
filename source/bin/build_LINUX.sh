#!/bin/bash
#Compiler flags: -w -lSDL2 -lSDL2_image  are required to use IMG_Load()
g++  ../src/game.cpp ../src/graphics.cpp ../src/player.cpp ../src/animatedsprite.cpp ../src/sprite.cpp ../src/input.cpp ../src/main.cpp -o game -w -lSDL2 -lSDL2_image -I ../headers/ `pkg-config --cflags --libs sdl2` `sdl-config --libs`
