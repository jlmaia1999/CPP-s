/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:31:04 by jomaia            #+#    #+#             */
/*   Updated: 2026/07/13 15:07:56 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain)
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other.type), _brain(new Brain(*other._brain))
{
	std::cout << "Cat copy constructor called << std::endl";
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this!= &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = other._brain;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

void Cat::Add_Idea(std::string idea)
{
	if (_brain != NULL)
		_brain->AddIdea(idea);
	else
		std::cout << "Error 404, Cat Brain not found\n";
}

void Cat::Print_idea(void) const
{
	if (_brain != NULL)
		_brain->Print_idea();
	else
		std::cout << "Error 404, Cat Brain not found\n";
}