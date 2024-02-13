/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:01:54 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/13 17:45:44 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "===== CONSTRUCTION =====" << std::endl;
	DiamondTrap	diamondTrap1("DiamondTrap1");
	DiamondTrap	diamondTrap2("DiamondTrap2");
	
	diamondTrap1.stats();
	diamondTrap2.stats();
	std::cout << std::endl;

	std::cout << "===== WHO AM I =====" << std::endl;
	diamondTrap1.whoAmI();
	std::cout << std::endl;

	std::cout << "===== ATTACK / TAKE DAMAGES / DEATH =====" << std::endl;
	diamondTrap1.attack("random target 1");
	diamondTrap1.takeDamage(45);
	diamondTrap1.stats();
	diamondTrap1.attack("random target 2");
	diamondTrap1.stats();
	diamondTrap1.takeDamage(60);
	diamondTrap1.attack("random target 3");
	std::cout << std::endl;

	std::cout << "===== REPARATION / NO ENERGY =====" << std::endl;
	diamondTrap2.stats();
	diamondTrap2.takeDamage(60);
	diamondTrap2.stats();
	diamondTrap2.beRepaired(10);
	diamondTrap2.stats();
	diamondTrap2.beRepaired(20);
	diamondTrap2.stats();
	for (int i = 0; i < 97; i++)
	{
		diamondTrap2.attack("another target");
	}
	diamondTrap2.stats();
	diamondTrap2.attack("another target");
	diamondTrap2.beRepaired(3);
	std::cout << std::endl;

	std::cout << "===== DESTRUCTION =====" << std::endl;
}
