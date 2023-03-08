#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("ShrubberyCreation", false, 137, 145)
{
	_target = "random";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:	AForm("ShrubberyCreation", false, 137, 145)
{
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	:	AForm::AForm(copy)
{
	_target = copy._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	AForm::operator=(copy);
	_target = copy._target;
	return (*this);
}

void	ShrubberyCreationForm::beSigned(Bureaucrat crat){
	if (!AForm::getSigned() && crat.getGrade() < AForm::getToSign()){
		AForm::setSigned(true);
	}
	else{
		throw AForm::GradeTooLowExecption();
	}
}

void	ShrubberyCreationForm::launchForm() const{
	std::string fileName = _target + "_shrubbery";
	std::string tree;
	std::ofstream outfile(fileName.c_str());

	tree = "   @\n  @@@\n @@@@@\n@@@@@@@\n   @\n   @\n";
	outfile << tree  << "\n" << tree << "\n" << tree;
	outfile.close();
}
