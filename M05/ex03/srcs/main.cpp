#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
    {
        Bureaucrat bob("Bob", 136);
        ShrubberyCreationForm form("home");
        std::cout << bob << std::endl;
        std::cout << form << std::endl;
        bob.signForm(form);
        bob.executeForm(form);
    }

    std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
    {
        Bureaucrat alice("Alice", 45);
        RobotomyRequestForm form("Bender");
        alice.signForm(form);
        alice.executeForm(form);
        alice.executeForm(form); // Try twice for randomness
    }

    std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
    {
        Bureaucrat zaphod("Zaphod", 5);
        PresidentialPardonForm form("Arthur Dent");
        zaphod.signForm(form);
        zaphod.executeForm(form);
    }

    std::cout << "\n=== Test 4: Grade too low to sign ===" << std::endl;
    {
        Bureaucrat lowly("Lowly", 150);
        ShrubberyCreationForm form("garden");
        lowly.signForm(form);   // Should fail - grade 150, needs 145
        lowly.executeForm(form); // Should fail - not signed
    }

    std::cout << "\n=== Test 5: Signed but grade too low to execute ===" << std::endl;
    {
        Bureaucrat signer("Signer", 145);
        Bureaucrat runner("Runner", 138);
        ShrubberyCreationForm form("office");
        signer.signForm(form);   // Can sign (grade 145)
        runner.executeForm(form); // Cannot exec (needs 137, has 138)
    }

    std::cout << "\n=== Test 6: Execute unsigned form ===" << std::endl;
    {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm form("Nobody");
        boss.executeForm(form); // Form not signed
    }

    std::cout << "\n=== Test 7: Intern makeForm ===" << std::endl;
    {
        Intern someRandomIntern;

        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) delete rrf;

        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
        if (scf) delete scf;

        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur");
        if (ppf) delete ppf;

        AForm* unknown = someRandomIntern.makeForm("coffee form", "nobody");
        if (unknown) delete unknown;
    }

    return 0;
}