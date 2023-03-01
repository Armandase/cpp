#include "Cat.hpp"
#include "Animal.hpp"
#include "iostream"

Cat::Cat()
	:	Animal("Cat")
{
	std::cout << "Cat constructor call" << std::endl;
	_type = "Cat";
	_ideas = new Brain;
}

Cat::~Cat(){
	std::cout << "Cat destructor call" << std::endl;
	delete _ideas;
}

Cat::Cat(const Cat& copy)
	:	Animal(copy)
{
	Cat::operator=(copy);
}

Cat& Cat::operator = (const Cat &cat){
	this->_type = cat._type;
	return (*this);
}

Cat::Cat(std::string idea)
{
	_ideas->addIdea(idea);
}

void	Cat::makeSound(void) const{
	std::cout << "Ronnnnn miaouuuuuu miaou" << std::endl;
}
