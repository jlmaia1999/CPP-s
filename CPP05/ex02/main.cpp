#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	Bureaucrat intern("Intern", 150);
	Bureaucrat shrubSigner("ShrubSigner", 140);
	Bureaucrat shrubExecutor("ShrubExec", 130);
	Bureaucrat roboSigner("RoboSigner", 70);
	Bureaucrat roboExecutor("RoboExec", 40);
	Bureaucrat presSigner("PresSigner", 20);
	Bureaucrat presExecutor("PresExec", 3);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pres("Marvin");

	// Attempt executing unsigned forms
	intern.executeForm(shrub);
	intern.executeForm(robo);
	intern.executeForm(pres);

	// Signing attempts
	intern.signForm(shrub); // should fail
	shrubSigner.signForm(shrub); // should succeed

	// Execute shrubbery (signer can't execute; executor can)
	shrubSigner.executeForm(shrub); // likely fails (grade too low to execute)
	shrubExecutor.executeForm(shrub); // should create file

	// Robotomy: sign and execute several times to see randomness
	roboSigner.signForm(robo);
	roboExecutor.executeForm(robo);
	roboExecutor.executeForm(robo);

	// Presidential: sign and execute
	presSigner.signForm(pres);
	presExecutor.executeForm(pres);

	return 0;
}
