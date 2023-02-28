#include "WrongAnimal.hpp"
#include "iostream"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal constructor call" << std::endl;
	_type = "WrongVie";
}

WrongAnimal::WrongAnimal(const std::string type){
	std::cout << "WrongAnimal constructor call" << std::endl;
	_type = type;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor call" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy){
	WrongAnimal::operator=(copy);
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal &animal){
	this->~WrongAnimal();
	new(this) WrongAnimal();
	(void)animal;
	return (*this);
}

std::string WrongAnimal::getType(void) const{
	return(_type);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "blurppp braaw" << std::endl;
}
