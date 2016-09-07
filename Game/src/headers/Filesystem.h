/*
 * Filesystem.h
 *
 *  Created on: Aug 27, 2016
 *      Author: will
 */

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <vector>
#include <map>
#include "File.h"
class Filesystem{
public:
	Filesystem(const std::string &name);
	~Filesystem();
	void addFolder(const std::string &s);
	void addFile(File *f);
	std::string getCwd();
	std::string cd(const std::string &dir);
	std::vector<std::string> ls(const std::string &s);
	std::string cat(const std::string &file);
	std::string toRoot(const std::string &path);
	void run(const std::string &file);
    static Filesystem* createFilesystem(const std::string &name);
private:
    std::string _name;
	std::map<std::string, std::vector<std::string>> _folders;
	std::map<std::string, File*> _files;
	std::string cwd;
};




#endif /* SRC_HEADERS_FILESYSTEM_H_ */
