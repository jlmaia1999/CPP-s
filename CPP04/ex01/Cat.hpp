/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:28:00 by jomaia            #+#    #+#             */
/*   Updated: 2026/06/26 15:36:42 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
		void makeSound() const;
};

#endif