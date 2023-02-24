#include "Dog.hpp"
#include "iostream"

Dog::Dog(){
	std::cout << "Dog constructor call" << std::endl;
	_type = "Dog";
}

Dog::~Dog(){
	std::cout << "Dog destructor call" << std::endl;
}

Dog::Dog(const Dog& copy){
	Dog::operator=(copy);
}

Dog& Dog::operator = (const Dog &dog){
	this->~Dog();
	new(this) Dog();
	(void)dog;
	return (*this);
}

void	Dog::makeSound(void){
	std::cout << "Grrahou waf waf" << std::endl;
}
