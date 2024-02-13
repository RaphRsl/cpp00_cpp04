/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:29:40 by lle-briq          #+#    #+#             */
/*   Updated: 2022/02/23 17:40:02 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define GRAY "\x1B[90m"
# define END "\033[0m"
# include <iostream>
# include <iomanip>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		
		void		_showStats(void) const;
		void		_initMsg(std::string initStr) const;
		std::string	_embedName(void) const;
		void		_impossibleAction(std::string action, std::string color, std::string reason) const;

	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap &clapTrap);
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &clapTrap);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
