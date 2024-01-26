#include "HumanA.hpp"

// HumanA::HumanA(void)
// {
// 	this->_name = "defaultName";
// 	this->_weapon = "defaultWeapon";
// 	return ;
// }

// HumanA::HumanA(std::string name, Weapon &weapon)
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	// this->_name = name;
	// this->_weapon = weapon;
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}