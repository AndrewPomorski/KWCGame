#include "projectile.h"

Projectile::Projectile(){}

Projectile::Projectile(SDL_Texture texture, float xVelocity, float yVelocity = 0) :
	_projectileTex(texture),
	_xVelocity(xVelocity),
	_yVelocity(yVelocity)
{}

Projectile::~Projectile(){}


void Projectile::shootProjectile(Vector2 direction){
	horizontalDest = direction.x;
	verticalDest = direction.y;
		
}


SDL_Texture Projectile::getBulletTex(){
	return this->_projectileTex;
};
