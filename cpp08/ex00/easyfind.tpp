#include <algorithm>
#include <vector>

template <typename T>

std::vector<int>::iterator easyfind(T t, int nb)
{
	std::vector<int>::iterator ret;
	ret  = std::find(t.begin(), t.end(), nb); 
	if (ret == t.end() && t.at(t.size()) != nb){
		throw ("The number isn't inside the vector");
	}
	return (ret);
}
