#include <iostream>

template< typename T >
void iter(T *array, size_t len, void (*f)(T const &))
{
	if (!array)
		return ;
	for (size_t i = 0; i < len; i++)
		(*f)(array[i]);
}

template< typename T >
void print(T const &data)
{
	std::cout << data << std::endl;
}


