/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:13:19 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/27 15:03:54 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _n(0)
{
	std::cout << "Default constructor called \n";
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called";
	_n = i << _bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called";
	_n = roundf(f *(1 << _bits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assigment operator called\n";
	_n = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return _n;
}

void Fixed::setRawBits(int const raw)
{
	this->_n = raw;
}

