#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		~MateriaSource(void);
		MateriaSource & operator=(MateriaSource const & src);

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
	private:
		AMateria *mat[4];
};

#endif /* MATERIASOURCE_HPP */

