/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:14:50 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 14:39:01 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <cstdlib>
# include <iostream>
# include <cstring>

class Contact
{
	private:
		std::string _first;
		std::string _last;
		std::string _number;
		std::string _nickname;
		std::string _secret;
	public:
		Contact();
		~Contact();
	
		std::string get_first();
		std::string get_last();
		std::string get_number();
		std::string get_nickname();
		std::string get_secret();
		
		void set_first(std::string first);
		void set_last(std::string last);
		void set_number(std::string number);
		void set_nick(std::string nick);
		void set_secret(std::string secret);
};

#endif