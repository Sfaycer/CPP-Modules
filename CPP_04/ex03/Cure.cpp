#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
//	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
//	std::cout << "Copy Cure constructor called" << std::endl;
}

Cure::~Cure(void)
{
//	std::cout << "Cure Destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &rhs)
{
//	std::cout << "Assignation operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
