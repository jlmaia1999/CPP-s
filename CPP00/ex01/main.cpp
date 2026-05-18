/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:55:42 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 14:34:46 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"


int main()
{
	Phonebook pb;

	pb.set_last();
	while (1)
	{
		std::string input;
		std::cout << "Command(ADD, SEARCH or EXIT): ";
		input = checkeof();
		if (input == "ADD")
			pb.Add();
		else if (input == "SEARCH")
			pb.Search();
		else if (input == "EXIT")
			exit(0);
	}
}