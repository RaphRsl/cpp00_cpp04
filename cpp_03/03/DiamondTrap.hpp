/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:20:04 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/16 22:20:04 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
		DiamondTrap(void);
		
	public:
		DiamondTrap(const DiamondTrap &diamondTrap);
		DiamondTrap(std::string name);
		~DiamondTrap();

		DiamondTrap	&operator=(const DiamondTrap &diamondTrap);

		void	whoAmI(void) const;
		using	ScavTrap::attack;
};

#endif
