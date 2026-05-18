/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:08:02 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 16:09:43 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int n;
	
	n = 5;
	Zombie *arr = zombieHorde(n, "Gervasio");
	for(int i = 0; i < n; i++)
		arr[i].announce();
	delete[] arr;
	return 0;
}