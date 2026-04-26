#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm {
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExec;

public:
    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() { return "Grade too high!"; }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() { return "Grade too low!"; }
    };
    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw() { return "Form is not signed!"; }
    };

    AForm(const std::string& name, int gradeToSign, int gradeToExec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string&  getName() const;
    bool                isSigned() const;
    int                 getGradeToSign() const;
    int                 getGradeToExec() const;

    void                beSigned(const Bureaucrat& b);

    // execute checks requirements, then calls executeAction
    void                execute(Bureaucrat const& executor) const;

    // Pure virtual: each concrete form implements its action
    virtual void        executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);