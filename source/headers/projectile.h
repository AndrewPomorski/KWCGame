#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "globals.h"

class Projectile {
public:
	Projectile();
	Projectile(Vector2 position, Vector2 speed);
	~Projectile();
	void shoot(float elapsedTime);
	Vector2 getPosition();
	vector2 getSpeed();
	/*
	 *This might not be needed after all.
	 */
	void setSpeed(Vector2 speed);
private:
	Vector2 _position;
	Vector2 _speed;
	Vector2 _direction;
	SDL_Texture _bulletSprite;
};


#endif
