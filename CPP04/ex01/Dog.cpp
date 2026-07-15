/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:18:36 by jomaia            #+#    #+#             */
/*   Updated: 2026/07/13 15:07:17 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other.type), _brain(new Brain(*other._brain))
{
	std::cout << "Dog copy constructor called << std::endl";
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this!= &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = other._brain;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark" << std::endl;
}

void Dog::Add_Idea(std::string idea)
{
	if (_brain != NULL)
		_brain->AddIdea(idea);
	else
		std::cout << " Error 404, Dog brain not found\n";
}

void Dog::Print_idea(void) const
{
	if (_brain != NULL)
		_brain->Print_idea();
	else
		std::cout << "Error 404, Dog brain not found\n";
}
