#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor call" << std::endl;
	for (int i = 0; i < 100; i++){
		_ideas[i].assign("\0");
	}	
}

void	Brain::addIdea(std::string idea)
{
	int	i = 0;

	while (_ideas[i] != "\0"){
		i++;
	}
	if (i < 100){
		_ideas[i] = idea;
	} else {
		std::cout << "Too many ideas" << std::endl;
	}
}

Brain::~Brain(){
	std::cout << "Brain destructor call" << std::endl;
}

Brain::Brain(const Brain& copy){
	Brain::operator=(copy);
}

Brain& Brain::operator = (const Brain &brain){
	for (int i = 0; i < 100; i++){
		this->_ideas[i] = brain._ideas[i]; 
	}
	return (*this);
}

void	Brain::printIdeas()
{
	for (int i = 0; i < 100; i++){
		if (_ideas[i] != "\0"){
			std::cout << _ideas[i] << std::endl;
		}
	}
}
