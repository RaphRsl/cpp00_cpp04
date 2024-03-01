#ifndef SPAN_HPP
# define SPAN_HPP
# include <string>
# include <iostream>
# include <algorithm>
# include <exception>
# include <vector>
# include <iterator>
# include <climits>
# define VERBOSE 0
# define PRINTSMALLSTORAGE 1
# define PRINTBIGSTORAGE 0

class Span
{
	private:
		std::vector<int> _storage;
		unsigned int _size;
		unsigned int _currentStorage;


	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();

		Span &operator=(const Span &src);

		void addNumber(int number);
		void rngAddNumbers(unsigned int totalNB, time_t rngTime);
		unsigned int shortestSpan()const;
		unsigned int longestSpan()const;
		void printStorage()const;

		unsigned int getSize()const;
		unsigned int getCurrentStorage()const;

	class	VectorIssueException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	NoMorePlaceException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	LessThanTwoElementsException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
};

#endif