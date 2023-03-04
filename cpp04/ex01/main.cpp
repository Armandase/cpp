#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "Main from the subject" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		

		delete j;
		delete i;
		std::cout << std::endl;
	}

	int	n = 4;
	Animal* b[4];
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
	((Cat*)b[n / 2 + 1])->getIdeas();
	((Cat*)b[n / 2 + 1])->setIdea("miaou");
	((Cat*)b[n / 2 + 1])->getIdeas();
	
	std::cout << "\ndestruction : " << std::endl;
	for (int i = 0; i < n; i++)
		delete b[i];
	std::cout << "destruction done" << std::endl;
	return 0;
}
