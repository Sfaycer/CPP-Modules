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
	std::cout << this->name << " ClapTrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	this->name = rhs.name;
	this->hitpoints = rhs.hitpoints;
	this->energypoints = rhs.energypoints;
	this->attackdamage = rhs.attackdamage;

	return (*this);
}

void ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << this->name << " attacks " << target
		<< ", causing " << this->attackdamage << " points of damage!" << std::endl;
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
	std::cout << "ClapTrap " << this->name << " receives " << temp << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->hitpoints += amount;
	std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " hitpoints!" << std::endl;
}

