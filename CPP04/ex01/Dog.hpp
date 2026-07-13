/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:24:42 by jomaia            #+#    #+#             */
/*   Updated: 2026/06/26 15:36:52 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
		void makeSound() const;
};

#endif