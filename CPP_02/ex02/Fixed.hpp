#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);
		Fixed & operator=(Fixed const & rhs);

		void setRawBits(int const raw);
		int getRawBits(void) const;

		Fixed(const int raw);
		Fixed(const float raw);
		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator >(const Fixed &right) const;
		bool operator <(const Fixed &right) const;
		bool operator >=(const Fixed &right) const;
		bool operator <=(const Fixed &right) const;
		bool operator ==(const Fixed &right) const;
		bool operator !=(const Fixed &right) const;

		Fixed operator +(const Fixed &right) const;
		Fixed operator -(const Fixed &right) const;
		Fixed operator *(const Fixed &right) const;
		Fixed operator /(const Fixed &right) const;

		Fixed &operator ++(void);
		Fixed &operator --(void);
		Fixed operator ++(int);
		Fixed operator --(int);

		static Fixed &min(Fixed &a, Fixed &b);
		const static Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		const static Fixed &max(const Fixed &a, const Fixed &b);
	private:
		int value;
		static const int bits = 8;
};

std::ostream & operator<<(std::ostream &o, Fixed const & rhs);

#endif /* FIXED_HPP */

