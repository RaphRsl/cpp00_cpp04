/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:27:08 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/20 18:51:39 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* 
**		CONSTRUCTORS AND DESTRUCTOR
*/

DiamondTrap::DiamondTrap(void) : 
	ClapTrap(), ScavTrap(), FragTrap()
{
	_initMsg("Hey there!");
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) :
	ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
	*this = diamondTrap;
	_initMsg("Hey there!");
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name")
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_initMsg("Hey there!");
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED << _embedName() << END << "Bye bye!" << std::endl;
}

/* 
**		OVERLOAD OPERATORS
*/

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

/* 
**		MEMBER FUNCTIONS
*/

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "My name is " << _name << " and my clapName " << ClapTrap::_name << "!" << std::endl;
}
