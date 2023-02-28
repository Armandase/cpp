#include "Animal.hpp"
#include "iostream"

Animal::Animal(){
	std::cout << "Animal constructor call" << std::endl;
	_type = "vie";
}

Animal::Animal(const std::string type){
	std::cout << "Animal constructor call" << std::endl;
	_type = type;
}

Animal::~Animal(){
	std::cout << "Animal destructor call" << std::endl;
}

Animal::Animal(const Animal& copy){
	Animal::operator=(copy);
}

Animal& Animal::operator = (const Animal &animal){
	this->~Animal();
	new(this) Animal();
	(void)animal;
	return (*this);
}

std::string Animal::getType(void) const{
	return(_type);
}

void	Animal::makeSound(void) const{
	std::cout << "blurppp braaw" << std::endl;
}
