#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
//	std::cout << "MateriaSource Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->mat[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
//	std::cout << "MateriaSource Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.mat[i])
			this->mat[i] = src.mat[i]->clone();
		else
			this->mat[i] = 0;
	}
}

MateriaSource::~MateriaSource(void)
{
//	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->mat[i])
			delete this->mat[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
//	std::cout << "MateriaSource Assignation operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->mat[i])
		{
			delete this->mat[i];
			this->mat[i] = 0;
		}
		if (src.mat[i])
			this->mat[i] = src.mat[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->mat[i])
		{
			this->mat[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria *tmp = 0;

	for (int i = 0; i < 4; i++)
	{
		if (this->mat[i] && this->mat[i]->getType() == type)
		{
			tmp = this->mat[i]->clone();
			break;
		}
	}
	return (tmp);
}

