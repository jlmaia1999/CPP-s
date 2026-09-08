#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other.get_name(), 145, 137), _target(other._target){};

ShrubberyCreationForm::~ShrubberyCreationForm(){};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		_target = other._target;
	return *this;
}

void ShrubberyCreationForm::executeForm() const
{
	std::string name = _target + "_shrubbery";
	std::ofstream file(name.c_str());
	if (!file.is_open())
		throw FileErroException();

	file << "       _-_              _-_\n";
	file << "    /~~   ~~\\       /~~   ~~\\    \n";
	file << " /~~         ~~\\ /~~         ~~\\\n";
	file << "{               }{               }\n";
	file << " \\  _-     -_  / \\  _-     -_  /\n";
	file << "   ~  \\ //  ~      ~  \\ //  ~\n";
	file << "_- -   | | _- _  _- -   | | _- _\n";
	file << "  _ -  | |   -_    _ -  | |   -_\n";
	file << "       | |              | |\n";
	file << "       | |              | |\n";
	file << "       | |              | |\n";
	file << "       |_|              | |\n";
	file << "       ---              ---\n";
	file.close();
}

const char* ShrubberyCreationForm::FileErroException::what() const throw()
{
	return ("ShrubberyCreationForm: could not open file");
}