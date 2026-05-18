/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:34:01 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 17:57:01 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon){}

HumanA::~HumanA(){}

void HumanA::attack()
{
	std::cout << _name << " attacks with their" << _weapon.getType() << std::endl;
}