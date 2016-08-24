/*
 * Graphics.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */


#include "Graphics.h"
#include <iostream>
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
void Graphics::setFont(const std::string &font, int size){
    if(_fonts.count(font+std::to_string(size))==0){
        TTF_Font* f = TTF_OpenFont(font.c_str(), size);
        if(!f){
            std::cout << TTF_GetError() << std::endl;
        }
        _fonts[font+std::to_string(size)] = f;
    }
    currentFont = font+std::to_string(size);
    fontSize = size;
}
void Graphics::drawText(const std::string &text, int x, int y){
    if(currentFont=="")return;
    if(_fonts[currentFont]==NULL)return;
    SDL_Surface* s = TTF_RenderText_Solid(_fonts[currentFont], text.c_str(), _color);
    SDL_Rect r1{0,0,s->w, s->h};
    SDL_Rect r2{x,y,s->w, s->h};
    blitSurface(SDL_CreateTextureFromSurface(_renderer, s), &r1, &r2);
}
void Graphics::setColor(Uint8 r, Uint8 g, Uint8 b){
    _color = {r,g,b,255};
    SDL_SetRenderDrawColor(_renderer, _color.r, _color.g, _color.b, _color.a);
}
void Graphics::drawLine(int x1, int y1, int x2, int y2){
	SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
    
}
void Graphics::drawRect(int x, int y, int w, int h){
	SDL_Rect r = {x,y,w,h};
	SDL_RenderDrawRect(_renderer, &r);
}
void Graphics::fillRect(int x, int y, int w, int h){
	SDL_Rect r = {x,y,w,h};
	SDL_RenderFillRect(_renderer, &r);
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
