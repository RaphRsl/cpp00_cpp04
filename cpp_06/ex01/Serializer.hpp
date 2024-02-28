#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <string>
# include <iostream>
# include <stdint.h>

typedef struct Data
{
	std::string	time;
	std::string	food;
	Data		*next;
}				Data;

class Serializer
{
	private:
	public:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();
		Serializer &operator=(const Serializer &src);

		uintptr_t serialize(Data *ptr);
		Data *deserialize(uintptr_t raw);
};

#endif
