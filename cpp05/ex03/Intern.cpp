#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::~Intern(){
}

Intern::Intern(const Intern &copy)
{
	Intern::operator=(copy);
}

Intern& Intern::operator=(const Intern& copy)
{
	this->~Intern();
	new(this) Intern();
	(void)copy;
	return (*this);
}

AForm*	Intern::makeForm(std::string name, std::string target){
	std::string	names[3] = {"shrubbery creation" ,"robotomy request", "presidential pardon"};
	AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	int	index = -1;
	for (int i = 0; i < 3; i++){
		if (name == names[i]){
			index = i;
		}
	}
	for (int i = 0; i < 3; i++){
		if (i == index)
			continue ;
		delete forms[i];
	}
	if (index == -1){
		std::cout << name << " isn't a valid form." << std::endl;
		return (NULL);
	}
	return (forms[index]);
}
