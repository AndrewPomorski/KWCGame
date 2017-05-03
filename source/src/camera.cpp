#include "camera.h"


Camera::Camera(){}

Camera::~Camera(){}

void Camera::update(float elapsedTime, Player player){
	this->_viewport.x = player.getPosX();
	this->_viewport.y = player.getPosY();
}


SDL_Rect Camera::getRect(){
	return this->_viewport;
}
