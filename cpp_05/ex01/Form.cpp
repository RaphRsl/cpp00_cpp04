
#include "Form.hpp"

Form::Form(void) : _name("badForm"), _gradeSign(150), _gradeExec(150), _signed(false)
{
	return ;
}

Form::Form(const std::string name, int gradeSign, int gradeExec) :
	_name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &form) : _name(form._name), _gradeSign(form._gradeSign), _gradeExec(form._gradeExec)
{
	*this = form;
}

Form::~Form()
{
	return ;
}

Form	&Form::operator=(const Form &form)
{
	if (this != &form)
		_signed = form._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Form &form)
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

const std::string	Form::getName(void) const
{
	return (_name);
}

int		Form::getGradeSign(void) const
{
	return (_gradeSign);
}

int		Form::getGradeExec(void) const
{
	return (_gradeExec);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}
