#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "BitcoinExchange.hpp"

#define DATA_CSV_FILE "./data.csv"

float ft_strtof(const std::string& str);

static int print_error(std::string error_str)
{
	std::cerr << error_str << "\n";
	return (EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return print_error("Error: expected syntax is:	./btc <input_file>");

	std::ifstream input_file(argv[1], std::ifstream::in);
	if (!input_file.is_open())
		return print_error("Error: could not open input file");

    std::ifstream data_csv(DATA_CSV_FILE, std::ifstream::in);
	if (!data_csv.is_open())
		return print_error("Error: fatal: could not open data.csv file");

	BitcoinExchange btc;
	btc.parseDataCsv(data_csv);

	std::string line;
    std::getline(input_file, line);
    while (std::getline(input_file, line))
    {
        size_t delimPos = line.find('|');
		if (delimPos == std::string::npos || line.length() < delimPos + 2)
		{
			std::cerr << "\tError: incorrect input line => " << "\"" << line << "\"" << std::endl;
			continue ;
		}

		std::string date = line.substr(0, delimPos - 1);
		if (!btc.checkDateFormat(date) || !btc.checkDateValid(date))
			continue;

        std::string str_exchRate = line.substr(delimPos + 2);
		if (!btc.checkExchrateValid(str_exchRate, date))
			continue;
		float float_exchRate = ft_strtof(str_exchRate);

		std::cout << date << " => " << float_exchRate << " = " << std::setprecision(3) << float_exchRate * btc.getMatchingExchRate(date) << std::endl;
    }
    input_file.close();
    data_csv.close();
	return EXIT_SUCCESS;
}
