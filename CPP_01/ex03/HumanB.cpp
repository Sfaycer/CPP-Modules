#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name)
{
	this->_weapon = 0;
}

void HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with his bare fists" << std::endl;
}


void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
