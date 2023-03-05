#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern
{
	 public:
		Intern();
		~Intern();
		Intern (const Intern &copy);
		Intern &operator=(const Intern& copy);
		Intern(std::string target);
		
		AForm*	makeForm(std::string name, std::string target);
};

#endif
