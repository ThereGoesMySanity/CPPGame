/*
 * Filesystem.cpp
 *
 *  Created on: Aug 27, 2016
 *      Author: will
 */
#include "Filesystem.h"
#include "Globals.h"
#include <cstdlib>
#include <SDL2/SDL.h>
Filesystem::Filesystem(const std::string &name) : _name(name){}

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
	if(dir=="~")cd("/home/"+_name);
	if(dir=="..")cd(cwd.substr(0, cwd.find_last_of("/")));
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
Filesystem* Filesystem::createFilesystem(const std::string &name){
	Filesystem* f = new Filesystem(name);
	f->addFolder("home");
	f->cd("home");
	f->addFolder(name);
	f->cd(name);
	f->addFolder("Desktop");
	f->addFolder("Documents");
	f->addFolder("Downloads");
	f->addFolder("Pictures");
	std::srand(SDL_GetTicks());
	int lit = std::rand()%100;
	if(lit<60){
		f->cd("Desktop");
		int num = std::rand()%300+200;
		for(std::string i :
				std::vector<std::string>({"jan ", "march", "apr ", "jul", "sep-nov ", "December"})){
			f->addFolder(i+"2009");
			for(int i = 0; i < std::rand()%10+10; i++){
				f->addFile(new File(this, "DSC"+globals::padInt(num, 5)+".jpg"));
				num++;
			}
		}
	}
	return f;
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
