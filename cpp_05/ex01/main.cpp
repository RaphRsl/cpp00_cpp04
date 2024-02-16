#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form 		form("contract", 33, 9);
	Bureaucrat	MD("MrDupont", 34);

	std::cout << form << std::endl;
	std::cout << MD << std::endl;
	
	MD.signForm(form);
	MD.upGrade();
	MD.signForm(form);

	std::cout << std::endl << form << std::endl;

	return (0);
}
