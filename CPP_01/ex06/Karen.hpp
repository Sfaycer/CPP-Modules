#ifndef KAREN_HPP
#define KAREN_HPP

#include <string>
#include <iostream>

class Karen
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void (Karen::*p[4])(void);
		std::string levels[4];
	public:
		void filter( std::string level );
		Karen(void);
};

#endif
