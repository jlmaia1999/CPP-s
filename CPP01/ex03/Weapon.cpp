/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:51:12 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 17:51:21 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {};

Weapon::~Weapon(){};

std::string& Weapon::getType()
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}
