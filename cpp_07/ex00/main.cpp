
#include "whatever.hpp"
#include <iostream>

void	floats_tests()
{
// FLOATS
	std::cout << "===== MIN / MAX TESTS - floats =====" << std::endl;
	float	x = 24.424f;
	float	y = 42.242f;

	std::cout << "x = " << x << "\ty = " << y << std::endl;
	std::cout << "\tThe min is: " << ::min(x, y) << std::endl;

	std::cout << "\tThe max is: " << ::max(x, y) << std::endl;

	std::cout << std::endl;
	std::cout << "===== SWAP TEST - floats =====" << std::endl;

	std::cout << "Before swap\n\tx = " << x << "\n\ty = " << y << std::endl;
	::swap(x, y);
	std::cout << "After swap\n\tx = " << x << "\n\ty = " << y << std::endl;
	std::cout << std::endl;
}

void	string_tests()
{
// STRINGS
	std::cout << "===== MIN / MAX TESTS - strings =====" << std::endl;
	std::string	a = "String A";
	std::string b = "String B";

	std::cout << "String A = " << a << "\t String B = " << b << std::endl;
	std::cout << "\tThe min is: " << ::min(a, b) << std::endl;
	std::cout << "\tThe max is: " << ::max(a, b) << std::endl;

	std::cout << std::endl;
	std::cout << "===== SWAP TEST - strings =====" << std::endl;
	std::cout << "Before swap\n\tString A = " << a << "\n\tString B = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap\n\tString A = " << a << "\n\tString B = " << b << std::endl;
}
int	main()
{
	floats_tests();
	string_tests();
	return (0);
}
