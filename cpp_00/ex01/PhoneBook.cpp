#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_indexContact = 0;
	std::cout << "Your PhoneBook has been created" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Your PhoneBook has been destroyed" << std::endl;
	return ;
}

void	PhoneBook::addContact(void)
{
	if (this->_indexContact > 7)
		std::cout << "Be careful, your PhoneBook is full. You will overwrite the oldest contact: " \
		<< this->_contacts[this->_indexContact % 8].getFirstName() << " " \
		<<this->_contacts[this->_indexContact % 8].getLastName() << std::endl;
	while