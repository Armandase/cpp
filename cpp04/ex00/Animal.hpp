#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "iostream"

class Animal
{
	 public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal &animal);
		std::string 	getType(void) const;
		virtual void	makeSound(void) const;
	 protected:
		std::string	_type;
};

#endif
