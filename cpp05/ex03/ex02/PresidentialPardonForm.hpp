#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "Bureaucrat.hpp"
# include "iostream"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	 public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm (const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& copy);
		PresidentialPardonForm(std::string target);
		
		void	launchForm() const;
		void	beSigned(Bureaucrat crat);

	 private:
		std::string _target;
};

#endif
