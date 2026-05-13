/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:40:00 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/13 17:49:14 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

class Phonebook
{
	private:
		Contact _contacts[8];
	public:
		Phonebook();
		~Phonebook();
		void Add();
		void Search();
};