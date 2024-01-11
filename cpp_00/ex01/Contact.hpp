/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsl <rsl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:17:34 by rsl               #+#    #+#             */
/*   Updated: 2024/01/11 21:30:47 by rsl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>

class Contact
{
	public:

	Contact(void);
	~Contact(void);

	void	initContact(void);
	void	setIndexContact(int indexContact);
	void	printOverview(int indexContact) const;
	void	printFullContact(void) const;

	private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
	int			_indexContact;

	std::string	_askGetInput(std::string ask, int type) const;
	bool		_emptyOrWhiteSpace(std::string str) const;
	bool		_unvalidAlpha(std::string str) const;
	bool		_unvalidPhoneNumber(std::string str) const;
	std::string	_truncateAndFill(std::string str) const;

};

#endif