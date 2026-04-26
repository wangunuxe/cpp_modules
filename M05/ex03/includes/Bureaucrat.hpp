#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class Bureaucrat {
private:
    const std::string   _name;
    int                 _grade;

public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() { return "Bureaucrat grade too high!"; }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() { return "Bureaucrat grade too low!"; }
    };

    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string&  getName() const;
    int                 getGrade() const;

    void                increment();
    void                decrement();

    void                signForm(AForm& form) const;
    void                executeForm(AForm const& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);