#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename L, typename F>

void	iter(T addr, L len, F foo){
	L initLen = len;
	while (len){
		foo(addr[initLen - len]);
		len--;
	}
}

#endif
