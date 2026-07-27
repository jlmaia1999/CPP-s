/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:02:01 by jomaia            #+#    #+#             */
/*   Updated: 2026/06/22 14:46:43 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called \n";
	_name = "Unnamed Claptrap";
	_hp = 10;
	_mp = 10;
	_ad = 0;
}

ClapTrap::ClapTrap(const std::string name)
{
	std::cout << "ClapTrap Constructor called \n";
	_name = name;
	_hp = 10;
	_mp = 10;
	_ad = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy constructor called\n";
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy assigment operator called\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hp = other._hp;
		this->_mp = other._mp;
		this->_ad = other._ad;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name <<"ClapTrap Destructor called \n";
}

void ClapTrap::attack(const std::string& target)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " has no hp left to attack" << std::endl;
		return ;
	}
	if (_mp == 0)
	{
		std::cout <<"ClapTrap " << _name << " has no energy left to attack" << std::endl;
		return ;
	}
	_mp -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _ad << " points of damage !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " has no hp left to repair itself" << std::endl;
		return ;
	}
	if (_mp == 0)
	{
		std::cout <<"ClapTrap " << _name << " has no energy left to restore itself" << std::endl;
		return ;
	}
	_mp -= 1;
	std::cout << "ClapTrap " << _name << " has gained " << amount << " points of health!" << std::endl;
	_hp += amount;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " has taken " << amount << " points damage!" << std::endl;
	if (_hp - amount < 0)
		_hp = 0;
	else
		_hp -= amount;
}