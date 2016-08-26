/*
 * Game.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */
#include <SDL2/SDL.h>
#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include "Graphics.h"
#include "Input.h"
#include "Globals.h"
#include "Dock.h"
#include "TerminalWindow.h"

#if defined __MACH__
#define FONT "/Library/Fonts/FSEX300.ttf"
#elif defined _WIN32

#else
#define FONT "/git/CPPGame/Game/FSEX300.ttf"
#endif

using namespace globals;

Game::Game() {

	SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
	run();
}
Game::~Game(){

}
void Game::run(){
	Graphics g;
	Input i(this);
	SDL_Event event;
    addWindow(new TerminalWindow(this, 0,0,256,300));
    addWindow(new TerminalWindow(this, "The other terminal with a longname so that I can test and differentiate between the two",100,100,500,300));
    addWindow(new Dock(this, 0, HEIGHT-20, WIDTH, 20));
    g.setFont(getenv("HOME")+std::string(FONT), 16);
	int last = SDL_GetTicks();
	while(true){
		i.nextFrame();
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_QUIT:
				return;
			case SDL_KEYDOWN:
				if(!event.key.repeat){
					i.onKeyDown(event);
				}
				break;
			case SDL_KEYUP:
				i.onKeyUp(event);
				break;
			case SDL_MOUSEMOTION:
                i.onMouseMove(event);
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(event.button.button==SDL_BUTTON_LEFT)i.onMouse(true);
				break;
			case SDL_MOUSEBUTTONUP:
				if(event.button.button==SDL_BUTTON_LEFT)i.onMouse(false);
				break;
			case SDL_TEXTINPUT:
				i.onTextInput(event);
				break;
			}
		}
		draw(g);
		int delta = SDL_GetTicks()-last;
		last = SDL_GetTicks();
		update(std::min(delta, 1000));
	}
}
void Game::addWindow(Window* w){
    _windows.insert(_windows.begin(),w);
}
Window* Game::getWindow(int i){return _windows[i];}
void Game::focusWindow(int pos){
	_windows[0]->onUnfocus();
    auto it = _windows.begin() + pos;
    std::rotate(_windows.begin(),it, it+1);
    _windows[0]->onFocus();
}
int Game::getWindowAtLocation(int x, int y){
    for(int i = 0; i < _windows.size(); i++){
        Window* w = _windows[i];
        if(x>=w->_x&&y>=w->_y&&x<w->_x+w->_w&&y<w->_y+w->_h){
            return i;
        }
    }
    return 0;
}
void Game::draw(Graphics &graphics){
	graphics.setColor(0,0,0);
	graphics.clear();
	for(int i = _windows.size()-1; i>=0; i--){
		_windows[i]->draw(graphics);
	}
	graphics.flip();
}

void Game::update(float delta){

}
