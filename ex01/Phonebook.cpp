/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:49:21 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/14 09:16:37 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(){}

Phonebook::~Phonebook(){}

void Phonebook::set_last()
{
	this->_last_contact = 0;
}

void Phonebook::Add()
{
	std::string input;

	if (this->_last_contact >= 8)
		Phonebook::set_last();
	do {
		std::cout << "First Name: ";
		std::getline(std::cin, input);
	} while (!std::cin.eof() && input.size() == 0);
	_contacts[_last_contact].set_first(input);
	do {
		std::cout << "Last Name: ";
		std::getline(std::cin, input);
	} while (!std::cin.eof() && input.size() == 0);
	_contacts[_last_contact].set_last(input);
	do {
		std::cout << "Number: ";
		std::getline(std::cin, input);
	} while (!std::cin.eof() && input.size() == 0);
	_contacts[_last_contact].set_number(input);
	do {
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, input);
	} while (!std::cin.eof() && input.size() == 0);
	_contacts[_last_contact].set_secret(input);
	this->_last_contact++;
}

void Phonebook::Search()
{
	
}