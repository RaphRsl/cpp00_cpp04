#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("randomBureaucrat"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
	{
		_grade = bureaucrat._grade;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (o);
}

const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::upGrade(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::downGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception &except)
	{
		std::cout << _name << " couldn't sign " << form.getName() <<  " because " << except.what() << std::endl;
	}
}