/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 14:23:47 by jomaia            #+#    #+#             */
/*   Updated: 2026/06/26 15:35:11 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
};

#endif
