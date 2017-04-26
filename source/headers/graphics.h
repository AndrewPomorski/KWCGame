#ifndef GRAPHICS_H
#define GRAPHICS_H
/*
*Graphics class. 
*Holds all information dealing with graphics in the game.
*/
#include "SDL.h"
#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();
	
	/*SDL_Surface* loadImage
	* Loads an image into the _spriteSheets map if it doesn't exist.
	* So each image only gets loaded once.
	* Returns image from the map.
	*/
	SDL_Surface* loadImage(const std::string &filePath);
	
	/*
	*Draws a texture to a certain part of the screen.
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/*
	*Renders everything to the screen.
	*/
	void flip();

	/*
	* Clears the screen.
	*/
	void clear();

	/*
	*Returns the renderer to be used in a Sprite class.
	*/
	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* 	_window;
	SDL_Renderer* 	_renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
	
};


#endif
