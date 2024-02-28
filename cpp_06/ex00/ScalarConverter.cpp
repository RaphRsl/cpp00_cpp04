
#include "ScalarConverter.hpp"

/* --- CONSTRUCTORS - DESTRUCTOR - COPY - OPERATOR "=" --- */

ScalarConverter::ScalarConverter()
{
	std::cout << "// ScalarConverter - default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string input): _input(input)
{
	std::cout << "// ScalarConverter - constructor : " << this->getInput() << std::endl;
	this->_double = atof(this->getInput().c_str());
	this->convertInput();
	this->printOutput();
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "// ScalarConverter - destructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src): _input(src.getInput())
{
	std::cout << "// ScalarConverter - copy constructor" << std::endl;
	*this = src;
	this->printOutput();
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	std::cout << "// ScalarConverter - operator '='" << std::endl;
	if (this == &src)
		return *this;

	this->_type = src.getType();
	this->_char = src.getChar();
	this->_int = src.getInt();
	this->_float = src.getFloat();
	this->_double = src.getDouble();
	return *this;
}

/* --- PRIVATE METHODS --- */

/* CHECKER */
int	ScalarConverter::checkInput()
{
/* check if inf or nan */
	if (this->getInput().compare("nan") == 0 || this->getInput().compare("+inf") == 0 || this->getInput().compare("-inf") == 0 || this->getInput().compare("+inff") == 0 || this->getInput().compare("-inff") == 0)
	{
		return (NAN_INF);
	}
/* check if just 1 char */
	else if (this->getInput().length() == 1 && (this->getInput()[0] == '+' || this->getInput()[0] == '-' || this->getInput()[0] == 'f' || this->getInput()[0] == '.'))
	{
		return (CHAR);
	}
/* check if mix of + and - */
	else if (this->getInput().find_first_of("+-") != this->getInput().find_last_of("+-"))
		return (ERROR);
/* check if only int */
	else if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);
/* check if [..] or [x. ] or [.x] or double */
	else if (this->getInput().find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (this->getInput().find_first_of(".") != this->getInput().find_last_of(".") || isdigit(this->getInput()[this->getInput().find_first_of(".") + 1]) == false || this->getInput().find_first_of(".") == 0)
			return (ERROR);
		else
			return (DOUBLE);
	}
/* check if [ff] or [..] or [x.f] or [.xf] or [x.xfx] or float */
	else if (this->getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (this->getInput().find_first_of("f") != this->getInput().find_last_of("f") || this->getInput().find_first_of(".") != this->getInput().find_last_of(".") || this->getInput().find_first_of("f") - this->getInput().find_first_of(".") == 1 || this->getInput().find_first_of(".") == 0 || this->getInput()[this->getInput().find_first_of("f") + 1] != '\0')
			return (ERROR);
		else
			return (FLOAT);
	}
/* check if 1 char */
	else if ((this->getInput().length() == 1 && std::isprint(this->getInput()[0])) || (this->getInput().length() == 1 && std::isalpha(this->getInput()[0])))
	{
		return (CHAR);
	}
/* everything else ERROR */
	else
		return (ERROR);
}

/* CONVERTERS */
void ScalarConverter::fromChar(void)
{
	this->_char = static_cast<unsigned char>(this->getInput()[0]);
	this->_int = static_cast<int>(this->getChar());
	this->_float = static_cast<float>(this->getChar());
	this->_double = static_cast<double>(this->getChar());
}
void ScalarConverter::fromInt(void)
{
	this->_int = static_cast<int>(this->getDouble());
	this->_char = static_cast<unsigned char>(this->getInt());
	this->_float = static_cast<float>(this->getDouble());
}
void ScalarConverter::fromFloat(void)
{
	this->_float = static_cast<float>(this->getDouble());
	this->_char = static_cast<char>(this->getFloat());
	this->_int = static_cast<int>(this->getFloat());
}
void ScalarConverter::fromDouble(void)
{
	this->_char = static_cast<char>(this->getDouble());
	this->_int = static_cast<int>(this->getDouble());
	this->_float = static_cast<float>(this->getDouble());
}

/* CONVERTERS CALLER */
void	ScalarConverter::convertInput(void)
{
	void (ScalarConverter::*func_ptrs[])(void) =\
		{&ScalarConverter::fromChar,\
		&ScalarConverter::fromInt,\
		&ScalarConverter::fromFloat,\
		&ScalarConverter::fromDouble};
	int types[] = {CHAR, INT, FLOAT, DOUBLE};

	this->_type = checkInput();

	if (this->getType() == NAN_INF)
		return ;
	int i;
	for (i = 0; i < 4; i++)
	{
		if (this->getType() == types[i])
		{
			(this->*func_ptrs[i])();
			break ;
		}
	}
	if (i == 4)
		throw ScalarConverter::ErrorException();
}

/* PRINTER */
void	ScalarConverter::printOutput(void)const
{
	/* char */
	if (this->getType() != NAN_INF && this->getDouble() <= UCHAR_MAX && this->getDouble() >= 0)
	{
		if (isprint(this->getChar()))
			std::cout << "char: '" << this->getChar() << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	/* int */
	if (this->getType() != NAN_INF && this->getDouble() >= std::numeric_limits<int>::min() && this->getDouble() <= std::numeric_limits<int>::max())
	{
		std::cout << "int: " << this->getInt() << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;

	/* float */
	if (this->getType() != NAN_INF)
	{
		std::cout << "float: " << this->getFloat();
		if (this->getFloat() - this->getInt() == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	else
	{
		if (this->getInput() == "nan" || this->getInput() == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (this->getInput()[0] == '+')
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}

	/* double */
	if (this->getType() != NAN_INF)
	{
		std::cout << "double: " << this->getDouble();
		if (this->getDouble() < std::numeric_limits<int>::min() || this->getDouble() > std::numeric_limits<int>::max() ||
			this->getDouble() - this->getInt() == 0)
		{
			std::cout << ".0" << std::endl;
		}
		else
			std::cout << std::endl;
	}
	else
	{
		if (this->getInput() == "nan" || this->getInput() == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (this->getInput()[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
}

/* GETTERS */
std::string	ScalarConverter::getInput(void)const
{
	return (this->_input);
}

int	ScalarConverter::getType(void)const
{
	return (this->_type);
}

char	ScalarConverter::getChar(void)const
{
	return (this->_char);
}

int	ScalarConverter::getInt(void)const
{
	return (this->_int);
}

float	ScalarConverter::getFloat(void)const
{
	return (this->_float);
}

double ScalarConverter::getDouble(void)const
{
	return (this->_double);
}

/* EXCEPTIONS */
const char *ScalarConverter::ErrorException::what(void) const throw()
{
	return ("Error: The input is impossible to print or not convertable...");
};
