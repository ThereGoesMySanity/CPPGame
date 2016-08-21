/*
 * TerminalWindow.h
 *
 *  Created on: Aug 21, 2016
 *      Author: will
 */

#ifndef TERMINALWINDOW_H
#define TERMINALWINDOW_H
#include <string>
#include "Graphics.h"
#include "Vec2.h"
class TerminalWindow{
public:
	TerminalWindow();
	~TerminalWindow();
	void print(std::string &s);
	void delayedPrint(std::string &s, int delay);
	void update();
	void draw(Graphics &g);
private:
	Vec2 pos;
	int _w, _h;
	std::string delayedText;
	std::string text;
};



#endif /* SRC_HEADERS_TERMINALWINDOW_H_ */
