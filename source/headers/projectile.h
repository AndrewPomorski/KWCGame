#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "sprite.h"
#include "globals.h"
#include "graphics.h"
#include "SDL.h"


class Projectile : public Sprite {
public:
	Projectile();
	Projectile(SDL_Texture texture, float xVelocity, float yVelocity);
	~Projectile();
	void shootProjectile(Vector2 direction);
	SDL_Texture getBulletTex();
private:
	float _xVelocity;
	float _yVelocity;
	Vector2 _direction;
	SDL_Texture _projectileTex;	
};


#endif
