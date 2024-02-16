/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:33:03 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 09:56:17 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;
		
	public:
		WrongAnimal(void);
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &wrongAnimal);
		virtual ~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal &wrongAnimal);

		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif
