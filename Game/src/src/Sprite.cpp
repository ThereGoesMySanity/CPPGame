/*
 * Sprite.cpp
 *
 *  Created on: Aug 18, 2016
 *      Author: Will
 */

#include "Sprite.h"
#include "Graphics.h"

Sprite::Sprite() : pos(0.0f,0.0f){
	_scale = 1;
	_currentSprite = 0;
}

Sprite::Sprite(Graphics &graphics, const std::vector<std::string> &file, int xSource, int ySource,
		int w, int h, float x, float y) : pos(x,y){
	_sourceRect.x = xSource;
	_sourceRect.y = ySource;
	_sourceRect.w=w;
	_sourceRect.h=h;
	for(std::string s : file){
		_sprite.push_back(SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(s)));
	}
	_scale = 1;
	_currentSprite = 0;
}
Sprite::~Sprite(){}
void Sprite::draw(Graphics &graphics, int x, int y) {
	SDL_Rect destinationRectangle = { x, y, _sourceRect.w*_scale, _sourceRect.h*_scale };
	graphics.blitSurface(_sprite[_currentSprite], &_sourceRect, &destinationRectangle);
}
void Sprite::update(){

}
void Sprite::scale(float f){
	_scale = f;
}
void Sprite::next(){
	_currentSprite = (_currentSprite+1)%_sprite.size();
}
void Sprite::sprite(int i){
	if(i<_sprite.size())_currentSprite=i;
}
