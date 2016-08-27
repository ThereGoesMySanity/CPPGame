/*
 * Filesystem.h
 *
 *  Created on: Aug 27, 2016
 *      Author: will
 */

#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include "File.h"
class Filesystem{
public:
	void addFolder(const std::string &s);
	void addFile(File *f);
	std::string getCwd();
	std::string cd(const std::string &dir);
	std::vector<std::string> ls(const std::string &s);
private:
	std::map<std::string, std::vector<std::string>> _folders;
	std::map<std::string, File*> _files;
	std::string cwd;
};




#endif /* SRC_HEADERS_FILESYSTEM_H_ */
