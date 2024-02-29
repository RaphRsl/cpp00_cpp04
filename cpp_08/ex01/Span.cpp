
#include "Span.hpp"

// Constructors
Span::Span(): _size(0), _pos(0) //is private --> unusable and unnecessary
{
	if (VERBOSE)
		std::cout << "Span - default constructor" << std::endl;
}

Span::Span(unsigned int N): _size(N), _pos(0)
{
	if (VERBOSE)
		std::cout << "Span - constructor for size of " << N << std::endl;
	this->_storage.reserve(this->getSize());
}

Span::Span(const Span &src): _size(src.getSize()), _pos(src.getPos())
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

//TO CHECK
void	Span::addNumber(int number)
{
	if ((this->_pos != 0 && this->_storage.empty() == true)\
		|| this->_storage.max_size() < this->getSize()) //utiliser _storage.size() plutot que pos...
		throw (Span::VectorIssueException());
	// if (this->getPos() + 1 > this->getSize()) // veifier je crois qu'il y a une case de trop/de moins
	if (this->getPos() >= this->getSize())
		throw (Span::NoMorePlaceException());
	else
	{
		this->_pos++;
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

//EN COURS DE RELECTURE
unsigned int	Span::shortestSpan(void) const
{
	if (this->_pos == 1 || this->_storage.size() == 1) // pos = 1 ? ; check empty plutot ? ou size == 0 ? 
		throw (Span::CannotCompareException());

	std::vector<int> v(this->_storage);			// 10 20 30 30 20 10 10 20

	std::sort (v.begin(), v.end());				// 10 10 10 20 20 20 30 30

	unsigned int ret = UINT_MAX;
	std::vector<int>::iterator temp_it = v.begin();
	std::vector<int>::iterator temp_it_next = v.begin() + 1;
	while (temp_it_next != v.end())
	{
		if ((unsigned int)(*temp_it_next - *temp_it) < ret)
			ret = *temp_it_next - *temp_it;
		++temp_it_next;
		++temp_it;
	}
	return (ret);
}

unsigned int	Span::longestSpan(void)const
{
	if (this->_pos == 1 || this->_storage.size() == 1)
		throw (Span::CannotCompareException());

	std::vector<int> v(this->_storage);			// 10 20 30 30 20 10 10 20
	int low, high;

	std::sort (v.rbegin(), v.rend());			// 30 30 20 20 20 10 10 10
	high = *v.begin();

	std::sort (v.begin(), v.end());				// 10 10 10 20 20 20 30 30
	low = *v.begin();

	return (high - low);
}

unsigned int	Span::getSize() const
{
	return (this->_size);
}

unsigned int	Span::getPos() const
{
	return (this->_pos);
}



// Exceptions
const char	*Span::VectorIssueException::what() const throw()
{
	return ("Error: Invalid or broken vector");
}

const char	*Span::NoMorePlaceException::what() const throw()
{
	return ("Error: Array full");
}

const char	*Span::CannotCompareException::what() const throw()
{
	return ("Error: more than one element in vector needed to be compared");
}