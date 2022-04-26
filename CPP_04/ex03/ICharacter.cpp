#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

ICharacter::ICharacter(ICharacter const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ICharacter::~ICharacter(void)
{
	std::cout << "Destructor called" << std::endl;
}

ICharacter &ICharacter::operator=(const ICharacter &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = rhs.getRawBits();
	return (*this);
}

int ICharacter::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void ICharacter::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

