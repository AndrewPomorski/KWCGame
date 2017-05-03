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
	 *	Moves player left by - dx
	 */
	void moveLeft();
	
	/*
	 *	Moves player right by dx.
	 */
	void moveRight();
	
	/*
	 * Subtract from y axis
	 */
	void moveUp();
	
	/*
	 * Add to y axis
	 */
	void moveDown();
	/*
	 *Stops moving the player and plays "idle" animation 
	 * */
	void stopMoving();

	void moveToLocation(float xDest, float yDest);
	
	int getCurrentHealth();
	
	void setMaxHealth(int amount);

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();

	float getPosX();
	float getPosY();
private:
	float _dx, _dy;	
	
	int _currentHealth;
	int _maxHealth;

	Direction _facing;
};

#endif
