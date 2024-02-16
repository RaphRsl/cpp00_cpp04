#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	if (VERBOSE)
		std::cout << overlayPrint("Ice", MAC_CONSTRUCT, LIGHTGREY) << "constructor called" << std::endl;
}

Ice::Ice(const Ice &ice) : AMateria(ice)
{
	if (VERBOSE)
		std::cout << overlayPrint("Ice", MAC_COPY, LIGHTGREY) << "copy constructor called" << std::endl;
	*this = ice;
}

Ice::~Ice()
{
	if (VERBOSE)
		std::cout << overlayPrint("Ice", MAC_DESTRUCT, RED) << "destructor called" << std::endl;
}

Ice	&Ice::operator=(const Ice &ice)
{
	(void)ice;
	return (*this);
}

Ice		*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
