#include "Character.hpp"

Character::Character(void) : _name("unknown_character")
{
	if (VERBOSE)
		std::cout << overlayPrint("Character", MAC_CONSTRUCT, LIGHTGREY) << "constructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
		delete _inventory[i];
		// _inventory[i] = NULL; //commented
}


Character::Character(const std::string &name) : _name(name)
{
	if (VERBOSE)
		std::cout << overlayPrint("Character", MAC_CONSTRUCT, LIGHTGREY) << "constructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
		delete _inventory[i];
		// _inventory[i] = NULL; //commented
}

Character::Character(const Character &character)
{
	if (VERBOSE)
		std::cout << overlayPrint("Character", MAC_COPY, LIGHTGREY) << "copy constructor called" << std::endl;
	*this = character;
}

Character::~Character()
{
	if (VERBOSE)
		std::cout << overlayPrint("Character", MAC_DESTRUCT, RED) << "destructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character	&Character::operator=(const Character &character)
{
	if (this != &character)
	{
		_name = character._name;
		for (int i = 0; i < _inventorySize; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (character._inventory[i])
				_inventory[i] = character._inventory[i]->clone();
			else
				delete _inventory[i];
				// _inventory[i] = NULL; //commented
		}
	}
	return (*this);
}

std::string	const &Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	std::cout << overlayPrint(_name, MAC_EQUIP, ORANGE);
	for (int i = 0; i < _inventorySize; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "equips " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "can't equips " <<  m->getType() << " (inventory full)" << std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < _inventorySize)
	{
		std::cout << overlayPrint(_name, MAC_DROP, ORANGE) << "unequips " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
		// _inventory[idx] = NULL; //gerer le drop sur le floor
		delete _inventory[idx];
	}
}

void	Character::use(int idx, ICharacter &target)
{
	// std::cout << overlayPrint(_name, MAC_INVENTORY, BLUE); //quelle color pour quel use ?
	if (idx >= 0 && idx < _inventorySize && _inventory[idx])
	{
		if (_inventory[idx]->getType() == "cure")
			std::cout << overlayPrint(_name, MAC_CURE, GREEN);
		else
			std::cout << overlayPrint(_name, MAC_ICE, BLUE);
		_inventory[idx]->use(target);
		return ;
	}
	std::cout << "/nothing happens/" << std::endl; //COLOR OVERLAY ?
}

//NEEDED ?
static std::string	centering(const std::string str, int size = 6)
{
	int n, s1, s2;
	std::string	centered;
	std::string	toCenter = str; 
	
	n = toCenter.size();
	if (n > size)
	{
		toCenter = toCenter.substr(0, size - 2);
		toCenter[size - 4] = '.';
		toCenter[size - 3] = ' ';
		n = toCenter.size();
	}
	s1 = (size - n) / 2;
	s2 = size - n - s1;
	centered = std::string(s1, ' ') + toCenter + std::string(s2, ' ');
	return (centered);
}

//NEEDED ?
void	Character::printInventory(void) const
{
	std::cout << overlayPrint(_name, MAC_INVENTORY, ORANGE) << "|";
	for (int i = 0; i < _inventorySize; i++)
	{
		if (_inventory[i])
			std::cout << centering(_inventory[i]->getType()) << "|";
		else
			std::cout << centering("") << "|";
	}
	std::cout << std::endl;
}
