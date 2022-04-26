#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "========================================" << std::endl;
	try
	{
		Bureaucrat Jim("Jim", 0);
		std::cout << Jim << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try
	{
		Bureaucrat Jim("Jim", 151);
		std::cout << Jim << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try
	{
		Bureaucrat Jim("Jim", 5);
		Bureaucrat Steward("Steward", 10);
		std::cout << Steward << std::endl;
		Steward = Jim;
		Jim.inc_grade();
		Steward.dec_grade();
		std::cout << Jim << std::endl;
		std::cout << Steward << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try
	{
		Bureaucrat Jim("Jim", 1);
		std::cout << Jim << std::endl;
		Jim.inc_grade();
		std::cout << Jim << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	try
	{
		Bureaucrat Jim("Jim", 150);
		std::cout << Jim << std::endl;
		Jim.dec_grade();
		std::cout << Jim << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "========================================" << std::endl;
	return (0);
}
