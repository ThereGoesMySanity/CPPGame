/*
 * TerminalWindow.h
 *
 *  Created on: Aug 21, 2016
 *      Author: will
 */

#ifndef TERMINALWINDOW_H
#define TERMINALWINDOW_H

class TerminalWindow{
public:
	void println(std::string &s);
	void draw(Graphics &g);
private:
	int _x, _y, _w, _h;
};



#endif /* SRC_HEADERS_TERMINALWINDOW_H_ */
