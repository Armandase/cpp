#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	 public:
		AForm();
		~AForm();
		AForm (const AForm &copy);
		AForm &operator=(const AForm& copy);
		AForm(std::string name, bool isSigned, int toExecute, int toSign);

		virtual bool		getSigned() const = 0;
		virtual std::string	getName() const = 0;
		virtual int			getToSign() const = 0;
		virtual int			getToExecute() const = 0;

		virtual void		beSigned(Bureaucrat crat) = 0;

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

std::ostream& operator << (std::ostream& os, const AForm& form);

#endif
