#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "Bureaucrat.hpp"
# include "iostream"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	 public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm (const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm(std::string target);
		
		void	launchForm() const;
		void	beSigned(Bureaucrat crat);

	 private:
		std::string _target;
};

#endif
