#include <exception>
#include <iostream>
#include "Array.hpp"
#include "Array.tpp"
#include <cstdlib>

#define MAX_VAL 750

void	own_test(){
    Array<int> numbers(MAX_VAL);
	std::cout << "Array len: " << numbers.size() << std::endl;
    srand(time(NULL));
    for (int i = 2; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
    }
	numbers[0] = 10;
	numbers[1] = 15;
	std::cout << "tab index 0:" << numbers[0] << std::endl;
	std::cout << "tab index 1:" << numbers[1] << std::endl;
	std::cout << "tab index 2:" << numbers[2] << std::endl;
	try {
		std::cout << "out of range:" << numbers[755] << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	own_test();
    return 0;
}
