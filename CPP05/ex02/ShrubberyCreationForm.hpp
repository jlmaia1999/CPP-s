#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		void executeForm() const;

		class FileErroException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};