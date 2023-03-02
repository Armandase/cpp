#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "iostream"

class WrongAnimal
{
	 public:
		WrongAnimal();
		WrongAnimal(const std::string type);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal &wronganimal);
		std::string 	getType(void) const;
		void	makeSound(void) const;
	 protected:
		std::string	_type;
};

#endif
