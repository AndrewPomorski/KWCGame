#include "player.h"
#include "graphics.h"

namespace player_constants {
	const float WALK_SPEED = 0.2f;
}

Player::Player() {}

Player::Player(Graphics &graphics, float x, float y) :
	AnimatedSprite(graphics, "../../assets/sprites/link.png", 0, 0, 16, 16, x, y, 100),
	_dx(0),
	_dy(0),
	_facing(RIGHT)
{
	graphics.loadImage("../../assets/sprites/link.png");
	
	this->setupAnimations();
	this->playAnimation("IdleLeft");
}


void Player::setupAnimations(){
	this->addAnimation(3, 0, 16, "RunLeft", 16, 16, Vector2(0,0));
	this->addAnimation(3, 0, 48, "RunRight", 16, 16, Vector2(0,0));
	this->addAnimation(1, 0, 16, "IdleLeft", 16, 16, Vector2(0,0));
	this->addAnimation(1, 0, 48, "IdleRight", 16, 16, Vector2(0,0));
	this->addAnimation(2, 0, 0,  "RunDown", 16, 16, Vector2(0,0));
	this->addAnimation(1, 0, 0, "IdleDown", 16, 16, Vector2(0,0));
	this->addAnimation(2, 0, 32, "RunUp", 16, 16, Vector2(0,0));
	this->addAnimation(1, 0, 32,  "IdleUp", 16, 16, Vector2(0,0));
}


void Player::animationDone(std::string currentAnimation){}

void Player::moveLeft(){
	this->_dx = -player_constants::WALK_SPEED;
	this->playAnimation("RunLeft");
	this->_facing = LEFT;
}

void Player::moveRight(){
	this->_dx = player_constants::WALK_SPEED;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}

void Player::moveUp(){
	this->_dy = -player_constants::WALK_SPEED;
	this->playAnimation("RunUp");
	this->_facing = UP;
}


void Player::moveDown(){
	this->_dy = player_constants::WALK_SPEED;
	this->playAnimation("RunDown");
	this->_facing = DOWN;
}


void Player::stopMoving(){
	this->_dx = 0.0f;
	this->_dy = 0.0f;
	if (this->_facing == RIGHT){
		this->playAnimation("IdleRight");
	}
	else if(this->_facing == LEFT){
		this->playAnimation("IdleLeft");
	}
	else if(this->_facing == DOWN){
		this->playAnimation("IdleDown");
	}
	else if(this->_facing == UP){
		this->playAnimation("IdleUp");
	}
//	this->playAnimation(this->_facing == RIGHT ? "IdleRight" : "IdleLeft");

}

void Player::update(float elapsedTime){
	// Move by dx
	this->_x += this->_dx  * elapsedTime;
	this->_y += this->_dy  * elapsedTime;
	AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics){
	AnimatedSprite::draw(graphics, this->_x, this->_y);
}

int Player::getCurrentHealth(){
	return this->_currentHealth;
}


void Player::setMaxHealth(int amount){
	this->_maxHealth += amount;
}


void Player::moveToLocation(float xDest, float yDest){
	this->_x = xDest;
	this->_y = yDest;
}

float Player::getPosX(){
	return this->_x;
}

float Player::getPosY(){
	return this->_y;
}
