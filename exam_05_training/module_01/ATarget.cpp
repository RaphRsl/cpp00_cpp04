#include "ATarget.hpp"

ATarget::ATarget()
{

}

ATarget::~ATarget()
{

}

ATarget::ATarget(ATarget const & src)
{
	*this = src;
}

ATarget & ATarget::operator=(ATarget const & src)
{
	_type = src._type;
	return(*this);
}

ATarget::ATarget(std::string type) : _type(type)
{
}

std::string const & ATarget::getType(void) const
{
	return(_type);
}

void ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << "GETTING HIT" << std::endl;
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}

//NOTE :
// - ; a la fin de class {}
// () apres appel a une fonction
// protected pour ASpell et ATarget et.. ?
// si classe qui herite d'une autre, ajouter ": public base_classe" + prototype class_base;
// si .hpp include autres .hpp, [pragma once]
	// ATarget.hpp doit include ASpell.hpp, et vice versa