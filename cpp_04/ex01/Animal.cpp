/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:54:33 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 09:59:41 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Random_animal_type")
{
	std::cout << "[Animal constructor called]" << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "[Animal constructor called]" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "[Animal copy constructor called]" << std::endl;
	*this = animal;
}

Animal::~Animal()
{
	std::cout << "[Animal destructor called]" << std::endl;
}

Animal	&Animal::operator=(const Animal &animal)
{
	if (this != &animal)
	{
		this->_type = animal._type;
	}
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "*random animal sound*" << std::endl;
}

std::string		Animal::getType(void) const
{
	return (this->_type);
}
