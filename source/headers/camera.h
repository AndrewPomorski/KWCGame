#ifndef CAMERA_H
#define CAMERA_H

#include "SDL.h"
#include "player.h"


class Camera {
public:
	Camera();
	~Camera();
	void update(float elapsedTime, Player player);
	SDL_Rect getRect();
	SDL_Rect _viewport;
};



#endif
