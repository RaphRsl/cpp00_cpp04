/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:29:44 by lle-briq          #+#    #+#             */
/*   Updated: 2022/02/23 17:56:45 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* 
**		USEFUL FUNCTIONS 
*/

static int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

/* 
**		CONSTRUCTORS AND DESTRUCTOR
*/

ClapTrap::ClapTrap(void) : _name("CL4P-TP"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	_initMsg("Let's get this party started!");
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	*this = clapTrap;
	_initMsg("Let's get this party started!");
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	this->_name = name;
	_initMsg("Let's get this party started!");
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED << _embedName() << END << "I'm too pretty to die! No, nononono NO!" << std::endl;
}

/* 
**		OVERLOAD OPERATORS
*/

ClapTrap	&ClapTrap::operator=(const ClapTrap &clapTrap)
{
	if (this != &clapTrap)
	{
		this->_name = clapTrap._name;
		this->_hitPoints = clapTrap._hitPoints;
		this->_energyPoints = clapTrap._energyPoints;
		this->_attackDamage = clapTrap._attackDamage;
	}
	return (*this);
}

/* 
**		MEMBER FUNCTIONS
*/

void	ClapTrap::attack(const std::string &target) 
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << ORANGE << _embedName() << END << "Heyyah! Let's attack " << target << "! (-" << _attackDamage << "HP)" << std::endl;
		_energyPoints -= 1;
	}
	else if (_energyPoints > 0)
		_impossibleAction("attack", ORANGE, "he's dead");
	else
		_impossibleAction("attack", ORANGE, "he has no energy left");
	_showStats();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << PURPLE << _embedName() << END << "Why do I even feel pain?! (-" << amount << "HP)" << std::endl;
		_hitPoints = max(_hitPoints - amount, 0);
		if (_hitPoints == 0)
			std::cout << "\tOh no " << _name << " is dead..." << std::endl;
	}
	else
		_impossibleAction("take damage", PURPLE, "he's dead");
	_showStats();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << GREEN << _embedName() << END << "Sweet life juice! (+" << amount << "HP)"<< std::endl;
		_hitPoints += amount;
		_energyPoints -= 1;
	}
	else if (_energyPoints > 0)
		_impossibleAction("be repaired", GREEN, "he's dead");
	else
		_impossibleAction("be repaired", GREEN, "he has no energy left");
	_showStats();
}

void	ClapTrap::_showStats(void) const
{
	std::cout << GRAY << std::setw(5) << _hitPoints << "HP";
	std::cout << std::setw(5) << _energyPoints << "EP";
	std::cout << std::setw(5) << _attackDamage << "AD" << END << std::endl;
}

std::string	ClapTrap::_embedName(void) const
{
	return ("[" + _name + "] ");
}

void	ClapTrap::_impossibleAction(std::string action, std::string color, std::string reason) const
{
	std::cout << _name << " can't " << color << action << END << " since " << reason << std::endl;
}

void	ClapTrap::_initMsg(std::string initStr) const
{
	std::cout << YELLOW << _embedName() << END << initStr << std::endl;
}
