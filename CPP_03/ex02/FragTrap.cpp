#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->name = "Default";
	this->hitpoints = 100;
	this->energypoints = 100;
	this->attackdamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << name << " FragTrap constructor called" << std::endl;
	this->name = name;
	this->hitpoints = 100;
	this->energypoints = 100;
	this->attackdamage = 30;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " died" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "= operator called" << std::endl;
	this->name = rhs.name;
	this->hitpoints = rhs.hitpoints;
	this->energypoints = rhs.energypoints;
	this->attackdamage = rhs.attackdamage;

	return (*this);
}

void FragTrap::selfmes(void)
{
	std::cout << "FragTrap " << this->name;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " offers to do a high five!" << std::endl;
}
