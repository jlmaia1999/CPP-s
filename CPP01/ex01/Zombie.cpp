/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:38:35 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 16:18:54 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("Mindless zombie") {}

Zombie::Zombie(std::string name) : _name(name) {};

Zombie::~Zombie()
{
	std::cout << _name << ": has died\n";
}

void Zombie::announce()
{
	std::cout << _name << ": : BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setname(std::string name)
{
	this->_name = name;
}