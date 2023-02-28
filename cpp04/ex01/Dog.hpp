#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	 public:
		Dog();
		~Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog &animal);

		void		makeSound(void)const;
	 private:
		std::string	_type;
		Brain	*ideas;
};

#endif
