#pragma once
#ifndef E_H
#define E_H

#include <string>
#include <iostream>

class E {
	std::string err;
public:
	E() : err("Something went badly wrong!") { std::cout << err; };
};

#endif // !E_H
