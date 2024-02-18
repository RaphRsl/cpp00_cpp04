#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	if (VERBOSE)
		std::cout << overlayPrint("MateriaSource", MAC_CONSTRUCT, LIGHTGREY)  << "constructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
		// delete _inventory[i]; //tried to change next line
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	if (VERBOSE)
		std::cout << overlayPrint("MateriaSource", MAC_COPY, LIGHTGREY) << "copy constructor called" << std::endl;
	*this = materiaSource;
}

MateriaSource::~MateriaSource()
{
	if (VERBOSE)
		std::cout << overlayPrint("MateriaSource", MAC_DESTRUCT, RED) << "destructor called" << std::endl;
	for (int i = 0; i < _inventorySize; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &materiaSource)
{
	if (this != &materiaSource)
	{
		for (int i = 0; i < _inventorySize; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (materiaSource._inventory[i])
				_inventory[i] = materiaSource._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < _inventorySize; i++)
	{
		if (_inventory[i] == NULL)
		{
			std::cout << overlayPrint("MateriaSource", MAC_LEARN, PURPLE) << "learning " << m->getType() << std::endl;
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << overlayPrint("MateriaSource", MAC_CANT, BROWN) << "can't learn new materia (inventory full)" << std::endl;
	delete m;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < _inventorySize; i++)
	{
		if (_inventory[i] != NULL && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	std::cout << overlayPrint("MateriaSource", MAC_CANT, BROWN) << "can't create " << type << " materia (not learned)" << std::endl;
	return (NULL);
}
