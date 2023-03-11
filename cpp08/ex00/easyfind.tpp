#include <algorithm>
#include <vector>
#include <iostream>

template <typename T>

int	easyfind(T &t, int nb)
{
	std::vector<int>::iterator ret;
	ret  = std::find(t.begin(), t.end(), nb); 
	if (ret == t.end()){
		throw ("The number isn't inside the vector");
	}
	return (ret - t.begin());
}
