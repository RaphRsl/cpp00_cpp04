
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip> //USE ?

int	main(void) //DO AGAIN MAIN
{
	srand(time(NULL));

	std::cout << "===== Shrubbery =====" << std::endl;
	AForm		*shrub = new ShrubberyCreationForm("home");
	Bureaucrat	corr("Correcteur", 1);
	Bureaucrat	me("Lucie", 140);

	corr.executeForm(*shrub);
	corr.signForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << corr << std::endl;
	corr.executeForm(*shrub);
	me.executeForm(*shrub);
	delete shrub;


	std::cout << "===== Robotomy =====" << std::endl;
	AForm		*robotomy = new RobotomyRequestForm("Correcteur");
	Bureaucrat	me2("Lucie", 1);

	me2.executeForm(*robotomy);
	me2.signForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	delete robotomy;
	
	
	std::cout << "===== Presidential Pardon =====" << std::endl;
	AForm		*presidential = new PresidentialPardonForm("Correcteur");
	Bureaucrat	me3("Lucie", 6);

	me3.executeForm(*presidential);
	me3.signForm(*presidential);
	me3.executeForm(*presidential);
	me3.upGrade();
	me3.executeForm(*presidential);
	delete presidential;

	return (0);
}
