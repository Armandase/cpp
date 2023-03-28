#include <algorithm>
#include <iostream>

template <typename T>

typename T::iterator easyfind(T &t, int nb)
{
<<<<<<< HEAD
	typename T::iterator ret;
	ret  = std::find(t.begin(), t.end(), nb); 
	if (ret == t.end()){
		throw std::logic_error("The number isn't inside the vector");
=======
	int ret;
	ret  = std::find(t.begin(), t.end(), nb) - t.begin(); 
	if (ret == static_cast<int>(t.size())){
		throw ("The number isn't inside the vector");
>>>>>>> 1e5bc1e0a6f7dbe6f19d0e2cf3c48a8804a1cf5a
	}
	return (ret);
}
