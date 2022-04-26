#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}


Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = raw << this->bits;
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(raw * (1 << this->bits)) ;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << this->bits));
}

int Fixed::toInt( void ) const
{
	return (this->value >> this->bits);
}

std::ostream & operator<<(std::ostream &o, Fixed const & rhs)
{
	return (o << rhs.toFloat());
}
