#include "ASpell.hpp"

ASpell::ASpell()
{

}

ASpell::~ASpell()
{

}

ASpell::ASpell(ASpell const & src)
{
	*this = src;
}

ASpell & ASpell::operator=(ASpell const & src)
{
	_name = src._name;
	_effects = src._effects;
	return(*this);
}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{
}

std::string const & ASpell::getName(void) const
{
	return(_name);
}

std::string const & ASpell::getEffects(void) const
{
	return(_effects);
}

void ASpell::launch(ATarget const & target) const
{
	std::cout << "LAUNCHING SPELL" << std::endl;
	target.getHitBySpell(*this); //NOTE: parameter = [*this]
}