#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _sign;
	const int _gradeToSign;
	const int _gradeToExecute;
public:
	Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
	~Form();
	Form(const Form& other);
	Form& operator=(const Form& other);

	const std::string& getName() const;
	bool getSign() const;
	int getGradeSign() const;
	int getGradeExecute() const;

	void beSigned(const Bureaucrat& b);

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const Form& a);

#endif