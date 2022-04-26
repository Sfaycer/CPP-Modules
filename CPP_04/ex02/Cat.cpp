#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(Cat const &src)
{
	std::cout << "Cat Copy" << std::endl;
	this->brain = new Brain;
	*this->brain = *src.brain;
	this->type = src.type;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat Assign" << std::endl;
	this->type = rhs.type;
	*this->brain = *rhs.brain;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "* Myau *" << std::endl;
}

