#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>

int	main(void)
{
	std::cout << "===== Shrubbery =====" << std::endl;

	AForm		*shrubbery = new ShrubberyCreationForm("home");
	Bureaucrat	mrDupont("MrDupont", 1);
	Bureaucrat	mmeMartin("MmeMartin", 140);

	std::cout << mrDupont << std::endl;
	std::cout << *shrubbery << std::endl;
	mrDupont.executeForm(*shrubbery);
	mrDupont.signForm(*shrubbery);
	std::cout << *shrubbery << std::endl;
	mrDupont.executeForm(*shrubbery);
	std::cout << mmeMartin << std::endl;
	mmeMartin.executeForm(*shrubbery);
	delete shrubbery;
	std::cout << std::endl;


	std::cout << "===== Robotomy =====" << std::endl;

	AForm		*robotomy = new RobotomyRequestForm("MrDupont");
	Bureaucrat	mrRobert("MrRobert", 1);

	std::cout << mrRobert << std::endl;
	std::cout << *robotomy << std::endl;
	mrRobert.executeForm(*robotomy);
	mrRobert.signForm(*robotomy);
	mrRobert.executeForm(*robotomy);
	mrRobert.executeForm(*robotomy);
	mrRobert.executeForm(*robotomy);
	mrRobert.executeForm(*robotomy);
	delete robotomy;
	std::cout << std::endl;
	
	
	std::cout << "===== Presidential Pardon =====" << std::endl;

	AForm		*presidential = new PresidentialPardonForm("MrDupont");
	Bureaucrat	mmeDurand("MmeDurand", 6);

	std::cout << mmeDurand << std::endl;
	std::cout << *presidential << std::endl;
	mmeDurand.executeForm(*presidential);
	mmeDurand.signForm(*presidential);
	mmeDurand.executeForm(*presidential);
	std::cout << mmeDurand.getName() << " gets a promotion!" << std::endl;
	mmeDurand.upGrade();
	mmeDurand.executeForm(*presidential);
	delete presidential;

	return (0);
}
