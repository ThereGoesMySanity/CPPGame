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
#include <sstream>
#include <iostream>
#include <string>
#include "Graphics.h"
#include "Window.h"
class TerminalWindow: public Window {
public:
	TerminalWindow(int x, int y, int w, int h);
	TerminalWindow(const std::string &name, int x, int y, int w, int h);
	TerminalWindow(Filesystem* f, const std::string &name, bool movable, int x, int y, int w, int h);
	~TerminalWindow();
	void println(const std::string &s);
	void print(const std::string &s);
	void delayedPrint(const std::string &s, int delay);
	void drawExtra(Graphics &g) override;
	void update(float delta) override;
	void onInput(const std::string &in) override;
	void executeCommand(const std::string &s);
	void onSpecialKey(SDL_Scancode s) override;
    void onFocus() override;
    void onUnfocus() override;
    void onFilesystemChange(Filesystem* f) override;
private:
    Filesystem* _f;
	std::string delayedText;
	std::vector<std::string> text;
	std::string input;
    static std::string prelude;
	static std::string user;
	float delay;
	float remaining;
	bool _movable;
};

#endif /* SRC_HEADERS_TERMINALWINDOW_H_ */
