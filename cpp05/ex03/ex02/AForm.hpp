#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	 public:
		AForm();
		virtual ~AForm();
		AForm (const AForm &copy);
		AForm &operator=(const AForm& copy);
		AForm(std::string name, bool isSigned, int toExecute, int toSign);

		bool		getSigned() const;
		void		setSigned(bool);
		std::string	getName() const;
		int			getToSign() const;
		int			getToExecute() const;

		virtual void		beSigned(Bureaucrat crat) = 0;
		void				execute(Bureaucrat const & executor) const;
		virtual void		launchForm() const = 0;

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
		class NotSigned : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("The form is not signed !");
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
