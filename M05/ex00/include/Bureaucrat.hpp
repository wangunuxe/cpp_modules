#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
// the rule of thumb: primitives(int, double, char) are passed by value; Objects(std::string or custom classes) are passed by const reference
class Bureaucrat
{
private:
	const std::string _name;
	int	_grade;
public:
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	// The difference between "std::string getName() const" and "const std::string& getName() const;" : (1) "std::string getName() const" ->Every time someone calls getName(), a full copy of the string is made just to be read. That's wasteful. ;  (2) "const std::string& getName() const;"  -> You return a direct window into the original _name — no copy, no extra memory.
	const std::string&	getName() const;
	int	getGrade() const;

	void	incrementGrade(); //grade--
	void	decrementGrade(); //grade++

	//nested class inside Bureaucrat
	//This is an override of std::exception's what() method. : (1) const char* — returns a C-style string (the error message); (2)what() — the method name, defined in std::exception; (3) Promise 1: first const — the returned pointer's content won't be modified; (4)Promise 2: second const — this method won't modify the object (calling this method will not modify the GradeTooHighException instance); (5)promise 3:throw() is just a promise attached to what() -> throw() with nothing inside = "I promise this function will never throw"; throw(SomeException) with something inside = "I might throw this type"
	class	GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std :: ostream& operator<<(std::ostream& os, const Bureaucrat& a);
#endif