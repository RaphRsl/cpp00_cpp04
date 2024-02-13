/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:44:48 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/16 21:48:14 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamondTrap("Halfy");

	diamondTrap.whoAmI();
	diamondTrap.attack("random human");
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.takeDamage(20);
	diamondTrap.beRepaired(10);
	diamondTrap.takeDamage(100);

	return (0);
}
