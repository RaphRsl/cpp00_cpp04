
#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signed;
		
	public:
		Form(void);
		Form(const std::string name, int gradeSign, int gradeExec);
		Form(const Form &form);
		virtual ~Form();

		Form	&operator=(const Form &form);

		const std::string	getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				getSigned(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("grade is too high"); }
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw() { return ("grade is too low"); }
		};
};

std::ostream	&operator<<(std::ostream &o, const Form &form);

#endif
