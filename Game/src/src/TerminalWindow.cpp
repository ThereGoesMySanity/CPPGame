/*
 * TerminalWindow.cpp
 *
 *  Created on: Aug 21, 2016
 *      Author: will
 */

#include "TerminalWindow.h"

std::string TerminalWindow::prelude = "";
std::string TerminalWindow::user = "";

TerminalWindow::TerminalWindow(int x, int y, int w, int h):
    TerminalWindow("Terminal",x, y, w, h){}
TerminalWindow::TerminalWindow(const std::string &name, int x, int y, int w, int h):
    TerminalWindow(nullptr, name, true, x, y, w, h){}
TerminalWindow::TerminalWindow(Filesystem* f, const std::string &name, bool movable, int x, int y, int w, int h):
    Window(name, x, y, w, h), delay(1), remaining(0), _f(f), _movable(movable){
    if(user=="")text.push_back("login as: ");
}

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
		text[text.size()-1]+=input.substr(0, _w/8-text[text.size()-1].size());
		for(int i = 1; i <= (prelude.size()+input.size())*8/_w; i++){
			text.push_back(input.substr(_w*i/8-prelude.size(), _w/8));
		}
		if(user==""){
            user=input;
			prelude = user+"@"+user+"-pc:~$ ";
		}else{
            executeCommand(input);
		}
		input = "";
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
void TerminalWindow::executeCommand(const std::string &s){
	std::vector<std::string> cmd = globals::splits(s, ' ');
	if(cmd.size()==0)return;
	cmd.push_back("");
	if(cmd[0]=="ls"){

    }
}
void TerminalWindow::drawExtra(Graphics &g){
	if(text.size()==0)return;
	int z = std::min((_h-20)/16-(input.size()+text[text.size()-1].size())*8/_w, text.size());
	int i = 0;
	for(; i < z-1; i++){
		g.drawText(text[text.size()-z+i], _x+2, _y+16*i+18, true);
	}
	for(int j = 0; j <= (input.size()+text[text.size()-1].size())*8/_w; j++){
		g.drawText((text[text.size()-1]+input).substr(_w/8*j, _w/8), _x+2, _y+16*(i+j)+18, true);
	}
}
void TerminalWindow::onFocus(){
	SDL_StartTextInput();
}

void TerminalWindow::onUnfocus(){
	SDL_StopTextInput();
}
void TerminalWindow::onFilesystemChange(Filesystem* f){
    _f = f;
}
