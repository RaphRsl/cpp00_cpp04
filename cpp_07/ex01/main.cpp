#include "iter.hpp"
#include <iostream>
#include <cctype>

void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

void ft_double(int &arr)
{
	arr *= 2;
}

int main()
{
	std::cout << "===== ARRAY OF CHAR =====" << std::endl;
	char c[] = {'T', 'E', 'S', 'T'};

	std::cout << "Before changes:" <<
	"\n\tc[0]: " << c[0] <<
	"\n\tc[1]: " << c[1] <<
	"\n\tc[2]: " << c[2] <<
	"\n\tc[3]: " << c[3] <<
	std::endl << std::endl;

	::iter(c, sizeof(c) / sizeof(char), ft_tolower);

	std::cout << "After changes - tolower" <<
	"\n\tc[0]: " << c[0] <<
	"\n\tc[1]: " << c[1] <<
	"\n\tc[2]: " << c[2] <<
	"\n\tc[3]: " << c[3] <<
	std::endl << std::endl;

	::iter(c, 2, ft_toupper);

	std::cout << "After changes - toupper" <<
	"\n\tc[0]: " << c[0] <<
	"\n\tc[1]: " << c[1] <<
	"\n\tc[2]: " << c[2] <<
	"\n\tc[3]: " << c[3] <<
	std::endl << std::endl;

	std::cout << "===== ARRAY OF INT =====" << std::endl;
	int a[] = {1, 2, 3};

	std::cout << "Before changes:" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;

	::iter(a, sizeof(a) / sizeof(int), ft_double);

	std::cout << "After changes - twice" <<
	"\n\ta[0]: " << a[0] <<
	"\n\ta[1]: " << a[1] <<
	"\n\ta[2]: " << a[2] <<
	std::endl << std::endl;

	return 0;
}