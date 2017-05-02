#include "projectile.h"


/*
 * Default constructor.
 */
Projectile::Projectile(){};

Projectile::Projectile(Vector2 position, Vector2 speed):
	/*
	 * Position should be initialized at player's current position
	 */
	_position(0,0),
	_speed(globals::VELOCITY, 0),
	_direction(0,0)
{}

Projectile::~Projectile(){}

void Projectile::shoot(float elapsedTime){
	startingPosition = this->_position;
	direction = this->_direction;
	speed = this->_speed;
	/*
	 * Basically spawn bullet sprite at location = this->_position, and move it along the y or x axis (depending on position)
	 * Until it collides with something.
	 * The bullet might disappear if it doesn't hit anything after some time.
	 * */
}

Vector2 Projectile::getPosition(){
	return this->_position;
}

Vector2 Projectile::getSpeed(){
	return this->_speed;
}

void Projectile::setSpeed(Vector2 speed){
	this->_speed = speed;
}



