#include "Span.hpp"

Span::Span(): _size(0), _currentStorage(0)
{
	if (VERBOSE)
		std::cout << "Span - default constructor" << std::endl;
}

Span::Span(unsigned int N): _size(N), _currentStorage(0)
{
	if (VERBOSE)
		std::cout << "Span - constructor for size of " << N << std::endl;
	this->_storage.reserve(this->getSize());
}

Span::Span(const Span &src): _size(src.getSize()), _currentStorage(src.getCurrentStorage())
{
	if (VERBOSE)
		std::cout << "Span - copy constructor" << std::endl;
	*this = src;
}

Span::~Span()
{
	if (VERBOSE)
		std::cout << "Span - deconstructor" << std::endl;
}

Span	&Span::operator=(const Span &src)
{
	if (VERBOSE)
		std::cout << "Span - operator=" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

void	Span::addNumber(int number)
{
	if ((this->_currentStorage != 0 && this->_storage.empty() == true)\
		|| this->_storage.max_size() < this->getSize())
		throw (Span::VectorIssueException());
	if (this->getCurrentStorage() >= this->getSize())
		throw (Span::NoMorePlaceException());
	else
	{
		this->_currentStorage++;
		this->_storage.push_back(number);
		if (VERBOSE)
			std::cout << "Added: " << number << std::endl;
	}
}

void	Span::rngAddNumbers(unsigned int totalNb, time_t rngTime)
{
	srand(rngTime);
	for (size_t i = 0; i < totalNb; i++)
	{
		try
		{
			addNumber(rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_currentStorage <= 1 || this->_storage.size() <= 1)
		throw (Span::LessThanTwoElementsException());

	std::vector<int> sortedVector(this->_storage);
	std::sort (sortedVector.begin(), sortedVector.end());
	unsigned int retValue = UINT_MAX;
	std::vector<int>::iterator it_1 = sortedVector.begin();
	std::vector<int>::iterator it_2 = sortedVector.begin() + 1;

	while (it_2 != sortedVector.end())
	{
		if ((unsigned int)(*it_2 - *it_1) < retValue)
			retValue = *it_2 - *it_1;
		++it_1;
		++it_2;
	}
	return (retValue);
}

unsigned int	Span::longestSpan(void)const
{
	if (this->_currentStorage <= 1 || this->_storage.size() <= 1)
		throw (Span::LessThanTwoElementsException());

	std::vector<int> sortedVector(this->_storage);

	std::sort (sortedVector.begin(), sortedVector.end());

    int min = *sortedVector.begin();
    int max = *(sortedVector.end() - 1);

    return (max - min);
}

void	Span::printStorage(void)const
{
	std::vector<int>::const_iterator it = this->_storage.begin();
	while (it != this->_storage.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

unsigned int	Span::getSize() const
{
	return (this->_size);
}

unsigned int	Span::getCurrentStorage() const
{
	return (this->_currentStorage);
}

const char	*Span::VectorIssueException::what() const throw()
{
	return ("Error: Vector is invalid or misfunctioning.");
}

const char	*Span::NoMorePlaceException::what() const throw()
{
	return ("Error: Trying to add a number to a full vector.");
}

const char	*Span::LessThanTwoElementsException::what() const throw()
{
	return ("Error: trying to compare a vector with less than 2 elements.");
}