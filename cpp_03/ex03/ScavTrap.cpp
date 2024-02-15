/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:15:54 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/15 12:17:34 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("default-name")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << _name << " : [ScavTrap - Default constructor]" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << _name << " : [ScavTrap - Naming constructor]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	*this = scavTrap;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << _name << " : [ScavTrap - Destructor]" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scavTrap)
{
	if (this != &scavTrap)
	{
		this->_name = scavTrap._name;
		this->_hitPoints = scavTrap._hitPoints;
		this->_energyPoints = scavTrap._energyPoints;
		this->_attackDamage = scavTrap._attackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
		std::cout << _name << " can't attack " << target << " because it's dead..." << std::endl;
	else if (_energyPoints <= 0)
		std::cout << _name << " can't attack " << target << " because it's lacking of energy..." << std::endl;
	else
	{
		std::cout << _name << " attacks " << target << " causing " << _attackDamage << " damages !" << std::endl;
		_energyPoints -= 1;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << _name << " : is now in Gate keeper mode." << std::endl;
}