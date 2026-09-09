#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;


class AForm{
	private:
		const std::string	_name;
		bool	_is_signed;
		const int	_sgrade;
		const int	_egrade;
	public:
		AForm(std::string name, int sgrade, int egrade);
		AForm(const AForm &other);
		virtual ~AForm();
		AForm &operator=(const AForm &other);
		std::string	get_name() const;
		bool	get_sign() const;
		int		get_sgrade() const;
		int		get_egrade() const;

		void	beSigned(Bureaucrat &b);
		void	execute(Bureaucrat const &executor) const;
		virtual void	executeForm() const = 0;

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NotSignedException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);