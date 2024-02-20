#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form 		form("form51", 33, 9);
	Bureaucrat	mrDupont("MrDupont", 34);

	std::cout << form << std::endl;
	std::cout << mrDupont << std::endl;
	
	mrDupont.signForm(form);
	std::cout << mrDupont.getName() << " gets a promotion !" << std::endl;
	mrDupont.upGrade();
	mrDupont.signForm(form);

	std::cout << std::endl << form << std::endl;

	return (0);
}
