/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:42:09 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 17:56:46 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name){};

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
