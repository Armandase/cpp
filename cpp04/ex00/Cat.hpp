#ifndef DOG_HPP
# define DOG_HPP

#include "iostream"
#include "Animal.hpp"

class Cat : Animal
{
	 public:
		Cat();
		~Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat &animal);

		void		makeSound(void);
	 private:
		std::string	_type;
};

#endif
