#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>

AForm::AForm()
	:	_name("random"),
		_toExecute(150),
		_toSign(150)
{
	_signed = false;
}

AForm::AForm(std::string name, bool isSigned, int toExecute, int toSign)
	:	_name(name),
		_toExecute(toExecute),
		_toSign(toSign)
{
	_signed = isSigned;
}

AForm::~AForm(){
}

AForm::AForm(const AForm &copy)
	:	_name(copy.getName()),
		_toExecute(copy.getToExecute()),
		_toSign(copy.getToSign())
{
	_signed = copy.getSigned();
}

AForm & AForm::operator=(const AForm &copy){
	_signed = copy._signed;
	return (*this);
}

bool	AForm::getSigned() const {
	return (_signed);
}

void	AForm::setSigned(bool action){
	_signed = action;
}

std::string AForm::getName() const {
	return (_name);
}

int	AForm::getToSign() const {
	return (_toSign);
}

int AForm::getToExecute() const {
	return (_toExecute);
}

std::ostream& operator << (std::ostream& os, const AForm& form){
	os << "Name: " << form.getName() << " Signed: " << form.getSigned();
	os << " Grade to sign: " << form.getToSign() << " Grade to execute: " << form.getToExecute();
	return (os);
}

void	AForm::beSigned(Bureaucrat crat){
	if (!_signed && crat.getGrade() < _toSign){
		_signed = true;
	}
	else
		throw AForm::GradeTooLowExecption();
}

bool	check_form(Bureaucrat const & executor, AForm const & form){
	if (form.getSigned() && executor.getGrade() < form.getToExecute()){
		return true;
	}
	return false;
}

void	AForm::execute(Bureaucrat const & executor) const{
	if (check_form(executor, *this)){
		this->launchForm();
	} else if (!getSigned()){
		throw AForm::NotSigned();
	}
	else{
		throw AForm::GradeTooLowExecption();
	}
}
