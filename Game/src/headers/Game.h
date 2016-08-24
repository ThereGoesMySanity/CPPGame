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
#include <map>
class Graphics;

class Game{
public:
	Game();
	~Game();
private:
	void run();
	void draw(Graphics &graphics);
	void update(float delta);

	std::vector<Window*> _windows;
	Sprite _player;
};



#endif /* GAME_H_ */
