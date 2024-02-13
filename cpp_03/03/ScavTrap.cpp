/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:47:54 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/16 21:57:05 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* 
**		CONSTRUCTORS AND DESTRUCTOR
*/

ScavTrap::ScavTrap(void) : ClapTrap("SC4V-TP")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_initMsg("You want me? To join you? I am SO excited.");
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_initMsg("You want me? To join you? I am SO excited.");
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	*this = scavTrap;
	_initMsg("You want me? To join you? I am SO excited.");
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << _embedName() << END << "I have many regrets!" << std::endl;
}

/* 
**		OVERLOAD OPERATORS
*/

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

/* 
**		MEMBER FUNCTIONS
*/

void	ScavTrap::guardGate(void) const
{
	std::cout << BLUE << _embedName() << END << "Gate keeper mode activated!" << std::endl;
}

void	ScavTrap::attack(const std::string &target) 
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << ORANGE << _embedName() << END << "Take that " << target << "! (-" << _attackDamage << "HP)" << std::endl;
		_energyPoints -= 1;
	}
	else if (_energyPoints > 0)
		_impossibleAction("attack", ORANGE, "he's dead");
	else
		_impossibleAction("attack", ORANGE, "he has no energy left");
	_showStats();
}
