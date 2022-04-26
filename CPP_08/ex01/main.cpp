#include "Span.hpp"

int randomGen(void)
{
	return (rand() % 100000);
}

int main(void)
{
	srand(time(0));

	Span A(10);
	std::vector<int> test1(100, 5);
	std::vector<int> test2(10, 5);

	std::cout << "===========A==========" << std::endl;
	try
	{
		A.addNumber(test1.begin(), test1.end());
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		A.addNumber(test2.begin(), test2.end());
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "Longest: " <<A.longestSpan() << std::endl;
	std::cout << "Shortest: " <<A.shortestSpan() << std::endl;

	Span A2(101);

	std::cout << "===========A2==========" << std::endl;
	try
	{
		A2.addNumber(test1);
		A2.addNumber(20);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "Longest: " <<A2.longestSpan() << std::endl;
	std::cout << "Shortest: " <<A2.shortestSpan() << std::endl;


	std::cout << "===========B==========" << std::endl;
	Span B(10000);
	try
	{
		B.addNumber(5000, 14999);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "Longest: " << B.longestSpan() << std::endl;
	std::cout << "Shortest: " << B.shortestSpan() << std::endl;

	std::cout << "===========C==========" << std::endl;
	Span C(10000);
	std::vector<int> test3(100);
	std::generate(test3.begin(), test3.end(), randomGen);
	try
	{
		C.addNumber(test3.begin(), test3.end());
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "Longest: " << C.longestSpan() << std::endl;
	std::cout << "Shortest: " << C.shortestSpan() << std::endl;

	std::cout << "===========D==========" << std::endl;
	Span D(10);
	try
	{
		std::cout << "Longest: " << D.longestSpan() << std::endl;
		std::cout << "Shortest: " << D.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}
