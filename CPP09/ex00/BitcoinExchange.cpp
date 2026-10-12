#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

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

bool BitcoinExchange::isOpen(char *filename)
{
	file.open(filename, std::ios::in);
	if (!file)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 0;
	}
	return 1;
}

static std::string infoTrim(std::string const& s)
{
	std::string::size_type start = s.find_first_not_of(" \t\n");
	std::string::size_type end = s.find_last_not_of(" \t\n");

	if (start == std::string::npos)
		return ("");
	return (s.substr(start, end - start + 1));
}

static bool validateDate(std::string &date)
{
	std::istringstream stream(date);
	int	year, month, day;
	char	sep1, sep2;

	if (date.size() != 10)
		return false;
	if ()
}

bool BitcoinExchange::createMap()
{
	std::string buffer;
	std::string date;
	std::string e_rate_str;
	std::string::size_type separator;
	float		e_rate;
	if (!isOpen("data.csv"))
		return 0;
	std::getline(file, buffer);
	if (buffer != "date,exchange_rate")
		return (file.close(), 0);
	while (std::getline(file, buffer))
	{
		separator = buffer.find(",");
		if (separator == std::string::npos)
			return(file.close(), 0);
		date = infoTrim(buffer.substr(0, separator));
		e_rate_str = infoTrim (buffer.substr(separator + 1));

	}
}