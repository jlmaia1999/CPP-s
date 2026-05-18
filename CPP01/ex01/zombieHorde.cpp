/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:04:52 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 16:19:01 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		zombies[i].setname(name);
	}
	return zombies;
}