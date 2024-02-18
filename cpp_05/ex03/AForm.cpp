
#include "AForm.hpp"

AForm::AForm(void) : _name("badForm"), _gradeSign(150), _gradeExec(150), _signed(false)
{
	return ;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExec) :
	_name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &form) : _name(form._name), _gradeSign(form._gradeSign), _gradeExec(form._gradeExec)
{
	*this = form;
}

AForm::~AForm()
{
	return ;
}

AForm	&AForm::operator=(const AForm &form)
{
	if (this != &form)
		_signed = form._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const AForm &form)
{
	o << "Contract name: " << form.getName() << std::endl;
	if (form.getSigned() == 0)
		o << "-> not signed" << std::endl;
	else
		o << "-> signed" << std::endl;
	o << "-> grade needed to sign : " << form.getGradeSign() << std::endl;
	o << "-> grade needed to execute : " << form.getGradeExec() << std::endl;
	return (o);
};

const std::string	AForm::getName(void) const
{
	return (_name);
}

int		AForm::getGradeSign(void) const
{
	return (_gradeSign);
}

int		AForm::getGradeExec(void) const
{
	return (_gradeExec);
}

bool	AForm::getSigned(void) const
{
	return (_signed);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::executeCheck(const Bureaucrat &bureaucrat) const
{
	if (!this->getSigned())
		throw AForm::ExecuteNotSigned();
	if (this->getGradeExec() < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
}
