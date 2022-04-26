#include "Data.hpp"

Data::Data(void)
{
}

Data::Data(Data const &src)
{
	(void)src;
}

Data::~Data(void)
{
}

Data &Data::operator=(const Data &src)
{
	(void)src;
	return (*this);
}

void Data::danger(void) const
{
	std::cout << "He he, I'm in danger!" << std::endl;
}

void Data::noDanger(void) const
{
	std::cout << "Oh wow, I'm safe!" << std::endl;
}
