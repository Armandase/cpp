#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	{
	std::cout << "Main from the subject" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	

	delete j;
	delete i;
	}/*
	int	n = 10;
	std::cout << "Main from the subject" << std::endl;
	Animal* b = new Animal[n]();

	for (int i = 0; i < n; i++){
		if (i < n / 2){
			b[i] = Dog();
		} else {
			b[i] = Cat();
		}
	}*/
	return 0;
}
