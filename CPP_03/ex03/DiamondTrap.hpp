#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);
		DiamondTrap & operator=(DiamondTrap const & rhs);

		void whoAmI(void);
	protected:
		void selfmes(void);
	private:
		std::string name;
};

#endif /* DIAMONDTRAP_HPP */

