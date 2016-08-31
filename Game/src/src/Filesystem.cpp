/*
 * Filesystem.cpp
 *
 *  Created on: Aug 27, 2016
 *      Author: will
 */
#include "Filesystem.h"

void Filesystem::addFolder(const std::string &s){
	_folders[cwd].push_back(s);
	_folders[cwd+"/"+s]={};
}
void Filesystem::addFile(File *f){
	_files[cwd+"/"+f->_name]=f;
	_folders[cwd].push_back(f->_name);
}
std::string Filesystem::getCwd(){
	return cwd;
}
std::string Filesystem::cd(const std::string &dir){
	if(dir.substr(0,1)=="/"){
		if(_folders.count(dir)>0){
			cwd=dir;
			return "";
		}else if(_files.count(dir)>0){
			return "bash: cd: "+dir+": Not a directory";
		}
		return "bash: cd: "+dir+": No such file or directory";
	}
	return cd(cwd+"/"+dir);
}
std::vector<std::string> Filesystem::ls(const std::string &s){
	if(s!=""){
		if(s.substr(0,1)=="/"){
			return _folders[s];
		}
		return _folders[cwd+"/"+s];
	}
	return _folders[cwd];
}
