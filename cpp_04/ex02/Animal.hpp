/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:54:31 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 13:35:17 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	protected:
		std::string	_type;
		
	public:
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &animal);
		virtual ~Animal() = 0;

		Animal	&operator=(const Animal &animal);
		
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
