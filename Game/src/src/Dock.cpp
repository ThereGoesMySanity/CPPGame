//
//  Dock.cpp
//  Game
//
//  Created by Willem Kennedy on 2016-08-24.
//  Copyright © 2016 Willem Kennedy. All rights reserved.
//

#include "Dock.h"
#include <iostream>

Dock::Dock(Game *g, int x, int y, int w, int h) : Window(g, "Dock", x , y, w, h){}
Dock::~Dock(){};
void Dock::draw(Graphics &g){
	g.setColor(0,200,0);
	g.fillRect(_x, _y, _w, _h);
	int wid = std::min(static_cast<int>(globals::WIDTH/(_g->_windows.size()-1)), 84);
	int i = 0;
	for(Window *w : _g->_windows){
		if(w!=this){
			g.setColor(0,255,0);
			g.drawRect(_x+2+wid*i, _y+2, wid-2, 16);
			g.drawText(w->_title.substr(0, wid/8), _x+4+wid*i, _y+2);
			i++;
		}
	}
}
void Dock::onMouse(bool b, int x, int y){
	int wid = std::min(static_cast<int>(globals::WIDTH/(_g->_windows.size()-1)), 84);
	int j = 0;
	for(int i = 0; i < _g->_windows.size(); i++){
		if(_g->_windows[i]!=this){
			if(x>=_x+2+wid*j&&y>=_y+2&&x<_x+wid*(j+1)&&y<_y+18){
				_g->focusWindow(i);
				_g->_windows[i]->minimize(false);
			}
			j++;
		}
	}
}
