/*
 * Globals.h
 *
 *  Created on: Aug 24, 2016
 *      Author: will
 */

#ifndef GLOBALS_H
#define GLOBALS_H
#include <iostream>
#include <sstream>
#include <vector>
namespace globals {
const int WIDTH = 800;
const int HEIGHT = 600;
inline std::vector<std::string> splits(const std::string &s, char delim){
	std::vector<std::string> vec;
	std::istringstream f(s);
	std::string s1;
	while (std::getline(f, s1, delim)) {
		std::cout << s1 << std::endl;
		vec.push_back(s1);
	}
	return vec;
}
inline std::string merge(std::vector<std::string> s, char delim){
	std::string s1;
	for(std::string s2 : s){
		s1+=s2+delim;
	}
	return s1.substr(0,s1.size()-1);
}
}



#endif /* SRC_HEADERS_GLOBALS_H_ */
