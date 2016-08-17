/*
 * Graphics.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */


#include "graphics.h"
#include <SDL2/SDL.h>

Graphics::Graphics(){
	SDL_CreateWindowAndRenderer(800,600, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Game thing");
}

Graphics::~Graphics(){
	SDL_DestroyWindow(this->_window);
}
