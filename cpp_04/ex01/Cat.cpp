/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:54:36 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 12:31:49 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
	this->whatsInMyMind();
	std::cout << "[Cat constructor called]" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal("Cat"), _brain(new Brain(*(cat._brain)))
{
	std::cout << "[Cat copy constructor called]" << std::endl;
	*this = cat;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "[Cat destructor called]" << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		this->_type = cat._type;
		*(this->_brain) = *(cat._brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "*miaouu miaouuu*" << std::endl;
}

void	Cat::whatsInMyMind(void) const
{
	this->_brain->showIdeas();
	std::cout << " /// location: " << &this->_brain << std::endl;
}

void	Cat::play(void)
{
	this->_brain->anotherIdea("I wanna play");
}