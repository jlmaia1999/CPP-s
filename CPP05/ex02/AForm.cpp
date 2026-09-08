#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade too low");
}
const char* AForm::NotSignedException::what() const throw()
{
	return ("AForm not signed");
}


AForm::AForm(std::string name,  int sgrade, int egrade):_name(name), _is_signed(0), _sgrade(sgrade), _egrade(egrade){
	if (_sgrade < 1 || _egrade < 1)
		throw GradeTooHighException();
	if (_sgrade > 150 || _egrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other):_name(other._name), _is_signed(other._is_signed), _sgrade(other._sgrade), _egrade(other._egrade){}

AForm::~AForm(){}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_is_signed = other._is_signed;
	}
	return *this;
}

std::string AForm::get_name() const
{
	return this->_name;
}

bool AForm::get_sign() const
{
	return this->_is_signed;
}

int AForm::get_egrade() const
{
	return this->_egrade;
}

int AForm::get_sgrade() const
{
	return this->_sgrade;
}

void AForm::beSigned(Bureaucrat &b)
{
	if(b.get_grade() > this->_sgrade)
		throw GradeTooLowException();
	else
		_is_signed = 1;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_is_signed)
		throw NotSignedException();
	else if (executor.get_grade() > _egrade)
		throw GradeTooLowException();
	else
		executeForm();
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
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