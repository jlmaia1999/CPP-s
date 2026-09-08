#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHigh::what() const throw()
{
    return ("Grade too high, max value: 1");
}

const char* Bureaucrat::GradeTooLow::what() const throw()
{
    return ("Grade too low, min value: 150");
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    try
    {
        if(grade < 1)
            throw GradeTooHigh();
        if(grade > 150)
            throw GradeTooLow();
        _grade = grade;
    }
    catch(GradeTooHigh& h)
    {
        std::cout << h.what() <<std::endl;
        _grade = 1;
    }
    catch(GradeTooLow& l)
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
            throw GradeTooHigh();
        _grade--;
    }
    catch(GradeTooHigh& h)
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
            throw GradeTooLow();
        _grade ++;
    }
    catch(GradeTooLow& l)
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
	catch(const Form::GradeTooLow& e)
	{
		std::cout << this->_name << " couldn't sign " << f.get_name() << " because her grade isn't high enough" << std::endl;
	}
	
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.get_name() << ", bureaucrat grade " << obj.get_grade();
    return out;
}