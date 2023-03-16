#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename L, typename F>

void	iter(T addr, L len, F foo){
	L i = 0;

	for(T it = &addr[0]; i < len && *it!=addr[sizeof(T)]; ++it)
	{
		foo(*it);
		i++;
	}
}

#endif
