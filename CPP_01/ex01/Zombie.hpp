#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		void announce( void ) const;
		Zombie (std::string name);
		~Zombie (void);
		Zombie (void);

		void setName(std::string name);
};

#endif
