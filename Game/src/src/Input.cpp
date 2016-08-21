/*
 * Input.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */

#include "Input.h"
#include <iostream>


void Input::nextFrame(){
	_pressedKeys.clear();
	_releasedKeys.clear();
}

void Input::onKeyDown(const SDL_Event &event){
	_heldKeys[event.key.keysym.scancode] = true;
	_pressedKeys[event.key.keysym.scancode] = true;
}

void Input::onKeyUp(const SDL_Event &event){
	_heldKeys[event.key.keysym.scancode] = false;
	_releasedKeys[event.key.keysym.scancode] = true;
}

void Input::onMouseMove(const SDL_Event &event){
	_mousePos = {event.motion.x,event.motion.y};
}

std::vector<int> Input::getMousePos(){
	return _mousePos;
}
int Input::getX(){
	return _mousePos[0];
}
int Input::getY(){
	return _mousePos[1];
}

bool Input::getKeyDown(SDL_Scancode key){
	return _pressedKeys[key];
}
bool Input::getKeyUp(SDL_Scancode key){
	return _releasedKeys[key];
}
bool Input::getKeyHeld(SDL_Scancode key){
	return _heldKeys[key];
}
