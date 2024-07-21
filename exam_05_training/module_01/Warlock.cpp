#include "Warlock.hpp"

Warlock::Warlock()
{

}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(Warlock const & src)
{
	*this = src;
}

Warlock & Warlock::operator=(Warlock const & src)
{
	_name = src._name;
	_title = src._title;
	return(*this);
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

std::string const & Warlock::getName(void) const
{
	return(_name);
}

std::string const & Warlock::getTitle(void) const
{
	return(_title);
}

void Warlock::introduce(void) const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::setTitle(std::string const & str)
{
	this->_title = str;
}

void Warlock::learnSpell(ASpell* spell)
{
	if(spell)
	{
		if (_spellBook.find(spell->getName()) == _spellBook.end())
			_spellBook[spell->getName()] = spell->clone();
	}

}

void Warlock::forgetSpell(std::string spellName)
{
	if(_spellBook.find(spellName) != _spellBook.end())
		_spellBook.erase(_spellBook.find(spellName));
}

void Warlock::launchSpell(std::string spellName, ATarget & target)
{
	if(_spellBook.find(spellName) != _spellBook.end())
		_spellBook[spellName]->launch(target);
}