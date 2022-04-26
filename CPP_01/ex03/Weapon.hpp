#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		std::string const &getType(void) const;
		void setType(const std::string weapontype);
		Weapon(std::string weapon_type);
};

#endif
