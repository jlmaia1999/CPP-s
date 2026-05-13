/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:14:50 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/13 17:33:49 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact
{
	private:
		std::string _first;
		std::string _last;
		std::string _number;
		std::string _secret;
		
	public:
		Contact();
		~Contact();
	
		std::string get_first();
		std::string get_last();
		std::string get_number();
		std::string get_secret();
		
		void set_first(std::string first);
		void set_last(std::string last);
		void get_number(std::string number);
		void get_secret(std::string secret);
};