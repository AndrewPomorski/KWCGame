#!/bin/bash
#Compiler flags: -w -lSDL2 -lSDL2_image  are required to use IMG_Load()
g++ -g ../src/game.cpp ../src/tinyxml2.cpp ../src/camera.cpp ../src/tile.cpp ../src/graphics.cpp ../src/player.cpp ../src/level.cpp ../src/animatedsprite.cpp ../src/sprite.cpp ../src/input.cpp ../src/main.cpp -o gameLin -w -lSDL2 -lSDL2_image -I ../headers/ `pkg-config --cflags --libs sdl2` 
