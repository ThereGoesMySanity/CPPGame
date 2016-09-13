/*
 * Sprite.cpp
 *
 *  Created on: Aug 18, 2016
 *      Author: Will
 */
/*
#include "Sprite.h"
#include "Graphics.h"

Sprite::Sprite() : _x(0), _y(0){
	_scale = 1;
	_currentSprite = 0;
}

Sprite::Sprite(Graphics &graphics, const std::vector<std::string> &file, int xSource, int ySource,
		int w, int h, float x, float y) : _x(x), _y(y){
	_sourceRect.x = xSource;
	_sourceRect.y = ySource;
	_sourceRect.w=w;
	_sourceRect.h=h;
	for(std::string s : file){
		_sprite.push_back();
	}
	_scale = 1;
	_currentSprite = 0;
}
Sprite::~Sprite(){}
void Sprite::draw(Graphics &graphics, int x, int y) {
	SDL_Rect destinationRectangle = { x, y, static_cast<int>(_sourceRect.w*_scale), static_cast<int>(_sourceRect.h*_scale) };
	graphics.blitSurface(_sprite[_currentSprite], , );
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
*/
