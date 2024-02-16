/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:40:48 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 12:31:11 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "[Brain constructor called]" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "FOOD";
}

Brain::Brain(const Brain &brain)
{
	std::cout << "[Brain copy constructor called]" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "FOOD";
	*this = brain;
}

Brain::~Brain()
{
	std::cout << "[Brain destructor called]" << std::endl;
}

Brain	&Brain::operator=(const Brain &brain)
{
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = brain._ideas[i];
	}
	return (*this);
}

void	Brain::showIdeas(void) const
{
	std::cout << "[Inside the brain] " << _ideas[0] << "," << _ideas[1] << "," << _ideas[2] << "," << _ideas[3] << "," << _ideas[4] << ",... ";
}

void	Brain::anotherIdea(std::string idea)
{
	for (int i = 0; i < 5; i++)
		this->_ideas[i] = idea;
}
