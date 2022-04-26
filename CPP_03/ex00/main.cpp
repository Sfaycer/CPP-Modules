#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap;
	ClapTrap bob("Bob");

	clap.attack("Human");
	bob.attack("Unnamed");
	clap.takeDamage(5);
	clap.takeDamage(15);
	clap.beRepaired(10);

	return (0);
}
