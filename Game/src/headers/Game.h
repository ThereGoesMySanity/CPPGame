/*
 * Game.h
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include "Sprite.h"
#include "Filesystem.h"
#include "Window.h"
#include "Graphics.h"
#include "Input.h"
#include "Globals.h"
#include "Dock.h"
#include "TerminalWindow.h"
class Graphics;
class Window;
class Game{
public:
	Game();
	~Game();
    Window* getWindow(int i);
    void focusWindow(int pos);
    int getWindowAtLocation(int x, int y);
    void addWindow(Window* w);
    void addGameListener(GameListener* g);
    std::vector<Window*> _windows;
    Window* _dock;
    Filesystem* _f;
private:
	void run();
	void draw(Graphics &graphics);
	void update(float delta);
    std::vector<GameListener*> _listeners;
};



#endif /* GAME_H_ */
