/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:39:41 by jomaia            #+#    #+#             */
/*   Updated: 2026/07/01 16:42:46 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCAT_HPP
# define WrongCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat();
		void makeSound() const;
};

#endif