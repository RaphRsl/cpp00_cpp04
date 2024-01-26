#include <iostream>
#include <string>

int	main(void)
{
	std::string	str;
	str = "HI THIS IS BRAIN";

	std::string *stringPTR;
	stringPTR = &str;

	std::string &stringREF(str);

	std::cout << "1 - Memory adress of the string variable: " << &str << std::endl;
	std::cout << "    Memory adress held by stringPTR: " << stringPTR << std::endl;
	std::cout << "    Memory adress held by stringREF: " << &stringREF << std::endl;
	
	std::cout << "2 - Value of the string variable: " << str << std::endl;
	std::cout << "    Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "    Value pointed to by stringREF: " << stringREF << std::endl;

	return (0);
}