#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
	this->name = "Default";
	this->hitpoints = 10;
	this->energypoints = 10;
	this->attackdamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << name << " ClapTrap constructor called" << std::endl;
	this->name = name;
	this->hitpoints = 10;
	this->energypoints = 10;
	this->attackdamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " died" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "= operator called" << std::endl;
	this->name = rhs.name;
	this->hitpoints = rhs.hitpoints;
	this->energypoints = rhs.energypoints;
	this->attackdamage = rhs.attackdamage;

	return (*this);
}

void ClapTrap::selfmes(void)
{
	std::cout << "ClapTrap " << this->name;
}

void ClapTrap::attack(std::string const & target)
{
	this->selfmes();
	std::cout << " attacks " << target << ", causing " << this->attackdamage
		<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int temp;

	if (amount > (unsigned)this->hitpoints)
	{
		temp = this->hitpoints;
		this->hitpoints = 0;
	}
	else
	{
		temp = amount;
		this->hitpoints -= amount;
	}
	this->selfmes();
	std::cout << " receives " << temp << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->hitpoints += amount;
	this->selfmes();
	std::cout << " is repaired by " << amount << " hitpoints!" << std::endl;
}

