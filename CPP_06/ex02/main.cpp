#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int i;
	
	i = rand() % 99;
	if (i >= 66)
	{
		std::cout << " generated: A";
		return (new A);
	}
	else if (i >= 33)
	{
		std::cout << " generated: B";
		return (new B);
	}
	std::cout << " generated: C";
	return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "C";
}

void identify(Base& p)
{
	try
	{
		Base &base = dynamic_cast<A&>(p);
		std::cout << "A";
		(void)base;
		return ;
	}
	catch(std::exception &e){}
	try
	{
		Base &base = dynamic_cast<B&>(p);
		std::cout << "B";
		(void)base;
		return ;
	}
	catch(std::exception &e){}
	try
	{
		Base &base = dynamic_cast<C&>(p);
		std::cout << "C";
		(void)base;
		return ;
	}
	catch(std::exception &e){}
}

int main(void)
{
	Base *base;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << ") ";
		base = generate();
		std::cout << "; ptr: ";
		identify(base);
		std::cout << "; ref: ";
		identify(*base);
		std::cout << std::endl;
	}
	return (0);
}
