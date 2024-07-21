#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::SpellBook(SpellBook const & src)
{
	*this = src;
}

SpellBook & SpellBook::operator=(SpellBook const & src)
{
	_spellBook = src._spellBook;
	return(*this);
}

SpellBook::~SpellBook(void)
{
	for(std::map<std::string, ASpell*>::iterator it = _spellBook.begin() ; it != _spellBook.end() ; ++it)
		delete it->second;
	_spellBook.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
	if(spell)
		if(_spellBook.find(spell->getName()) == _spellBook.end())
			_spellBook[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const & spellName)
{
	if(_spellBook.find(spellName) != _spellBook.end())
		_spellBook.erase(_spellBook.find(spellName));
}

ASpell* SpellBook::createSpell(std::string const & spellName)
{
	ASpell* tmp = NULL;
	if (_spellBook.find(spellName) != _spellBook.end())
		tmp = _spellBook[spellName];
	return(tmp);
}