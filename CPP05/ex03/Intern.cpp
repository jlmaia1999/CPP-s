#include "Intern.hpp"

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern(){}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string names[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm *form = NULL;
	int i;

	for (i = 0; i < 3; i++)
	{
		if (name == names[i])
			break;
	}
	try
	{
		switch (i)
		{
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			throw FormNotFoundException();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return form;
}