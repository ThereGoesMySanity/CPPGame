/*
 * Game.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */
#include <SDL2/SDL.h>
#include "Game.h"
#include <iostream>
#include <algorithm>
#include "Graphics.h"
#include "Input.h"

Game::Game() {
	std::cout << "Initializing..." <<std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    std::cout << "Initialized SDL" <<std::endl;
	run();
}
Game::~Game(){

}
void Game::run(){
	Graphics g;
	std::cout << "Initialized graphics and input" <<std::endl;
	Input i(this);
	SDL_Event event;
    _windows.insert(_windows.begin(), new TerminalWindow(0,0,256,300));
    g.setFont("/Users/wkennedy/Library/Fonts/FSEX300.ttf", 16);
    std::cout << "Loaded font" <<std::endl;
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
    auto it = _windows.begin() + pos;
    std::rotate(_windows.begin(),_windows.begin()+1, it);
}
int Game::getWindowAtLocation(int x, int y){
    for(int i = 0; i < _windows.size(); i++){
        Window* w = _windows[i];
        if(x>=w->_x&&y>=w->_y&&x<w->_x+w->_w&&y<w->_y+w->_h){
            return i;
        }
    }
    return NULL;
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
