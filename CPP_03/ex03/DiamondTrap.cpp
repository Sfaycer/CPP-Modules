#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->name = "Default";
	ClapTrap::name = this->name + "_clap_name";
	this->hitpoints = FragTrap::hitpoints;
	this->energypoints = ScavTrap::energypoints;
	this->attackdamage = FragTrap::attackdamage;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << name << " DiamondTrap constructor called" << std::endl;
	this->name = name;
	ClapTrap::name = this->name + "_clap_name";
	this->hitpoints = FragTrap::hitpoints;
	this->energypoints = ScavTrap::energypoints;
	this->attackdamage = FragTrap::attackdamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->name << " died" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "= operator called" << std::endl;
	this->name = rhs.name;
	ClapTrap::name = rhs.ClapTrap::name;
	this->hitpoints = rhs.hitpoints;
	this->energypoints = rhs.energypoints;
	this->attackdamage = rhs.attackdamage;

	return (*this);
}

void DiamondTrap::selfmes(void)
{
	std::cout << "DiamondTrap " << this->name;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "This DiamondTrap is " << this->name << " of " << this->ClapTrap::name << "!" << std::endl;
}
