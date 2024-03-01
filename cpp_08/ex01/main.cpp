
#include "Span.hpp"

void smallSpan()
{
	Span small = Span(5);
	for (size_t i = 0; i < 5; i++)
	{
		try
		{
			small.addNumber(2*i);
		}
		catch (std::exception &e)
		{
			std::cerr << "\tWhile adding number [" << i << "] - " << e.what() << std::endl;
		}
	}
	if (PRINTSMALLSTORAGE)
	{
		std::cout << "--> Small span storage: ";
		small.printStorage();
	}
	std::cout << "--> Tryint to add a 6th number: " << std::endl;
	int j = 6;
	try
	{
		small.addNumber(j);
	}
	catch (std::exception &e)
	{
			std::cerr << "\tWhile adding number [" << j << "] - " << e.what() << std::endl;
	}
	try
	{
		std::cout << "--> Shortest span is " << small.shortestSpan() << std::endl;
		std::cout << "--> Longest span is " << small.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "\tWhile calculating span: " << e.what() << std::endl;
	}
}

void largeSpan()
{
	Span large = Span(15000);
	large.rngAddNumbers(15002, time(0));
	if (PRINTBIGSTORAGE)
	{
		std::cout << "--> Large span storage: ";
		large.printStorage();
	}
	try
	{
		std::cout << "--> Shortest span is " << large.shortestSpan() << std::endl;
		std::cout << "--> Longest span is " << large.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "\tWhile calculating span: " << e.what() << std::endl;
	}
}

void spanOfSize1()
{
	Span one = Span(1);
	try
	{
		one.addNumber(1);
	}
	catch (std::exception &e)
	{
		std::cerr << "\tWhile adding number [1] - " << e.what() << std::endl;
	}
	std::cout << "--> Tryint to add a 2nd number: " << std::endl;
	try
	{
		one.addNumber(2);
	}
	catch (std::exception &e)
	{
		std::cerr << "\tWhile adding number [2] - " << e.what() << std::endl;
	}
	std::cout << "--> Span of size 1 storage: ";
	one.printStorage();
	try
	{
		one.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cerr << "\tWhile calculating shortest span: " << e.what() << std::endl;
	}
	try
	{
		one.longestSpan();
	}
	catch (std::exception &e)
	{
		std::cerr << "\tWhile calculating longest span: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "===== SMALL SPAN =====" << std::endl;
	smallSpan();
	std::cout << std::endl;
	std::cout << "===== LARGE SPAN =====" << std::endl;
	largeSpan();
	std::cout << std::endl;
	std::cout << "===== SPAN OF SIZE 1 =====" << std::endl;
	spanOfSize1();
	std::cout << std::endl;
    return 0;
}