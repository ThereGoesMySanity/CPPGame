/*
 * Game.h
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */

#ifndef GAME_H
#define GAME_H

#include "Sprite.h"
#include "TerminalWindow.h"

class Graphics;

class Game{
public:
	Game();
	~Game();
private:
	void run();
	void draw(Graphics &graphics);
	void update(float delta);

	Sprite _player;
    TerminalWindow _window;
};



#endif /* GAME_H_ */
