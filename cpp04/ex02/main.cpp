#include "Cat.hpp"
#include "Dog.hpp"
#include "AAnimal.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
	int	n = 4;
	AAnimal* b[4];
	/*
	This does not work because it is an abstract class :
	AAnimal licorne;
	*/
	std::cout << "creation : " << std::endl;
	for (int i = 0; i < n; i++)
	{
		if (i  < n / 2){
			b[i] = new Dog();
		} else {
			b[i] =  new Cat();
		}
	}
	std::cout << "creation done\n" << std::endl;

	for (int i = 0; i < 101; i++){
		if (i % 3 == 0)
			((Dog*)b[0])->setIdea("WAF WAF");
		else
			((Dog*)b[0])->setIdea("thinking");
	}
	((Dog*)b[0])->getIdeas();

	std::cout << std::endl;

	((Cat*)b[n / 2 + 1])->setIdea("MIAOU");
	((Cat*)b[n / 2 + 1])->getIdeas();
	
	std::cout << "\ndestruction : " << std::endl;
	for (int i = 0; i < n; i++)
		delete b[i];
	std::cout << "destruction done" << std::endl;
	return 0;
}
