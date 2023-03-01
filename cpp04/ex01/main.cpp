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
	}

	std::cout << "\nMain from the subject" << std::endl;
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
	std::cout << "creation done" << std::endl;

	for (int i = 0; i < 100; i++){
		b[0]->newIdead("thinking");
	}
	
	std::cout << "\ndestruction : " << std::endl;
	for (int i = 0; i < 4; i++)
		delete b[i];
	std::cout << "destruction done" << std::endl;
	return 0;
}
