#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	 public:
		Form();
		~Form();
		Form (const Form &copy);
		Form &operator=(const Form& copy);
		Form(std::string name, bool isSigned, int toExecute, int toSign);
		bool		getSigned() const;
		std::string	getName() const;
		int			getToSign() const;
		int			getToExecute() const;
		void	beSigned(Bureaucrat crat);
		class GradeTooLowExecption : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("The grade is too low !");
			}
		};
		class GradeTooHighExecption : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("The grade is too high !");
			}
		};
	 private:
		const std::string	_name;
		bool				_signed;
		const int			_toExecute;
		const int			_toSign;
};

std::ostream& operator << (std::ostream& os, const Form& form);

#endif
