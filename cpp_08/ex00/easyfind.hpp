#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <iostream>
#include <exception>

class NotFoundException: public std::exception
{
	public:
			virtual const char *what() const throw()
			{
				return ("\t-> Occurence not found.");
			}
};

template< typename T>
typename T::iterator easyfind(T &intContainer, int i)
{
	typename T::iterator	it;
	it = find(intContainer.begin(), intContainer.end(), i);
	if (it == intContainer.end())
		throw (NotFoundException());
	return (it);
}

#endif
