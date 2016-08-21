/*
 * Vec2.cpp
 *
 *  Created on: Aug 21, 2016
 *      Author: will
 */

#include "Vec2.h"
Vec2::Vec2(float x, float y) : _x(x), _y(y){}
Vec2::Vec2(Vec2 &v) : _x(v._x), _y(v._y){}
Vec2::~Vec2(){}
float Vec2::getX(){
	return _x;
}
float Vec2::getY(){
	return _y;
}
Vec2* Vec2::operator+(const Vec2 &v){
	return new Vec2(_x+v._x, _y+v._y);
}
Vec2* Vec2::operator-(const Vec2 &v){
	return new Vec2(_x-v._x, _y-v._y);
}
bool Vec2::operator==(const Vec2 &v){
	return v._x==_x&&v._y==_y;
}
void Vec2::operator+=(const Vec2 &v){
	_x+=v._x;
	_y+=v._y;
}


