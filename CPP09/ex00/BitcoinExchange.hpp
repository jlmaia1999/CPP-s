#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <sstream>

class BitcoinExchange{
	private:
		std::map<std::string, float> data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		bool isOpen(char *filename);
		bool createMap();
		std::fstream file;
		
};
