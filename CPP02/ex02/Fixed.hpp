/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:09:31 by jomaia            #+#    #+#             */
/*   Updated: 2026/06/22 14:09:16 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
	private:
		int _n;
		static const int _bits = 8;
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed&copy);
		Fixed &operator= (const Fixed &copy);
		~Fixed();
		int getRawBits()const;
		void setRawBits(int const n);
		float toFloat()const;
		int toInt()const;

		Fixed operator*(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);

		static const Fixed& min(const Fixed &n1, const Fixed &n2);
		static Fixed& min(Fixed &n1, Fixed &n2);
		static const Fixed& max(const Fixed &n1, const Fixed &n2);
		static Fixed& max(Fixed &n1, Fixed &n2);
		
};

std::ostream &operator<<(std::ostream &out, const Fixed &c);

#endif