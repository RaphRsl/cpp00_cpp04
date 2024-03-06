#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	if (VERBOSE)
		std::cout << "Default constructor" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& bitExch)
{
	if (VERBOSE)
		std::cout << "Copy constructor" << std::endl;
    *this = bitExch;
	return ;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& bitExch)
{
	if (VERBOSE)
		std::cout << "Operator =" << std::endl;
    this->dataBase = bitExch.dataBase;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (VERBOSE)
		std::cout << "Destructor" << std::endl;
	return ;
}

float BitcoinExchange::getMatchingExchRate(const std::string& date)
{
    if (this->dataBase.count(date) > 0)
	{
        return this->dataBase.at(date);
	}
	std::map<std::string, float>::iterator it = this->dataBase.lower_bound(date);
    if (it == this->dataBase.begin())
	{
        std::cerr << "(Error: No exchange rate available for this date, set to 0) " << std::flush;
		return (0);
	}
    return (--it)->second;
}

static unsigned int ft_strtouint(const std::string& str)
{
    unsigned int num;
    std::stringstream strStream(str);

    strStream >> num;
    return num;
}

float ft_strtof(const std::string& str)
{
    float num;
    std::stringstream strStream(str);

    strStream >> num;
    return num;
}

bool BitcoinExchange::checkDateFormat(const std::string &date)
{
	if (date.empty())
		return false;

 	size_t firstDelim = date.find('-');
    size_t secondDelim = date.find('-', firstDelim + 1);

	if (firstDelim == std::string::npos || secondDelim == std::string::npos || date.find_first_not_of("0123456789.-") != std::string::npos)
	{
		std::cerr << "\tError: bad input date => " << "\"" << date << "\"" << '\n';
		return false;
	}
	return true;
}

bool BitcoinExchange::checkDateValid(const std::string& date)
{
	std::string str;
	int year, month, day;
	std::istringstream strStream(date);
	int dateParts = 1;

	while (std::getline(strStream, str, '-'))
	{
		if (dateParts == 1)
		{
			year = ft_strtouint(str);
			if (year < 2009 || year > 2022)
			{
				std::cerr << "\tError: invalid year (outside the data.csv) => " << "\"" << year << "\"" << " (" << date << ")" << '\n';
				return false;
			}
		}
		if (dateParts == 2)
		{
			month = ft_strtouint(str);
			if (month < 1 || month > 12)
			{
				std::cerr << "\tError: invalid month => " << "\"" << month << "\"" << " (" << date << ")" << '\n';
				return false;
			}
		}
		if (dateParts == 3)
		{
			day = ft_strtouint(str);
			if ((day < 1 || day > 31)
				||  (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
				||  (day > 28 && month == 2 && year % 4 != 0))
			{
				std::cerr << "\tError: invalid day => " << "\"" << day << "\"" << " (" << date << ")" << '\n';
				return false;
			}
		}
		dateParts += 1;
	}
	if (dateParts != 4)
	{
		std::cerr << "\tError: invalid date => " << "\"" << date << "\"" << '\n';
		return false;
	}
	return true;
}
bool BitcoinExchange::checkExchrateValid(const std::string& exchRate,  const std::string& date)
{
	if (exchRate.empty()
		|| exchRate.find_first_not_of("0123456789.-") != std::string::npos
		|| exchRate.find_first_not_of("0123456789.", 1) != std::string::npos
		|| exchRate.at(0) == '.'
		|| exchRate.at(exchRate.length() - 1) == '.'
		|| std::count(exchRate.begin(), exchRate.end(), '.') > 1)
		std::cerr << "\tError: invalid exchRate => " << "\"" << exchRate << "\"" << " (" << date << ")" << std::endl;
	else if (exchRate.at(0) == '-')
		std::cerr << "\tError: invalid negative exchRate => " << "\"" << exchRate << "\"" << " (" << date << ")" << std::endl;
	else if (exchRate.length() > 10 || (exchRate.length() == 10 && exchRate > "2147483647"))
		std::cerr << "\tError: exchRate is too large => " << "\"" << exchRate << "\"" << " (" << date << ")" << std::endl;
	else
		return true;
	return false;
}

void BitcoinExchange::parseDataCsv(std::ifstream& data_csv)
{
    std::string line;
    size_t delimPos;

    std::getline(data_csv, line);
    while (std::getline(data_csv, line))
    {
        delimPos = line.find(',');
        std::string exchRate = line.substr(delimPos + 1);
		std::string date = line.substr(0, delimPos);
    	this->dataBase[date] = ft_strtof(exchRate);
		if (VERBOSE)
			std::cout << "Added: " << date << "," << this->dataBase[date] << std::endl;
	}
    data_csv.close();
}
