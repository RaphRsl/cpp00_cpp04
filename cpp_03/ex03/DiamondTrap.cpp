/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:01:58 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/15 12:39:00 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
	_name = "default-name";
	_hitPoints = FragTrap::_hitPoints = 100;
	_energyPoints = ScavTrap::_energyPoints = 50;
	_attackDamage = FragTrap::_attackDamage = 30;
	std::cout << _name << " : [DiamondTrap - Default constructor]" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints = 100;
	_energyPoints = ScavTrap::_energyPoints = 50;
	_attackDamage = FragTrap::_attackDamage = 30;
	std::cout << _name << " : [DiamondTrap - Naming constructor]" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
	*this = diamondTrap;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << _name << " : [DiamondTrap - Destructor]" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	if (this != &diamondTrap)
	{
		this->_name = diamondTrap._name;
		this->_hitPoints = diamondTrap._hitPoints;
		this->_energyPoints = diamondTrap._energyPoints;
		this->_attackDamage = diamondTrap._attackDamage;
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My DiamondTrap name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}
