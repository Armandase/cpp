#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <exception>

Form::Form()
	:	_name("random"),
		_toExecute(150),
		_toSign(150)
{
	_signed = false;
}

Form::Form(std::string name, bool isSigned, int toExecute, int toSign)
	:	_name(name),
		_toExecute(toExecute),
		_toSign(toSign)
{
	_signed = isSigned;
}

Form::~Form(){
}

Form::Form(const Form &copy)
	:	_name(copy.getName()),
		_toExecute(copy.getToExecute()),
		_toSign(copy.getToSign())
{
	_signed = copy.getSigned();
}

Form & Form::operator=(const Form &copy){
	this->~Form();
	new(this) Form(copy._name, copy._signed, copy._toExecute, copy._toSign);
	return (*this);
}

bool	Form::getSigned() const {
	return (_signed);
}

std::string Form::getName() const {
	return (_name);
}

int	Form::getToSign() const {
	return (_toSign);
}

int Form::getToExecute() const {
	return (_toExecute);
}

std::ostream& operator << (std::ostream& os, const Form& form){
	os << "Name: " << form.getName() << " Signed: " << form.getSigned();
	os << " Grade to sign: " << form.getToSign() << " Grade to execute: " << form.getToExecute();
	return (os);
}

void	Form::beSigned(Bureaucrat crat){
	if (!_signed && crat.getGrade() < _toSign){
		_signed = true;
	}
	else
		throw Form::GradeTooLowExecption();
}
