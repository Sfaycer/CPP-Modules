#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <exception>
#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <cfloat>
#include <iomanip>

class Convert
{
	public:
		Convert(char *numstr);
		Convert(void);
		Convert(Convert const &src);
		~Convert(void);
		Convert & operator=(Convert const & src);

		void convert(char *numstr);

		std::string const &getChar(void) const;
		std::string const &getInt(void) const;
		std::string const &getFloat(void) const;
		std::string const &getDouble(void) const;
	private:
		char num_char;
		int num_int;
		float num_float;
		double num_double;
		std::string str_char;
		std::string str_int;
		std::string str_float;
		std::string str_double;

		int precision;

		void isChar(std::string str);

		void isNumber(std::string str);
		void toChar(std::string str);
		void toInt(std::string str);
		void toFloat(std::string str);
		void toDouble(std::string str);

		void isFloatWord(std::string str);

		class InputError : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream & operator<<(std::ostream &o, Convert const & rhs);

#endif /* CONVERT_HPP */

