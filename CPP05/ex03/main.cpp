#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Intern intern;
	AForm *pres = intern.makeForm("PresidentialPardonForm", "Marvin");
	AForm *robo = intern.makeForm("RobotomyRequestForm", "Bender");
	AForm *shrub = intern.makeForm("ShrubberyCreationForm", "home");
	AForm *invalid = intern.makeForm("UnknownForm", "Nobody");

	Bureaucrat senior("Senior", 1);
	Bureaucrat robotBoss("RobotBoss", 45);
	Bureaucrat shrubBoss("ShrubBoss", 137);

	if (pres)
	{
		senior.signForm(*pres);
		senior.executeForm(*pres);
		delete pres;
	}
	if (robo)
	{
		robotBoss.signForm(*robo);
		robotBoss.executeForm(*robo);
		delete robo;
	}
	if (shrub)
	{
		shrubBoss.signForm(*shrub);
		shrubBoss.executeForm(*shrub);
		delete shrub;
	}
	(void)invalid;
	return 0;
}

