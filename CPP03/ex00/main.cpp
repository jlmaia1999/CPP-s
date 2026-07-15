/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:26:14 by jomaia            #+#    #+#             */
/*   Updated: 2026/07/15 16:02:44 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap original("Gervasio");
	ClapTrap clone = original;
	original.beRepaired(10);
	original.attack("Alcino");
	original.takeDamage(5);
	original.beRepaired(2);
	original.takeDamage(7);
	original.attack("Alcino");
	original.beRepaired(10);
}