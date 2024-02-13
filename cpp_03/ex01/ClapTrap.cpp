/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:58:56 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/13 15:42:53 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default-name"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << _name << " : [ClapTrap - Default constructor]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	*this = clapTrap;
}

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

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << _name << " : [ClapTrap - Naming constructor]" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << _name << " : [ClapTrap - Destructor]" << std::endl;
}

void	ClapTrap::stats(void) const
{
	std::cout << _name << " has " << _hitPoints << " HP, " << _energyPoints << " energy points and " << _attackDamage << " attack damages." << std::endl;
}

void	ClapTrap::attack(const std::string &target)
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
		std::cout << _name << " can't take any damage because it's already dead..." << std::endl;
	else
	{
		std::cout << _name << " is taking " << amount << " damages." << std::endl;
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		if (_hitPoints > 0)
			std::cout << "(" << _name << " has " << _hitPoints << " HP left)" << std::endl;
		else
			std::cout << "(" << _name << " is dead...)" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
		std::cout << _name << " can't be repared because it's dead..." << std::endl;
	else if (_energyPoints <= 0)
		std::cout << _name << " can't be repared because it's lacking of energy..." << std::endl;
	else
	{
		std::cout << _name << " is being repared of " << amount << " HP !" << std::endl;
		_energyPoints -= 1;
		_hitPoints += amount;
	}
}
