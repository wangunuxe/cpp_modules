#include "Bureaucrat.hpp"
// Think of try/catch like a safety net: try → "attempt this, but it might go wrong";catch → "if something goes wrong, handle it here"

int main()
{
	//Test valid creation
	try
	{
		Bureaucrat b("Tom", 32);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << "After increment: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After decrement: " << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	// Test GradeTooHighException
	try
	{
		Bureaucrat b("Bob", 0);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << "After increment: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After decrement: " << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << std::endl;
	}

	//Test GradeTooLowException
	try
	{
		Bureaucrat b("Steve", 151);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << "After increment: " << b << std::endl;
		b.decrementGrade();
		std::cout << "After decrement: " << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception:" << e.what() << std::endl;
	}
}