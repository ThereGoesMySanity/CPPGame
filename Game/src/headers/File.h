/*
 * File.h
 *
 *  Created on: Aug 27, 2016
 *      Author: will
 */

#ifndef FILE_H
#define FILE_H

#include "Filesystem.h"
#include <string>
class Filesystem;
class File{
public:
	File(Filesystem* f, std::string name);
	void onCat();
	std::string _name;
};



#endif /* SRC_HEADERS_FILE_H_ */
