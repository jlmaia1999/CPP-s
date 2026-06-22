/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 13:45:01 by jomaia            #+#    #+#             */
/*   Updated: 2026/06/22 14:45:40 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_mode;
	public:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap&copy);
		ScavTrap &operator= (const ScavTrap &copy);
		~ScavTrap();

		void guardGate();
		void attack(const std::string name);
};

#endif