/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:54:41 by rroussel          #+#    #+#             */
/*   Updated: 2024/02/16 12:27:58 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iomanip>
#include "Dog.hpp"
#include "Cat.hpp"

static void	testDeepCopy(void)
{
	std::cout << " ------------ DEEP COPY ------------" << std::endl;
	Dog	dog1;
	Dog	dog2;
	std::cout << std::endl << "Before copy :" << std::endl;
	dog1.whatsInMyMind();
	dog2.whatsInMyMind();
	dog1.sleep();
	std::cout << std::endl << "After changes :" << std::endl;
	dog1.whatsInMyMind();
	dog2.whatsInMyMind();
	dog2 = dog1;
	std::cout << std::endl << "After copy :" << std::endl;
	dog1.whatsInMyMind();
	dog2.whatsInMyMind();

	std::cout << std::endl;

	Cat	cat1;
	cat1.whatsInMyMind();
	cat1.play();
	Cat	cat2(cat1);

	cat1.whatsInMyMind();
	cat2.whatsInMyMind();
}

static void	testSubject(int size)
{
	std::cout << " ------------ SUBJECT ------------" << std::endl;
	Animal	*arrayAnimals[2 * size];

	for (int i = 0; i < size; i++)
	{
		arrayAnimals[i] = new Dog();
		arrayAnimals[size + i] = new Cat();
	}

	for (int i = 0; i < 2 * size; i++)
		delete arrayAnimals[i];
}

int	main(void)
{
	testSubject(3);
	testDeepCopy();
	return (0);
}