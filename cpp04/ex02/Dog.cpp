#include "Dog.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"
#include "iostream"

Dog::Dog()
	:	AAnimal("Dog")
{
	std::cout << "Dog constructor call" << std::endl;
	_type = "Dog";
	_ideas = new Brain;
}

Dog::~Dog(){
	std::cout << "Dog destructor call" << std::endl;
	delete _ideas;
}

Dog::Dog(const Dog& copy)
	:	AAnimal(copy)
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

void	Dog::setIdea(std::string idea){
	_ideas->addIdea(idea);
}

void	Dog::getIdeas(){
	_ideas->printIdeas();
}
