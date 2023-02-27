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

Cat& Cat::operator = (const Cat &cat){
	this->_type = cat._type;
	return (*this);
}

void	Cat::makeSound(void) const{
	std::cout << "Ronnnnn miaouuuuuu miaou" << std::endl;
}
