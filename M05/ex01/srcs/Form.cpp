#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"


Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) : _name(name), _sign(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign > 150 ||  _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::~Form() {}

Form::Form(const Form& other) : _name(other._name), _sign(other._sign), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){}

Form& Form::operator=(const Form& other)
{
	if(this != &other)
		_sign = other._sign;
	return *this;
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getSign() const
{
	return _sign;
}

int Form::getGradeSign() const
{
	return _gradeToSign;
}

int Form::getGradeExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _gradeToSign)
		_sign = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& a)
{
	if (a.getSign() == true)
	{
		os << a.getName() << " has been signed, the grade required to sign it is " << a.getGradeSign() << " and the grade required to execute is " << a.getGradeExecute();
	}
	else
	{
		os << a.getName() << " has not been signed, the grade required to sign it is " << a.getGradeSign() << " and the grade required to execute is " << a.getGradeExecute();
	}
	return os;
}
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade required to sign or execute is too high (minimum is 1)";
}
const char* Form::GradeTooLowException::what() const throw()
{
		return "Grade required to sign or execute is too low (maximum is 150)";
}