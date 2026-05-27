/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:06:08 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/19 13:11:12 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <cstdlib>
# include <iostream>
# include <cstring>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};
