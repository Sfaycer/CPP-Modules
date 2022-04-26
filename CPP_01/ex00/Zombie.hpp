#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#define ARRAYSIZEM(b) (sizeof(b)/sizeof(b[0]))

class Zombie
{
	private:
		std::string _name;
	public:
		void announce( void ) const;
		Zombie (std::string name);
		~Zombie (void);
		Zombie (void);
};

#endif
