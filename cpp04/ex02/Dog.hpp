#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	 public:
		Dog();
		~Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog &animal);

		void	setIdea(std::string idea);
		void	getIdeas();
		void	makeSound(void)const;
	 private:
		std::string	_type;
		Brain	*_ideas;
};

#endif
