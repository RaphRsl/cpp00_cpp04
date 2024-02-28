#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer - default constructor" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Serializer - copy constructor" << std::endl;
	*this = src;
}

Serializer::~Serializer()
{
	std::cout << "Serializer - destructor" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	if (this == &src)
		return *this;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
