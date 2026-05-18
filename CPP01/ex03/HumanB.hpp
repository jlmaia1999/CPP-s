/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:37:23 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 17:54:55 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
		private:
			std::string _name;
			Weapon *_weapon;
		public:
			HumanB(std::string name);
			~HumanB();
			void attack();
			void setWeapon(Weapon& weapon);
};

#endif