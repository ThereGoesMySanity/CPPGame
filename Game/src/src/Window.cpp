#include "Window.h"
#include <string>
#include <iostream>

Window::Window(Game *game, const std::string &title, int x, int y, int w, int h)
:_title(title), _g(game),
 _x(x),_y(y),_w(w),_h(h),
 _minimized(false), _moving(false){

}
Window::~Window(){}
void Window::draw(Graphics &g){
	if(!_minimized){
		g.setColor(0, 0, 0);
		g.fillRect(_x, _y, _w, _h);
		g.setColor(0, 255, 0);
		g.drawRect(_x, _y, _w, _h);
		g.drawLine(_x, _y+16, _x+_w-1, _y+16);
		g.drawText(_title.substr(0,globals::WIDTH/8), _x+2, _y);
		g.drawLine(_x+_w-12, _y+8, _x+_w-6, _y+8);
	}
}
void Window::onMouse(bool b, int x, int y){
	if(b&&!_minimized)_minimized=x>=_x+_w-12&&y>=_y+2&&x<_x+_w-6&&y<_y+14;
	if(!_minimized)_moving=b&&y-_y>=0&&y-_y<20;
}
void Window::onMouseMotion(SDL_MouseMotionEvent m){
	if(_moving)move(m.xrel, m.yrel);
}
void Window::minimize(bool b){
	_minimized = b;
}
void Window::move(int x, int y){_x+=x;_y+=y;}
void Window::update(float delta){}
void Window::drawExtra(Graphics &g){}
void Window::onInput(const std::string &input){}
