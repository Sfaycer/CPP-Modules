#include "Character.hpp"

Character::Character(void)
{
//	std::cout << "Character Default constructor called" << std::endl;
	this->_name = "Default";
	for (int i = 0; i < 4; i++)
		this->powers[i] = 0;
}

Character::Character(std::string name)
{
//	std::cout << "Character " << name << " constructor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->powers[i] = 0;
}

Character::Character(Character const &src)
{
//	std::cout << "Character Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.powers[i])
			this->powers[i] = src.powers[i]->clone();
		else
			this->powers[i] = 0;
	}
	this->_name = src._name;
}

Character::~Character(void)
{
//	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->powers[i])
			delete this->powers[i];
	}
}

Character &Character::operator=(const Character &src)
{
//	std::cout << "Character Assignation operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->powers[i])
		{
			delete this->powers[i];
			this->powers[i] = 0;
		}
		if (src.powers[i])
			this->powers[i] = src.powers[i]->clone();
	}
	this->_name = src._name;
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->powers[i])
		{
			this->powers[i] = m;
			break;
		}
	}
}
void Character::unequip(int idx)
{
	if ((idx >= 0 && idx <= 3) && this->powers[idx])
		this->powers[idx] = 0;
}
void Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx <= 3) && this->powers[idx])
		this->powers[idx]->use(target);
}

