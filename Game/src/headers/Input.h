/*
 * Input.h
 *
 *  Created on: Aug 17, 2016
 *      Author: Will
 */

#ifndef INPUT_H
#define INPUT_H
#include <map>
#include <vector>
class Input {
public:
	void nextFrame();
	void onKeyUp(const SDL_Event &event);
	void onKeyDown(const SDL_Event &event);

	void onMouseMove(const SDL_Event &event);

	bool getKeyDown(SDL_Scancode key);
	bool getKeyUp(SDL_Scancode key);
	bool getKeyHeld(SDL_Scancode key);

	std::vector getMousePos();
	int getX();
	int getY();
private:
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
	std::vector<int> _mousePos;
};



#endif /* HEADERS_INPUT_H_ */
