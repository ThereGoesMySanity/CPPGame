/*
 * File.h
 *
 *  Created on: Aug 27, 2016
 *      Author: will
 */

#ifndef FILE_H
#define FILE_H
#include <string>
#include "TerminalWindow.h"
class File{
public:
	File(const std::string &name);
	File(const std::string &name, const std::string &cat);
	virtual ~File();
	std::string cat();
	virtual void run(TerminalWindow* t);
	std::string _name;
private:
	Filesystem* _f;
	std::string _cat;
};



#endif /* SRC_HEADERS_FILE_H_ */
