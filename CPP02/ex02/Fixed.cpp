/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:13:19 by jomaia            #+#    #+#             */
/*   Updated: 2026/06/11 13:52:28 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _n(0)
{
	std::cout << "Default constructor called \n";
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called\n";
	_n = i << _bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
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

void Fixed::setRawBits(int const n)
{
	this->_n = n;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(_n) / static_cast<float>(1 << _bits));
}

int Fixed::toInt() const
{
	return _n >> _bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
	out << c.toFloat();
	return out;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (Fixed(toFloat() / other.toFloat()));
}

Fixed Fixed::operator++(void)
{
	++_n;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed prev(*this);
	_n++;
	return prev;
}

Fixed Fixed::operator--(void)
{
	--_n;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed prev(*this);
	_n--;
	return prev;
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_n < other._n);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (_n > other._n);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_n <= other._n);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_n > other._n);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_n == other._n);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_n != other._n);
}

const Fixed& Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1.toFloat() < n2.toFloat())
		return n1;
	return n2;
}

Fixed& Fixed::min(Fixed &n1, Fixed& n2)
{
	if (n1.toFloat() < n2.toFloat())
		return n1;
	return n2;
}

const Fixed& Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1.toFloat() > n2.toFloat())
		return n1;
	return n2;
}

Fixed& Fixed::max(Fixed &n1, Fixed& n2)
{
	if (n1.toFloat() > n2.toFloat())
		return n1;
	return n2;
}