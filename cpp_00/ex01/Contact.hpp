#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
	public:

	Contact(void);
	~Contact(void);

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;
	void		setFirstName(std::string str);
	void		setLastName(std::string str);
	void		setNickname(std::string str);
	void		setPhoneNumber(std::string str);
	void		setDarkestSecret(std::string str);

	private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

};

#endif