/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:53:34 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/16 22:08:12 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* 
**		CONSTRUCTORS AND DESTRUCTOR
*/

FragTrap::FragTrap(void) : ClapTrap("FR4G-TP")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_initMsg("Look out everybody! Things are about to get awesome!");
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_initMsg("Look out everybody! Things are about to get awesome!");
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	*this = fragTrap;
	_initMsg("Look out everybody! Things are about to get awesome!");
}

FragTrap::~FragTrap(void)
{
	std::cout << RED << _embedName() << END << "Robot down!" << std::endl;
}

/* 
**		OVERLOAD OPERATORS
*/

FragTrap	&FragTrap::operator=(const FragTrap &fragTrap)
{
	if (this != &fragTrap)
	{
		this->_name = fragTrap._name;
		this->_hitPoints = fragTrap._hitPoints;
		this->_energyPoints = fragTrap._energyPoints;
		this->_attackDamage = fragTrap._attackDamage;
	}
	return (*this);
}

/* 
**		MEMBER FUNCTIONS
*/

void	FragTrap::highFivesGuys(void) const
{
	std::cout << BLUE << _embedName() << END << "High Fives Guys!" << std::endl;
}
