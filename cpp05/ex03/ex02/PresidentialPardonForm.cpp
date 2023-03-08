#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:	AForm("PresidentialPardon", false, 5, 25)
{
	_target = "random";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:	AForm("PresidentialPardon", false, 5, 25)
{
	_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	:	AForm::AForm(copy)
{
	_target = copy._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	AForm::operator=(copy);
	_target = copy._target;
	return (*this);
}

void	PresidentialPardonForm::beSigned(Bureaucrat crat){
	if (!AForm::getSigned() && crat.getGrade() < AForm::getToSign()){
		AForm::setSigned(true);
	}
	else{
		throw AForm::GradeTooLowExecption();
	}
}

void	PresidentialPardonForm::launchForm() const{
	std::cout << _target << " has been pardoned by Saphod Beeblebrox" << std::endl;
}
