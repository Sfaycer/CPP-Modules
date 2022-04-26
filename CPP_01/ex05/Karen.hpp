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
		void dummyf ( void );
		void (Karen::*p[5])(void);
		std::string levels[4];
	public:
		void complain( std::string level );
		Karen(void);
};

#endif
