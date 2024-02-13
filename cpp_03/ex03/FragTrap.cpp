/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:35:40 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/13 18:01:42 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("default-name")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << _name << " : [FragTrap - Default constructor]" << std::endl;

}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << _name << " : [FragTrap - Naming constructor]" << std::endl;

}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	*this = fragTrap;
}

FragTrap::~FragTrap(void)
{
	std::cout << _name << " : [FragTrap - Destructor]" << std::endl;
}

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

void	FragTrap::highFivesGuys(void)
{
	std::cout << "High Fives Guys!" << std::endl;
}