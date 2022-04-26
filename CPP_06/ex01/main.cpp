#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	uintptr_t newptr;

	newptr = reinterpret_cast<uintptr_t>(ptr);
	return (newptr);
}

Data* deserialize(uintptr_t raw)
{
	Data *newptr;

	newptr = reinterpret_cast<Data*>(raw);
	return (newptr);
}

int main(void)
{
	Data *A = new Data;
	Data *B;
	uintptr_t test;

	A->danger();
	std::cout << "Data ptr before cast: " << A << std::endl;
	test = serialize(A);
	B = deserialize(test);
	if (A == B)
	{
		std::cout << "Data ptr after  cast: " << B << std::endl;
		B->noDanger();
	}
	return (0);
}
