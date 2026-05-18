/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:20:50 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/18 16:26:42 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <cstdlib>
# include <iostream>
# include <cstring>

int main()
{
	std::cout << std::endl;
	std::string string = "HI THIS IS BRAIN";

	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "string adress" << &string << std::endl;
	std::cout << "stringPTR adress" << &stringPTR << std::endl;
	std::cout << "stringREF adress" << &stringREF << std::endl << std::endl;

	std::cout << "string value" << string << std::endl;
	std::cout << "stringPTR value" << stringPTR << std::endl;
	std::cout << "stringREF value" << stringREF << std::endl;
}