#ifndef PLAYER_H
#define PLAYER_H

#include "animatedsprite.h"
#include "globals.h"

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	/*
	 *Moves player left by - dx
	 * */	
	void moveLeft();
	
	/*
	 *Moves player right by dx. 
	 * */
	void moveRight();

	/*
	 *Stops moving the player and plays "idle" animation 
	 * */
	void stopMoving();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();
private:
	float _dx, _dy;	

	Direction facing;
};

#endif
