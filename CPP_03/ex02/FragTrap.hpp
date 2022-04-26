#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);
		FragTrap & operator=(FragTrap const & rhs);

		void highFivesGuys(void);
	protected:
		void selfmes(void);
};

#endif /* FRAGTRAP_HPP */

