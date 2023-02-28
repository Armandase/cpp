#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++){
		_ideas[i].assign("\0");
	}	
}

Brain::Brain(std::string idea)
{
	int	i = 0;

	while (_ideas[i] != "\0"){
		i++;
	}
	if (i < 100){
		_ideas[i] = idea;
	} else {
		std::cout << "To manyu ideas" << std::endl;
	}
}

Brain::~Brain(){
	std::cout << "Brain destructor call" << std::endl;
}

Brain::Brain(const Brain& copy){
	Brain::operator=(copy);
}

Brain& Brain::operator = (const Brain &brain){
	this->_ideas 
	return (*this);
}
