/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:54:41 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 10:02:47 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

static void	wrongTest(void)
{
	const WrongAnimal	*wrongAnimal = new WrongCat();

	std::cout << "w type is " << wrongAnimal->getType() << " : ";
	wrongAnimal->makeSound();
	
	delete wrongAnimal;
}

static void	subjectTest(void)
{
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << "j type is " << j->getType() << " : ";
	j->makeSound();
	std::cout << "i type is " << i->getType() << " : ";
	i->makeSound();
	std::cout << "meta type is " << meta->getType() << " : ";
	meta->makeSound();

	delete i;
	delete j;
	delete meta;
}
int	main(void)
{
	std::cout << "----------- SUBJECT TEST -----------" << std::endl;
	subjectTest();
	std::cout << std::endl;
	std::cout << "----------- WRONG TEST -----------" << std::endl;
	wrongTest();
	return (0);
}