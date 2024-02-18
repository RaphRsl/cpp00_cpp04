
#include "Intern.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern::~Intern()
{
	return ;
}

Intern	&Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

static const std::string	lowerStr(const std::string str)
{
	std::string	res;

	for (unsigned int i = 0; i < str.size(); i++)
		res += tolower(str[i]);
	return (res);
}

static AForm	*newShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*newRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*newPresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static int		getFormNumber(const std::string formName)
{
	std::string		formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int				choosen = -1;

	for (int i = 0; i < 3; i++)
	{
		if (lowerStr(formName) == formNames[i])
		{
			choosen = i;
			break;
		}
	}
	return (choosen);
}

AForm	*Intern::makeForm(const std::string formName, const std::string target) const
{
	constructorPtr	funCreations[3] = {&newShrubbery, &newRobotomy, &newPresidential};
	int				choosen;
	AForm			*formPtr = NULL;

	choosen = getFormNumber(formName);
	std::cout << "Intern";
	if (choosen >= 0)
	{
		formPtr = funCreations[choosen](target);
		std::cout << " creates " << formPtr->getName() << " form!" << std::endl;
	}
	else
		std::cout << " coudn't create " << formName << " because form's name was unknown..." << std::endl;
	return (formPtr);

}