/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsl <rsl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:17:39 by rsl               #+#    #+#             */
/*   Updated: 2024/01/24 12:22:27 by rsl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string userInput = "";
	bool		firstTime = true;
	phoneBook.starter();
	while (userInput != "EXIT")
	{
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << std::endl;
			return (0);
		}
		else if (userInput == "ADD")
			phoneBook.addCommand();
		else if (userInput == "SEARCH")
			phoneBook.searchCommand();
		else if (!firstTime)
			std::cout << "Please enter a valid command. Expected commands: ADD, SEARCH or EXIT" << std::endl;
		firstTime = false;
		std::cout << "Command > " << std::flush;
		std::getline(std::cin, userInput);
	}
	return (0);
}