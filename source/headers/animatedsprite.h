#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

class Graphics;

/*
*Holds logic for animating sprites.
*/
class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, 
		float posX, float posY, float timeToUpdate);

	/*
	* plays once or in a loop. Unless it's already playing.
	*/
	void playAnimation( std::string animation, bool once = false );
	
	/*
	* Updates animated sprite with a timer.
	*/
	void update(int elapsedTime);
	/*
	* Draws sprite to the screen.
	*/
	void draw(Graphics &graphics, int x, int y);

	/*
	* A required function that sets up all animations for a sprite.
	*/
	virtual void setupAnimations();

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;
	
	/*
	*  Adds an animation to the map of animations for the sprite.
	*/
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	/*
	* Clears out animation map.
	*/
	void resetAnimations();

	/*
	* Halts current animation.
	*/
	void stopAnimation();

	/*
	* Changes visibility of the animated sprite.
	*/
	void setVisible(bool visible);


	/*
	* Logic that happens when the animation ends.
	*/
	virtual void animationDone(std::string currentAnimation);

private:
	/*
	* Vector of frame rectangles.
	*/
	std::map< std::string, std::vector<SDL_Rect> > _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	int _timeElapsed;
	bool _visible;
};


#endif