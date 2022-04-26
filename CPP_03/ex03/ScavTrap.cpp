#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->name = "Default";
	this->hitpoints = 100;
	this->energypoints = 50;
	this->attackdamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << name << " ScavTrap constructor called" << std::endl;
	this->name = name;
	this->hitpoints = 100;
	this->energypoints = 50;
	this->attackdamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " died" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "= operator called" << std::endl;
	this->name = rhs.name;
	this->hitpoints = rhs.hitpoints;
	this->energypoints = rhs.energypoints;
	this->attackdamage = rhs.attackdamage;

	return (*this);
}

void ScavTrap::selfmes(void)
{
	std::cout << "ScavTrap " << this->name;
}

void ScavTrap::attack(std::string const & target)
{
	this->selfmes();
	std::cout << " pounds " << target << ", dealing " << this->attackdamage
		<< " points of damage!" << std::endl;
}


void ScavTrap::guardGate(void)
{
	this->selfmes();
	std::cout << " has entered Gate Keeper mode!" << std::endl;
}
