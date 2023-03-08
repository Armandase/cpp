#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	:	AForm("RobotomyRequest", false, 45, 72)
{
	_target = "random";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:	AForm("RobotomyRequest", false, 45, 72)
{
	_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	:	AForm::AForm(copy)
{
	_target = copy._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	AForm::operator=(copy);
	_target = copy._target;
	return (*this);
}

void	RobotomyRequestForm::beSigned(Bureaucrat crat){
	if (!AForm::getSigned() && crat.getGrade() < AForm::getToSign()){
		AForm::setSigned(true);
	}
	else{
		throw AForm::GradeTooLowExecption();
	}
}

void	RobotomyRequestForm::launchForm() const{
	std::srand((unsigned)time(NULL));
	int nu = std::rand() % 2;
	std::cout << "Vrrrrrrrrr vrrrrr vrrr" << std::endl;
	if (nu)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
