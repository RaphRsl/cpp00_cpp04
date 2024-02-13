/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:01:54 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/13 16:56:43 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "===== CONSTRUCTION AND COPY =====" << std::endl;
	ClapTrap	clapTrap1("ClapTrap1");
	ScavTrap	scavTrap1("ScavTrap1");
	FragTrap	fragTrap1("FragTrap1");
	FragTrap	fragTrap2;

	clapTrap1.stats();
	scavTrap1.stats();
	fragTrap1.stats();
	fragTrap2.stats();
	fragTrap2 = fragTrap1;
	fragTrap2.stats();
	std::cout << std::endl;

	std::cout << "===== HIGH FIVES =====" << std::endl;
	fragTrap1.highFivesGuys();
	fragTrap2.highFivesGuys();
	std::cout << std::endl;

	std::cout << "===== ATTACK / TAKE DAMAGES / DEATH =====" << std::endl;
	fragTrap1.attack("random target 1");
	fragTrap1.takeDamage(45);
	fragTrap1.stats();
	fragTrap1.attack("random target 2");
	fragTrap1.stats();
	fragTrap1.takeDamage(60);
	fragTrap1.attack("random target 3");
	std::cout << std::endl;

	std::cout << "===== REPARATION / NO ENERGY =====" << std::endl;
	fragTrap2.stats();
	fragTrap2.takeDamage(60);
	fragTrap2.stats();
	fragTrap2.beRepaired(10);
	fragTrap2.stats();
	fragTrap2.beRepaired(20);
	fragTrap2.stats();
	for (int i = 0; i < 97; i++)
	{
		fragTrap2.attack("another target");
	}
	fragTrap2.stats();
	fragTrap2.attack("another target");
	fragTrap2.beRepaired(3);
	std::cout << std::endl;

	std::cout << "===== DESTRUCTION =====" << std::endl;
}
