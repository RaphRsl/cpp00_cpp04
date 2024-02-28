
#ifndef WHATEVER_HPP
# define WHATEVER_HPP


template< typename T >

const T	&max(const T &x ,const T &y)
{
	if (x >= y)
		return (x);
	return (y);
}

template< typename U >

const U	&min(const U &x ,const U &y)
{
	if (x <= y)
		return (x);
	return (y);
}

template< typename V >

void swap(V &x, V &y)
{
	V temp = x;
	x = y;
	y = temp;
}

#endif