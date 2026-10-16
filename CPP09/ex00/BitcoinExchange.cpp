#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	createMap();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->data = other.data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

const char *BitcoinExchange::OFException::what() const throw()
{
	return "Could not open file";
}

const char *BitcoinExchange::RFException::what() const throw()
{
	return "Could not read file";
}

const char *BitcoinExchange::IDException::what() const throw()
{
	return "Invalid date format";
}

const char *BitcoinExchange::IHException::what() const throw()
{
	return "Invalid header format";
}

const char *BitcoinExchange::DBErrorException::what() const throw()
{
	return "Database error";
}

void BitcoinExchange::isOpen(char *filename)
{
	file.open(filename, std::ios::in);
	if (!file)
		throw OFException();
}

void BitcoinExchange::readDB(std::string fileName)
{
	std::ifstream file(fileName.c_str());
	std::string::size_type seperator;
	float		value;
	if (!file)
		throw OFException();
	std::string buffer;
	std::getline(file, buffer);
	if (buffer != "date | value")
		throw IHException();
	while (std::getline(file, buffer))
	{
		seperator = buffer.find(" | ");
		if (seperator == std::string::npos)
		{
			std::cout << "bad input => " << buffer << std::endl;
			continue ;
		}
		tm t;
		memset(&t, 0, sizeof(tm));
		std::string date = buffer.substr(0, seperator);
		if (!strptime(date.c_str(), "%Y-%m-%d", &t))
		{
			std::cout << "bad input => " << date << std::endl;
			continue;
		}
		std::istringstream value_str(buffer.substr(seperator + 3));
		value_str >> value;
		if (value_str.fail() || !value_str.eof())
		{
			std::cout << "bad input => " << value_str.str() << std::endl;
			continue;
		}
		if (value < 0.0f)
		{
			std::cout << "not a positive number" << std::endl;
			continue;
		}
		if (value > 1000.0f)
		{
			std::cout << "number too large" << std::endl;
			continue;
		}
		time_t tm = mktime(&t);
		std::map<time_t, float>::iterator it = data.lower_bound(tm);
		if (it != data.end() && it->first == tm)
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		else if (it != data.begin())
		{
			it--;
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		}
		else
			std::cout << "No corresponding date (too early)" << std::endl;
	}
}

void BitcoinExchange::createMap()
{
	std::ifstream file("data.csv");
	if (!file)
		throw OFException();
	std::string buffer;
	std::string::size_type separator;
	tm t;
	memset(&t, 0, sizeof(tm));
	float		e_rate;
	std::getline(file, buffer);
	if (buffer != "date,exchange_rate")
		throw IHException();
	while (std::getline(file, buffer))
	{
		separator = buffer.find(",");
		if (separator == std::string::npos)
			throw RFException();
		if (!strptime(buffer.substr(0, separator).c_str(), "%Y-%m-%d", &t))
			throw IDException();
		std::istringstream e_rate_str(buffer.substr(separator + 1));
		e_rate_str >> e_rate;
		if (e_rate_str.fail() || !e_rate_str.eof())
			throw RFException();
		std::size_t size = data.size();
		data.insert(std::make_pair(mktime(&t), e_rate));
		if (size == data.size())
			throw DBErrorException();
	}
	if (!file.eof())
		throw DBErrorException();
}
