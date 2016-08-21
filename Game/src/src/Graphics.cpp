/*
 * Graphics.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */


#include "Graphics.h"
#include <SDL2/SDL.h>
#ifdef __MACH__
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif
Graphics::Graphics(){
	SDL_CreateWindowAndRenderer(800,600, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Game thing");
}

Graphics::~Graphics(){
	SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath){
	if(_sprites.count(filePath) == 0){
		_sprites[filePath] = IMG_Load(filePath.c_str());
	}
	return _sprites[filePath];
}

void Graphics::blitSurface(SDL_Texture* img, SDL_Rect* src, SDL_Rect* dest){
	SDL_RenderCopy(_renderer, img, src, dest);
}
void Graphics::flip(){
	SDL_RenderPresent(_renderer);
}
void Graphics::clear(){
	SDL_RenderClear(_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
	return _renderer;
}
