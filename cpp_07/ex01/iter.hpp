#ifndef ITER_HPP
# define ITER_HPP
# include <string>

template< typename T >

void	iter(T *array, size_t arr_len, void (*foo)(T &))
{
	if (array == NULL || foo == NULL)
		return ;
	size_t i = 0;
	while (i < arr_len)
		foo(array[i++]);
	return ;
}

#endif