#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include "iostream"

class AAnimal
{
	 public:
		AAnimal();
		AAnimal(const std::string type);
		virtual ~AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal &aanimal);
		std::string 	getType(void) const;
		virtual void	makeSound(void) const = 0;
	 protected:
		std::string	_type;
};

#endif
