#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	a.setRawBits(5);

	Fixed b ( a );
	std::cout << b.getRawBits() << std::endl;

	Fixed c;
	b.setRawBits(10);
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return (0);
}
