#include "graphics.h"
#include <SDL.h>

/*
* Graphics class implementation.
* Holds all information dealing with game graphics.
*/

Graphics::Graphics(){
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Hong");
}

Graphics::~Graphics(){
	SDL_DestroyWindow(this->_window);
}
