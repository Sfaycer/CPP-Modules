#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
/*	{
		Weapon axe("Sharpened Axe");
		HumanA human1("Mike", axe);
		human1.attack();
		axe.setType("Dulled Axe");
		human1.attack();

		Weapon fist("bare fists");
		Weapon sword("Excalibur");
		HumanB human2("Arthur");
		human2.setWeapon(fist);
		fist.setType("barbed fists");
		human2.attack();
		human2.setWeapon(sword);
		human2.attack();
	}*/
	return (0);
}
