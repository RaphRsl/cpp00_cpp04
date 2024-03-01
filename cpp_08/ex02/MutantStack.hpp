#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	typedef std::stack<T> stack;
	typedef typename stack::container_type container;
	typedef typename container::iterator iterator;

	MutantStack() : stack()
	{
		std::cout << "MutantStack - default constructor" << std::endl;
	}

	~MutantStack()
	{
		std::cout << "MutantStack - destructor" << std::endl;
	}

	MutantStack(const stack &src) : stack(src)
	{
		std::cout << "MutantStack - copy constructor" << std::endl;
	}

	stack &operator=(const stack &src)
	{
		if (*this != src)
			*this = src;
		return (*this);
	}

	iterator begin()
	{
		return (stack::c.begin());
	}

	iterator end()
	{
		return (stack::c.end());
	}
};

#endif