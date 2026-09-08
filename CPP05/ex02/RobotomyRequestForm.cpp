#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other.get_name(), 72, 45), _target(other._target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		_target = other._target;
	return *this;
}

void	RobotomyRequestForm::executeForm() const
{
	std::cout << "*Drilling noises*" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
