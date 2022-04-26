#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	{
	ScavTrap scav("John");
	scav.attack("Harry");
	scav.takeDamage(75);
	scav.takeDamage(75);
	scav.guardGate();
	ScavTrap scav2 = scav;
	}
	return (0);
}
