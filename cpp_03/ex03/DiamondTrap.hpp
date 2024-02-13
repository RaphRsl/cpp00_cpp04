/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:01:56 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/13 17:24:08 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &diamondTrap);
		DiamondTrap(std::string name);
		~DiamondTrap(void);

		DiamondTrap &operator=(const DiamondTrap &diamondTrap);

		void	whoAmI(void);
		using	ScavTrap::attack;
};

#endif