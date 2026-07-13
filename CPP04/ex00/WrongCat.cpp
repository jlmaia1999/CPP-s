/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:40:11 by jomaia            #+#    #+#             */
/*   Updated: 2026/07/01 16:43:32 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong Cat")
{
	std::cout << "Wrong Cat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.type)
{
	std::cout << "Wrong Cat copy constructor called << std::endl";
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this!= &other)
		this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Minhao" << std::endl;
}