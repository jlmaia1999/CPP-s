/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:36:08 by jomaia            #+#    #+#             */
/*   Updated: 2026/05/27 11:33:37 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <cstdlib>
#include <fstream>
# include <iostream>
# include <cstring>
#include <iomanip>

bool	check_input(char *argv)
{
	if (!argv[0])
		return 0;
	return 1;
}

std::string replace(std::string line, std::string tofind, std::string replace)
{
	size_t pos = 0;
	size_t len = tofind.length();

	while(line.find(tofind) != std::string::npos)
	{
		pos = line.find(tofind);	
		line.erase(pos, len);
		line.insert(pos, replace);
		pos += replace.length();
	}
	return line;
}

int main(int argc, char **argv)
{
	std::string s1;
	std::string s2;
	std::ifstream inputFile (argv[1]);
	std::string aux = argv[1];
	std::string outfile = aux + ".replace";
	std::ofstream outputFile (outfile.c_str());
	std::string line;
	
	if (argc != 4)
		return 0;
	for(int i = 1; i < argc - 1; i++)
		if (!check_input(argv[i]))
			return 0;
	s1 = argv[2];
	s2 = argv[3];

	if (!inputFile.is_open())
	{
		std::cout << "Could not open file" << std::endl;
		return 0;
	}
	while(std::getline(inputFile, line))
	{
		line = replace(line, s1, s2);
		outputFile << line << std::endl;
	}
	inputFile.close();
	return 0;
}
