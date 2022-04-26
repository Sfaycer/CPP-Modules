#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
//	std::cout << "AMateria constructor called" << std::endl;
	this->_type = type;
}

AMateria::AMateria(AMateria const &src)
{
//	std::cout << "Copy AMateria constructor called" << std::endl;
	this->_type = src._type;
}

AMateria::~AMateria(void)
{
//	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
//	std::cout << "Assignation operator called" << std::endl;
	this->_type = rhs._type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* shoots Materia at " << target.getName() << " *" << std::endl;
}

