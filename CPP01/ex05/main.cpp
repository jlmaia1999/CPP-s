/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:50:30 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/27 11:55:15 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	std::string level;
	Harl harl;

	std::cout << "Choose an option\n";
	std::cout << "DEBUG\n";
	std::cout << "INFO\n";
	std::cout << "WARNING\n";
	std::cout << "ERROR\n\n";

	while (getline(std::cin, level))
	{
		harl.complain(level);
	}
	return 0;
}