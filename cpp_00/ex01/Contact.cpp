/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:17:27 by rsl               #+#    #+#             */
/*   Updated: 2024/01/24 14:22:04 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::setIndexContact(int indexContact)
{
	this->_indexContact = indexContact;
	return ;
}

bool	Contact::_emptyOrWhiteSpace(std::string str) const
{
	if (str.empty())
		return (true);
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isspace(str[i]))
			return (false);
	return (true);
}

bool	Contact::_unvalidAlpha(std::string str) const
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && !std::isspace(str[i]))
			return (true);
	}
	return (false);
}

bool	Contact::_unvalidPhoneNumber(std::string str) const
{
	if (str.length() != 10)
		return (true);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (true);
	}
	return (false);
}

std::string	Contact::_askGetInput(std::string ask, int type) const
{
	std::string	input = "";
	bool		isValid = false;

	std::cout << ask << std::flush;
	while (!isValid && !std::cin.eof())
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ("");
		}
		if (type == 1 && (this->_emptyOrWhiteSpace(input) || this->_unvalidAlpha(input)))
			std::cout << "[Please enter a valid alphabetical input] " << ask << std::flush;
		else if (type == 2 && (this->_emptyOrWhiteSpace(input) || this->_unvalidPhoneNumber(input)))
			std::cout << "[Please enter a valid numerical input] " << ask << std::flush;
		else if (type == 3 && this->_emptyOrWhiteSpace(input))
			std::cout << "[Please enter a valid input] " << ask << std::flush;
		else
			isValid = true;
	}
	return (input);
}

void	Contact::initContact(void)
{
	this->_firstName = this->_askGetInput("First name: ", 1);
	if (this->_firstName.empty())
		return ;
	this->_lastName = this->_askGetInput("Last name: ", 1);
	if (this->_lastName.empty())
		return ;
	this->_nickname = this->_askGetInput("Nickname: ", 1);
	if (this->_nickname.empty())
		return ;
	this->_phoneNumber = this->_askGetInput("Phone number: ", 2);
	if (this->_phoneNumber.empty())
		return ;
	this->_darkestSecret = this->_askGetInput("Darkest secret: ", 3);
	if (this->_darkestSecret.empty())
		return ;
	std::cout << "Contact successfully added!" << std::endl;
	return ;
}

std::string	Contact::_truncateAndFill(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	while (str.length() < 10)
		str = " " + str;
	return (str);
}

std::string intToString(int nb)
{
	std::ostringstream oss;
	oss << nb;
	return oss.str();
}

void	Contact::printOverview(int indexContact) const
{
	if (this->_emptyOrWhiteSpace(this->_firstName) && this->_emptyOrWhiteSpace(this->_lastName)\
	&& this->_emptyOrWhiteSpace(this->_nickname))
		return ;
	std::cout << "|" << this->_truncateAndFill(intToString(indexContact)) \
	<< "|" << this->_truncateAndFill(this->_firstName) << "|" \
	<< this->_truncateAndFill(this->_lastName) << "|" \
	<< this->_truncateAndFill(this->_nickname) << "|" << std::endl;
	return ;
}

void	Contact::printFullContact(void) const
{
	std::cout << std::endl;
	if (this->_emptyOrWhiteSpace(this->_firstName) && this->_emptyOrWhiteSpace(this->_lastName)\
	&& this->_emptyOrWhiteSpace(this->_nickname) && this->_emptyOrWhiteSpace(this->_phoneNumber)\
	&& this->_emptyOrWhiteSpace(this->_darkestSecret))
		return ;
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
	return ;
}

