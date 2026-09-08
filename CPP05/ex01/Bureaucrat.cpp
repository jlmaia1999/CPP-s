#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high, max value: 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low, min value: 150");
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    try
    {
        if(grade < 1)
            throw GradeTooHighException();
        if(grade > 150)
            throw GradeTooLowException();
        _grade = grade;
    }
    catch(GradeTooHighException& h)
    {
        std::cout << h.what() <<std::endl;
        _grade = 1;
    }
    catch(GradeTooLowException& l)
    {
        std::cout << l.what() << std::endl;
        _grade = 150;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
{
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){};

std::string Bureaucrat::get_name() const
{
    return (_name);
}

int Bureaucrat::get_grade() const
{
    return (_grade);
}

void Bureaucrat::increase_grade()
{
    try
    {
        if (_grade - 1 < 1)
            throw GradeTooHighException();
        _grade--;
    }
    catch(GradeTooHighException& h)
    {
        std::cout << h.what() << std::endl;
        _grade = 1;
    }
}

void Bureaucrat::decrease_grade()
{
    try
    {
        if (_grade + 1 > 150)
            throw GradeTooLowException();
        _grade ++;
    }
    catch(GradeTooLowException& l)
    {
        std::cout << l.what() << std::endl;
        _grade = 150;
    }
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.get_name() << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << this->_name << " couldn't sign " << f.get_name() << " because her grade isn't high enough" << std::endl;
	}
	
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.get_name() << ", bureaucrat grade " << obj.get_grade();
    return out;
}