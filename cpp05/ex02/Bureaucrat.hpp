#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "iostream"
#include <exception>
#include <ostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	 public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat (const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat&);
		int			getGrade() const;
		std::string	getName() const;
		class GradeTooLowExecption : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("The bureaucrat grade is too low !");
			}
		};
		class GradeTooHighExecption : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("The bureaucrat grade is too high !");
			}
		};
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm *form);
		void	executeForm(AForm const & form);
	private:
		const std::string	_name;
		int					_grade;
		
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& crat);
#endif
