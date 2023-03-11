#include <vector>
#include "easyfind.tpp"
#include <iostream>

int	main(void)
{
	std::vector<int>	tab;
	for (int i = 7; i; i--)
		tab.push_back(i);
	std::vector<int>::iterator val;
	val = easyfind(tab, 2);
	std::cout << "ret of easyfind: " << *val << std::endl;
	return (0);
}
