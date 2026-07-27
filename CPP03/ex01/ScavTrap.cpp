/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:44:25 by jomaia            #+#    #+#             */
/*   Updated: 2026/06/22 15:28:15 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor called \n";
	_name = "Unnamed Scavtrap";
	_hp = 100;
	_mp = 50;
	_ad = 20;
	_mode = false;
}

ScavTrap::ScavTrap(const std::string name)
{
	std::cout << "ScavTrap Constructor called \n";
	_name = name;
	_hp = 100;
	_mp = 50;
	_ad = 20;
	_mode = false;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy constructor called\n";
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap Copy assigment operator called\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_mp = other._mp;
		this->_ad = other._ad;
		this->_mode = other._mode;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << _name <<"ScavTrap Destructor called \n";
}

void ScavTrap::guardGate()
{
	if (_mode)
	{
		std::cout << "ScavTrap " << _name << " is guarding the gate!" << std::endl;
		_mode = true;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " is no longuer guarding the gate!" << std::endl;
		_mode = false;
	}
}

void ScavTrap::attack(const std::string name)
{
	if (_hp == 0)
	{
		std::cout << "ScavTrap " << _name << " has no hp left to attack" << std::endl;
		return ;
	}
	if (_mp == 0)
	{
		std::cout <<"ScavTrap " << _name << " has no energy left to attack" << std::endl;
		return ;
	}
	_mp -= 1;
	std::cout << "ScavTrap " << _name << " attacks " << name << ", causing " << _ad << " points of damage !" << std::endl;
}