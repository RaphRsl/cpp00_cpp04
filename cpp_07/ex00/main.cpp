
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

/*

The :: operator is used to specify the global namespace.
In your case, you have defined min, max, and swap functions in your whatever.hpp file.
These functions are template functions and can work with any data type.

When you include whatever.hpp in your main file, these functions become part of
the global namespace. Therefore, when you call min, max, or swap without ::,
the compiler will use the versions from whatever.hpp.

However, the std namespace also contains min, max, and swap functions.
When you use std::string, the compiler prefers the min, max, and swap
functions from the std namespace over the ones in the global namespace.
This is due to Argument-Dependent Lookup (ADL), a feature in C++ where the compiler
also considers functions in the namespace of the arguments.

To force the compiler to use your versions of min, max, and swap,
you need to use the :: operator to specify the global namespace.
This is why you need to use ::min(a, b) and ::max(a, b) for strings, but not
for floats. For floats, there is no min and max in the std namespace that takes two floats,
so the compiler uses your versions without needing ::.

*/