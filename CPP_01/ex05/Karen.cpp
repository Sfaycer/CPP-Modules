#include "Karen.hpp"

void Karen::debug( void )
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::dummyf( void)
{

}

Karen::Karen(void)
{
	this->p[0] = &Karen::debug;
	this->p[1] = &Karen::info;
	this->p[2] = &Karen::warning;
	this->p[3] = &Karen::error;
	this->p[4] = &Karen::dummyf;

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}

void Karen::complain( std::string level )
{
	size_t i = 0;

	while (i < 4 && (levels[i].compare(level) != 0))
		i++;
	(this->*p[i])();
}

//Don't worry about that function, it's just there for future reference
/*
void Karen::chooser (void (Karen::*f)(void))
{
	(this->*f)();
}
*/

