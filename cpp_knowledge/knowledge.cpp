// FORME CACONIQUE - Coplien's form

	// HPP









// REFERENCES, POINTERS, VALUES			(cpp_01/ex02)

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


// POINTERS OR REFERENCES?			(cpp_01/ex03)

	// ...


// FILES MANIPULATION			(cpp_01/ex04)

	// ...


// POINTER TO FUNCTIONS			(cpp_01/ex05)


void	Harl::debug(void)
{
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

// and other functions...

void	Harl::complain(std::string level)
{
	int	detectedLevel = levelDetector(level);
	void	(Harl::*levelFunctions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (detectedLevel == -1)
		std::cout << "Invalid level. Expected level are [DEBUG]/[INFO]/[WARNING]/[ERROR]." << std::endl;
	else
		(this->*levelFunctions[detectedLevel])();
}


// SWITCH CASE			(cpp_01/ex06)

