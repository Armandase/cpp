#include "Cat.hpp"
#include "iostream"

Cat::Cat(){
	std::cout << "Cat constructor call" << std::endl;
	_type = "Cat";
}

Cat::~Cat(){
	std::cout << "Cat destructor call" << std::endl;
}

Cat::Cat(const Cat& copy){
	Cat::operator=(copy);
}

Cat& Cat::operator = (const Cat &dog){
	this->~Cat();
	new(this) Cat();
	(void)dog;
	return (*this);
}

void	Cat::makeSound(void){
	std::cout << "Ronnnnn miaouuuuuu miaou" << std::endl;
}
