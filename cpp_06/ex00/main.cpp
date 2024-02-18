
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "\nExpected syntax: [./ScalarConverter <input_to_convert>]\n" << std::endl;
		return (1);
	}
	try
	{
		ScalarConverter scalarConverter(argv[1]);
	}
	catch(const ScalarConverter::ErrorException &except)
	{
		std::cerr << except.what() << std::endl;
	}
	return (0);
}
