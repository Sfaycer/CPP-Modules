#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	{
	FragTrap frag("Linkoln");
	frag.attack("Eve");
	frag.takeDamage(70);
	frag.highFivesGuys();
	FragTrap frag2 = frag;
	}
	return (0);
}
