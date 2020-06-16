#pragma once
#ifndef E_H
#define E_H

#include <string>

class E {
public:
	std::string err;
	E() : err("Word does not exist in dictionary!") {}; 
};

#endif // !E_H
