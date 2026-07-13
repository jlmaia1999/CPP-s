/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:29:02 by jomaia            #+#    #+#             */
/*   Updated: 2026/06/26 15:36:19 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() :type("animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "*Animalistic noises*" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}