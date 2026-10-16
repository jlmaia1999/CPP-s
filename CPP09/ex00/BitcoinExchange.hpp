#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <exception>
#include <cstring>

class BitcoinExchange{
	private:
		std::map<time_t, float> data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void isOpen(char *filename);
		void createMap();
		void readDB(std::string fileName);
		std::fstream file;

		class OFException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class RFException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class IDException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class IHException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class DBErrorException : public std::exception
		{
			virtual const char *what() const throw();
		};
};
