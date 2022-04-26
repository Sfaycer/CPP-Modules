#include "Fixed.hpp"

int main(void)
{
	Fixed a;// = 0
	Fixed const b(Fixed( 5.05f ) * Fixed( 2 )); // = 10.1016
	Fixed c(5);
	Fixed d(2.5f);

	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl << std::endl;

	std::cout << "b: " << b << std::endl;

	std::cout << "Min(a, b) " << Fixed::min(a,b) << std::endl;//uses const func
	std::cout << "Min(c, d) " << Fixed::min(c,d) << std::endl;//uses non-const func
	std::cout << "Max(a, b) " << Fixed::max(a,b) << std::endl;
	std::cout << "Max(c, d) " << Fixed::max(c,d) << std::endl << std::endl;

	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "c + d: " << c + d << std::endl;
	std::cout << "c - d: " << c - d << std::endl;
	std::cout << "d - c: " << d - c << std::endl;
	std::cout << "c * d: " << c * d << std::endl;
	std::cout << "c / d: " << c / d << std::endl;
	std::cout << "d / c: " << d / c << std::endl << std::endl;


	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl << std::endl;

	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a == b: " << (a != b) << std::endl;

	return (0);
}
