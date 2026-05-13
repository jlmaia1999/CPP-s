/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:07:33 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/13 17:39:28 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

Contact::Contact(){}

Contact::~Contact(){}

std::string Contact::get_first()
{
	return _first;
}

std::string Contact::get_last()
{
	return _last;
}
std::string Contact::get_number()
{
	return _number;
}
std::string Contact::get_secret()
{
	return _secret;
}

void Contact::set_first(std::string first)
{
	this->_first = first;
}

void Contact::set_first(std::string last)
{
	this->_last = last;
}

void Contact::set_first(std::string number)
{
	this->_number = number;
}

void Contact::set_first(std::string secret)
{
	this->_secret = secret;
}
