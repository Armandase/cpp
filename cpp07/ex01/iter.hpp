#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename L, typename F>

void	iter(T addr, L len, F foo){
	L i = 0;
	L real = 0;
	if (sizeof(T[0]))
		real = sizeof(T) / sizeof(T[0]);
	else 
		real = sizeof(T);

	while ( i < len && i < real)
	{
		foo(addr[i]);
		i++;
	}
}

#endif
