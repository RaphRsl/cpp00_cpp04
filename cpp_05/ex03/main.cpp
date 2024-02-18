#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iomanip> // USE ?

int	main(void) // CHECK AND CLEAN MAIN IF NEEDED.. add a wrong 0,5 form ?
{
	srand(time(NULL)); //USE ?

	std::cout << "===== SUBJECT TEST =====" << std::endl;
	Intern  someRandomIntern;
    AForm*   rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << std::endl;

	std::cout << "===== MORE TESTS =====" << std::endl;
	Bureaucrat	pres("President", 1);
	Intern		exploitedIntern;
	AForm		*forms[4];

	forms[0] = exploitedIntern.makeForm("shrubbery creation", "Trg1");
	forms[1] = exploitedIntern.makeForm("robotomy request", "Target2");
	forms[2] = exploitedIntern.makeForm("presidential pardon", "Target3");
	forms[3] = exploitedIntern.makeForm("formular", "Target4");

	for (int i = 0; i < 4; i++)
	{
		if (forms[i])
		{
			std::cout << std::endl << *(forms[i]);
			pres.signForm(*(forms[i]));
			pres.executeForm(*(forms[i]));
		}
	}

	for (int i = 0; i < 4; i++)
		delete forms[i];
	std::cout << std::endl;
	return (0);
}
