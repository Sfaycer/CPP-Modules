#include "Karen.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Karen karen;

		karen.filter(argv[1]);
	}
	else
		std::cout << "Please input only 1 arg" << std::endl;
	return (0);
}
