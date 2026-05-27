/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:09:31 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/27 14:20:35 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	private:
		int _n;
		static const int _bits = 8;
	public:
		Fixed();
		Fixed(const Fixed&copy);
		Fixed &operator= (const Fixed &copy);
		~Fixed();
		int getRawBits()const;
		void setRawBits(int const raw);
};