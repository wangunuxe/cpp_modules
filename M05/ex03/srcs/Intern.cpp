#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

// ── 每种表单对应一个工厂函数 ──────────────────────────────
static AForm* makeShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}
static AForm* makeRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}
static AForm* makePardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// ── 函数指针类型 ──────────────────────────────────────────
typedef AForm* (*FormFactory)(const std::string&);

// ── 名字 → 工厂函数 的映射表（替代 if/else 链）────────────
AForm* Intern::makeForm(const std::string& formName,
                        const std::string& target) const
{
    static const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    static const FormFactory factories[3] = {
        makeShrubbery,
        makeRobotomy,
        makePardon
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == names[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return factories[i](target);
        }
    }

    std::cerr << "Intern error: unknown form \"" << formName << "\"" << std::endl;
    return NULL;
}