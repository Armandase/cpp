#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:	Aform("ShrubberyCreation", false, 137, 147)
{
	_target = "random";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:	Aform("ShrubberyCreation", false, 137, 147)
{
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	:	Form::Form(copy)
{
	_target = copy.target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{

}



