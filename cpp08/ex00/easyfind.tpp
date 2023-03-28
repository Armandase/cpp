#include <algorithm>
#include <vector>
#include <iostream>

template <typename T>

typename T::iterator easyfind(T &t, int nb)
{
	typename T::iterator ret;
	ret  = std::find(t.begin(), t.end(), nb); 
	if (ret == t.end()){
		throw std::logic_error("The number isn't inside the vector");
	}
	return (ret);
}
