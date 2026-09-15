#include "Span.hpp"

Span::Span(unsigned int size): _size_max(size)
{
	_numbers.reserve(size);
}

Span::Span(const Span &other): _size_max(other._size_max)
{
	_numbers.reserve(other._size_max);
	for (int i = 0; i < _size_max; i++)
		_numbers.push_back(other._numbers[i]);
}

Span	&Span::operator=(const Span &other)
{
	
}