#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "iostream"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	 public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm (const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);
	 private:
		std::string _target;
		
};

#endif
