#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	if (VERBOSE)
		std::cout << overlayPrint("Cure", MAC_CONSTRUCT, LIGHTGREY) << "constructor called" << std::endl;
}

Cure::Cure(const Cure &cure) : AMateria(cure)
{
	if (VERBOSE)
		std::cout << overlayPrint("Cure", MAC_COPY, LIGHTGREY) << "copy constructor called" << std::endl;
	*this = cure;
}

Cure::~Cure()
{
	if (VERBOSE)
		std::cout << overlayPrint("Cure", MAC_DESTRUCT, RED) << "destructor called" << std::endl;
}

Cure	&Cure::operator=(const Cure &cure)
{
	(void)cure;
	return (*this);
}

Cure	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
