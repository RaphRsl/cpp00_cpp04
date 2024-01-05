/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsl <rsl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:17:56 by rsl               #+#    #+#             */
/*   Updated: 2024/01/05 17:57:21 by rsl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Your PhoneBook has been created" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Your PhoneBook has been destroyed" << std::endl;
	return ;
}

void	PhoneBook::starter(void) const
{
	std::cout << std::endl;
	std::cout << "Welcome to your PhoneBook" << std::endl;
	std::cout << "Please enter a command: ADD, SEARCH or EXIT" << std::endl;
	return ;
}

void	PhoneBook::addCommand(void)
{
	static int	i;
	bool		keepGoing = true;
	if (i > 7)
	{
		std::cout << "Your PhoneBook is full, you will overwrite the oldest contact." << std::endl;
		std::cout << "Are you sure you want to continue? (y/n) => " << std::flush;
		std::string userInput = "";
		std::getline(std::cin, userInput);
		while (userInput != "y" && userInput != "n")
		{
			std::cout << "Please enter a valid answer (y/n) => " << std::flush;
			std::getline(std::cin, userInput);
		}
		if (userInput == "n")
			keepGoing = false;
	}
	if (keepGoing)
	{
		this->_contacts[i % 8].initContact();
		this->_contacts[i % 8].setIndexContact(i % 8);
		i++;
	}
	return ;
}

void	PhoneBook::searchCommand(void) const
{
	int	indexContact = this->_whichContact();
	this->_contacts[indexContact].printFullContact();
	return ;
}

void	PhoneBook::printContacts(void) const
{
	std::cout << std::endl;
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                 PhoneBook                 |" << std::endl;
	std::cout << "_____________________________________________" << std::endl;	
	std::cout << "|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" <<\
	std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
		this->_contacts[i].printOverview(i);
	std::cout << "|___________________________________________|" << std::endl;	
	std::cout << std::endl;
	return ;
}

int		PhoneBook::_whichContact(void) const
{
	std::string	input = "";
	int			indexContact = -1;
	bool		isValid = false;

	this->printContacts();
	std::cout << "Please enter the index of the contact you want to see: " << std::flush;
	while (!isValid)
	{
		std::getline(std::cin, input);
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
		{
			indexContact = input[0] - '0';
			isValid = true;
		}
		else
			std::cout << "Please enter a valid index: " << std::flush;
	}
	return (indexContact);
}
