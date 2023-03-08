#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "Bureaucrat.hpp"
# include "iostream"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	 public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm (const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& copy);
		RobotomyRequestForm(std::string target);
		
		void	launchForm() const;
		void	beSigned(Bureaucrat crat);

	 private:
		std::string _target;
};

#endif
