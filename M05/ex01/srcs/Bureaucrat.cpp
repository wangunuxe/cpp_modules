#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if(grade < 1)
		throw GradeTooHighException();
	if(grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){}

//Assignment operator : can't copy _name since it's const
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

const std::string&	Bureaucrat::getName() const 
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if(_grade - 1 < 1)
		throw GradeTooHighException();//this Action "throw" is different from the promise "throw()" : "throw GradeTooHighException();" ->This is an action — it actually creates and launches an exception object : "GradeTooHighException()" → creates a new exception object; Action "throw" -> fires it upward through the call stack
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if(_grade + 1 >150)
		throw GradeTooLowException();
	_grade++;
}

std :: ostream& operator<<(std::ostream& os, const Bureaucrat& a)
{
	os << a.getName() << " , bureaucrat grade " << a.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high (minimum is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low (maximum is 150)";
}

void  Bureaucrat::signForm(Form& c)
{
	try
	{
		c.beSigned(*this);
		std::cout << _name << " signed " << c.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << c.getName() 
				<< " because " << e.what()  << std::endl;
	}
	
}
