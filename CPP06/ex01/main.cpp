#include <iostream>
#include <iomanip>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data *d = new Data(1337, "Serializer test");

	std::cout << "Original pointer: " << d << std::endl;
	std::cout << "Original object: " << *d << std::endl;

	uintptr_t raw = Serializer::serialize(d);

	std::cout << "\nSerialized pointer: " << raw << std::endl;

	Data *d2 = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << d2 << std::endl;
	std::cout << "Deserialized object:\n" << *d2;

	delete d;
	return 0;
}

