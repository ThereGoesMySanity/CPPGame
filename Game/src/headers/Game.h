/*
 * Game.h
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */

#ifndef GAME_H
#define GAME_H

class Graphics;

class Game{
public:
	Game();
	~Game();
private:
	void run();
	void draw(Graphics &graphics);
	void update(float delta);
};



#endif /* GAME_H_ */
