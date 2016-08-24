/*
 * TerminalWindow.h
 *
 *  Created on: Aug 21, 2016
 *      Author: will
 */

#ifndef TERMINALWINDOW_H
#define TERMINALWINDOW_H
#include <string>
#include <vector>
#include "Window.h"
#include "Graphics.h"
class TerminalWindow: public Window {
public:
	TerminalWindow(Game *g, int x, int y, int w, int h);
	TerminalWindow(Game *g, const std::string &name, int x, int y, int w, int h);
	~TerminalWindow();
	void println(const std::string &s);
	void print(const std::string &s);
	void delayedPrint(const std::string &s, int delay);
	void drawExtra(Graphics &g);
	void update(float delta);
private:
	std::string delayedText;
	std::vector<std::string> text;
	float delay;
	float remaining;
};



#endif /* SRC_HEADERS_TERMINALWINDOW_H_ */
