/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 15:27:03 by jomaia            #+#    #+#             */
/*   Updated: 2026/06/22 15:33:12 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default constructor called \n";
	_name = "Unnamed Fragtrap";
	_hp = 100;
	_mp = 100;
	_ad = 30;

}

FragTrap::FragTrap(const std::string name)
{
	std::cout << "Constructor called \n";
	_name = name;
	_hp = 100;
	_mp = 100;
	_ad = 30;

}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Copy assigment operator called\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_mp = other._mp;
		this->_ad = other._ad;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << _name <<" Destructor called \n";
}

void FragTrap::highFivesGuys(void)
{
	if (_hp == 0)
		std::cout << "FragTrap " << _name << " has no hp left to high five" << std::endl;
	else
		std::cout << "FragTrap " << _name << " wants a High Five!" << std::endl;
}

void FragTrap::attack(const std::string name)
{
	if (_hp == 0)
	{
		std::cout << "FragTrap " << _name << " has no hp left to attack" << std::endl;
		return ;
	}
	if (_mp == 0)
	{
		std::cout <<"FragTrap " << _name << " has no energy left to attack" << std::endl;
		return ;
	}
	_mp -= 1;
	std::cout << "FragTrap " << _name << " attacks " << name << ", causing " << _ad << " points of damage !" << std::endl;
}