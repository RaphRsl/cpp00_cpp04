#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", 145, 137), _target("NoTarget")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyForm)
{
	*this = shrubberyForm;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyForm)
{
	(void)shrubberyForm;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	std::ofstream	file;

	this->AForm::executeCheck(bureaucrat);
	file.open((_target + "_shrubbery").c_str());
	if (file.good() == false)
		throw FileOpeningFail(); //CHANGE TREES
	file << "               ,@@@@@@@,                                                ,@@@@@@@,                  " << std::endl;
    file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.                            ,,,.   ,@@@@@@/@@,  .oo8888o.      " << std::endl;
    file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888888/8o                        ,&%%&%&&%,@@@@@/@@@@@@,8888888/8o     " << std::endl;
    file << "   ,%&&%&&%&&%,@@@@@@@/@@@88888888/88'                      ,%&%%&&%&&%,@@@@@@@/@@@88888888/88'    " << std::endl;
    file << "   %&&%&%&/%&&%@@@@@/ /@@@88888888888'    ____________      %&&%&%&/%&&%@@@@@/ /@@@88888888888'    " << std::endl;
    file << "   %&&%/ %&%%&&@@\\ V /@@' `8888 `/88'    |            |     %&&%/ %&%%&&@@@ V /@@' `8888 `/88'     " << std::endl;
    file << "   `&%\\ ` /%&'    |.|        \\ '|8'      |    " << _target << "    |      `&%  ` /%&'    |.|        \\ '|8'       " << std::endl;
    file << "       |o|        | |         | |        |____________|         |o|        | |         | |         " << std::endl;
    file << "       |.|        | |         | |              ||               |.|        | |         | |         " << std::endl;
	file << "_\\_ \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_  __   _||_   _   _\\_ \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_ " << std::endl;
	file.close();
}
