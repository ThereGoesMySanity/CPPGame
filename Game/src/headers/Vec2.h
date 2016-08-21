/*
 * Vec2.h
 *
 *  Created on: Aug 21, 2016
 *      Author: will
 */

#ifndef VEC2_H
#define VEC2_H

class Vec2{
public:
	Vec2(float x, float y);
	Vec2(Vec2 &v);
	float getX();
	float getY();
	Vec2 operator+(const Vec2 &v);
	Vec2 operator-(const Vec2 &v);
	Vec2 operator*(const Vec2 &v);
	Vec2 operator/(const Vec2 &v);
	Vec2 operator==(const Vec2 &v);
	void operator+=(const Vec2 &v);
private:
	float _x, _y;
};



#endif /* SRC_SRC_VEC2_H_ */
