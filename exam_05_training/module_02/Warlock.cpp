#include "Warlock.hpp"

Warlock::Warlock()
{
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	// for(std::map<std::string, ASpell*>::iterator it = _spellBook.begin() ; it != _spellBook.end(); ++it)
	// {
	// 	delete it->second;
	// }
	// _spellBook.clear();
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock & Warlock::operator=(Warlock const & src)
{
	_name = src.getName();
	_title = src.getTitle();
	return(*this);
}

Warlock::Warlock(Warlock const & src)
{
	*this = src;
}

std::string const & Warlock::getName(void) const
{
	return(_name);
}

std::string const & Warlock::getTitle() const
{
	return (_title);
}

void Warlock::setTitle(std::string const & title)
{
	this->_title = title;
}

void Warlock::introduce(void) const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}



void Warlock::learnSpell(ASpell* spell)
{
	_spellBook.learnSpell(spell);
}


void Warlock::forgetSpell(std::string spellName)
{
	_spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, ATarget const & target)
{
	if(_spellBook.createSpell(spellName))
		_spellBook.createSpell(spellName)->launch(target);
}



