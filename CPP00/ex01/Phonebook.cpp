/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:49:21 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 14:29:53 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(){}

Phonebook::~Phonebook(){}

void Phonebook::set_last()
{
	this->_last_contact = 0;
}

std::string checkeof()
{
	std::string input;

	std::getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
	else
		return (input);
}

void Phonebook::Add()
{
	std::string input;
	bool check;

	check = 0;
	do {
		std::cout << "First Name: ";
		input = checkeof();
	} while (!std::cin.eof() && input.size() == 0);
	_contacts[_last_contact % 8].set_first(input);
	do {
		std::cout << "Last Name: ";
		input = checkeof();
	} while (!std::cin.eof() && input.size() == 0);
	_contacts[_last_contact % 8].set_last(input);
	do {
		std::cout << "Nickname: ";
		input = checkeof();
	} while (!std::cin.eof() && input.size() == 0);
	_contacts[_last_contact % 8].set_nick(input);
	do {
		check = 0;
		std::cout << "Number: ";
		input = checkeof();
		if (input.length() != 9)
			check = 1;
		for (int i = 0; i < (int)input.length(); i++)
			if(std::isalpha(input[i]))
				check = 1;
	} while ((!std::cin.eof() && input.size() == 0) || check);
	_contacts[_last_contact % 8].set_number(input);
	do {
		std::cout << "Darkest Secret: ";
		input = checkeof();
	} while (!std::cin.eof() && input.size() == 0);
	_contacts[_last_contact % 8].set_secret(input);
	this->_last_contact++;
}

void Phonebook::Search()
{
	int i;
	bool check;
	std::string input;

	check = 0;
	i = 1;
	std::cout << "     Index|First Name| Last Name|  Nickname|\n";
	while (i < 9 && i <= _last_contact)
	{
		if (this->_last_contact == 0)
		{
			std::cout << "Phonebook is empty." << std::endl;
			return ;
		}
		std::cout << "         "<< i << "|";
		if (_contacts[i - 1].get_first().length() >= 10)
			std::cout << _contacts[i - 1].get_first().substr(0,9) << ".";
		else
			std::cout << std::setw(10) << _contacts[i - 1].get_first();
		std::cout << "|";
		if (_contacts[i - 1].get_last().length() >= 10)
			std::cout << _contacts[i - 1].get_last().substr(0,9) << ".";
		else
			std::cout << std::setw(10) << _contacts[i - 1].get_last();
		std::cout << "|";
		if (_contacts[i - 1].get_nickname().length() >= 10)
			std::cout << _contacts[i - 1].get_nickname().substr(0,9) << ".";
		else
			std::cout << std::setw(10) << _contacts[i - 1].get_nickname();		
		std::cout << "|\n";
		i++;
	}
	std::cout << "\n";
	do {
		check = 0;
		std::cout << "Choose contact: ";
		input = checkeof();
		for (int j = 0; j < (int)input.length(); j++)
			if(std::isalpha(input[j]))
				check = 1;
		if (!check)
			i = std::atoi(input.c_str());
	} while ((!std::cin.eof() && input.size() == 0) || check || i <= 0 || i >= 9 || i > _last_contact);
	std::cout << "First name: " << _contacts[i - 1].get_first() << "\n";
	std::cout << "Last name: " << _contacts[i - 1].get_last() << "\n";
	std::cout << "Nickname: " << _contacts[i - 1].get_nickname() << "\n";
	std::cout << "First number: " << _contacts[i - 1].get_number() << "\n";
	std::cout << "Darkest Secret: " << _contacts[i - 1].get_secret() << "\n";
}