#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR;
	std::string &stringREF = str;

	stringPTR = &str;

	std::cout << "STD string address: " << &str << std::endl;
	std::cout << "PTR string address: " << stringPTR << std::endl;
	std::cout << "REF string address: " << &stringREF << std::endl << std::endl;

	std::cout << "PTR string: " << *stringPTR << std::endl;
	std::cout << "REF string: " << stringREF << std::endl;
}
