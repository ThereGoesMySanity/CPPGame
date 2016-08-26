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
void TerminalWindow::onInput(const std::string &input){
	this->input += input;
}
void TerminalWindow::onSpecialKey(SDL_Scancode s){
	switch(s){
	case SDL_SCANCODE_BACKSPACE:
		if(input.size()>0)
			input=input.substr(0,input.size()-1);
		break;
	case SDL_SCANCODE_RETURN:
		for(int i = 1; i <= (prelude.size()+input.size())*8/_w; i++){
			text.push_back();
		}
		text.push_back(prelude);
		break;
	default:
		break;
	}
}
void TerminalWindow::print(const std::string &s){
	for(int i = 0; i < s.size(); i++){
		std::string s1 = s.substr(i,i+1);
		if(text.size()==0||text[text.size()-1].size()==_w/8){
			text.push_back(s1);
		}else{
			text[text.size()-1]+=s1;
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

}
void TerminalWindow::onFocus(){
	SDL_StartTextInput();
}

void TerminalWindow::onUnfocus(){
	SDL_StopTextInput();
}
