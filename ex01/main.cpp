/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:55:42 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/14 10:02:49 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
	Phonebook pb;

	pb.set_last();
	while (1)
	{
		std::string input;
		std::cout << "Command(ADD, SEARCH or EXIT): ";
		std::getline(std::cin, input);
		if (input == "ADD")
			pb.Add();
		else if (input == "SEARCH")
			pb.Search();
		else if (input == "EXIT")
			exit(0);
	}
}