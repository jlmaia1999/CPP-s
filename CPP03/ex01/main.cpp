/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:26:14 by jomaia            #+#    #+#             */
/*   Updated: 2026/07/15 16:14:40 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "-------ClapTrap-------" << std::endl;
	ClapTrap original("Gervasio");
	ClapTrap clone = original;
	original.beRepaired(10);
	original.attack("Alcino");
	original.takeDamage(5);
	original.beRepaired(2);
	original.takeDamage(7);
	original.attack("Alcino");
	original.beRepaired(10);
	std::cout << "-------ScavTrap-------" << std::endl;
	ScavTrap gateguard("Asdrubal");
	gateguard.beRepaired(10);
	gateguard.guardGate();
	gateguard.attack("Alcino");
	gateguard.takeDamage(90);
	gateguard.attack("Alcino");
	for (int i = 0; i < 50; i++)
	{
		gateguard.beRepaired(1);
	}
	gateguard.beRepaired(1);
	
}