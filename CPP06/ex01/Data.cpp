#include "Data.hpp"

Data::Data(int number, std::string s)
{
	i = number;
	str = s;
}

std::ostream &operator<<(std::ostream &out,const Data &data)
{
	out << "Integer: " << data.i << "\nString: " << data.str << std::endl;
	return out;
}