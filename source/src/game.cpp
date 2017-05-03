#include "SDL.h"
#include "game.h"
#include "graphics.h"
#include "input.h"
/*
* Holds all the information about the main game loop.
*/

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 1000 / FPS;
}



Game::Game(){
	SDL_Init( SDL_INIT_EVERYTHING );
	this->gameLoop();

}

Game::~Game(){	
}

void Game::gameLoop(){

	Camera camera;
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->_player = Player(graphics, 100, 100);
	this->_level = Level("overworld", Vector2(100, 100), graphics);

	int LAST_UPDATE_TIME = SDL_GetTicks();

	//Start the game loop
	while ( true ){
		input.beginNewFrame();
		if ( SDL_PollEvent( &event ) ){
			if ( event.type == SDL_KEYDOWN ){
				if( event.key.repeat == 0 ){
					input.keyDownEvent( event );
				} 
			}
			else if ( event.type == SDL_KEYUP ){
				input.keyUpEvent( event );
			}
			else if ( event.type == SDL_QUIT ){
				return;
			} 
		}
		if ( input.wasKeyPressed( SDL_SCANCODE_ESCAPE ) ){
			return;
		}
		else if (input.wasKeyPressed(SDL_SCANCODE_R)){
			this->_player.moveToLocation(100, 100);
		}
		else if (input.wasKeyPressed(SDL_SCANCODE_F)){
			graphics.toggleFullScreen();
		}
		else if ( input.isKeyHeld(SDL_SCANCODE_A) ){
			this->_player.moveLeft();
		}
		else if ( input.isKeyHeld(SDL_SCANCODE_D) ){
			this->_player.moveRight();
		}
		else if ( input.isKeyHeld(SDL_SCANCODE_S) ){
			this->_player.moveDown();
		}
		else if ( input.isKeyHeld(SDL_SCANCODE_W) ){
			this->_player.moveUp();
		}
		
		if(!input.isKeyHeld(SDL_SCANCODE_A) && !input.isKeyHeld(SDL_SCANCODE_D) && !input.isKeyHeld(SDL_SCANCODE_S) && !input.isKeyHeld(SDL_SCANCODE_W)){
			this->_player.stopMoving();
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS  - LAST_UPDATE_TIME;

		this->update(std::min( ELAPSED_TIME_MS, MAX_FRAME_TIME ));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw( graphics );
	}
}

void Game::draw( Graphics &graphics ){
	graphics.clear();

	this->_level.draw(graphics);
	this->_player.draw(graphics);

	graphics.flip();
}

void Game::update( float elapsedTime ){
	this->_camera.update(elapsedTime, this->_player);
	this->_player.update(elapsedTime);
	this->_level.update(elapsedTime);	
}


