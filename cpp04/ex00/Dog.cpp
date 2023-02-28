#include "Dog.hpp"
#include "Animal.hpp"
#include "iostream"

Dog::Dog()
	:	Animal("Dog")
{
	std::cout << "Dog constructor call" << std::endl;
	_type = "Dog";
}

Dog::~Dog(){
	std::cout << "Dog destructor call" << std::endl;
}

Dog::Dog(const Dog& copy)
	:	Animal(copy)
{
	Dog::operator=(copy);
}

Dog& Dog::operator = (const Dog &dog){
	this->_type = dog._type;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Grrahou waf waf" << std::endl;
}
