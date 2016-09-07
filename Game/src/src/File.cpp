/*
 * File.cpp
 *
 *  Created on: Aug 27, 2016
 *      Author: will
 */
#include "File.h"

File::File(const std::string &name): File(name, ""){}
File::File(const std::string &name, const std::string &cat): _name(name), _cat(cat){}

std::string File::cat(){
    return _cat;
}
void run(TerminalWindow* t){}
