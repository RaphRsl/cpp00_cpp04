#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->_name = "nameByDefault";
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called on Zombie named '" << this->_name << "'." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}