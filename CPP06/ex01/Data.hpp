#pragma once

#include <iostream>

struct Data
{
	int i;
	std::string str;
	Data(int number, std::string s);
};

std::ostream &operator<<( std::ostream &out,const Data &data);