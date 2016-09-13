//
//  Dock.cpp
//  Game
//
//  Created by Willem Kennedy on 2016-08-24.
//  Copyright © 2016 Willem Kennedy. All rights reserved.
//

#include "Dock.h"
#include <iostream>

Dock::Dock(int x, int y, int w, int h) : Window("Dock", x , y, w, h){}
Dock::~Dock(){};
void Dock::draw(Graphics &g){
	g.setColor(0,200,0,200);
	g.fillRect(_x, _y, _w, _h);
    std::vector<Window*> w = getWindows();
	int wid = std::min(static_cast<int>(globals::WIDTH/(w.size()-1)), 84);
	int i = 0;
	for(Window *wn : w){
        g.setColor(0,255,0);
        g.drawRect(_x+2+wid*i, _y+2, wid-2, 16);
        g.drawText(wn->_title.substr(0, wid/8), _x+4+wid*i, _y+2, false);
        i++;
	}
}
void Dock::onMouse(bool b, int x, int y){
    Game* g = getGame();
	int wid = std::min(static_cast<int>(globals::WIDTH/(getWindows().size()-1)), 84);
	for(int i = 0; i < getWindows().size(); i++){
		if(x>=_x+2+wid*i&&y>=_y+2&&x<_x+wid*(i+1)&&y<_y+18){
			g->focusWindow(i);
			g->_windows[0]->minimize(false);
		}
	}
}
void Dock::onFilesystemChange(Filesystem* f){}

