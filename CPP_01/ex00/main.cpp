#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
	Zombie *zombie1;
	Zombie *zombie2;
	Zombie *zombie3;
	Zombie zombie4;

	zombie1 = newZombie("Valorie");
	zombie1->announce();
	zombie2 = newZombie("Vasya");
	zombie3 = newZombie("Leo");
	zombie3->announce();
	zombie2->announce();
	zombie4.announce();

	randomChump("Clee");
	randomChump("Chris");
	randomChump("Jake");

	delete zombie1;
	delete zombie2;
	delete zombie3;
	return (0);
}
