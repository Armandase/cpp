#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "iostream"

class Animal
{
	 public:
		Animal();
		~Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal &animal);
		std::string getType(void);
		void		makeSound(void);
	 private:
		std::string	_type;
};

#endif
