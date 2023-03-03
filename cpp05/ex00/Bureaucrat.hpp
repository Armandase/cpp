#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "iostream"
#include <ostream>

class Bureaucrat
{
	 public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat (const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat&);
		std::string	getName();
		int			getGrade();
	private:
		const std::string	_name;
		int					_grade;
		
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& crat);

#endif
