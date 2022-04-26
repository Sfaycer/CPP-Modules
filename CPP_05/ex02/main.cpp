#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "========================================" << std::endl;
	try //Tree - not signed | Can also check with no access file
	{
		Form *form = new ShrubberyCreationForm("tree");
		Bureaucrat Jim("Jim", 1);
		std::cout << *form << std::endl;
		form->execute(Jim);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try //Tree - signed
	{
		Form *form = new ShrubberyCreationForm("tree2");
		Bureaucrat Jim("Jim", 1);
		form->beSigned(Jim);
		std::cout << *form << std::endl;
		form->execute(Jim);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try //Tree - not signed - executeForm
	{
		Form *form = new ShrubberyCreationForm("tree3");
		Bureaucrat Jim("Jim", 1);
		std::cout << *form << std::endl;
		Jim.executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try //Robot - signed
	{
		Form *form = new RobotomyRequestForm("Tree");
		Bureaucrat Jim("Jim", 1);
		form->beSigned(Jim);
		std::cout << *form << std::endl;
		Jim.executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try //Pardon - signed, can't execute
	{
		Form *form = new PresidentialPardonForm("Tree");
		Bureaucrat Jim("Jim", 10);
		Jim.signForm(*form);
		std::cout << *form << std::endl;
		Jim.executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try //Pardon - signed
	{
		Form *form = new PresidentialPardonForm("Tree");
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
