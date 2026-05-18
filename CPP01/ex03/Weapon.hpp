/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:48:58 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 17:54:24 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
# include <string>
# include <cstdlib>
# include <iostream>
# include <cstring>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon();
		std::string& getType();
		void setType(std::string type);
};

#endif