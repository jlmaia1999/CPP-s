/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:48:38 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 16:00:15 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	zombie = newZombie("Gervasio");
	zombie->announce();
	randomChump("Asdrubal");
	delete zombie;
}