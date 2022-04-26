#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);
		Cat & operator=(Cat const & rhs);

		void makeSound(void) const;
	private:
		Brain *brain;
};

#endif /* CAT_HPP */

