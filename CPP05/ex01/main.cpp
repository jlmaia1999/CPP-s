#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 1);

		Form contract("TopSecret", 30, 20);

		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << contract << std::endl;

		// Alice (grade 50) tries to sign (requires 30) -> should fail
		alice.signForm(contract);
		std::cout << contract << std::endl;

		// Bob (grade 1) signs successfully
		bob.signForm(contract);
		std::cout << contract << std::endl;

		// Test invalid form construction
		try {
			Form badForm("Bad", 0, 10);
		} catch (const Form::GradeTooHigh &e) {
			std::cout << "Caught form construction error: " << e.what() << std::endl;
		}

	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}