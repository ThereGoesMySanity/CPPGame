/*
 * TerminalWindow.cpp
 *
 *  Created on: Aug 21, 2016
 *      Author: will
 */

#include "TerminalWindow.h"
#include <string>
TerminalWindow::TerminalWindow(){}
TerminalWindow::~TerminalWindow(){}
void TerminalWindow::print(std::string &s){
	text += s;
}
void TerminalWindow::update(){
	if(delayedText.size()>0){
		std::string s = delayedText.substr(0,1);
		print(s);
	}
}
void TerminalWindow::draw(Graphics &g){
    g.setColor(0, 255, 0);
    g.drawText("Terminal", _x, _y);
}
