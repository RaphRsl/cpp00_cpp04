#include "AMateria.hpp"

AMateria::AMateria(void) : _type("unknow_type")
{
	return ;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	return;
}

AMateria::AMateria(const AMateria &aMateria)
{
	*this = aMateria;
}

AMateria::~AMateria()
{
	return;
}

AMateria	&AMateria::operator=(const AMateria &aMateria)
{
	if (this != &aMateria)
		_type = aMateria._type;
	return (*this);
}

std::string const	&AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "is acting on " << target.getName() << std::endl;
}

std::string		overlayPrint(const std::string str, std::string mac, const std::string color, int size)
{
	std::string	name = str;

	if (str == "")
		return (std::string(size + 1, ' '));
	if (name.size() > (unsigned)size - 2)
		name = '[' + name.substr(0, size - 5) + '.' + ']' + " " + mac;
	else
		name = '[' + name + ']' + " " + mac;
	return (std::string(size - name.size(), ' ') + color + name + " " + END);
}