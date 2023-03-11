#include <exception>
#include <vector>
#include "easyfind.tpp"
#include <iostream>

int	main(void)
{
	std::vector<int>	tab;
	for (int i = 0; i < 10; i++){
		int 	tmp;
		tmp = i * 2;
		tab.push_back(tmp);
	}
	for (int i = 0; i < 10; i++)
		std::cout << tab.at(i) << "; ";
	std::cout << std::endl;
	int val;
	try {
		val = easyfind(tab, 18);
	} catch (const char *err) {
		std::cout << err << std::endl;
		return (1);
	}
	std::cout << "ret of easyfind from zero: " << val << std::endl;
	std::cout << "content: " << tab.at(val) << std::endl;
	return (0);
}
