/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:26:14 by jomaia            #+#    #+#             */
/*   Updated: 2026/06/18 16:31:11 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap original("Arthur");
	ClapTrap clone = original;
	original.beRepaired(10);
	original.attack("your shins");
	std::cout << "Your shins fight back!" << std::endl;
	original.takeDamage(5);
	original.beRepaired(2);
	original.takeDamage(7);
	original.attack("your shins");
	original.beRepaired(10);
}