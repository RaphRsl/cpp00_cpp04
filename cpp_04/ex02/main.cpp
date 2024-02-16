/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:54:41 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 13:35:45 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iomanip>
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Cat	cat;
	Dog	dog;

	std::cout << "Cat says: ";
	cat.makeSound();
	std::cout << "Dog says: ";
	dog.makeSound();
	
	// Animal	animal;

	return (0);
}