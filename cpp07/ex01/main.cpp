#include "iter.hpp"
#include <cctype>
#include <iostream>

void	increment(int &nu){
	nu++;
}

void	toLowercase(std::string &str){
	for (int i = 0; str[i]; i++){
		if (str[i] >= 'a' && str[i] <= 'z'){
			str[i] -= 32;
		}
	}
}

int	main(void)
{
	{
		int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		std::cout << "initiale : ";
		for (int i = 0; i < 9; i++){
			std::cout << array[i]  << " ; ";
		}
		std::cout << std::endl;
		iter(array, 9, &increment);
		std::cout << "after iter : ";
		for (int i = 0; i < 9; i++){
			std::cout << array[i]  << " ; ";
		}
		std::cout << std::endl;
	}
	{
		std::string strs[7] = {"aBon", "Bon", "Cuit", "Druide" , "etoile", "FOIRE", "glObe"};
		std::cout << "initiale : ";
		for (int i = 0; i < 7; i++){
			std::cout << strs[i]  << " ; ";
		}
		std::cout << std::endl;
		iter(strs, 7, &toLowercase);
		std::cout << "after iter : ";
		for (int i = 0; i < 7; i++){
			std::cout << strs[i]  << " ; ";
		}
		std::cout << std::endl;
	}
	return (0);
}
