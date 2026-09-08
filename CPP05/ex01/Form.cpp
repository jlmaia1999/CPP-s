#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}

Form::Form(std::string name,  int sgrade, int egrade):_name(name), _is_signed(0), _sgrade(sgrade), _egrade(egrade){
	if (_sgrade < 1 || _egrade < 1)
		throw GradeTooHighException();
	if (_sgrade > 150 || _egrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other):_name(other._name), _is_signed(other._is_signed), _sgrade(other._sgrade), _egrade(other._egrade){}

Form::~Form(){}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_is_signed = other._is_signed;
	}
	return *this;
}

std::string Form::get_name() const
{
	return this->_name;
}

bool Form::get_sign() const
{
	return this->_is_signed;
}

int Form::get_egrade() const
{
	return this->_egrade;
}

int Form::get_sgrade() const
{
	return this->_sgrade;
}

void Form::beSigned(Bureaucrat &b)
{
	if(b.get_grade() > this->_sgrade)
		throw GradeTooLowException();
	else
		_is_signed = 1;
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	if (!obj.get_sign())
    {
		out << obj.get_name() << " is not signed, form signature grade " << obj.get_sgrade() << ", form execution grade " << obj.get_egrade();
    	return out;
	}
	else
	{
		out << obj.get_name() << " is signed, form signature grade " << obj.get_sgrade() << ", form execution grade " << obj.get_egrade();
    	return out;
	}
}