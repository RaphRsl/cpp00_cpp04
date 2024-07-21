#include "ATarget.hpp"

ATarget::ATarget()
{}

ATarget::~ATarget()
{}

ATarget::ATarget(std::string type) : _type(type)
{}

ATarget::ATarget(ATarget const & src)
{
	*this = src;
}

ATarget & ATarget::operator=(ATarget const & src)
{
	_type = src.getType();
	return(*this);
}


std::string const & ATarget::getType(void) const
{
	return(_type);
}

void ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}