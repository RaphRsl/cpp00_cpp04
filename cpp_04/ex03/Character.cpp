#include "Character.hpp"

Character::Character(void) : _name("unknown_character")
{
	if (VERBOSE)
		std::cout << overlayPrint("Character", MAC_CONSTRUCT, LIGHTGREY) << "constructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
		_inventory[i] = NULL;
	for (int j = 0; j < _maxFloorDrop; j++)
		_floorDrop[j] = NULL;
}


Character::Character(const std::string &name) : _name(name)
{
	if (VERBOSE)
		std::cout << overlayPrint("Character", MAC_CONSTRUCT, LIGHTGREY) << "constructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
		_inventory[i] = NULL;
	for (int j = 0; j < _maxFloorDrop; j++)
		_floorDrop[j] = NULL;
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
	for (int j = 0; j < _maxFloorDrop; j++)
	{
		if (_floorDrop[j])
			_floorDrop[j] = NULL;
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
				_inventory[i] = NULL;
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
		int i = 0;
		while (_floorDrop[i] != NULL)
		{
			i++;
			if (i > _maxFloorDrop)
				i = 0;
		}
		_floorDrop[i] = _inventory[idx];
		if (i == _maxFloorDrop)
		{
			_floorDrop[0] = NULL;
		}
		else
		{
			delete _floorDrop[i + 1];
			_floorDrop[i + 1] = NULL;
		}
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < _inventorySize && _inventory[idx])
	{
		if (_inventory[idx]->getType() == "cure")
			std::cout << overlayPrint(_name, MAC_CURE, GREEN);
		else
			std::cout << overlayPrint(_name, MAC_ICE, BLUE);
		_inventory[idx]->use(target);
		return ;
	}
	std::cout << "/nothing happens/" << std::endl;
}

void	Character::printInventory(void) const
{
	std::cout << overlayPrint(_name, MAC_INVENTORY, ORANGE) << "|";
	for (int i = 0; i < _inventorySize; i++)
	{
		if (_inventory[i])
			std::cout << _inventory[i]->getType() << "|";
		else
			std::cout << " ∅ " << "|";
	}
	std::cout << std::endl;
}
 