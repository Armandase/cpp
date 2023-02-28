#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "iostream"

class Brain{
public:
	Brain();
	Brain(std::string idea);
	~Brain();
	Brain(const Brain& copy);
	Brain& operator = (const Brain &brain);
protected:
	std::string _ideas[100];	
};

#endif
