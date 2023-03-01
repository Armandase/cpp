#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "iostream"

class Brain{
public:
	Brain();
	~Brain();
	Brain(const Brain& copy);
	Brain& operator = (const Brain &brain);
	void addIdea(std::string idea);
protected:
	std::string _ideas[100];	
};

#endif
