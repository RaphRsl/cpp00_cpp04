/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsl <rsl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:18:05 by rsl               #+#    #+#             */
/*   Updated: 2024/01/05 17:18:19 by rsl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:

	PhoneBook(void);
	~PhoneBook(void);
	void	starter(void) const;
	void	addCommand(void);
	void	searchCommand(void)const;
	void	printContacts(void) const;
	
	private:

	Contact		_contacts[8];
	int			_whichContact(void) const;
};

#endif
