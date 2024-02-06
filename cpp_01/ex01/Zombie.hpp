#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

class	Zombie
{
	private:

	std::string	_name;

	public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void	setName(std::string);
	void	announce(void) const;

};

#endif