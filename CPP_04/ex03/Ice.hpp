#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &src);
		~Ice(void);
		Ice & operator=(Ice const & rhs);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif /* ICE_HPP */

