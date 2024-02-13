/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:01:54 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/13 15:02:03 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "===== CONSTRUCTION AND COPY =====" << std::endl;
	ClapTrap	clapTrap1("ClapTrap1");
	ClapTrap	clapTrap2("ClapTrap2");
	ClapTrap	clapTrap3;

	clapTrap1.stats();
	clapTrap2.stats();
	clapTrap3.stats();
	clapTrap3 = clapTrap1;
	clapTrap3.stats();
	std::cout << std::endl;

	std::cout << "===== ATTACK / TAKE DAMAGES / DEATH =====" << std::endl;
	clapTrap1.attack("random target");
	clapTrap1.takeDamage(5);
	clapTrap1.stats();
	clapTrap1.attack("random target 2");
	clapTrap1.takeDamage(3);
	clapTrap1.stats();
	clapTrap1.takeDamage(5);
	clapTrap1.stats();
	clapTrap1.attack ("random target 3");
	clapTrap1.beRepaired(5);
	std::cout << std::endl;

	std::cout << "===== REPARATION / NO ENERGY =====" << std::endl;
	clapTrap2.stats();
	clapTrap2.takeDamage(6);
	clapTrap2.stats();
	clapTrap2.beRepaired(1);
	clapTrap2.stats();
	clapTrap2.beRepaired(2);
	clapTrap2.stats();
	clapTrap2.attack("new target 1");
	clapTrap2.attack("new target 2");
	clapTrap2.attack("new target 3");
	clapTrap2.attack("new target 4");
	clapTrap2.attack("new target 5");
	clapTrap2.attack("new target 6");
	clapTrap2.attack("new target 7");
	clapTrap2.stats();
	clapTrap2.attack("new target 8");
	clapTrap2.attack("new target 9");
	clapTrap2.beRepaired(3);
	std::cout << std::endl;

	std::cout << "===== DESTRUCTION =====" << std::endl;
}
