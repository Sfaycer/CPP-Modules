#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << "========================================" << std::endl;
	try //Known form
	{
		Intern Nick;
		Form *form = Nick.makeForm("Robotomy Request", "Brain");
		Bureaucrat Jim("Jim", 1);
		Jim.signForm(*form);
		std::cout << *form << std::endl;
		Jim.executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try //Unknown form
	{
		Intern Nick;
		Form *form = Nick.makeForm("lalala", "Brain");
		Bureaucrat Jim("Jim", 1);
		Jim.signForm(*form);
		std::cout << *form << std::endl;
		Jim.executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	return (0);
}
