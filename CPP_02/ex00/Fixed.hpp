#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);
		Fixed & operator=(Fixed const & rhs);

		void setRawBits(int const raw);
		int getRawBits(void) const;
	private:
		int value;
		static const int bits = 8;
};

#endif
