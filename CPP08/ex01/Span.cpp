#include "Span.hpp"

Span::Span(unsigned int size): _size_max(size)
{
	_numbers.reserve(size);
}

Span::Span(const Span &other): _size_max(other._size_max)
{
	_numbers.reserve(other._size_max);
	for (unsigned int i = 0; i < _size_max; i++)
		_numbers.push_back(other._numbers[i]);
}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_numbers = other._numbers;
		this->_size_max = other._size_max;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int num)
{
	if(_numbers.size() >= _size_max)
		throw (std::out_of_range("Error: container is full"));
	_numbers.push_back(num);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw(std::out_of_range("Error: Not enough elemens"));
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	int result = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < _numbers.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < result)
			result = tmp[i + 1] - tmp[i];
	}
	return result;
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw(std::out_of_range("Error: Not enough elements"));
	std::vector<int>::iterator max_element_ptr = std::max_element(_numbers.begin(), _numbers.end());
	std::vector<int>::iterator min_element_ptr = std::min_element(_numbers.begin(), _numbers.end());
	return *max_element_ptr - *min_element_ptr;
}

