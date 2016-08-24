/*
 * TerminalWindow.cpp
 *
 *  Created on: Aug 21, 2016
 *      Author: will
 */

#include "TerminalWindow.h"
#include <iostream>
#include <string>
TerminalWindow::TerminalWindow(Game *g, int x, int y, int w, int h)
	: Window(g, "Terminal",x, y, w, h), delay(1), remaining(0){}
TerminalWindow::TerminalWindow(Game *g, const std::string &name, int x, int y, int w, int h)
	: Window(g, name,x, y, w, h), delay(1), remaining(0){}
TerminalWindow::~TerminalWindow(){}
void TerminalWindow::println(const std::string &s){
	print(s+"\n");
}
void TerminalWindow::print(const std::string &s){
	for(unsigned int i = 0; i < s.length(); i++){
		char c = s[i];

		if(c=='\n'){
			text.push_back("");
		}else if(text.size()==0){
			text.push_back({c});
		}else{
			text[text.size()-1]+=c;
		}
	}
}
void TerminalWindow::delayedPrint(const std::string &s, int delay){
	delayedText += s;
}
void TerminalWindow::update(float delta){
	if(remaining<=0){
		if(delayedText.size()>0){
			std::string s = delayedText.substr(0,1);
			print(s);
			remaining=delay;
		}
    }else{
        remaining-=delta;
    }
}
void TerminalWindow::drawExtra(Graphics &g){
	int t = std::min(static_cast<int>(text.size()), _w/16);
	for(int i = 0; i < t; i++){
		g.drawText(text[i+text.size()-t], _x, _y+16+i*16);
	}
}
