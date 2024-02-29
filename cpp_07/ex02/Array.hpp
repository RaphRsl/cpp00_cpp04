#ifndef ARRAY_HPP
# define ARRAY_HPP
# define VERBOSE 1
# define PRINT 1

template< typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(): _size(0)
		{
			if (VERBOSE)
				std::cout << "Array - default constructor (empty array of size 0)" << std::endl;
			this->_array = new T[this->_size];
			if (PRINT)
			{
				for (unsigned int i = 0; i < this->size(); i++)
					std::cout << "[" << this->_array[i] << "]" << std::flush;
			}
		}

		Array(unsigned int size): _size(size)
		{
			if (VERBOSE)
				std::cout << "Array - size constructor (array of size " << size << ")" << std::endl;
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->size(); i++)
				this->_array[i] = 0;
			if (PRINT)
			{
				for (unsigned int i = 0; i < this->size(); i++)
					std::cout << "[" << this->_array[i] << "]" << std::flush;
			}
			std::cout << std::endl;
		}

		Array(const Array &src): _size(src.size())
		{
			if (VERBOSE)
				std::cout << "Array - copy constructor" << std::endl;
			this->_array = NULL;
			*this = src;
		}

		~Array()
		{
			if (VERBOSE)
				std::cout << "Array - destructor" << std::endl;
			if (this->_array != NULL)
				delete [] this->_array;
		}

		Array &operator=(const Array &src)
		{
			if (VERBOSE)
				std::cout << "Array - operator=" << std::endl;
			if (this->_array != NULL)
				delete [] this->_array;
			if (src.size() != 0)
			{
				this->_size = src.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->size(); i++)
					this->_array[i] = src._array[i];
			}
			return (*this);
		}

		T &operator[]( unsigned int index )
		{
			if (VERBOSE)
				std::cout << "Array - operator[]" << std::endl;
			if (index >= this->_size || this->_array == NULL)
			{
				std::cout << "Trying to access index: " << index << std::endl;
				throw Array<T>::ExceptionIndexOutOfBounds();
			}
			return (this->_array[index]);
		}

		class	ExceptionIndexOutOfBounds : public std::exception
		{
		public:
			virtual const char	*what() const throw();
		};

		unsigned int size() const
		{
			if (VERBOSE)
				std::cout << "Array - size getter" << std::endl;
			return (this->_size);
		}
};

template< typename T >
const char	*Array<T>::ExceptionIndexOutOfBounds::what() const throw()
{
	return ("Error: the element's index is out of the array's bounds.");
}

#endif