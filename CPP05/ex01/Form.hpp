#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;


class Form{
	private:
		const std::string	_name;
		bool	_is_signed;
		const int	_sgrade;
		const int	_egrade;
	public:
		Form(std::string name, int sgrade, int egrade);
		Form(const Form &other);
		~Form();
		Form &operator=(const Form &other);
		std::string	get_name() const;
		bool	get_sign() const;
		int		get_sgrade() const;
		int		get_egrade() const;

		void	beSigned(Bureaucrat &b);

		class GradeTooHigh: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLow: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &obj);