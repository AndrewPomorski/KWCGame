#include "SDL.h"
#include "SDL/SDL_image.h"

#include "graphics.h"
#include "globals.h"
/*
* Graphics class implementation.
* Holds all information dealing with game graphics.
*/

Graphics::Graphics(){
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Hong");


}

Graphics::~Graphics(){
	SDL_DestroyWindow(this->_window);
}


SDL_Surface* Graphics::loadImage( const std::string &filePath ){
	if ( this->_spriteSheets.count(filePath) == 0 ){
		/*
		* the file from this path hasn't been loaded yet.
		*/
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return _spriteSheets[filePath];
}

void Graphics::blitSurface( SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle ) {
	SDL_RenderCopy( this->_renderer, texture, sourceRectangle, destinationRectangle );
}

void Graphics::flip(){
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear(){
	SDL_RenderClear(this->_renderer);
}


SDL_Renderer* Graphics::getRenderer() const {
	return this->_renderer;
}
