
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequestForm", 72, 45), _target("NoTarget")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomy)
{
	*this = robotomy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomy)
{
	(void)robotomy;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	int	robotomized;

	this->AForm::executeCheck(bureaucrat);
	std::cout << "* VRRRRRR RRRRIII VRRRIIII * " << std::endl;
	robotomized = rand() % 2;
	if (robotomized)
		std::cout << "=> " << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << _target  << "'s robotomy failed..." << std::endl;
	
}
