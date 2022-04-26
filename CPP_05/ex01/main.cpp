#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "========================================" << std::endl;
	try //TooHigh
	{
		Form form("Document", 0, 80);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try //TooLow
	{
		Form form("Document", 151, 80);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try //beSigned
	{
		Form form("Document", 100, 80);
		std::cout << form << std::endl;

		Bureaucrat Jim("Jim", 100);
		Bureaucrat Steward("Steward", 101);
		std::cout << Jim << std::endl;
		std::cout << Steward << std::endl;
		form.beSigned(Jim);
		std::cout << form << std::endl;
		form.beSigned(Steward);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try //signForm
	{
		Form form("Document", 100, 80);
		std::cout << form << std::endl;

		Bureaucrat Jim("Jim", 100);
		Bureaucrat Jim2("Jim2", 10);
		Jim.signForm(form);
		std::cout << form << std::endl;
		Jim2.signForm(form);
		std::cout << form << std::endl << std::endl;
		Form form2("Paper", 70, 50);
		std::cout << form2 << std::endl;
		Jim.signForm(form2);
		std::cout << form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	return (0);
}
