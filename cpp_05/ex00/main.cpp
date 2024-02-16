
#include "Bureaucrat.hpp"

// ===== BASIC TESTS =====
void	testBasic(void)
{
	Bureaucrat	MrDupont("MrDupont", 88);

	std::cout << MrDupont << std::endl;
	std::cout << "=> Downgrade 1 time" << std::endl;
	MrDupont.downGrade();
	std::cout << MrDupont << std::endl;
	std::cout << "=> Upgrade 4 time" << std::endl;
	MrDupont.upGrade();
	MrDupont.upGrade();
	MrDupont.upGrade();
	MrDupont.upGrade();
	std::cout << MrDupont << std::endl;
}

// ===== EXCEPTIONS TEST LOW =====
void	testExceptionLow(void)
{
	Bureaucrat	MrDupont("MrDupont", 151);
}

// ===== EXCEPTIONS TEST HIGH =====
void	testExceptionHigh(void)
{
	Bureaucrat	MrDupont("MrDupont", 0);
}

// ===== DOWNGRADE TESTS =====
void	testDownGrade(void)
{
	Bureaucrat	MrDupont("MrDupont", 2);
	MrDupont.upGrade();
	std::cout << MrDupont << std::endl;
	MrDupont.upGrade();
}

// ===== UPGRADE TESTS =====
void	testUpGrade(void)
{
	Bureaucrat	MrDupont("MrDupont", 149);
	MrDupont.downGrade();
	std::cout << MrDupont << std::endl;
	MrDupont.downGrade();
}

// ===== MAIN =====
int	main(void)
{
	std::cout << "===== BASIC TESTS =====" << std::endl;
	try
	{
		testBasic();
	}
	catch (std::exception &except)
	{
		std::cerr << except.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "===== EXCEPTIONS TEST =====" << std::endl;
	try
	{
		testExceptionLow();
	}
	catch (std::exception &except)
	{
		std::cerr << except.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testExceptionHigh();
	}
	catch (std::exception &except)
	{
		std::cerr << except.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "===== DOWN/UPGRADE TESTS =====" << std::endl;
	try
	{
		testDownGrade();
	}
	catch (std::exception &except)
	{
		std::cerr << except.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		testUpGrade();
	}
	catch (std::exception &except)
	{
		std::cerr << except.what() << std::endl;
	}

	return (0);
}
