/*
 * Game.cpp
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */
#include <SDL2/SDL.h>
#include "Game.h"
#include "Graphics.h"
#include "Input.h"

Game::Game(){
	SDL_Init(SDL_INIT_EVERYTHING);
	run();
}
Game::~Game(){

}
void Game::run(){
	Graphics g;
	Input i;
	SDL_Event event;
	_player = Sprite(g, "")

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

				break;
			}
		}
		draw(g);
		int delta = SDL_GetTicks()-last;
		last = SDL_GetTicks();
		update(std::min(delta, 1000));
	}
}

void Game::draw(Graphics &graphics){
	graphics.clear();

	graphics.flip();
}

void Game::update(float delta){

}
