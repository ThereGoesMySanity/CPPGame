#include "Window.h"
#include <string>

Window::Window(const std::string &title, int x, int y, int w, int h)
                :_title(title),_x(x),_y(y),_w(w),_h(h) {
    
}
Window::~Window(){}
void Window::draw(Graphics &g){
    g.setColor(0, 0, 0);
    g.fillRect(_x, _y, _w, _h);
    g.setColor(0, 255, 0);
    g.drawRect(_x, _y, _w, _h);
    g.drawLine(_x, _y+16, _x+_w-1, _y+16);
    g.drawText(_title, _x, _y);
}
void Window::onMouse(bool b, int x, int y){
    _moving=b&&y-_y>=0&&y-_y<20;
}
void Window::onMouseMotion(SDL_MouseMotionEvent m){
    if(_moving)move(m.xrel, m.yrel);
}
void Window::move(int x, int y){_x+=x;_y+=y;}
void Window::update(float delta){}
void Window::drawExtra(Graphics &g){}
void Window::onInput(const std::string &input){}
