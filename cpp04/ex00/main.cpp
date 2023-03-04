#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	{
		std::cout << "Right class :" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		j->makeSound();
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		delete i;
		delete j;
		delete meta;
		std::cout << std::endl;
	}
	{
		std::cout << "Wrong class :" << std::endl;
		const WrongAnimal* a = new WrongAnimal();
		const WrongAnimal* b = new WrongCat();

		std::cout << a->getType() << " " << std::endl;
		std::cout << b->getType() << " " << std::endl;
		a->makeSound();
		b->makeSound(); //will output the animal sound!
		delete a;
		delete b;
	}
	return 0;
}
