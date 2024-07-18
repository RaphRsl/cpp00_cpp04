// FORME CACONIQUE - Coplien's form

	// HPP








// CONST

- When const is at the end of the member function declaration, it means that the function does not modify the state of the object.
This means that none of the member variables can be changed within that function. These functions can be called on const objects.

	std::string const & getTitle() const;
	void introduce() const;

Here, getTitle and introduce promise not to modify any member variables of the Warlock object.

- When const is at the beginning of the function declaration (before the return type), it means the function returns a constant value.
This implies that the caller cannot modify the returned value directly.

	std::string const & getTitle() const;

In this case, getTitle returns a reference to a constant std::string, meaning the caller cannot modify the returned string directly.
This is important for protecting internal class data from being changed inadvertently.

- When const is used inside the parameter list, it means that the parameter is read-only within the function.
The function will not (and cannot) modify the value of this parameter. If the parameter is passed by reference, this can also help avoid unnecessary copying.

	void setTitle(std::string const & title);

Here, setTitle takes a constant reference to a std::string.
This means the function will not modify the input string title, and it also avoids copying the string, which is more efficient.

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

