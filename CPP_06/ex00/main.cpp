#include <cstdlib>
#include <iostream>
#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			Convert A;
			A.convert(argv[1]);
			std::cout << A << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	else
		std::cout << "Please input only 1 argument to convert" << std::endl;
	return (0);
}
