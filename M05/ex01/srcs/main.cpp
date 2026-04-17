#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
	std::cout << "****************************************" << std::endl;
	std::cout << "Test 1: successful signing" << std::endl;
	std::cout << "****************************************" << std::endl;
    try
    {
        Bureaucrat b("Tom", 16);  // name and grade
        Form f("F1", 18, 30);   // name, gradeToSign, gradeToExecute
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;  // should show signed = true
    }
    catch (std::exception& e)
    { std::cerr << e.what() << std::endl; }

	std::cout << "****************************************" << std::endl;
	std::cout << "Test 2: failed signing (bureaucrat grade too low)" << std::endl;
	std::cout << "****************************************" << std::endl;
    try
    {
        Bureaucrat b("Tom", 16);  // pick a HIGH number (low rank)
        Form f("F2", 15, 30);   // pick a LOW gradeToSign (high rank)
        b.signForm(f);
    }
    catch (std::exception& e)
    { std::cerr << e.what() << std::endl; }

	std::cout << "****************************************" << std::endl;
	std::cout << "Test 3: invalid form grade" << std::endl;
	std::cout << "****************************************" << std::endl;
    try
    {
        Form f("F3", 0, 151);  // use an invalid grade like 0 or 151
    }
    catch (std::exception& e)
    { std::cerr << e.what() << std::endl; }

    return 0;
}