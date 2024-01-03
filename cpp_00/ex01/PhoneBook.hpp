#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook
{
	public:

	PhoneBook(void);
	~PhoneBook(void);
	void	addContact(void);
	void	searchContact(void);
	void	printContact(Contact contact) const;
	Contact	getContact(int index) const;
	
	private:

	Contact		_contacts[8];
	int			_indexContact;
};

#endif