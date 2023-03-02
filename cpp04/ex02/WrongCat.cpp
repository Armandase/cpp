#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "iostream"

WrongCat::WrongCat()
	:	WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor call" << std::endl;
	_type = "WrongCat";
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor call" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
	:	WrongAnimal(copy)
{
	WrongCat::operator=(copy);
}

WrongCat& WrongCat::operator = (const WrongCat &cat){
	this->_type = cat._type;
	return (*this);
}

void	WrongCat::makeSound(void) const{
	std::cout << "Ronnnnn miaouuuuuu miaou" << std::endl;
}
