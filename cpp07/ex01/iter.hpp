#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename L, typename F>

void	iter(T addr, L len, F foo){
	L i = 0;

	if (len < 0 || len > static_cast<int>(sizeof(T)))
	{
		std::cerr << "wrong len" << std::endl;
		return ;
	}
	while ( i < len)
	{
		foo(addr[i]);
		i++;
	}
}

#endif
