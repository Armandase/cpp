#ifndef DOG_HPP
# define DOG_HPP

#include "iostream"
#include "Animal.hpp"

class Dog : Animal
{
	 public:
		Dog();
		~Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog &animal);

		void		makeSound(void);
	 private:
		std::string	_type;
};

#endif
