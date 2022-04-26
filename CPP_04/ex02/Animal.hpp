#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);
		Animal & operator=(Animal const & rhs);

		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
	protected:
		std::string type;
};

#endif /* ANIMAL_HPP */

