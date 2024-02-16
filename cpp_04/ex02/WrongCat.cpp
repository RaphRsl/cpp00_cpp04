/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:37:06 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 09:39:07 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Cat")
{
	std::cout << "[WrongCat constructor called]" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat)
{
	std::cout << "[WrongCat copy constructor called]" << std::endl;
	*this = wrongCat;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat destructor called]" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &wrongCat)
{
	if (this != &wrongCat)
	{
		this->_type = wrongCat._type;
	}
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "*miaouu miaouuu*" << std::endl;
}
