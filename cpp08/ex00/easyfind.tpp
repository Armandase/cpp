#include <algorithm>
#include <iostream>

template <typename T>

int	easyfind(T &t, int nb)
{
	int ret;
	ret  = std::find(t.begin(), t.end(), nb) - t.begin(); 
	if (ret == static_cast<int>(t.size())){
		throw ("The number isn't inside the vector");
	}
	return (ret - t.begin());
}
