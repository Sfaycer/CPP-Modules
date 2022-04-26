#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
//	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
//	std::cout << "Copy Ice constructor called" << std::endl;
}

Ice::~Ice(void)
{
//	std::cout << "Ice Destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &rhs)
{
//	std::cout << "Assignation operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
