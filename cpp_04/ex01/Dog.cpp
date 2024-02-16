/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:54:29 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 12:31:58 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain())
{
	this->whatsInMyMind();
	std::cout << "[Dog constructor called]" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog), _brain(new Brain(*(dog._brain)))
{
	std::cout << "[Dog copy constructor called]" << std::endl;
	*this = dog;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "[Dog destructor called]" << std::endl;
}

Dog	&Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
		this->_type = dog._type;
		*(this->_brain) = *(dog._brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "*ouaff ouaaaf*" << std::endl;
}

void	Dog::whatsInMyMind(void) const
{
	this->_brain->showIdeas();
	std::cout << " /// location: " << &this->_brain << std::endl;
}

void	Dog::sleep(void)
{
	this->_brain->anotherIdea("I wanna sleep");
}