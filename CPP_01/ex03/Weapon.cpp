#include "Weapon.hpp"

std::string const &Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(const std::string weapontype)
{
	this->type = weapontype;
}

Weapon::Weapon(std::string weapontype) : type(weapontype)
{

}
