/*
 * Input.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */

#include "Input.h"
#include <iostream>

Input::Input(Game *g) : _mouseDown(false){
	_g = g;
}
void Input::nextFrame(){
	_pressedKeys.clear();
	_releasedKeys.clear();
}

void Input::onKeyDown(const SDL_Event &event){
	_heldKeys[event.key.keysym.scancode] = true;
	_pressedKeys[event.key.keysym.scancode] = true;
	switch(event.key.keysym.scancode){
	case SDL_SCANCODE_BACKSPACE:
	case SDL_SCANCODE_RETURN:
		_g->getWindow(0)->onSpecialKey(event.key.keysym.scancode);
		break;
	default:
		break;
	}
}

void Input::onKeyUp(const SDL_Event &event){
	_heldKeys[event.key.keysym.scancode] = false;
	_releasedKeys[event.key.keysym.scancode] = true;
}
void Input::onTextInput(const SDL_Event &event){
	_g->getWindow(0)->onInput(event.text.text);
}
void Input::onMouse(bool b){
    if(b){
        int z = _g->getWindowAtLocation(_mousePos[0], _mousePos[1]);
        if(z){
            if(z==_g->_windows.size()){
                _g->_dock->onMouse(true, _mousePos[0], _mousePos[1]);
                return;
            }
            _g->focusWindow(z);
        }
    }
    Window* w = _g->getWindow(0);
    if(w)w->onMouse(b, _mousePos[0], _mousePos[1]);
}
bool Input::getMouse(){
	return _mouseDown;
}

void Input::onMouseMove(const SDL_Event &event){
	_mousePos = {event.motion.x,event.motion.y};
    Window* w = _g->getWindow(0);
    if(w)w->onMouseMotion(event.motion);

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
