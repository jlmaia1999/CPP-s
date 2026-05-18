/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 17:40:00 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 14:39:41 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "Contact.hpp"

class Phonebook
{
	private:
		Contact _contacts[8];
		int _last_contact;
	public:
		Phonebook();
		~Phonebook();
		void Add();
		void Search();
		void set_last();
};

#endif