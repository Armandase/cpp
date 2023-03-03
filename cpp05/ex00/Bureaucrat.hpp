#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "iostream"
#include <exception>
#include <ostream>

class Bureaucrat : public std::exception
{
	 public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat() throw();
		Bureaucrat (const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat&);
		 virtual const char * what() const throw();
		std::string	getName();
		int			getGrade();
	private:
		const std::string	_name;
		int					_grade;
		
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& crat);

#endif
