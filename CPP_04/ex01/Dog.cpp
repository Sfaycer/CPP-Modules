#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog(Dog const &src)
{
	std::cout << "Dog Copy" << std::endl;
	this->brain = new Brain;
	*this->brain = *src.brain;
	this->type = src.type;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog Assign" << std::endl;
	this->type = rhs.type;
	*this->brain = *rhs.brain;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "* Bork! *" << std::endl;
}

