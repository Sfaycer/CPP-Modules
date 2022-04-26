#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	{
	DiamondTrap diamond("Linkoln");
	diamond.attack("Eve");
	diamond.ClapTrap::attack("Lady");
	diamond.takeDamage(70);
	diamond.highFivesGuys();
	diamond.guardGate();
	diamond.whoAmI();
	}
	return (0);
}
