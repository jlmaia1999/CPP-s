#include "Array.hpp"

template<typename T>Array<T>::Array(): _arr(new T[1]), _arr_size(0)
{
	_arr[0] = 0;
}

template<typename T>Array<T>::Array(unsigned int n): _arr(new T[n]()), _arr_size(n){}

template<typename T>Array<T>::Array(const Array &other): _arr(new T[other._arr_size]()), _arr_size(other._arr_size)
{
	for (unsigned int i = 0; i < size(); i++)
		_arr[i] = other._arr[i];
}

template<typename T>Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		this->_arr_size = other.size();
		delete [] this->_arr;
		this->_arr = new T[_arr_size];
		for (unsigned int i = 0; i < size(); i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template<typename T> Array<T>::~Array()
{
	delete [] this->_arr;
}

template <typename T> T &Array<T>::operator[](unsigned int index)
{
	if (index >= size())
		throw(std::out_of_range("out of bounds"));
	return _arr[index];
}

template <typename T> unsigned int Array<T>::size() const
{
	return (_arr_size);
}
