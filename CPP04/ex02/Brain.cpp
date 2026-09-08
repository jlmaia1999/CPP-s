/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 11:35:20 by jomaia            #+#    #+#             */
/*   Updated: 2026/07/15 17:04:29 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : _i(0)
{
	_ideas_arr[0] = "No ideas";
	std::cout << "Smooth brain created\n";
}

Brain::Brain(const Brain& other) : _i(other._i)
{
	for (int i = 0; i < 100; i++)
	{
		if (i > other._i)
			break;
		_ideas_arr[i] = other._ideas_arr[i];
	}
	std::cout << "Brain was cloned\n";
}

Brain::~Brain()
{
	std::cout << "Brain died\n";
}

Brain &Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		_i = other._i;
		for (int i = 0; i < other._i; i++)
			_ideas_arr[i] = other._ideas_arr[i];
		std::cout << "Brain has stole an identity\n";
	}
	return *this;
}

void Brain::AddIdea(std::string idea)
{
	_ideas_arr[_i % 100] = idea;
	_i++;
}

void Brain::Print_idea(void) const
{
	for (int i = 0; i < _i; i++)
	{
		std::cout<< _ideas_arr[i] << std::endl;
	}
}