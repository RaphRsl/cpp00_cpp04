#include <cstdlib>
#include <iostream>
#include "RPN.hpp"

static int print_error(const std::string& str)
{
    std::cerr <<  str << std::endl;
    return EXIT_FAILURE;
}

int main(int argc, char **argv)
{
	if (argc != 2)
        return print_error("ERROR: wrong format, expected syntax =>   ./RPN [mathematic expression]");

	if (!RPN::check_valid(argv[1]))
        return print_error("ERROR: invalid expression");

    try {
        std::cout << RPN::calculate(argv[1]) << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
	return EXIT_SUCCESS;
}
