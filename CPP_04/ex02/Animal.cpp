#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(Animal const &src)
{
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	this->type = rhs.type;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->type);
}
