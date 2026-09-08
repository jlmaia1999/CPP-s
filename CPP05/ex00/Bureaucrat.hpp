#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat{
    private:
        const std::string _name;
        int         _grade;
    public:
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &other);

        std::string get_name() const;
        int get_grade() const;

        void increase_grade();
        void decrease_grade();

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
};

    std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);